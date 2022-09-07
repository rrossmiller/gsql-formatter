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

var (
	parser = participle.MustBuild[types.GsqlRoot]()
)

func main() {
	// dev := flag.Bool("dev", false, "run through lines one by one")
	railroad := flag.Bool("r", false, "Make railroad file")
	verbose := flag.Bool("v", false, "Verbose output")
	flag.Parse()
	// fmt.Printf("dev: %v\n", *dev)

	fmt.Print("running\n\n")

	q := utils.Q0
	fmt.Printf("q: %v\n", q)
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
