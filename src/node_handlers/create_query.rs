use tree_sitter::TreeCursor;

use crate::utils::get_text;

pub fn fmt_create_query(src: &String, cursor: &mut TreeCursor) -> String {
    let mut rtn = String::new();

    loop {
        match cursor.node().kind() {
            "name" //| "ERROR" 
            => {
                // just add the text and move on
                rtn.push_str(&format!(" {}", &get_text(src, cursor.node())));
            }
             "ERROR" => {
                // just add the text and move on
                println!("ERROR",);
                rtn.push_str(&format!(" {}", &get_text(src, cursor.node())));
            }
            "parameter_list" => {
                cursor.goto_first_child();
                rtn.push_str(&fmt_parameter_list(&src, cursor));
            }
            _ => {
                // CREATE, OR, REPLACE, DISTRIBUTED, QUERY, FOR, GRAPH, SYNTAX, V2,
                rtn.push_str(&format!(
                    " {}",
                    &get_text(src, cursor.node()).trim().to_uppercase()
                ));
            }
        }

        if !cursor.goto_next_sibling() {
            break;
        }
    }

    cursor.goto_parent();
    rtn.push_str(" ");
    rtn
}

fn fmt_parameter_list(src: &String, cursor: &mut TreeCursor) -> String {
    let mut rtn = String::new();
    loop {
        match cursor.node().kind() {
            "query_param" => {
                rtn.push_str(&fmt_query_param(cursor, &src));
                // go one level up (create query level)
                cursor.goto_parent();
            }
            "query_params" => {
                // get into param definition level
                cursor.goto_first_child();
                rtn.push_str(&fmt_query_param(cursor, &src))
            }
            "(" | ")" => rtn.push_str(&get_text(src, cursor.node())),
            "," => rtn.push_str(&format!("{} ", get_text(src, cursor.node()))),
            _ => {
                print!("{}..", cursor.node().kind());
                println!("{}", get_text(src, cursor.node()));
                break;
            }
        }
        if !cursor.goto_next_sibling() {
            cursor.goto_parent();
            break;
        }
    }

    rtn
}

fn fmt_query_param(cursor: &mut TreeCursor, src: &String) -> String {
    let mut rtn = String::new();
    loop {
        cursor.goto_first_child();
        match cursor.node().kind() {
            "base_type" => {
                rtn.push_str(&format!("{} ", get_text(src, cursor.node())).to_uppercase())
            }
            "name" => rtn.push_str(&format!("{}", get_text(src, cursor.node()))),
            _ => {
                rtn.push_str(&get_text(src, cursor.node()).trim());
            }
        }
        if !cursor.goto_next_sibling() {
            // go to query param level
            cursor.goto_parent();
            cursor.goto_parent();
            break;
        }
    }
    rtn.to_string()
}
