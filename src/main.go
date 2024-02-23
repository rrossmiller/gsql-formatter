package main

import (
	// "context"
	"fmt"
	"grommet/gfmt"
	"grommet/preprocess"
	gsql "grommet/sitterLang"
	"os"

	sitter "github.com/smacker/go-tree-sitter"
)

func main() {
	sourceCode := readFile()
	src, err := preprocess.Preprocess(sourceCode)
	if err != nil {
		panic(err)
	}
	format(src)
}

func readFile() []byte {
	// b, err := os.ReadFile("../test-data/simple.gsql")
	b, err := os.ReadFile("../test-data/hello.gsql")
	if err != nil {
		panic(err)
	}
	return b
}

func format(sourceCode []byte) {
	// parse the sourceCode into a tree
	parser := sitter.NewParser()
	parser.SetLanguage(gsql.GetLanguage())
	// tree, _ := parser.ParseCtx(context.Background(), nil, sourceCode)
	tree := parser.Parse(nil, sourceCode)
	n := tree.RootNode()
	fmt.Println(n)
	// fmt.Println()

	child := n.NamedChild(0)
	fmt.Println(child.Type())

	switch child.Type() {
	case "create_query":
		gfmt.CreateQuery(child, sourceCode)
	case "interpret_query":
		panic("not done yet")
	}

	// fmt.Println()
	// fmt.Println(child.NextSibling().Type())
}
