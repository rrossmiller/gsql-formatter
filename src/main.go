package main

import (
	"fmt"
	"gourmet/types"
	"gourmet/utils"

	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/repr"
)

func main() {

	fmt.Print("running\n\n")
	parser, err := participle.Build[types.Query]()
	utils.Check(err, "")
	stmts := [10]string{
		"Users = SELECT s FROM Src;",                              // select
		"Users = SELECT s FROM Src:s;",                            // select
		"Users = SELECT s FROM Src:s -(Etype:e)-VType;",           // select
		"Users = SELECT s FROM Src:s -(DirEdge:e)-> VType:v;",     // select
		"Users = SELECT s FROM Src:s -(DirEdge>:e)- VType:alias;", // select v2
		"Users = SELECT s FROM Src:s -(<DirEdge:e)- VType:alias;", // select v2
		// "i := 0;",           // Assignment
		// "i := \"here\";",    // Assignment
		// "i := @@global;",    // Assignment
		// "i := a.@lclaccum;", // Assignment
	}

	for _, v := range stmts {
		if v == "" {
			continue
		}
		fmt.Println("***")
		gsql, err := parser.ParseString("", v)
		fmt.Printf("%v\n", v)
		utils.Check(err, v)
		fmt.Println("\n\nrepr:")
		repr.Println(gsql, repr.Indent("  "), repr.OmitEmpty(true))
	}
}
