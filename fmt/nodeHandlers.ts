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
        let middleChildren: SyntaxNode[];
        if (children.length > 3) {
            middleChildren = children.slice(1, children.length - 1);
        } else {
            middleChildren = [children[1]];
        }

        middleChildren.forEach((node: SyntaxNode, i: number) => {
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

    handleQueryBodyStmt(children: SyntaxNode[]): string {
        let rtn = this.getIndent();
        children.forEach((c: SyntaxNode) => {
            switch (c.type) {
                case 'assign_stmt':
                    const res = this.handleAssignStmt(c.children);
                    rtn += res.slice(0, res.length - 1); // slice to remove space before semicolon
                    break;

                default:
                    rtn += c.text;
                    break;
            }
        });

        return rtn;
    }

    handleAssignStmt(children: SyntaxNode[]): string {
        let rtn = '';
        let child: SyntaxNode;
        // two different types of assign according to the grammar
        switch (children[1].type) {
            case '.':
                // name.name =
                rtn += children[0].text.trim() + children[1].text.trim() + children[2].text.trim() + ' ' + children[3].text.trim() + ' ';
                child = children[4];
                break;
            case '=':
                // name =
                rtn += children[0].text.trim() + ' ' + children[1].text.trim() + ' ';
                child = children[2];
                break;
        }

        // handle expression after =
        rtn += this.handleExpr(child.children);
        return rtn;
    }

    handleExpr(children: SyntaxNode[]): string {
        let rtn = '';
        children.forEach((c: SyntaxNode) => {
            switch (c.type) {
                case 'expr':
                    rtn += this.handleExpr(c.children);
                    break;

                case 'func_call_stmt':
                    rtn += this.handleFuncCall(c.children) + ' ';
                    break;

                default:
                    console.log(c.text, c.type);
                    if (c.type === '(') {
                        rtn += c.text.trim();
                    } else if (c.type === ')' && rtn[rtn.length - 1] === ' ') {
                        rtn = rtn.slice(0, rtn.length - 1);
                        rtn += c.text.trim() + ' ';
                    } else {
                        rtn += c.text.trim() + ' ';
                    }
                    break;
            }
        });

        return rtn;
    }

    handleFuncCall(children: SyntaxNode[]): string {
        let i = 0;
        let rtn = '';
        while (children[i].type !== '(') {
            rtn += children[i].text.trim();
            i++;
        }
        rtn += '(';
        // args
        children.slice(i).forEach((c: SyntaxNode) => {
            c.children.forEach((node) => {
                if (node.type === 'expr') {
                    rtn += this.handleExpr(node.children).trimEnd();
                } else if (node.type === ',') {
                    // comma space
                    rtn += node.text + ' ';
                } else {
                    rtn += node.text;
                }
            });
        });
        rtn += ')';
        return rtn;
    }

    getIndent(): string {
        return ' '.repeat(4 * this.indentLevel);
    }
}
