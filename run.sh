rm pepper
clear
cd src
echo building
go build
echo running
echo
mv pepper ..
# cd ..
# ./pepper 
echo "run this:
  ./pepper -dev path/to/query.gsql"