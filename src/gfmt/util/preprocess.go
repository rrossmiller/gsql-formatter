package util

import (
	"fmt"
	"regexp"
	"strings"

	"github.com/google/uuid"
)

var spl = regexp.MustCompile(`\b`)
var doubleStr = regexp.MustCompile(`"([\s\S]*)"`)
var singleStr = regexp.MustCompile(`'.*'`)

// preprocess the words in the query to abide by the caps rules
func Preprocess(b []byte) ([]byte, error) {
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

func GetStrings(b []byte) ([]byte, map[string][]byte, error) {
	stringStore := map[string][]byte{}
	f := doubleStr.FindAllSubmatchIndex(b, -1)
	for _, x := range f {
		match := b[x[0]:x[1]]
		key := uuid.New().String()
		//store the string
		stringStore[key] = b[x[2]:x[3]]
		// make a regex to replace to quoted text with uuid
		t := regexp.MustCompile(fmt.Sprint(string(match)))
		// replace string contents with UUID key
		b = t.ReplaceAll(b, []byte(fmt.Sprintf("%q", key)))
	}

	return b, stringStore, nil
}
