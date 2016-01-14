#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "symbol.h"
#include "type.h"
#include "expr.h"
#include "scope.h"
#include <stdio.h>
#include <stdlib.h>

struct expr;

struct param_list {
	char *name;
	struct type *type;
	struct symbol *symbol;
	struct param_list *next;
};

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next );
void param_list_print( struct param_list *a );
void param_list_resolve( struct param_list *p );
int param_list_compare(struct param_list * a, struct param_list * b);

#endif
