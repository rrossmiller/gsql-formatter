import fs from 'fs';
import Parser, {Tree} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';
import {handleCreateQuery} from './nodeHandlers';
import {preprocess} from './preprocess';

const parser = new Parser();
parser.setLanguage(gsql);

let sourceCode = fs.readFileSync('../example.gsql', 'utf8');

/* Capitalize keywords for parser */
let srcCodeCaps = preprocess(sourceCode);

// testing... intermediate output
fs.writeFileSync('test_Caps.gsql', srcCodeCaps);

/* parse, and format*/
function formatGSQL(tree: Tree): string {
    let rtn = '';

    tree.rootNode.children.forEach((node) => {
        // format parent node types: create_query or comment/error
        switch (node.type) {
            case 'create_query':
                const cursor = node.walk();
                if (cursor.gotoFirstChild()) {
                    rtn += handleCreateQuery(cursor) + '\n\n';
                }
                break;
            // case 'line_comment':
            //     rtn += handleComment(node.text);
            //     break;
            default:
                rtn += node.text.trim() + '\n';
                break;
        }
    });

    return rtn;
}

const tree: Tree = parser.parse(srcCodeCaps);
const query = formatGSQL(tree);

fs.writeFileSync('test_Formatted.gsql', query);
