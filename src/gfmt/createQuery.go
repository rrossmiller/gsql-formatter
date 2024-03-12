package gfmt

import (
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func CreateQuery(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		if child.Type() == "parameter_list" {
			txt = parameterList(child, src)
		} else if i != 0 {
			txt = " " + util.GetNodeText(child, src)
		} else {
			txt = util.GetNodeText(child, src)
		}

		sb.WriteString(txt)
	}
	return sb.String()
}

func parameterList(node *sitter.Node, src []byte) string {
	var sb strings.Builder

	sb.WriteString("(")
	node = node.Child(1) // skip open parens

	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		switch child.Type() {
		case ",":
			sb.WriteString(", ")
			break
		case "query_param":
			param := queryParam(child, src)
			sb.WriteString(param)
			break
		}

	}
	sb.WriteString(")")

	return sb.String()
}

func queryParam(node *sitter.Node, src []byte) string {

	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		if child.Type() == "set_param" {
			txt := setParam(child, src)
			sb.WriteString(txt)
		} else {
			txt := util.GetNodeText(child, src)
			if i < int(node.ChildCount())-1 {
				txt += " "
			}
			sb.WriteString(txt)
		}
	}

	return sb.String()
}

func setParam(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		sb.WriteString(util.GetNodeText(child, src))
	}

	sb.WriteString(" ")
	return sb.String()
}
