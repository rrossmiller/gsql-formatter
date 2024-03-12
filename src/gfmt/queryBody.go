package gfmt

import (
	"fmt"
	querybodystmts "grommet/gfmt/queryBodyStmts"
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
			break
		case "}":
			txt = "}\n"
			break
		case "typedef":
			txt = TypeDef(child, src)
			// separate typedefs from rest of query
			if child.NextSibling().Type() != "typedef" {
				txt += "\n"
			}
			break
		case "query_body_stmt":
			txt = querybodystmts.QueryBodyStmts(child, src)
			break
		case "block_comment":
			txt = BlockComment(child, src, 1)
			break
		case "line_comment":
			txt = LineComment(child, src, 1)
			break
		case "spacing_line":
			// if i > 0 && i+1 < int(node.ChildCount()) && node.Child(i-1).Type() != "query_body_stmt" {
			txt = "\n"
			// }
			break
		}
		sb.WriteString(txt)
	}
	return sb.String()
}
