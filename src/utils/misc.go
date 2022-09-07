package utils

import (
	"fmt"
	"strconv"
	"strings"
	"unicode/utf8"
)

func Check(err error, v string) {
	if err != nil {
		if v != "" {
			s := strings.Split(err.Error(), ":")[1]
			i, _ := strconv.Atoi(s)

			if i+5 < utf8.RuneCountInString(v) {
				fmt.Printf("\nxxxxxx %v\n", v[:i+2])
			} else {
				fmt.Printf("\nxxxxxx %v\n", v[:i])
			}
		}
		panic(err)
	}
}
