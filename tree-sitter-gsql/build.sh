clear
./node_modules/.bin/tree-sitter generate
# tree-sitter generate && clear
tree-sitter parse example.gsql #&&
cd ../ex/ &&
	npm uninstall tree-sitter-gsql &&
	npm i ../tree-sitter-gsql
