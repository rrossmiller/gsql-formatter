package main

import (
	"context"
	"errors"
	"fmt"
	"grommet/gfmt"
	"grommet/gfmt/util"
	"grommet/preprocess"
	gsql "grommet/sitterLang"
	"os"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func main() {
	fmt.Println("*******")
	pth := "../test-data/simple.gsql"
	if len(os.Args) > 1 {
		pth = os.Args[1]
	}
	sourceCode := readFile(pth)
	src, err := preprocess.Preprocess(sourceCode)
	if err != nil {
		panic(err)
	}
	writeFormattedQuery(string(src), "../test-data/pre.gsql")

	err = util.GetConfig()
	if err != nil {
		panic(err)
	}

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
		errPoint := findErr(root)
		return "", errors.New(fmt.Sprintf("There's an error at row: %d col: %d", errPoint.Row+1, errPoint.Column+1))
	}

	var sb strings.Builder
	for i := 0; i < int(root.ChildCount()); i++ {
		child := root.Child(i)
		// fmt.Println("root children:", child.Type())

		var txt string
		switch child.Type() {
		case "create_query":
			txt = gfmt.CreateQuery(child, sourceCode)
		case "interpret_query":
			panic("not done yet")
		case "query_body":
			txt = gfmt.QueryBody(child, sourceCode)
		case "block_comment":
			txt = gfmt.BlockComment(child, sourceCode, 0)
		case "line_comment":
			txt = gfmt.LineComment(child, sourceCode, 0)
		case "newline":
			txt = "\n"
		}
		sb.WriteString(txt)
	}

	return sb.String(), nil
}

func readFile(pth string) []byte {
	b, err := os.ReadFile(pth)
	if err != nil {
		panic(err)
	}
	return b
}
func writeFormattedQuery(q, pth string) error {
	err := os.WriteFile(pth, []byte(q), 0644)
	return err
}

func findErr(node *sitter.Node) sitter.Point {
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		if child.IsError() {
			return child.StartPoint()
		}
		if child.HasError() {
			return findErr(child)
		}
	}
	return sitter.Point{}
}
