// src https://github.com/alecthomas/participle/tree/v2.0.0-beta.5/cmd
package utils

import (
	"fmt"
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
				fmt.Printf("\nxxxxxx %v\n", v[:i+1])
			} else {
				fmt.Printf("\nxxxxxx %v\n", v[:i])
			}
		}
		panic(err)
	}
}

const (
	MultiHop        = "Friends2 = SELECT tgt FROM Users:s -(FRIENDSHIP:e)- _:u -(FRIENDSHIP:e2)- Friend:tgt;	"
	LinesOfCommands = `Users = {User.*};
			Users = {User};
			Users = SELECT s FROM Src; 
			Users = SELECT s FROM Src;
			Line2 = SELECT s FROM Src2-(DirEdge>:e)- VType:alias; 
			Users = SELECT s FROM Src:s;                          
			Users = SELECT s FROM Src:s -(Etype:e)-VType;         
			Users = SELECT s FROM Src:s -(DirEdge:e)-> VType:v;   
			Users = SELECT s FROM Src:s -(DirEdge>:e)- VType:alias;
			Users = SELECT s FROM Src:s -(<DirEdge:e)- VType:alias;
			i := 0;          
			i := "Here";    
			i := @@global;    
			i := a.@lclaccum; `
	Q0 = `
		Users = {User.*};
		Users = SELECT s FROM Users:s ;
		
		Friends1 = SELECT u FROM Users:s -(FRIENDSHIP:e)- Friend:u;

		Friends2 = SELECT tgt FROM Users:s -(FRIENDSHIP:e)- _:u -(FRIENDSHIP:e)- Friend:tgt;
	`

	Q2 = `
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
