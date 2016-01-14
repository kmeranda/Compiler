
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


/* Line 189 of yacc.c  */
#line 73 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NOT_TOKEN = 258,
     TOKEN_ARRAY = 259,
     TOKEN_BOOL = 260,
     TOKEN_CHAR = 261,
     TOKEN_CHAR_LITERAL = 262,
     TOKEN_ELSE = 263,
     TOKEN_FALSE = 264,
     TOKEN_FOR = 265,
     TOKEN_FUNCT = 266,
     TOKEN_IF = 267,
     TOKEN_IDENT = 268,
     TOKEN_INT = 269,
     TOKEN_INT_LITERAL = 270,
     TOKEN_PRINT = 271,
     TOKEN_RETURN = 272,
     TOKEN_STRING = 273,
     TOKEN_STRING_LITERAL = 274,
     TOKEN_TRUE = 275,
     TOKEN_VOID = 276,
     TOKEN_WHILE = 277,
     TOKEN_PAREN_OPEN = 278,
     TOKEN_PAREN_CLOSE = 279,
     TOKEN_BRACKET_OPEN = 280,
     TOKEN_BRACKET_CLOSE = 281,
     TOKEN_BRACE_OPEN = 282,
     TOKEN_BRACE_CLOSE = 283,
     TOKEN_COMMA = 284,
     TOKEN_SEMICOLON = 285,
     TOKEN_COLON = 286,
     TOKEN_INCREMENT = 287,
     TOKEN_DECREMENT = 288,
     TOKEN_NEGATION = 289,
     TOKEN_EXP = 290,
     TOKEN_MULT = 291,
     TOKEN_DIVIDE = 292,
     TOKEN_MOD = 293,
     TOKEN_ADD = 294,
     TOKEN_SUBTRACT = 295,
     TOKEN_LT = 296,
     TOKEN_LE = 297,
     TOKEN_GT = 298,
     TOKEN_GE = 299,
     TOKEN_EQUAL = 300,
     TOKEN_NE = 301,
     TOKEN_L_AND = 302,
     TOKEN_L_OR = 303,
     TOKEN_ASSIGN = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 49 "parser.y"

	struct decl* decl;
	struct stmt* stmt;
	struct expr* expr;
	struct param_list* param_list;
	struct type* type;
	char* ident;



/* Line 214 of yacc.c  */
#line 169 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 69 "parser.y"

#include "symbol.h"
#include "decl.h"
#include "expr.h"
#include "stmt.h"
#include "type.h"
#include "param_list.h"
#include "token.h"
#include "hash_table.h"	
#include <stdio.h>
#include <string.h>

/*
YYSTYPE is the lexical value returned by each rule in a bison grammar.
By default, it is an integer. In this example, we are returning a pointer to an expression.
*/
/*struct stype {
	struct decl* decl;
	struct stmt* stmt;
	struct expr* expr;
	struct param_list* param_list;
	struct type* type;
	char* ident;
} stype;
*/
//#define YYSTYPE stype		// ??????

/*
Clunky: Manually declare the interface to the scanner generated by flex. 
*/

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

struct decl * program = 0;
/*
Clunky: Keep the final result of the parse in a global variable,
so that it can be retrieved by main().
*/

//struct expr * parser_result = 0;
// c preamble


/* Line 264 of yacc.c  */
#line 227 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    16,    21,    29,    38,
      40,    42,    44,    46,    48,    54,    60,    61,    63,    65,
      69,    73,    75,    77,    79,    83,    85,    88,    98,   100,
     104,   108,   116,   122,   130,   140,   143,   144,   148,   150,
     154,   156,   158,   162,   164,   165,   166,   168,   172,   174,
     178,   180,   184,   186,   190,   194,   198,   202,   206,   210,
     212,   216,   220,   222,   226,   230,   234,   236,   240,   242,
     245,   248,   250,   253,   256,   258,   262,   268,   273,   275,
     280,   281,   283,   285,   287,   289,   291
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    -1,    53,    52,    -1,    -1,    58,
      31,    54,    49,    69,    30,    -1,    58,    31,    54,    30,
      -1,    58,    31,    54,    49,    27,    63,    28,    -1,    58,
      31,    54,    49,    27,    65,    28,    30,    -1,    18,    -1,
      14,    -1,     6,    -1,     5,    -1,    21,    -1,     4,    25,
      68,    26,    54,    -1,    11,    54,    23,    55,    24,    -1,
      -1,    56,    -1,    57,    -1,    57,    29,    56,    -1,    58,
      31,    54,    -1,    13,    -1,    61,    -1,    62,    -1,    27,
      63,    28,    -1,    53,    -1,    69,    30,    -1,    10,    23,
      68,    30,    68,    30,    68,    24,    61,    -1,    60,    -1,
      17,    68,    30,    -1,    16,    67,    30,    -1,    12,    23,
      69,    24,    61,     8,    61,    -1,    12,    23,    69,    24,
      59,    -1,    12,    23,    69,    24,    61,     8,    62,    -1,
      10,    23,    68,    30,    68,    30,    68,    24,    62,    -1,
      59,    63,    -1,    -1,    69,    29,    64,    -1,    69,    -1,
      66,    29,    65,    -1,    66,    -1,    64,    -1,    27,    65,
      28,    -1,    64,    -1,    -1,    -1,    69,    -1,    70,    49,
      69,    -1,    70,    -1,    70,    48,    71,    -1,    71,    -1,
      71,    47,    72,    -1,    72,    -1,    72,    43,    73,    -1,
      72,    44,    73,    -1,    72,    41,    73,    -1,    72,    42,
      73,    -1,    72,    45,    73,    -1,    72,    46,    73,    -1,
      73,    -1,    73,    39,    74,    -1,    73,    40,    74,    -1,
      74,    -1,    74,    36,    75,    -1,    74,    37,    75,    -1,
      74,    38,    75,    -1,    75,    -1,    75,    35,    76,    -1,
      76,    -1,    40,    76,    -1,    34,    76,    -1,    77,    -1,
      78,    32,    -1,    78,    33,    -1,    78,    -1,    23,    69,
      24,    -1,    58,    25,    69,    26,    79,    -1,    58,    23,
      67,    24,    -1,    80,    -1,    25,    69,    26,    79,    -1,
      -1,    58,    -1,    15,    -1,    19,    -1,     7,    -1,    20,
      -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   118,   121,   124,   126,   128,   130,   134,
     136,   138,   140,   142,   144,   146,   150,   151,   154,   156,
     160,   164,   168,   170,   174,   178,   180,   182,   184,   186,
     188,   190,   194,   196,   198,   201,   204,   206,   208,   211,
     213,   215,   218,   221,   224,   227,   228,   231,   233,   237,
     239,   243,   245,   249,   251,   253,   255,   257,   259,   261,
     265,   267,   269,   273,   275,   277,   279,   283,   285,   289,
     291,   293,   297,   299,   301,   305,   307,   309,   311,   314,
     317,   320,   322,   324,   326,   328,   330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NOT_TOKEN", "TOKEN_ARRAY", "TOKEN_BOOL",
  "TOKEN_CHAR", "TOKEN_CHAR_LITERAL", "TOKEN_ELSE", "TOKEN_FALSE",
  "TOKEN_FOR", "TOKEN_FUNCT", "TOKEN_IF", "TOKEN_IDENT", "TOKEN_INT",
  "TOKEN_INT_LITERAL", "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_STRING",
  "TOKEN_STRING_LITERAL", "TOKEN_TRUE", "TOKEN_VOID", "TOKEN_WHILE",
  "TOKEN_PAREN_OPEN", "TOKEN_PAREN_CLOSE", "TOKEN_BRACKET_OPEN",
  "TOKEN_BRACKET_CLOSE", "TOKEN_BRACE_OPEN", "TOKEN_BRACE_CLOSE",
  "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_COLON", "TOKEN_INCREMENT",
  "TOKEN_DECREMENT", "TOKEN_NEGATION", "TOKEN_EXP", "TOKEN_MULT",
  "TOKEN_DIVIDE", "TOKEN_MOD", "TOKEN_ADD", "TOKEN_SUBTRACT", "TOKEN_LT",
  "TOKEN_LE", "TOKEN_GT", "TOKEN_GE", "TOKEN_EQUAL", "TOKEN_NE",
  "TOKEN_L_AND", "TOKEN_L_OR", "TOKEN_ASSIGN", "$accept", "program",
  "decl_list", "decl", "type", "param_list", "not_empty_param_list",
  "param", "ident", "stmt", "stmt_block", "stmt_matched", "stmt_unmatched",
  "stmt_list", "not_empty_expr_list", "not_empty_expr_list_block",
  "expr_block", "expr_list", "expr_opt", "expr", "expr_or", "expr_and",
  "expr_cmp", "expr_add", "expr_mult", "expr_exp", "expr_unary",
  "expr_incr", "expr_group", "expr_array_list", "expr_primary", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    58,    59,    59,    60,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     4,     7,     8,     1,
       1,     1,     1,     1,     5,     5,     0,     1,     1,     3,
       3,     1,     1,     1,     3,     1,     2,     9,     1,     3,
       3,     7,     5,     7,     9,     2,     0,     3,     1,     3,
       1,     1,     3,     1,     0,     0,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     2,
       2,     1,     2,     2,     1,     3,     5,     4,     1,     4,
       0,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    21,     0,     2,     4,     0,     1,     3,     0,     0,
      12,    11,     0,    10,     9,    13,     0,    45,     0,     6,
       0,    84,    86,    82,    83,    85,     0,     0,     0,    81,
       0,    46,    48,    50,    52,    59,    62,    66,    68,    71,
      74,    78,    16,    36,     0,     0,    70,    69,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,    17,
      18,     0,     0,     0,    44,    45,    36,    25,    81,    36,
      28,    22,    23,     0,    41,     0,    40,    38,     5,    75,
      43,     0,    38,     0,    14,    49,    47,    51,    55,    56,
      53,    54,    57,    58,    60,    61,    63,    64,    65,    67,
      15,     0,     0,    45,     0,     0,     0,     0,     0,    36,
      35,     0,     7,     0,     0,     0,    26,    77,    80,    19,
      20,     0,     0,    30,    29,    24,    42,     8,     0,    39,
      37,     0,    76,    45,     0,     0,     0,    32,    22,    80,
      45,     0,    79,     0,    31,    33,     0,    27,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    77,    16,    68,    69,    70,    29,    79,
      80,    81,    82,   117,    84,   118,    86,    91,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   142,
      41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -137
static const yytype_int16 yypact[] =
{
       5,  -137,    27,  -137,     5,     1,  -137,  -137,     8,    14,
    -137,  -137,     8,  -137,  -137,  -137,   -25,   200,    34,  -137,
      95,  -137,  -137,  -137,  -137,  -137,   200,   200,   200,    24,
      49,  -137,    11,    33,     9,    31,    -1,    42,  -137,  -137,
      30,  -137,     5,   130,    48,    59,  -137,  -137,   200,   200,
       8,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,  -137,  -137,    66,  -137,
      62,    61,    70,    71,   200,   200,   130,  -137,    15,   156,
    -137,  -137,  -137,    67,  -137,    69,    76,    43,  -137,  -137,
    -137,    74,    80,    73,  -137,    33,  -137,     9,    31,    31,
      31,    31,    31,    31,    -1,    -1,    42,    42,    42,  -137,
    -137,     5,     8,   200,   200,    82,    83,    72,    88,   156,
    -137,    87,  -137,    91,   178,   200,  -137,  -137,    99,  -137,
    -137,    97,   101,  -137,  -137,  -137,  -137,  -137,   178,  -137,
    -137,   200,  -137,   200,   156,   102,   100,  -137,   123,    99,
     200,   156,  -137,   108,  -137,  -137,   156,  -137,  -137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   132,    17,    -9,  -137,    37,  -137,     0,   -10,
    -137,  -128,  -136,   -34,   -41,   -42,  -137,    78,   -69,   -18,
    -137,    90,   105,    10,    28,    23,   -17,  -137,  -137,     6,
    -137
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       5,    85,    44,    18,     5,    19,   116,    90,    45,    83,
      46,    47,     9,    10,    11,   155,   148,     4,     1,    12,
     158,     4,    13,   154,    20,    87,    14,     6,   157,    15,
      92,    93,     8,    90,    96,    62,    63,    64,    48,    17,
      49,    94,    71,    78,   131,   120,     8,    48,   109,    49,
      54,    55,    56,    57,    58,    59,    92,    42,    87,    51,
      52,   121,    66,    67,    98,    99,   100,   101,   102,   103,
      60,    61,   125,   126,   146,    50,    78,    65,    88,    78,
      53,   153,   139,    89,   140,   106,   107,   108,   104,   105,
     110,   111,   112,   113,   114,   122,   132,   123,   127,   128,
     135,   121,    21,   130,    22,   124,    92,    92,     1,   125,
      23,    71,   133,   134,    24,    25,   136,   126,    26,    78,
      92,   137,    43,   145,   141,   144,   121,   143,   149,    27,
     150,   151,   156,   121,   147,    28,     7,    21,   121,    22,
      72,    95,    73,     1,    78,    23,    74,    75,   129,    24,
      25,    78,   115,    26,     0,   152,    78,    76,    97,     0,
       0,     0,     0,    21,    27,    22,    72,     0,    73,     1,
      28,    23,    74,    75,     0,    24,    25,     0,     0,    26,
       0,     0,     0,   119,     0,    21,     0,    22,     0,     0,
      27,     1,     0,    23,     0,     0,    28,    24,    25,     0,
       0,    26,     0,     0,     0,   138,     0,    21,     0,    22,
       0,     0,    27,     1,     0,    23,     0,     0,    28,    24,
      25,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      28
};

static const yytype_int16 yycheck[] =
{
       0,    43,    20,    12,     4,    30,    75,    48,    26,    43,
      27,    28,     4,     5,     6,   151,   144,     0,    13,    11,
     156,     4,    14,   151,    49,    43,    18,     0,   156,    21,
      48,    49,    31,    74,    52,    36,    37,    38,    23,    25,
      25,    50,    42,    43,   113,    79,    31,    23,    65,    25,
      41,    42,    43,    44,    45,    46,    74,    23,    76,    48,
      49,    79,    32,    33,    54,    55,    56,    57,    58,    59,
      39,    40,    29,    30,   143,    26,    76,    35,    30,    79,
      47,   150,   124,    24,   125,    62,    63,    64,    60,    61,
      24,    29,    31,    23,    23,    28,   114,    28,    24,    26,
      28,   119,     7,   112,     9,    29,   124,   125,    13,    29,
      15,   111,    30,    30,    19,    20,    28,    30,    23,   119,
     138,    30,    27,   141,    25,    24,   144,    30,    26,    34,
      30,     8,    24,   151,   144,    40,     4,     7,   156,     9,
      10,    51,    12,    13,   144,    15,    16,    17,   111,    19,
      20,   151,    74,    23,    -1,   149,   156,    27,    53,    -1,
      -1,    -1,    -1,     7,    34,     9,    10,    -1,    12,    13,
      40,    15,    16,    17,    -1,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,    27,    -1,     7,    -1,     9,    -1,    -1,
      34,    13,    -1,    15,    -1,    -1,    40,    19,    20,    -1,
      -1,    23,    -1,    -1,    -1,    27,    -1,     7,    -1,     9,
      -1,    -1,    34,    13,    -1,    15,    -1,    -1,    40,    19,
      20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    51,    52,    53,    58,     0,    52,    31,     4,
       5,     6,    11,    14,    18,    21,    54,    25,    54,    30,
      49,     7,     9,    15,    19,    20,    23,    34,    40,    58,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    80,    23,    27,    69,    69,    76,    76,    23,    25,
      26,    48,    49,    47,    41,    42,    43,    44,    45,    46,
      39,    40,    36,    37,    38,    35,    32,    33,    55,    56,
      57,    58,    10,    12,    16,    17,    27,    53,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    69,    30,    24,
      64,    67,    69,    69,    54,    71,    69,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    76,
      24,    29,    31,    23,    23,    67,    68,    63,    65,    27,
      63,    69,    28,    28,    29,    29,    30,    24,    26,    56,
      54,    68,    69,    30,    30,    28,    28,    30,    27,    65,
      64,    25,    79,    30,    24,    69,    68,    59,    61,    26,
      30,     8,    79,    68,    61,    62,    24,    61,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { program = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (2)].decl); (yyvsp[(1) - (2)].decl) -> next = (yyvsp[(2) - (2)].decl); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { (yyval.decl) = 0; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { (yyval.decl) = decl_create((yyvsp[(1) - (6)].ident), (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].expr), NULL, NULL ); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { (yyval.decl) = decl_create((yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].type), NULL, NULL, NULL ); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { (yyval.decl) = decl_create((yyvsp[(1) - (7)].ident), (yyvsp[(3) - (7)].type), NULL, (yyvsp[(6) - (7)].stmt), NULL ); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { (yyval.decl) = decl_create((yyvsp[(1) - (8)].ident), (yyvsp[(3) - (8)].type), (yyvsp[(6) - (8)].expr), NULL, NULL ); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { (yyval.type) = type_create(TYPE_CHARACTER, NULL, NULL); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval.type) = type_create(TYPE_VOID, NULL, NULL); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { (yyval.type) = type_create_array(TYPE_ARRAY, NULL, (yyvsp[(5) - (5)].type), (yyvsp[(3) - (5)].expr)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { (yyval.type) = type_create_array(TYPE_FUNCTION, (yyvsp[(4) - (5)].param_list), (yyvsp[(2) - (5)].type), NULL); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { (yyval.param_list) = 0; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.param_list) = (yyvsp[(1) - (1)].param_list); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval.param_list) = (yyvsp[(1) - (1)].param_list); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { (yyval.param_list) = (yyvsp[(1) - (3)].param_list); (yyvsp[(1) - (3)].param_list)->next  = (yyvsp[(3) - (3)].param_list); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval.param_list) = param_list_create((yyvsp[(1) - (3)].ident), (yyvsp[(3) - (3)].type), NULL); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { char * temp; temp = strdup(yytext); (yyval.ident) = temp; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, (yyvsp[(2) - (3)].stmt), NULL); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[(1) - (1)].decl), NULL, NULL, NULL, NULL, NULL); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[(1) - (2)].expr), NULL, NULL, NULL ); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_FOR, NULL, (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt), NULL); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[(2) - (3)].expr), NULL, NULL, NULL); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_PRINT, NULL, NULL, (yyvsp[(2) - (3)].expr), NULL, NULL, NULL); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    { (yyval.stmt) = stmt_create( STMT_IF_ELSE, NULL, NULL, (yyvsp[(3) - (7)].expr), NULL, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt) ); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[(3) - (5)].expr), NULL, (yyvsp[(5) - (5)].stmt), NULL);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[(3) - (7)].expr), NULL, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_FOR, NULL, (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt), NULL); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (2)].stmt); (yyvsp[(1) - (2)].stmt) -> next = (yyvsp[(2) - (2)].stmt); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval.stmt) = stmt_create(STMT_EMPTY, NULL, NULL, NULL, NULL, NULL, NULL); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    { (yyval.expr) = expr_create(EXPR_LIST, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    { (yyval.expr) = expr_create(EXPR_LIST, (yyvsp[(1) - (1)].expr), NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    { (yyval.expr) = expr_create(EXPR_LIST, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval.expr) = expr_create(EXPR_LIST, (yyvsp[(1) - (1)].expr), NULL); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval.expr) = expr_create(EXPR_BLOCK, NULL, (yyvsp[(2) - (3)].expr)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { (yyval.expr) = 0; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    { (yyval.expr) = 0; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    { (yyval.expr) = expr_create( EXPR_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval.expr) = expr_create( EXPR_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { (yyval.expr) = expr_create( EXPR_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    { (yyval.expr) = expr_create( EXPR_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    { (yyval.expr) = expr_create( EXPR_GE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    { (yyval.expr) = expr_create( EXPR_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    { (yyval.expr) = expr_create( EXPR_LE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    { (yyval.expr) = expr_create( EXPR_EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    { (yyval.expr) = expr_create( EXPR_NE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    { (yyval.expr) = expr_create( EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    { (yyval.expr) = expr_create( EXPR_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    { (yyval.expr) = expr_create( EXPR_MUL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    { (yyval.expr) = expr_create( EXPR_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    { (yyval.expr) = expr_create( EXPR_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { (yyval.expr) = expr_create( EXPR_EXP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 290 "parser.y"
    { (yyval.expr) = expr_create( EXPR_NEG, NULL, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    { (yyval.expr) = expr_create( EXPR_NOT, NULL, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    { (yyval.expr) = expr_create( EXPR_INCR, (yyvsp[(1) - (2)].expr), NULL); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    { (yyval.expr) = expr_create( EXPR_DECR, (yyvsp[(1) - (2)].expr), NULL); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    { (yyval.expr) = expr_create( EXPR_GROUP, (yyvsp[(2) - (3)].expr), NULL); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 308 "parser.y"
    { (yyval.expr) = expr_create( EXPR_ARR, expr_create_name((yyvsp[(1) - (5)].ident)), expr_create(EXPR_ARR_LIST, (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr))); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 310 "parser.y"
    { (yyval.expr) = expr_create( EXPR_FUNCT, expr_create_name((yyvsp[(1) - (4)].ident)), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    { (yyval.expr) = expr_create( EXPR_ARR_LIST, (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
    { (yyval.expr) = 0; ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { (yyval.expr) = expr_create_name((yyvsp[(1) - (1)].ident)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { char * temp; temp = strdup(yytext); (yyval.expr) = expr_create_string_literal(temp); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 327 "parser.y"
    { (yyval.expr) = expr_create_character_literal(*yytext); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { (yyval.expr) = expr_create_boolean_literal(1); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 331 "parser.y"
    { (yyval.expr) = expr_create_boolean_literal(0); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2184 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 333 "parser.y"

// c postamble
/*
This function will be called by bison if the parse should
encounter an error.  In principle, "str" will contain something
useful.  In practice, it often does not.
*/
int yyerror( char *str )
{
	printf("parse error: %s\n",str);
}

