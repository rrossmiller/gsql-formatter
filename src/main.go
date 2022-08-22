package main

import (
	"os"
	"pepper/reserved"
	"pepper/utils"
	"strings"
	"unicode/utf8"
)

func main() {
	// load file
	fp := "../test-data/simple.gsql"
	// fp := "../test-data/complex.gsql"
	b, err := os.ReadFile(fp)
	utils.Check(err)
	queryString := string(b)

	queryString = EqualizeSpacing(queryString)
	// EqualizeSpacing("../test-data/complex.gsql")

	queryString = CapitalizeKeywords(queryString)

	// TODO ifblock indentation (should work inside select, too)

	WriteQuery(queryString, fp)
}

func EqualizeSpacing(queryString string) string {
	// split into lines
	queryText := strings.Split(queryString, "\n")

	// remove a file's trailing newline
	if queryText[len(queryText)-1] == "" {
		queryText = queryText[:len(queryText)-1]
	}

	// resest all leading whitespace/indentation
	for i, line := range queryText {
		// skip empty lines
		if utf8.RuneCountInString(line) == 0 {
			continue
		}
		runes := []rune(line)
		runes = utils.RemoveLeadingWhitespace(runes)
		queryText[i] = string(runes)
	}

	for i, line := range queryText {
		// skip empty lines
		if utf8.RuneCountInString(line) == 0 {
			continue
		}

		// if the line is a select statement
		if lower := strings.ToLower(line); strings.Contains(lower, " select ") {
			// find which line the select statement ends on --> j
			for j := i; j < len(queryText); j++ {
				if strings.ContainsRune(queryText[j], ';') {
					// correct indentation for the block
					utils.SelectBlock(i, j, queryText)

					// idx := 0
					// for k := i; k <= j; k++ {
					// 	queryText[k] = sel_out[idx]
					// 	idx++
					// }
					break
				}
			}
		}
		// if lower := strings.ToLower(line); strings.Contains(lower, "if ") {
		// 	// find which line the IF statement ends on --> j
		// 	for j := i; j < len(queryText); j++ {
		// 		if queryText[j] == "end" {
		// 			// correct indentation for the block
		// 			sel_out := utils.IfBlock(i, j, queryText)

		// 			idx := 0
		// 			for k := i; k <= j; k++ {
		// 				queryText[k] = sel_out[idx]
		// 				idx++
		// 			}
		// 			break
		// 		}
		// 	}
		// }

		// default one indentation for query body
		if i > 0 && i < len(queryText)-1 {
			queryText[i] = reserved.INDENTATION + queryText[i] // TODO change to config.NumIndents or something like that

		}
	}

	outSlice := strings.Join(queryText, "\n")
	return outSlice
}

func CapitalizeKeywords(queryString string) string {
	queryStringSplit := strings.Split(queryString, " ")
	outSlice := make([]string, 0)
	isComment := false
	for _, word := range queryStringSplit {
		for _, kw := range reserved.KEYWORDS {
			if strings.Contains(word, "\n") {
				isComment = false
			}
			if strings.HasPrefix(word, "//") || isComment {
				isComment = true
				continue
			} else if strings.ToUpper(word) == kw {
				word = strings.ToUpper(word)
			}
		}
		outSlice = append(outSlice, word)
	}

	out := strings.Join(outSlice, " ")
	return out
}

func WriteQuery(query, fp string) {
	os.WriteFile(fp, []byte(query), 0666)
}
