use tree_sitter::Node;

pub fn get_text(code: &String, node: Node) -> String {
    let start_point = node.start_position();
    let end_point = node.end_position();
    let code_rows: Vec<String> = code.lines().map(|x| x.to_string()).collect();
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
