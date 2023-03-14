cd ..
file=$(pwd)/example.gsql
treesitterpth=''
if [[ $USER == 'rrossmil' ]]; then
    treesitterpth='/Users/rrossmil/Documents/personal/tree-sitter-gsql'
else
    treesitterpth='../../tree-sitter-gsql'
fi

clear

# build the case_insensitive grammar for testing
cd $treesitterpth
./node_modules/.bin/tree-sitter generate

# check the build status
if [[ $? -ne 0 ]]; then
    exit 1
fi

# testing only parse the file
if [ $# -gt 0 ] && [ $1 == 't' ]; then
    ./node_modules/.bin/tree-sitter parse $file

    if [[ $? -eq 0 ]]; then
        echo 'OK'
    fi

    # testing parse the file and install the lib no matter what
elif [[ $# -gt 0 ]]; then
    ./node_modules/.bin/tree-sitter parse $file
    # cd ../ex/ &&
    cd ../gsql-formatter/fmt/ &&
        npm uninstall tree-sitter-gsql &&
        npm i $treesitterpth

else
    cp grammar.js grammar_case_insensitive.js
    # pase the file and check the status
    ./node_modules/.bin/tree-sitter parse $file &&
        # convert the grammar to a case-sensitive version to allow for sytax nodes to show up
        # this requires a keyword preprocessor in the formatter
        echo 'convert the grammar to a case-sensitive version' &&
        python3 case.py &&
        # regenerate the library with the case-sensitive grammar
        echo 'regenerate the library with the case-sensitive grammar' &&
        ./node_modules/.bin/tree-sitter generate &&
        # install the library
        echo 'install the library' &&
        cd ../gsql-formatter/fmt/ &&
        npm uninstall tree-sitter-gsql &&
        npm i $treesitterpth
fi
cd $treesitterpth
# reset the grammar to a case-insensitive one to make dev much easier
mv grammar_case_insensitive.js grammar.js
