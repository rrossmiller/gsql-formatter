package utils

import (
	"unicode"
)
const INDENTATION = "    " //fixme set in init and from .gourmetconfig
// const HALF_INDENTATION = "  "

var KW_INDENTATION = map[string]string{
	"ACCUM": "      ",
	"AND":   "    ",
	"WHERE": "      ",
}

func RemoveLeadingWhitespace(runes []rune) []rune {
	if unicode.IsSpace(runes[0]) {
		i := 0
		for ; i < len(runes); i++ {
			if !unicode.IsSpace(runes[i]) {
				break
			}
		}
		return runes[i:]
	}

	return runes
}
