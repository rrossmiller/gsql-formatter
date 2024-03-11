package gfmt

import (
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func BlockComment(node *sitter.Node, src []byte, indentLevel int) string {
	var sb strings.Builder
	defer sb.Reset()
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		txt := util.GetNodeText(child, src)
		if child.Type() != "/*" && child.Type() != "*/" {
			sb.WriteString(util.GetIndent(indentLevel+1))
		} else {
			sb.WriteString(util.GetIndent(indentLevel))
		}
		sb.WriteString(txt)
		sb.WriteString("\n")
	}
	return sb.String()
}

func LineComment(node *sitter.Node, src []byte, indentLevel int) string {
	var sb strings.Builder
	defer sb.Reset()
	txt := util.GetNodeText(node, src)

	sb.WriteString(util.GetIndent(indentLevel))
	sb.WriteString(txt)
	sb.WriteString("\n")
	return sb.String()
}
