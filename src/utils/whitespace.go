package utils

import (
	"unicode"
)

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
