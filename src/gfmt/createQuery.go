package gfmt

import (
	"fmt"
	sitter "github.com/smacker/go-tree-sitter"
)

func CreateQuery(node *sitter.Node, src []byte) {
	// sb := node.StartByte()
	// eb := node.EndByte()
	// fmt.Println(sb)
	// fmt.Println(eb)
	// fmt.Println(string(src[sb:eb]))
	fmt.Println()
	fmt.Println(node.ChildCount())
	fmt.Println()

	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)

		fmt.Println(child.Type())
		sb := child.StartByte()
		eb := child.EndByte()
		// fmt.Println(sb)
		// fmt.Println(eb)
		fmt.Println(string(src[sb:eb]))
		fmt.Println()
	}
}
