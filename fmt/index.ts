import fs from 'fs';
import Parser from 'tree-sitter';
import {Tree} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';
import {keywords} from './keywords';

const parser = new Parser();
parser.setLanguage(gsql);

let sourceCode = fs.readFileSync('../example.gsql', 'utf8');

// capitalize keywords for parser
let srcCodeCaps = '';
let isComment = false;
sourceCode.split('\n').forEach((l) => {
    // separate comments to be able to find keywords before // with no space
    if (l.includes('//')) {
        l = l.replace('//', ' //');
    }

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
                    }
                }
                return w;
            })
            .join(' ') + '\n';

    isComment = false;
});

console.log(srcCodeCaps);

/* traverse -->
    use the visitor pattern https://craftinginterpreters.com/representing-code.html#the-visitor-pattern
    https://www.typescriptlang.org/docs/handbook/2/classes.html#implements-clauses

    I don't think an interface will work becaue it wouldn't make sense to get the node, instantiate
    an object of the node's class, then run visit. 
    might make more sense just to have a switch statement for all the node types
*/
const tree: Tree = parser.parse(srcCodeCaps);
console.log(tree.rootNode.child(1).children);

// function traverse_tree(tree: Tree) {
//     const cursor = tree.walk();
//     let reachedRoot = false;
//     let currentNode: SyntaxNode;

//     while (!reachedRoot) {
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
