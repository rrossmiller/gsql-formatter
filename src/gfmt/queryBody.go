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

	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println("QB:", child.Type())
		var txt string
		switch child.Type() {
		case "{":
			txt = "{\n"
			break
		case "typedef":
			txt = typeDef(child, src)
			// txt = GetNodeText(child, src)
			// txt += "\n"
			// separate typedefs from rest of query
			if child.NextSibling().Type() != "typedef" {
				txt += "\n"
			}
			break
		case "query_body_stmts":
			txt = GetNodeText(child, src)
			txt += "\n"
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

func typeDef(node *sitter.Node, src []byte) string {
	var sb strings.Builder

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
				txt = GetNodeText(child, src)
				break
			default:
				txt = GetNodeText(child, src) + " "
				break
			}
		}
		sb.WriteString(txt)
	}
	return sb.String()
}

func tupleField(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		sb.WriteString(GetNodeText(child, src))
		if i < int(node.ChildCount())-1 {
			sb.WriteString(" ")
		}
	}

	return sb.String()
}

