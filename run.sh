rm gourmet
clear
cd src
echo building
go build
echo running
echo
mv gourmet ..

echo "run this:
  ./gourmet -dev path/to/query.gsql"