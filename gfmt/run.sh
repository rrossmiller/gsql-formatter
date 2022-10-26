#! /bin/zsh
pkg="gfmt"
clear
rm $pkg/*.class
javac $pkg/*.java && java $pkg.GFmt $@
