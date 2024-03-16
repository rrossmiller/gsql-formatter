package util

import (
	"os"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
	"gopkg.in/yaml.v3"
)

// Configs
type Config struct {
	IndentWidth int `yaml:"indentWidth"`
}

var fmtConfig Config

func GetConfig() error {
	// read the config file
	home, err := os.UserHomeDir()
	if err != nil {
		return err
	}
	b, err := os.ReadFile(home + "/.grommetcfg.yml")
	if err != nil {
		// file doesn't exist. use default
		if os.IsNotExist(err) {
			fmtConfig = Config{IndentWidth: 4}
			return nil
		}
		return err
	}

	// parse config file
	var cfg Config
	err = yaml.Unmarshal(b, &cfg)
	if err != nil {
		return err
	}
	fmtConfig = cfg
	return nil
}

// --

// Concat all text in the within the node
func ConsumeNode(node *sitter.Node, src []byte) string {
	var sb strings.Builder
	for i := 0; i < int(node.ChildCount()); i++ {
		child := node.Child(i)
		txt := GetNodeText(child, src)
		sb.WriteString(txt)
	}

	return sb.String()
}
func GetNodeText(node *sitter.Node, src []byte) string {
	stb := node.StartByte()
	eb := node.EndByte()
	txt := string(src[stb:eb])
	txt = strings.TrimSpace(txt)
	txt = strings.ReplaceAll(txt, "\n", "")
	return txt
}

func GetIndent(indentLvl int) string {
	return strings.Repeat(" ", fmtConfig.IndentWidth*indentLvl)
}
