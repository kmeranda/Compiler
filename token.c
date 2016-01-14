#include "token.h"

const char * token_string(token_t t) {
	switch(t) {
		case NOT_TOKEN:
			return "ERROR";
			break;
		case TOKEN_ARRAY:
			return "ARRAY";
			break;
		case TOKEN_BOOL:
			return "BOOLEAN";
			break;
		case TOKEN_CHAR:
			return "CHARACTER";
			break;
		case TOKEN_CHAR_LITERAL:
			return "CHARACTER_LITERAL";
			break;
		case TOKEN_ELSE:
			return "ELSE";
			break;
		case TOKEN_FALSE:
			return "FALSE";
			break;
		case TOKEN_FOR:
			return "FOR";
			break;
		case TOKEN_FUNCT:
			return "FUNCTION";
			break;
		case TOKEN_IF:
			return "IF";
			break;
		case TOKEN_IDENT:
			return "IDENTIFIER";
			break;
		case TOKEN_INT:
			return "INTEGER";
			break;
		case TOKEN_INT_LITERAL:
			return "INTEGER_LITERAL";
			break;
		case TOKEN_PRINT:
			return "PRINT";
			break;
		case TOKEN_RETURN:
			return "RETURN";
			break;
		case TOKEN_STRING:
			return "STRING";
			break;
		case TOKEN_STRING_LITERAL:
			return "STRING_LITERAL";
			break;
		case TOKEN_TRUE:
			return "TRUE";
			break;
		case TOKEN_VOID:
			return "VOID";
			break;
		case TOKEN_WHILE:
			return "WHILE";
			break;
		case TOKEN_PAREN_OPEN:
			return "OPEN_PARENTHESIS";
			break;
		case TOKEN_PAREN_CLOSE:
			return "CLOSE_PARENTHESIS";
			break;
		case TOKEN_BRACKET_OPEN:
			return "OPEN_BRACKET";
			break;
		case TOKEN_BRACKET_CLOSE:
			return "CLOSE_BRACKET";
			break;
		case TOKEN_BRACE_OPEN:
			return "OPEN_BRACE";
			break;
		case TOKEN_BRACE_CLOSE:
			return "CLOSE_BRACE";
			break;
		case TOKEN_COMMA:
			return "COMMA";
			break;
		case TOKEN_SEMICOLON:
			return "SEMICOLON";
			break;
		case TOKEN_COLON:
			return "COLON";
			break;
		case TOKEN_INCREMENT:
			return "INCREMENT";
			break;
		case TOKEN_DECREMENT:
			return "DECREMENT";
			break;
		case TOKEN_NEGATION:
			return "NEGATION";
			break;
		case TOKEN_EXP:
			return "EXPONENTIATION";
			break;
		case TOKEN_MULT:
			return "MULTIPLICATION";
			break;
		case TOKEN_DIVIDE:
			return "DIVIDE";
			break;
		case TOKEN_MOD:
			return "MODULUS";
			break;
		case TOKEN_ADD:
			return "ADDITION";
			break;
		case TOKEN_SUBTRACT:
			return "SUBTRACTION";
			break;
		case TOKEN_LT:
			return "LT";
			break;
		case TOKEN_LE:
			return "LE";
			break;
		case TOKEN_GT:
			return "GT";
			break;
		case TOKEN_GE:
			return "GE";
			break;
		case TOKEN_EQUAL:
			return "EQUALITY";
			break;
		case TOKEN_NE:
			return "NOT_EQUAL";
			break;
		case TOKEN_L_AND:
			return "LOGICAL_AND";
			break;
		case TOKEN_L_OR:
			return "LOGICAL_OR";
			break;
		case TOKEN_ASSIGN:
			return "ASSIGNMENT";
			break;
		default: return "other";
	}
}
