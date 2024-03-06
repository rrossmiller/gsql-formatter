package gfmt

import (
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetNodeText(node *sitter.Node, src []byte) string {
	stb := node.StartByte()
	eb := node.EndByte()
	txt := string(src[stb:eb])
	txt = strings.TrimSpace(txt)
	txt = strings.ReplaceAll(txt, "\n", "")
	return txt
}
