#ifndef EXPR_H
#define EXPR_H

#include <stdio.h>
#include <stdlib.h>
//#include "register.h"

typedef enum {
	EXPR_ADD,	// +
	EXPR_SUB,	// -
	EXPR_MUL,	// *
	EXPR_DIV,	// /
	EXPR_EXP,	// ^
	EXPR_MOD,	// %
	EXPR_GT,	// >
	EXPR_GE,	// >=
	EXPR_LT,	// >
	EXPR_LE,	// >=
	EXPR_NE,	// !=
	EXPR_EQ,	// ==
	EXPR_AND,	// &&
	EXPR_OR,	// ||
	EXPR_NOT,	// !
	EXPR_INCR,	// ++
	EXPR_DECR,	// --
	EXPR_NEG,	// -c
	EXPR_ASSIGN,	// = 
	EXPR_ARR,	// array subscript
	EXPR_ARR_LIST,	// multi dimensional array subscript
	EXPR_FUNCT,	// function call
	EXPR_GROUP,
	EXPR_BLOCK,	// for expr lists of expr lists (for arrays of arrays)
	EXPR_BOOL,	// true/false
	EXPR_NAME,	// ident
	EXPR_INT,	// #'s
	EXPR_CHAR,
	EXPR_STR,
	EXPR_LIST
	/* many more types to add here */
} expr_t;

struct expr {
	/* used by all expr types */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by leaf expr types */
	const char *name;
	struct symbol *symbol;
	int literal_value;
	const char * string_literal;
	int reg;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );
struct expr * expr_create_name( const char *n );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_character_literal( int c );
struct expr * expr_create_string_literal( const char *str );
void expr_print( struct expr *e );
void expr_resolve(struct expr *e);
struct type * expr_typecheck(struct expr * e);
void expr_codegen(struct expr *e, FILE * output);
void expr_print_codegen(struct expr *e, FILE * output);
void expr_get_string(struct expr *e, FILE * output);
int expr_compare(struct expr * a, struct expr * b);
int is_constant(struct expr * e);

#endif
