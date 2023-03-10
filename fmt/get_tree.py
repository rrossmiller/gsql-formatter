with open("tree.dot") as fin:
    f = fin.read()
f = f.split("_*_*_")

print(f[0])
with open("tree.dot", "w") as fout:
    fout.write(f[1])
