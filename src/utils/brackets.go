package utils

import "strings"

func GetBracketState(bracketState int, line string) int {
	bracketState -= strings.Count(line, "}")
	bracketState += strings.Count(line, "{")

	if bracketState < 0 {
		return 0
	}
	return bracketState
}
func GetIndentState(){
	
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
