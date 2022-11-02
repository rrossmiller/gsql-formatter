#! /bin/zsh
clear
# rm gbin/tool/*.class
# javac -d gbin src/main/java/com/optum/tool/*.java && java -cp gbin tool.GenerateAst src/$@

java -cp target/classes com.optum.ghs.tool.GenerateAst
