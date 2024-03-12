package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func assignStmt(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	sb.WriteString(util.GetIndent(1))
	fmt.Println()
	fmt.Println("****")
	fmt.Println(node)
	fmt.Println(node.ChildCount())
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		fmt.Println(child.Type(), child.ChildCount(), txt)
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
	fmt.Println("****")
	fmt.Println()

	// sb.WriteString(util.GetIndent(1))
	// sb.WriteString(txt)
	return sb.String()
}
