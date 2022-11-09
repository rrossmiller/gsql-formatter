package com.optum.grnd.grommet.types;

public enum TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR, MODULO,
    PLUSEQUALS, MINUSEQUALS,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE, TYPE,

    CREATE, INTERPRET, REPLACE, DISTRIBUTED, QUERY,
    GRAPH, RETURNS, API, SYNTAX,
    // comments
    COMMENT, BLOCK_COMMENT,

    EOF
}