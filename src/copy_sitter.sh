rm sitterLang/parser.*
# cp $HOME/Documents/Projects/tree-sitter-gsql/src/parser.c sitterLang/
cp $HOME/Documents/Projects/tree-sitter-gsql/src/parser.c t.c
cp $HOME/Documents/Projects/tree-sitter-gsql/src/tree_sitter/parser.h sitterLang/
#
echo '#include "parser.h"' > sitterLang/parser.c
tail -n +2 t.c >> sitterLang/parser.c
rm t.c

# for newer tree sitter version
# rm -rf sitterLang/parser.h sitterLang/parser.c
# cp -R $HOME/Documents/Projects/tree-sitter-gsql/src/ sitterLang/
# mv sitterLang/parser.h sitterLang/
# rm sitterLang/*.json
