use tree_sitter::TreeCursor;

use crate::utils::get_text;

pub fn fmt_query_body(src: &String, cursor: &mut TreeCursor) -> String {
    let mut rtn = String::new();
    cursor.goto_first_child();

    //newlines are gone because it's just nodes now. Make sure you add newlines in the right spots
    loop {
        match cursor.node().kind() {
            "{" //| "ERROR"
            => {
                // just add the text and move on
                rtn.push_str(&format!("{}\n", &get_text(src, cursor.node())));

            }
             "ERROR" => {
                // just add the text and move on
                println!("ERROR {}",get_text(src, cursor.node()));
                let x =format!("{}\n", &get_text(src, cursor.node()));
                println!("{}",x);
                rtn.push_str(&x);
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
