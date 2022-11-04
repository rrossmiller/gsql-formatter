#! /bin/zsh
clear
# pkg=grommet
# rm bin/$pkg/*.class
# echo 'compiling'
# javac -d bin src/$pkg/*.java \
# 	&& echo 'running\n' \
#     && java -cp bin $pkg.Grommet $@

#javac -d bin src/$pkg/*.java && java -cp bin $pkg.Grommet $@

# mvn clean
java -cp target/classes com.optum.grnd.grommet.Grommet $@
