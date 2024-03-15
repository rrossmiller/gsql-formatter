package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func constant(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println("****")
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "integer", "real":
			txt = number(child, src)
		case "string_literal":
			txt = stringLiteral(child, src)
			fmt.Printf("txt '%s'\n", txt)
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}
	fmt.Println("****")
	// sb.WriteString("\n\nworking on capturing string literals\n")

	return sb.String()
}

func number(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println("****")
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}
	fmt.Println("****")

	return sb.String()
}

func stringLiteral(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println("****")
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "space":
		txt=" "
		default:
			txt = util.GetNodeText(child, src)
		}
		fmt.Println("str child content:", txt, child)
		sb.WriteString(txt)
	}
	fmt.Println("****")

	return sb.String()
}
