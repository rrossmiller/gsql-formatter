package com.optum.ghs.grommet;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.optum.ghs.grommet.types.Token;
import com.optum.ghs.grommet.types.TokenType;
import static com.optum.ghs.grommet.types.TokenType.*;

public class Scanner {
    private static final Map<String, TokenType> keywords;
    static {
        keywords = new HashMap<>();
        keywords.put("and", AND);
        keywords.put("class", CLASS);
        keywords.put("else", ELSE);
        keywords.put("false", FALSE);
        keywords.put("for", FOR);
        keywords.put("fun", FUN);
        keywords.put("if", IF);
        keywords.put("nil", NIL);
        keywords.put("or", OR);
        keywords.put("print", PRINT);
        keywords.put("return", RETURN);
        keywords.put("super", SUPER);
        keywords.put("this", THIS);
        keywords.put("true", TRUE);
        keywords.put("var", VAR);
        keywords.put("while", WHILE);
    }
    private final String source;
    private final List<Token> tokens = new ArrayList<>();
    private int start = 0;
    private int current = 0;
    private int line = 1;

    private char curchar;

    Scanner(String source) {
        this.source = source;
        curchar = source.charAt(current);
    }

    List<Token> scanTokens() {
        while (!isAtEnd()) {
            // start at the beginning of the next lexeme
            this.start = this.current;
            scanToken();
        }

        this.tokens.add(new Token(EOF, "", null, line)); // add eof at the end
        return this.tokens;
    }

    // scan a single token
    void scanToken() {
        char c = advance();
        switch (c) {
            case '(':
                addToken(LEFT_PAREN);
                break;
            case ')':
                addToken(RIGHT_PAREN);
                break;
            case '{':
                addToken(LEFT_BRACE);
                break;
            case '}':
                addToken(RIGHT_BRACE);
                break;
            case ',':
                addToken(COMMA);
                break;
            case '.':
                addToken(DOT);
                break;
            case '-':
                addToken(match('=') ? MINUSEQUALS : MINUS);
                break;
            case '+':
                addToken(match('=') ? PLUSEQUALS : PLUS);
                break;
            case ';':
                addToken(SEMICOLON);
                break;
            case '*':
                addToken(STAR);
                break;
            case '%':
                addToken(MODULO);
                break;
            case '!':
                addToken(match('=') ? BANG_EQUAL : BANG);
                break;
            case '=':
                addToken(match('=') ? EQUAL_EQUAL : EQUAL);
                break;
            case '<':
                addToken(match('=') ? LESS_EQUAL : LESS);
                break;
            case '>':
                addToken(match('=') ? GREATER_EQUAL : GREATER);
                break;
            case '/':
                if (match('/')) {
                    // A comment goes until the end of the line.
                    while (peek() != '\n' && !isAtEnd())
                        advance();
                    // addToken(COMMENT);
                }
                // else if (match('*')) {
                // // A block comment goes until '*/' termination
                // advanceComment();
                // addToken(COMMENT);}
                else {
                    addToken(SLASH);
                }
                break;
            // whitespace
            case ' ':
            case '\r':
            case '\t':
                break;
            case '\n':
                line++;
                break;
            // string literals
            case '"':
                string();
                break;
            default:
                if (isDigit(c)) {
                    number();
                } else if (isAlpha(c)) {
                    identifier();
                } else {
                    Grommet.error(line, "Unexpected character.");
                }
                break;
        }
    }

    private void identifier() {
        while (isAlphaNumeric(peek()))
            advance();

        String text = source.substring(start, current);
        TokenType type = keywords.get(text);
        if (type == null)
            type = IDENTIFIER;

        addToken(type);
    }

    private boolean isAlpha(char c) {
        return (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') || (c == '_');
    }

    private boolean isAlphaNumeric(char c) {
        return isAlpha(c) || isDigit(c);
    }

    private void number() {
        while (isDigit(peek()))
            advance();

        // look for a fractional part
        if (peek() == '.' && isDigit(peekNext()))
            advance(); // consume the .

        while (isDigit(peek()))
            advance();

        double value = Double.parseDouble(source.substring(start, current));
        addToken(NUMBER, value);
    }

    private void string() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') // lox supports multi-line strings
                line++;

            advance();
        }

        if (isAtEnd()) {
            Grommet.error(line, "Unterminiated string.");
            return;
        }
        // the closing "
        advance();

        // Trim the surrounding quotes
        String value = source.substring(start + 1, current - 1);
        addToken(STRING, value);
    }

    private boolean match(char expected) {
        if (isAtEnd())
            return false;
        if (this.source.charAt(current) != expected)
            return false;
        curchar = source.charAt(current);
        this.current++;
        return true;
    }

    private char peek() {
        if (isAtEnd())
            return '\0';
        return this.source.charAt(current);
    }

    private char peekNext() {
        if (current + 1 >= source.length())
            return '\0';
        return source.charAt(current + 1);
    }

    private boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int i = 0;

    private boolean isAtEnd() {
        return current >= source.length();
    }

    // consumes th next char in the source
    private char advance() {

        curchar = source.charAt(current);
        return source.charAt(current++);
    }

    // private char advanceComment() {
    // while (!isAtEnd() || (peek() != '*' && peekNext() != '/')) {
    // if (peek() == '\n')
    // line++;
    // advance();
    // }
    // // consume */
    // advance(2);
    // return source.charAt(current++);
    // }

    private void advance(int n) {
        for (int i = 0; i < n; i++) {
            advance();
        }
    }

    // creates a new token for the curernt lexeme
    private void addToken(TokenType type) {
        addToken(type, null);
    }

    private void addToken(TokenType type, Object literal) {
        String text = source.substring(start, current);
        tokens.add(new Token(type, text, literal, line));
    }
}
