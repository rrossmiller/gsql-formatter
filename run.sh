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
#	echo "run this:
 # ./gourmet -dev path/to/query.gsql"
