package preprocess

import (
	"fmt"
	"strings"
)

// preprocess the words in the query to abide by the caps rules
func Preprocess(b []byte) ([]byte, error) {
	src := strings.Split(string(b), " ")
	var sb strings.Builder

	for _, w := range src {
		w = strings.TrimSpace(w)
		w = strings.ToLower(w)
		if v, prs := words[w]; prs {
			w = v
		}
		w += " "
		_, err := sb.WriteString(w)
		if err != nil {
			return []byte(sb.String()), err
		}
	}

	fmt.Println(sb.String())

	return []byte(sb.String()), nil
}
