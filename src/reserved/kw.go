package reserved

import "gourmet/tokens"

// todo populate
var (
	Keywords = make(map[string]tokens.TokenType)
	Types    = make(map[string]tokens.TokenType)
)

func init() {
	Keywords["and"] = tokens.AND
	Keywords["else"] = tokens.ELSE
	Keywords["false"] = tokens.FALSE
	Keywords["for"] = tokens.FOR
	Keywords["fun"] = tokens.FUN
	Keywords["if"] = tokens.IF
	Keywords["null"] = tokens.NULL
	Keywords["or"] = tokens.OR
	Keywords["print"] = tokens.PRINT
	Keywords["true"] = tokens.TRUE
	Keywords["while"] = tokens.WHILE

	// graphy
	Keywords["create"] = tokens.CREATE
	Keywords["interpret"] = tokens.INTERPRET
	Keywords["replace"] = tokens.REPLACE
	Keywords["distributed"] = tokens.DISTRIBUTED
	Keywords["query"] = tokens.QUERY
	Keywords["graph"] = tokens.GRAPH
	Keywords["select"] = tokens.SELECT
	Keywords["from"] = tokens.FROM
	Keywords["where"] = tokens.WHERE
	Keywords["returns"] = tokens.RETURNS
	// Keywords["api"]= tokens.API
	Keywords["syntax"] = tokens.SYNTAX

	Types["int"] = tokens.TYPE
	Types["uint"] = tokens.TYPE
	Types["float"] = tokens.TYPE
	Types["double"] = tokens.TYPE
	Types["string"] = tokens.TYPE
	Types["bool"] = tokens.TYPE
	Types["vertex"] = tokens.TYPE
	Types["edge"] = tokens.TYPE
	Types["jsonobject"] = tokens.TYPE
	Types["jsonarray"] = tokens.TYPE
	Types["datetime"] = tokens.TYPE
	Types["typedef tuple"] = tokens.TYPEDEF
}
