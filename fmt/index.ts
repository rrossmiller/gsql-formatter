import fs from 'fs';
import Parser, {Tree} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';
import {Formatter} from './nodeHandlers';
import {Postprocessor, Preprocessor} from './process';

const parser = new Parser();
parser.setLanguage(gsql);

let sourceCode = fs.readFileSync('../example.gsql', 'utf8');

/* Capitalize keywords for parser */
console.log('preprocessing');
const preprocessor = new Preprocessor(sourceCode);
let srcCodeCaps = preprocessor.scan();
console.log(preprocessor.numStatements, preprocessor.blankLines);

// testing... intermediate output
fs.writeFileSync('test_Caps.gsql', srcCodeCaps);

/* parse, and format*/
function formatGSQL(tree: Tree): string {
    let rtn = '';
    const formatter = new Formatter();

    tree.rootNode.children.forEach((node) => {
        // format parent node types: create_query or comment/error
        switch (node.type) {
            case 'create_query':
                const cursor = node.walk();
                if (cursor.gotoFirstChild()) {
                    rtn += formatter.handleCreateQuery(cursor);
                }
                break;
            default:
                rtn += node.text.trim() + '\n';
                break;
        }
    });
    if (rtn[rtn.length - 1] !== '\n') {
        rtn += '\n';
    }
    return rtn;
}

console.log('parsing');
const tree: Tree = parser.parse(srcCodeCaps);
console.log('formatting');
let query = formatGSQL(tree);

query = query.replaceAll('<_-_-_>', '');
const postprocessor = new Postprocessor(query);
query = postprocessor.scan();
fs.writeFileSync('test_Formatted.gsql', query);

if (process.env.tree === 'yes') {
    console.log('_-_-_');
    // console.log(tree.rootNode.toString());
    tree.printDotGraph();
}
