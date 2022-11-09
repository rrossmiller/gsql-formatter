package com.optum.grnd.grommet.types;

public class Token {
    public final TokenType type;
    public final String lexeme;
    public final Object literal;
    public final int line;
    // add col and length

    public Token(TokenType type, String lexeme, Object literal, int line) {
        this.type = type;
        this.lexeme = lexeme;
        this.literal = literal;
        this.line = line;
    }

    public String toString() {
        return type + " | " + lexeme + " | " + literal;
    }

    public static Token sum(Token... tokens) {
        TokenType type = tokens[0].type;
        StringBuilder lexeme = new StringBuilder();
        Object literal = null;
        int line = tokens[0].line;

        for (Token token : tokens) {
            lexeme.append(token.lexeme + " ");
        }
        return new Token(type, lexeme.toString(), literal, line);
    }
}