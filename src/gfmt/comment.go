package gfmt

import (
	sitter "github.com/smacker/go-tree-sitter"
	"strings"
)

func BlockComment(node *sitter.Node, src []byte, indentLevel uint) string {
	var sb strings.Builder
	defer sb.Reset()
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		txt := GetNodeText(child, src)
		if child.Type() != "/*" && child.Type() != "*/" {
			sb.WriteString("    ") //TODO: configureable space indenting
		}
		sb.WriteString(txt)
		sb.WriteString("\n")
	}
	return sb.String()
}

func LineComment(node *sitter.Node, src []byte, indentLevel uint) string {
	var sb strings.Builder
	defer sb.Reset()
	txt := GetNodeText(node, src)
	sb.WriteString(txt)
	sb.WriteString("\n")
	return sb.String()
}
