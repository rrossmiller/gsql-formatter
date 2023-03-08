import {SyntaxNode, TreeCursor} from 'tree-sitter';

export class Formatter {
    indentLevel = 0;

    handleCreateQuery(cursor: TreeCursor) {
        console.log('********');

        let rtn = '';
        do {
            const c: SyntaxNode = cursor.currentNode;
            if (cursor.currentFieldName === 'queryName') {
                rtn += c.text.trim();
            } else if (c.type === 'parameter_list') {
                rtn += this.handleParameterList(c.children);
            } else if (c.type === 'query_body') {
                rtn += this.handleQueryBody(c.children);
            } else {
                rtn += c.text.trim() + ' ';
            }
        } while (cursor.gotoNextSibling());

        console.log();
        console.log(rtn);
        console.log('********');

        return rtn;
    }

    handleParameterList(children: SyntaxNode[]): string {
        let rtn = children[0].text.trim(); // start with open paren
        // query params
        children[1].children.forEach((c: SyntaxNode) => {
            if (c.type === 'query_param') {
                rtn += c.text.trim();
            } else {
                rtn += c.text + ' ';
            }
        });

        rtn += children[children.length - 1].text.trim() + ' ';

        return rtn;
    }

    handleQueryBody(children: SyntaxNode[]): string {
        let rtn = children[0].text.trim() + '\n'; // start with open brackets
        this.indentLevel++;
        children.slice(1, children.length - 2).forEach((node: SyntaxNode, i: number) => {
            switch (node.type) {
                case 'typedef':
                    rtn += this.handleTypeDef(node.children) + '\n';

                    // if the next node isn't a typedef, we've reached the end of the typedef section, add a new line
                    if (children[i + 2].type !== 'typedef') {
                        rtn += '\n';
                    }
                    break;

                default:
                    rtn += this.getIndent() + node.text.trim() + '\n';
                    break;
            }
        });

        //closing brackets
        rtn += children[children.length - 1].text.trim();
        return rtn;
    }

    handleTypeDef(children: SyntaxNode[]): string {
        // set indentation TODO make 4 a config variable
        let rtn = this.getIndent();
        // start with "TYPDEF TUPLE<"
        rtn += children[0].text.trim() + ' ' + children[1].text.trim() + children[2].text.trim();

        // handle tuple fields
        children[3].children.forEach((c: SyntaxNode, i: number) => {
            console.log(c);
            rtn += c.text.trim();
            if (c.type == ',') {
                rtn += ' ';
            }
        });

        // closing ">" and tuple name
        rtn += children[4].text.trim() + ' ' + children[5].text.trim() + children[6].text.trim();
        return rtn;
    }

    getIndent(): string {
        return ' '.repeat(4 * this.indentLevel);
    }
}
