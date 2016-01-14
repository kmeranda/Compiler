%{
#include "token.h"
%}
NUMBER [0-9]
LETTER [a-zA-Z]
WHITESPACE [ \n\t]+
ID ({LETTER}|_)({LETTER}|_|{NUMBER})*
COMMENT1 \/\*([^*]|[\r\n]|(\*+([^*\/]|[\r\n])))*\*+\/
COMMENT2 (\/\/.*)
%%
{WHITESPACE}
({COMMENT1}|{COMMENT2})
while { return TOKEN_WHILE; }
array { return TOKEN_ARRAY; }
boolean {return TOKEN_BOOL; }
char { return TOKEN_CHAR; }

\'(((\\)?[^\\])|(\\\\))\' { edit_string(yytext); return TOKEN_CHAR_LITERAL; }

else { return TOKEN_ELSE; }
false { return TOKEN_FALSE; }
for { return TOKEN_FOR; }
function { return TOKEN_FUNCT; }
if { return TOKEN_IF; }
integer {return TOKEN_INT; }
{NUMBER}+ {return TOKEN_INT_LITERAL; }
print { return TOKEN_PRINT; }
return { return TOKEN_RETURN; }
string { return TOKEN_STRING; }

\"([^\"\n]|\\\")*\" { edit_string(yytext); return TOKEN_STRING_LITERAL; }

true { return TOKEN_TRUE; }
void { return TOKEN_VOID; }
{ID} { return TOKEN_IDENT; }
"(" { return TOKEN_PAREN_OPEN; }
")" { return TOKEN_PAREN_CLOSE; }
"[" { return TOKEN_BRACKET_OPEN; }
"]" { return TOKEN_BRACKET_CLOSE; }
"{" { return TOKEN_BRACE_OPEN; }
"}" { return TOKEN_BRACE_CLOSE; }
"," { return TOKEN_COMMA; }
";" { return TOKEN_SEMICOLON; }
":" { return TOKEN_COLON; }
"++" { return TOKEN_INCREMENT; }
"--" { return TOKEN_DECREMENT; }
"^" { return TOKEN_EXP; }
"*" { return TOKEN_MULT; }
"/" { return TOKEN_DIVIDE; }
"%" { return TOKEN_MOD; }
"+" { return TOKEN_ADD; }
"-" { return TOKEN_SUBTRACT; }
"<" { return TOKEN_LT; }
"<=" { return TOKEN_LE; }
">" { return TOKEN_GT; }
">=" { return TOKEN_GE; }
"==" { return TOKEN_EQUAL; }
"!=" { return TOKEN_NE; }
"&&" { return TOKEN_L_AND; }
"||" { return TOKEN_L_OR; }
"!" { return TOKEN_NEGATION; }
"=" { return TOKEN_ASSIGN; }
. {	fprintf(stderr, "scan error: %s is not a valid character\n", yytext);
	exit(1);
	break;
	 /*return NOT_TOKEN;*/ 
}
%%
