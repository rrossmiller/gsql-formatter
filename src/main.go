package main

import (
	"fmt"
	"os"
	"pepper/utils"
	"strings"
)

func main() {
	EqualizeSpacing("../test-data/complex.gsql")
}

func Check(err error) {
	if err != nil {
		panic(err)
	}
}

func EqualizeSpacing(fp string) {
	b, err := os.ReadFile(fp)
	Check(err)
	queryText := strings.Split(string(b), "\n")
	if queryText[len(queryText)-1] == "" {
		queryText = queryText[:len(queryText)-1]
	}

	for i, line := range queryText {
		if len(line) == 0 {
			continue
		}

		runes := []rune(line)
		runes = utils.RemoveLeadingWhitespace(runes)
		queryText[i] = string(runes)
	}
	for i, line := range queryText {
		if len(line) == 0 {
			continue
		}
		if lower := strings.ToLower(line); strings.Contains(lower, " select ") {
			for j := i; j < len(queryText); j++ {
				if strings.ContainsRune(queryText[j], ';') {
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

		if i > 0 && i < len(queryText)-1 {
			queryText[i] = "\t" + queryText[i]

		}
	}

	out := strings.Join(queryText, "\n")
	os.WriteFile(fp, []byte(out), 0666)
}

func SelectBlocks(start, end int, queryText []string) []string {
	lower := strings.ToLower(queryText[start])
	spacingToSelect := strings.Index(lower, " select ") + 1

	rtn := make([]string, 0)
	rtn = append(rtn, queryText[start])

	fmt.Printf("%v\n", queryText[start])
	for i := start + 1; i <= end; i++ {
		tmp := strings.Repeat(" ", spacingToSelect) + queryText[i]
		fmt.Printf("%v\n", tmp)
		rtn = append(rtn, tmp)
	}
	return rtn

}
