package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func declStmt(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println()
	fmt.Println("****")
	fmt.Println(node)
	fmt.Println(node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child.Type(), child.ChildCount())
		var txt string
		switch child.Type() {
		case "base_decl_stmt":
			txt = baseDecl(child, src)
			break
		case "accum_decl_stmt":
			txt = accumDecl(child, src)
			break

		}
		sb.WriteString(util.GetIndent(1))
		sb.WriteString(txt)
	}
	fmt.Println("****")
	fmt.Println()

	return sb.String()
}

func baseDecl(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child, child.Type(), child.ChildCount())

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
	fmt.Println(">>>")
	// fmt.Println(node)
	// fmt.Println(node.ChildCount())

	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child, child.Type(), child.ChildCount())
		var txt string
		switch child.Type() {
		case "accum_type":
			txt = accumType(child, src)
			break
		case ",":
			txt = ", "
			break
		case "=":
			txt = " = "
			break
		default:
			txt = util.GetNodeText(child, src)
			break
		}
		sb.WriteString(txt)
	}
	fmt.Println(">>>")

	return sb.String()
}

func accumType(node *sitter.Node, src []byte) string {
	var sb strings.Builder

	fmt.Println("type info...")
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child.Type())
		var txt string
		switch child.Type() {
		case "accum_type":
			txt = accumType(child, src)
			break
		case "base_type":
			txt = util.GetNodeText(child, src) + " "
			break
		case ",":
			txt = ", "
			break
		case "ASC", "DESC":
			txt = " " + util.GetNodeText(child, src)
			break
		default:
			txt = util.GetNodeText(child, src)
			break
		}
		sb.WriteString(txt)
	}

	fmt.Println("accum type func done")
	sb.WriteString(" ")
	return sb.String()
}
