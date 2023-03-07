import fs from 'fs';
import Parser, {SyntaxNode} from 'tree-sitter';
import {Tree} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';
import {accumTypes, keywords} from './keywords';

const parser = new Parser();
parser.setLanguage(gsql);

let sourceCode = fs.readFileSync('../example.gsql', 'utf8');

// capitalize keywords for parser
let srcCodeCaps = '';
let isComment = false;
const whitespaceRegex = /^\s+$/;

const bracketHandler = (line: string, seq: string): string => {
    if (line.includes(seq)) {
        const idx = line.indexOf(seq);
        // if the comment doesn't start the line
        // and there isn't already a space before
        if (idx > 0 && line.charAt(idx - 1) !== ' ') {
            line = line.replace(seq, ` ${seq}`);
        }
    }
    return line;
};
function handleNamesByBrakets(line: string): string {
    // separate symbols to be able to find keywords before // with no space
    line = bracketHandler(line, '//');
    line = bracketHandler(line, '(');
    line = bracketHandler(line, ')');
    line = bracketHandler(line, '<');
    line = bracketHandler(line, '>');
    line = bracketHandler(line, '{');
    line = bracketHandler(line, '}');
    return line;
}

sourceCode.split('\n').forEach((l) => {
    // if the line is more than just whitespace
    if (!whitespaceRegex.test(l)) {
        l = handleNamesByBrakets(l);
        srcCodeCaps +=
            l
                .split(' ')
                .map((w: string) => {
                    if (w === '//') {
                        isComment = true;
                    }
                    // ignore capitalization rule in a comment
                    if (!isComment) {
                        const t = w.toUpperCase();
                        if (keywords.includes(t)) {
                            return t;
                        } else if (Object.keys(accumTypes).includes(t)) {
                            return accumTypes[t];
                        }
                    }
                    return w;
                })
                .join(' ') + '\n';
    }
    // if the line is just whitespace, remove it, but leave the line
    else {
        srcCodeCaps += '\n';
    }
    isComment = false;
});

fs.writeFileSync('testOut.gsql', srcCodeCaps);
/* traverse -->
    use the visitor pattern https://craftinginterpreters.com/representing-code.html#the-visitor-pattern
    https://www.typescriptlang.org/docs/handbook/2/classes.html#implements-clauses

    I don't think an interface will work becaue it wouldn't make sense to get the node, instantiate
    an object of the node's class, then run visit. 
    might make more sense just to have a switch statement for all the node types
*/
const tree: Tree = parser.parse(srcCodeCaps);
tree.rootNode.children.forEach((e) => {
    if (e.type === 'create_query') {
        console.log(e, '-->');
        console.log(e.children);
    }
});

// function traverse_tree(tree: Tree) {
//     const cursor = tree.walk();
//     let reachedRoot = false;
//     let currentNode: SyntaxNode;
//     while (!reachedRoot) {
//         console.log(cursor.currentFieldName);
//         currentNode = cursor.currentNode;
//         if (
//             // currentNode.childCount == 0 || !
//             !currentNode.isNamed
//         ) {
//             // console.log(cursor.currentNode);
//             console.log(currentNode.text, currentNode.type);
//             // console.log(currentNode.fie);
//         }

//         if (cursor.gotoFirstChild()) {
//             continue;
//         }
//         if (cursor.gotoNextSibling()) {
//             continue;
//         }

//         let retracing = true;
//         while (retracing) {
//             if (!cursor.gotoParent()) {
//                 retracing = false;
//                 reachedRoot = true;
//             }

//             if (cursor.gotoNextSibling()) {
//                 retracing = false;
//             }
//         }
//     }
// }

// traverse_tree(tree);
