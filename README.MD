# GSQL formatter
```
create quERy queryName() FOR GRAPH mygraph {
   h = select x fRom hello:h
   post-aCcum 
   FOREACH x in @@a.size() DO
        CASE WHEN (f.subject == x) THEN
            f.@post_likes += 1
            END
        END
   ;

   PRINt h[h.attr as attr];

}
```

parses to the tree below... Next traverse the tree and format the query
![](ex/tree.png)