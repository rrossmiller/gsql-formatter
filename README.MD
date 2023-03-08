# GSQL formatter

```
// This does not look nice, but it's valid gsql
creaTe
 or Replace quERy myQuery(int i  , string j,Datetime d)

For graph MyGraph {
    // typedef tuple <int i,string j  , datetime d, list l> myType;
    mapaccum<INT,         String> @acc;
Src = {V.*};

    // here's a comment in the query body
    Tgt = selecT t FROM Src:s -(_>)-V:v -(E>:e)- T:t
    WHERE t.attr1 == s.attr1
                        ACCUM t.@acc += (0 -> "acc");

print Tgt;
}

```

Is formatted to (still WIP)

```
// This does not look nice, but it's valid gsql
CREATE OR REPLACE QUERY myQuery(INT i, STRING j, DATETIME d) FOR GRAPH MyGraph {
    // typedef tuple <int i,string j  , datetime d, list l> myType;
    MapAccum<INT,         STRING> @acc;
Src = {V.*};

    // here's a comment in the query body
    Tgt = SELECT t FROM Src:s -(_>)-V:v -(E>:e)- T:t
    WHERE t.attr1 == s.attr1
                        ACCUM t.@acc += (0 -> "acc");

PRINT Tgt;
}
```
