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
		case "integer":
			fmt.Println("int")
			txt = util.GetNodeText(child, src)
		case "real":
			fmt.Println("real")
			txt = util.GetNodeText(child, src)
		case "string_literal":
			fmt.Println("string")
			txt = util.GetNodeText(child, src)
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}
	fmt.Println("****")
	sb.WriteString("\n\nworking on const/int/real/string\n")

	return sb.String()
}
