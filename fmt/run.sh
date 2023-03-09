echo '' >test_formatted.gsql
clear

if [[ $1 = 'g' ]]; then
    tree=yes npm run start >&tree.dot
    python3 get_tree.py

    dot -Tpng tree.dot >tree.png && open tree.png
else
    tree=no npm run start
fi
