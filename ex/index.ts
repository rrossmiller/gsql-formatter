import fs from 'fs';
import Parser from 'tree-sitter';
import {Tree} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';

const parser = new Parser();
parser.setLanguage(gsql);

let sourceCode = fs.readFileSync('../example.gsql', 'utf8');
// sourceCode = sourceCode.toLowerCase();
console.log(sourceCode);

const tree: Tree = parser.parse(sourceCode);
console.log('*********************************');
tree.printDotGraph();
console.log('*********************************');

// fs.writeFileSync('result.json', JSON.stringify(tree));
console.log(tree.rootNode.toString());
