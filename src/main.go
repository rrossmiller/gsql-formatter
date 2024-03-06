package main

import (
	"context"
	"fmt"
	"grommet/gfmt"
	"grommet/preprocess"
	gsql "grommet/sitterLang"
	"os"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

type treeError struct {
	msg string
}

func (e *treeError) Error() string {
	return e.msg
}

func main() {
	fmt.Println("*******")
	// pth := "../test-data/simple.gsql"
	pth := "../test-data/hello.gsql"
	if len(os.Args) > 1 {
		pth = os.Args[1]
	}
	sourceCode := readFile(pth)
	src, err := preprocess.Preprocess(sourceCode)
	if err != nil {
		panic(err)
	}
	writeFormattedQuery(string(src), "../test-data/pre.gsql")
	formatted, err := format(src)
	if err != nil {
		panic(err)
	}
	err = writeFormattedQuery(formatted, "../test-data/fmt.gsql")
	if err != nil {
		panic(err)
	}
}

func format(sourceCode []byte) (string, error) {
	// parse the sourceCode into a tree
	parser := sitter.NewParser()
	parser.SetLanguage(gsql.GetLanguage())
	tree, err := parser.ParseCtx(context.Background(), nil, sourceCode)
	if err != nil {
		return "", err
	}
	root := tree.RootNode()
	fmt.Println(root)
	fmt.Println("error:", root.HasError())
	if root.HasError() {
		return "", &treeError{msg: "there was an error in the syntax tree"}
	}

	var sb strings.Builder
	for i := 0; i < int(root.ChildCount()); i++ {
		child := root.Child(i)
		fmt.Println(child.Type())

		switch child.Type() {
		case "create_query":
			s := gfmt.CreateQuery(child, sourceCode)
			sb.WriteString(s)
			break
		case "interpret_query":
			panic("not done yet")
		case "query_body":
			txt := gfmt.QueryBody(child, sourceCode)
			sb.WriteString(txt)
		}
	}

	return sb.String(), nil
}

func readFile(pth string) []byte {
	b, err := os.ReadFile(pth)
	// b, err := os.ReadFile("../test-data/hello.gsql")
	if err != nil {
		panic(err)
	}
	return b
}
func writeFormattedQuery(q, pth string) error {
	err := os.WriteFile(pth, []byte(q), 0644)
	return err
}
