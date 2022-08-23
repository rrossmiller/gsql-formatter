package utils

import (
	"gourmet/reserved"
	"strings"
)

func GetBracketState(bracketState int, line string) int {
	bracketState -= strings.Count(line, "}")
	bracketState += strings.Count(line, "{")

	if bracketState < 0 {
		return 0
	}
	return bracketState
}

func SelectBlock(start, end int, queryText []string) {
	// get the number of spaces to the 'S' in SELECT
	lower := strings.ToLower(queryText[start])
	spacingToSelect := strings.Index(lower, " select ") + 1

	outSlice := make([]string, end-start+1)
	outSlice[0] = queryText[start]

	// set spacing for the lines
	idx := 1
	indentLevel := 0 // if the line is a WHERE/Accum, subsequent lines should be indented again
	for i := start + 1; i <= end; i++ {
		queryText[i] = strings.Repeat(" ", spacingToSelect) + queryText[i]
		if reserved.ContainsSelectKeyword(queryText[i]) {
			if indentLevel > 0 {
				indentLevel--
			} else {
				indentLevel++
			}
		} else {
			queryText[i] = reserved.HALF_INDENTATION + queryText[i]
		}
		idx++
	}

	// if the next line is not blank, insert an empty line
	if end < len(queryText) {
		if queryText[end+1] != "" {
			queryText[end] += "\n"
		}
	}
}

// // come back to this with an AST. You need to know the purpose of a bracket to get the right indent
// func Brackets(){
// 		// fist line should not be indented
// 		if bracketState == 0 && unicode.IsSpace(runes[0]) {
// 			idx := 0
// 			for i := 0; i < len(runes); i++ {
// 				if unicode.IsSpace(runes[i]) {
// 					idx++
// 				} else {
// 					break
// 				}
// 			}
// 			runes = runes[idx:]
// 		}

// 		bracketState = GetBracketState(bracketState, line)

// }
