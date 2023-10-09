use preprocess::Processor;
use std::fs;
use std::io::Write;
use tree_sitter::Tree;
use tree_sitter_gsql;

use crate::node_handlers::create_query::fmt_create_query;
mod keywords;
mod node_handlers;
mod pprint_tree;
mod preprocess;
mod utils;

fn main() {
    // load the query
    let query = fs::read_to_string("test-data/simple.gsql").unwrap();
    // let query = fs::read_to_string("test-data/complex.gsql").unwrap();

    // fix any caps errors so the case-sensitive parser works
    let mut preprocessor = Processor::new(&query);
    let query = match preprocessor.preprocess() {
        Ok(v) => v,
        Err(e) => {
            eprintln!("Error: {:#?}", e);
            std::process::exit(1)
        }
    };

    println!("****");
    println!("");
    println!("{}", query);
    println!("");
    println!("");
    println!("****");
    let mut file = fs::File::create("fmt1.gsql").unwrap();
    write!(file, "{}", query).unwrap();

    // parse the query
    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(tree_sitter_gsql::language())
        .expect("Error loading gsql grammar");
    let tree = parser
        .parse(&query, None)
        .expect("There was an error parsing the query");

    // format the query
    start formatting
    let mut formatter = Formatter::new();
    pprint_tree::pprint_tree(&tree, true);
    formatter.fmt(tree, query);
    // t(query);
}

struct Formatter {
    // indent_level: i8,
}
impl Formatter {
    pub fn new() -> Formatter {
        Formatter {}
    }
    fn fmt(&mut self, ast: Tree, src: String) {
        let mut cursor = ast.walk();
        debug_assert_eq!(cursor.node().kind(), "gsql");
        cursor.goto_first_child();

        match cursor.node().kind() {
            "create_query" => fmt_create_query(cursor.node(), src),
            _ => println!("done"),
        }
    }
}

// fn t(code: &String) {
//     // let code = "CREATE QUERY myQuery() FOR GRAPH MyGraph {}";
//     // let code_rows: Vec<String> = code.lines().map(|x| x.to_string()).collect();
//     let mut parser = tree_sitter::Parser::new();
//     parser
//         .set_language(tree_sitter_gsql::language())
//         .expect("Error loading gsql grammar");
//     let tree = parser.parse(code, None).unwrap();
//
//     // println!("{}",tree.root_node().to_sexp());
//     println!("****");
//     pprint_tree::pprint_tree(&tree, true);
//
//     let mut cursor = tree.walk();
//     while cursor.goto_first_child() || cursor.goto_next_sibling() {
//         println!("{:?}: {}", cursor.node(), cursor.node().kind());
//         let sp = cursor.node().start_position();
//         let ep = cursor.node().end_position();
//         let txt = get_text(&code, sp, ep);
//         println!("{:?}", txt);
//         println!("");
//
//         // cursor.goto_first_child();
//     }
// }
