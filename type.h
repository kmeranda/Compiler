#ifndef TYPE_H
#define TYPE_H

//#include "symbol.h"
#include "param_list.h"
#include <stdlib.h>

typedef enum {
	TYPE_BOOLEAN,
	TYPE_CHARACTER,
	TYPE_INTEGER,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_FUNCTION,
	TYPE_VOID
} type_kind_t;

struct type {
	type_kind_t kind;
	struct param_list *params;
	struct type *subtype;
	struct expr *expr;
};

struct type * type_create( type_kind_t kind, struct param_list *params, struct type *subtype);
struct type * type_create_array( type_kind_t kind, struct param_list *params, struct type *subtype, struct expr * expr);
void          type_print( struct type *t );
int type_compare(struct type * a, struct type * b);


#endif
