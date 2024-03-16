package util 

import "strings"

func PostProcess(formattedQuery string, stringStore map[string][]byte) (string, error) {
	for k, v := range stringStore {
		formattedQuery = strings.ReplaceAll(formattedQuery, k, string(v))
	}
	return formattedQuery, nil
}
