#include "symbol.h"
#include <string.h>

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ) {
	struct symbol * sym = malloc(sizeof * sym);
	sym -> name = name;
	sym -> type = type;
	sym -> kind = kind;
	sym -> num_locals = -1;
	return sym;
}

int symbol_compare(struct symbol * a, struct symbol * b) {
	if (!a && !b) {
		return 1;
	}
	else if ((!a || !b)) {
		return 0;
	}
	else {
		if (!(a->name) && !(b->name)) {
			return (a->kind==b->kind) && (a->which==b->which) && type_compare(a->type, b->type) && (a->code==b->code);
		}
		else if (!(a->name) || !(b->name)) {
			return 0;
		}
		else {
			return (a->kind==b->kind) && (a->which==b->which) && type_compare(a->type, b->type) && !strcmp(a->name, b->name) && (a->code==b->code);
		}
	}
}

void symbol_code(struct symbol * s, char * buffer) {
	if (s->kind==SYMBOL_GLOBAL) {
		sprintf(buffer, "%s", s->name);
	}
	else if (s->kind==SYMBOL_PARAM) {
		sprintf(buffer, "-%d(%%rbp)", 8+8*(s->which));
	}
	else if (s->kind==SYMBOL_LOCAL) {
		sprintf(buffer, "-%d(%%rbp)", 56+8*(s->which));
	}
}
