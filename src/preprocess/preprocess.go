package preprocess

import (
	"regexp"
	"strings"
)

// preprocess the words in the query to abide by the caps rules
func Preprocess(b []byte) ([]byte, error) {
	// blankLines := regexp.MustCompile(`(?m)^\n`)
	// b = blankLines.ReplaceAll(b, []byte("<_-_-_>\n"))

	spl := regexp.MustCompile(`\b`)
	src := spl.Split(string(b), -1)
	var sb strings.Builder

	for _, w := range src {
		for _, k := range keywordRegexes {
			r, err := regexp.Compile(k)
			if err != nil {
				return nil, err
			}
			if match := r.FindString(w); len(match) > 0 {
				v := words[strings.ToLower(match)]
				w = strings.ReplaceAll(w, match, v)

				break
			}
		}
		_, err := sb.WriteString(w)
		if err != nil {
			return []byte(sb.String()), err
		}
	}

	return []byte(sb.String()), nil
}
