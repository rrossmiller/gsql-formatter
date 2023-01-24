package main

import (
	"fmt"
	"gourmet/reserved"
	"gourmet/tokens"
	"gourmet/util"
	"strconv"
	"strings"
	"unicode"
	"unicode/utf8"
)

var (
	src     string
	srcLen  int
	tkns    = []tokens.Token{}
	start   int
	current int = 0
	line    int = 1
)

func ScanTokens(input string) {
	src = input
	srcLen = utf8.RuneCountInString(src)
	for !isAtEnd() {
		// start at the beginning of the next lexeme
		start = current
		scanToken()
	}
	for _, v := range tkns {
		fmt.Println(v)
	}
}

func scanToken() {
	r := advance()
	switch r {
	case '(':
		addToken(tokens.LEFT_PAREN)
	case ')':
		addToken(tokens.RIGHT_PAREN)
	case '{':
		addToken(tokens.LEFT_BRACE)
	case '}':
		addToken(tokens.RIGHT_BRACE)
	case ',':
		addToken(tokens.COMMA)
	case '.':
		addToken(tokens.DOT)
	case '-':
		if match('=') {
			addToken(tokens.MINUSEQUALS)
		} else {
			addToken(tokens.MINUS)
		}
	case '+':
		if match('=') {
			addToken(tokens.PLUSEQUALS)
		} else {
			addToken(tokens.PLUS)
		}
	case ';':
		addToken(tokens.SEMICOLON)
	case '*':
		addToken(tokens.STAR)
	case '%':
		addToken(tokens.MODULO)
	case '!':
		if match('=') {
			addToken(tokens.BANG_EQUAL)
		} else {
			addToken(tokens.BANG)
		}
	case ':':
		addToken(tokens.COLON)
	case '=':
		if match('=') {
			addToken(tokens.EQUAL_EQUAL)
		} else {
			addToken(tokens.EQUAL)
		}
	case '<':
		if match('=') {
			addToken(tokens.LESS_EQUAL)
		} else {
			addToken(tokens.LESS)
		}
	case '>':
		if match('=') {
			addToken(tokens.GREATER_EQUAL)
		} else {
			addToken(tokens.GREATER)
		}
	case '/':
		comment()
	// whitespace
	case ' ', '\r', '\t': // do nothing
	case '\n':
		line++
	// string literals
	case '"':
		str()
	default:
		if isDigit(r) {
			number()
		} else if isAlpha(r) || r == '@' {
			identifier()
		} else {
			fmt.Println("--->", string(r))
			fmt.Println(line)
			panic("Unexpected character.")
			// Grommet.error(line, "Unexpected character.")
		}

	}
}

// Check if the current rune equal to expected
func match(expected rune) bool {
	if isAtEnd() {
		return false
	}
	r, _ := utf8.DecodeRuneInString(src[current:])

	if r != expected {
		return false
	}

	current++
	return true
}

// peek the current rune without consuming
func peek() rune {
	if isAtEnd() {
		return '•' // this means eof
	}
	r, _ := utf8.DecodeRuneInString(src[current:])

	return r
}

// peek the next rune without consuming
func peekNext() rune {
	if current+1 >= srcLen {
		return '•'
	}
	r, _ := utf8.DecodeRuneInString(src[current+1:])
	return r
}

// handle comments
func comment() {
	if match('/') {
		// A comment goes until the end of the line.
		for peek() != '\n' && !isAtEnd() {
			advance()
		}
		addToken(tokens.COMMENT)
	} else if match('*') {
		// A block comment goes until '*/' termination
		for !isAtEnd() && (peek() != '*' && peekNext() != '/') {
			if peek() == '\n' { // supports multi-line comments
				line++
			}
			advance()
		}
		// consume */
		advanceN(2)
		addToken(tokens.BLOCK_COMMENT)

	} else {
		addToken(tokens.SLASH)
	}
}

// handle strings
func str() {
	for peek() != '"' && !isAtEnd() {
		if peek() == '\n' { // supports multi-line strings
			line++
		}

		advance()
	}

	if isAtEnd() {
		panic("Unterminiated string.")
		// Grommet.error(line, "Unterminiated string.")
		// return
	}
	// the closing "
	advance()

	// Trim the surrounding quotes
	value := src[start+1 : current-1]
	addTokenLit(tokens.STRING, value)
}

// check if the rune is a digit
func isDigit(r rune) bool {
	return r >= '0' && r <= '9'
}

// handle numbers
func number() {
	for isDigit(peek()) {
		advance()
	}

	// look for a fractional part
	if peek() == '.' && isDigit(peekNext()) {
		advance()
	} // consume the .

	for isDigit(peek()) {
		advance()
	}

	value, err := strconv.ParseFloat(src[start:current], 32)
	util.Check(err)
	addTokenLit(tokens.NUMBER, value)
}

// check if the rune is an alpha char
func isAlpha(r rune) bool {
	return (r >= 'a' && r <= 'z') ||
		(r >= 'A' && r <= 'Z') || (r == '_')
}
func isAlphaNumeric(r rune) bool {
	return isAlpha(r) || isDigit(r)
}

// handle identifiers
func identifier() {
	for isAlphaNumeric(peek()) || peek() == '@' {
		advance()
	}

	text := strings.ToLower(src[start:current])
	ttype, exists := reserved.Keywords[text]
	if !exists {
		ttype, exists = reserved.Types[text]
	}
	if !exists {
		ttype = tokens.IDENTIFIER
	}

	// check for typdef tuple
	if text == "typedef" {
		advance()
		prev := current
		nextToken()
		w := strings.ToLower(src[prev:current])
		w = strings.ReplaceAll(w, " ", "")
		w = strings.ReplaceAll(w, "\t", "")
		if w == "tuple" {
			ttype = tokens.TYPEDEF
		}
	}
	addToken(ttype)
}

// get the next token (skipping whitespace)
func nextToken() {
	// find the next word
	for unicode.IsSpace(peek()) {
		advance()
	}
	// find the end of the word

	for !unicode.IsSpace(peek()) {
		advance()
	}
}

// creates a new token for the curernt lexeme
func addToken(ttype tokens.TokenType) {
	addTokenLit(ttype, nil)
}

func addTokenLit(ttype tokens.TokenType, literal any) {
	text := src[start:current]
	tkns = append(tkns, tokens.Token{TokenType: ttype, Lexeme: text, Literal: literal, Line: line})
}

// consumes th next char in the source
func advance() rune {
	r, w := utf8.DecodeRuneInString(src[current:])
	current += w
	return r

}
func advanceN(n int) {
	for i := 0; i < n; i++ {
		advance()
	}
}
func isAtEnd() bool {
	return current >= srcLen
}
