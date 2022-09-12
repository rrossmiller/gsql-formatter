&types.GsqlRoot{
  QueryBody: &types.QueryBody{
    QueryBodyStmts: []*types.QueryBodyStmt{
      {
        VSetVarDeclStmt: &types.VSetVarDeclStmt{
          VertexSetName: "Users",
          SeedSet: types.SeedSet{
            Seed: &types.Seed{
              GlobalAccumName: types.GlobalAccumName{
              },
              VertexType: "User",
            },
          },
          SimpleSet: types.SimpleSet{
          },
          SelectStmt: types.SelectStmt{
            Pos: Position{Filename: "", Offset: 0, Line: 0, Column: 0},
          },
        },
      },
      {
        VSetVarDeclStmt: &types.VSetVarDeclStmt{
          VertexSetName: "Users",
          SeedSet: types.SeedSet{
            Seed: &types.Seed{
              GlobalAccumName: types.GlobalAccumName{
              },
              VertexDotStar: "User",
            },
          },
          SimpleSet: types.SimpleSet{
          },
          SelectStmt: types.SelectStmt{
            Pos: Position{Filename: "", Offset: 0, Line: 0, Column: 0},
          },
        },
      },
      {
        SelectStmt: &types.SelectStmt{
          Pos: Position{Filename: "", Offset: 38, Line: 4, Column: 2},
          GsqlSelectBlock: &types.GsqlSelectBlock{
            GsqlSelectClause: &types.GsqlSelectClause{
              VertexSetName: "Users",
              VertexAlias: "s",
            },
            FromClause: &types.FromClause{
              StepSourceSet: &types.StepSourceSet{
                VertexSetName: "Users",
                VertexAlias: types.Alias{
                  Alias: "s",
                },
              },
            },
            WhereClause: &types.WhereClause{
              Conditions: []*types.Condition{
                {
                  NotComparison: &types.Condition{
                    Comparison: &types.Comparison{
                      Expr1: &types.Expr{
                        LclAccum: &types.LocalAccumName{
                          ParentName: &"a",
                          AccumName: &"thing",
                        },
                        Val: types.Name{
                        },
                      },
                      Expr2: &types.Expr{
                        Val: types.Name{
                          Str: &"AND",
                        },
                      },
                    },
                  },
                },
                {
                  Comparison: &types.Comparison{
                    Expr1: &types.Expr{
                      Val: types.Name{
                        Str: &"True",
                      },
                    },
                  },
                },
              },
            },
          },
        },
      },
      {
        SelectStmt: &types.SelectStmt{
          Pos: Position{Filename: "", Offset: 100, Line: 6, Column: 2},
          GsqlSelectBlock: &types.GsqlSelectBlock{
            GsqlSelectClause: &types.GsqlSelectClause{
              VertexSetName: "Friends1",
              VertexAlias: "u",
            },
            FromClause: &types.FromClause{
              StepSourceSet: &types.StepSourceSet{
                VertexSetName: "Users",
                VertexAlias: types.Alias{
                  Alias: "s",
                },
              },
              Step: []*types.Step{
                {
                  StepEdgeSet: types.StepEdgeSet{
                    StepEdgeTypes: types.StepEdgeTypes{
                      EdgeType: "FRIENDSHIP",
                    },
                    EdgeAlias: "e",
                  },
                  StepVertexSet: types.StepVertexSet{
                    StepVertexTypes: types.StepVertexTypes{
                      VertType: "Friend",
                    },
                    VertAlias: types.Alias{
                      Alias: "u",
                    },
                  },
                },
              },
            },
          },
        },
      },
      {
        SelectStmt: &types.SelectStmt{
          Pos: Position{Filename: "", Offset: 161, Line: 7, Column: 2},
          GsqlSelectBlock: &types.GsqlSelectBlock{
            GsqlSelectClause: &types.GsqlSelectClause{
              VertexSetName: "Friends2",
              VertexAlias: "tgt",
            },
            FromClause: &types.FromClause{
              StepSourceSet: &types.StepSourceSet{
                VertexSetName: "Users",
                VertexAlias: types.Alias{
                  Alias: "s",
                },
              },
              Step: []*types.Step{
                {
                  StepEdgeSet: types.StepEdgeSet{
                    StepEdgeTypes: types.StepEdgeTypes{
                      FwdEdgeType: "FRIENDSHIP",
                    },
                    EdgeAlias: "e",
                  },
                  StepVertexSet: types.StepVertexSet{
                    StepVertexTypes: types.StepVertexTypes{
                      VertType: "_",
                    },
                    VertAlias: types.Alias{
                      Alias: "u",
                    },
                  },
                },
                {
                  StepEdgeSet: types.StepEdgeSet{
                    StepEdgeTypes: types.StepEdgeTypes{
                      BackEdgeType: "FRIENDSHIP",
                    },
                    EdgeAlias: "e2",
                  },
                  StepVertexSet: types.StepVertexSet{
                    StepVertexTypes: types.StepVertexTypes{
                      VertType: "Friend",
                    },
                    VertAlias: types.Alias{
                      Alias: "tgt",
                    },
                  },
                },
              },
            },
          },
        },
      },
    },
  },
}