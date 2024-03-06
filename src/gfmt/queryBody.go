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
		var txt string
		switch child.Type() {
		case "typedef":
			txt = GetNodeText(child, src)
			break
		case "query_body_stmts":
			txt = GetNodeText(child, src)
			break
		case "block_comment":
			txt = BlockComment(child, src, 0)
			break
		case "line_comment":
			txt = LineComment(child, src, 0)
			break
		}
		sb.WriteString(txt + " ")
	}
	return sb.String()
}
