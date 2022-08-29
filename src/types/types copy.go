package types

import "github.com/alecthomas/participle/v2/lexer"

// root structure
type Query struct {
	// createQuery string `"CREATE" [OR REPLACE] [DISTRIBUTED] QUERY queryName`
	// interpretQuery
	// parameterValueList
	// parameterValue
}

type INI struct {
	Properties []*Property `@@*`
	Sections   []*Section  `@@*`
}
type Property struct {
	Key   string `@Ident "="`
	Value *Value `@@`
}
type Value struct {
	Pos    lexer.Position
	Str    *string  ` @String`
	Number *float64 ` | @Float | @Int`
}
type Section struct {
	Identifier string      `"[" @Ident "]"`
	Properties []*Property `@@*`
}
