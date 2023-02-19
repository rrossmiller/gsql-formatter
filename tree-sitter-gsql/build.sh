file="../example.gsql"
clear
./node_modules/.bin/tree-sitter generate
# tree-sitter generate && clear
if [ $# -gt 0 ] && [ $1 == 't' ]; then
	tree-sitter parse $file

elif [[ $# -gt 0 ]]; then
	tree-sitter parse $file
	cd ../ex/ &&
		npm uninstall tree-sitter-gsql &&
		npm i ../tree-sitter-gsql

else
	tree-sitter parse $file &&
		cd ../ex/ &&
		npm uninstall tree-sitter-gsql &&
		npm i ../tree-sitter-gsql

fi
