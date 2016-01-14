
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 49 "parser.y"

	struct decl* decl;
	struct stmt* stmt;
	struct expr* expr;
	struct param_list* param_list;
	struct type* type;
	char* ident;



/* Line 1676 of yacc.c  */
#line 112 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


