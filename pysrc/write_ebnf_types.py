# if __name__ == '__main__':
#     ruleNames:list[str] = []
#     with open('../gsql.ebnf') as fin:
#         lines = fin.readlines()
    
#     # get the rule names
#     for i,l in enumerate(lines):
#         if ':=' in l:
#             name = l.split(':=')
#             ruleNames.append(name[0].strip())
    

#     out = '''package types

# import "github.com/alecthomas/participle/v2/lexer"

# // root structure
# '''
#     # write the rule names
#     for n in ruleNames:
#         n = n[0].upper() + n[1:]
#         out += f'type  {n} struct ' + '{\n\n}\n\n'

#     with open('types.go','w') as fout:
#         fout.writelines(out)


v = '''gAccumAccumStmt      // Assignment
funcCallStmt         // Function Call
selectStmt           // Select
queryBodyCaseStmt    // Control Flow
queryBodyIfStmt      // Control Flow
queryBodyWhileStmt   // Control Flow
queryBodyForEachStmt // Control Flow
BREAK                // Control Flow
CONTINUE             // Control Flow
updateStmt           // Data Modification
insertStmt           // Data Modification
queryBodyDeleteStmt  // Data Modification
printStmt            // Output
printlnStmt          // Output
logStmt              // Output
returnStmt           // Output
raiseStmt            // Exception
tryStmt              // Exception'''

for l in v.split('\n'):
    l = l[0].upper() + l[1:]

    print(l)