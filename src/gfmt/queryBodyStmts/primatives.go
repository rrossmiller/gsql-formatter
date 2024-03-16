package querybodystmts

import (
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func constant(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "integer", "real":
			txt = number(child, src)
		case "string_literal":
			txt = stringLiteral(child, src)
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}

func number(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}

func stringLiteral(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "space":
		txt=" "
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}
