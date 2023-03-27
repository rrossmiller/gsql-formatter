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
        // console.log(rtn);
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
        let eol_comment = false;
        let rtn = children[0].text.trim() + '\n'; // start with open brackets
        this.indentLevel++;
        let middleChildren: SyntaxNode[];
        if (children.length > 3) {
            middleChildren = children.slice(1, children.length - 1);
        } else if (children[1].type === '}') {
            //closing brackets
            rtn += children[1].text.trim();
            return rtn;
        } else {
            middleChildren = [children[1]];
        }

        middleChildren.forEach((node: SyntaxNode, idx: number) => {
            switch (node.type) {
                case 'typedef':
                    rtn += this.handleTypeDef(node.children) + '\n';
                    break;

                case 'query_body_stmts':
                    node.children.forEach((child) => {
                        if (child.type === ';') {
                            // handle comments on the end of the line
                            const n = middleChildren[idx + 1];

                            if (n !== undefined && n.type === 'line_comment') {
                                eol_comment = true;
                                rtn += '; ';
                            } else {
                                rtn += ';\n';
                            }
                        } else {
                            rtn += this.handleQueryBodyStmt(child.children);
                        }
                    });
                    break;
                case 'line_comment':
                    if (eol_comment) {
                        rtn += node.text.trim() + '\n';
                        eol_comment = false;
                    } else {
                        rtn += this.getIndent() + node.text.trim() + '\n';
                    }
                    break;
                case 'newline':
                    rtn += '\n';
                    break;
                default:
                    console.log('**DEFAULT QBS***', node);

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
        children.forEach((c: SyntaxNode, idx) => {
            let res = '';
            switch (c.type) {
                case 'assign_stmt':
                    res = this.handleAssignStmt(c.children);
                    rtn += res.trimEnd(); // slice to remove space before semicolon
                    break;
                case 'v_set_var_decl_stmt':
                    rtn += this.handleVSetVarDeclaration(c.children);
                    break;
                case 'decl_stmt':
                    rtn += this.handleDeclStmt(c.children);
                    break;
                case 'l_accum_assign_stmt':
                    rtn += c.children[0].text.trim() + c.children[1].text.trim();
                    rtn += this.handleAccumAssign(c.children.slice(2));
                    break;
                case 'g_accum_assign_stmt':
                    rtn += this.handleAccumAssign(c.children);
                    break;
                case 'func_call_stmt':
                    rtn += this.handleFuncCall(c.children);
                    break;
                case 'gsql_select_block':
                    rtn += this.handleSelectStmt(c.children);
                    break;
                default:
                    console.log('DEFAULT --', c.type, c.text);
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

    handleDeclStmt(children: SyntaxNode[]): string {
        let rtn = '';
        children.forEach((c: SyntaxNode) => {
            switch (c.type) {
                case 'base_decl_stmt':
                    //                  base name             =
                    rtn += c.children[0].text.trim() + ' ' + c.children[1].text.trim() + ' ';
                    c.children.slice(2).forEach((node) => {
                        if (node.type === ',') {
                            rtn = rtn.trimEnd() + node.text.trim() + ' ';
                        } else if (node.type === '=') {
                            rtn += node.text.trim() + ' ';
                        } else if (node.type === 'expr') {
                            rtn += this.handleExpr(node.children);
                        } else {
                            rtn += node.text.trim() + ' ';
                        }
                    });
                    break;
                case 'accum_decl_stmt':
                    // console.log(c.children);
                    console.log();
                    console.log();

                    // accum type
                    rtn += this.handleAccumType(c.children);
                    // rtn += c.text.trim();
                    break;
                default:
                    console.log(c);
                    rtn += c.text.trim();
                    break;
            }
        });

        return rtn.trimEnd();
    }

    handleAccumAssign(children: SyntaxNode[]): string {
        let rtn = children[0].text.trim() + ' ' + children[1].text.trim() + ' ';

        rtn += this.handleExpr(children[2].children).trimEnd();
        return rtn;
    }

    handleAccumType(children: SyntaxNode[]): string {
        let rtn = '';
        let i = 0;
        if (children[0].childCount > 0) {
            i = 1;

            // accum type
            children[0].children.forEach((c, i) => {
                if (c.type === 'accum_type') {
                    console.log('*', c, c.children);
                    rtn += this.handleAccumType(c.children) + ' ';
                } else if (c.type === ',' || c.type === '>' || c.type === ')') {
                    rtn += c.text.trim() + ' ';
                } else if (c.type === 'ASC' || c.type === 'DESC') {
                    rtn += ' ' + c.text.trim();
                } else if (c.type === 'base_type' && children[0].child(i + 1).type === 'name') {
                    rtn += c.text + ' ';
                } else {
                    rtn += c.text.trim();
                }
            });
            if (!rtn.endsWith(' ')) {
                rtn += ' ';
            }
        }
        // name, optional = and optional repeated names
        children.slice(i).forEach((c: SyntaxNode) => {
            console.log('-----', c);
            if (c.type === ',') {
                rtn += ', ';
            } else if (c.type === '=') {
                rtn += ' = ';
            } else {
                // problem with avg accum
                rtn += c.text.trim();
            }
        });

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
                case 'set_bag_expr':
                    rtn += this.handleSetBagExpr(c.children);
                    break;
                default:
                    if (c.type === '(') {
                        rtn = rtn.trimEnd() + c.text.trim();
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
                    rtn += node.text.trim() + ' ';
                } else {
                    rtn += node.text.trim();
                }
            });
        });
        rtn += ')';
        return rtn;
    }

    handleSetBagExpr(children: SyntaxNode[]): string {
        let rtn = '';

        // if it's simple, return the trimmed text
        if (children.length == 1) {
            return children[0].text.trim();
        }
        // otherwise, find the case
        children.forEach((c: SyntaxNode) => {
            switch (c.type) {
                case 'set_bag_expr':
                    rtn += this.handleSetBagExpr(c.children);
                    break;
                case 'arg_list':
                    // args
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

                    break;
                case 'name_dot':

                default:
                    rtn += c.text.trim();
                    break;
            }
        });

        return rtn;
    }

    handleVSetVarDeclaration(children: SyntaxNode[]): string {
        // start with "name = "
        let rtn = children[0].text.trim() + ' ' + children[1].text.trim() + ' ';

        children.slice(2).forEach((c: SyntaxNode) => {
            switch (c.type) {
                case 'simple_set':
                    if (c.children[0].type === 'simple_set') {
                        rtn += c.text;
                        break;
                    }

                case 'seed_set':
                    // open brackets
                    rtn += c.children[0].text.trim();
                    c.children.slice(1, c.children.length - 1).forEach((x) => {
                        if (x.type === ',') {
                            rtn += x.text.trim() + ' ';
                        } else {
                            rtn += x.text.trim();
                        }
                    });
                    // close brackets
                    rtn += c.children[c.children.length - 1].text.trim();
                    break;
                case 'gsql_select_block':
                    rtn += this.handleSelectStmt(c.children);
                    break;
                default:
                    rtn += c.text.trim();
                    break;
            }
            // if (c.children.length > 0) {
            //     c.children.forEach((x) => {
            //         rtn += x.text.trim();
            //     });
            // } else {
            // }
        });

        return rtn;
    }

    handleSelectStmt(children: SyntaxNode[]): string {
        const select = children[0].children;
        //           name                           =                             SELECT                     name
        let rtn = select[0].text.trim() + ' ' + select[1].text.trim() + ' ' + select[2].text.trim() + ' ' + select[3].text.trim() + ' ';

        const from = children[1].children;
        //           FROM
        rtn += from[0].text.trim() + ' ';
        switch (from[1].type) {
            case 'path_pattern':
                console.log('path pattern');
                console.log(from[1].children);
                break;
            case 'step':
                console.log('step');
                console.log(from[1].children);
                const step = from[1];
                const stepSrc = step.children[0].children;
                stepSrc.forEach((c) => {
                    rtn += c.text.trim();
                });

                if (step.childCount > 1) {
                    // open edge arrow
                    const openEdgeArrow = step.children
                        .slice(1, 3)
                        .map((x) => {
                            return x.text.trim();
                        })
                        .join('');
                    // step_edge_set

                    const stepEdgeSet = step.child(3); // todo something to the children

                    // close edge arrow
                    const closeEdgeArrow = step.children
                        .slice(4, step.childCount - 1)
                        .map((x) => {
                            return x.text.trim();
                        })
                        .join('');

                    // tgt
                    const tgt = step.lastChild; // todo something to the children

                    rtn += ' ' + openEdgeArrow + stepEdgeSet.text.trim() + closeEdgeArrow + ' ' + tgt.text.trim();
                }
                break;
            default:
                rtn += from[1].text.trim();
                break;
        }

        // children.slice(1).forEach((c: SyntaxNode) => {
        //     console.log('SELECT', c);
        //     console.log(c.children);
        //     console.log();

        //     rtn += c.text.trim() + ' ';
        // });

        return rtn;
    }

    getIndent(): string {
        return ' '.repeat(4 * this.indentLevel);
    }
}
