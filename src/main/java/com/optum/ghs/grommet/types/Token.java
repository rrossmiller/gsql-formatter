package com.optum.ghs.grommet.types;

import lombok.Getter;

@Getter
public class Token {
    private final TokenType type;
    private final String lexeme;
    private final Object literal;
    private final int line;
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
}