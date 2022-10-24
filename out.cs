&types.GsqlRoot{
  CreateQuery: &types.CreateQuery{
    IsDistributed: true,
    QueryName: "TwitchEgosData",
    ParameterList: "a",
    GraphName: "TwitchEgos",
    SyntaxV2: true,
    OpenBody: true,
    QueryBody: types.QueryBody{
      Typedefs: []types.Typedef{
        {
          Fields: []types.TupleFields{
            {
              BaseType: "INT",
              FieldName: "from_id",
            },
            {
              BaseType: "INT",
              FieldName: "to_id",
            },
          },
          TupleType: "Edges",
        },
        {
          Fields: []types.TupleFields{
            {
              BaseType: "INT",
              FieldName: "id",
            },
            {
              BaseType: "STRING",
              FieldName: "t",
            },
          },
          TupleType: "Vert",
        },
      },
      QueryBodyStmts: []types.QueryBodyStmt{
        {
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            VertexSetName: "Users",
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
                VertexDotStar: "User",
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexAlias: types.Alias{
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            VertexSetName: "Users",
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
                Param: "userSet",
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexAlias: types.Alias{
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
                VertexSetName: "Users",
                VertexAlias: "s",
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexSetName: "Src",
                  VertexAlias: types.Alias{
                    Alias: "s",
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
                VertexSetName: "Line2",
                VertexAlias: "s",
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexSetName: "Src2",
                  VertexAlias: types.Alias{
                  },
                },
                Step: []types.Step{
                  {
                    StepEdgeSet: types.StepEdgeSet{
                      StepEdgeTypes: types.StepEdgeTypes{
                        FwdEdgeType: "DirEdge",
                      },
                      EdgeAlias: types.Alias{
                        Alias: "e",
                      },
                    },
                    StepVertexSet: types.StepVertexSet{
                      StepVertexTypes: types.StepVertexTypes{
                        VertType: "VType",
                      },
                      VertAlias: types.Alias{
                        Alias: "alias",
                      },
                    },
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
                VertexSetName: "Users",
                VertexAlias: "s",
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexSetName: "Src3",
                  VertexAlias: types.Alias{
                    Alias: "s",
                  },
                },
                Step: []types.Step{
                  {
                    StepEdgeSet: types.StepEdgeSet{
                      StepEdgeTypes: types.StepEdgeTypes{
                        EdgeType: "Etype",
                      },
                      EdgeAlias: types.Alias{
                        Alias: "e",
                      },
                    },
                    StepVertexSet: types.StepVertexSet{
                      StepVertexTypes: types.StepVertexTypes{
                        VertType: "VType",
                      },
                      VertAlias: types.Alias{
                      },
                    },
                  },
                },
              },
              WhereClause: types.WhereClause{
                Conditions: []types.Condition{
                  {
                    IsTrue: true,
                    Comparison: types.Comparison{
                      Expr1: types.Expr{
                        GlblAccum: types.GlobalAccumName{
                        },
                        LclAccum: types.LocalAccumName{
                        },
                      },
                      Expr2: types.Expr{
                        GlblAccum: types.GlobalAccumName{
                        },
                        LclAccum: types.LocalAccumName{
                        },
                      },
                    },
                  },
                  {
                    OrCondition: &types.Condition{
                      IsFalse: true,
                      Comparison: types.Comparison{
                        Expr1: types.Expr{
                          GlblAccum: types.GlobalAccumName{
                          },
                          LclAccum: types.LocalAccumName{
                          },
                        },
                        Expr2: types.Expr{
                          GlblAccum: types.GlobalAccumName{
                          },
                          LclAccum: types.LocalAccumName{
                          },
                        },
                      },
                    },
                    Comparison: types.Comparison{
                      Expr1: types.Expr{
                        GlblAccum: types.GlobalAccumName{
                        },
                        LclAccum: types.LocalAccumName{
                        },
                      },
                      Expr2: types.Expr{
                        GlblAccum: types.GlobalAccumName{
                        },
                        LclAccum: types.LocalAccumName{
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
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
                VertexSetName: "Users",
                VertexAlias: "s",
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexSetName: "Src4",
                  VertexAlias: types.Alias{
                    Alias: "s",
                  },
                },
                Step: []types.Step{
                  {
                    StepEdgeSet: types.StepEdgeSet{
                      StepEdgeTypes: types.StepEdgeTypes{
                        EdgeType: "DirEdge",
                      },
                      EdgeAlias: types.Alias{
                        Alias: "e",
                      },
                    },
                    Directed: true,
                    StepVertexSet: types.StepVertexSet{
                      StepVertexTypes: types.StepVertexTypes{
                        VertType: "VType",
                      },
                      VertAlias: types.Alias{
                        Alias: "v",
                      },
                    },
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
                VertexSetName: "Users",
                VertexAlias: "s",
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexSetName: "Src5",
                  VertexAlias: types.Alias{
                    Alias: "s",
                  },
                },
                Step: []types.Step{
                  {
                    StepEdgeSet: types.StepEdgeSet{
                      StepEdgeTypes: types.StepEdgeTypes{
                        FwdEdgeType: "DirEdge",
                      },
                      EdgeAlias: types.Alias{
                        Alias: "e",
                      },
                    },
                    StepVertexSet: types.StepVertexSet{
                      StepVertexTypes: types.StepVertexTypes{
                        VertType: "VType",
                      },
                      VertAlias: types.Alias{
                        Alias: "alias",
                      },
                    },
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
                VertexSetName: "Users",
                VertexAlias: "s",
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexSetName: "Src6",
                  VertexAlias: types.Alias{
                    Alias: "s",
                  },
                },
                Step: []types.Step{
                  {
                    StepEdgeSet: types.StepEdgeSet{
                      StepEdgeTypes: types.StepEdgeTypes{
                        BackEdgeType: "DirEdge",
                      },
                      EdgeAlias: types.Alias{
                        Alias: "e",
                      },
                    },
                    StepVertexSet: types.StepVertexSet{
                      StepVertexTypes: types.StepVertexTypes{
                        VertType: "VType",
                      },
                      VertAlias: types.Alias{
                        Alias: "alias",
                      },
                    },
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Name: "i",
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexAlias: types.Alias{
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Name: "i",
            Expr: types.Expr{
              StrVal: "\"Here\"",
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexAlias: types.Alias{
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Name: "i",
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
                AccumName: &"global",
              },
              LclAccum: types.LocalAccumName{
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexAlias: types.Alias{
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
        {
          AssignStmt: types.AssignStmt{
            Name: "i",
            Expr: types.Expr{
              GlblAccum: types.GlobalAccumName{
              },
              LclAccum: types.LocalAccumName{
                ParentName: &"a",
                AccumName: &"lclaccum",
              },
            },
          },
          VSetVarDeclStmt: types.VSetVarDeclStmt{
            SeedSet: types.SeedSet{
              Seed: types.Seed{
                GlobalAccumName: types.GlobalAccumName{
                },
              },
            },
            SelectStmt: types.SelectStmt{
              GsqlSelectBlock: types.GsqlSelectBlock{
                GsqlSelectClause: types.GsqlSelectClause{
                },
                FromClause: types.FromClause{
                  StepSourceSet: types.StepSourceSet{
                    VertexAlias: types.Alias{
                    },
                  },
                },
                WhereClause: types.WhereClause{
                },
              },
            },
          },
          SelectStmt: types.SelectStmt{
            GsqlSelectBlock: types.GsqlSelectBlock{
              GsqlSelectClause: types.GsqlSelectClause{
              },
              FromClause: types.FromClause{
                StepSourceSet: types.StepSourceSet{
                  VertexAlias: types.Alias{
                  },
                },
              },
              WhereClause: types.WhereClause{
              },
            },
          },
        },
      },
    },
    CloseBody: true,
  },
}