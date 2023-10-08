use tree_sitter::Node;

use crate::utils::get_text;

pub fn fmt_create_query(node: Node, src: String) {
    let text = get_text(&src, node.start_position(), node.end_position());
    let mut cursor = node.walk();

    let x = node.child(0).unwrap();
    // println!("{:?}", x);
    for c in cursor.node().children(&mut cursor) {
        println!("{:?}", c);
        println!("{}", get_text(&src, c.start_position(), c.end_position()));
    }

    // println!("{}", text);
}
