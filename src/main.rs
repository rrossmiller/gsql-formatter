use process::Processor;
use std::fs;
use std::io::Write;
use tree_sitter::Tree;
use tree_sitter_gsql;

use crate::node_handlers::create_query::fmt_create_query;
use crate::node_handlers::query_body;
use crate::utils::get_text;
mod keywords;
mod node_handlers;
mod pprint_tree;
mod process;
mod utils;

fn main() {
    // load the query
    let query = fs::read_to_string("test-data/simple.gsql").unwrap();
    // let query = fs::read_to_string("test-data/complex.gsql").unwrap();

    // fix any caps errors so the case-sensitive parser works
    let mut processor = Processor::new(&query, true);
    let query = match processor.process() {
        Ok(v) => v,
        Err(e) => {
            eprintln!("Error: {:#?}", e);
            std::process::exit(1)
        }
    };

    let mut file = fs::File::create("fmt1.gsql").unwrap();
    write!(file, "{}", query).unwrap();

    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(tree_sitter_gsql::language())
        .expect("Error loading gsql grammar");

    // parse the query
    let tree = parser
        .parse(&query, None)
        .expect("There was an error parsing the query");

    // format the query
    pprint_tree::pprint_tree(&tree, true);
    let query = fmt(tree, query);

    // post process to make accums ThisCase instead of all caps
    let mut processor = Processor::new(&query, false);
    let query = match processor.process() {
        Ok(v) => v,
        Err(e) => {
            eprintln!("Error: {:#?}", e);
            std::process::exit(1)
        }
    };

    // write fully-formated query
    let mut file = fs::File::create("fmt2.gsql").unwrap();
    write!(file, "{}", query).unwrap();
}

fn fmt(ast: Tree, src: String) -> String {
    let mut cursor = ast.walk();
    debug_assert_eq!(cursor.node().kind(), "gsql");

    // go to the query
    cursor.goto_first_child();
    let mut query = String::new();
    loop {
        match cursor.node().kind() {
            "create_query" => {
                cursor.goto_first_child();
                query.push_str(&fmt_create_query(&src, &mut cursor));
            }
            "query_body" => {
                query.push_str(&query_body::fmt_query_body(&src, &mut cursor));
            }
            _ => {
                // default
                query.push_str(&get_text(&src, cursor.node()))
            }
        };

        if !cursor.goto_next_sibling() {
            break;
        }
    }

    query
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
