#include "decl.h"
#include "expr.h"
#include "symbol.h"
#include "global.h"
#include "scope.h"
#include <string.h>
#include <stdio.h>

extern error_count;

struct decl * decl_create( char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next ) {
	struct decl * new_decl = malloc(sizeof *new_decl);
	new_decl -> name = name;
	new_decl -> type = t; //type_create_array(t->kind, t->params, t->subtype, t->expr);
	new_decl -> value = v;
	new_decl -> code = c;
	new_decl -> next = next;
	return new_decl;
}

void decl_print( struct decl *d, int indent ) {
	if (!d) { return; }
	printf("\n");
	printf("%*s", indent, "");
	printf("%s: ", d->name);
	type_print(d->type);
	if (d->value) {
		printf(" = ");
		if (d->value->kind==EXPR_LIST) {	// array with one item in them???
			printf("{ ");		// name : array [3] integer = {1,2,3};
			expr_print(d->value);
			printf(" };");
		}
		else {			// name : integer = 5;
			expr_print(d->value);
			printf(";");
		}
	}
	else if (d->code) {	// name: function void ( x : integer) = { print "hello world"; }
		printf(" = {");
		stmt_print(d->code, indent+4);
		printf("%*s", indent, "");
		printf("\n}");
		
	} 
	else {		// name : integer;
		printf(";");
	}
	decl_print(d->next, indent);
}

void decl_resolve(struct decl *d) {
	if (!d) { return; }
	struct symbol * sym;
	if (scope_lookup_single(d->name)) {
		if (scope_lookup_single(d->name)->type->kind!=TYPE_FUNCTION || scope_lookup_single(d->name)->code==1) {	// code already exists for this function or is non-function already declared
			printf("resolve error: variable %s already declared in this scope\n", d->name);
			error_count++;
		}
		else {	// function without code
			d->symbol = scope_lookup_single(d->name);
			//printf("%s resolves to global %s\n", d->name, d->symbol->name);
			if (d->code) { // function prototypes exist, but no code yet, adding code
				if (!type_compare(scope_lookup_single(d->name)->type, d->type)) {
					printf("resolve error: %s is already declared in this scope with different parameters/return values\n", d->name);
					error_count++;
				}
				else {
					d->symbol = scope_lookup_single(d->name);
					printf("%s resolves to global %s\n", d->name, d->symbol->name);
					d->symbol->code = 1;
					scope_enter();
					param_list_resolve(d->type->params);
					stmt_resolve(d->code);
					scope_exit();
				}
			}
			else { // function prototypes exist, but no code yet, second prototype of function
				if (!type_compare(scope_lookup_single(d->name)->type, d->type)) {
					printf("resolve error: %s is already declared in this scope with different parameters/return values\n", d->name);
					error_count++;
				}
				else {
					d->symbol = scope_lookup_single(d->name);
					printf("%s resolves to global %s\n", d->name, d->symbol->name);
					scope_enter();
					param_list_resolve(d->type->params);
					stmt_resolve(d->code);
					scope_exit();
				}
			}
		}
	}
	else {
		if (scope_level()==1) {	// is global
			sym = symbol_create( SYMBOL_GLOBAL, d->type, d->name);
			printf("%s resolves to global %s\n", d->name, sym->name);
		}
		else {
			sym = symbol_create( SYMBOL_LOCAL, d->type, d->name);
			sym->which = scope_increment_local();
			printf("%s resolves to local %d\n", d->name, sym->which);
		}
		d->symbol = sym;
		scope_bind(d->name, sym);
		expr_resolve(d->value);
		if (d->code) {
			d->symbol->code = 1;
			scope_enter();
			param_list_resolve(d->type->params);
			stmt_resolve(d->code);
			int * temp = hash_table_lookup(h, "0l_count");
			d->symbol->num_locals = (*temp);
			scope_exit();
		}
		//else if ((scope_lookup_single(d->name))->type->kind!=TYPE_FUNCTION) {
		//	param_list_resolve(d->type->params);
		//}
	}
	decl_resolve(d->next);
}

void decl_typecheck(struct decl *d) {
	if (!d) { return; }	// null
	if (d->value) {		// if it has a value and isn't a function
		struct type * t = expr_typecheck(d->value);
		if (!type_compare(d->type, t)) {
			printf("type error: cannot declare ");
			type_print(d->type);
			printf(" (%s) with value of type ", d->name);
			type_print(t);
			printf(" (");
			expr_print(d->value);
			printf(")\n");
			error_count++;
		}
		if (d->symbol->kind == SYMBOL_GLOBAL && !is_constant(d->value)) {
			printf("type error: cannot declare variable %s in global scope with non-constant value (", d->name);
			expr_print(d->value);
			printf(")\n");
			error_count++;
		}
	}
	if (d->code) {	// function declarations (func: function return_type (param) = {})
		stmt_typecheck(d->code, d);	// check stmts and return value
	}
	// don't need to check prototypes
	decl_typecheck(d->next);
}

void decl_codegen(struct decl *d, FILE * output) {
	char buffer[200];
	if (!d) return;
	if (d->symbol->kind==SYMBOL_GLOBAL) {
		switch(d->type->kind) {
			case TYPE_BOOLEAN:
			case TYPE_CHARACTER:
			case TYPE_INTEGER:
				if (d->value) {
					fprintf(output, ".data\n");
					symbol_code(d->symbol, buffer);
					fprintf(output, "%s: .quad %d\n", buffer, d->value->literal_value);
				}
				else {
					fprintf(output, ".data\n");
					symbol_code(d->symbol, buffer);
					fprintf(output, "%s: .quad %d\n", buffer, 0);
				}
				break;
			case TYPE_STRING:
				if (d->value) {
					fprintf(output, ".data\n");
					symbol_code(d->symbol, buffer);
					fprintf(output, "%s: .string ", buffer);
					expr_get_string(d->value, output );
					fprintf(output, "\n");
					fprintf(output,".%s_address: .quad %s\n",buffer,buffer);
				}
				else {
					fprintf(output, ".data\n");
					symbol_code(d->symbol, buffer);
					fprintf(output, "%s: .string %s\n", buffer, "\"\"");
					fprintf(output,".%s_address: .quad %s\n",buffer,buffer);
				}
				break;
			case TYPE_FUNCTION:
				if (d->code) {
					// preamble
					symbol_code(d->symbol, buffer);
					fprintf(output, ".text\n.globl %s\n%s:\n", buffer, buffer);
					fprintf(output, "\t### function preamble ###\n");
					fprintf(output, "\tPUSHQ %%rbp\n");          	// save the base pointer
					fprintf(output, "\tMOVQ  %%rsp, %%rbp\n");    	// set new base pointer
					fprintf(output, "\tPUSHQ %%rdi\n");          	// save first argument on the stack
					fprintf(output, "\tPUSHQ %%rsi\n");         	// save second argument on the stack
					fprintf(output, "\tPUSHQ %%rdx\n");          	// save third argument on the stack
					fprintf(output, "\tPUSHQ %%rcx\n");          	// save fourth argument on the stack
					fprintf(output, "\tPUSHQ %%r8\n");         	// save fifth argument on the stack
					fprintf(output, "\tPUSHQ %%r9\n");          	// save sixth argument on the stack
					if (d->symbol->num_locals!=0) {
						fprintf(output, "\tSUBQ  $%d, %%rsp\n", d->symbol->num_locals*8);     	// allocate space for local variables
					}
					fprintf(output, "\tPUSHQ %%rbx\n");          	// save callee-saved registers
					fprintf(output, "\tPUSHQ %%r12\n");
					fprintf(output, "\tPUSHQ %%r13\n");
					fprintf(output, "\tPUSHQ %%r14\n");
					fprintf(output, "\tPUSHQ %%r15\n\n");
					// function body
					fprintf(output, "\t### function body ###\n");
					stmt_codegen(d->code, output);
					// postamble
					fprintf(output, "\n\t### function postamble ###\n");
					fprintf(output, "\t.ret%d:\n", ret_count);
					ret_count++;		// for next return label
					fprintf(output, "\tPOPQ %r15\n");          	// restore callee-saved registers
					fprintf(output, "\tPOPQ %r14\n");
					fprintf(output, "\tPOPQ %r13\n");
					fprintf(output, "\tPOPQ %r12\n");
					fprintf(output, "\tPOPQ %rbx\n");
					fprintf(output, "\tMOVQ %rbp, %rsp\n");    	// reset stack to base pointer.
					fprintf(output, "\tPOPQ %rbp\n");          	// restore the old base pointer
					fprintf(output, "\tRET\n");                	// return to caller
				}
				break;
			default:
				printf("codegen error: incorrect declaration type\n");
				exit(1);
				break;
		}
	}
	else if (d->symbol->kind == SYMBOL_LOCAL) {	// local declarations
		struct expr * e;
		switch(d->type->kind) {
			case TYPE_BOOLEAN:
			case TYPE_CHARACTER:
			case TYPE_INTEGER:
				if (d->value) {	// has value assigned in decl
					expr_codegen(d->value, output);
					symbol_code(d->symbol, buffer);
					fprintf(output, "\tMOV %s, %s\n", register_name(d->value->reg), buffer);
					register_free(d->value->reg);
				}
				else { // no value, just initialized
					symbol_code(d->symbol, buffer);
					e = expr_create_integer_literal(0);	// initialize expr object to work with its reg
					e->reg = register_alloc();
					fprintf(output, "\tMOV $0, %s\n", register_name(e->reg));
					fprintf(output, "\tMOV %s, %s\n", register_name(e->reg), buffer);
					register_free(e->reg);
				}
				break;
			case TYPE_STRING:
				if (d->value) {
					expr_codegen(d->value, output);
					symbol_code(d->symbol, buffer);
					fprintf(output, "\tMOV %s, %s\n", register_name(d->value->reg), buffer);
					register_free(d->value->reg);
				}
				else {
					e = expr_create_string_literal("");
					e->reg = register_alloc();
					fprintf(output, "\t.data\n");
					fprintf(output, "\t.STR%d: \n", string_count);
					fprintf(output, "\t.string \"\"\n");
					fprintf(output, "\t.text\n");
					fprintf(output, "\tLEA .STR%d, %s\n", string_count, register_name(e->reg));
					string_count++;
					symbol_code(d->symbol, buffer);
					fprintf(output, "\tMOV %s, %s\n",  register_name(e->reg), buffer);
					register_free(e->reg);
				}
				break;
			case TYPE_FUNCTION:
				// this shouldn't happen, can't declare functions within functions
				break;
			default:
				printf("code error: invalid declaration type\n");
				exit(1);
				break;
		}
	}
	decl_codegen(d->next, output);
}

int decl_compare(struct decl * a, struct decl * b) {
	if (!a && !b) {
		return 1;
	}
	else if ((!a && b) || (a && !b)) {
		return 0;
	}
	else {
		return (!strcmp(a->name,b->name) && type_compare(a->type, b->type) && expr_compare(a->value, b->value) && stmt_compare(a->code, b->code) && symbol_compare(a->symbol, b->symbol) && decl_compare(a->next, b->next));
	}
}
