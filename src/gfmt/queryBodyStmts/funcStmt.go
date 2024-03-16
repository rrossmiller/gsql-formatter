package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func funcStmt(node *sitter.Node, src []byte, indentLvl int) string {
	var sb strings.Builder
	sb.WriteString(util.GetIndent(indentLvl))
	fmt.Println("****")
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child.Type())
		var txt string
		switch child.Type() {
		case "arg_list":
			txt = argList(child, src)
		case ",":
			txt = ", "
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}
	fmt.Println("****")

	return sb.String()
}

func argList(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println("****")
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child.Type())
		var txt string
		switch child.Type() {
		case "expr":
			txt = expr(child, src)
		case ",":
			txt = ", "
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}
	fmt.Println("****")

	return sb.String()
}
