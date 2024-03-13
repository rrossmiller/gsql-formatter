package gfmt

import (
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func TypeDef(node *sitter.Node, src []byte) string {
	var sb strings.Builder

	sb.WriteString(util.GetIndent(1))
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		if child.Type() == "tuple_fields" {
			var fields strings.Builder
			for i := 0; i < int(child.ChildCount()); i++ {
				fieldNode := child.Child(i)
				if fieldNode.Type() == "," {
					fields.WriteString(", ")
				} else {
					fieldTxt := tupleField(fieldNode, src)
					fields.WriteString(fieldTxt)
				}
			}
			txt = fields.String()
		} else {
			// get type or field name and switch on that
			switch child.Type() {
			case "<", "name":
				txt = util.GetNodeText(child, src)
			default:
				txt = util.GetNodeText(child, src) + " "
			}
		}
		sb.WriteString(txt)
	}
	sb.WriteString("\n")
	return sb.String()
}

func tupleField(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		sb.WriteString(util.GetNodeText(child, src))
		if i < int(node.ChildCount())-1 {
			sb.WriteString(" ")
		}
	}

	return sb.String()
}
