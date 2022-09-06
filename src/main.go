package main

import (
	"fmt"
	"gourmet/types"
	"gourmet/utils"

	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/repr"
)

func main() {
	parser, err := participle.Build[types.Property]()
	utils.Check(err)
	var fName string

	if true {
		fName = `
Users = SELECT s FROM Users:s
	`
	} else {
		// fName := `
		// Users =
		// `
	}

	ini, err := parser.ParseString("", fName)
	utils.Check(err)
	fmt.Println("\n\nrepr:")
	repr.Println(ini, repr.Indent("  "), repr.OmitEmpty(true))
}
