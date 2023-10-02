echo '' >test_formatted.gsql
clear

if [[ $1 = 'g' ]]; then
    tree=yes npm run start >&tree.dot
    python3 get_tree.py

    dot -Tpng tree.dot >tree.png && open tree.png
elif [[ $1 = 't' ]]; then
   lisp=yes npm run start 
else
     npm run start
fi
