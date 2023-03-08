import {SyntaxNode, TreeCursor} from 'tree-sitter';

export function handleParameterList(children: SyntaxNode[]) {
    let rtn = children[0].text.trim(); // start with open paren
    // query params
    children[1].children.forEach((c: SyntaxNode, i) => {
        if (c.type === 'query_param') {
            rtn += c.text.trim();
        } else {
            rtn += c.text + ' ';
        }
    });

    rtn += children[children.length - 1].text.trim() + ' ';

    return rtn;
}

export function handleCreateQuery(cursor: TreeCursor) {
    console.log('********');

    let rtn = '';
    do {
        const c: SyntaxNode = cursor.currentNode;
        if (cursor.currentFieldName === 'queryName') {
            rtn += c.text.trim();
        } else if (c.type === 'parameter_list') {
            rtn += handleParameterList(c.children);
            console.log(c.children);
        } else {
            rtn += c.text.trim() + ' ';
        }
    } while (cursor.gotoNextSibling());

    console.log();
    console.log(rtn);
    console.log('********');

    return rtn;
}
