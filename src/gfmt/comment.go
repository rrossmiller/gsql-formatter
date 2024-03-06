package gfmt

import (
	"fmt"
	sitter "github.com/smacker/go-tree-sitter"
	"os"
	"strings"
)

func BlockComment(node *sitter.Node, src []byte, indentLevel uint) string {
	var sb strings.Builder
	txt := GetNodeText(node, src)
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child)
	}
	os.Exit(0)
	sb.WriteString(txt)
	return sb.String()
}

func LineComment(node *sitter.Node, src []byte, indentLevel uint) string {
	var sb strings.Builder

	return sb.String()
}
