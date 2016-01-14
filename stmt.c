#include "stmt.h"

extern error_count;

struct stmt * stmt_create( stmt_kind_t kind, struct decl *d, struct expr *init_expr, struct expr *e, struct expr *next_expr, struct stmt *body, struct stmt *else_body ) {
	struct stmt * new_stmt = malloc(sizeof * new_stmt);
	new_stmt -> kind = kind;
	new_stmt -> decl = d;
	new_stmt -> init_expr = init_expr;
	new_stmt -> expr = e;
	new_stmt -> next_expr = next_expr;
	new_stmt -> body = body;
	new_stmt -> else_body = else_body;
	return new_stmt;
}

void stmt_print( struct stmt *s, int indent ) {
	if(!s) { return; }
	printf("\n");
	switch(s->kind) {
		case STMT_DECL:
			decl_print(s->decl, indent);
			break;
		case STMT_EXPR:
			printf("%*s", indent, "");
			expr_print( s->expr );
			printf(";");
			break;
		case STMT_IF_ELSE:
			printf("%*sif (", indent, "");
			expr_print(s->expr);
			if (s->body) {
			if (s->body->kind == STMT_BLOCK) {
				printf(") {");
				if (s->body) {
					stmt_print(s->body->body, indent+4);
				}
				printf("\n%*s}", indent, "");
			}
			else {
				printf(")");
				stmt_print(s->body, indent+4);
			}
			}
			if (s->else_body) {
			if(s->else_body->kind == STMT_BLOCK) {
				printf("\n%*selse {", indent, "");
				if (s->else_body) {
					stmt_print(s->else_body->body, indent+4);
				}
				printf("\n%*s}", indent, "");
			}
			else {
				printf("\n%*selse ", indent, "");
				stmt_print(s->else_body, indent+4);
			}
			}
			break;
		case STMT_FOR:
			printf("%*sfor(", indent, "");
			expr_print(s->init_expr);
			printf(";");
			expr_print(s->expr);
			printf(";");
			expr_print(s->next_expr);
			printf(")");
			if(s->body)
			if(s->body->kind == STMT_BLOCK) {
				printf(" {");
				if(s->body)
				stmt_print(s->body->body, indent+4);
				printf("\n%*s}", indent, "");
			}
			else {
				stmt_print(s->body, indent+4);	
			}
			break;
		case STMT_PRINT:
			printf("%*sprint ", indent, "");
			expr_print(s->expr);
			printf(";");
			break;
		case STMT_RETURN:
			printf("%*sreturn ", indent, "");
			expr_print(s->expr);
			printf(";");
			break;
		case STMT_BLOCK:
			printf("%*s{", indent, "");
			stmt_print(s->body,indent+4);
			printf("\n%*s}", indent, "");
			break;
		case STMT_EMPTY:
			break;
	}
	stmt_print(s->next, indent);
}

void stmt_resolve(struct stmt *s) {
	if (!s) { return; }
	switch (s->kind) {
		case STMT_DECL: 
			decl_resolve(s->decl);
			break;
		case STMT_IF_ELSE:
			expr_resolve(s->expr);
			stmt_resolve(s->body);
			stmt_resolve(s->else_body);
			break;
		case STMT_BLOCK:
			scope_enter();
			stmt_resolve(s->body);
			scope_exit();
			break;
		case STMT_EXPR:
			expr_resolve(s->expr);
			break;
		case STMT_FOR:
			expr_resolve(s->init_expr);
			expr_resolve(s->expr);
			expr_resolve(s->next_expr);
			stmt_resolve(s->body);
			break;
		case STMT_PRINT:
			expr_resolve(s->expr);
			break;
		case STMT_RETURN:
			expr_resolve(s->expr);
			break;
		case STMT_EMPTY:
			break;
	}
	stmt_resolve(s->next);
}

void stmt_typecheck( struct stmt *s, struct decl * current_function ) {
	if (!s) { return; }
	struct type * T = expr_typecheck(s->expr);
	switch (s -> kind) {
		case STMT_IF_ELSE:				
			T = expr_typecheck(s->expr);
			if(T->kind != TYPE_BOOLEAN){
				printf("type error: if condition is of type ");
				type_print(T);
				printf(" (");
				expr_print(s->expr);
				printf("), where a boolean value is required\n");
				error_count++;
			}
			stmt_typecheck(s->body,current_function);
			stmt_typecheck(s->else_body,current_function);
			break;
		// decl can't be a function decl if outside of global scope
		case STMT_DECL: 
			if(s->decl->type->kind == TYPE_FUNCTION){
				printf("type error: cannot declare a function (%s) nested in another function (%s)\n",s->decl->name,current_function->name);
				error_count++;
			}
			decl_typecheck(s->decl);
			break;
		case STMT_EXPR:
			expr_typecheck(s->expr);
			break;
		case STMT_FOR:
			expr_typecheck(s->init_expr);
			T = expr_typecheck(s->expr);
			if(T->kind != TYPE_BOOLEAN && T->kind != TYPE_VOID){
				printf("type error: for loop conditional is of type ");
				type_print(T);
				printf(" (");
				expr_print(s->expr);
				printf("), where a boolean value is required\n");
				error_count++;
			}
			expr_typecheck(s->next_expr);
			stmt_typecheck(s->body,current_function);
			break;
		case STMT_PRINT:
			expr_typecheck(s->expr);
			break;
		// check that value being returned matches the subtype of the function it is called in (the return values must match)
		case STMT_RETURN:
			if(current_function->type->subtype->kind != expr_typecheck(s->expr)->kind){
				printf("type error: cannot return ");
				type_print(expr_typecheck(s->expr));
				printf(" in function (%s) that returns ",current_function->name);
				type_print(current_function->type->subtype);
				printf("\n");
				error_count++;
			}
			break;
		case STMT_BLOCK:
			stmt_typecheck(s->body,current_function);
			break;
		case STMT_EMPTY:
			// do nothing
			break;
	}
	stmt_typecheck(s->next,current_function);
}

void stmt_codegen(struct stmt *s, FILE * output) {
	struct expr * e_cursor;
	int label_save;
	if (!s) return;
	switch (s->kind) {
		case STMT_DECL:
			decl_codegen(s->decl, output);
			break;
		case STMT_EXPR:
			expr_codegen(s->expr, output);
			register_free(s->expr->reg);
			break;
		case STMT_IF_ELSE:
			fprintf(output, "\n\t## if statement ##\n");
			label_save = label_count;
			label_count+=2;
			expr_codegen(s->expr, output);
			fprintf(output, "\tCMP $0, %s\n", register_name(s->expr->reg));
			register_free(s->expr->reg);
			fprintf(output, "\tJE .L%d\n", label_save);
			stmt_codegen(s->body, output);
			fprintf(output, "\tJMP .L%d\n", label_save+1);
			fprintf(output, "\t.L%d:\n", label_save);
			stmt_codegen(s->else_body, output);
			fprintf(output, "\t.L%d:\n", label_save+1);
			fprintf(output, "\n\t## end of if statement ##\n");
			break;
		case STMT_FOR:
			label_save = label_count;
			label_count+=2;
			fprintf(output, "\n\t## for loop ##\n");
			expr_codegen(s->init_expr, output);
			if(s->init_expr) {	// for infinite for loops
				register_free(s->init_expr->reg);
			}
			fprintf(output, "\t.L%d:\n", label_save);
			expr_codegen(s->expr, output);
			if (s->expr) {		// for infinite for loops
				register_free(s->expr->reg);
				fprintf(output, "\tCMP $0, %s\n", register_name(s->expr->reg));
				fprintf(output, "\tJE .L%d\n", label_save+1);
			}
			stmt_codegen(s->body, output);
			expr_codegen(s->next_expr, output);
			if (s->next_expr) {
				register_free(s->next_expr->reg);
			}
			fprintf(output, "\tJMP .L%d\n", label_save);
			fprintf(output, "\t.L%d:\n", label_save+1);
			fprintf(output, "\t## end of for loop ##\n");
			break;
		case STMT_PRINT:
			if(s->expr) {
				if(s->expr->kind == EXPR_LIST) {	// multiple things to print
					e_cursor = s->expr;	// traverse the expr_list
					while(e_cursor) {
						expr_print_codegen(e_cursor->left, output);
						e_cursor = e_cursor->right;
					}
				}
				else {	// single thing to print
					expr_print_codegen(s->expr, output);
				}
			}
			break;
		case STMT_RETURN:
			fprintf(output, "\n\t## return statement ##\n");
			if (s->expr) {
				expr_codegen(s->expr, output);
				fprintf(output, "\tMOV %s, %%rax\n", register_name(s->expr->reg));
				register_free(s->expr->reg);
				fprintf(output, "\tJMP .ret%d\n", ret_count);                	// return to caller
			}
			else {
				fprintf(output, "\tJMP .ret%d\n", ret_count); 
			}
			fprintf(output, "\t## end return statement ##\n\n");
			break;
		case STMT_BLOCK:
			stmt_codegen(s->body, output);
			break;
		case STMT_EMPTY:
			break;
	} 
	stmt_codegen(s->next, output);
}

int stmt_compare(struct stmt * a, struct stmt * b) {
	if (!a && !b) {
		return 1;
	}
	else if ((!a || !b)) {
		return 0;
	}
	else {
		return (a->kind==b->kind) && decl_compare(a->decl, b->decl) && expr_compare(a->init_expr, b->init_expr) && expr_compare(a->expr, b->expr) && expr_compare(a->next_expr, b->next_expr) && stmt_compare(a->body, b->body) && stmt_compare(a->else_body, b->else_body) && stmt_compare(a->next, b->next);
	}
}
