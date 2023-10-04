use std::fs;
use std::io::Write;
use tree_sitter::Tree;

pub fn pprint_tree(tree: &Tree, write_to_file: bool) {
    let lb = '(';
    let rb = ')';
    let tab = " ".repeat(2);
    let mut formatted_clips = String::new();
    let mut tab_count = 0;
    let mut is_field = false;

    let sexp = tree.root_node().to_sexp();

    for c in sexp.chars() {
        if c == lb && !is_field {
            formatted_clips.push('\n');
            formatted_clips.push_str(&tab.repeat(tab_count));
            tab_count += 1;
        } else if c == rb {
            if !is_field {
                tab_count -= 1;
            } else {
                is_field = false;
            }
        } else if c.to_string() == ":" {
            //backtrack -- replace last space with new line and tabs
            let mut j = formatted_clips.len() - 1;
            let mut tmp = formatted_clips.chars().nth(j).unwrap();
            while tmp != ' ' {
                j -= 1;
                tmp = formatted_clips.chars().nth(j).unwrap();
            }
            let f = &formatted_clips[..j];
            let b = &formatted_clips[j + 1..];

            let spaces = format!("\n{}", &tab.repeat(tab_count));
            formatted_clips = format!("{}{}{}", f, spaces, b);
            is_field = true;
        }
        formatted_clips.push(c);
    }

    if formatted_clips
        .chars()
        .next()
        .expect("There is no text to format")
        == '\n'
    {
        formatted_clips = formatted_clips[1..].to_string();
    }

    if write_to_file {
        let mut file = fs::File::create("tree.txt").unwrap();
        write!(file, "{}", formatted_clips).unwrap();
    } else {
        println!("{}", formatted_clips);
    }
}
