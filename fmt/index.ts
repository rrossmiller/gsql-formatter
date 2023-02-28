import fs from 'fs';
import Parser from 'tree-sitter';
import {Tree, SyntaxNode} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';
import {keywords} from './keywords';

const parser = new Parser();
parser.setLanguage(gsql);

let sourceCode = fs.readFileSync('../example.gsql', 'utf8');

// todo do this in traversal in order to ignore comments
// caps keywords
let srcCaps = '';
sourceCode.split('\n').forEach((l) => {
    srcCaps +=
        l
            .split(' ')
            .map((w: string) => {
                const t = w.toUpperCase();
                if (keywords.includes(t)) {
                    return t;
                }
                return w;
            })
            .join(' ') + '\n';
});

// console.log(srcCaps);
// //traverse
const tree: Tree = parser.parse(srcCaps);
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
