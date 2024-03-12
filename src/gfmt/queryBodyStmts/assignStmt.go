package querybodystmts

import (
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func assignStmt(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	sb.WriteString(util.GetIndent(1))
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "=":
			txt = " = "
			break
		default:
			txt = util.GetNodeText(child, src)
			break
		}

		sb.WriteString(txt)
	}
	return sb.String()
}
