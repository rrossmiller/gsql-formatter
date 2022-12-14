package reserved

import "strings"

const INDENTATION = "    " //fixme set in init and from .gourmetconfig
const HALF_INDENTATION = "  "

var SELECT_KEYWORDS = [7]string{"ACCUM", "POST-ACCUM", "FOR", "WHERE", "IF", "ELSE", "END"}

var KEYWORDS = [122]string{"ACCUM", "AND", "ANY", "API", "AS", "ASC", "AVG", "BAG", "BATCH", "BETWEEN", "BOOL", "BOTH", "BREAK", "BY", "CASE", "CATCH", "COALESCE", "COMPRESS", "CONTINUE", "COUNT", "CREATE", "DATETIME", "DATETIME_ADD", "DATETIME_SUB", "DELETE", "DESC", "DISTRIBUTED", "DO", "DOUBLE", "EDGE", "ELSE", "END", "ESCAPE", "EXCEPTION", "FALSE", "FILE", "FILTER", "FLOAT", "FOR", "FOREACH", "FROM", "GRAPH", "GROUP", "GSQL_INT_MAX", "GSQL_INT_MIN", "GSQL_UINT_MAX", "HAVING", "IF", "IN", "INSERT", "INT", "INTERPRET", "INTERSECT", "INTERVAL", "INTO", "IS", "ISEMPTY", "JSONARRAY", "JSONOBJECT", "LASTHOP", "LEADING", "LIKE", "LIMIT", "LIST", "LOAD_ACCUM", "LOG", "MAP", "MATCH", "MAX", "MIN", "MINUS", "NOT", "NOW", "NULL", "OFFSET", "OR", "ORDER", "PATH", "PER", "PINNED", "POST_ACCUM", "POST-ACCUM", "PRIMARY_ID", "PRINT", "QUERY", "RAISE", "RANGE", "REPLACE", "RESET_COLLECTION_ACCUM", "RETURN", "RETURNS", "RUN", "SAMPLE", "SELECT", "SELECT_VERTEX", "SET", "SRC", "STATIC", "STRING", "SUM", "SYNTAX", "TARGET", "TAGS", "THEN", "TO", "TO_CSV", "TO_DATETIME", "TRAILING", "TRIM", "TRUE", "TRY", "TUPLE", "TYPEDEF", "UINT", "UNION", "UPDATE", "VALUES", "VERTEX", "WHEN", "WHERE", "WHILE", "WITH"}

func ContainsSelectKeyword(line string) bool {
	line = strings.ToUpper(line)
	lSplit := strings.Split(line, " ")
	for _, word := range lSplit {

		for _, kw := range SELECT_KEYWORDS {
			if word == kw {
				return true
			}
		}
	}

	return false
}
