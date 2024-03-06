package gfmt

import (
	"fmt"
	sitter "github.com/smacker/go-tree-sitter"
	"strings"
)

func QueryBody(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println()
	fmt.Println(node.ChildCount())
	fmt.Println()

	if node.Child(0).Type() == "{" {
		sb.WriteString("{\n")
	}
		fmt.Println(node.Child(0).Type())
	for i := 1; i < int(node.ChildCount()); i++ {
		child := node.Child(i)

		fmt.Println(child.Type())
		txt := GetNodeText(child, src)
		sb.WriteString(txt + " ")
	}
	return sb.String()
}
