#! /bin/bash
rm gourmet
clear
cd src
echo building
go build
mv gourmet ..
cd ..
#echo running
# echo

./gourmet $@


FILE=gsql.html
if [[ -f "$FILE" ]]; then
    mv $FILE src/utils/assets
fi
