clear
cd src
rm pepper
echo building
go build
echo running
echo
mv pepper ..
cd ..
./pepper $1
