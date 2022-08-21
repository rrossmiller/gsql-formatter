package main

import (
	"os"
	"pepper/reserved"
	"pepper/utils"
	"strings"
	"unicode/utf8"
)

func main() {
	EqualizeSpacing("../test-data/simple.gsql")
	// EqualizeSpacing("../test-data/complex.gsql")

	// caps keywords
	CapitalizeKeywords("../test-data/simple.gsql")
	// writebytes()
	// ifblock indentation (should work inside select, too)
}

func Check(err error) {
	if err != nil {
		panic(err)
	}
}

func EqualizeSpacing(fp string) {
	// load file
	b, err := os.ReadFile(fp)
	Check(err)

	// split into lines
	queryText := strings.Split(string(b), "\n")

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
					sel_out := SelectBlocks(i, j, queryText)

					idx := 0
					for k := i; k <= j; k++ {
						queryText[k] = sel_out[idx]
						idx++
					}
					break
				}
			}

		}

		// default one indentation for query body
		if i > 0 && i < len(queryText)-1 {
			queryText[i] = reserved.INDENTATION + queryText[i] // TODO change to config.NumIndents or something like that

		}
	}

	out := strings.Join(queryText, "\n")
	os.WriteFile(fp, []byte(out), 0666)
}

func SelectBlocks(start, end int, queryText []string) []string {
	// get the number of spaces to the 'S' in SELECT
	lower := strings.ToLower(queryText[start])
	spacingToSelect := strings.Index(lower, " select ") + 1

	rtn := make([]string, end-start+1)
	rtn[0] = queryText[start]

	// set spacing for the lines
	idx := 1
	indentLevel := 0 // if the line is a WHERE/Accum, subsequent lines should be indented again
	for i := start + 1; i <= end; i++ {
		rtn[idx] = strings.Repeat(" ", spacingToSelect) + queryText[i]
		if containsSelectKeyword(queryText[i]) {
			if indentLevel > 0 {
				indentLevel--
			} else {
				indentLevel++
			}
		} else {
			rtn[idx] = reserved.HALF_INDENTATION + rtn[idx]

		}
		idx++
	}

	// if the next line is not blank, insert an empty line
	if end < len(queryText) {
		if queryText[end+1] != "" {
			rtn[len(rtn)-1] += "\n"
		} else {
			// leave only one space between query blocks
			for j := end + 2; j < len(queryText); j++ {
				if queryText[j] != "" {
					queryText = append(queryText[:end+1], queryText[j-1:]...)
					break
				}
			}
		}
	}
	return rtn

}

func containsSelectKeyword(line string) bool {
	for _, kw := range reserved.SELECT_KEYWORDS {
		if strings.Contains(line, kw) {
			return true
		}
	}

	return false
}

func CapitalizeKeywords(fp string) {
	// // load file
	// b, err := os.ReadFile(fp)
	// Check(err)
}
