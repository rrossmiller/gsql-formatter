import re

# pattern = re.compile('("[a-z]*")')

pattern = re.compile('caseInsensitive\("[a-z]*"\)')
word_pattern = re.compile(r'("[a-z]*")')


def process(line: str):
    rtn = ""  # output (string builder)

    # # get all the matches in the line
    # matches = pattern.finditer(line)
    # for i, m in enumerate(matches):
    #     # if it's the first match, add all of the text up to the start of this match to the output
    #     if i == 0:
    #         rtn += line[: m.start()]

    #     # handle current match
    #     # get only the double quoted word we're trying to match
    #     match = word_pattern.search(m.string[m.start() : m.end()])
    #     print(match.string[match.start() : match.end()].upper())
    #     rtn += match.string[match.start() : match.end()].upper()

    #     # get the string in between matches
    #     rtn += line[m.end() : matches[i + 1].start()]
    for p in line.split("caseInsensitive"):
        w_match = word_pattern.search(p)
        if w_match is not None:
            # print(p, "|", w_match.string[w_match.start() : w_match.end()])
            x = w_match.string[w_match.start() : w_match.end()].upper()
            # x = x.replace("(", "", 1)
            # x = x.replace(")", "", 1)
            p = x + w_match.string[w_match.end() + 1 :]
            # print(p)
            # if "_" in p:
            # print()
            # raise Exception
        rtn += p
    return rtn


with open("grammar_case_insensitive.js") as fin:
    lines = fin.read().splitlines()

out = []
for i, l in enumerate(lines):
    if "caseInsensitive" in l and "function caseInsensitive(" not in l:
        l = process(l)
    out.append(l + "\n")

with open("grammar.js", "w") as fout:
    fout.writelines(out)
