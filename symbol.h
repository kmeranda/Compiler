#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"
//#include "scope.h"

typedef enum {
	SYMBOL_LOCAL,
	SYMBOL_PARAM,
	SYMBOL_GLOBAL
} symbol_t;

struct symbol {
	symbol_t kind;
	int which;
	struct type *type;
	char *name;
	int code;
	int num_locals;
};

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name );
int symbol_compare(struct symbol * a, struct symbol * b);
void symbol_code(struct symbol * s, char * buffer);

#endif
