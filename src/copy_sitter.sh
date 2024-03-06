cp $HOME/Documents/Projects/tree-sitter-gsql/src/parser.c sitterLang/
cp $HOME/Documents/Projects/tree-sitter-gsql/src/parser.c t.c
cp $HOME/Documents/Projects/tree-sitter-gsql/src/tree_sitter/parser.h sitterLang/

echo '#include "parser.h"' > sitterLang/parser.c
tail -n +2 t.c >> sitterLang/parser.c
rm t.c

