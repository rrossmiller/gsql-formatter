// https://craftinginterpreters.com/scanning.html
just reread the book
package main

import (
	"bufio"
	"flag"
	"fmt"
	"gourmet/reserved"
	"gourmet/util"
	"os"
	"strings"
	"unicode/utf8"
)

/*
 1. make sure the token can be recognized by the scanner
 2. parse: https://craftinginterpreters.com/parsing-expressions.html
    if you hit an error, discard tokens until you hit a statement boundary https://craftinginterpreters.com/parsing-expressions.html#synchronizing-a-recursive-descent-parser
 3. AST/formatting
    AST takes a list of statements. Each statemtent has expressions that need to correctly placed on the page
*/
func main() {
	dev := flag.Bool("dev", false, "reset query after execution")

	var fp string
	flag.Parse()
	// parse args
	args := flag.Args()
	fmt.Printf("args: %v\n", args)
	if len(args) > 0 {
		fp = args[0]
	} else if fp == "" { //fixme remove after dev
		fp = "../test-data/simple.gsql"
	}

	// load file
	b, err := os.ReadFile(fp)
	util.Check(err)
	query := string(b)
	tkns := ScanTokens(query)
	ParseQuery(tkns) //!bookmark You are doing the parser
	//

	// TODO ifblock indentation (should work inside select, too)
	// WriteQuery(queryString, fp)

	// if in dev mode reset file
	if *dev {
		reader := bufio.NewReader(os.Stdin)
		fmt.Printf("Enter to reset %v: ", fp)
		text, _ := reader.ReadString('\n')
		fmt.Println(text)
		WriteQuery(string(b), fp)
	}

}

func EqualizeSpacing(queryString string) string {
	// split into lines
	queryText := strings.Split(queryString, "\n")

	// remove a file's trailing newline
	if queryText[len(queryText)-1] == "" {
		queryText = queryText[:len(queryText)-1]
	}

	// resest all leading whitespace/indentation
	tmp := make([]string, 0)
	for _, line := range queryText {
		// skip empty lines
		if utf8.RuneCountInString(line) != 0 {
			runes := []rune(line)
			runes = util.RemoveLeadingWhitespace(runes)
			if len(runes) > 0 {
				tmp = append(tmp, string(runes))
			}
		}
	}
	queryText = tmp

	for i, line := range queryText {
		// if the line is a select statement
		if lower := strings.ToLower(line); strings.Contains(lower, " select ") {
			// find which line the select statement ends on --> j
			for j := i; j < len(queryText); j++ {
				if strings.ContainsRune(queryText[j], ';') {
					// correct indentation for the block
					util.SelectBlock(i, j, queryText)
					break
				}
			}
		}
		// if lower := strings.ToLower(line); strings.Contains(lower, "if ") {
		// 	// find which line the IF statement ends on --> j
		// 	for j := i; j < len(queryText); j++ {
		// 		if queryText[j] == "end" {
		// 			// correct indentation for the block
		// 			sel_out := util.IfBlock(i, j, queryText)

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
			} else if w := strings.ReplaceAll(word, "\n", ""); strings.ToUpper(w) == kw {
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
