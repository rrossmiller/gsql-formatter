package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func declStmt(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "base_decl_stmt":
			txt = baseDecl(child, src)
		case "accum_decl_stmt":
			txt = accumDecl(child, src)

		}
		sb.WriteString(util.GetIndent(1))
		sb.WriteString(txt)
	}

	return sb.String()
}

func baseDecl(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		if child.ChildCount() > 0 {
			txt = util.GetNodeText(child.Child(0), src)
		} else {
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)

		if i < int(node.ChildCount())-1 && node.Child(i+1).Type() != "," {
			sb.WriteString(" ")
		}
	}
	return sb.String()
}

func accumDecl(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "accum_type":
			txt = accumType(child, src)
		case ",":
			txt = ", "
		case "=":
			txt = " = "
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}

func accumType(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(">",child.Type())
		var txt string
		switch child.Type() {
		case "accum_type":
			txt = accumType(child, src)
		case "base_type":
			txt = util.GetNodeText(child, src) 
		case ",":
			txt = ", "
		case "ASC", "DESC":
			txt = " " + util.GetNodeText(child, src)
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	sb.WriteString(" ")
	return sb.String()
}
