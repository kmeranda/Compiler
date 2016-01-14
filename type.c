#include "type.h"

struct type * type_create( type_kind_t kind, struct param_list *params, struct type *subtype) {
	struct type * new_type = malloc(sizeof * new_type);
	new_type -> kind = kind;
	new_type -> params = params;
	new_type -> subtype = subtype;
	new_type -> expr = NULL;
	return new_type;
}

struct type * type_create_array( type_kind_t kind, struct param_list *params, struct type *subtype, struct expr *expr) {
	struct type * new_type = malloc(sizeof * new_type);
	new_type -> kind = kind;
	new_type -> params = params;
	new_type -> subtype = subtype;
	new_type -> expr = expr;
	return new_type;
}

void type_print( struct type *t ) {
	if (!t) {
		printf("NULL");
		return; 
	}
	switch (t->kind) {
		case TYPE_BOOLEAN:
			printf("boolean");
			break;
		case TYPE_CHARACTER:
			printf("character");
			break;
		case TYPE_INTEGER:
			printf("integer");
			break;
		case TYPE_STRING:
			printf("string");
			break;
		case TYPE_ARRAY:
			printf("array [");
			expr_print(t->expr);
			printf("] ");
			type_print(t->subtype);
			break;
		case TYPE_FUNCTION:
			printf("function ");
			type_print(t->subtype);
			printf("( ");
			param_list_print(t->params);
			printf(" )");
			break;
		case TYPE_VOID:
			printf("void");
			break;
	}
}

int type_compare(struct type * a, struct type * b) {
	if (!a && !b) {
		return 1;
	}
	else if ((!a || !b)) {
		return 0;
	}
	else {
		return (a->kind==b->kind) && param_list_compare(a->params, b->params) && type_compare(a->subtype, b->subtype) && expr_compare(a->expr, b->expr);
	}
}




