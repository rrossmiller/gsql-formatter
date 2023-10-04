use std::fs;

use tree_sitter::Point;
use tree_sitter_gsql;
mod pprint_tree;
fn main() {
    // let code = "CREATE QUERY myQuery() FOR GRAPH MyGraph {}";
    let code = fs::read_to_string("test-data/complex.gsql").unwrap();
    let code_rows: Vec<String> = code.lines().map(|x| x.to_string()).collect();
    let mut parser = tree_sitter::Parser::new();
    parser
        .set_language(tree_sitter_gsql::language())
        .expect("Error loading gsql grammar");
    let tree = parser.parse(code, None).unwrap();

    // println!("{}",tree.root_node().to_sexp());
    println!("****");
    pprint_tree::pprint_tree(&tree, true);

    let mut cursor = tree.walk();
    while cursor.goto_first_child() || cursor.goto_next_sibling() {
        println!("{:?}: {}", cursor.node(), cursor.node().kind());
        let sp = cursor.node().start_position();
        let ep = cursor.node().end_position();
        let txt = get_text(&code_rows, sp, ep);
        println!("{:?}", txt);
        println!("");

        // cursor.goto_first_child();
    }
}

fn get_text(code_rows: &Vec<String>, start_point: Point, end_point: Point) -> String {
    if start_point.row == end_point.row {
        let txt = &code_rows[start_point.row][start_point.column..end_point.column];
        return txt.to_string();
    }
    let mut txt = "".to_string();
    for r in start_point.row..end_point.row {
        if r == end_point.row {
            txt.push_str(&code_rows[r][0..end_point.column]);
        } else if r == start_point.row {
            txt.push_str(&code_rows[r][start_point.column..code_rows[r].len()]);
        } else {
            txt.push_str(&code_rows[r][0..code_rows[r].len()]);
        }
    }
    txt
}
