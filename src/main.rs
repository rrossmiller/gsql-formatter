use std::fs;

use tree_sitter_gsql;
fn main() {
    // let code = "CREATE QUERY myQuery() FOR GRAPH MyGraph {}";
    let code = fs::read_to_string("test-data/complex.gsql").unwrap();
    let code_rows: Vec<char> = code.chars().collect();
    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(tree_sitter_gsql::language())
        .expect("Error loading gsql grammar");
    let tree = parser.parse(code, None).unwrap();


    let mut cursor = tree.walk();
    while cursor.goto_first_child() || cursor.goto_next_sibling() {
        println!("{:?}: {}", cursor.node(), cursor.node().kind());
        let sp = cursor.node().start_position();
        let ep = cursor.node().end_position();
        let txt: String = code_rows[sp.column..ep.column].iter().collect();
        println!("{:?}", txt);
        println!("");

        // cursor.goto_first_child();
    }
}
