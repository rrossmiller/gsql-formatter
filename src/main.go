package main

import (
	"fmt"
	"gourmet/types"
	"gourmet/utils"

	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/repr"
)

func main() {
	parser, err := participle.Build[types.SelectStmt]()
	utils.Check(err)
	stmts := [10]string{
		`Users = SELECT s FROM asdf`,
		"Users = SELECT s FROM Src:s",
		"Users = SELECT s FROM Src:s -()-> VType",
	}

	for _, v := range stmts {
		fmt.Println("***")
		ini, err := parser.ParseString("", v)
		fmt.Printf("%v\n", v)
		utils.Check(err)
		fmt.Println("\n\nrepr:")
		repr.Println(ini, repr.Indent("  "), repr.OmitEmpty(true))
	}
}
