package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func gsqlSelect(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	sb.WriteString(util.GetIndent(1))
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "gsql_select_clause":
			txt = gsqlSelectClause(child, src)
		case "from_clause":
			txt = fromClause(child, src)
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}

func gsqlSelectClause(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		txt := util.GetNodeText(child, src)
		sb.WriteString(txt)
		sb.WriteString(" ")
	}

	return sb.String()
}

func fromClause(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "FROM":
			txt = "FROM "
		case "step":
			txt = step(child, src)
		case "path_pattern":
			txt = pathPattern(child, src)
		case "step_v2":
		default:
			txt = util.GetNodeText(child, src)
		}
		sb.WriteString(txt)
	}

	return sb.String()
}

func step(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println("****")
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println(child.Type())
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

func pathPattern(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println("****")
	fmt.Println(node, node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {

		case "step_source_set":
			txt = util.ConsumeNode(child, src)
		default:
			txt = util.GetNodeText(child, src)
			fmt.Println(txt)
		}
		sb.WriteString(txt)
	}
	fmt.Println("****")

	return sb.String()
}

func stepSourceSet(node *sitter.Node, src []byte) string {
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

func stepEdgeSet(node *sitter.Node, src []byte) string {
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

func stepVertexSet(node *sitter.Node, src []byte) string {
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
