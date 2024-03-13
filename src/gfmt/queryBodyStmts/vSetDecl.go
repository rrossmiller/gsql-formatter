package querybodystmts

import (
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func vSetDecl(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	sb.WriteString(util.GetIndent(1))
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "=":
			txt = " = "
		case "seed_set":
			txt = seedSet(child, src)
		default:
			txt = util.GetNodeText(child, src)
		}

		sb.WriteString(txt)
	}
	return sb.String()
}

func seedSet(node *sitter.Node, src []byte) string {
	var sb strings.Builder

	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case ",":
			txt = ", "
		default:
			txt = util.GetNodeText(child, src)
			txt = strings.ReplaceAll(txt, " ", "")
		}
		sb.WriteString(txt)
	}

	return sb.String()
}
