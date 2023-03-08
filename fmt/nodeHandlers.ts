import {SyntaxNode} from 'tree-sitter';

export function handleParameterList(children: SyntaxNode[]) {
    console.log('**00');
    console.log(children.join(''));
    console.log('**00');

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

export function handleCreateQuery(children: SyntaxNode[]) {
    console.log('********');

    let rtn = '';
    children.forEach((c: SyntaxNode) => {
        console.log(c);
        if (c.type === 'parameter_list') {
            rtn += handleParameterList(c.children);
            console.log(c.children);
        } else if (c.type === 'name' && c.nextSibling.type === 'parameter_list') {
            rtn += c.text.trim();
        } else {
            rtn += c.text.trim() + ' ';
        }
    });

    console.log();
    console.log(rtn);
    console.log('********');

    return rtn;
}
