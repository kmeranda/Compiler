#include "param_list.h"
#include <string.h>

extern int error_count;

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ) {
	struct param_list * new_param_list = malloc(sizeof * new_param_list);
	new_param_list -> name = name;
	new_param_list -> type = type;
	new_param_list -> symbol = NULL;
	new_param_list -> next = next;
	return new_param_list;
}

void param_list_print( struct param_list *a ) {
	if (!a) {return;}
	printf("%s: ", a->name);
	type_print(a->type);
	if (a->next) {
		printf(", ");
		param_list_print(a->next);
	}
}

void param_list_resolve( struct param_list *p ) {
	if(!p) { return; }
	if (scope_lookup_single(p->name)) {
		printf("resolve error: redefinition of already existing variable %s.\n", p->name);
		error_count++;
	}
	else {
		struct symbol * sym = symbol_create(SYMBOL_PARAM, p->type, p->name);
		scope_bind(p->name, sym);
		int * temp = hash_table_lookup(h, "0p_count");
		if ((*temp) >= 6) {
			printf("resolve error: function cannot have more than 6 parameters.\n");
			exit(1);
		}
		sym->which = *temp;
		printf("%s resolves to parameter %d\n", p->name, sym->which);
		(*temp)++;
		p->symbol = sym;
	}
	param_list_resolve(p->next);
}

int param_list_compare(struct param_list * a, struct param_list * b) {
	if (!a && !b) {
		return 1;
	}
	else if ((!a || !b)) {
		return 0;
	}
	else {
		if (!(a->name) && !(b->name)) {
			return param_list_compare(a->next, b->next) && type_compare(a->type, b->type) && symbol_compare(a->symbol, b->symbol);
		}
		else if (!(a->name) || !(b->name)) {
			return 0;
		}
		else {
			return !strcmp(a->name, b->name) && param_list_compare(a->next, b->next) && type_compare(a->type, b->type) && symbol_compare(a->symbol, b->symbol);
		}
	}
}
