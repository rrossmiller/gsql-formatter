# gsql-formatter
🚧 Under development. 
To run: `./run.sh <path/to/query.gsql>`
To run in dev mode: `./run.sh -dev <path/to/query.gsql>`

Format gsql queries so that you can spend more time writing and less time formatting your code for readability.


Sample results:
```sql
    CREATE QUERY TwitchEgosData(INT current_partition=0, INT total_partitions=100) FOR GRAPH TwitchEgos SYNTAX V2{
        // This is a comment
Users = {User.*};
	Users = SELECT s FROM Users:s 
			             WHERE vertex_to_int(s) % total_partitions == current_partition
						 And testCondition
			  aND anotherOne
			  ACCUM s.@id += s.id,
              another.@accum += 0;
			
PRINT Users;
}
```

Is formatted to...
```sql
CREATE QUERY TwitchEgosData(INT current_partition=0, INT total_partitions=100) FOR GRAPH TwitchEgos SYNTAX V2{
    // This is a comment
    Users = {User.*};
    Users = SELECT s FROM Users:s 
            WHERE vertex_to_int(s) % total_partitions == current_partition
              AND testCondition
              AND anotherOne
            ACCUM s.@id += s.id,
              another.@accum += 0;

    PRINT Users;
}
```
