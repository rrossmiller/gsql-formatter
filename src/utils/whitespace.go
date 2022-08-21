package utils

import "unicode"

func RemoveLeadingWhitespace(runes []rune) []rune {
	if unicode.IsSpace(runes[0]) {
		idx := 0
		for i := 0; i < len(runes); i++ {
			if unicode.IsSpace(runes[i]) {
				idx++
			} else {
				break
			}
		}
		return runes[idx:]
	}

	return runes
}
