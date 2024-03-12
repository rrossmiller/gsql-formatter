# gsql-formatter
🚧 Under development. 
To run: `./run.sh <path/to/query.gsql>`
To run in dev mode: `./run.sh -dev <path/to/query.gsql>`

Format gsql queries so that you can spend more time writing and less time formatting your code for readability.


Sample results:
```sql
creAte 
or replace distRibuted QUERY TwitchEgosData( inT  
current_partition =   0 , INT total_partitions=100, set <string >   myList) FOR GRAPH   TwitchEgos SYNTAX V2{
    /*
 block comment line 1
	 block comment line 2
	*/

       //line comment
typedef   TUPlE<VeRTeX indv      , InT age, string name, float x , datetime day, uint 

u>indv_age     ;
typedef   TUPlE<VeRTeX indv      , InT age, string name, float x , datetime day, uint u> type2    ;
    InT x 
    = 90         
    ;
                            FlOAT x = 90.0
         , y, z =                     1.0   ;
sumaccum<
int     > 
@a   ;
   mapAccum
   <InT
   , STRING> @acc   ;

    HeapAccum <
    T  > ( 150,
    attr1 aSC ,    attr2 DeSC) @@ac1            ;

   int i 
;

Users = {User.*};

}
```

Is formatted to...
```sql
CREATE OR REPLACE DISTRIBUTED QUERY TwitchEgosData(INT current_partition = 0, INT total_partitions = 100, SET<STRING> myList) FOR GRAPH TwitchEgos SYNTAX V2{
    /*
        block comment line 1
        block comment line 2
    */

    //line comment
    TYPEDEF TUPLE <VERTEX indv, INT age, STRING name, FLOAT x, DATETIME day, UINT <_-_-_> u> indv_age; 
    TYPEDEF TUPLE <VERTEX indv, INT age, STRING name, FLOAT x, DATETIME day, UINT u> type2; 

    INT x = 90;
    FLOAT x = 90.0, y, z = 1.0;
    SumAccum<INT> @a;
    MapAccum<INT , STRING > @acc;

    HeapAccum<T>(150, attr1 ASC, attr2 DESC) @@ac1;

    INT i;

    Users = {User.*};
}
```
