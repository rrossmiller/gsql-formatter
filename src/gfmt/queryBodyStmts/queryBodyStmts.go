package querybodystmts

import (
	"fmt"
	"grommet/gfmt/util"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func QueryBodyStmts(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		fmt.Println("top:", child.Type())
		var txt string
		switch child.Type() {
		case "decl_stmt":
			txt = declStmt(child, src)
		case "assign_stmt":
			txt = assignStmt(child, src)
		case "v_set_var_decl_stmt":
			txt = vSetDecl(child, src)
		case "l_accum_assign_stmt":
			txt = localAccumAssign(child, src)
		case "g_accum_assign_stmt":
			txt = util.GetNodeText(child, src)
		case "g_accum_accum_stmt":
			txt = util.GetNodeText(child, src)
		case "func_call_stmt":
			txt = util.GetNodeText(child, src)
		case "gsql_select_block":
			txt = util.GetNodeText(child, src)
		case "query_body_case_stmt":
			txt = util.GetNodeText(child, src)
		case "query_body_if_stmt":
			txt = util.GetNodeText(child, src)
		case "query_body_while_stmt":
			txt = util.GetNodeText(child, src)
		case "query_body_for_each_stmt":
			txt = util.GetNodeText(child, src)
		case "print_stmt":
			txt = util.GetNodeText(child, src)
		case ";":
			sb.WriteString(";\n")
		}
		sb.WriteString(txt)
	}

	return sb.String()
}
