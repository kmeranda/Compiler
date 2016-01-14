#ifndef STMT_H
#define STMT_H

#include "type.h"
#include "symbol.h"
#include "decl.h"
#include "scope.h"
#include "global.h"
#include "register.h"
#include <stdlib.h>

typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK,
	STMT_EMPTY
} stmt_kind_t;

struct stmt {
	stmt_kind_t kind;
	struct decl *decl;		// declarations
	struct expr *init_expr;		// for
	struct expr *expr;		// for/if
	struct expr *next_expr;		// for
	struct stmt *body;		// if/if-else
	struct stmt *else_body;		// if-else
	struct stmt *next;		// stmt_list
};

struct stmt * stmt_create( stmt_kind_t kind, struct decl *d, struct expr *init_expr, struct expr *e, struct expr *next_expr, struct stmt *body, struct stmt *else_body );
void stmt_print( struct stmt *s, int indent );
void stmt_resolve( struct stmt *s );
void stmt_typecheck( struct stmt *s, struct decl * current_function );
void stmt_codegen(struct stmt *s, FILE * output);
int stmt_compare(struct stmt * a, struct stmt * b);
#endif
