import fs from 'fs';
import Parser from 'tree-sitter';
import {Tree} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';

const parser = new Parser();
parser.setLanguage(gsql);

const sourceCode = fs.readFileSync('example-file.gsql', 'utf8');
const tree: Tree = parser.parse(sourceCode);
tree.printDotGraph();

fs.writeFileSync('result.json', JSON.stringify(tree));
