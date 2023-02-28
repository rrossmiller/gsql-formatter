file="../example.gsql"
clear
./node_modules/.bin/tree-sitter generate

if [[ $? -ne 0 ]]; then
	exit 1
fi
# tree-sitter generate && clear
if [ $# -gt 0 ] && [ $1 == 't' ]; then
	tree-sitter parse $file

	if [[ $? -eq 0 ]]; then
		echo 'OK'
	fi
elif [[ $# -gt 0 ]]; then
	tree-sitter parse $file
	# cd ../ex/ &&
	cd ../fmt/ &&
		npm uninstall tree-sitter-gsql &&
		npm i ../tree-sitter-gsql

else
	tree-sitter parse $file &&
		# cd ../ex/ &&
		cd ../fmt/ &&
		npm uninstall tree-sitter-gsql &&
		npm i ../tree-sitter-gsql

fi
