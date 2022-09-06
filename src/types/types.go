package types

// root structure
type CreateQuery struct {
}

type InterpretQuery struct {
}

type ParameterValueList struct {
}

type ParameterValue struct {
}

type ParameterConstant struct {
}

type ParameterList struct {
}

type SyntaxName Name

type QueryBody struct {
}

type Typedefs struct {
}

type DeclStmts struct {
}

type DeclStmt struct {
}

type DeclExceptStmts struct {
}

type Query struct {
	QueryBodyStmts []*QueryBodyStmt `@@*`
}

type QueryBodyStmt struct {
	// *AssignStmt `@@` // Assignment
	// // *VSetVarDeclStmt      `| @@` // Declaration
	// *DeclStmts            `| @@` // Declaration
	// *LAccumAssignStmt     `| @@` // Assignment
	// *GAccumAssignStmt     `| @@` // Assignment
	// *GAccumAccumStmt      `| @@` // Assignment
	// *FuncCallStmt         `| @@` // Function Call
	SelectStmt *SelectStmt `| @@` // Select
	// *QueryBodyCaseStmt    `| @@` // Control Flow
	// *QueryBodyIfStmt      `| @@` // Control Flow
	// *QueryBodyWhileStmt   `| @@` // Control Flow
	// *QueryBodyForEachStmt `| @@` // Control Flow
	// *UpdateStmt           `| @@` // Data Modification
	// *InsertStmt           `| @@` // Data Modification
	// *QueryBodyDeleteStmt  `| @@` // Data Modification
	// *PrintStmt            `| @@` // Output
	// *PrintlnStmt          `| @@` // Output
	// *LogStmt              `| @@` // Output
	// *ReturnStmt           `| @@` // Output
	// *RaiseStmt            `| @@` // Exception
	// *TryStmt              `| @@` // Exception
	// BREAK                // Control Flow
	// CONTINUE             // Control Flow

}

type InstallQuery struct {
}

type RunQuery struct {
}

type ShowQuery struct {
}

type DropQuery struct {
}

type Lowercase struct {
}

type Uppercase struct {
}

type Letter struct {
}

type Digit struct {
}

type Integer struct {
}

type Real struct {
}

type Numeric struct {
}

type StringLiteral struct {
}

type Name struct {
	Str string `@Ident`
}

type VertexType struct {
}

type Type struct {
}

type BaseType struct {
}

type FilePath struct {
}

type Typedef struct {
}

type TupleFields struct {
}

type ParameterType struct {
}

type AccumDeclStmt struct {
}

type LocalAccumName struct {
}

type GlobalAccumName struct {
}

type AccumType struct {
}

type ElementType struct {
}

type GAccumAccumStmt struct {
}

type Constant struct {
}

type MathOperator struct {
}

type Condition struct {
}

type ComparisonOperator struct {
}

type Aggregator struct {
}

type Expr struct {
}

type SetBagExpr struct {
}

type BaseDeclStmt struct {
}

type FileDeclStmt struct {
}

type FileVar struct {
}

type LocalVarDeclStmt struct {
}

type AssignDeclLocalTuple struct {
}

// type VSetVarDeclStmt struct {
// 	VertexSetName string     `@Ident`
// 	VertexType    VertexType `['(' @@ ')']`
// 	SeedSet       SeedSet    `'=' @@`
// 	SimpleSet  SimpleSet  `| '=' @@`
// 	SelectStmt SelectStmt `| '=' @@`
// }

type SimpleSet struct {
	VertexSetName string `@Ident`
}

// type SeedSet struct {
// 	Seed Seed `'{' [@@ [',' @@ ]*] '}'`
// }

// type Seed struct {
// 	Seed             string           `'_' | 'ANY'`
// 	VertexSetName    string           `|@Ident`
// 	GlobalAccumName  GlobalAccumName  `| @@`
// 	VertexType       VertexType       `| @@ '.*'`
// 	ParamName        string           `|@Ident`
// 	SelectVertParams SelectVertParams `| 'SelectVertex' @@`
// }

// type SelectVertParams struct {
// }

type ColumnId struct {
}

type AssignStmt struct {
	Name     string `@Ident '='`
	Expr     string `'=' @Ident`
	AttrName string `@Ident`
}

type AttrAccumStmt struct {
}

type LAccumAssignStmt struct {
}

type GAccumAssignStmt struct {
}

type LoadAccumStmt struct {
}

type LoadAccumParams struct {
}

type FuncCallStmt struct {
}

type ArgList struct {
}

type Alias struct {
	Alias string `':' @Ident`
}

type SelectStmt struct {
	GsqlSelectBlock `@@`
	// SqlSelectBlock  `| @@`
}

type GsqlSelectBlock struct {
	GsqlSelectClause `@@`
	FromClause       `@@`

	// TODO SampleClause    `[ @@ ]`  // [sampleClause]

	// TODO WhereClause `[ @@ ]` // [whereClause]
	// TODO AccumClause `[ @@ ]` // [accumClause]

	// TODO PostAccumClause `[ @@ ]*` // [postAccumClause]*
	// TODO HavingClause    `[ @@ ]`  // [havingClause]
	// TODO OrderClause     `[ @@ ]`  // [orderClause]
	// TODO LimitClause     `[ @@ ]`  // [limitClause]
	EndColon string `";"`
}

type GsqlSelectClause struct {
	VertexSetName string `@Ident '='`
	VertexAlias   string `'SELECT' @Ident`
}

type FromClause struct {
	StepSourceSet StepSourceSet `'FROM' @@`
	Step          Step          `@@?`
	// StepV2      `|(@@)`
	// PathPattern `(@@ [',' @@]*)`
}

type StepSourceSet struct {
	VertexSetName string `@Ident`
	VertexAlias   Alias  `@@?`
}
type Step struct {
	StepEdgeSet   StepEdgeSet   `( '-' '(' @@ ')' '-' '>'? )`
	StepVertexSet StepVertexSet `@@?`
}

type StepV2 struct {
}

type StepEdgeSet struct {
	StepEdgeTypes StepEdgeTypes `@@`
	EdgeAlias     Alias         `@@?`
}

type StepEdgeTypes struct {
	EdgeType string `@Ident | '_' | 'ANY'`
	// GlobalAccumName `|@@` //paramName | globalAccumName
}

type StepVertexSet struct {
	StepVertexTypes StepVertexTypes `@@`
	VertAlias       Alias           `@@?`
}

type StepVertexTypes struct {
	VertType string `@Ident | '_' | 'ANY'`
	// GlobalAccumName `|@@` //paramName | globalAccumName
}

type SqlSelectBlock struct {
	// SqlSelectClause `@@`
	// FromClause      `@@`

	// WhereClause   `[ @@ ]` // [GroupByClause]
	// GroupByClause `[ @@ ]` // [accumClause]
	// HavingClause  `[ @@ ]` // [havingClause]
	// OrderClause   `[ @@ ]` // [orderClause]
	// LimitClause   `[ @@ ]` // [limitClause]
}

type SqlSelectClause struct {
}

type ColumnExpr struct {
}

type ColumnName struct {
}

type TableName struct {
}

type AtomicVertexType struct {
}

type VertexSetType struct {
}

type PathPattern struct {
}

type PathEdgePattern struct {
}

type AtomicEdgePattern struct {
}

type DisjPattern struct {
}

type StarPattern struct {
}

type StarBounds struct {
}

type SampleClause struct {
}

type WhereClause struct {
}

type AccumClause struct {
}

type PerClauseV2 struct {
}

type PostAccumClause struct {
}

type DmlSubStmtList struct {
}

type DmlSubStmt struct {
}

type VAccumFuncCall struct {
}

type GroupByClause struct {
}

type GroupExpr struct {
}

type HavingClause struct {
}

type OrderClause struct {
}

type LimitClause struct {
}

type QueryBodyIfStmt struct {
}

type DmlSubIfStmt struct {
}

type QueryBodyCaseStmt struct {
}

type DmlSubCaseStmt struct {
}

type QueryBodyWhileStmt struct {
}

type DmlSubWhileStmt struct {
}

type SimpleSize struct {
}

type QueryBodyForEachStmt struct {
}

type DmlSubForEachStmt struct {
}

type ForEachControl struct {
}

type IterationVar struct {
}

type KeyVar struct {
}

type ValueVar struct {
}

type QueryBodyDeleteStmt struct {
}

type DmlSubDeleteStmt struct {
}

type UpdateStmt struct {
}

type InsertStmt struct {
}

type InsertVertexStmt struct {
}

type InsertEdgeStmt struct {
}

type PrintStmt struct {
}

type PrintExpr struct {
}

type VExprSet struct {
}

type VSetProj struct {
}

type JsonKey struct {
}

type PrintlnStmt struct {
}

type LogStmt struct {
}

type ReturnStmt struct {
}

type DeclExceptStmt struct {
}

type ExceptVarName struct {
}

type ErrorInt struct {
}

type RaiseStmt struct {
}

type ErrorMsg struct {
}

type TryStmt struct {
}

type CaseExceptBlock struct {
}

// type ElseExceptBlock struct {
// *QueryBodyStmt ``
// }
