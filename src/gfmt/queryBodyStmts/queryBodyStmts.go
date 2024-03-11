package querybodystmts

import (
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func QueryBodyStmts(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		switch child.Type() {
		case "decl_stmt":
			txt = declStmt(child, src)
			break
		case "assign_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "v_set_var_decl_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "l_accum_assign_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "g_accum_assign_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "g_accum_accum_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "func_call_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "_select_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "query_body_case_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "query_body_if_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "query_body_while_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "query_body_for_each_stmt":
			txt = util.GetNodeText(child, src)
			break
		case "print_stmt":
			txt = util.GetNodeText(child, src)
			break
		case ";":
			sb.WriteString(";\n")
			break
		}
		sb.WriteString(txt)
	}

	return sb.String()
}
