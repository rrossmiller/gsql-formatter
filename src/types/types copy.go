package types

import "github.com/alecthomas/participle/v2/lexer"

type INI struct {
	Properties []*aProperty `@@*`
	Sections   []*Section   `@@*`
}

type Section struct {
	Identifier string      `"[" @Ident "]"`
	Properties []*Property `@@*`
}

type aProperty struct {
	Key   string  `@Ident "="`
	Value *aValue `@@`
}
type aValue struct {
	Pos    lexer.Position
	Str    *string  ` @String`
	Number *float64 ` | @Float | @Int`
}
