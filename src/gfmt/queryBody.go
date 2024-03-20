package gfmt

import (
	"fmt"
	qbs "grommet/gfmt/querybodystatements"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
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
		case "}":
			txt = "}\n"
		case "typedef":
			txt = TypeDef(child, src)
			// separate typedefs from rest of query
			// if child.NextSibling().Type() != "typedef" {
			// 	txt += "\n"
			// }
		case "query_body_stmt":
			txt = qbs.QueryBodyStmts(child, src)
		case "block_comment":
			txt = qbs.BlockComment(child, src, 1)
		case "line_comment":
			txt = qbs.LineComment(child, src, 1)
		case "spacing_line":
			txt = "\n"
		}
		sb.WriteString(txt)
	}
	return sb.String()
}
