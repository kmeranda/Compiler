#include "expr.h"
#include "type.h"
#include "symbol.h"
#include "scope.h"
#include "global.h"
#include <string.h>

extern error_count;

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ) {
	struct expr * new_expr = malloc(sizeof * new_expr);
	new_expr -> kind = kind;
	new_expr -> left = left;
	new_expr -> right = right;
	new_expr -> name = NULL;
	new_expr -> symbol = NULL;
	new_expr -> string_literal = NULL;
	return new_expr;
}

struct expr * expr_create_name( const char *n ) {
	struct expr * new_expr = malloc(sizeof * new_expr);
	new_expr -> kind = EXPR_NAME;
	new_expr -> left = NULL;
	new_expr -> right = NULL;
	new_expr -> name = n;
	new_expr -> symbol = NULL;
	new_expr -> string_literal = n;
	return new_expr;
}

struct expr * expr_create_boolean_literal( int c ) {
	struct expr * new_expr = malloc(sizeof * new_expr);
	new_expr -> kind = EXPR_BOOL;
	new_expr -> left = NULL;
	new_expr -> right = NULL;
	new_expr -> name = NULL;
	new_expr -> symbol = NULL;
	new_expr -> literal_value = c;
	new_expr -> string_literal = NULL;
	return new_expr;
}

struct expr * expr_create_integer_literal( int c ) {
	struct expr * new_expr = malloc(sizeof * new_expr);
	new_expr -> kind = EXPR_INT;
	new_expr -> left = NULL;
	new_expr -> right = NULL;
	new_expr -> name = NULL;
	new_expr -> symbol = NULL;
	new_expr -> literal_value = c;
	new_expr -> string_literal = NULL;
	return new_expr;
}

struct expr * expr_create_character_literal( int c ) {
	struct expr * new_expr = malloc(sizeof * new_expr);
	new_expr -> kind = EXPR_CHAR;
	new_expr -> left = NULL;
	new_expr -> right = NULL;
	new_expr -> name = NULL;
	new_expr -> symbol = NULL;
	new_expr -> literal_value = c;
	new_expr -> string_literal = NULL;
	return new_expr;
}

struct expr * expr_create_string_literal( const char *str ) {
	struct expr * new_expr = malloc(sizeof * new_expr);
	new_expr -> kind = EXPR_STR;
	new_expr -> left = NULL;
	new_expr -> right = NULL;
	new_expr -> name = NULL;
	new_expr -> symbol = NULL;
	new_expr -> string_literal = str;
	return new_expr;
}

void expr_print( struct expr *e ) {
	int i;
	if (!e) { return; }
	// no parens unless given by the user
	if (e->kind==EXPR_GROUP) {
		printf("(");
	}
	expr_print(e->left);
	switch (e->kind) {
		case EXPR_ADD:	printf("+"); break;
		case EXPR_SUB:	printf("-"); break;
		case EXPR_MUL:	printf("*"); break;
		case EXPR_DIV:	printf("/"); break;
		case EXPR_EXP:	printf("^"); break;
		case EXPR_MOD:	printf("%c", '%'); break;
		case EXPR_GT:	printf(">"); break;
		case EXPR_GE:	printf(">="); break;
		case EXPR_LT:	printf("<"); break;
		case EXPR_LE:	printf("<="); break;
		case EXPR_NE:	printf("!="); break;
		case EXPR_EQ:	printf("=="); break;
		case EXPR_AND:	printf("&&"); break;
		case EXPR_OR:	printf("||"); break;
		case EXPR_NOT:	printf("!"); break;
		case EXPR_INCR:	printf("++"); break;
		case EXPR_DECR:	printf("--"); break;
		case EXPR_NEG:	printf("-"); break;
		case EXPR_ASSIGN:	printf("="); break;
		case EXPR_ARR:	printf("["); break;
		case EXPR_FUNCT:	printf("("); break;
		case EXPR_BOOL:	
			if (e->literal_value==1) {
				printf("true");
			} else {
				printf("false");
			} break;
		case EXPR_NAME:	printf("%s", e->string_literal); break;
		case EXPR_INT:	printf("%d", e->literal_value); break;
		case EXPR_CHAR:	
			if (e->literal_value==0x0A) {
				printf("'\\n'");
			}
			else if (e->literal_value==0x0) {
				printf("'\\0'");
			}
			else {
				printf("'%c'", e->literal_value); 
			}
			break;
		case EXPR_STR:
			printf("\"");
			for(i=0; i<strlen(e->string_literal); i++) {	
				if (e->string_literal[i]==0x0A) {
					printf("\\n");
				}
				else if (e->string_literal[i]==0x0) {
					printf("'\\0'");
				}
				else {
					printf("%c", e->string_literal[i]); 
				}
			}
			printf("\"");
			break;
		case EXPR_LIST:	
			if (e->right) {
				printf(", ");
			} 
			break;
		case EXPR_BLOCK:
			printf("{");
			break;
		case EXPR_ARR_LIST:
			if (e->right) {
				printf("][");
			}
			break;
	}
	expr_print(e->right);
	if (e->kind == EXPR_BLOCK) { printf("}");}
	if (e->kind == EXPR_FUNCT) { printf(")"); }
	if (e->kind == EXPR_ARR) { printf("]"); }
	// no parens unless given by the users
	if (e->kind==EXPR_GROUP) {
		printf(")");
	}
}

void expr_resolve(struct expr *e) {
	if (!e) return;
	expr_resolve(e->left);
	expr_resolve(e->right);
	if (e->kind == EXPR_NAME) {
		struct symbol * s = scope_lookup(e->name);
		if (s) {
			e->symbol = s;
			switch (s->kind) {
				case SYMBOL_LOCAL:
					printf("%s resolves to local %d\n", e->name, s->which);
					break;
				case SYMBOL_GLOBAL:
					printf("%s resolves to global %s\n", e->name, s->name);
					break;
				case SYMBOL_PARAM:
					printf("%s resolves to parameter %d\n", e->name, s->which);
					break;				
			}
		}
		else {
			printf("resolve error: variable %s not declared before use.\n", e->name);
			error_count++;
		}
	}
}

struct type * expr_typecheck(struct expr * e) {
	if (!e) { return type_create(TYPE_VOID, 0, 0); }
	struct type * L = expr_typecheck(e->left);
	struct type * R = expr_typecheck(e->right);
	struct type * arg;
	struct param_list * param_cursor;
	struct symbol * sym;
	struct expr * expr_cursor;
	int arg_count;
	int param_count;
	int counter = 0;
	switch (e->kind) {
		case EXPR_ADD:	// +
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot add ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_SUB:	// -
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot subtract ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(") from ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_MUL:	// *
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot multiply ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") with ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_DIV:	// /
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot divide ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") with ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_EXP:	// ^
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot use exponent on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_MOD:	// %
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot use modulo on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_GT:	// >
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot use greater than on ");
				type_print(L);
				printf(" and ");
				type_print(R);
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_GE:	// >=
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot use greater than or equal on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_LT:	// >
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot use less than on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_LE:	// >=
			if (L->kind!=TYPE_INTEGER || R->kind!=TYPE_INTEGER) {
				printf("type error: cannot use less than or equal on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_NE:	// !=
			if (L->kind==TYPE_ARRAY || L->kind==TYPE_FUNCTION || R->kind==TYPE_ARRAY || R->kind==TYPE_FUNCTION || L->kind != R->kind) {
				printf("type error: cannot use not equal on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_EQ:	// ==
			if (L->kind==TYPE_ARRAY || L->kind==TYPE_FUNCTION || R->kind==TYPE_ARRAY || R->kind==TYPE_FUNCTION || L->kind != R->kind) {
				printf("type error: cannot use equal on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_AND:	// &&
			if (L->kind!=TYPE_BOOLEAN || R->kind!=TYPE_BOOLEAN) {
				printf("type error: cannot use boolean logical and on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_OR:	// ||
			if (L->kind!=TYPE_BOOLEAN || R->kind!=TYPE_BOOLEAN) {
				printf("type error: cannot use boolean logical or on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_NOT:	// !
			if (R->kind!=TYPE_BOOLEAN) {
				printf("type error: cannot use boolean logical not on ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_INCR:	// ++
			if (L->kind!=TYPE_INTEGER) {
				printf("type error: cannot increment ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_DECR:	// --
			if (L->kind!=TYPE_INTEGER) {
				printf("type error: cannot decrement ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_NEG:	// -c
			if (R->kind!=TYPE_INTEGER) {
				printf("type error: cannot negate ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_ASSIGN:	// = 
			if (R->kind != L->kind || R->kind==TYPE_FUNCTION || L->kind==TYPE_FUNCTION) {
				printf("type error: cannot assign ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(") and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				error_count++;
			}
			return type_create(R->kind, 0, 0);
			break;
		case EXPR_ARR:	// array subscript
			printf("error: arrays not supported in cminor\n");
			exit(1);
			/*if (R->kind != TYPE_INTEGER) {
				printf("type error: cannot index array with ");
				type_print(R);
				printf(")\n");
				error_count++;
			}*/
			expr_typecheck(e->right);
//type_create_array(e->left->symbol->type->subtype->kind,0,e->left->symbol->type->subtype,0);
			break;
		case EXPR_ARR_LIST:
			if (L->kind != TYPE_INTEGER) {
				printf("type error: cannot index array with ");
				type_print(L);
				printf("(");
				expr_print(e->left);
				printf(")\n");
				error_count++;
			}
			if (e->right) {
				return expr_typecheck(e->right);
			}
			else {
				return expr_typecheck(e->left);
			}
			break;
		case EXPR_FUNCT:	// function call
			sym = scope_lookup(e->left->name);
			expr_cursor = e->right;
			param_cursor = sym->type->params;
			param_count = 0;
			arg_count = 0;
			// count number of args
			while (expr_cursor) {
				arg_count++;
				expr_cursor = expr_cursor->right;
			}
			// count number of params
			while (param_cursor) {
				param_count++;
				param_cursor = param_cursor->next;
			}
			// compare arg_count to param_count for first check of function calls
			if (arg_count != param_count) {
				printf("type error: %d arguments passed into function %s, which requires %d arguments", arg_count, e->left->name, param_count);
				error_count++;
				return type_create(sym->type->subtype->kind,0,0);
			}
			expr_cursor = e->right;
			param_cursor = sym->type->params;
			if (arg_count==1) {
				if (!type_compare(expr_typecheck(expr_cursor->left), param_cursor->type)) {
					printf("type error: argument 1 of function %s is of type ", e->left->name);
					type_print(expr_typecheck(expr_cursor->left));
					printf(" (");
					expr_print(e->right);
					printf(") when ");
					type_print(param_cursor->type);
					printf(" is required\n");
					error_count++;
				}
			}
			else {
				counter = 0;
				while (expr_cursor) {
					counter++;
					if (!type_compare(expr_typecheck(expr_cursor->left), param_cursor->type)) {
						printf("type error: argument %d of function %s  is of the type ", counter, e->left->name);
						type_print(expr_typecheck(expr_cursor->left));
						printf(" (");
						expr_print(expr_cursor->left);
						printf(") when ");
						type_print(param_cursor->type);
						printf(" is required\n");
						error_count++;
					}
					if (expr_cursor) {
						expr_cursor = expr_cursor->right;
					}
					param_cursor = param_cursor->next;
				}
			}
			return type_create(sym->type->subtype->kind,0,0);
			break;
		case EXPR_GROUP:
			return type_create(L->kind,0,0);
			break;
		case EXPR_BLOCK:	// for expr lists of expr lists (for arrays of arrays)
			expr_cursor = e->right;
			while (expr_cursor) {
				if (expr_cursor->kind==EXPR_LIST) {
					if (!expr_cursor->right) {
						counter++;//=2;
						break;
					}
					else {
						counter++;
						expr_cursor = expr_cursor->right;
					}
				}
				else {
					counter++;
					break;
				}
			}
			return expr_typecheck(e->right);
			break;
		case EXPR_BOOL:	// true/false
			return type_create(TYPE_BOOLEAN, 0, 0);
			break;
		case EXPR_NAME:	// ident
			return e -> symbol -> type;
			break;
		case EXPR_INT:	// #'s
			return type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_CHAR:
			return type_create(TYPE_CHARACTER, 0, 0);
			break;
		case EXPR_STR:
			return type_create(TYPE_STRING, 0, 0);
			break;
		case EXPR_LIST:
			expr_cursor = e->right;
			while (expr_cursor) {
				if (expr_cursor->kind==EXPR_LIST) {
					if (!expr_cursor->right) {
						counter+=2;
						break;
					}
					else {
						counter++;
						expr_cursor = expr_cursor->right;
					}
				}
				else {
					counter++;
					break;
				}
			}
			return type_create_array(TYPE_ARRAY, 0, expr_typecheck(e->left), expr_create_integer_literal(counter));
			break;
	}
}

void expr_codegen(struct expr *e, FILE * output) {
	char buffer[200];
	char args_reg[6][100] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};		// all of the argument registers for function calls
	if(!e) return;
	//if (e->kind!=EXPR_ASSIGN) {
	//	expr_codegen(e->left, output);
	//}
	//expr_codegen(e->right, output);
	struct expr * expr_cursor;
	switch (e->kind) {
		case EXPR_ADD:		// +
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tADD %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
			e->reg = e->right->reg;
			register_free(e->left->reg);
			break;
		case EXPR_SUB:		// -
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tSUB %s, %s\n", register_name(e->right->reg), register_name(e->left->reg));
			e->reg = e->left->reg;
			register_free(e->right->reg);
			break;
		case EXPR_MUL:		// *
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tMOV %s, %%rax\n", register_name(e->left->reg));
			fprintf(output, "\tIMUL %s\n", register_name(e->right->reg));
			fprintf(output, "\tMOV %%rax, %s\n", register_name(e->right->reg));
			register_free(e->left->reg);
			e->reg = e->right->reg;
			break;
		case EXPR_DIV:		// /
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tMOV %s, %%rax\n", register_name(e->left->reg));
			fprintf(output, "\tCQTO\n");
			fprintf(output, "\tIDIV %s\n", register_name(e->right->reg));
			fprintf(output, "\tMOV %%rax, %s\n", register_name(e->right->reg));
			register_free(e->left->reg);
			e->reg = e->right->reg;
			break;
		case EXPR_EXP:		// ^
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tPUSHQ %%r10\n");
			fprintf(output, "\tPUSHQ %% r11\n");
			// push arguments in argument registers (2 args because exp takes 2)
			fprintf(output, "\tMOV %s, %%rdi\n", register_name(e->left->reg));
			fprintf(output, "\tMOV %s, %%rsi\n", register_name(e->right->reg));
			fprintf(output, "\tCALL integer_power\n");
			// pop arguments
			fprintf(output, "\tPOPQ %%r11\n");
			fprintf(output, "\tPOPQ %%r10\n");
			// get answer from return register
			fprintf(output, "\tMOV %%rax, %s\n", register_name(e->right->reg));
			e->reg = e->right->reg;
			register_free(e->left->reg);
			break;
		case EXPR_MOD:		// %
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tMOV %s, %%rax\n", register_name(e->left->reg));
			fprintf(output, "\tCQTO\n");
			fprintf(output, "\tIDIV %s\n", register_name(e->right->reg));
			fprintf(output, "\tMOV %%rdx, %s\n", register_name(e->right->reg));
			e->reg = e->right->reg;
			register_free(e->left->reg);
			break;
		case EXPR_GT:		// >
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
			fprintf(output, "\tJGE .L%d\n", label_count);
			fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
			fprintf(output, "\tJMP .L%d\n", label_count+1);
			fprintf(output, "\t.L%d:\n", label_count);
			fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
			fprintf(output, "\t.L%d:\n", label_count+1);
			label_count += 2;
			register_free(e->left->reg);
			e->reg = e->right->reg;
			break;
		case EXPR_GE:		// >=
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
			fprintf(output, "\tJG .L%d\n", label_count);
			fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
			fprintf(output, "\tJMP .L%d\n", label_count+1);
			fprintf(output, "\t.L%d:\n", label_count);
			fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
			fprintf(output, "\t.L%d:\n", label_count+1);
			label_count += 2;
			register_free(e->left->reg);
			e->reg = e->right->reg;
			break;
		case EXPR_LT:		// >
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
			fprintf(output, "\tJLE .L%d\n", label_count);
			fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
			fprintf(output, "\tJMP .L%d\n", label_count+1);
			fprintf(output, "\t.L%d:\n", label_count);
			fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
			fprintf(output, "\t.L%d:\n", label_count+1);
			label_count += 2;
			register_free(e->left->reg);
			e->reg = e->right->reg;
			break;
		case EXPR_LE:		// >=
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
			fprintf(output, "\tJL .L%d\n", label_count);
			fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
			fprintf(output, "\tJMP .L%d\n", label_count+1);
			fprintf(output, "\t.L%d:\n", label_count);
			fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
			fprintf(output, "\t.L%d:\n", label_count+1);
			label_count += 2;
			register_free(e->left->reg);
			e->reg = e->right->reg;
			break;
		case EXPR_NE:		// !=
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			if((e->left->kind==EXPR_STR && e->right->kind==EXPR_STR) || (e->left->kind == EXPR_NAME && e->left->symbol->type->kind == TYPE_STRING) || (e->right->kind == EXPR_NAME && e->right->symbol->type->kind == TYPE_STRING)) {	// handle strings
				fprintf(output,"\tPUSHQ %%r10\n");
				fprintf(output,"\tPUSHQ %%r11\n");
				fprintf(output,"\tMOV %s, %%rdi\n",register_name(e->left->reg));
				fprintf(output,"\tMOV %s, %%rsi\n",register_name(e->right->reg));
				fprintf(output,"\tCALL strcmp\n");
				fprintf(output,"\tPOPQ %%r11\n");
				fprintf(output,"\tPOPQ %%r10\n");
				fprintf(output,"\tCMP $0, %%rax\n");
				fprintf(output,"\tJNE .L%d\n",label_count);
				label_count++;
				fprintf(output,"\tMOV $0, %s\n",register_name(e->right->reg));
				fprintf(output,"\tJMP .L%d\n",label_count);
				label_count++;
				fprintf(output,".L%d:\n",label_count-2);
				fprintf(output,"\tMOV $1, %s\n",register_name(e->right->reg));
				fprintf(output,".L%d:\n",label_count-1);
				e->reg = e->right->reg;
				register_free(e->left->reg);
			}
			else {	// all non strings
				e->reg = e->left->reg;
				fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
				fprintf(output, "\tJE .L%d\n", label_count);
				fprintf(output, "\tMOV $1, %s\n", register_name(e->reg));
				fprintf(output, "\tJMP .L%d\n", label_count+1);
				fprintf(output, "\t.L%d:\n", label_count);
				fprintf(output, "\tMOV $0, %s\n", register_name(e->reg));
				fprintf(output, "\t.L%d:\n", label_count+1);
				label_count += 2;
				register_free(e->right->reg);
			}
			break;
		case EXPR_EQ:
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			if((e->left->kind == EXPR_STR && e->right->kind == EXPR_STR) || (e->left->kind == EXPR_NAME && e->left->symbol->type->kind == TYPE_STRING) || (e->right->kind == EXPR_NAME && e->right->symbol->type->kind == TYPE_STRING) ){
				fprintf(output,"\tPUSHQ %%r10\n");
				fprintf(output,"\tPUSHQ %%r11\n");
				fprintf(output,"\tMOV %s, %%rdi\n",register_name(e->left->reg));
				fprintf(output,"\tMOV %s, %%rsi\n",register_name(e->right->reg));
				fprintf(output,"\tCALL strcmp\n");
				fprintf(output,"\tPOPQ %%r11\n");
				fprintf(output,"\tPOPQ %%r10\n");
				fprintf(output,"\tCMP $0, %%rax\n");
				fprintf(output,"\tJE .L%d\n",label_count);
				label_count++;
				fprintf(output,"\tMOV $0, %s\n",register_name(e->right->reg));
				fprintf(output,"\tJMP .L%d\n",label_count);
				label_count++;
				fprintf(output,".L%d:\n",label_count-2);
				fprintf(output,"\tMOV $1, %s\n",register_name(e->right->reg));
				fprintf(output,".L%d:\n",label_count-1);
				e->reg = e->right->reg;
				register_free(e->left->reg);
			} 
			else {
				e->reg = e->left->reg;
				fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
				fprintf(output, "\tJNE .L%d\n", label_count);
				fprintf(output, "\tMOV $1, %s\n", register_name(e->reg));
				fprintf(output, "\tJMP .L%d\n", label_count+1);
				fprintf(output, "\t.L%d:\n", label_count);
				fprintf(output, "\tMOV $0, %s\n", register_name(e->reg));
				fprintf(output, "\t.L%d:\n", label_count+1);
				label_count += 2;
				register_free(e->right->reg);
			}
			break;
		case EXPR_AND:		// &&
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tAND %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
			e->reg = e->right->reg;
			register_free(e->left->reg);
			break;
		case EXPR_OR:		// ||
			expr_codegen(e->left, output);
			expr_codegen(e->right, output);
			fprintf(output, "\tOR %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
			e->reg = e->right->reg;
			register_free(e->left->reg);
			break;
		case EXPR_NOT:		// !
			expr_codegen(e->right, output);
			fprintf(output, "\tXOR $1, %s\n", register_name(e->right->reg));
			e->reg = e->right->reg;
			break;
		case EXPR_INCR:		// ++
			expr_codegen(e->left, output);
			e->reg = e->left->reg;
			fprintf(output, "\tINC %s\n", register_name(e->reg));
			symbol_code(e->left->symbol, buffer);
			fprintf(output, "\tMOV %s, %s\n", register_name(e->reg), buffer);
			break;
		case EXPR_DECR:		// --
			expr_codegen(e->left, output);
			e->reg = e->left->reg;
			fprintf(output, "\tDEC %s\n", register_name(e->reg));
			symbol_code(e->left->symbol, buffer);
			fprintf(output, "\tMOV %s, %s\n", register_name(e->reg), buffer);
			break;
		case EXPR_NEG:		// -c
			//fprintf(output, "\tMOV %s, %s\n", register_name(e->right->reg), register_name(e->reg));
			expr_codegen(e->right, output);
			fprintf(output, "\tNEG %s\n", register_name(e->right->reg));
			e->reg = e->right->reg;
			break;
		case EXPR_ASSIGN:	// = 
			expr_codegen(e->right, output);
			symbol_code(e->left->symbol, buffer);
			if (e->left->symbol->kind==SYMBOL_GLOBAL && e->left->symbol->type->kind == TYPE_STRING) {
				fprintf(output,"\tMOV %s, .%s_address\n",register_name(e->right->reg), buffer);
			}
			else {
				fprintf(output, "\tMOV %s, %s\n", register_name(e->right->reg), buffer);
			}
			e->reg = e->right->reg;
			break;
		case EXPR_ARR:		// array subscript
			printf("codegen error: arrays are not supported in cminor\n");
			exit(1);
			break;
		case EXPR_ARR_LIST:	// multi dimensional array subscript
			printf("codegen error: arrays are not supported in cminor\n");
			exit(1);
			break;
		case EXPR_FUNCT:	// function call
			arg_count = 0; 	// reinitialize the global argument count
			e->reg = register_alloc();
			// push callee saved registers
			fprintf(output, "\tPUSHQ %%r10\n");
			fprintf(output, "\tPUSHQ %%r11\n");
			// handle arguments
			if (e->right /*at least 1 arg*/ && e->right->kind != EXPR_LIST /*not more than 1 arg*/) {
				expr_codegen(e->right, output);
				fprintf(output, "\tMOV %s, %%rdi\n", register_name(e->right->reg));	// move arg into argument register
				register_free(e->right->reg);
				arg_count++;
			}
			else { // not exactly 1 arg
				expr_codegen(e->right, output);		// leads to EXPR_LIST
			}
			// call function
			fprintf(output, "\tCALL %s\n", e->left->name);
			// pop callee saved registers
			fprintf(output, "\tPOPQ %%r11\n");
			fprintf(output, "\tPOPQ %%r10\n");
			// move function return value into register
			fprintf(output, "\tMOV %%rax, %s\n", register_name(e->reg));
			break;
		case EXPR_GROUP:
			expr_codegen(e->left, output);
			e->reg = e->left->reg;
			break;
		case EXPR_BLOCK:	// for expr lists of expr lists (for arrays of arrays)
			printf("codegen error: arrays are not supported in cminor\n");
			exit(1);
			break;
		case EXPR_NAME:		// ident
			e->reg = register_alloc();
			symbol_code(e->symbol, buffer);
			if(e->symbol->kind == SYMBOL_GLOBAL && e->symbol->type->kind == TYPE_STRING) {		// case where e is a global string
				fprintf(output,"\tMOV .%s_address, %s\n",buffer,register_name(e->reg));	// move the register name into e->reg
			} else {
				fprintf(output,"\tMOV %s, %s\n",buffer,register_name(e->reg));	// move the register name into e->reg
			}
			break;
		case EXPR_BOOL:		// true/false
		case EXPR_INT:		// #'s
		case EXPR_CHAR:		//characters
			e->reg = register_alloc();
			fprintf(output, "\tMOV $%d, %s\n", e->literal_value, register_name(e->reg));
			break;
		case EXPR_STR:
			e->reg = register_alloc();
			fprintf(output, "\t.data\n");
			//symbol_code(e->symbol, buffer);
			fprintf(output, "\t.STR%d: .string ", string_count);
			expr_get_string(e, output );
			fprintf(output, "\n");
			fprintf(output, "\t.text\n");
			fprintf(output, "\tLEA .STR%d, %s\n", string_count, register_name(e->reg));
			string_count++;
			break;
		case EXPR_LIST:		// used for function calls with multiple arguments
			expr_cursor = e;	// initialize cursor
			while(expr_cursor) {
				expr_codegen(expr_cursor->left, output);
				fprintf(output, "\tMOV %s, %s\n", register_name(expr_cursor->left->reg), args_reg[arg_count]);
				arg_count++;
				register_free(expr_cursor->left->reg);
				expr_cursor = expr_cursor->right;
			}
			break;
	}
}

void expr_print_codegen(struct expr *e, FILE * output) {
	//printf("enter expr_print_codegen\n");
	struct type *t = expr_typecheck(e);
	expr_codegen(e, output);
	//printf("after expr_codegen\n");
	fprintf(output, "\tPUSHQ %%rdi\n");
	fprintf(output, "\tPUSHQ %%r10\n");
	fprintf(output, "\tPUSHQ %% r11\n");
	fprintf(output, "\tMOV %s, %%rdi\n", register_name(e->reg));
	switch(t->kind) {
		case TYPE_INTEGER:
			fprintf(output, "\tCALL print_integer\n");
			break;
		case TYPE_BOOLEAN:
			fprintf(output, "\tCALL print_boolean\n");
			break;
		case TYPE_CHARACTER:
			fprintf(output, "\tCALL print_character\n");
			break;
		case TYPE_STRING:
			fprintf(output, "\tCALL print_string\n");
			break;
		default:
			printf("error: attempt to print unprintable expression\n");
	}
	fprintf(output, "\tPOPQ %%r11\n");
	fprintf(output, "\tPOPQ %%r10\n");
	fprintf(output, "\tPOPQ %%rdi\n");
	register_free(e->reg);
	//printf("after fprintfs\n");
}

void expr_get_string(struct expr *e, FILE * output) {
	int i;
	fprintf(output, "\"");
	for(i=0; i<strlen(e->string_literal); i++) {	
		if (e->string_literal[i]==0x0A) {
			fprintf(output, "\\n");
		}
		else if (e->string_literal[i]==0x0) {
			fprintf(output, "\\0");
		}
		else {
			fprintf(output, "%c", e->string_literal[i]); 
		}
	}
	fprintf(output, "\"");
}

int expr_compare(struct expr * a, struct expr * b) {
	if (!a && !b) {
		return 1;
	}
	else if ((!a && b) || (a && !b)) {
		return 0;
	}
	else {
		if (!(a->name) && !(b->name) && !(a->string_literal) && !(b->string_literal)){ 
			return (a->kind==b->kind) && expr_compare(a->left, b->left) && expr_compare(a->right, b->right) && symbol_compare(a->symbol, b->symbol) && (a->literal_value==b->literal_value);
		}
		else if (!(a->string_literal) && !(b->string_literal)) {
			return (a->kind==b->kind) && expr_compare(a->left, b->left) && expr_compare(a->right, b->right) && !strcmp(a->name, b->name) && symbol_compare(a->symbol, b->symbol) && (a->literal_value==b->literal_value);
		}
		else if (!(a->name) && !(b->name)) {
			return (a->kind==b->kind) && expr_compare(a->left, b->left) && expr_compare(a->right, b->right) && symbol_compare(a->symbol, b->symbol) && (a->literal_value==b->literal_value) && !strcmp(a->string_literal, b->string_literal);
		}
		else if (!(a->name) || !(b->name) || !(a->string_literal) || !(b->string_literal)) {
			return 0;
		}
		else {
			return (a->kind==b->kind) && expr_compare(a->left, b->left) && expr_compare(a->right, b->right) && !strcmp(a->name, b->name) && symbol_compare(a->symbol, b->symbol) && (a->literal_value==b->literal_value) && !strcmp(a->string_literal, b->string_literal);
		}
	}
}

int is_constant(struct expr * e) {
	if (!e) { return 0; }
	if (e->kind==EXPR_INT || e->kind==EXPR_BOOL || e->kind==EXPR_CHAR || e->kind==EXPR_STR || e->kind==EXPR_LIST) { 
		return 1; 
	}
}
