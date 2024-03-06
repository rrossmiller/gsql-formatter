package gfmt

import (
	"fmt"
	sitter "github.com/smacker/go-tree-sitter"
	"strings"
)

func CreateQuery(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	fmt.Println()

	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		var txt string
		if child.Type() == "parameter_list" {
			txt = parameterList(child, src)
		} else {

			txt = GetNodeText(child, src)
		}
		sb.WriteString(txt + " ")
	}
	return sb.String()
}

/*
parameter_list: $ => seq(

	"(",
	repeat($.query_params),
	")"

),

query_params: $ => seq(

	$.query_param,
	optional(
		repeat(seq(",", $.query_param))
	)

),

query_param: $ => seq(

	$._type,
	$.name,
	optional(seq("=", $.numeric))

),
*/
func parameterList(node *sitter.Node, src []byte) string {
	var sb strings.Builder

	fmt.Println("********")
	sb.WriteString("(")
	node = node.Child(1) // skip open parens
	fmt.Println(GetNodeText(node, src))
	fmt.Println(node.Type())
	fmt.Println(node.ChildCount())
	fmt.Println()
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		switch child.Type() {
		case ",":
			sb.WriteString(", ")
			break
		case "query_param":
			param := queryParam(child, src)
			sb.WriteString(param)
			break
		}
		fmt.Println()
	}
	sb.WriteString(")")
	fmt.Println("********")
	return sb.String()
}

func queryParam(node *sitter.Node, src []byte) string {
	fmt.Println("params")
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		if child.Type() == "set_param" {
			txt := setParam(child, src)
			sb.WriteString(txt)
		} else {
			fmt.Println(child.Type())
			txt := GetNodeText(child, src)
			if i < int(node.ChildCount())-1 {
				txt += " "
			}
			sb.WriteString(txt)
		}
	}

	return sb.String()
}

func setParam(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		sb.WriteString(GetNodeText(child, src))
	}

	sb.WriteString(" ")
	return sb.String()
}
