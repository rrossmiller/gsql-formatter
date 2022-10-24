package main

import (
	"flag"
	"fmt"
	"gourmet/types"
	"gourmet/utils"
	"os"

	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/repr"
)

var parser = participle.MustBuild[types.GsqlRoot]()

// var (
// 	sqlLexer = lexer.MustSimple([]lexer.SimpleRule{
// 		{Name: `Keyword`, Pattern: `(?i)\b(ACCUM|AND|ANY|API|AS|ASC|AVG|BAG|BATCH|BETWEEN|BOOL|BOTH|BREAK|CASE|CATCH|COALESCE|COMPRESS|CONTINUE|COUNT|CREATE|DATETIME|DATETIME_ADD|DATETIME_SUB|DELETE|DESC|DISTRIBUTED|DO|DOUBLE|EDGE|ELSE|END|ESCAPE|EXCEPTION|FALSE|FILTER|FLOAD|FOR|FOREACH|FROM|GRAPH|HAVING|IF|IN|INT|INTERPRET|INTERSECT|INTERVAL|INTO|IS|ISEMPTY|JSONARRAY|JSONOBJECT|LEADING|LIKE|LIMIT|LOADACCUM|MAX|MIN|MINUS|NOT|NULL|OFFSET|OR|ORDER|PINNED|POST_ACCUM|PRIMARY_ID|PRINT|QUERY|RAISE|RANGE|RETURN|RETURNS|RUN|SAMPLE|SELECT|SELECTVERTEX|SET|STATIC|STRING|SUM|SYNTAX|TARGET|TAGS|THEN|TO|TO_CSV|TRAILING|TRIM|TRUE|TRY|TUPLE|TYPEDEF|UINT|UNION|VALUES|VERTEX|WHEN|WHILE|WITH|GSQL_INT_MAX|GSQL_INT_MIN|GSQL_UINT_MAX|RESET_COLLECTION_ACCUM)\b`},
// 		{Name: `Ident`, Pattern: `[a-zA-Z_][a-zA-Z0-9_]*`},
// 		{Name: `Number`, Pattern: `[-+]?\d*\.?\d+([eE][-+]?\d+)?`},
// 		{Name: `String`, Pattern: `'[^']*'|"[^"]*"`},
// 		{Name: `Operators`, Pattern: `<>|!=|<=|>=||[-+*/%,.()=<>]`},
// 		{Name: "whitespace", Pattern: `\s+`},
// 	})
// 	parser = participle.MustBuild[types.GsqlRoot](
// 		participle.Lexer(sqlLexer),
// 		participle.Unquote("String"),
// 		participle.CaseInsensitive("Keyword"),
// 		// participle.Elide("Comment"),
// 		// Need to solve left recursion detection first, if possible.
// 		// participle.UseLookahead(),
// 	)
// )

func main() {
	// dev := flag.Bool("dev", false, "run through lines one by one")
	railroad := flag.Bool("r", false, "Make railroad file")
	verbose := flag.Bool("v", false, "Verbose output")
	flag.Parse()

	fmt.Print("running\n\n")
	q := utils.LinesOfCommands
	utils.PrintQuery(q)
	gsql, err := parser.ParseString("", q)
	utils.Check(err, q)

	if *verbose {
		fmt.Println("\n\nrepr:")
		repr.Println(gsql, repr.Indent("  "), repr.OmitEmpty(true))
	}
	rGSQL := repr.String(gsql, repr.Indent("  "), repr.OmitEmpty(true))
	WriteQuery(rGSQL, "out.cs")
	if *railroad {
		utils.Railroad(parser.String())
	}
}

func WriteQuery(query, fp string) {
	os.WriteFile(fp, []byte(query), 0666)
}

// Use below to run line by line
// stmts := [20]string{
// 	// "Users = {User.*};",
// 	// "Users = {User};",
// 	// "Users = SELECT s FROM Src;", // select
// 	`Users = SELECT s FROM Src;
// 	Line2 = SELECT s FROM Src2-(DirEdge>:e)- VType:alias;`, // Multiple select
// 	// "Users = SELECT s FROM Src:s;",                            // select
// 	// "Users = SELECT s FROM Src:s -(Etype:e)-VType;",           // select
// 	// "Users = SELECT s FROM Src:s -(DirEdge:e)-> VType:v;",     // select
// 	// "Users = SELECT s FROM Src:s -(DirEdge>:e)- VType:alias;", // select v2
// 	// "Users = SELECT s FROM Src:s -(<DirEdge:e)- VType:alias;", // select v2
// 	// "i := 0;",           // Assignment
// 	// "i := \"here\";",    // Assignment
// 	// "i := @@global;",    // Assignment
// 	// "i := a.@lclaccum;", // Assignment
// }

// for _, v := range stmts {
// 	if v == "" {
// 		continue
// 	}
// 	fmt.Println("***")
// 	gsql, err := parser.ParseString("", v)
// 	fmt.Printf("%v\n", v)
// 	utils.Check(err, v)
// 	fmt.Println("\n\nrepr:")
// 	repr.Println(gsql, repr.Indent("  "), repr.OmitEmpty(true))
// 	if *dev {
// 		reader := bufio.NewReader(os.Stdin)
// 		fmt.Print("Enter to proceed: ")
// 		// text, _ := reader.ReadString('\n')
// 		// fmt.Println(text)
// 		reader.ReadString('\n')
// 	}
// }
