package types

import "fmt"

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

type QueryBodyStmts struct {
	QueryBodyStmt []*QueryBodyStmt `@@*`
}

type QueryBodyStmt struct {
	*AssignStmt           `@@` // Assignment
	*VSetVarDeclStmt           // Declaration
	*DeclStmts                 // Declaration
	*LAccumAssignStmt          // Assignment
	*GAccumAssignStmt          // Assignment
	*GAccumAccumStmt           // Assignment
	*FuncCallStmt              // Function Call
	*SelectStmt                // Select
	*QueryBodyCaseStmt         // Control Flow
	*QueryBodyIfStmt           // Control Flow
	*QueryBodyWhileStmt        // Control Flow
	*QueryBodyForEachStmt      // Control Flow
	*UpdateStmt                // Data Modification
	*InsertStmt                // Data Modification
	*QueryBodyDeleteStmt       // Data Modification
	*PrintStmt                 // Output
	*PrintlnStmt               // Output
	*LogStmt                   // Output
	*ReturnStmt                // Output
	*RaiseStmt                 // Exception
	*TryStmt                   // Exception
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
	Str *string `@String`
}

type GraphName Name
type QueryName Name
type ParamName Name
type AccumName Name
type VertexSetName Name
type AttrName Name
type VarName Name
type TupleType Name
type FieldName Name
type FuncName Name

type VertexType struct {
}

type EdgeType struct {
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

type VSetVarDeclStmt struct {
}

type SimpleSet struct {
}

type SeedSet struct {
}

type Seed struct {
}

type SelectVertParams struct {
}

type ColumnId struct {
}

type AssignStmt struct {
	Name     string `@Ident "="`
	Expr     string `"=" @Ident`
	AttrName `@@`
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

type SelectStmt struct {
}

type GsqlSelectBlock struct {
}

type SqlSelectBlock struct {
}

type GsqlSelectClause struct {
}

type SqlSelectClause struct {
}

type ColumnExpr struct {
}

type ColumnName struct {
}

type TableName struct {
}

type FromClause struct {
}

type Step struct {
}

type StepV2 struct {
}

type StepSourceSet struct {
}

type StepEdgeSet struct {
}

type StepVertexSet struct {
}

type Alias struct {
}

type VertexAlias struct {
}

type EdgeAlias struct {
}

type StepEdgeTypes struct {
}

type AtomicEdgeType struct {
}

type EdgeSetType struct {
}

type StepVertexTypes struct {
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

type ElseExceptBlock struct {
	*QueryBodyStmts ``
}

func main() {
	var e ElseExceptBlock

	fmt.Printf("e.QueryBodyStmts: %v\n", e.QueryBodyStmts)
}
