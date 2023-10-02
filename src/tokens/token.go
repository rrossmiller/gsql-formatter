package tokens

import (
	"fmt"
	"strings"
)

type Token struct {
	TokenType TokenType
	Lexeme    string
	Literal   any
	Line      int
	// add col and length

	//     public static Token sum(Token... tokens) {
	//         TokenType type = tokens[0].type;
	//         StringBuilder lexeme = new StringBuilder();
	//         Object literal = null;
	//         int line = tokens[0].line;

	//         for (Token token : tokens) {
	//             lexeme.append(token.lexeme + " ");
	//         }
	//         return new Token(type, lexeme.toString(), literal, line);
}

func (t Token) String() string {
	lex := t.Lexeme
	if t.TokenType == BLOCK_COMMENT {
		lex = strings.ReplaceAll(t.Lexeme, "\n", " ")
	}
	if t.TokenType < 10 {
		return fmt.Sprintf("%d  | %s | %v", t.TokenType, lex, t.Literal)
	}
	return fmt.Sprintf("%d | %s | %v", t.TokenType, lex, t.Literal)

}
