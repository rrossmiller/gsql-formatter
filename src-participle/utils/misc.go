package utils

import (
	"fmt"
	"log"
	"strconv"
	"strings"
	"unicode/utf8"
)

func Check(err error, v string) {
	if err != nil {
		if v != "" {
			s := strings.Split(err.Error(), ":")
			r, _ := strconv.Atoi(s[0])
			i, _ := strconv.Atoi(s[1])
			v = strings.Split(v, "\n")[r-1]
			if i+1 < utf8.RuneCountInString(v) {
				// fmt.Printf("\nxxxxxx %v\n", v[:i+1])
				fmt.Println()
				log.Fatalf(" %v\n%v", v[:i+1], err)
			} else {
				// fmt.Printf("\nxxxxxx %v\n", v[:i])
				fmt.Println()
				log.Fatalf(" %v\n%v", v[:i-1], err)
			}
		}
		// panic(err)
	}
}

func PrintQuery(q string) {
	splits := strings.Split(q, "\n")
	spaces := "    "
	maxRow := len(splits) / 10
	for i, v := range splits {
		ispaces := spaces + strings.Repeat(" ", maxRow-(i/10))
		fmt.Printf("%d:%v%v\n", i, ispaces, v)
	}
}

const (
	MultiHop = "Friends2 = SELECT tgt FROM Users:s -(FRIENDSHIP:e)- _:u -(FRIENDSHIP:e2)- Friend:tgt;	"
	// LinesOfCommands = `CREATE DISTRIBUTED QUERY TwitchEgosData(INT current_partition=0, INT total_partitions=100) FOR GRAPH TwitchEgos SYNTAX V2{
	LinesOfCommands = `CREATE DISTRIBUTED QUERY TwitchEgosData(a) FOR GRAPH TwitchEgos SYNTAX V2 {
TYPEDEF TUPLE <INT from_id, INT to_id> Edges;
TYPEDEF TUPLE <INT id, STRING t> Vert;

Users = {User.*};
Users = {userSet};
Users = SELECT s FROM Src:s; 
Line2 = SELECT s FROM Src2-(DirEdge>:e)- VType:alias; 
Users = SELECT s FROM Src3:s -(Etype:e)-VType WHERE TRUE OR FALSE;         
Users = SELECT s FROM Src4:s -(DirEdge:e)-> VType:v;   
Users = SELECT s FROM Src5:s -(DirEdge>:e)- VType:alias;
Users = SELECT s FROM Src6:s -(<DirEdge:e)- VType:alias;
i := 0;          
i := "Here";    
i := @@global;    
i := a.@lclaccum;
end}`

	a = `
	Friends1 = SELECT u FROM Users:s -(FRIENDSHIP:e)- Friend:u;
	Friends2 = SELECT tgt FROM Users:s -(FRIENDSHIP:e)- _:u -(FRIENDSHIP:e2)- Friend:tgt;
	`

	Q0 = `
	Users = {User};
	Users = {User.*};
	Users = SELECT s FROM Users:s WHERE NOT a.@thing AND True;
	
	Friends1 = SELECT u FROM Users:s -(FRIENDSHIP:e)- Friend:u;
	Friends2 = SELECT tgt FROM Users:s -(FRIENDSHIP>:e)- _:u -(<FRIENDSHIP:e2)- Friend:tgt;
	`
	Q05 = `
		TYPEDEF TUPLE <INT from_id, INT to_id> Edges; // GNN train type
		TYPEDEF TUPLE <INT id, STRING t> Vert; // GNN train type

		// Accumulators for tracking edges and involved Vertices
		MaxAccum<INT> @graph_id, @id;
		MapAccum<INT, SetAccum<Edges>> @@edges;
		MapAccum<INT, SetAccum<Vert>> @@graph;

		Users = {User.*};
		Users = SELECT s FROM Users:s 
				WHERE vertex_to_int(s) % total_partitions == current_partition
				ACCUM s.@id += s.id,
				@@graph += (s.id -> Vert(s.id, s.type));

		// max 2-hop graph (this should be enough to encompas all subgraphs anyway)
		Friends1 = SELECT u FROM Users:s -(FRIENDSHIP:e)- Friend:u
				WHERE s.label >= 0
				ACCUM u.@id += u.id,
					@@edges += (s.id -> Edges(s.id, u.id)),
					@@graph += (s.id -> Vert(u.id, u.type));

		Friends2 = SELECT tgt FROM Users:s -(FRIENDSHIP:e)- _:u -(FRIENDSHIP:e)- Friend:tgt
				WHERE s.label >= 0 
				ACCUM tgt.@id += tgt.id,
					@@edges += (s.id -> Edges(u.id, tgt.id)),
					@@graph += (s.id -> Vert(tgt.id, tgt.type));

		Friends = Friends1 UNION Friends2;

		PRINT @@edges AS _edges; 
		PRINT @@graph AS _graph;
		PRINT Users;
		PRINT Friends;
	`
	Q1 = `
		CREATE QUERY TwitchEgosData(INT current_partition=0, INT total_partitions=100) FOR GRAPH TwitchEgos SYNTAX V2{
			TYPEDEF TUPLE <INT from_id, INT to_id> Edges; // GNN train type
			TYPEDEF TUPLE <INT id, STRING t> Vert; // GNN train type

			// Accumulators for tracking edges and involved Vertices
			MaxAccum<INT> @graph_id, @id;
			MapAccum<INT, SetAccum<Edges>> @@edges;
			MapAccum<INT, SetAccum<Vert>> @@graph;

			Users = {User.*};
			Users = SELECT s FROM Users:s 
					WHERE vertex_to_int(s) % total_partitions == current_partition
					ACCUM s.@id += s.id,
					@@graph += (s.id -> Vert(s.id, s.type));

			// max 2-hop graph (this should be enough to encompas all subgraphs anyway)
			Friends1 = SELECT u FROM Users:s -(FRIENDSHIP:e)- Friend:u
					WHERE s.label >= 0
					ACCUM u.@id += u.id,
						@@edges += (s.id -> Edges(s.id, u.id)),
						@@graph += (s.id -> Vert(u.id, u.type));

			Friends2 = SELECT tgt FROM Users:s -(FRIENDSHIP:e)- _:u -(FRIENDSHIP:e)- Friend:tgt
					WHERE s.label >= 0 
					ACCUM tgt.@id += tgt.id,
						@@edges += (s.id -> Edges(u.id, tgt.id)),
						@@graph += (s.id -> Vert(tgt.id, tgt.type));

			Friends = Friends1 UNION Friends2;

			PRINT @@edges AS _edges; 
			PRINT @@graph AS _graph;
			PRINT Users;
			PRINT Friends;
		}`
)
