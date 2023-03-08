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

                case 'query_body_stmts':
                    node.children.forEach((child) => {
                        if (child.type === ';') {
                            rtn += ';\n';
                        } else {
                            rtn += this.handleQueryBodyStmt(child.children);
                        }
                    });
                    break;

                case 'line_comment':
                    rtn += this.getIndent() + node.text.trim() + '\n';
                    break;

                default:
                    console.log(node);

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

    handleQueryBodyStmt(children: SyntaxNode[]): string {
        let rtn = '';
        children.forEach((c: SyntaxNode) => {
            console.log(c);

            switch (c.type) {
                case 'assign_stmt':
                    rtn += this.handleAssignStmt(c.children);
                    break;

                default:
                    rtn += c.text;
                    break;
            }
        });

        return rtn;
    }

    handleAssignStmt(children: SyntaxNode[]): string {
        let rtn = this.getIndent();
        let child: SyntaxNode;
        // two different types of assign according to the grammar
        switch (children[1].type) {
            case '.':
                console.log('dot');
                // name.name =
                rtn += children[0].text.trim() + children[1].text.trim() + children[2].text.trim() + ' ' + children[3].text.trim() + ' ';
                child = children[4];
                break;
            case '=':
                console.log('eq');
                // name =
                rtn += children[0].text.trim() + ' ' + children[1].text.trim() + ' ';
                child = children[2];
                break;
        }

        // handle expression after =
        console.log('---'.repeat(this.indentLevel), child);
        rtn += child.text.trim();
        // todo handle child --> it is an expr

        return rtn;
    }
}
