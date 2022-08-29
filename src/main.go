package main

import (
	"fmt"
	"gourmet/types"
	"gourmet/utils"

	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/repr"
)

func main() {
	parser, err := participle.Build[types.INI]()
	utils.Check(err)

	fName := `age = 21
	name = "Bob Smith"
	
	[address]
	city = "Beverly Hills"
	postal_code = 90210`
	ini, err := parser.ParseString("", fName)
	utils.Check(err)
	fmt.Println("\n\nrepr:")
	repr.Println(ini, repr.Indent("  "), repr.OmitEmpty(true))
}
