package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func expr(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "expr":
			txt = expr(child, src)
		case "name_dot":
			txt = nameDot(child, src)
		case "set_bag_expr":
			txt = setBagExpr(child, src)
		case "math_operator":
			txt = fmt.Sprintf(" %s ", util.GetNodeText(child, src))
			fmt.Println(txt)
		case "constant":
			txt = constant(child, src)
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}

func nameDot(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		txt := util.GetNodeText(child, src)
		sb.WriteString(txt)
	}

	return sb.String()
}

func setBagExpr(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "name_dot":
			txt = nameDot(child, src)
		case "set_bag_expr":
			txt = setBagExpr(child, src)
		case "UNION", "INTERSECT", "MINUS":
			txt = fmt.Sprint(" ", util.GetNodeText(child, src), " ")
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}
