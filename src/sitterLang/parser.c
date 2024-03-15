#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 881
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 258
#define ALIAS_COUNT 0
#define TOKEN_COUNT 134
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 14
#define MAX_ALIAS_SEQUENCE_LENGTH 13
#define PRODUCTION_ID_COUNT 28

enum ts_symbol_identifiers {
  anon_sym_CREATE = 1,
  anon_sym_OR = 2,
  anon_sym_REPLACE = 3,
  anon_sym_DISTRIBUTED = 4,
  anon_sym_QUERY = 5,
  anon_sym_FOR = 6,
  anon_sym_GRAPH = 7,
  anon_sym_SYNTAX = 8,
  anon_sym_V2 = 9,
  anon_sym_v2 = 10,
  anon_sym_INTERPRET = 11,
  anon_sym_LPAREN = 12,
  anon_sym_RPAREN = 13,
  anon_sym_COMMA = 14,
  anon_sym_EQ = 15,
  anon_sym_SET = 16,
  anon_sym_LT = 17,
  anon_sym_GT = 18,
  anon_sym_LBRACE = 19,
  anon_sym_RBRACE = 20,
  anon_sym_TYPEDEF = 21,
  anon_sym_TUPLE = 22,
  anon_sym_SEMI = 23,
  anon_sym_DOT = 24,
  anon_sym__ = 25,
  anon_sym_ANY = 26,
  anon_sym_DOT_STAR = 27,
  anon_sym_UNION = 28,
  anon_sym_INTERSECT = 29,
  anon_sym_MINUS = 30,
  anon_sym_PLUS_EQ = 31,
  anon_sym_SELECT = 32,
  anon_sym_FROM = 33,
  anon_sym_WHERE = 34,
  anon_sym_ACCUM = 35,
  anon_sym_IF = 36,
  anon_sym_THEN = 37,
  anon_sym_ELSE = 38,
  anon_sym_END = 39,
  anon_sym_CASE = 40,
  anon_sym_WHEN = 41,
  anon_sym_WHILE = 42,
  anon_sym_LIMIT = 43,
  anon_sym_DO = 44,
  anon_sym_FOREACH = 45,
  anon_sym_IN = 46,
  anon_sym_COLON = 47,
  anon_sym_RANGE = 48,
  anon_sym_LBRACK = 49,
  anon_sym_RBRACK = 50,
  anon_sym_STEP = 51,
  anon_sym_POST_DASHACCUM = 52,
  anon_sym_OFFSET = 53,
  anon_sym_DASH = 54,
  anon_sym_PIPE = 55,
  anon_sym_PIPE2 = 56,
  anon_sym_STAR = 57,
  anon_sym_SumAccum = 58,
  anon_sym_INT = 59,
  anon_sym_FLOAT = 60,
  anon_sym_DOUBLE = 61,
  anon_sym_STRING = 62,
  anon_sym_MaxAccum = 63,
  anon_sym_MinAccum = 64,
  anon_sym_AvgAccum = 65,
  anon_sym_OrAccum = 66,
  anon_sym_AndAccum = 67,
  anon_sym_BitwiseorAccum = 68,
  anon_sym_BitwiseandAccum = 69,
  anon_sym_ListAccum = 70,
  anon_sym_SetAccum = 71,
  anon_sym_BagAccum = 72,
  anon_sym_MapAccum = 73,
  anon_sym_HeapAccum = 74,
  anon_sym_ASC = 75,
  anon_sym_DESC = 76,
  anon_sym_GroupbyAccum = 77,
  anon_sym_ArrayAccum = 78,
  anon_sym_AT_AT = 79,
  anon_sym_AT = 80,
  anon_sym_FILTER = 81,
  anon_sym_COALESCE = 82,
  anon_sym_DISTINCT = 83,
  anon_sym_ISEMPTY = 84,
  anon_sym_DASH_GT = 85,
  anon_sym_NOT = 86,
  anon_sym_IS = 87,
  anon_sym_NULL = 88,
  anon_sym_BETWEEN = 89,
  anon_sym_AND = 90,
  anon_sym_TRUE = 91,
  anon_sym_FALSE = 92,
  anon_sym_LIKE = 93,
  anon_sym_COUNT = 94,
  anon_sym_MAX = 95,
  anon_sym_MIN = 96,
  anon_sym_AVG = 97,
  anon_sym_SUM = 98,
  anon_sym_PRINT = 99,
  anon_sym_TO_CSV = 100,
  anon_sym_AS = 101,
  anon_sym_BOOL = 102,
  anon_sym_UINT = 103,
  anon_sym_VERTEX = 104,
  anon_sym_EDGE = 105,
  anon_sym_JSONOBJECT = 106,
  anon_sym_JSONARRAY = 107,
  anon_sym_DATETIME = 108,
  sym_name = 109,
  anon_sym_GSQL_UINT_MAX = 110,
  anon_sym_GSQL_INT_MAX = 111,
  anon_sym_GSQL_UINT_MIN = 112,
  sym_digit = 113,
  anon_sym_DQUOTE = 114,
  anon_sym_SQUOTE = 115,
  sym_space = 116,
  sym_string_fragment = 117,
  anon_sym_SLASH = 118,
  anon_sym_PERCENT = 119,
  anon_sym_PLUS = 120,
  anon_sym_LT_LT = 121,
  anon_sym_GT_GT = 122,
  anon_sym_AMP = 123,
  anon_sym_LT_EQ = 124,
  anon_sym_GT_EQ = 125,
  anon_sym_EQ_EQ = 126,
  anon_sym_BANG_EQ = 127,
  sym_newline = 128,
  sym_spacing_line = 129,
  sym_comment_contents = 130,
  anon_sym_SLASH_STAR = 131,
  anon_sym_STAR_SLASH = 132,
  sym_line_comment = 133,
  sym_gsql = 134,
  sym__definition = 135,
  sym_create_query = 136,
  sym_interpret_query = 137,
  sym_parameter_list = 138,
  sym_query_params = 139,
  sym_query_param = 140,
  sym_set_param = 141,
  sym_query_body = 142,
  sym_typedef = 143,
  sym_tuple_fields = 144,
  sym_tuple_field = 145,
  sym_query_body_stmt = 146,
  sym_assign_stmt = 147,
  sym_v_set_var_decl_stmt = 148,
  sym_seed_set = 149,
  sym_seed = 150,
  sym_simple_set = 151,
  sym_l_accum_assign_stmt = 152,
  sym_g_accum_assign_stmt = 153,
  sym_g_accum_accum_stmt = 154,
  sym_func_call_stmt = 155,
  sym__select_stmt = 156,
  sym_gsql_select_block = 157,
  sym_gsql_select_clause = 158,
  sym_from_clause = 159,
  sym_where_clause = 160,
  sym_accum_clause = 161,
  sym_dml_sub_stmt_list = 162,
  sym_dml_sub_stmt = 163,
  sym_l_accum_accum_stmt = 164,
  sym_attr_accum_stmt = 165,
  sym_v_accum_func_call = 166,
  sym_local_var_decl_stmt = 167,
  sym_dml_sub_if_stmt = 168,
  sym_dml_sub_case_stmt = 169,
  sym_dml_sub_while_stmt = 170,
  sym_dml_sub_for_each_stmt = 171,
  sym_for_each_control = 172,
  sym_post_accum_clause = 173,
  sym_limit_clause = 174,
  sym_path_pattern = 175,
  sym_path_edge_pattern = 176,
  sym_atomic_edge_pattern = 177,
  sym_disj_pattern = 178,
  sym_step = 179,
  sym_step_v2 = 180,
  sym_step_source_set = 181,
  sym_step_edge_set = 182,
  sym_step_edge_types = 183,
  sym_atomic_edge_type = 184,
  sym_edge_set_type = 185,
  sym_step_vertex_set = 186,
  sym_step_vertex_types = 187,
  sym_atomic_vertex_type = 188,
  sym_vertex_set_type = 189,
  sym_query_body_case_stmt = 190,
  sym_query_body_if_stmt = 191,
  sym_query_body_while_stmt = 192,
  sym_query_body_for_each_stmt = 193,
  sym_decl_stmt = 194,
  sym_base_decl_stmt = 195,
  sym_accum_decl_stmt = 196,
  sym_accum_type = 197,
  sym_global_accum_name = 198,
  sym_local_accum_name = 199,
  sym_arg_list = 200,
  sym_simple_size = 201,
  sym_expr = 202,
  sym_condition = 203,
  sym_set_bag_expr = 204,
  sym_name_dot = 205,
  sym_aggregator = 206,
  sym_print_stmt = 207,
  sym_print_expr = 208,
  sym_v_expr_set = 209,
  sym_v_set_proj = 210,
  sym_file_path = 211,
  sym__type = 212,
  sym__element_type = 213,
  sym_base_type = 214,
  sym_constant = 215,
  sym__numeric = 216,
  sym_integer = 217,
  sym_real = 218,
  sym_string_literal = 219,
  sym_math_operator = 220,
  sym_comparison_operator = 221,
  sym_block_comment = 222,
  aux_sym_gsql_repeat1 = 223,
  aux_sym_query_params_repeat1 = 224,
  aux_sym_query_body_repeat1 = 225,
  aux_sym_typedef_repeat1 = 226,
  aux_sym_tuple_fields_repeat1 = 227,
  aux_sym_seed_set_repeat1 = 228,
  aux_sym_func_call_stmt_repeat1 = 229,
  aux_sym_func_call_stmt_repeat2 = 230,
  aux_sym_gsql_select_block_repeat1 = 231,
  aux_sym_from_clause_repeat1 = 232,
  aux_sym_dml_sub_stmt_list_repeat1 = 233,
  aux_sym_v_accum_func_call_repeat1 = 234,
  aux_sym_dml_sub_if_stmt_repeat1 = 235,
  aux_sym_dml_sub_case_stmt_repeat1 = 236,
  aux_sym_for_each_control_repeat1 = 237,
  aux_sym_path_pattern_repeat1 = 238,
  aux_sym_disj_pattern_repeat1 = 239,
  aux_sym_step_repeat1 = 240,
  aux_sym_step_edge_types_repeat1 = 241,
  aux_sym_step_vertex_types_repeat1 = 242,
  aux_sym_query_body_case_stmt_repeat1 = 243,
  aux_sym_query_body_case_stmt_repeat2 = 244,
  aux_sym_query_body_if_stmt_repeat1 = 245,
  aux_sym_base_decl_stmt_repeat1 = 246,
  aux_sym_accum_decl_stmt_repeat1 = 247,
  aux_sym_accum_type_repeat1 = 248,
  aux_sym_accum_type_repeat2 = 249,
  aux_sym_accum_type_repeat3 = 250,
  aux_sym_accum_type_repeat4 = 251,
  aux_sym_arg_list_repeat1 = 252,
  aux_sym_name_dot_repeat1 = 253,
  aux_sym_print_stmt_repeat1 = 254,
  aux_sym_v_expr_set_repeat1 = 255,
  aux_sym_string_literal_repeat1 = 256,
  aux_sym_block_comment_repeat1 = 257,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_CREATE] = "CREATE",
  [anon_sym_OR] = "OR",
  [anon_sym_REPLACE] = "REPLACE",
  [anon_sym_DISTRIBUTED] = "DISTRIBUTED",
  [anon_sym_QUERY] = "QUERY",
  [anon_sym_FOR] = "FOR",
  [anon_sym_GRAPH] = "GRAPH",
  [anon_sym_SYNTAX] = "SYNTAX",
  [anon_sym_V2] = "V2",
  [anon_sym_v2] = "v2",
  [anon_sym_INTERPRET] = "INTERPRET",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COMMA] = ",",
  [anon_sym_EQ] = "=",
  [anon_sym_SET] = "SET",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_TYPEDEF] = "TYPEDEF",
  [anon_sym_TUPLE] = "TUPLE",
  [anon_sym_SEMI] = ";",
  [anon_sym_DOT] = ".",
  [anon_sym__] = "_",
  [anon_sym_ANY] = "ANY",
  [anon_sym_DOT_STAR] = ".*",
  [anon_sym_UNION] = "UNION",
  [anon_sym_INTERSECT] = "INTERSECT",
  [anon_sym_MINUS] = "MINUS",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_SELECT] = "SELECT",
  [anon_sym_FROM] = "FROM",
  [anon_sym_WHERE] = "WHERE",
  [anon_sym_ACCUM] = "ACCUM",
  [anon_sym_IF] = "IF",
  [anon_sym_THEN] = "THEN",
  [anon_sym_ELSE] = "ELSE",
  [anon_sym_END] = "END",
  [anon_sym_CASE] = "CASE",
  [anon_sym_WHEN] = "WHEN",
  [anon_sym_WHILE] = "WHILE",
  [anon_sym_LIMIT] = "LIMIT",
  [anon_sym_DO] = "DO",
  [anon_sym_FOREACH] = "FOREACH",
  [anon_sym_IN] = "IN",
  [anon_sym_COLON] = ":",
  [anon_sym_RANGE] = "RANGE",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_STEP] = "STEP",
  [anon_sym_POST_DASHACCUM] = "POST-ACCUM",
  [anon_sym_OFFSET] = "OFFSET",
  [anon_sym_DASH] = "-",
  [anon_sym_PIPE] = " | ",
  [anon_sym_PIPE2] = "|",
  [anon_sym_STAR] = "*",
  [anon_sym_SumAccum] = "SumAccum",
  [anon_sym_INT] = "INT",
  [anon_sym_FLOAT] = "FLOAT",
  [anon_sym_DOUBLE] = "DOUBLE",
  [anon_sym_STRING] = "STRING",
  [anon_sym_MaxAccum] = "MaxAccum",
  [anon_sym_MinAccum] = "MinAccum",
  [anon_sym_AvgAccum] = "AvgAccum",
  [anon_sym_OrAccum] = "OrAccum",
  [anon_sym_AndAccum] = "AndAccum",
  [anon_sym_BitwiseorAccum] = "BitwiseorAccum",
  [anon_sym_BitwiseandAccum] = "BitwiseandAccum",
  [anon_sym_ListAccum] = "ListAccum",
  [anon_sym_SetAccum] = "SetAccum",
  [anon_sym_BagAccum] = "BagAccum",
  [anon_sym_MapAccum] = "MapAccum",
  [anon_sym_HeapAccum] = "HeapAccum",
  [anon_sym_ASC] = "ASC",
  [anon_sym_DESC] = "DESC",
  [anon_sym_GroupbyAccum] = "GroupbyAccum",
  [anon_sym_ArrayAccum] = "ArrayAccum",
  [anon_sym_AT_AT] = "@@",
  [anon_sym_AT] = "@",
  [anon_sym_FILTER] = "FILTER",
  [anon_sym_COALESCE] = "COALESCE",
  [anon_sym_DISTINCT] = "DISTINCT",
  [anon_sym_ISEMPTY] = "ISEMPTY",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_NOT] = "NOT",
  [anon_sym_IS] = "IS",
  [anon_sym_NULL] = "NULL",
  [anon_sym_BETWEEN] = "BETWEEN",
  [anon_sym_AND] = "AND",
  [anon_sym_TRUE] = "TRUE",
  [anon_sym_FALSE] = "FALSE",
  [anon_sym_LIKE] = "LIKE",
  [anon_sym_COUNT] = "COUNT",
  [anon_sym_MAX] = "MAX",
  [anon_sym_MIN] = "MIN",
  [anon_sym_AVG] = "AVG",
  [anon_sym_SUM] = "SUM",
  [anon_sym_PRINT] = "PRINT",
  [anon_sym_TO_CSV] = "TO_CSV",
  [anon_sym_AS] = "AS",
  [anon_sym_BOOL] = "BOOL",
  [anon_sym_UINT] = "UINT",
  [anon_sym_VERTEX] = "VERTEX",
  [anon_sym_EDGE] = "EDGE",
  [anon_sym_JSONOBJECT] = "JSONOBJECT",
  [anon_sym_JSONARRAY] = "JSONARRAY",
  [anon_sym_DATETIME] = "DATETIME",
  [sym_name] = "name",
  [anon_sym_GSQL_UINT_MAX] = "GSQL_UINT_MAX",
  [anon_sym_GSQL_INT_MAX] = "GSQL_INT_MAX",
  [anon_sym_GSQL_UINT_MIN] = "GSQL_UINT_MIN",
  [sym_digit] = "digit",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_space] = "space",
  [sym_string_fragment] = "string_fragment",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PLUS] = "+",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_AMP] = "&",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [sym_newline] = "newline",
  [sym_spacing_line] = "spacing_line",
  [sym_comment_contents] = "comment_contents",
  [anon_sym_SLASH_STAR] = "/*",
  [anon_sym_STAR_SLASH] = "*/",
  [sym_line_comment] = "line_comment",
  [sym_gsql] = "gsql",
  [sym__definition] = "_definition",
  [sym_create_query] = "create_query",
  [sym_interpret_query] = "interpret_query",
  [sym_parameter_list] = "parameter_list",
  [sym_query_params] = "query_params",
  [sym_query_param] = "query_param",
  [sym_set_param] = "set_param",
  [sym_query_body] = "query_body",
  [sym_typedef] = "typedef",
  [sym_tuple_fields] = "tuple_fields",
  [sym_tuple_field] = "tuple_field",
  [sym_query_body_stmt] = "query_body_stmt",
  [sym_assign_stmt] = "assign_stmt",
  [sym_v_set_var_decl_stmt] = "v_set_var_decl_stmt",
  [sym_seed_set] = "seed_set",
  [sym_seed] = "seed",
  [sym_simple_set] = "simple_set",
  [sym_l_accum_assign_stmt] = "l_accum_assign_stmt",
  [sym_g_accum_assign_stmt] = "g_accum_assign_stmt",
  [sym_g_accum_accum_stmt] = "g_accum_accum_stmt",
  [sym_func_call_stmt] = "func_call_stmt",
  [sym__select_stmt] = "_select_stmt",
  [sym_gsql_select_block] = "gsql_select_block",
  [sym_gsql_select_clause] = "gsql_select_clause",
  [sym_from_clause] = "from_clause",
  [sym_where_clause] = "where_clause",
  [sym_accum_clause] = "accum_clause",
  [sym_dml_sub_stmt_list] = "dml_sub_stmt_list",
  [sym_dml_sub_stmt] = "dml_sub_stmt",
  [sym_l_accum_accum_stmt] = "l_accum_accum_stmt",
  [sym_attr_accum_stmt] = "attr_accum_stmt",
  [sym_v_accum_func_call] = "v_accum_func_call",
  [sym_local_var_decl_stmt] = "local_var_decl_stmt",
  [sym_dml_sub_if_stmt] = "dml_sub_if_stmt",
  [sym_dml_sub_case_stmt] = "dml_sub_case_stmt",
  [sym_dml_sub_while_stmt] = "dml_sub_while_stmt",
  [sym_dml_sub_for_each_stmt] = "dml_sub_for_each_stmt",
  [sym_for_each_control] = "for_each_control",
  [sym_post_accum_clause] = "post_accum_clause",
  [sym_limit_clause] = "limit_clause",
  [sym_path_pattern] = "path_pattern",
  [sym_path_edge_pattern] = "path_edge_pattern",
  [sym_atomic_edge_pattern] = "atomic_edge_pattern",
  [sym_disj_pattern] = "disj_pattern",
  [sym_step] = "step",
  [sym_step_v2] = "step_v2",
  [sym_step_source_set] = "step_source_set",
  [sym_step_edge_set] = "step_edge_set",
  [sym_step_edge_types] = "step_edge_types",
  [sym_atomic_edge_type] = "atomic_edge_type",
  [sym_edge_set_type] = "edge_set_type",
  [sym_step_vertex_set] = "step_vertex_set",
  [sym_step_vertex_types] = "step_vertex_types",
  [sym_atomic_vertex_type] = "atomic_vertex_type",
  [sym_vertex_set_type] = "vertex_set_type",
  [sym_query_body_case_stmt] = "query_body_case_stmt",
  [sym_query_body_if_stmt] = "query_body_if_stmt",
  [sym_query_body_while_stmt] = "query_body_while_stmt",
  [sym_query_body_for_each_stmt] = "query_body_for_each_stmt",
  [sym_decl_stmt] = "decl_stmt",
  [sym_base_decl_stmt] = "base_decl_stmt",
  [sym_accum_decl_stmt] = "accum_decl_stmt",
  [sym_accum_type] = "accum_type",
  [sym_global_accum_name] = "global_accum_name",
  [sym_local_accum_name] = "local_accum_name",
  [sym_arg_list] = "arg_list",
  [sym_simple_size] = "simple_size",
  [sym_expr] = "expr",
  [sym_condition] = "condition",
  [sym_set_bag_expr] = "set_bag_expr",
  [sym_name_dot] = "name_dot",
  [sym_aggregator] = "aggregator",
  [sym_print_stmt] = "print_stmt",
  [sym_print_expr] = "print_expr",
  [sym_v_expr_set] = "v_expr_set",
  [sym_v_set_proj] = "v_set_proj",
  [sym_file_path] = "file_path",
  [sym__type] = "_type",
  [sym__element_type] = "_element_type",
  [sym_base_type] = "base_type",
  [sym_constant] = "constant",
  [sym__numeric] = "_numeric",
  [sym_integer] = "integer",
  [sym_real] = "real",
  [sym_string_literal] = "string_literal",
  [sym_math_operator] = "math_operator",
  [sym_comparison_operator] = "comparison_operator",
  [sym_block_comment] = "block_comment",
  [aux_sym_gsql_repeat1] = "gsql_repeat1",
  [aux_sym_query_params_repeat1] = "query_params_repeat1",
  [aux_sym_query_body_repeat1] = "query_body_repeat1",
  [aux_sym_typedef_repeat1] = "typedef_repeat1",
  [aux_sym_tuple_fields_repeat1] = "tuple_fields_repeat1",
  [aux_sym_seed_set_repeat1] = "seed_set_repeat1",
  [aux_sym_func_call_stmt_repeat1] = "func_call_stmt_repeat1",
  [aux_sym_func_call_stmt_repeat2] = "func_call_stmt_repeat2",
  [aux_sym_gsql_select_block_repeat1] = "gsql_select_block_repeat1",
  [aux_sym_from_clause_repeat1] = "from_clause_repeat1",
  [aux_sym_dml_sub_stmt_list_repeat1] = "dml_sub_stmt_list_repeat1",
  [aux_sym_v_accum_func_call_repeat1] = "v_accum_func_call_repeat1",
  [aux_sym_dml_sub_if_stmt_repeat1] = "dml_sub_if_stmt_repeat1",
  [aux_sym_dml_sub_case_stmt_repeat1] = "dml_sub_case_stmt_repeat1",
  [aux_sym_for_each_control_repeat1] = "for_each_control_repeat1",
  [aux_sym_path_pattern_repeat1] = "path_pattern_repeat1",
  [aux_sym_disj_pattern_repeat1] = "disj_pattern_repeat1",
  [aux_sym_step_repeat1] = "step_repeat1",
  [aux_sym_step_edge_types_repeat1] = "step_edge_types_repeat1",
  [aux_sym_step_vertex_types_repeat1] = "step_vertex_types_repeat1",
  [aux_sym_query_body_case_stmt_repeat1] = "query_body_case_stmt_repeat1",
  [aux_sym_query_body_case_stmt_repeat2] = "query_body_case_stmt_repeat2",
  [aux_sym_query_body_if_stmt_repeat1] = "query_body_if_stmt_repeat1",
  [aux_sym_base_decl_stmt_repeat1] = "base_decl_stmt_repeat1",
  [aux_sym_accum_decl_stmt_repeat1] = "accum_decl_stmt_repeat1",
  [aux_sym_accum_type_repeat1] = "accum_type_repeat1",
  [aux_sym_accum_type_repeat2] = "accum_type_repeat2",
  [aux_sym_accum_type_repeat3] = "accum_type_repeat3",
  [aux_sym_accum_type_repeat4] = "accum_type_repeat4",
  [aux_sym_arg_list_repeat1] = "arg_list_repeat1",
  [aux_sym_name_dot_repeat1] = "name_dot_repeat1",
  [aux_sym_print_stmt_repeat1] = "print_stmt_repeat1",
  [aux_sym_v_expr_set_repeat1] = "v_expr_set_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
  [aux_sym_block_comment_repeat1] = "block_comment_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_CREATE] = anon_sym_CREATE,
  [anon_sym_OR] = anon_sym_OR,
  [anon_sym_REPLACE] = anon_sym_REPLACE,
  [anon_sym_DISTRIBUTED] = anon_sym_DISTRIBUTED,
  [anon_sym_QUERY] = anon_sym_QUERY,
  [anon_sym_FOR] = anon_sym_FOR,
  [anon_sym_GRAPH] = anon_sym_GRAPH,
  [anon_sym_SYNTAX] = anon_sym_SYNTAX,
  [anon_sym_V2] = anon_sym_V2,
  [anon_sym_v2] = anon_sym_v2,
  [anon_sym_INTERPRET] = anon_sym_INTERPRET,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_SET] = anon_sym_SET,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_TYPEDEF] = anon_sym_TYPEDEF,
  [anon_sym_TUPLE] = anon_sym_TUPLE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym__] = anon_sym__,
  [anon_sym_ANY] = anon_sym_ANY,
  [anon_sym_DOT_STAR] = anon_sym_DOT_STAR,
  [anon_sym_UNION] = anon_sym_UNION,
  [anon_sym_INTERSECT] = anon_sym_INTERSECT,
  [anon_sym_MINUS] = anon_sym_MINUS,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_SELECT] = anon_sym_SELECT,
  [anon_sym_FROM] = anon_sym_FROM,
  [anon_sym_WHERE] = anon_sym_WHERE,
  [anon_sym_ACCUM] = anon_sym_ACCUM,
  [anon_sym_IF] = anon_sym_IF,
  [anon_sym_THEN] = anon_sym_THEN,
  [anon_sym_ELSE] = anon_sym_ELSE,
  [anon_sym_END] = anon_sym_END,
  [anon_sym_CASE] = anon_sym_CASE,
  [anon_sym_WHEN] = anon_sym_WHEN,
  [anon_sym_WHILE] = anon_sym_WHILE,
  [anon_sym_LIMIT] = anon_sym_LIMIT,
  [anon_sym_DO] = anon_sym_DO,
  [anon_sym_FOREACH] = anon_sym_FOREACH,
  [anon_sym_IN] = anon_sym_IN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_RANGE] = anon_sym_RANGE,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_STEP] = anon_sym_STEP,
  [anon_sym_POST_DASHACCUM] = anon_sym_POST_DASHACCUM,
  [anon_sym_OFFSET] = anon_sym_OFFSET,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_PIPE2] = anon_sym_PIPE2,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SumAccum] = anon_sym_SumAccum,
  [anon_sym_INT] = anon_sym_INT,
  [anon_sym_FLOAT] = anon_sym_FLOAT,
  [anon_sym_DOUBLE] = anon_sym_DOUBLE,
  [anon_sym_STRING] = anon_sym_STRING,
  [anon_sym_MaxAccum] = anon_sym_MaxAccum,
  [anon_sym_MinAccum] = anon_sym_MinAccum,
  [anon_sym_AvgAccum] = anon_sym_AvgAccum,
  [anon_sym_OrAccum] = anon_sym_OrAccum,
  [anon_sym_AndAccum] = anon_sym_AndAccum,
  [anon_sym_BitwiseorAccum] = anon_sym_BitwiseorAccum,
  [anon_sym_BitwiseandAccum] = anon_sym_BitwiseandAccum,
  [anon_sym_ListAccum] = anon_sym_ListAccum,
  [anon_sym_SetAccum] = anon_sym_SetAccum,
  [anon_sym_BagAccum] = anon_sym_BagAccum,
  [anon_sym_MapAccum] = anon_sym_MapAccum,
  [anon_sym_HeapAccum] = anon_sym_HeapAccum,
  [anon_sym_ASC] = anon_sym_ASC,
  [anon_sym_DESC] = anon_sym_DESC,
  [anon_sym_GroupbyAccum] = anon_sym_GroupbyAccum,
  [anon_sym_ArrayAccum] = anon_sym_ArrayAccum,
  [anon_sym_AT_AT] = anon_sym_AT_AT,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_FILTER] = anon_sym_FILTER,
  [anon_sym_COALESCE] = anon_sym_COALESCE,
  [anon_sym_DISTINCT] = anon_sym_DISTINCT,
  [anon_sym_ISEMPTY] = anon_sym_ISEMPTY,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_NOT] = anon_sym_NOT,
  [anon_sym_IS] = anon_sym_IS,
  [anon_sym_NULL] = anon_sym_NULL,
  [anon_sym_BETWEEN] = anon_sym_BETWEEN,
  [anon_sym_AND] = anon_sym_AND,
  [anon_sym_TRUE] = anon_sym_TRUE,
  [anon_sym_FALSE] = anon_sym_FALSE,
  [anon_sym_LIKE] = anon_sym_LIKE,
  [anon_sym_COUNT] = anon_sym_COUNT,
  [anon_sym_MAX] = anon_sym_MAX,
  [anon_sym_MIN] = anon_sym_MIN,
  [anon_sym_AVG] = anon_sym_AVG,
  [anon_sym_SUM] = anon_sym_SUM,
  [anon_sym_PRINT] = anon_sym_PRINT,
  [anon_sym_TO_CSV] = anon_sym_TO_CSV,
  [anon_sym_AS] = anon_sym_AS,
  [anon_sym_BOOL] = anon_sym_BOOL,
  [anon_sym_UINT] = anon_sym_UINT,
  [anon_sym_VERTEX] = anon_sym_VERTEX,
  [anon_sym_EDGE] = anon_sym_EDGE,
  [anon_sym_JSONOBJECT] = anon_sym_JSONOBJECT,
  [anon_sym_JSONARRAY] = anon_sym_JSONARRAY,
  [anon_sym_DATETIME] = anon_sym_DATETIME,
  [sym_name] = sym_name,
  [anon_sym_GSQL_UINT_MAX] = anon_sym_GSQL_UINT_MAX,
  [anon_sym_GSQL_INT_MAX] = anon_sym_GSQL_INT_MAX,
  [anon_sym_GSQL_UINT_MIN] = anon_sym_GSQL_UINT_MIN,
  [sym_digit] = sym_digit,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_space] = sym_space,
  [sym_string_fragment] = sym_string_fragment,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [sym_newline] = sym_newline,
  [sym_spacing_line] = sym_spacing_line,
  [sym_comment_contents] = sym_comment_contents,
  [anon_sym_SLASH_STAR] = anon_sym_SLASH_STAR,
  [anon_sym_STAR_SLASH] = anon_sym_STAR_SLASH,
  [sym_line_comment] = sym_line_comment,
  [sym_gsql] = sym_gsql,
  [sym__definition] = sym__definition,
  [sym_create_query] = sym_create_query,
  [sym_interpret_query] = sym_interpret_query,
  [sym_parameter_list] = sym_parameter_list,
  [sym_query_params] = sym_query_params,
  [sym_query_param] = sym_query_param,
  [sym_set_param] = sym_set_param,
  [sym_query_body] = sym_query_body,
  [sym_typedef] = sym_typedef,
  [sym_tuple_fields] = sym_tuple_fields,
  [sym_tuple_field] = sym_tuple_field,
  [sym_query_body_stmt] = sym_query_body_stmt,
  [sym_assign_stmt] = sym_assign_stmt,
  [sym_v_set_var_decl_stmt] = sym_v_set_var_decl_stmt,
  [sym_seed_set] = sym_seed_set,
  [sym_seed] = sym_seed,
  [sym_simple_set] = sym_simple_set,
  [sym_l_accum_assign_stmt] = sym_l_accum_assign_stmt,
  [sym_g_accum_assign_stmt] = sym_g_accum_assign_stmt,
  [sym_g_accum_accum_stmt] = sym_g_accum_accum_stmt,
  [sym_func_call_stmt] = sym_func_call_stmt,
  [sym__select_stmt] = sym__select_stmt,
  [sym_gsql_select_block] = sym_gsql_select_block,
  [sym_gsql_select_clause] = sym_gsql_select_clause,
  [sym_from_clause] = sym_from_clause,
  [sym_where_clause] = sym_where_clause,
  [sym_accum_clause] = sym_accum_clause,
  [sym_dml_sub_stmt_list] = sym_dml_sub_stmt_list,
  [sym_dml_sub_stmt] = sym_dml_sub_stmt,
  [sym_l_accum_accum_stmt] = sym_l_accum_accum_stmt,
  [sym_attr_accum_stmt] = sym_attr_accum_stmt,
  [sym_v_accum_func_call] = sym_v_accum_func_call,
  [sym_local_var_decl_stmt] = sym_local_var_decl_stmt,
  [sym_dml_sub_if_stmt] = sym_dml_sub_if_stmt,
  [sym_dml_sub_case_stmt] = sym_dml_sub_case_stmt,
  [sym_dml_sub_while_stmt] = sym_dml_sub_while_stmt,
  [sym_dml_sub_for_each_stmt] = sym_dml_sub_for_each_stmt,
  [sym_for_each_control] = sym_for_each_control,
  [sym_post_accum_clause] = sym_post_accum_clause,
  [sym_limit_clause] = sym_limit_clause,
  [sym_path_pattern] = sym_path_pattern,
  [sym_path_edge_pattern] = sym_path_edge_pattern,
  [sym_atomic_edge_pattern] = sym_atomic_edge_pattern,
  [sym_disj_pattern] = sym_disj_pattern,
  [sym_step] = sym_step,
  [sym_step_v2] = sym_step_v2,
  [sym_step_source_set] = sym_step_source_set,
  [sym_step_edge_set] = sym_step_edge_set,
  [sym_step_edge_types] = sym_step_edge_types,
  [sym_atomic_edge_type] = sym_atomic_edge_type,
  [sym_edge_set_type] = sym_edge_set_type,
  [sym_step_vertex_set] = sym_step_vertex_set,
  [sym_step_vertex_types] = sym_step_vertex_types,
  [sym_atomic_vertex_type] = sym_atomic_vertex_type,
  [sym_vertex_set_type] = sym_vertex_set_type,
  [sym_query_body_case_stmt] = sym_query_body_case_stmt,
  [sym_query_body_if_stmt] = sym_query_body_if_stmt,
  [sym_query_body_while_stmt] = sym_query_body_while_stmt,
  [sym_query_body_for_each_stmt] = sym_query_body_for_each_stmt,
  [sym_decl_stmt] = sym_decl_stmt,
  [sym_base_decl_stmt] = sym_base_decl_stmt,
  [sym_accum_decl_stmt] = sym_accum_decl_stmt,
  [sym_accum_type] = sym_accum_type,
  [sym_global_accum_name] = sym_global_accum_name,
  [sym_local_accum_name] = sym_local_accum_name,
  [sym_arg_list] = sym_arg_list,
  [sym_simple_size] = sym_simple_size,
  [sym_expr] = sym_expr,
  [sym_condition] = sym_condition,
  [sym_set_bag_expr] = sym_set_bag_expr,
  [sym_name_dot] = sym_name_dot,
  [sym_aggregator] = sym_aggregator,
  [sym_print_stmt] = sym_print_stmt,
  [sym_print_expr] = sym_print_expr,
  [sym_v_expr_set] = sym_v_expr_set,
  [sym_v_set_proj] = sym_v_set_proj,
  [sym_file_path] = sym_file_path,
  [sym__type] = sym__type,
  [sym__element_type] = sym__element_type,
  [sym_base_type] = sym_base_type,
  [sym_constant] = sym_constant,
  [sym__numeric] = sym__numeric,
  [sym_integer] = sym_integer,
  [sym_real] = sym_real,
  [sym_string_literal] = sym_string_literal,
  [sym_math_operator] = sym_math_operator,
  [sym_comparison_operator] = sym_comparison_operator,
  [sym_block_comment] = sym_block_comment,
  [aux_sym_gsql_repeat1] = aux_sym_gsql_repeat1,
  [aux_sym_query_params_repeat1] = aux_sym_query_params_repeat1,
  [aux_sym_query_body_repeat1] = aux_sym_query_body_repeat1,
  [aux_sym_typedef_repeat1] = aux_sym_typedef_repeat1,
  [aux_sym_tuple_fields_repeat1] = aux_sym_tuple_fields_repeat1,
  [aux_sym_seed_set_repeat1] = aux_sym_seed_set_repeat1,
  [aux_sym_func_call_stmt_repeat1] = aux_sym_func_call_stmt_repeat1,
  [aux_sym_func_call_stmt_repeat2] = aux_sym_func_call_stmt_repeat2,
  [aux_sym_gsql_select_block_repeat1] = aux_sym_gsql_select_block_repeat1,
  [aux_sym_from_clause_repeat1] = aux_sym_from_clause_repeat1,
  [aux_sym_dml_sub_stmt_list_repeat1] = aux_sym_dml_sub_stmt_list_repeat1,
  [aux_sym_v_accum_func_call_repeat1] = aux_sym_v_accum_func_call_repeat1,
  [aux_sym_dml_sub_if_stmt_repeat1] = aux_sym_dml_sub_if_stmt_repeat1,
  [aux_sym_dml_sub_case_stmt_repeat1] = aux_sym_dml_sub_case_stmt_repeat1,
  [aux_sym_for_each_control_repeat1] = aux_sym_for_each_control_repeat1,
  [aux_sym_path_pattern_repeat1] = aux_sym_path_pattern_repeat1,
  [aux_sym_disj_pattern_repeat1] = aux_sym_disj_pattern_repeat1,
  [aux_sym_step_repeat1] = aux_sym_step_repeat1,
  [aux_sym_step_edge_types_repeat1] = aux_sym_step_edge_types_repeat1,
  [aux_sym_step_vertex_types_repeat1] = aux_sym_step_vertex_types_repeat1,
  [aux_sym_query_body_case_stmt_repeat1] = aux_sym_query_body_case_stmt_repeat1,
  [aux_sym_query_body_case_stmt_repeat2] = aux_sym_query_body_case_stmt_repeat2,
  [aux_sym_query_body_if_stmt_repeat1] = aux_sym_query_body_if_stmt_repeat1,
  [aux_sym_base_decl_stmt_repeat1] = aux_sym_base_decl_stmt_repeat1,
  [aux_sym_accum_decl_stmt_repeat1] = aux_sym_accum_decl_stmt_repeat1,
  [aux_sym_accum_type_repeat1] = aux_sym_accum_type_repeat1,
  [aux_sym_accum_type_repeat2] = aux_sym_accum_type_repeat2,
  [aux_sym_accum_type_repeat3] = aux_sym_accum_type_repeat3,
  [aux_sym_accum_type_repeat4] = aux_sym_accum_type_repeat4,
  [aux_sym_arg_list_repeat1] = aux_sym_arg_list_repeat1,
  [aux_sym_name_dot_repeat1] = aux_sym_name_dot_repeat1,
  [aux_sym_print_stmt_repeat1] = aux_sym_print_stmt_repeat1,
  [aux_sym_v_expr_set_repeat1] = aux_sym_v_expr_set_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
  [aux_sym_block_comment_repeat1] = aux_sym_block_comment_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_CREATE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_OR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_REPLACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DISTRIBUTED] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QUERY] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FOR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GRAPH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SYNTAX] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_V2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_v2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_INTERPRET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TYPEDEF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TUPLE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ANY] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UNION] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_INTERSECT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MINUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SELECT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FROM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WHERE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ACCUM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_IF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_THEN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ELSE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_END] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CASE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WHEN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WHILE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LIMIT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DO] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FOREACH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_IN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RANGE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STEP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POST_DASHACCUM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_OFFSET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SumAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_INT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FLOAT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOUBLE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STRING] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MaxAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MinAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AvgAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_OrAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AndAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BitwiseorAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BitwiseandAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ListAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SetAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BagAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MapAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_HeapAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ASC] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DESC] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GroupbyAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ArrayAccum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FILTER] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COALESCE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DISTINCT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ISEMPTY] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_IS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NULL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BETWEEN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TRUE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FALSE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LIKE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COUNT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MAX] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MIN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AVG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SUM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PRINT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TO_CSV] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BOOL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UINT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VERTEX] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EDGE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_JSONOBJECT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_JSONARRAY] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DATETIME] = {
    .visible = true,
    .named = false,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_GSQL_UINT_MAX] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GSQL_INT_MAX] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GSQL_UINT_MIN] = {
    .visible = true,
    .named = false,
  },
  [sym_digit] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_space] = {
    .visible = true,
    .named = true,
  },
  [sym_string_fragment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_newline] = {
    .visible = true,
    .named = true,
  },
  [sym_spacing_line] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_contents] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SLASH_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_gsql] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_create_query] = {
    .visible = true,
    .named = true,
  },
  [sym_interpret_query] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_query_params] = {
    .visible = true,
    .named = true,
  },
  [sym_query_param] = {
    .visible = true,
    .named = true,
  },
  [sym_set_param] = {
    .visible = true,
    .named = true,
  },
  [sym_query_body] = {
    .visible = true,
    .named = true,
  },
  [sym_typedef] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_fields] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_field] = {
    .visible = true,
    .named = true,
  },
  [sym_query_body_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_assign_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_v_set_var_decl_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_seed_set] = {
    .visible = true,
    .named = true,
  },
  [sym_seed] = {
    .visible = true,
    .named = true,
  },
  [sym_simple_set] = {
    .visible = true,
    .named = true,
  },
  [sym_l_accum_assign_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_g_accum_assign_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_g_accum_accum_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_func_call_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym__select_stmt] = {
    .visible = false,
    .named = true,
  },
  [sym_gsql_select_block] = {
    .visible = true,
    .named = true,
  },
  [sym_gsql_select_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_from_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_where_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_accum_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_dml_sub_stmt_list] = {
    .visible = true,
    .named = true,
  },
  [sym_dml_sub_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_l_accum_accum_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_attr_accum_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_v_accum_func_call] = {
    .visible = true,
    .named = true,
  },
  [sym_local_var_decl_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_dml_sub_if_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_dml_sub_case_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_dml_sub_while_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_dml_sub_for_each_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_for_each_control] = {
    .visible = true,
    .named = true,
  },
  [sym_post_accum_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_path_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_path_edge_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_atomic_edge_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_disj_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_step] = {
    .visible = true,
    .named = true,
  },
  [sym_step_v2] = {
    .visible = true,
    .named = true,
  },
  [sym_step_source_set] = {
    .visible = true,
    .named = true,
  },
  [sym_step_edge_set] = {
    .visible = true,
    .named = true,
  },
  [sym_step_edge_types] = {
    .visible = true,
    .named = true,
  },
  [sym_atomic_edge_type] = {
    .visible = true,
    .named = true,
  },
  [sym_edge_set_type] = {
    .visible = true,
    .named = true,
  },
  [sym_step_vertex_set] = {
    .visible = true,
    .named = true,
  },
  [sym_step_vertex_types] = {
    .visible = true,
    .named = true,
  },
  [sym_atomic_vertex_type] = {
    .visible = true,
    .named = true,
  },
  [sym_vertex_set_type] = {
    .visible = true,
    .named = true,
  },
  [sym_query_body_case_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_query_body_if_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_query_body_while_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_query_body_for_each_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_decl_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_base_decl_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_accum_decl_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_accum_type] = {
    .visible = true,
    .named = true,
  },
  [sym_global_accum_name] = {
    .visible = true,
    .named = true,
  },
  [sym_local_accum_name] = {
    .visible = true,
    .named = true,
  },
  [sym_arg_list] = {
    .visible = true,
    .named = true,
  },
  [sym_simple_size] = {
    .visible = true,
    .named = true,
  },
  [sym_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_condition] = {
    .visible = true,
    .named = true,
  },
  [sym_set_bag_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_name_dot] = {
    .visible = true,
    .named = true,
  },
  [sym_aggregator] = {
    .visible = true,
    .named = true,
  },
  [sym_print_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_print_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_v_expr_set] = {
    .visible = true,
    .named = true,
  },
  [sym_v_set_proj] = {
    .visible = true,
    .named = true,
  },
  [sym_file_path] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym__element_type] = {
    .visible = false,
    .named = true,
  },
  [sym_base_type] = {
    .visible = true,
    .named = true,
  },
  [sym_constant] = {
    .visible = true,
    .named = true,
  },
  [sym__numeric] = {
    .visible = false,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_real] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_math_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_comparison_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_gsql_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_query_params_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_query_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_typedef_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tuple_fields_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_seed_set_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_func_call_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_func_call_stmt_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_gsql_select_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_from_clause_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dml_sub_stmt_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_v_accum_func_call_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dml_sub_if_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dml_sub_case_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_for_each_control_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_pattern_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_disj_pattern_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_step_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_step_edge_types_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_step_vertex_types_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_query_body_case_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_query_body_case_stmt_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_query_body_if_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_base_decl_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_accum_decl_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_accum_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_accum_type_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_accum_type_repeat3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_accum_type_repeat4] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arg_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_name_dot_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_print_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_v_expr_set_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_comment_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_alias = 1,
  field_edgeAlias = 2,
  field_funcName = 3,
  field_graphName = 4,
  field_iterationVar = 5,
  field_keyVar = 6,
  field_localAccumName = 7,
  field_plus_equal = 8,
  field_queryName = 9,
  field_tupleType = 10,
  field_valueVar = 11,
  field_varName = 12,
  field_vertexAlias = 13,
  field_vertexSetName = 14,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_edgeAlias] = "edgeAlias",
  [field_funcName] = "funcName",
  [field_graphName] = "graphName",
  [field_iterationVar] = "iterationVar",
  [field_keyVar] = "keyVar",
  [field_localAccumName] = "localAccumName",
  [field_plus_equal] = "plus_equal",
  [field_queryName] = "queryName",
  [field_tupleType] = "tupleType",
  [field_valueVar] = "valueVar",
  [field_varName] = "varName",
  [field_vertexAlias] = "vertexAlias",
  [field_vertexSetName] = "vertexSetName",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 2},
  [8] = {.index = 8, .length = 1},
  [9] = {.index = 9, .length = 2},
  [10] = {.index = 11, .length = 1},
  [11] = {.index = 12, .length = 2},
  [12] = {.index = 14, .length = 2},
  [13] = {.index = 16, .length = 1},
  [14] = {.index = 17, .length = 2},
  [15] = {.index = 19, .length = 1},
  [16] = {.index = 20, .length = 2},
  [17] = {.index = 22, .length = 2},
  [18] = {.index = 24, .length = 1},
  [19] = {.index = 25, .length = 2},
  [20] = {.index = 27, .length = 3},
  [21] = {.index = 30, .length = 1},
  [22] = {.index = 31, .length = 2},
  [23] = {.index = 33, .length = 1},
  [24] = {.index = 34, .length = 1},
  [25] = {.index = 35, .length = 2},
  [26] = {.index = 37, .length = 1},
  [27] = {.index = 38, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_vertexSetName, 0},
  [1] =
    {field_plus_equal, 1},
  [2] =
    {field_graphName, 5},
  [3] =
    {field_iterationVar, 0},
  [4] =
    {field_alias, 3},
  [5] =
    {field_edgeAlias, 1, .inherited = true},
  [6] =
    {field_graphName, 6},
    {field_queryName, 2},
  [8] =
    {field_valueVar, 1},
  [9] =
    {field_valueVar, 0, .inherited = true},
    {field_valueVar, 1, .inherited = true},
  [11] =
    {field_vertexAlias, 0},
  [12] =
    {field_vertexAlias, 2},
    {field_vertexSetName, 0},
  [14] =
    {field_edgeAlias, 0, .inherited = true},
    {field_edgeAlias, 1, .inherited = true},
  [16] =
    {field_vertexAlias, 2},
  [17] =
    {field_graphName, 7},
    {field_queryName, 3},
  [19] =
    {field_tupleType, 4},
  [20] =
    {field_localAccumName, 2},
    {field_vertexAlias, 0},
  [22] =
    {field_graphName, 8},
    {field_queryName, 4},
  [24] =
    {field_tupleType, 5},
  [25] =
    {field_keyVar, 1},
    {field_valueVar, 2, .inherited = true},
  [27] =
    {field_funcName, 3, .inherited = true},
    {field_localAccumName, 2},
    {field_vertexAlias, 0},
  [30] =
    {field_varName, 1},
  [31] =
    {field_graphName, 9},
    {field_queryName, 5},
  [33] =
    {field_edgeAlias, 2},
  [34] =
    {field_plus_equal, 3},
  [35] =
    {field_funcName, 0, .inherited = true},
    {field_funcName, 1, .inherited = true},
  [37] =
    {field_funcName, 1},
  [38] =
    {field_edgeAlias, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 19,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 28,
  [43] = 43,
  [44] = 31,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 73,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 88,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 91,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 97,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 113,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 115,
  [120] = 120,
  [121] = 105,
  [122] = 103,
  [123] = 106,
  [124] = 124,
  [125] = 125,
  [126] = 106,
  [127] = 120,
  [128] = 128,
  [129] = 90,
  [130] = 106,
  [131] = 99,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 73,
  [140] = 132,
  [141] = 141,
  [142] = 133,
  [143] = 141,
  [144] = 138,
  [145] = 18,
  [146] = 27,
  [147] = 147,
  [148] = 24,
  [149] = 20,
  [150] = 23,
  [151] = 151,
  [152] = 151,
  [153] = 25,
  [154] = 154,
  [155] = 155,
  [156] = 26,
  [157] = 157,
  [158] = 151,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 22,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 21,
  [169] = 169,
  [170] = 170,
  [171] = 19,
  [172] = 167,
  [173] = 167,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 157,
  [178] = 167,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 151,
  [187] = 187,
  [188] = 188,
  [189] = 28,
  [190] = 190,
  [191] = 31,
  [192] = 17,
  [193] = 134,
  [194] = 29,
  [195] = 137,
  [196] = 30,
  [197] = 32,
  [198] = 198,
  [199] = 199,
  [200] = 35,
  [201] = 33,
  [202] = 36,
  [203] = 198,
  [204] = 34,
  [205] = 38,
  [206] = 39,
  [207] = 19,
  [208] = 40,
  [209] = 41,
  [210] = 137,
  [211] = 48,
  [212] = 46,
  [213] = 31,
  [214] = 134,
  [215] = 28,
  [216] = 43,
  [217] = 45,
  [218] = 47,
  [219] = 52,
  [220] = 65,
  [221] = 53,
  [222] = 62,
  [223] = 51,
  [224] = 59,
  [225] = 66,
  [226] = 57,
  [227] = 55,
  [228] = 56,
  [229] = 50,
  [230] = 63,
  [231] = 160,
  [232] = 49,
  [233] = 58,
  [234] = 67,
  [235] = 61,
  [236] = 60,
  [237] = 64,
  [238] = 54,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 73,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 260,
  [261] = 261,
  [262] = 262,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 266,
  [267] = 267,
  [268] = 268,
  [269] = 269,
  [270] = 270,
  [271] = 271,
  [272] = 271,
  [273] = 273,
  [274] = 274,
  [275] = 199,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 279,
  [280] = 280,
  [281] = 281,
  [282] = 282,
  [283] = 283,
  [284] = 284,
  [285] = 285,
  [286] = 134,
  [287] = 287,
  [288] = 288,
  [289] = 137,
  [290] = 283,
  [291] = 291,
  [292] = 292,
  [293] = 291,
  [294] = 294,
  [295] = 295,
  [296] = 296,
  [297] = 297,
  [298] = 298,
  [299] = 30,
  [300] = 300,
  [301] = 301,
  [302] = 302,
  [303] = 303,
  [304] = 304,
  [305] = 305,
  [306] = 306,
  [307] = 307,
  [308] = 308,
  [309] = 309,
  [310] = 310,
  [311] = 311,
  [312] = 312,
  [313] = 313,
  [314] = 314,
  [315] = 315,
  [316] = 316,
  [317] = 317,
  [318] = 318,
  [319] = 319,
  [320] = 320,
  [321] = 321,
  [322] = 322,
  [323] = 323,
  [324] = 324,
  [325] = 325,
  [326] = 326,
  [327] = 327,
  [328] = 328,
  [329] = 329,
  [330] = 330,
  [331] = 331,
  [332] = 332,
  [333] = 333,
  [334] = 334,
  [335] = 335,
  [336] = 336,
  [337] = 337,
  [338] = 338,
  [339] = 339,
  [340] = 340,
  [341] = 341,
  [342] = 342,
  [343] = 343,
  [344] = 344,
  [345] = 345,
  [346] = 346,
  [347] = 347,
  [348] = 348,
  [349] = 349,
  [350] = 350,
  [351] = 351,
  [352] = 352,
  [353] = 353,
  [354] = 354,
  [355] = 355,
  [356] = 349,
  [357] = 357,
  [358] = 358,
  [359] = 359,
  [360] = 360,
  [361] = 361,
  [362] = 362,
  [363] = 363,
  [364] = 364,
  [365] = 365,
  [366] = 366,
  [367] = 367,
  [368] = 368,
  [369] = 369,
  [370] = 370,
  [371] = 371,
  [372] = 372,
  [373] = 373,
  [374] = 374,
  [375] = 375,
  [376] = 376,
  [377] = 377,
  [378] = 378,
  [379] = 379,
  [380] = 380,
  [381] = 381,
  [382] = 382,
  [383] = 383,
  [384] = 384,
  [385] = 385,
  [386] = 386,
  [387] = 387,
  [388] = 381,
  [389] = 389,
  [390] = 390,
  [391] = 391,
  [392] = 392,
  [393] = 393,
  [394] = 378,
  [395] = 395,
  [396] = 396,
  [397] = 382,
  [398] = 398,
  [399] = 399,
  [400] = 400,
  [401] = 401,
  [402] = 402,
  [403] = 403,
  [404] = 404,
  [405] = 405,
  [406] = 406,
  [407] = 407,
  [408] = 408,
  [409] = 409,
  [410] = 410,
  [411] = 411,
  [412] = 412,
  [413] = 413,
  [414] = 414,
  [415] = 415,
  [416] = 416,
  [417] = 17,
  [418] = 418,
  [419] = 419,
  [420] = 420,
  [421] = 421,
  [422] = 422,
  [423] = 423,
  [424] = 424,
  [425] = 425,
  [426] = 426,
  [427] = 427,
  [428] = 428,
  [429] = 429,
  [430] = 430,
  [431] = 431,
  [432] = 432,
  [433] = 433,
  [434] = 434,
  [435] = 435,
  [436] = 436,
  [437] = 437,
  [438] = 438,
  [439] = 439,
  [440] = 440,
  [441] = 441,
  [442] = 442,
  [443] = 443,
  [444] = 444,
  [445] = 445,
  [446] = 446,
  [447] = 447,
  [448] = 448,
  [449] = 449,
  [450] = 450,
  [451] = 451,
  [452] = 452,
  [453] = 453,
  [454] = 454,
  [455] = 455,
  [456] = 456,
  [457] = 457,
  [458] = 458,
  [459] = 459,
  [460] = 460,
  [461] = 461,
  [462] = 462,
  [463] = 463,
  [464] = 442,
  [465] = 447,
  [466] = 466,
  [467] = 467,
  [468] = 468,
  [469] = 263,
  [470] = 470,
  [471] = 438,
  [472] = 472,
  [473] = 473,
  [474] = 446,
  [475] = 475,
  [476] = 476,
  [477] = 477,
  [478] = 478,
  [479] = 479,
  [480] = 480,
  [481] = 481,
  [482] = 270,
  [483] = 483,
  [484] = 484,
  [485] = 485,
  [486] = 486,
  [487] = 487,
  [488] = 488,
  [489] = 489,
  [490] = 490,
  [491] = 491,
  [492] = 492,
  [493] = 493,
  [494] = 494,
  [495] = 495,
  [496] = 496,
  [497] = 497,
  [498] = 498,
  [499] = 499,
  [500] = 500,
  [501] = 501,
  [502] = 502,
  [503] = 503,
  [504] = 504,
  [505] = 483,
  [506] = 506,
  [507] = 507,
  [508] = 508,
  [509] = 509,
  [510] = 501,
  [511] = 511,
  [512] = 512,
  [513] = 513,
  [514] = 514,
  [515] = 515,
  [516] = 516,
  [517] = 517,
  [518] = 518,
  [519] = 519,
  [520] = 520,
  [521] = 521,
  [522] = 522,
  [523] = 523,
  [524] = 524,
  [525] = 525,
  [526] = 526,
  [527] = 527,
  [528] = 528,
  [529] = 529,
  [530] = 530,
  [531] = 531,
  [532] = 532,
  [533] = 68,
  [534] = 534,
  [535] = 535,
  [536] = 536,
  [537] = 537,
  [538] = 538,
  [539] = 516,
  [540] = 540,
  [541] = 541,
  [542] = 542,
  [543] = 543,
  [544] = 544,
  [545] = 545,
  [546] = 546,
  [547] = 547,
  [548] = 548,
  [549] = 549,
  [550] = 550,
  [551] = 280,
  [552] = 552,
  [553] = 515,
  [554] = 554,
  [555] = 555,
  [556] = 556,
  [557] = 557,
  [558] = 558,
  [559] = 559,
  [560] = 560,
  [561] = 561,
  [562] = 562,
  [563] = 528,
  [564] = 564,
  [565] = 565,
  [566] = 566,
  [567] = 567,
  [568] = 568,
  [569] = 569,
  [570] = 570,
  [571] = 571,
  [572] = 531,
  [573] = 573,
  [574] = 574,
  [575] = 478,
  [576] = 576,
  [577] = 577,
  [578] = 578,
  [579] = 554,
  [580] = 580,
  [581] = 581,
  [582] = 582,
  [583] = 583,
  [584] = 584,
  [585] = 585,
  [586] = 586,
  [587] = 587,
  [588] = 588,
  [589] = 589,
  [590] = 590,
  [591] = 591,
  [592] = 592,
  [593] = 593,
  [594] = 594,
  [595] = 595,
  [596] = 596,
  [597] = 597,
  [598] = 598,
  [599] = 599,
  [600] = 600,
  [601] = 601,
  [602] = 602,
  [603] = 603,
  [604] = 604,
  [605] = 605,
  [606] = 606,
  [607] = 607,
  [608] = 608,
  [609] = 609,
  [610] = 610,
  [611] = 611,
  [612] = 612,
  [613] = 613,
  [614] = 614,
  [615] = 615,
  [616] = 599,
  [617] = 617,
  [618] = 618,
  [619] = 619,
  [620] = 620,
  [621] = 621,
  [622] = 622,
  [623] = 623,
  [624] = 624,
  [625] = 625,
  [626] = 626,
  [627] = 627,
  [628] = 628,
  [629] = 629,
  [630] = 630,
  [631] = 631,
  [632] = 409,
  [633] = 411,
  [634] = 634,
  [635] = 635,
  [636] = 636,
  [637] = 637,
  [638] = 638,
  [639] = 639,
  [640] = 640,
  [641] = 17,
  [642] = 634,
  [643] = 643,
  [644] = 644,
  [645] = 629,
  [646] = 603,
  [647] = 647,
  [648] = 648,
  [649] = 649,
  [650] = 650,
  [651] = 651,
  [652] = 652,
  [653] = 653,
  [654] = 654,
  [655] = 655,
  [656] = 656,
  [657] = 657,
  [658] = 658,
  [659] = 659,
  [660] = 660,
  [661] = 661,
  [662] = 662,
  [663] = 663,
  [664] = 664,
  [665] = 665,
  [666] = 666,
  [667] = 667,
  [668] = 668,
  [669] = 669,
  [670] = 670,
  [671] = 671,
  [672] = 672,
  [673] = 673,
  [674] = 674,
  [675] = 675,
  [676] = 676,
  [677] = 677,
  [678] = 678,
  [679] = 679,
  [680] = 680,
  [681] = 681,
  [682] = 682,
  [683] = 683,
  [684] = 684,
  [685] = 685,
  [686] = 686,
  [687] = 687,
  [688] = 688,
  [689] = 689,
  [690] = 690,
  [691] = 691,
  [692] = 692,
  [693] = 693,
  [694] = 694,
  [695] = 695,
  [696] = 696,
  [697] = 697,
  [698] = 698,
  [699] = 699,
  [700] = 700,
  [701] = 701,
  [702] = 702,
  [703] = 703,
  [704] = 704,
  [705] = 705,
  [706] = 706,
  [707] = 707,
  [708] = 708,
  [709] = 709,
  [710] = 710,
  [711] = 711,
  [712] = 712,
  [713] = 713,
  [714] = 714,
  [715] = 715,
  [716] = 716,
  [717] = 717,
  [718] = 718,
  [719] = 719,
  [720] = 720,
  [721] = 721,
  [722] = 722,
  [723] = 723,
  [724] = 724,
  [725] = 725,
  [726] = 726,
  [727] = 727,
  [728] = 728,
  [729] = 729,
  [730] = 730,
  [731] = 731,
  [732] = 732,
  [733] = 733,
  [734] = 734,
  [735] = 735,
  [736] = 736,
  [737] = 737,
  [738] = 738,
  [739] = 739,
  [740] = 740,
  [741] = 741,
  [742] = 742,
  [743] = 743,
  [744] = 744,
  [745] = 745,
  [746] = 746,
  [747] = 747,
  [748] = 748,
  [749] = 749,
  [750] = 750,
  [751] = 751,
  [752] = 752,
  [753] = 753,
  [754] = 754,
  [755] = 755,
  [756] = 756,
  [757] = 757,
  [758] = 758,
  [759] = 759,
  [760] = 760,
  [761] = 761,
  [762] = 762,
  [763] = 763,
  [764] = 764,
  [765] = 749,
  [766] = 766,
  [767] = 767,
  [768] = 768,
  [769] = 769,
  [770] = 770,
  [771] = 771,
  [772] = 772,
  [773] = 773,
  [774] = 774,
  [775] = 775,
  [776] = 776,
  [777] = 777,
  [778] = 778,
  [779] = 779,
  [780] = 780,
  [781] = 781,
  [782] = 782,
  [783] = 783,
  [784] = 784,
  [785] = 785,
  [786] = 786,
  [787] = 787,
  [788] = 788,
  [789] = 789,
  [790] = 790,
  [791] = 791,
  [792] = 792,
  [793] = 793,
  [794] = 794,
  [795] = 795,
  [796] = 796,
  [797] = 797,
  [798] = 790,
  [799] = 789,
  [800] = 785,
  [801] = 801,
  [802] = 802,
  [803] = 803,
  [804] = 804,
  [805] = 805,
  [806] = 806,
  [807] = 807,
  [808] = 721,
  [809] = 809,
  [810] = 810,
  [811] = 811,
  [812] = 714,
  [813] = 813,
  [814] = 707,
  [815] = 815,
  [816] = 816,
  [817] = 664,
  [818] = 665,
  [819] = 819,
  [820] = 773,
  [821] = 776,
  [822] = 822,
  [823] = 823,
  [824] = 824,
  [825] = 825,
  [826] = 726,
  [827] = 827,
  [828] = 806,
  [829] = 801,
  [830] = 830,
  [831] = 830,
  [832] = 777,
  [833] = 739,
  [834] = 834,
  [835] = 835,
  [836] = 671,
  [837] = 697,
  [838] = 669,
  [839] = 839,
  [840] = 840,
  [841] = 841,
  [842] = 842,
  [843] = 790,
  [844] = 789,
  [845] = 845,
  [846] = 846,
  [847] = 830,
  [848] = 790,
  [849] = 849,
  [850] = 715,
  [851] = 830,
  [852] = 852,
  [853] = 853,
  [854] = 759,
  [855] = 755,
  [856] = 856,
  [857] = 740,
  [858] = 858,
  [859] = 859,
  [860] = 729,
  [861] = 861,
  [862] = 862,
  [863] = 853,
  [864] = 834,
  [865] = 865,
  [866] = 866,
  [867] = 729,
  [868] = 729,
  [869] = 758,
  [870] = 753,
  [871] = 737,
  [872] = 872,
  [873] = 873,
  [874] = 674,
  [875] = 654,
  [876] = 737,
  [877] = 737,
  [878] = 878,
  [879] = 879,
  [880] = 880,
};

static inline bool sym_name_character_set_1(int32_t c) {
  return (c < 6656
    ? (c < 2979
      ? (c < 2308
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < 'a'
                ? (c < 'K'
                  ? c == '$'
                  : (c <= 'Z' || c == '_'))
                : (c <= 'z' || (c < 181
                  ? c == 170
                  : c <= 181)))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1765
              ? (c < 1646
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1808
                ? (c < 1786
                  ? (c >= 1774 && c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1994 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2160
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : c <= 2154)
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2417
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : c <= 2448)))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2544 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2649
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : c <= 2617)
                : (c <= 2652 || (c < 2674
                  ? c == 2654
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2866
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2831
                ? (c < 2809
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2949
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2969
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 4159
        ? (c < 3412
          ? (c < 3214
            ? (c < 3114
              ? (c < 3077
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : c <= 3112)))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3313
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3314 || (c < 3346
                ? (c < 3342
                  ? (c >= 3332 && c <= 3340)
                  : c <= 3344)
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3724
            ? (c < 3520
              ? (c < 3482
                ? (c < 3450
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))
                : (c <= 3505 || (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : c <= 3517)))
              : (c <= 3526 || (c < 3713
                ? (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : (c <= 3635 || (c >= 3648 && c <= 3654)))
                : (c <= 3714 || (c < 3718
                  ? c == 3716
                  : c <= 3722)))))
            : (c <= 3747 || (c < 3804
              ? (c < 3773
                ? (c < 3751
                  ? c == 3749
                  : (c <= 3760 || (c >= 3762 && c <= 3763)))
                : (c <= 3773 || (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : c <= 3782)))
              : (c <= 3807 || (c < 3913
                ? (c < 3904
                  ? c == 3840
                  : c <= 3911)
                : (c <= 3948 || (c < 4096
                  ? (c >= 3976 && c <= 3980)
                  : c <= 4138)))))))))
        : (c <= 4159 || (c < 4888
          ? (c < 4688
            ? (c < 4238
              ? (c < 4197
                ? (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : (c <= 4189 || c == 4193))
                : (c <= 4198 || (c < 4213
                  ? (c >= 4206 && c <= 4208)
                  : c <= 4225)))
              : (c <= 4238 || (c < 4304
                ? (c < 4295
                  ? (c >= 4256 && c <= 4293)
                  : (c <= 4295 || c == 4301))
                : (c <= 4346 || (c < 4682
                  ? (c >= 4348 && c <= 4680)
                  : c <= 4685)))))
            : (c <= 4694 || (c < 4792
              ? (c < 4746
                ? (c < 4698
                  ? c == 4696
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))
                : (c <= 4749 || (c < 4786
                  ? (c >= 4752 && c <= 4784)
                  : c <= 4789)))
              : (c <= 4798 || (c < 4808
                ? (c < 4802
                  ? c == 4800
                  : c <= 4805)
                : (c <= 4822 || (c < 4882
                  ? (c >= 4824 && c <= 4880)
                  : c <= 4885)))))))
          : (c <= 4954 || (c < 6016
            ? (c < 5792
              ? (c < 5121
                ? (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : (c <= 5109 || (c >= 5112 && c <= 5117)))
                : (c <= 5740 || (c < 5761
                  ? (c >= 5743 && c <= 5759)
                  : c <= 5786)))
              : (c <= 5866 || (c < 5952
                ? (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))
                : (c <= 5969 || (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : c <= 6000)))))
            : (c <= 6067 || (c < 6320
              ? (c < 6272
                ? (c < 6108
                  ? c == 6103
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))
              : (c <= 6389 || (c < 6512
                ? (c < 6480
                  ? (c >= 6400 && c <= 6430)
                  : c <= 6509)
                : (c <= 6516 || (c < 6576
                  ? (c >= 6528 && c <= 6571)
                  : c <= 6601)))))))))))))
    : (c <= 6678 || (c < 43259
      ? (c < 8579
        ? (c < 8031
          ? (c < 7401
            ? (c < 7098
              ? (c < 6981
                ? (c < 6823
                  ? (c >= 6688 && c <= 6740)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7086
                  ? (c >= 7043 && c <= 7072)
                  : c <= 7087)))
              : (c <= 7141 || (c < 7296
                ? (c < 7245
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 7968
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))
              : (c <= 8005 || (c < 8025
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : c <= 8023)
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))))))
          : (c <= 8061 || (c < 8450
            ? (c < 8150
              ? (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))
              : (c <= 8155 || (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))))
            : (c <= 8450 || (c < 8488
              ? (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))
              : (c <= 8488 || (c < 8508
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : c <= 8505)
                : (c <= 8511 || (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : c <= 8526)))))))))
        : (c <= 8580 || (c < 12593
          ? (c < 11712
            ? (c < 11568
              ? (c < 11520
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : c <= 11565)))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12347
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12337
                  ? (c >= 12293 && c <= 12294)
                  : c <= 12341)))
              : (c <= 12348 || (c < 12449
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)
                : (c <= 12538 || (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : c <= 12591)))))))
          : (c <= 12686 || (c < 42775
            ? (c < 42192
              ? (c < 19903
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || c == 13312))
                : (c <= 19903 || (c < 40959
                  ? c == 19968
                  : c <= 42124)))
              : (c <= 42237 || (c < 42560
                ? (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : c <= 42725)))))
            : (c <= 42783 || (c < 43011
              ? (c < 42963
                ? (c < 42891
                  ? (c >= 42786 && c <= 42888)
                  : (c <= 42954 || (c >= 42960 && c <= 42961)))
                : (c <= 42963 || (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : c <= 43009)))
              : (c <= 43013 || (c < 43072
                ? (c < 43020
                  ? (c >= 43015 && c <= 43018)
                  : c <= 43042)
                : (c <= 43123 || (c < 43250
                  ? (c >= 43138 && c <= 43187)
                  : c <= 43255)))))))))))
      : (c <= 43259 || (c < 65313
        ? (c < 43808
          ? (c < 43642
            ? (c < 43488
              ? (c < 43360
                ? (c < 43274
                  ? (c >= 43261 && c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43471
                  ? (c >= 43396 && c <= 43442)
                  : c <= 43471)))
              : (c <= 43492 || (c < 43584
                ? (c < 43514
                  ? (c >= 43494 && c <= 43503)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43616
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43638)))))
            : (c <= 43642 || (c < 43739
              ? (c < 43705
                ? (c < 43697
                  ? (c >= 43646 && c <= 43695)
                  : (c <= 43697 || (c >= 43701 && c <= 43702)))
                : (c <= 43709 || (c < 43714
                  ? c == 43712
                  : c <= 43714)))
              : (c <= 43741 || (c < 43777
                ? (c < 43762
                  ? (c >= 43744 && c <= 43754)
                  : c <= 43764)
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55203
                  ? c == 44032
                  : c <= 55203)))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64467
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : c <= 64433)))
              : (c <= 64829 || (c < 65008
                ? (c < 64914
                  ? (c >= 64848 && c <= 64911)
                  : c <= 64967)
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65338 || (c < 66864
          ? (c < 66176
            ? (c < 65536
              ? (c < 65482
                ? (c < 65382
                  ? (c >= 65345 && c <= 65370)
                  : (c <= 65470 || (c >= 65474 && c <= 65479)))
                : (c <= 65487 || (c < 65498
                  ? (c >= 65490 && c <= 65495)
                  : c <= 65500)))
              : (c <= 65547 || (c < 65599
                ? (c < 65576
                  ? (c >= 65549 && c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))
                : (c <= 65613 || (c < 65664
                  ? (c >= 65616 && c <= 65629)
                  : c <= 65786)))))
            : (c <= 66204 || (c < 66464
              ? (c < 66370
                ? (c < 66304
                  ? (c >= 66208 && c <= 66256)
                  : (c <= 66335 || (c >= 66349 && c <= 66368)))
                : (c <= 66377 || (c < 66432
                  ? (c >= 66384 && c <= 66421)
                  : c <= 66461)))
              : (c <= 66499 || (c < 66736
                ? (c < 66560
                  ? (c >= 66504 && c <= 66511)
                  : c <= 66717)
                : (c <= 66771 || (c < 66816
                  ? (c >= 66776 && c <= 66811)
                  : c <= 66855)))))))
          : (c <= 66915 || (c < 67506
            ? (c < 66995
              ? (c < 66964
                ? (c < 66940
                  ? (c >= 66928 && c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))
                : (c <= 66965 || (c < 66979
                  ? (c >= 66967 && c <= 66977)
                  : c <= 66993)))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67680
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67808
                  ? (c >= 67712 && c <= 67742)
                  : c <= 67826)
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_name_character_set_2(int32_t c) {
  return (c < 6656
    ? (c < 2979
      ? (c < 2308
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < 'a'
                ? (c < 'A'
                  ? c == '$'
                  : (c <= 'Z' || c == '_'))
                : (c <= 'z' || (c < 181
                  ? c == 170
                  : c <= 181)))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1765
              ? (c < 1646
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1808
                ? (c < 1786
                  ? (c >= 1774 && c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1994 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2160
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : c <= 2154)
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2417
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : c <= 2448)))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2544 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2649
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : c <= 2617)
                : (c <= 2652 || (c < 2674
                  ? c == 2654
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2866
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2831
                ? (c < 2809
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2949
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2969
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 4159
        ? (c < 3412
          ? (c < 3214
            ? (c < 3114
              ? (c < 3077
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : c <= 3112)))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3313
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3314 || (c < 3346
                ? (c < 3342
                  ? (c >= 3332 && c <= 3340)
                  : c <= 3344)
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3724
            ? (c < 3520
              ? (c < 3482
                ? (c < 3450
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))
                : (c <= 3505 || (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : c <= 3517)))
              : (c <= 3526 || (c < 3713
                ? (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : (c <= 3635 || (c >= 3648 && c <= 3654)))
                : (c <= 3714 || (c < 3718
                  ? c == 3716
                  : c <= 3722)))))
            : (c <= 3747 || (c < 3804
              ? (c < 3773
                ? (c < 3751
                  ? c == 3749
                  : (c <= 3760 || (c >= 3762 && c <= 3763)))
                : (c <= 3773 || (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : c <= 3782)))
              : (c <= 3807 || (c < 3913
                ? (c < 3904
                  ? c == 3840
                  : c <= 3911)
                : (c <= 3948 || (c < 4096
                  ? (c >= 3976 && c <= 3980)
                  : c <= 4138)))))))))
        : (c <= 4159 || (c < 4888
          ? (c < 4688
            ? (c < 4238
              ? (c < 4197
                ? (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : (c <= 4189 || c == 4193))
                : (c <= 4198 || (c < 4213
                  ? (c >= 4206 && c <= 4208)
                  : c <= 4225)))
              : (c <= 4238 || (c < 4304
                ? (c < 4295
                  ? (c >= 4256 && c <= 4293)
                  : (c <= 4295 || c == 4301))
                : (c <= 4346 || (c < 4682
                  ? (c >= 4348 && c <= 4680)
                  : c <= 4685)))))
            : (c <= 4694 || (c < 4792
              ? (c < 4746
                ? (c < 4698
                  ? c == 4696
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))
                : (c <= 4749 || (c < 4786
                  ? (c >= 4752 && c <= 4784)
                  : c <= 4789)))
              : (c <= 4798 || (c < 4808
                ? (c < 4802
                  ? c == 4800
                  : c <= 4805)
                : (c <= 4822 || (c < 4882
                  ? (c >= 4824 && c <= 4880)
                  : c <= 4885)))))))
          : (c <= 4954 || (c < 6016
            ? (c < 5792
              ? (c < 5121
                ? (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : (c <= 5109 || (c >= 5112 && c <= 5117)))
                : (c <= 5740 || (c < 5761
                  ? (c >= 5743 && c <= 5759)
                  : c <= 5786)))
              : (c <= 5866 || (c < 5952
                ? (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))
                : (c <= 5969 || (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : c <= 6000)))))
            : (c <= 6067 || (c < 6320
              ? (c < 6272
                ? (c < 6108
                  ? c == 6103
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))
              : (c <= 6389 || (c < 6512
                ? (c < 6480
                  ? (c >= 6400 && c <= 6430)
                  : c <= 6509)
                : (c <= 6516 || (c < 6576
                  ? (c >= 6528 && c <= 6571)
                  : c <= 6601)))))))))))))
    : (c <= 6678 || (c < 43259
      ? (c < 8579
        ? (c < 8031
          ? (c < 7401
            ? (c < 7098
              ? (c < 6981
                ? (c < 6823
                  ? (c >= 6688 && c <= 6740)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7086
                  ? (c >= 7043 && c <= 7072)
                  : c <= 7087)))
              : (c <= 7141 || (c < 7296
                ? (c < 7245
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 7968
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))
              : (c <= 8005 || (c < 8025
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : c <= 8023)
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))))))
          : (c <= 8061 || (c < 8450
            ? (c < 8150
              ? (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))
              : (c <= 8155 || (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))))
            : (c <= 8450 || (c < 8488
              ? (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))
              : (c <= 8488 || (c < 8508
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : c <= 8505)
                : (c <= 8511 || (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : c <= 8526)))))))))
        : (c <= 8580 || (c < 12593
          ? (c < 11712
            ? (c < 11568
              ? (c < 11520
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : c <= 11565)))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12347
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12337
                  ? (c >= 12293 && c <= 12294)
                  : c <= 12341)))
              : (c <= 12348 || (c < 12449
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)
                : (c <= 12538 || (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : c <= 12591)))))))
          : (c <= 12686 || (c < 42775
            ? (c < 42192
              ? (c < 19903
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || c == 13312))
                : (c <= 19903 || (c < 40959
                  ? c == 19968
                  : c <= 42124)))
              : (c <= 42237 || (c < 42560
                ? (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : c <= 42725)))))
            : (c <= 42783 || (c < 43011
              ? (c < 42963
                ? (c < 42891
                  ? (c >= 42786 && c <= 42888)
                  : (c <= 42954 || (c >= 42960 && c <= 42961)))
                : (c <= 42963 || (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : c <= 43009)))
              : (c <= 43013 || (c < 43072
                ? (c < 43020
                  ? (c >= 43015 && c <= 43018)
                  : c <= 43042)
                : (c <= 43123 || (c < 43250
                  ? (c >= 43138 && c <= 43187)
                  : c <= 43255)))))))))))
      : (c <= 43259 || (c < 65313
        ? (c < 43808
          ? (c < 43642
            ? (c < 43488
              ? (c < 43360
                ? (c < 43274
                  ? (c >= 43261 && c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43471
                  ? (c >= 43396 && c <= 43442)
                  : c <= 43471)))
              : (c <= 43492 || (c < 43584
                ? (c < 43514
                  ? (c >= 43494 && c <= 43503)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43616
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43638)))))
            : (c <= 43642 || (c < 43739
              ? (c < 43705
                ? (c < 43697
                  ? (c >= 43646 && c <= 43695)
                  : (c <= 43697 || (c >= 43701 && c <= 43702)))
                : (c <= 43709 || (c < 43714
                  ? c == 43712
                  : c <= 43714)))
              : (c <= 43741 || (c < 43777
                ? (c < 43762
                  ? (c >= 43744 && c <= 43754)
                  : c <= 43764)
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55203
                  ? c == 44032
                  : c <= 55203)))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64467
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : c <= 64433)))
              : (c <= 64829 || (c < 65008
                ? (c < 64914
                  ? (c >= 64848 && c <= 64911)
                  : c <= 64967)
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65338 || (c < 66864
          ? (c < 66176
            ? (c < 65536
              ? (c < 65482
                ? (c < 65382
                  ? (c >= 65345 && c <= 65370)
                  : (c <= 65470 || (c >= 65474 && c <= 65479)))
                : (c <= 65487 || (c < 65498
                  ? (c >= 65490 && c <= 65495)
                  : c <= 65500)))
              : (c <= 65547 || (c < 65599
                ? (c < 65576
                  ? (c >= 65549 && c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))
                : (c <= 65613 || (c < 65664
                  ? (c >= 65616 && c <= 65629)
                  : c <= 65786)))))
            : (c <= 66204 || (c < 66464
              ? (c < 66370
                ? (c < 66304
                  ? (c >= 66208 && c <= 66256)
                  : (c <= 66335 || (c >= 66349 && c <= 66368)))
                : (c <= 66377 || (c < 66432
                  ? (c >= 66384 && c <= 66421)
                  : c <= 66461)))
              : (c <= 66499 || (c < 66736
                ? (c < 66560
                  ? (c >= 66504 && c <= 66511)
                  : c <= 66717)
                : (c <= 66771 || (c < 66816
                  ? (c >= 66776 && c <= 66811)
                  : c <= 66855)))))))
          : (c <= 66915 || (c < 67506
            ? (c < 66995
              ? (c < 66964
                ? (c < 66940
                  ? (c >= 66928 && c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))
                : (c <= 66965 || (c < 66979
                  ? (c >= 66967 && c <= 66977)
                  : c <= 66993)))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67680
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67808
                  ? (c >= 67712 && c <= 67742)
                  : c <= 67826)
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_name_character_set_3(int32_t c) {
  return (c < 6656
    ? (c < 2979
      ? (c < 2308
        ? (c < 1376
          ? (c < 880
            ? (c < 192
              ? (c < 170
                ? (c < 'B'
                  ? c == '$'
                  : (c <= 'Z' || (c >= 'a' && c <= 'z')))
                : (c <= 170 || (c < 186
                  ? c == 181
                  : c <= 186)))
              : (c <= 214 || (c < 736
                ? (c < 248
                  ? (c >= 216 && c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))
                : (c <= 740 || (c < 750
                  ? c == 748
                  : c <= 750)))))
            : (c <= 884 || (c < 910
              ? (c < 902
                ? (c < 890
                  ? (c >= 886 && c <= 887)
                  : (c <= 893 || c == 895))
                : (c <= 902 || (c < 908
                  ? (c >= 904 && c <= 906)
                  : c <= 908)))
              : (c <= 929 || (c < 1162
                ? (c < 1015
                  ? (c >= 931 && c <= 1013)
                  : c <= 1153)
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1765
              ? (c < 1646
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1808
                ? (c < 1786
                  ? (c >= 1774 && c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1994 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2160
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : c <= 2154)
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2417
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : c <= 2448)))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2544 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2649
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : c <= 2617)
                : (c <= 2652 || (c < 2674
                  ? c == 2654
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2866
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2831
                ? (c < 2809
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2949
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2969
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 4159
        ? (c < 3412
          ? (c < 3214
            ? (c < 3114
              ? (c < 3077
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : c <= 3112)))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3313
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3314 || (c < 3346
                ? (c < 3342
                  ? (c >= 3332 && c <= 3340)
                  : c <= 3344)
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3724
            ? (c < 3520
              ? (c < 3482
                ? (c < 3450
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))
                : (c <= 3505 || (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : c <= 3517)))
              : (c <= 3526 || (c < 3713
                ? (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : (c <= 3635 || (c >= 3648 && c <= 3654)))
                : (c <= 3714 || (c < 3718
                  ? c == 3716
                  : c <= 3722)))))
            : (c <= 3747 || (c < 3804
              ? (c < 3773
                ? (c < 3751
                  ? c == 3749
                  : (c <= 3760 || (c >= 3762 && c <= 3763)))
                : (c <= 3773 || (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : c <= 3782)))
              : (c <= 3807 || (c < 3913
                ? (c < 3904
                  ? c == 3840
                  : c <= 3911)
                : (c <= 3948 || (c < 4096
                  ? (c >= 3976 && c <= 3980)
                  : c <= 4138)))))))))
        : (c <= 4159 || (c < 4888
          ? (c < 4688
            ? (c < 4238
              ? (c < 4197
                ? (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : (c <= 4189 || c == 4193))
                : (c <= 4198 || (c < 4213
                  ? (c >= 4206 && c <= 4208)
                  : c <= 4225)))
              : (c <= 4238 || (c < 4304
                ? (c < 4295
                  ? (c >= 4256 && c <= 4293)
                  : (c <= 4295 || c == 4301))
                : (c <= 4346 || (c < 4682
                  ? (c >= 4348 && c <= 4680)
                  : c <= 4685)))))
            : (c <= 4694 || (c < 4792
              ? (c < 4746
                ? (c < 4698
                  ? c == 4696
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))
                : (c <= 4749 || (c < 4786
                  ? (c >= 4752 && c <= 4784)
                  : c <= 4789)))
              : (c <= 4798 || (c < 4808
                ? (c < 4802
                  ? c == 4800
                  : c <= 4805)
                : (c <= 4822 || (c < 4882
                  ? (c >= 4824 && c <= 4880)
                  : c <= 4885)))))))
          : (c <= 4954 || (c < 6016
            ? (c < 5792
              ? (c < 5121
                ? (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : (c <= 5109 || (c >= 5112 && c <= 5117)))
                : (c <= 5740 || (c < 5761
                  ? (c >= 5743 && c <= 5759)
                  : c <= 5786)))
              : (c <= 5866 || (c < 5952
                ? (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))
                : (c <= 5969 || (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : c <= 6000)))))
            : (c <= 6067 || (c < 6320
              ? (c < 6272
                ? (c < 6108
                  ? c == 6103
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))
              : (c <= 6389 || (c < 6512
                ? (c < 6480
                  ? (c >= 6400 && c <= 6430)
                  : c <= 6509)
                : (c <= 6516 || (c < 6576
                  ? (c >= 6528 && c <= 6571)
                  : c <= 6601)))))))))))))
    : (c <= 6678 || (c < 43259
      ? (c < 8579
        ? (c < 8031
          ? (c < 7401
            ? (c < 7098
              ? (c < 6981
                ? (c < 6823
                  ? (c >= 6688 && c <= 6740)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7086
                  ? (c >= 7043 && c <= 7072)
                  : c <= 7087)))
              : (c <= 7141 || (c < 7296
                ? (c < 7245
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 7968
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))
              : (c <= 8005 || (c < 8025
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : c <= 8023)
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))))))
          : (c <= 8061 || (c < 8450
            ? (c < 8150
              ? (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))
              : (c <= 8155 || (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))))
            : (c <= 8450 || (c < 8488
              ? (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))
              : (c <= 8488 || (c < 8508
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : c <= 8505)
                : (c <= 8511 || (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : c <= 8526)))))))))
        : (c <= 8580 || (c < 12593
          ? (c < 11712
            ? (c < 11568
              ? (c < 11520
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : c <= 11565)))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12347
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12337
                  ? (c >= 12293 && c <= 12294)
                  : c <= 12341)))
              : (c <= 12348 || (c < 12449
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)
                : (c <= 12538 || (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : c <= 12591)))))))
          : (c <= 12686 || (c < 42775
            ? (c < 42192
              ? (c < 19903
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || c == 13312))
                : (c <= 19903 || (c < 40959
                  ? c == 19968
                  : c <= 42124)))
              : (c <= 42237 || (c < 42560
                ? (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : c <= 42725)))))
            : (c <= 42783 || (c < 43011
              ? (c < 42963
                ? (c < 42891
                  ? (c >= 42786 && c <= 42888)
                  : (c <= 42954 || (c >= 42960 && c <= 42961)))
                : (c <= 42963 || (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : c <= 43009)))
              : (c <= 43013 || (c < 43072
                ? (c < 43020
                  ? (c >= 43015 && c <= 43018)
                  : c <= 43042)
                : (c <= 43123 || (c < 43250
                  ? (c >= 43138 && c <= 43187)
                  : c <= 43255)))))))))))
      : (c <= 43259 || (c < 65313
        ? (c < 43808
          ? (c < 43642
            ? (c < 43488
              ? (c < 43360
                ? (c < 43274
                  ? (c >= 43261 && c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43471
                  ? (c >= 43396 && c <= 43442)
                  : c <= 43471)))
              : (c <= 43492 || (c < 43584
                ? (c < 43514
                  ? (c >= 43494 && c <= 43503)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43616
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43638)))))
            : (c <= 43642 || (c < 43739
              ? (c < 43705
                ? (c < 43697
                  ? (c >= 43646 && c <= 43695)
                  : (c <= 43697 || (c >= 43701 && c <= 43702)))
                : (c <= 43709 || (c < 43714
                  ? c == 43712
                  : c <= 43714)))
              : (c <= 43741 || (c < 43777
                ? (c < 43762
                  ? (c >= 43744 && c <= 43754)
                  : c <= 43764)
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55203
                  ? c == 44032
                  : c <= 55203)))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64467
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : c <= 64433)))
              : (c <= 64829 || (c < 65008
                ? (c < 64914
                  ? (c >= 64848 && c <= 64911)
                  : c <= 64967)
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65338 || (c < 66864
          ? (c < 66176
            ? (c < 65536
              ? (c < 65482
                ? (c < 65382
                  ? (c >= 65345 && c <= 65370)
                  : (c <= 65470 || (c >= 65474 && c <= 65479)))
                : (c <= 65487 || (c < 65498
                  ? (c >= 65490 && c <= 65495)
                  : c <= 65500)))
              : (c <= 65547 || (c < 65599
                ? (c < 65576
                  ? (c >= 65549 && c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))
                : (c <= 65613 || (c < 65664
                  ? (c >= 65616 && c <= 65629)
                  : c <= 65786)))))
            : (c <= 66204 || (c < 66464
              ? (c < 66370
                ? (c < 66304
                  ? (c >= 66208 && c <= 66256)
                  : (c <= 66335 || (c >= 66349 && c <= 66368)))
                : (c <= 66377 || (c < 66432
                  ? (c >= 66384 && c <= 66421)
                  : c <= 66461)))
              : (c <= 66499 || (c < 66736
                ? (c < 66560
                  ? (c >= 66504 && c <= 66511)
                  : c <= 66717)
                : (c <= 66771 || (c < 66816
                  ? (c >= 66776 && c <= 66811)
                  : c <= 66855)))))))
          : (c <= 66915 || (c < 67506
            ? (c < 66995
              ? (c < 66964
                ? (c < 66940
                  ? (c >= 66928 && c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))
                : (c <= 66965 || (c < 66979
                  ? (c >= 66967 && c <= 66977)
                  : c <= 66993)))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67680
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67808
                  ? (c >= 67712 && c <= 67742)
                  : c <= 67826)
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_name_character_set_4(int32_t c) {
  return (c < 6656
    ? (c < 2979
      ? (c < 2308
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < 'a'
                ? (c < 'C'
                  ? c == '$'
                  : (c <= 'Z' || c == '_'))
                : (c <= 'z' || (c < 181
                  ? c == 170
                  : c <= 181)))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1765
              ? (c < 1646
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1808
                ? (c < 1786
                  ? (c >= 1774 && c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1994 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2160
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : c <= 2154)
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2417
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : c <= 2448)))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2544 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2649
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : c <= 2617)
                : (c <= 2652 || (c < 2674
                  ? c == 2654
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2866
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2831
                ? (c < 2809
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2949
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2969
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 4159
        ? (c < 3412
          ? (c < 3214
            ? (c < 3114
              ? (c < 3077
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : c <= 3112)))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3313
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3314 || (c < 3346
                ? (c < 3342
                  ? (c >= 3332 && c <= 3340)
                  : c <= 3344)
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3724
            ? (c < 3520
              ? (c < 3482
                ? (c < 3450
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))
                : (c <= 3505 || (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : c <= 3517)))
              : (c <= 3526 || (c < 3713
                ? (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : (c <= 3635 || (c >= 3648 && c <= 3654)))
                : (c <= 3714 || (c < 3718
                  ? c == 3716
                  : c <= 3722)))))
            : (c <= 3747 || (c < 3804
              ? (c < 3773
                ? (c < 3751
                  ? c == 3749
                  : (c <= 3760 || (c >= 3762 && c <= 3763)))
                : (c <= 3773 || (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : c <= 3782)))
              : (c <= 3807 || (c < 3913
                ? (c < 3904
                  ? c == 3840
                  : c <= 3911)
                : (c <= 3948 || (c < 4096
                  ? (c >= 3976 && c <= 3980)
                  : c <= 4138)))))))))
        : (c <= 4159 || (c < 4888
          ? (c < 4688
            ? (c < 4238
              ? (c < 4197
                ? (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : (c <= 4189 || c == 4193))
                : (c <= 4198 || (c < 4213
                  ? (c >= 4206 && c <= 4208)
                  : c <= 4225)))
              : (c <= 4238 || (c < 4304
                ? (c < 4295
                  ? (c >= 4256 && c <= 4293)
                  : (c <= 4295 || c == 4301))
                : (c <= 4346 || (c < 4682
                  ? (c >= 4348 && c <= 4680)
                  : c <= 4685)))))
            : (c <= 4694 || (c < 4792
              ? (c < 4746
                ? (c < 4698
                  ? c == 4696
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))
                : (c <= 4749 || (c < 4786
                  ? (c >= 4752 && c <= 4784)
                  : c <= 4789)))
              : (c <= 4798 || (c < 4808
                ? (c < 4802
                  ? c == 4800
                  : c <= 4805)
                : (c <= 4822 || (c < 4882
                  ? (c >= 4824 && c <= 4880)
                  : c <= 4885)))))))
          : (c <= 4954 || (c < 6016
            ? (c < 5792
              ? (c < 5121
                ? (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : (c <= 5109 || (c >= 5112 && c <= 5117)))
                : (c <= 5740 || (c < 5761
                  ? (c >= 5743 && c <= 5759)
                  : c <= 5786)))
              : (c <= 5866 || (c < 5952
                ? (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))
                : (c <= 5969 || (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : c <= 6000)))))
            : (c <= 6067 || (c < 6320
              ? (c < 6272
                ? (c < 6108
                  ? c == 6103
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))
              : (c <= 6389 || (c < 6512
                ? (c < 6480
                  ? (c >= 6400 && c <= 6430)
                  : c <= 6509)
                : (c <= 6516 || (c < 6576
                  ? (c >= 6528 && c <= 6571)
                  : c <= 6601)))))))))))))
    : (c <= 6678 || (c < 43259
      ? (c < 8579
        ? (c < 8031
          ? (c < 7401
            ? (c < 7098
              ? (c < 6981
                ? (c < 6823
                  ? (c >= 6688 && c <= 6740)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7086
                  ? (c >= 7043 && c <= 7072)
                  : c <= 7087)))
              : (c <= 7141 || (c < 7296
                ? (c < 7245
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 7968
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))
              : (c <= 8005 || (c < 8025
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : c <= 8023)
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))))))
          : (c <= 8061 || (c < 8450
            ? (c < 8150
              ? (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))
              : (c <= 8155 || (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))))
            : (c <= 8450 || (c < 8488
              ? (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))
              : (c <= 8488 || (c < 8508
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : c <= 8505)
                : (c <= 8511 || (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : c <= 8526)))))))))
        : (c <= 8580 || (c < 12593
          ? (c < 11712
            ? (c < 11568
              ? (c < 11520
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : c <= 11565)))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12347
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12337
                  ? (c >= 12293 && c <= 12294)
                  : c <= 12341)))
              : (c <= 12348 || (c < 12449
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)
                : (c <= 12538 || (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : c <= 12591)))))))
          : (c <= 12686 || (c < 42775
            ? (c < 42192
              ? (c < 19903
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || c == 13312))
                : (c <= 19903 || (c < 40959
                  ? c == 19968
                  : c <= 42124)))
              : (c <= 42237 || (c < 42560
                ? (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : c <= 42725)))))
            : (c <= 42783 || (c < 43011
              ? (c < 42963
                ? (c < 42891
                  ? (c >= 42786 && c <= 42888)
                  : (c <= 42954 || (c >= 42960 && c <= 42961)))
                : (c <= 42963 || (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : c <= 43009)))
              : (c <= 43013 || (c < 43072
                ? (c < 43020
                  ? (c >= 43015 && c <= 43018)
                  : c <= 43042)
                : (c <= 43123 || (c < 43250
                  ? (c >= 43138 && c <= 43187)
                  : c <= 43255)))))))))))
      : (c <= 43259 || (c < 65313
        ? (c < 43808
          ? (c < 43642
            ? (c < 43488
              ? (c < 43360
                ? (c < 43274
                  ? (c >= 43261 && c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43471
                  ? (c >= 43396 && c <= 43442)
                  : c <= 43471)))
              : (c <= 43492 || (c < 43584
                ? (c < 43514
                  ? (c >= 43494 && c <= 43503)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43616
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43638)))))
            : (c <= 43642 || (c < 43739
              ? (c < 43705
                ? (c < 43697
                  ? (c >= 43646 && c <= 43695)
                  : (c <= 43697 || (c >= 43701 && c <= 43702)))
                : (c <= 43709 || (c < 43714
                  ? c == 43712
                  : c <= 43714)))
              : (c <= 43741 || (c < 43777
                ? (c < 43762
                  ? (c >= 43744 && c <= 43754)
                  : c <= 43764)
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55203
                  ? c == 44032
                  : c <= 55203)))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64467
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : c <= 64433)))
              : (c <= 64829 || (c < 65008
                ? (c < 64914
                  ? (c >= 64848 && c <= 64911)
                  : c <= 64967)
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65338 || (c < 66864
          ? (c < 66176
            ? (c < 65536
              ? (c < 65482
                ? (c < 65382
                  ? (c >= 65345 && c <= 65370)
                  : (c <= 65470 || (c >= 65474 && c <= 65479)))
                : (c <= 65487 || (c < 65498
                  ? (c >= 65490 && c <= 65495)
                  : c <= 65500)))
              : (c <= 65547 || (c < 65599
                ? (c < 65576
                  ? (c >= 65549 && c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))
                : (c <= 65613 || (c < 65664
                  ? (c >= 65616 && c <= 65629)
                  : c <= 65786)))))
            : (c <= 66204 || (c < 66464
              ? (c < 66370
                ? (c < 66304
                  ? (c >= 66208 && c <= 66256)
                  : (c <= 66335 || (c >= 66349 && c <= 66368)))
                : (c <= 66377 || (c < 66432
                  ? (c >= 66384 && c <= 66421)
                  : c <= 66461)))
              : (c <= 66499 || (c < 66736
                ? (c < 66560
                  ? (c >= 66504 && c <= 66511)
                  : c <= 66717)
                : (c <= 66771 || (c < 66816
                  ? (c >= 66776 && c <= 66811)
                  : c <= 66855)))))))
          : (c <= 66915 || (c < 67506
            ? (c < 66995
              ? (c < 66964
                ? (c < 66940
                  ? (c >= 66928 && c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))
                : (c <= 66965 || (c < 66979
                  ? (c >= 66967 && c <= 66977)
                  : c <= 66993)))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67680
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67808
                  ? (c >= 67712 && c <= 67742)
                  : c <= 67826)
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_name_character_set_5(int32_t c) {
  return (c < 6400
    ? (c < 2979
      ? (c < 2365
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < '_'
                ? (c < '0'
                  ? c == '$'
                  : (c <= '9' || (c >= 'A' && c <= 'Z')))
                : (c <= '_' || (c < 170
                  ? (c >= 'a' && c <= 'z')
                  : (c <= 170 || c == 181))))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1749
              ? (c < 1632
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1641 || (c < 1649
                  ? (c >= 1646 && c <= 1647)
                  : c <= 1747)))
              : (c <= 1749 || (c < 1808
                ? (c < 1774
                  ? (c >= 1765 && c <= 1766)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1984 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2185
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : (c <= 2154 || (c >= 2160 && c <= 2183)))
                : (c <= 2190 || (c < 2308
                  ? (c >= 2208 && c <= 2249)
                  : c <= 2361)))))))))
        : (c <= 2365 || (c < 2703
          ? (c < 2534
            ? (c < 2474
              ? (c < 2417
                ? (c < 2392
                  ? c == 2384
                  : (c <= 2401 || (c >= 2406 && c <= 2415)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : (c <= 2448 || (c >= 2451 && c <= 2472)))))
              : (c <= 2480 || (c < 2510
                ? (c < 2486
                  ? c == 2482
                  : (c <= 2489 || c == 2493))
                : (c <= 2510 || (c < 2527
                  ? (c >= 2524 && c <= 2525)
                  : c <= 2529)))))
            : (c <= 2545 || (c < 2613
              ? (c < 2579
                ? (c < 2565
                  ? c == 2556
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))
                : (c <= 2600 || (c < 2610
                  ? (c >= 2602 && c <= 2608)
                  : c <= 2611)))
              : (c <= 2614 || (c < 2662
                ? (c < 2649
                  ? (c >= 2616 && c <= 2617)
                  : (c <= 2652 || c == 2654))
                : (c <= 2671 || (c < 2693
                  ? (c >= 2674 && c <= 2676)
                  : c <= 2701)))))))
          : (c <= 2705 || (c < 2866
            ? (c < 2784
              ? (c < 2741
                ? (c < 2730
                  ? (c >= 2707 && c <= 2728)
                  : (c <= 2736 || (c >= 2738 && c <= 2739)))
                : (c <= 2745 || (c < 2768
                  ? c == 2749
                  : c <= 2768)))
              : (c <= 2785 || (c < 2831
                ? (c < 2809
                  ? (c >= 2790 && c <= 2799)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2947
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2929
                  ? (c >= 2918 && c <= 2927)
                  : c <= 2929)))
              : (c <= 2947 || (c < 2969
                ? (c < 2958
                  ? (c >= 2949 && c <= 2954)
                  : (c <= 2960 || (c >= 2962 && c <= 2965)))
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 3872
        ? (c < 3406
          ? (c < 3205
            ? (c < 3114
              ? (c < 3046
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3055 || (c < 3086
                  ? (c >= 3077 && c <= 3084)
                  : (c <= 3088 || (c >= 3090 && c <= 3112)))))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3200
                  ? (c >= 3174 && c <= 3183)
                  : c <= 3200)))))
            : (c <= 3212 || (c < 3296
              ? (c < 3253
                ? (c < 3218
                  ? (c >= 3214 && c <= 3216)
                  : (c <= 3240 || (c >= 3242 && c <= 3251)))
                : (c <= 3257 || (c < 3293
                  ? c == 3261
                  : c <= 3294)))
              : (c <= 3297 || (c < 3342
                ? (c < 3313
                  ? (c >= 3302 && c <= 3311)
                  : (c <= 3314 || (c >= 3332 && c <= 3340)))
                : (c <= 3344 || (c < 3389
                  ? (c >= 3346 && c <= 3386)
                  : c <= 3389)))))))
          : (c <= 3406 || (c < 3664
            ? (c < 3507
              ? (c < 3450
                ? (c < 3423
                  ? (c >= 3412 && c <= 3414)
                  : (c <= 3425 || (c >= 3430 && c <= 3439)))
                : (c <= 3455 || (c < 3482
                  ? (c >= 3461 && c <= 3478)
                  : c <= 3505)))
              : (c <= 3515 || (c < 3585
                ? (c < 3520
                  ? c == 3517
                  : (c <= 3526 || (c >= 3558 && c <= 3567)))
                : (c <= 3632 || (c < 3648
                  ? (c >= 3634 && c <= 3635)
                  : c <= 3654)))))
            : (c <= 3673 || (c < 3762
              ? (c < 3724
                ? (c < 3716
                  ? (c >= 3713 && c <= 3714)
                  : (c <= 3716 || (c >= 3718 && c <= 3722)))
                : (c <= 3747 || (c < 3751
                  ? c == 3749
                  : c <= 3760)))
              : (c <= 3763 || (c < 3792
                ? (c < 3776
                  ? c == 3773
                  : (c <= 3780 || c == 3782))
                : (c <= 3801 || (c < 3840
                  ? (c >= 3804 && c <= 3807)
                  : c <= 3840)))))))))
        : (c <= 3881 || (c < 4802
          ? (c < 4295
            ? (c < 4193
              ? (c < 4096
                ? (c < 3913
                  ? (c >= 3904 && c <= 3911)
                  : (c <= 3948 || (c >= 3976 && c <= 3980)))
                : (c <= 4138 || (c < 4176
                  ? (c >= 4159 && c <= 4169)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))
              : (c <= 4193 || (c < 4238
                ? (c < 4206
                  ? (c >= 4197 && c <= 4198)
                  : (c <= 4208 || (c >= 4213 && c <= 4225)))
                : (c <= 4238 || (c < 4256
                  ? (c >= 4240 && c <= 4249)
                  : c <= 4293)))))
            : (c <= 4295 || (c < 4698
              ? (c < 4682
                ? (c < 4304
                  ? c == 4301
                  : (c <= 4346 || (c >= 4348 && c <= 4680)))
                : (c <= 4685 || (c < 4696
                  ? (c >= 4688 && c <= 4694)
                  : c <= 4696)))
              : (c <= 4701 || (c < 4786
                ? (c < 4746
                  ? (c >= 4704 && c <= 4744)
                  : (c <= 4749 || (c >= 4752 && c <= 4784)))
                : (c <= 4789 || (c < 4800
                  ? (c >= 4792 && c <= 4798)
                  : c <= 4800)))))))
          : (c <= 4805 || (c < 5919
            ? (c < 5112
              ? (c < 4888
                ? (c < 4824
                  ? (c >= 4808 && c <= 4822)
                  : (c <= 4880 || (c >= 4882 && c <= 4885)))
                : (c <= 4954 || (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : c <= 5109)))
              : (c <= 5117 || (c < 5792
                ? (c < 5743
                  ? (c >= 5121 && c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))
                : (c <= 5866 || (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : c <= 5905)))))
            : (c <= 5937 || (c < 6112
              ? (c < 6016
                ? (c < 5984
                  ? (c >= 5952 && c <= 5969)
                  : (c <= 5996 || (c >= 5998 && c <= 6000)))
                : (c <= 6067 || (c < 6108
                  ? c == 6103
                  : c <= 6108)))
              : (c <= 6121 || (c < 6279
                ? (c < 6176
                  ? (c >= 6160 && c <= 6169)
                  : (c <= 6264 || (c >= 6272 && c <= 6276)))
                : (c <= 6312 || (c < 6320
                  ? c == 6314
                  : c <= 6389)))))))))))))
    : (c <= 6430 || (c < 43216
      ? (c < 8490
        ? (c < 7968
          ? (c < 7086
            ? (c < 6784
              ? (c < 6576
                ? (c < 6512
                  ? (c >= 6470 && c <= 6509)
                  : (c <= 6516 || (c >= 6528 && c <= 6571)))
                : (c <= 6601 || (c < 6656
                  ? (c >= 6608 && c <= 6617)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6793 || (c < 6981
                ? (c < 6823
                  ? (c >= 6800 && c <= 6809)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7043
                  ? (c >= 6992 && c <= 7001)
                  : c <= 7072)))))
            : (c <= 7141 || (c < 7401
              ? (c < 7296
                ? (c < 7232
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7241 || (c >= 7245 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))
              : (c <= 7404 || (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))))))
          : (c <= 8005 || (c < 8160
            ? (c < 8064
              ? (c < 8027
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : (c <= 8023 || c == 8025))
                : (c <= 8027 || (c < 8031
                  ? c == 8029
                  : c <= 8061)))
              : (c <= 8116 || (c < 8134
                ? (c < 8126
                  ? (c >= 8118 && c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))
                : (c <= 8140 || (c < 8150
                  ? (c >= 8144 && c <= 8147)
                  : c <= 8155)))))
            : (c <= 8172 || (c < 8455
              ? (c < 8319
                ? (c < 8182
                  ? (c >= 8178 && c <= 8180)
                  : (c <= 8188 || c == 8305))
                : (c <= 8319 || (c < 8450
                  ? (c >= 8336 && c <= 8348)
                  : c <= 8450)))
              : (c <= 8455 || (c < 8484
                ? (c < 8469
                  ? (c >= 8458 && c <= 8467)
                  : (c <= 8469 || (c >= 8473 && c <= 8477)))
                : (c <= 8484 || (c < 8488
                  ? c == 8486
                  : c <= 8488)))))))))
        : (c <= 8493 || (c < 12449
          ? (c < 11680
            ? (c < 11506
              ? (c < 8526
                ? (c < 8508
                  ? (c >= 8495 && c <= 8505)
                  : (c <= 8511 || (c >= 8517 && c <= 8521)))
                : (c <= 8526 || (c < 11264
                  ? (c >= 8579 && c <= 8580)
                  : (c <= 11492 || (c >= 11499 && c <= 11502)))))
              : (c <= 11507 || (c < 11568
                ? (c < 11559
                  ? (c >= 11520 && c <= 11557)
                  : (c <= 11559 || c == 11565))
                : (c <= 11623 || (c < 11648
                  ? c == 11631
                  : c <= 11670)))))
            : (c <= 11686 || (c < 11736
              ? (c < 11712
                ? (c < 11696
                  ? (c >= 11688 && c <= 11694)
                  : (c <= 11702 || (c >= 11704 && c <= 11710)))
                : (c <= 11718 || (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : c <= 11734)))
              : (c <= 11742 || (c < 12347
                ? (c < 12293
                  ? c == 11823
                  : (c <= 12294 || (c >= 12337 && c <= 12341)))
                : (c <= 12348 || (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)))))))
          : (c <= 12538 || (c < 42623
            ? (c < 19903
              ? (c < 12704
                ? (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : (c <= 12591 || (c >= 12593 && c <= 12686)))
                : (c <= 12735 || (c < 13312
                  ? (c >= 12784 && c <= 12799)
                  : c <= 13312)))
              : (c <= 19903 || (c < 42240
                ? (c < 40959
                  ? c == 19968
                  : (c <= 42124 || (c >= 42192 && c <= 42237)))
                : (c <= 42508 || (c < 42560
                  ? (c >= 42512 && c <= 42539)
                  : c <= 42606)))))
            : (c <= 42653 || (c < 42965
              ? (c < 42891
                ? (c < 42775
                  ? (c >= 42656 && c <= 42725)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))
                : (c <= 42954 || (c < 42963
                  ? (c >= 42960 && c <= 42961)
                  : c <= 42963)))
              : (c <= 42969 || (c < 43020
                ? (c < 43011
                  ? (c >= 42994 && c <= 43009)
                  : (c <= 43013 || (c >= 43015 && c <= 43018)))
                : (c <= 43042 || (c < 43138
                  ? (c >= 43072 && c <= 43123)
                  : c <= 43187)))))))))))
      : (c <= 43225 || (c < 65296
        ? (c < 43808
          ? (c < 43616
            ? (c < 43471
              ? (c < 43264
                ? (c < 43259
                  ? (c >= 43250 && c <= 43255)
                  : (c <= 43259 || (c >= 43261 && c <= 43262)))
                : (c <= 43301 || (c < 43360
                  ? (c >= 43312 && c <= 43334)
                  : (c <= 43388 || (c >= 43396 && c <= 43442)))))
              : (c <= 43481 || (c < 43584
                ? (c < 43494
                  ? (c >= 43488 && c <= 43492)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43600
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43609)))))
            : (c <= 43638 || (c < 43714
              ? (c < 43701
                ? (c < 43646
                  ? c == 43642
                  : (c <= 43695 || c == 43697))
                : (c <= 43702 || (c < 43712
                  ? (c >= 43705 && c <= 43709)
                  : c <= 43712)))
              : (c <= 43714 || (c < 43777
                ? (c < 43744
                  ? (c >= 43739 && c <= 43741)
                  : (c <= 43754 || (c >= 43762 && c <= 43764)))
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64285
            ? (c < 55203
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 44032
                  ? (c >= 44016 && c <= 44025)
                  : c <= 44032)))
              : (c <= 55203 || (c < 64112
                ? (c < 55243
                  ? (c >= 55216 && c <= 55238)
                  : (c <= 55291 || (c >= 63744 && c <= 64109)))
                : (c <= 64217 || (c < 64275
                  ? (c >= 64256 && c <= 64262)
                  : c <= 64279)))))
            : (c <= 64285 || (c < 64326
              ? (c < 64318
                ? (c < 64298
                  ? (c >= 64287 && c <= 64296)
                  : (c <= 64310 || (c >= 64312 && c <= 64316)))
                : (c <= 64318 || (c < 64323
                  ? (c >= 64320 && c <= 64321)
                  : c <= 64324)))
              : (c <= 64433 || (c < 65008
                ? (c < 64848
                  ? (c >= 64467 && c <= 64829)
                  : (c <= 64911 || (c >= 64914 && c <= 64967)))
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65305 || (c < 66816
          ? (c < 65664
            ? (c < 65498
              ? (c < 65474
                ? (c < 65345
                  ? (c >= 65313 && c <= 65338)
                  : (c <= 65370 || (c >= 65382 && c <= 65470)))
                : (c <= 65479 || (c < 65490
                  ? (c >= 65482 && c <= 65487)
                  : c <= 65495)))
              : (c <= 65500 || (c < 65596
                ? (c < 65549
                  ? (c >= 65536 && c <= 65547)
                  : (c <= 65574 || (c >= 65576 && c <= 65594)))
                : (c <= 65597 || (c < 65616
                  ? (c >= 65599 && c <= 65613)
                  : c <= 65629)))))
            : (c <= 65786 || (c < 66432
              ? (c < 66349
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))
                : (c <= 66368 || (c < 66384
                  ? (c >= 66370 && c <= 66377)
                  : c <= 66421)))
              : (c <= 66461 || (c < 66720
                ? (c < 66504
                  ? (c >= 66464 && c <= 66499)
                  : (c <= 66511 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67463
            ? (c < 66979
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : c <= 66977)))
              : (c <= 66993 || (c < 67392
                ? (c < 67003
                  ? (c >= 66995 && c <= 67001)
                  : (c <= 67004 || (c >= 67072 && c <= 67382)))
                : (c <= 67413 || (c < 67456
                  ? (c >= 67424 && c <= 67431)
                  : c <= 67461)))))
            : (c <= 67504 || (c < 67647
              ? (c < 67594
                ? (c < 67584
                  ? (c >= 67506 && c <= 67514)
                  : (c <= 67589 || c == 67592))
                : (c <= 67637 || (c < 67644
                  ? (c >= 67639 && c <= 67640)
                  : c <= 67644)))
              : (c <= 67669 || (c < 67828
                ? (c < 67712
                  ? (c >= 67680 && c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_name_character_set_6(int32_t c) {
  return (c < 6400
    ? (c < 2979
      ? (c < 2365
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < '_'
                ? (c < '0'
                  ? c == '$'
                  : (c <= '9' || (c >= 'B' && c <= 'Z')))
                : (c <= '_' || (c < 170
                  ? (c >= 'a' && c <= 'z')
                  : (c <= 170 || c == 181))))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1749
              ? (c < 1632
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1641 || (c < 1649
                  ? (c >= 1646 && c <= 1647)
                  : c <= 1747)))
              : (c <= 1749 || (c < 1808
                ? (c < 1774
                  ? (c >= 1765 && c <= 1766)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1984 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2185
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : (c <= 2154 || (c >= 2160 && c <= 2183)))
                : (c <= 2190 || (c < 2308
                  ? (c >= 2208 && c <= 2249)
                  : c <= 2361)))))))))
        : (c <= 2365 || (c < 2703
          ? (c < 2534
            ? (c < 2474
              ? (c < 2417
                ? (c < 2392
                  ? c == 2384
                  : (c <= 2401 || (c >= 2406 && c <= 2415)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : (c <= 2448 || (c >= 2451 && c <= 2472)))))
              : (c <= 2480 || (c < 2510
                ? (c < 2486
                  ? c == 2482
                  : (c <= 2489 || c == 2493))
                : (c <= 2510 || (c < 2527
                  ? (c >= 2524 && c <= 2525)
                  : c <= 2529)))))
            : (c <= 2545 || (c < 2613
              ? (c < 2579
                ? (c < 2565
                  ? c == 2556
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))
                : (c <= 2600 || (c < 2610
                  ? (c >= 2602 && c <= 2608)
                  : c <= 2611)))
              : (c <= 2614 || (c < 2662
                ? (c < 2649
                  ? (c >= 2616 && c <= 2617)
                  : (c <= 2652 || c == 2654))
                : (c <= 2671 || (c < 2693
                  ? (c >= 2674 && c <= 2676)
                  : c <= 2701)))))))
          : (c <= 2705 || (c < 2866
            ? (c < 2784
              ? (c < 2741
                ? (c < 2730
                  ? (c >= 2707 && c <= 2728)
                  : (c <= 2736 || (c >= 2738 && c <= 2739)))
                : (c <= 2745 || (c < 2768
                  ? c == 2749
                  : c <= 2768)))
              : (c <= 2785 || (c < 2831
                ? (c < 2809
                  ? (c >= 2790 && c <= 2799)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2947
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2929
                  ? (c >= 2918 && c <= 2927)
                  : c <= 2929)))
              : (c <= 2947 || (c < 2969
                ? (c < 2958
                  ? (c >= 2949 && c <= 2954)
                  : (c <= 2960 || (c >= 2962 && c <= 2965)))
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 3872
        ? (c < 3406
          ? (c < 3205
            ? (c < 3114
              ? (c < 3046
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3055 || (c < 3086
                  ? (c >= 3077 && c <= 3084)
                  : (c <= 3088 || (c >= 3090 && c <= 3112)))))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3200
                  ? (c >= 3174 && c <= 3183)
                  : c <= 3200)))))
            : (c <= 3212 || (c < 3296
              ? (c < 3253
                ? (c < 3218
                  ? (c >= 3214 && c <= 3216)
                  : (c <= 3240 || (c >= 3242 && c <= 3251)))
                : (c <= 3257 || (c < 3293
                  ? c == 3261
                  : c <= 3294)))
              : (c <= 3297 || (c < 3342
                ? (c < 3313
                  ? (c >= 3302 && c <= 3311)
                  : (c <= 3314 || (c >= 3332 && c <= 3340)))
                : (c <= 3344 || (c < 3389
                  ? (c >= 3346 && c <= 3386)
                  : c <= 3389)))))))
          : (c <= 3406 || (c < 3664
            ? (c < 3507
              ? (c < 3450
                ? (c < 3423
                  ? (c >= 3412 && c <= 3414)
                  : (c <= 3425 || (c >= 3430 && c <= 3439)))
                : (c <= 3455 || (c < 3482
                  ? (c >= 3461 && c <= 3478)
                  : c <= 3505)))
              : (c <= 3515 || (c < 3585
                ? (c < 3520
                  ? c == 3517
                  : (c <= 3526 || (c >= 3558 && c <= 3567)))
                : (c <= 3632 || (c < 3648
                  ? (c >= 3634 && c <= 3635)
                  : c <= 3654)))))
            : (c <= 3673 || (c < 3762
              ? (c < 3724
                ? (c < 3716
                  ? (c >= 3713 && c <= 3714)
                  : (c <= 3716 || (c >= 3718 && c <= 3722)))
                : (c <= 3747 || (c < 3751
                  ? c == 3749
                  : c <= 3760)))
              : (c <= 3763 || (c < 3792
                ? (c < 3776
                  ? c == 3773
                  : (c <= 3780 || c == 3782))
                : (c <= 3801 || (c < 3840
                  ? (c >= 3804 && c <= 3807)
                  : c <= 3840)))))))))
        : (c <= 3881 || (c < 4802
          ? (c < 4295
            ? (c < 4193
              ? (c < 4096
                ? (c < 3913
                  ? (c >= 3904 && c <= 3911)
                  : (c <= 3948 || (c >= 3976 && c <= 3980)))
                : (c <= 4138 || (c < 4176
                  ? (c >= 4159 && c <= 4169)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))
              : (c <= 4193 || (c < 4238
                ? (c < 4206
                  ? (c >= 4197 && c <= 4198)
                  : (c <= 4208 || (c >= 4213 && c <= 4225)))
                : (c <= 4238 || (c < 4256
                  ? (c >= 4240 && c <= 4249)
                  : c <= 4293)))))
            : (c <= 4295 || (c < 4698
              ? (c < 4682
                ? (c < 4304
                  ? c == 4301
                  : (c <= 4346 || (c >= 4348 && c <= 4680)))
                : (c <= 4685 || (c < 4696
                  ? (c >= 4688 && c <= 4694)
                  : c <= 4696)))
              : (c <= 4701 || (c < 4786
                ? (c < 4746
                  ? (c >= 4704 && c <= 4744)
                  : (c <= 4749 || (c >= 4752 && c <= 4784)))
                : (c <= 4789 || (c < 4800
                  ? (c >= 4792 && c <= 4798)
                  : c <= 4800)))))))
          : (c <= 4805 || (c < 5919
            ? (c < 5112
              ? (c < 4888
                ? (c < 4824
                  ? (c >= 4808 && c <= 4822)
                  : (c <= 4880 || (c >= 4882 && c <= 4885)))
                : (c <= 4954 || (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : c <= 5109)))
              : (c <= 5117 || (c < 5792
                ? (c < 5743
                  ? (c >= 5121 && c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))
                : (c <= 5866 || (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : c <= 5905)))))
            : (c <= 5937 || (c < 6112
              ? (c < 6016
                ? (c < 5984
                  ? (c >= 5952 && c <= 5969)
                  : (c <= 5996 || (c >= 5998 && c <= 6000)))
                : (c <= 6067 || (c < 6108
                  ? c == 6103
                  : c <= 6108)))
              : (c <= 6121 || (c < 6279
                ? (c < 6176
                  ? (c >= 6160 && c <= 6169)
                  : (c <= 6264 || (c >= 6272 && c <= 6276)))
                : (c <= 6312 || (c < 6320
                  ? c == 6314
                  : c <= 6389)))))))))))))
    : (c <= 6430 || (c < 43216
      ? (c < 8490
        ? (c < 7968
          ? (c < 7086
            ? (c < 6784
              ? (c < 6576
                ? (c < 6512
                  ? (c >= 6470 && c <= 6509)
                  : (c <= 6516 || (c >= 6528 && c <= 6571)))
                : (c <= 6601 || (c < 6656
                  ? (c >= 6608 && c <= 6617)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6793 || (c < 6981
                ? (c < 6823
                  ? (c >= 6800 && c <= 6809)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7043
                  ? (c >= 6992 && c <= 7001)
                  : c <= 7072)))))
            : (c <= 7141 || (c < 7401
              ? (c < 7296
                ? (c < 7232
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7241 || (c >= 7245 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))
              : (c <= 7404 || (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))))))
          : (c <= 8005 || (c < 8160
            ? (c < 8064
              ? (c < 8027
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : (c <= 8023 || c == 8025))
                : (c <= 8027 || (c < 8031
                  ? c == 8029
                  : c <= 8061)))
              : (c <= 8116 || (c < 8134
                ? (c < 8126
                  ? (c >= 8118 && c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))
                : (c <= 8140 || (c < 8150
                  ? (c >= 8144 && c <= 8147)
                  : c <= 8155)))))
            : (c <= 8172 || (c < 8455
              ? (c < 8319
                ? (c < 8182
                  ? (c >= 8178 && c <= 8180)
                  : (c <= 8188 || c == 8305))
                : (c <= 8319 || (c < 8450
                  ? (c >= 8336 && c <= 8348)
                  : c <= 8450)))
              : (c <= 8455 || (c < 8484
                ? (c < 8469
                  ? (c >= 8458 && c <= 8467)
                  : (c <= 8469 || (c >= 8473 && c <= 8477)))
                : (c <= 8484 || (c < 8488
                  ? c == 8486
                  : c <= 8488)))))))))
        : (c <= 8493 || (c < 12449
          ? (c < 11680
            ? (c < 11506
              ? (c < 8526
                ? (c < 8508
                  ? (c >= 8495 && c <= 8505)
                  : (c <= 8511 || (c >= 8517 && c <= 8521)))
                : (c <= 8526 || (c < 11264
                  ? (c >= 8579 && c <= 8580)
                  : (c <= 11492 || (c >= 11499 && c <= 11502)))))
              : (c <= 11507 || (c < 11568
                ? (c < 11559
                  ? (c >= 11520 && c <= 11557)
                  : (c <= 11559 || c == 11565))
                : (c <= 11623 || (c < 11648
                  ? c == 11631
                  : c <= 11670)))))
            : (c <= 11686 || (c < 11736
              ? (c < 11712
                ? (c < 11696
                  ? (c >= 11688 && c <= 11694)
                  : (c <= 11702 || (c >= 11704 && c <= 11710)))
                : (c <= 11718 || (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : c <= 11734)))
              : (c <= 11742 || (c < 12347
                ? (c < 12293
                  ? c == 11823
                  : (c <= 12294 || (c >= 12337 && c <= 12341)))
                : (c <= 12348 || (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)))))))
          : (c <= 12538 || (c < 42623
            ? (c < 19903
              ? (c < 12704
                ? (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : (c <= 12591 || (c >= 12593 && c <= 12686)))
                : (c <= 12735 || (c < 13312
                  ? (c >= 12784 && c <= 12799)
                  : c <= 13312)))
              : (c <= 19903 || (c < 42240
                ? (c < 40959
                  ? c == 19968
                  : (c <= 42124 || (c >= 42192 && c <= 42237)))
                : (c <= 42508 || (c < 42560
                  ? (c >= 42512 && c <= 42539)
                  : c <= 42606)))))
            : (c <= 42653 || (c < 42965
              ? (c < 42891
                ? (c < 42775
                  ? (c >= 42656 && c <= 42725)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))
                : (c <= 42954 || (c < 42963
                  ? (c >= 42960 && c <= 42961)
                  : c <= 42963)))
              : (c <= 42969 || (c < 43020
                ? (c < 43011
                  ? (c >= 42994 && c <= 43009)
                  : (c <= 43013 || (c >= 43015 && c <= 43018)))
                : (c <= 43042 || (c < 43138
                  ? (c >= 43072 && c <= 43123)
                  : c <= 43187)))))))))))
      : (c <= 43225 || (c < 65296
        ? (c < 43808
          ? (c < 43616
            ? (c < 43471
              ? (c < 43264
                ? (c < 43259
                  ? (c >= 43250 && c <= 43255)
                  : (c <= 43259 || (c >= 43261 && c <= 43262)))
                : (c <= 43301 || (c < 43360
                  ? (c >= 43312 && c <= 43334)
                  : (c <= 43388 || (c >= 43396 && c <= 43442)))))
              : (c <= 43481 || (c < 43584
                ? (c < 43494
                  ? (c >= 43488 && c <= 43492)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43600
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43609)))))
            : (c <= 43638 || (c < 43714
              ? (c < 43701
                ? (c < 43646
                  ? c == 43642
                  : (c <= 43695 || c == 43697))
                : (c <= 43702 || (c < 43712
                  ? (c >= 43705 && c <= 43709)
                  : c <= 43712)))
              : (c <= 43714 || (c < 43777
                ? (c < 43744
                  ? (c >= 43739 && c <= 43741)
                  : (c <= 43754 || (c >= 43762 && c <= 43764)))
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64285
            ? (c < 55203
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 44032
                  ? (c >= 44016 && c <= 44025)
                  : c <= 44032)))
              : (c <= 55203 || (c < 64112
                ? (c < 55243
                  ? (c >= 55216 && c <= 55238)
                  : (c <= 55291 || (c >= 63744 && c <= 64109)))
                : (c <= 64217 || (c < 64275
                  ? (c >= 64256 && c <= 64262)
                  : c <= 64279)))))
            : (c <= 64285 || (c < 64326
              ? (c < 64318
                ? (c < 64298
                  ? (c >= 64287 && c <= 64296)
                  : (c <= 64310 || (c >= 64312 && c <= 64316)))
                : (c <= 64318 || (c < 64323
                  ? (c >= 64320 && c <= 64321)
                  : c <= 64324)))
              : (c <= 64433 || (c < 65008
                ? (c < 64848
                  ? (c >= 64467 && c <= 64829)
                  : (c <= 64911 || (c >= 64914 && c <= 64967)))
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65305 || (c < 66816
          ? (c < 65664
            ? (c < 65498
              ? (c < 65474
                ? (c < 65345
                  ? (c >= 65313 && c <= 65338)
                  : (c <= 65370 || (c >= 65382 && c <= 65470)))
                : (c <= 65479 || (c < 65490
                  ? (c >= 65482 && c <= 65487)
                  : c <= 65495)))
              : (c <= 65500 || (c < 65596
                ? (c < 65549
                  ? (c >= 65536 && c <= 65547)
                  : (c <= 65574 || (c >= 65576 && c <= 65594)))
                : (c <= 65597 || (c < 65616
                  ? (c >= 65599 && c <= 65613)
                  : c <= 65629)))))
            : (c <= 65786 || (c < 66432
              ? (c < 66349
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))
                : (c <= 66368 || (c < 66384
                  ? (c >= 66370 && c <= 66377)
                  : c <= 66421)))
              : (c <= 66461 || (c < 66720
                ? (c < 66504
                  ? (c >= 66464 && c <= 66499)
                  : (c <= 66511 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67463
            ? (c < 66979
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : c <= 66977)))
              : (c <= 66993 || (c < 67392
                ? (c < 67003
                  ? (c >= 66995 && c <= 67001)
                  : (c <= 67004 || (c >= 67072 && c <= 67382)))
                : (c <= 67413 || (c < 67456
                  ? (c >= 67424 && c <= 67431)
                  : c <= 67461)))))
            : (c <= 67504 || (c < 67647
              ? (c < 67594
                ? (c < 67584
                  ? (c >= 67506 && c <= 67514)
                  : (c <= 67589 || c == 67592))
                : (c <= 67637 || (c < 67644
                  ? (c >= 67639 && c <= 67640)
                  : c <= 67644)))
              : (c <= 67669 || (c < 67828
                ? (c < 67712
                  ? (c >= 67680 && c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_name_character_set_7(int32_t c) {
  return (c < 6400
    ? (c < 2979
      ? (c < 2365
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < '_'
                ? (c < '0'
                  ? c == '$'
                  : (c <= '9' || (c >= 'A' && c <= 'Z')))
                : (c <= '_' || (c < 170
                  ? (c >= 'b' && c <= 'z')
                  : (c <= 170 || c == 181))))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1749
              ? (c < 1632
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1641 || (c < 1649
                  ? (c >= 1646 && c <= 1647)
                  : c <= 1747)))
              : (c <= 1749 || (c < 1808
                ? (c < 1774
                  ? (c >= 1765 && c <= 1766)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1984 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2185
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : (c <= 2154 || (c >= 2160 && c <= 2183)))
                : (c <= 2190 || (c < 2308
                  ? (c >= 2208 && c <= 2249)
                  : c <= 2361)))))))))
        : (c <= 2365 || (c < 2703
          ? (c < 2534
            ? (c < 2474
              ? (c < 2417
                ? (c < 2392
                  ? c == 2384
                  : (c <= 2401 || (c >= 2406 && c <= 2415)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : (c <= 2448 || (c >= 2451 && c <= 2472)))))
              : (c <= 2480 || (c < 2510
                ? (c < 2486
                  ? c == 2482
                  : (c <= 2489 || c == 2493))
                : (c <= 2510 || (c < 2527
                  ? (c >= 2524 && c <= 2525)
                  : c <= 2529)))))
            : (c <= 2545 || (c < 2613
              ? (c < 2579
                ? (c < 2565
                  ? c == 2556
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))
                : (c <= 2600 || (c < 2610
                  ? (c >= 2602 && c <= 2608)
                  : c <= 2611)))
              : (c <= 2614 || (c < 2662
                ? (c < 2649
                  ? (c >= 2616 && c <= 2617)
                  : (c <= 2652 || c == 2654))
                : (c <= 2671 || (c < 2693
                  ? (c >= 2674 && c <= 2676)
                  : c <= 2701)))))))
          : (c <= 2705 || (c < 2866
            ? (c < 2784
              ? (c < 2741
                ? (c < 2730
                  ? (c >= 2707 && c <= 2728)
                  : (c <= 2736 || (c >= 2738 && c <= 2739)))
                : (c <= 2745 || (c < 2768
                  ? c == 2749
                  : c <= 2768)))
              : (c <= 2785 || (c < 2831
                ? (c < 2809
                  ? (c >= 2790 && c <= 2799)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2947
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2929
                  ? (c >= 2918 && c <= 2927)
                  : c <= 2929)))
              : (c <= 2947 || (c < 2969
                ? (c < 2958
                  ? (c >= 2949 && c <= 2954)
                  : (c <= 2960 || (c >= 2962 && c <= 2965)))
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 3872
        ? (c < 3406
          ? (c < 3205
            ? (c < 3114
              ? (c < 3046
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3055 || (c < 3086
                  ? (c >= 3077 && c <= 3084)
                  : (c <= 3088 || (c >= 3090 && c <= 3112)))))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3200
                  ? (c >= 3174 && c <= 3183)
                  : c <= 3200)))))
            : (c <= 3212 || (c < 3296
              ? (c < 3253
                ? (c < 3218
                  ? (c >= 3214 && c <= 3216)
                  : (c <= 3240 || (c >= 3242 && c <= 3251)))
                : (c <= 3257 || (c < 3293
                  ? c == 3261
                  : c <= 3294)))
              : (c <= 3297 || (c < 3342
                ? (c < 3313
                  ? (c >= 3302 && c <= 3311)
                  : (c <= 3314 || (c >= 3332 && c <= 3340)))
                : (c <= 3344 || (c < 3389
                  ? (c >= 3346 && c <= 3386)
                  : c <= 3389)))))))
          : (c <= 3406 || (c < 3664
            ? (c < 3507
              ? (c < 3450
                ? (c < 3423
                  ? (c >= 3412 && c <= 3414)
                  : (c <= 3425 || (c >= 3430 && c <= 3439)))
                : (c <= 3455 || (c < 3482
                  ? (c >= 3461 && c <= 3478)
                  : c <= 3505)))
              : (c <= 3515 || (c < 3585
                ? (c < 3520
                  ? c == 3517
                  : (c <= 3526 || (c >= 3558 && c <= 3567)))
                : (c <= 3632 || (c < 3648
                  ? (c >= 3634 && c <= 3635)
                  : c <= 3654)))))
            : (c <= 3673 || (c < 3762
              ? (c < 3724
                ? (c < 3716
                  ? (c >= 3713 && c <= 3714)
                  : (c <= 3716 || (c >= 3718 && c <= 3722)))
                : (c <= 3747 || (c < 3751
                  ? c == 3749
                  : c <= 3760)))
              : (c <= 3763 || (c < 3792
                ? (c < 3776
                  ? c == 3773
                  : (c <= 3780 || c == 3782))
                : (c <= 3801 || (c < 3840
                  ? (c >= 3804 && c <= 3807)
                  : c <= 3840)))))))))
        : (c <= 3881 || (c < 4802
          ? (c < 4295
            ? (c < 4193
              ? (c < 4096
                ? (c < 3913
                  ? (c >= 3904 && c <= 3911)
                  : (c <= 3948 || (c >= 3976 && c <= 3980)))
                : (c <= 4138 || (c < 4176
                  ? (c >= 4159 && c <= 4169)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))
              : (c <= 4193 || (c < 4238
                ? (c < 4206
                  ? (c >= 4197 && c <= 4198)
                  : (c <= 4208 || (c >= 4213 && c <= 4225)))
                : (c <= 4238 || (c < 4256
                  ? (c >= 4240 && c <= 4249)
                  : c <= 4293)))))
            : (c <= 4295 || (c < 4698
              ? (c < 4682
                ? (c < 4304
                  ? c == 4301
                  : (c <= 4346 || (c >= 4348 && c <= 4680)))
                : (c <= 4685 || (c < 4696
                  ? (c >= 4688 && c <= 4694)
                  : c <= 4696)))
              : (c <= 4701 || (c < 4786
                ? (c < 4746
                  ? (c >= 4704 && c <= 4744)
                  : (c <= 4749 || (c >= 4752 && c <= 4784)))
                : (c <= 4789 || (c < 4800
                  ? (c >= 4792 && c <= 4798)
                  : c <= 4800)))))))
          : (c <= 4805 || (c < 5919
            ? (c < 5112
              ? (c < 4888
                ? (c < 4824
                  ? (c >= 4808 && c <= 4822)
                  : (c <= 4880 || (c >= 4882 && c <= 4885)))
                : (c <= 4954 || (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : c <= 5109)))
              : (c <= 5117 || (c < 5792
                ? (c < 5743
                  ? (c >= 5121 && c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))
                : (c <= 5866 || (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : c <= 5905)))))
            : (c <= 5937 || (c < 6112
              ? (c < 6016
                ? (c < 5984
                  ? (c >= 5952 && c <= 5969)
                  : (c <= 5996 || (c >= 5998 && c <= 6000)))
                : (c <= 6067 || (c < 6108
                  ? c == 6103
                  : c <= 6108)))
              : (c <= 6121 || (c < 6279
                ? (c < 6176
                  ? (c >= 6160 && c <= 6169)
                  : (c <= 6264 || (c >= 6272 && c <= 6276)))
                : (c <= 6312 || (c < 6320
                  ? c == 6314
                  : c <= 6389)))))))))))))
    : (c <= 6430 || (c < 43216
      ? (c < 8490
        ? (c < 7968
          ? (c < 7086
            ? (c < 6784
              ? (c < 6576
                ? (c < 6512
                  ? (c >= 6470 && c <= 6509)
                  : (c <= 6516 || (c >= 6528 && c <= 6571)))
                : (c <= 6601 || (c < 6656
                  ? (c >= 6608 && c <= 6617)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6793 || (c < 6981
                ? (c < 6823
                  ? (c >= 6800 && c <= 6809)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7043
                  ? (c >= 6992 && c <= 7001)
                  : c <= 7072)))))
            : (c <= 7141 || (c < 7401
              ? (c < 7296
                ? (c < 7232
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7241 || (c >= 7245 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))
              : (c <= 7404 || (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))))))
          : (c <= 8005 || (c < 8160
            ? (c < 8064
              ? (c < 8027
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : (c <= 8023 || c == 8025))
                : (c <= 8027 || (c < 8031
                  ? c == 8029
                  : c <= 8061)))
              : (c <= 8116 || (c < 8134
                ? (c < 8126
                  ? (c >= 8118 && c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))
                : (c <= 8140 || (c < 8150
                  ? (c >= 8144 && c <= 8147)
                  : c <= 8155)))))
            : (c <= 8172 || (c < 8455
              ? (c < 8319
                ? (c < 8182
                  ? (c >= 8178 && c <= 8180)
                  : (c <= 8188 || c == 8305))
                : (c <= 8319 || (c < 8450
                  ? (c >= 8336 && c <= 8348)
                  : c <= 8450)))
              : (c <= 8455 || (c < 8484
                ? (c < 8469
                  ? (c >= 8458 && c <= 8467)
                  : (c <= 8469 || (c >= 8473 && c <= 8477)))
                : (c <= 8484 || (c < 8488
                  ? c == 8486
                  : c <= 8488)))))))))
        : (c <= 8493 || (c < 12449
          ? (c < 11680
            ? (c < 11506
              ? (c < 8526
                ? (c < 8508
                  ? (c >= 8495 && c <= 8505)
                  : (c <= 8511 || (c >= 8517 && c <= 8521)))
                : (c <= 8526 || (c < 11264
                  ? (c >= 8579 && c <= 8580)
                  : (c <= 11492 || (c >= 11499 && c <= 11502)))))
              : (c <= 11507 || (c < 11568
                ? (c < 11559
                  ? (c >= 11520 && c <= 11557)
                  : (c <= 11559 || c == 11565))
                : (c <= 11623 || (c < 11648
                  ? c == 11631
                  : c <= 11670)))))
            : (c <= 11686 || (c < 11736
              ? (c < 11712
                ? (c < 11696
                  ? (c >= 11688 && c <= 11694)
                  : (c <= 11702 || (c >= 11704 && c <= 11710)))
                : (c <= 11718 || (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : c <= 11734)))
              : (c <= 11742 || (c < 12347
                ? (c < 12293
                  ? c == 11823
                  : (c <= 12294 || (c >= 12337 && c <= 12341)))
                : (c <= 12348 || (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)))))))
          : (c <= 12538 || (c < 42623
            ? (c < 19903
              ? (c < 12704
                ? (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : (c <= 12591 || (c >= 12593 && c <= 12686)))
                : (c <= 12735 || (c < 13312
                  ? (c >= 12784 && c <= 12799)
                  : c <= 13312)))
              : (c <= 19903 || (c < 42240
                ? (c < 40959
                  ? c == 19968
                  : (c <= 42124 || (c >= 42192 && c <= 42237)))
                : (c <= 42508 || (c < 42560
                  ? (c >= 42512 && c <= 42539)
                  : c <= 42606)))))
            : (c <= 42653 || (c < 42965
              ? (c < 42891
                ? (c < 42775
                  ? (c >= 42656 && c <= 42725)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))
                : (c <= 42954 || (c < 42963
                  ? (c >= 42960 && c <= 42961)
                  : c <= 42963)))
              : (c <= 42969 || (c < 43020
                ? (c < 43011
                  ? (c >= 42994 && c <= 43009)
                  : (c <= 43013 || (c >= 43015 && c <= 43018)))
                : (c <= 43042 || (c < 43138
                  ? (c >= 43072 && c <= 43123)
                  : c <= 43187)))))))))))
      : (c <= 43225 || (c < 65296
        ? (c < 43808
          ? (c < 43616
            ? (c < 43471
              ? (c < 43264
                ? (c < 43259
                  ? (c >= 43250 && c <= 43255)
                  : (c <= 43259 || (c >= 43261 && c <= 43262)))
                : (c <= 43301 || (c < 43360
                  ? (c >= 43312 && c <= 43334)
                  : (c <= 43388 || (c >= 43396 && c <= 43442)))))
              : (c <= 43481 || (c < 43584
                ? (c < 43494
                  ? (c >= 43488 && c <= 43492)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43600
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43609)))))
            : (c <= 43638 || (c < 43714
              ? (c < 43701
                ? (c < 43646
                  ? c == 43642
                  : (c <= 43695 || c == 43697))
                : (c <= 43702 || (c < 43712
                  ? (c >= 43705 && c <= 43709)
                  : c <= 43712)))
              : (c <= 43714 || (c < 43777
                ? (c < 43744
                  ? (c >= 43739 && c <= 43741)
                  : (c <= 43754 || (c >= 43762 && c <= 43764)))
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64285
            ? (c < 55203
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 44032
                  ? (c >= 44016 && c <= 44025)
                  : c <= 44032)))
              : (c <= 55203 || (c < 64112
                ? (c < 55243
                  ? (c >= 55216 && c <= 55238)
                  : (c <= 55291 || (c >= 63744 && c <= 64109)))
                : (c <= 64217 || (c < 64275
                  ? (c >= 64256 && c <= 64262)
                  : c <= 64279)))))
            : (c <= 64285 || (c < 64326
              ? (c < 64318
                ? (c < 64298
                  ? (c >= 64287 && c <= 64296)
                  : (c <= 64310 || (c >= 64312 && c <= 64316)))
                : (c <= 64318 || (c < 64323
                  ? (c >= 64320 && c <= 64321)
                  : c <= 64324)))
              : (c <= 64433 || (c < 65008
                ? (c < 64848
                  ? (c >= 64467 && c <= 64829)
                  : (c <= 64911 || (c >= 64914 && c <= 64967)))
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65305 || (c < 66816
          ? (c < 65664
            ? (c < 65498
              ? (c < 65474
                ? (c < 65345
                  ? (c >= 65313 && c <= 65338)
                  : (c <= 65370 || (c >= 65382 && c <= 65470)))
                : (c <= 65479 || (c < 65490
                  ? (c >= 65482 && c <= 65487)
                  : c <= 65495)))
              : (c <= 65500 || (c < 65596
                ? (c < 65549
                  ? (c >= 65536 && c <= 65547)
                  : (c <= 65574 || (c >= 65576 && c <= 65594)))
                : (c <= 65597 || (c < 65616
                  ? (c >= 65599 && c <= 65613)
                  : c <= 65629)))))
            : (c <= 65786 || (c < 66432
              ? (c < 66349
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))
                : (c <= 66368 || (c < 66384
                  ? (c >= 66370 && c <= 66377)
                  : c <= 66421)))
              : (c <= 66461 || (c < 66720
                ? (c < 66504
                  ? (c >= 66464 && c <= 66499)
                  : (c <= 66511 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67463
            ? (c < 66979
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : c <= 66977)))
              : (c <= 66993 || (c < 67392
                ? (c < 67003
                  ? (c >= 66995 && c <= 67001)
                  : (c <= 67004 || (c >= 67072 && c <= 67382)))
                : (c <= 67413 || (c < 67456
                  ? (c >= 67424 && c <= 67431)
                  : c <= 67461)))))
            : (c <= 67504 || (c < 67647
              ? (c < 67594
                ? (c < 67584
                  ? (c >= 67506 && c <= 67514)
                  : (c <= 67589 || c == 67592))
                : (c <= 67637 || (c < 67644
                  ? (c >= 67639 && c <= 67640)
                  : c <= 67644)))
              : (c <= 67669 || (c < 67828
                ? (c < 67712
                  ? (c >= 67680 && c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_name_character_set_8(int32_t c) {
  return (c < 6400
    ? (c < 2984
      ? (c < 2384
        ? (c < 1488
          ? (c < 880
            ? (c < 192
              ? (c < 'a'
                ? (c < '0'
                  ? c == '$'
                  : (c <= '9' || (c >= 'A' && c <= 'Z')))
                : (c <= 'z' || (c < 181
                  ? c == 170
                  : (c <= 181 || c == 186))))
              : (c <= 214 || (c < 736
                ? (c < 248
                  ? (c >= 216 && c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))
                : (c <= 740 || (c < 750
                  ? c == 748
                  : c <= 750)))))
            : (c <= 884 || (c < 910
              ? (c < 902
                ? (c < 890
                  ? (c >= 886 && c <= 887)
                  : (c <= 893 || c == 895))
                : (c <= 902 || (c < 908
                  ? (c >= 904 && c <= 906)
                  : c <= 908)))
              : (c <= 929 || (c < 1329
                ? (c < 1015
                  ? (c >= 931 && c <= 1013)
                  : (c <= 1153 || (c >= 1162 && c <= 1327)))
                : (c <= 1366 || (c < 1376
                  ? c == 1369
                  : c <= 1416)))))))
          : (c <= 1514 || (c < 1984
            ? (c < 1765
              ? (c < 1646
                ? (c < 1568
                  ? (c >= 1519 && c <= 1522)
                  : (c <= 1610 || (c >= 1632 && c <= 1641)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1810
                ? (c < 1791
                  ? (c >= 1774 && c <= 1788)
                  : (c <= 1791 || c == 1808))
                : (c <= 1839 || (c < 1969
                  ? (c >= 1869 && c <= 1957)
                  : c <= 1969)))))
            : (c <= 2026 || (c < 2112
              ? (c < 2074
                ? (c < 2042
                  ? (c >= 2036 && c <= 2037)
                  : (c <= 2042 || (c >= 2048 && c <= 2069)))
                : (c <= 2074 || (c < 2088
                  ? c == 2084
                  : c <= 2088)))
              : (c <= 2136 || (c < 2208
                ? (c < 2160
                  ? (c >= 2144 && c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))
                : (c <= 2249 || (c < 2365
                  ? (c >= 2308 && c <= 2361)
                  : c <= 2365)))))))))
        : (c <= 2384 || (c < 2707
          ? (c < 2556
            ? (c < 2482
              ? (c < 2437
                ? (c < 2406
                  ? (c >= 2392 && c <= 2401)
                  : (c <= 2415 || (c >= 2417 && c <= 2432)))
                : (c <= 2444 || (c < 2451
                  ? (c >= 2447 && c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))
              : (c <= 2482 || (c < 2524
                ? (c < 2493
                  ? (c >= 2486 && c <= 2489)
                  : (c <= 2493 || c == 2510))
                : (c <= 2525 || (c < 2534
                  ? (c >= 2527 && c <= 2529)
                  : c <= 2545)))))
            : (c <= 2556 || (c < 2616
              ? (c < 2602
                ? (c < 2575
                  ? (c >= 2565 && c <= 2570)
                  : (c <= 2576 || (c >= 2579 && c <= 2600)))
                : (c <= 2608 || (c < 2613
                  ? (c >= 2610 && c <= 2611)
                  : c <= 2614)))
              : (c <= 2617 || (c < 2674
                ? (c < 2654
                  ? (c >= 2649 && c <= 2652)
                  : (c <= 2654 || (c >= 2662 && c <= 2671)))
                : (c <= 2676 || (c < 2703
                  ? (c >= 2693 && c <= 2701)
                  : c <= 2705)))))))
          : (c <= 2728 || (c < 2869
            ? (c < 2790
              ? (c < 2749
                ? (c < 2738
                  ? (c >= 2730 && c <= 2736)
                  : (c <= 2739 || (c >= 2741 && c <= 2745)))
                : (c <= 2749 || (c < 2784
                  ? c == 2768
                  : c <= 2785)))
              : (c <= 2799 || (c < 2835
                ? (c < 2821
                  ? c == 2809
                  : (c <= 2828 || (c >= 2831 && c <= 2832)))
                : (c <= 2856 || (c < 2866
                  ? (c >= 2858 && c <= 2864)
                  : c <= 2867)))))
            : (c <= 2873 || (c < 2949
              ? (c < 2918
                ? (c < 2908
                  ? c == 2877
                  : (c <= 2909 || (c >= 2911 && c <= 2913)))
                : (c <= 2927 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2972
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : (c <= 2965 || (c >= 2969 && c <= 2970)))
                : (c <= 2972 || (c < 2979
                  ? (c >= 2974 && c <= 2975)
                  : c <= 2980)))))))))))
      : (c <= 2986 || (c < 3904
        ? (c < 3412
          ? (c < 3214
            ? (c < 3133
              ? (c < 3077
                ? (c < 3024
                  ? (c >= 2990 && c <= 3001)
                  : (c <= 3024 || (c >= 3046 && c <= 3055)))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : (c <= 3112 || (c >= 3114 && c <= 3129)))))
              : (c <= 3133 || (c < 3174
                ? (c < 3165
                  ? (c >= 3160 && c <= 3162)
                  : (c <= 3165 || (c >= 3168 && c <= 3169)))
                : (c <= 3183 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3302
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3311 || (c < 3346
                ? (c < 3332
                  ? (c >= 3313 && c <= 3314)
                  : (c <= 3340 || (c >= 3342 && c <= 3344)))
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3713
            ? (c < 3517
              ? (c < 3461
                ? (c < 3430
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3439 || (c >= 3450 && c <= 3455)))
                : (c <= 3478 || (c < 3507
                  ? (c >= 3482 && c <= 3505)
                  : c <= 3515)))
              : (c <= 3517 || (c < 3634
                ? (c < 3558
                  ? (c >= 3520 && c <= 3526)
                  : (c <= 3567 || (c >= 3585 && c <= 3632)))
                : (c <= 3635 || (c < 3664
                  ? (c >= 3648 && c <= 3654)
                  : c <= 3673)))))
            : (c <= 3714 || (c < 3773
              ? (c < 3749
                ? (c < 3718
                  ? c == 3716
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3762
                  ? (c >= 3751 && c <= 3760)
                  : c <= 3763)))
              : (c <= 3773 || (c < 3804
                ? (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : (c <= 3782 || (c >= 3792 && c <= 3801)))
                : (c <= 3807 || (c < 3872
                  ? c == 3840
                  : c <= 3881)))))))))
        : (c <= 3911 || (c < 4802
          ? (c < 4295
            ? (c < 4193
              ? (c < 4159
                ? (c < 3976
                  ? (c >= 3913 && c <= 3948)
                  : (c <= 3980 || (c >= 4096 && c <= 4138)))
                : (c <= 4169 || (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : c <= 4189)))
              : (c <= 4193 || (c < 4238
                ? (c < 4206
                  ? (c >= 4197 && c <= 4198)
                  : (c <= 4208 || (c >= 4213 && c <= 4225)))
                : (c <= 4238 || (c < 4256
                  ? (c >= 4240 && c <= 4249)
                  : c <= 4293)))))
            : (c <= 4295 || (c < 4698
              ? (c < 4682
                ? (c < 4304
                  ? c == 4301
                  : (c <= 4346 || (c >= 4348 && c <= 4680)))
                : (c <= 4685 || (c < 4696
                  ? (c >= 4688 && c <= 4694)
                  : c <= 4696)))
              : (c <= 4701 || (c < 4786
                ? (c < 4746
                  ? (c >= 4704 && c <= 4744)
                  : (c <= 4749 || (c >= 4752 && c <= 4784)))
                : (c <= 4789 || (c < 4800
                  ? (c >= 4792 && c <= 4798)
                  : c <= 4800)))))))
          : (c <= 4805 || (c < 5919
            ? (c < 5112
              ? (c < 4888
                ? (c < 4824
                  ? (c >= 4808 && c <= 4822)
                  : (c <= 4880 || (c >= 4882 && c <= 4885)))
                : (c <= 4954 || (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : c <= 5109)))
              : (c <= 5117 || (c < 5792
                ? (c < 5743
                  ? (c >= 5121 && c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))
                : (c <= 5866 || (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : c <= 5905)))))
            : (c <= 5937 || (c < 6112
              ? (c < 6016
                ? (c < 5984
                  ? (c >= 5952 && c <= 5969)
                  : (c <= 5996 || (c >= 5998 && c <= 6000)))
                : (c <= 6067 || (c < 6108
                  ? c == 6103
                  : c <= 6108)))
              : (c <= 6121 || (c < 6279
                ? (c < 6176
                  ? (c >= 6160 && c <= 6169)
                  : (c <= 6264 || (c >= 6272 && c <= 6276)))
                : (c <= 6312 || (c < 6320
                  ? c == 6314
                  : c <= 6389)))))))))))))
    : (c <= 6430 || (c < 43216
      ? (c < 8490
        ? (c < 7968
          ? (c < 7086
            ? (c < 6784
              ? (c < 6576
                ? (c < 6512
                  ? (c >= 6470 && c <= 6509)
                  : (c <= 6516 || (c >= 6528 && c <= 6571)))
                : (c <= 6601 || (c < 6656
                  ? (c >= 6608 && c <= 6617)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6793 || (c < 6981
                ? (c < 6823
                  ? (c >= 6800 && c <= 6809)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7043
                  ? (c >= 6992 && c <= 7001)
                  : c <= 7072)))))
            : (c <= 7141 || (c < 7401
              ? (c < 7296
                ? (c < 7232
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7241 || (c >= 7245 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))
              : (c <= 7404 || (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))))))
          : (c <= 8005 || (c < 8160
            ? (c < 8064
              ? (c < 8027
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : (c <= 8023 || c == 8025))
                : (c <= 8027 || (c < 8031
                  ? c == 8029
                  : c <= 8061)))
              : (c <= 8116 || (c < 8134
                ? (c < 8126
                  ? (c >= 8118 && c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))
                : (c <= 8140 || (c < 8150
                  ? (c >= 8144 && c <= 8147)
                  : c <= 8155)))))
            : (c <= 8172 || (c < 8455
              ? (c < 8319
                ? (c < 8182
                  ? (c >= 8178 && c <= 8180)
                  : (c <= 8188 || c == 8305))
                : (c <= 8319 || (c < 8450
                  ? (c >= 8336 && c <= 8348)
                  : c <= 8450)))
              : (c <= 8455 || (c < 8484
                ? (c < 8469
                  ? (c >= 8458 && c <= 8467)
                  : (c <= 8469 || (c >= 8473 && c <= 8477)))
                : (c <= 8484 || (c < 8488
                  ? c == 8486
                  : c <= 8488)))))))))
        : (c <= 8493 || (c < 12449
          ? (c < 11680
            ? (c < 11506
              ? (c < 8526
                ? (c < 8508
                  ? (c >= 8495 && c <= 8505)
                  : (c <= 8511 || (c >= 8517 && c <= 8521)))
                : (c <= 8526 || (c < 11264
                  ? (c >= 8579 && c <= 8580)
                  : (c <= 11492 || (c >= 11499 && c <= 11502)))))
              : (c <= 11507 || (c < 11568
                ? (c < 11559
                  ? (c >= 11520 && c <= 11557)
                  : (c <= 11559 || c == 11565))
                : (c <= 11623 || (c < 11648
                  ? c == 11631
                  : c <= 11670)))))
            : (c <= 11686 || (c < 11736
              ? (c < 11712
                ? (c < 11696
                  ? (c >= 11688 && c <= 11694)
                  : (c <= 11702 || (c >= 11704 && c <= 11710)))
                : (c <= 11718 || (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : c <= 11734)))
              : (c <= 11742 || (c < 12347
                ? (c < 12293
                  ? c == 11823
                  : (c <= 12294 || (c >= 12337 && c <= 12341)))
                : (c <= 12348 || (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)))))))
          : (c <= 12538 || (c < 42623
            ? (c < 19903
              ? (c < 12704
                ? (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : (c <= 12591 || (c >= 12593 && c <= 12686)))
                : (c <= 12735 || (c < 13312
                  ? (c >= 12784 && c <= 12799)
                  : c <= 13312)))
              : (c <= 19903 || (c < 42240
                ? (c < 40959
                  ? c == 19968
                  : (c <= 42124 || (c >= 42192 && c <= 42237)))
                : (c <= 42508 || (c < 42560
                  ? (c >= 42512 && c <= 42539)
                  : c <= 42606)))))
            : (c <= 42653 || (c < 42965
              ? (c < 42891
                ? (c < 42775
                  ? (c >= 42656 && c <= 42725)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))
                : (c <= 42954 || (c < 42963
                  ? (c >= 42960 && c <= 42961)
                  : c <= 42963)))
              : (c <= 42969 || (c < 43020
                ? (c < 43011
                  ? (c >= 42994 && c <= 43009)
                  : (c <= 43013 || (c >= 43015 && c <= 43018)))
                : (c <= 43042 || (c < 43138
                  ? (c >= 43072 && c <= 43123)
                  : c <= 43187)))))))))))
      : (c <= 43225 || (c < 65296
        ? (c < 43808
          ? (c < 43616
            ? (c < 43471
              ? (c < 43264
                ? (c < 43259
                  ? (c >= 43250 && c <= 43255)
                  : (c <= 43259 || (c >= 43261 && c <= 43262)))
                : (c <= 43301 || (c < 43360
                  ? (c >= 43312 && c <= 43334)
                  : (c <= 43388 || (c >= 43396 && c <= 43442)))))
              : (c <= 43481 || (c < 43584
                ? (c < 43494
                  ? (c >= 43488 && c <= 43492)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43600
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43609)))))
            : (c <= 43638 || (c < 43714
              ? (c < 43701
                ? (c < 43646
                  ? c == 43642
                  : (c <= 43695 || c == 43697))
                : (c <= 43702 || (c < 43712
                  ? (c >= 43705 && c <= 43709)
                  : c <= 43712)))
              : (c <= 43714 || (c < 43777
                ? (c < 43744
                  ? (c >= 43739 && c <= 43741)
                  : (c <= 43754 || (c >= 43762 && c <= 43764)))
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64285
            ? (c < 55203
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 44032
                  ? (c >= 44016 && c <= 44025)
                  : c <= 44032)))
              : (c <= 55203 || (c < 64112
                ? (c < 55243
                  ? (c >= 55216 && c <= 55238)
                  : (c <= 55291 || (c >= 63744 && c <= 64109)))
                : (c <= 64217 || (c < 64275
                  ? (c >= 64256 && c <= 64262)
                  : c <= 64279)))))
            : (c <= 64285 || (c < 64326
              ? (c < 64318
                ? (c < 64298
                  ? (c >= 64287 && c <= 64296)
                  : (c <= 64310 || (c >= 64312 && c <= 64316)))
                : (c <= 64318 || (c < 64323
                  ? (c >= 64320 && c <= 64321)
                  : c <= 64324)))
              : (c <= 64433 || (c < 65008
                ? (c < 64848
                  ? (c >= 64467 && c <= 64829)
                  : (c <= 64911 || (c >= 64914 && c <= 64967)))
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65305 || (c < 66816
          ? (c < 65664
            ? (c < 65498
              ? (c < 65474
                ? (c < 65345
                  ? (c >= 65313 && c <= 65338)
                  : (c <= 65370 || (c >= 65382 && c <= 65470)))
                : (c <= 65479 || (c < 65490
                  ? (c >= 65482 && c <= 65487)
                  : c <= 65495)))
              : (c <= 65500 || (c < 65596
                ? (c < 65549
                  ? (c >= 65536 && c <= 65547)
                  : (c <= 65574 || (c >= 65576 && c <= 65594)))
                : (c <= 65597 || (c < 65616
                  ? (c >= 65599 && c <= 65613)
                  : c <= 65629)))))
            : (c <= 65786 || (c < 66432
              ? (c < 66349
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))
                : (c <= 66368 || (c < 66384
                  ? (c >= 66370 && c <= 66377)
                  : c <= 66421)))
              : (c <= 66461 || (c < 66720
                ? (c < 66504
                  ? (c >= 66464 && c <= 66499)
                  : (c <= 66511 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67463
            ? (c < 66979
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : c <= 66977)))
              : (c <= 66993 || (c < 67392
                ? (c < 67003
                  ? (c >= 66995 && c <= 67001)
                  : (c <= 67004 || (c >= 67072 && c <= 67382)))
                : (c <= 67413 || (c < 67456
                  ? (c >= 67424 && c <= 67431)
                  : c <= 67461)))))
            : (c <= 67504 || (c < 67647
              ? (c < 67594
                ? (c < 67584
                  ? (c >= 67506 && c <= 67514)
                  : (c <= 67589 || c == 67592))
                : (c <= 67637 || (c < 67644
                  ? (c >= 67639 && c <= 67640)
                  : c <= 67644)))
              : (c <= 67669 || (c < 67828
                ? (c < 67712
                  ? (c >= 67680 && c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(365);
      if (lookahead == '\n') ADVANCE(789);
      if (lookahead == ' ') ADVANCE(774);
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == '\'') ADVANCE(771);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(780);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == ':') ADVANCE(421);
      if (lookahead == ';') ADVANCE(392);
      if (lookahead == '<') ADVANCE(383);
      if (lookahead == '=') ADVANCE(380);
      if (lookahead == '>') ADVANCE(386);
      if (lookahead == '@') ADVANCE(474);
      if (lookahead == '[') ADVANCE(423);
      if (lookahead == ']') ADVANCE(424);
      if (lookahead == '_') ADVANCE(394);
      if (lookahead == '{') ADVANCE(388);
      if (lookahead == '|') ADVANCE(431);
      if (lookahead == '}') ADVANCE(389);
      if (('\t' <= lookahead && lookahead <= '\r')) ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      if (lookahead != 0) ADVANCE(776);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(773);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'A') ADVANCE(727);
      if (lookahead == 'B') ADVANCE(614);
      if (lookahead == 'C') ADVANCE(517);
      if (lookahead == 'D') ADVANCE(514);
      if (lookahead == 'E') ADVANCE(547);
      if (lookahead == 'F') ADVANCE(590);
      if (lookahead == 'G') ADVANCE(734);
      if (lookahead == 'H') ADVANCE(705);
      if (lookahead == 'I') ADVANCE(570);
      if (lookahead == 'J') ADVANCE(633);
      if (lookahead == 'L') ADVANCE(709);
      if (lookahead == 'M') ADVANCE(668);
      if (lookahead == 'O') ADVANCE(735);
      if (lookahead == 'P') ADVANCE(630);
      if (lookahead == 'S') ADVANCE(654);
      if (lookahead == 'T') ADVANCE(661);
      if (lookahead == 'U') ADVANCE(578);
      if (lookahead == 'V') ADVANCE(563);
      if (lookahead == 'W') ADVANCE(576);
      if (lookahead == '}') ADVANCE(389);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_1(lookahead)) ADVANCE(762);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(774);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == ':') ADVANCE(421);
      if (lookahead == '>') ADVANCE(386);
      if (('\t' <= lookahead && lookahead <= '\r')) ADVANCE(772);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(430);
      END_STATE();
    case 4:
      if (lookahead == '!') ADVANCE(31);
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(780);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == ';') ADVANCE(392);
      if (lookahead == '<') ADVANCE(385);
      if (lookahead == '=') ADVANCE(33);
      if (lookahead == '>') ADVANCE(387);
      if (lookahead == 'A') ADVANCE(67);
      if (lookahead == 'B') ADVANCE(113);
      if (lookahead == 'D') ADVANCE(190);
      if (lookahead == 'E') ADVANCE(151);
      if (lookahead == 'I') ADVANCE(177);
      if (lookahead == 'L') ADVANCE(135);
      if (lookahead == 'M') ADVANCE(137);
      if (lookahead == 'N') ADVANCE(191);
      if (lookahead == 'O') ADVANCE(120);
      if (lookahead == 'P') ADVANCE(199);
      if (lookahead == 'T') ADVANCE(127);
      if (lookahead == 'U') ADVANCE(171);
      if (lookahead == 'W') ADVANCE(129);
      if (lookahead == '[') ADVANCE(423);
      if (lookahead == ']') ADVANCE(424);
      if (lookahead == '|') ADVANCE(431);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      END_STATE();
    case 5:
      if (lookahead == '!') ADVANCE(31);
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(780);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(429);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == '<') ADVANCE(385);
      if (lookahead == '=') ADVANCE(33);
      if (lookahead == '>') ADVANCE(387);
      if (lookahead == 'A') ADVANCE(170);
      if (lookahead == 'B') ADVANCE(113);
      if (lookahead == 'D') ADVANCE(104);
      if (lookahead == 'I') ADVANCE(177);
      if (lookahead == 'L') ADVANCE(136);
      if (lookahead == 'M') ADVANCE(137);
      if (lookahead == 'N') ADVANCE(191);
      if (lookahead == 'O') ADVANCE(207);
      if (lookahead == 'U') ADVANCE(171);
      if (lookahead == '|') ADVANCE(431);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      END_STATE();
    case 6:
      if (lookahead == '!') ADVANCE(31);
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(780);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == ':') ADVANCE(421);
      if (lookahead == ';') ADVANCE(392);
      if (lookahead == '<') ADVANCE(385);
      if (lookahead == '=') ADVANCE(33);
      if (lookahead == '>') ADVANCE(387);
      if (lookahead == 'A') ADVANCE(67);
      if (lookahead == 'B') ADVANCE(113);
      if (lookahead == 'D') ADVANCE(190);
      if (lookahead == 'E') ADVANCE(151);
      if (lookahead == 'I') ADVANCE(180);
      if (lookahead == 'L') ADVANCE(135);
      if (lookahead == 'M') ADVANCE(140);
      if (lookahead == 'N') ADVANCE(191);
      if (lookahead == 'O') ADVANCE(120);
      if (lookahead == 'P') ADVANCE(199);
      if (lookahead == 'T') ADVANCE(127);
      if (lookahead == 'W') ADVANCE(129);
      if (lookahead == '[') ADVANCE(423);
      if (lookahead == ']') ADVANCE(424);
      if (lookahead == '|') ADVANCE(431);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      END_STATE();
    case 7:
      if (lookahead == '!') ADVANCE(31);
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(780);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(429);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == '<') ADVANCE(385);
      if (lookahead == '=') ADVANCE(33);
      if (lookahead == '>') ADVANCE(387);
      if (lookahead == 'A') ADVANCE(169);
      if (lookahead == 'B') ADVANCE(113);
      if (lookahead == 'I') ADVANCE(180);
      if (lookahead == 'L') ADVANCE(136);
      if (lookahead == 'N') ADVANCE(191);
      if (lookahead == 'O') ADVANCE(207);
      if (lookahead == '|') ADVANCE(431);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      END_STATE();
    case 8:
      if (lookahead == '!') ADVANCE(31);
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(781);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == ':') ADVANCE(421);
      if (lookahead == ';') ADVANCE(392);
      if (lookahead == '<') ADVANCE(385);
      if (lookahead == '=') ADVANCE(381);
      if (lookahead == '>') ADVANCE(387);
      if (lookahead == 'A') ADVANCE(67);
      if (lookahead == 'B') ADVANCE(113);
      if (lookahead == 'D') ADVANCE(190);
      if (lookahead == 'E') ADVANCE(151);
      if (lookahead == 'I') ADVANCE(177);
      if (lookahead == 'L') ADVANCE(135);
      if (lookahead == 'M') ADVANCE(137);
      if (lookahead == 'N') ADVANCE(191);
      if (lookahead == 'O') ADVANCE(120);
      if (lookahead == 'P') ADVANCE(199);
      if (lookahead == 'T') ADVANCE(127);
      if (lookahead == 'U') ADVANCE(171);
      if (lookahead == 'W') ADVANCE(129);
      if (lookahead == '[') ADVANCE(423);
      if (lookahead == ']') ADVANCE(424);
      if (lookahead == '|') ADVANCE(431);
      if (lookahead == '}') ADVANCE(389);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '\'') ADVANCE(771);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'C') ADVANCE(617);
      if (lookahead == 'F') ADVANCE(520);
      if (lookahead == 'G') ADVANCE(631);
      if (lookahead == 'I') ADVANCE(635);
      if (lookahead == 'T') ADVANCE(624);
      if (lookahead == '[') ADVANCE(423);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '\'') ADVANCE(771);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == '+') ADVANCE(32);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '=') ADVANCE(380);
      if (lookahead == '>') ADVANCE(386);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'C') ADVANCE(617);
      if (lookahead == 'F') ADVANCE(520);
      if (lookahead == 'G') ADVANCE(631);
      if (lookahead == 'I') ADVANCE(635);
      if (lookahead == 'S') ADVANCE(569);
      if (lookahead == 'T') ADVANCE(624);
      if (lookahead == '[') ADVANCE(423);
      if (lookahead == '{') ADVANCE(388);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 11:
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '\'') ADVANCE(771);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '<') ADVANCE(383);
      if (lookahead == '>') ADVANCE(386);
      if (lookahead == '@') ADVANCE(475);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 12:
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '\'') ADVANCE(771);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'C') ADVANCE(617);
      if (lookahead == 'F') ADVANCE(520);
      if (lookahead == 'G') ADVANCE(631);
      if (lookahead == 'I') ADVANCE(635);
      if (lookahead == 'N') ADVANCE(620);
      if (lookahead == 'T') ADVANCE(624);
      if (lookahead == '[') ADVANCE(423);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '\'') ADVANCE(771);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'C') ADVANCE(617);
      if (lookahead == 'F') ADVANCE(520);
      if (lookahead == 'G') ADVANCE(631);
      if (lookahead == 'I') ADVANCE(635);
      if (lookahead == 'T') ADVANCE(624);
      if (lookahead == 'W') ADVANCE(577);
      if (lookahead == '[') ADVANCE(423);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 14:
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '/') ADVANCE(777);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (lookahead != 0) ADVANCE(776);
      END_STATE();
    case 15:
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(780);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(429);
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == '<') ADVANCE(30);
      if (lookahead == '>') ADVANCE(34);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'A') ADVANCE(727);
      if (lookahead == 'B') ADVANCE(614);
      if (lookahead == 'C') ADVANCE(517);
      if (lookahead == 'D') ADVANCE(514);
      if (lookahead == 'E') ADVANCE(547);
      if (lookahead == 'F') ADVANCE(590);
      if (lookahead == 'G') ADVANCE(734);
      if (lookahead == 'H') ADVANCE(705);
      if (lookahead == 'I') ADVANCE(570);
      if (lookahead == 'J') ADVANCE(633);
      if (lookahead == 'L') ADVANCE(709);
      if (lookahead == 'M') ADVANCE(668);
      if (lookahead == 'O') ADVANCE(735);
      if (lookahead == 'P') ADVANCE(630);
      if (lookahead == 'S') ADVANCE(654);
      if (lookahead == 'U') ADVANCE(578);
      if (lookahead == 'V') ADVANCE(563);
      if (lookahead == 'W') ADVANCE(576);
      if (lookahead == '|') ADVANCE(431);
      if (lookahead == '}') ADVANCE(389);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_1(lookahead)) ADVANCE(762);
      END_STATE();
    case 16:
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '<') ADVANCE(383);
      if (lookahead == '>') ADVANCE(386);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == 'A') ADVANCE(607);
      if (lookahead == '_') ADVANCE(395);
      if (lookahead == '}') ADVANCE(389);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_3(lookahead)) ADVANCE(762);
      END_STATE();
    case 17:
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == 'D') ADVANCE(582);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 18:
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == 'R') ADVANCE(524);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 19:
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '+') ADVANCE(32);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == ';') ADVANCE(392);
      if (lookahead == 'B') ADVANCE(195);
      if (lookahead == 'D') ADVANCE(52);
      if (lookahead == 'E') ADVANCE(82);
      if (lookahead == 'F') ADVANCE(155);
      if (lookahead == 'I') ADVANCE(187);
      if (lookahead == 'J') ADVANCE(228);
      if (lookahead == 'L') ADVANCE(132);
      if (lookahead == 'P') ADVANCE(199);
      if (lookahead == 'S') ADVANCE(114);
      if (lookahead == 'U') ADVANCE(145);
      if (lookahead == 'V') ADVANCE(110);
      if (lookahead == 'W') ADVANCE(130);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      END_STATE();
    case 20:
      if (lookahead == '*') ADVANCE(795);
      if (lookahead == '/') ADVANCE(798);
      END_STATE();
    case 21:
      if (lookahead == '*') ADVANCE(397);
      END_STATE();
    case 22:
      if (lookahead == '+') ADVANCE(32);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == ':') ADVANCE(421);
      if (lookahead == ';') ADVANCE(392);
      if (lookahead == '=') ADVANCE(380);
      if (lookahead == 'E') ADVANCE(151);
      if (lookahead == 'I') ADVANCE(179);
      if (lookahead == 'L') ADVANCE(132);
      if (lookahead == 'P') ADVANCE(199);
      if (lookahead == 'W') ADVANCE(130);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      END_STATE();
    case 23:
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '<') ADVANCE(383);
      if (lookahead == '>') ADVANCE(386);
      if (lookahead == 'B') ADVANCE(615);
      if (lookahead == 'D') ADVANCE(514);
      if (lookahead == 'E') ADVANCE(547);
      if (lookahead == 'F') ADVANCE(591);
      if (lookahead == 'I') ADVANCE(604);
      if (lookahead == 'J') ADVANCE(633);
      if (lookahead == 'S') ADVANCE(655);
      if (lookahead == 'U') ADVANCE(578);
      if (lookahead == 'V') ADVANCE(563);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(45);
      END_STATE();
    case 25:
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'B') ADVANCE(615);
      if (lookahead == 'C') ADVANCE(517);
      if (lookahead == 'D') ADVANCE(514);
      if (lookahead == 'E') ADVANCE(547);
      if (lookahead == 'F') ADVANCE(590);
      if (lookahead == 'I') ADVANCE(570);
      if (lookahead == 'J') ADVANCE(633);
      if (lookahead == 'S') ADVANCE(655);
      if (lookahead == 'U') ADVANCE(578);
      if (lookahead == 'V') ADVANCE(563);
      if (lookahead == 'W') ADVANCE(576);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_2(lookahead)) ADVANCE(762);
      END_STATE();
    case 26:
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'A') ADVANCE(727);
      if (lookahead == 'B') ADVANCE(614);
      if (lookahead == 'D') ADVANCE(514);
      if (lookahead == 'E') ADVANCE(547);
      if (lookahead == 'F') ADVANCE(591);
      if (lookahead == 'G') ADVANCE(734);
      if (lookahead == 'H') ADVANCE(705);
      if (lookahead == 'I') ADVANCE(604);
      if (lookahead == 'J') ADVANCE(633);
      if (lookahead == 'L') ADVANCE(709);
      if (lookahead == 'M') ADVANCE(668);
      if (lookahead == 'O') ADVANCE(735);
      if (lookahead == 'S') ADVANCE(654);
      if (lookahead == 'U') ADVANCE(578);
      if (lookahead == 'V') ADVANCE(563);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (sym_name_character_set_4(lookahead)) ADVANCE(762);
      END_STATE();
    case 27:
      if (lookahead == '/') ADVANCE(777);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (lookahead != 0) ADVANCE(776);
      END_STATE();
    case 28:
      if (lookahead == '2') ADVANCE(374);
      END_STATE();
    case 29:
      if (lookahead == '2') ADVANCE(375);
      END_STATE();
    case 30:
      if (lookahead == '<') ADVANCE(782);
      END_STATE();
    case 31:
      if (lookahead == '=') ADVANCE(788);
      END_STATE();
    case 32:
      if (lookahead == '=') ADVANCE(401);
      END_STATE();
    case 33:
      if (lookahead == '=') ADVANCE(787);
      END_STATE();
    case 34:
      if (lookahead == '>') ADVANCE(783);
      END_STATE();
    case 35:
      if (lookahead == '@') ADVANCE(473);
      END_STATE();
    case 36:
      if (lookahead == 'A') ADVANCE(160);
      if (lookahead == 'I') ADVANCE(159);
      if (lookahead == 'O') ADVANCE(208);
      if (lookahead == 'R') ADVANCE(193);
      END_STATE();
    case 37:
      if (lookahead == 'A') ADVANCE(263);
      if (lookahead == 'I') ADVANCE(183);
      if (lookahead == 'a') ADVANCE(336);
      if (lookahead == 'i') ADVANCE(332);
      END_STATE();
    case 38:
      if (lookahead == 'A') ADVANCE(280);
      END_STATE();
    case 39:
      if (lookahead == 'A') ADVANCE(264);
      END_STATE();
    case 40:
      if (lookahead == 'A') ADVANCE(201);
      END_STATE();
    case 41:
      if (lookahead == 'A') ADVANCE(269);
      END_STATE();
    case 42:
      if (lookahead == 'A') ADVANCE(265);
      END_STATE();
    case 43:
      if (lookahead == 'A') ADVANCE(75);
      END_STATE();
    case 44:
      if (lookahead == 'A') ADVANCE(266);
      if (lookahead == 'I') ADVANCE(176);
      END_STATE();
    case 45:
      if (lookahead == 'A') ADVANCE(78);
      END_STATE();
    case 46:
      if (lookahead == 'A') ADVANCE(215);
      if (lookahead == 'O') ADVANCE(64);
      END_STATE();
    case 47:
      if (lookahead == 'A') ADVANCE(241);
      END_STATE();
    case 48:
      if (lookahead == 'A') ADVANCE(282);
      END_STATE();
    case 49:
      if (lookahead == 'A') ADVANCE(249);
      END_STATE();
    case 50:
      if (lookahead == 'A') ADVANCE(284);
      END_STATE();
    case 51:
      if (lookahead == 'A') ADVANCE(286);
      END_STATE();
    case 52:
      if (lookahead == 'A') ADVANCE(251);
      if (lookahead == 'O') ADVANCE(254);
      END_STATE();
    case 53:
      if (lookahead == 'A') ADVANCE(288);
      END_STATE();
    case 54:
      if (lookahead == 'A') ADVANCE(290);
      END_STATE();
    case 55:
      if (lookahead == 'A') ADVANCE(292);
      END_STATE();
    case 56:
      if (lookahead == 'A') ADVANCE(294);
      END_STATE();
    case 57:
      if (lookahead == 'A') ADVANCE(296);
      END_STATE();
    case 58:
      if (lookahead == 'A') ADVANCE(298);
      END_STATE();
    case 59:
      if (lookahead == 'A') ADVANCE(300);
      END_STATE();
    case 60:
      if (lookahead == 'A') ADVANCE(302);
      END_STATE();
    case 61:
      if (lookahead == 'A') ADVANCE(304);
      END_STATE();
    case 62:
      if (lookahead == 'A') ADVANCE(306);
      END_STATE();
    case 63:
      if (lookahead == 'A') ADVANCE(308);
      END_STATE();
    case 64:
      if (lookahead == 'B') ADVANCE(146);
      END_STATE();
    case 65:
      if (lookahead == 'B') ADVANCE(260);
      END_STATE();
    case 66:
      if (lookahead == 'B') ADVANCE(158);
      END_STATE();
    case 67:
      if (lookahead == 'C') ADVANCE(71);
      if (lookahead == 'N') ADVANCE(79);
      if (lookahead == 'S') ADVANCE(499);
      END_STATE();
    case 68:
      if (lookahead == 'C') ADVANCE(71);
      if (lookahead == 'N') ADVANCE(79);
      if (lookahead == 'S') ADVANCE(499);
      if (lookahead == 'V') ADVANCE(123);
      if (lookahead == 'n') ADVANCE(309);
      if (lookahead == 'r') ADVANCE(338);
      if (lookahead == 'v') ADVANCE(313);
      END_STATE();
    case 69:
      if (lookahead == 'C') ADVANCE(467);
      END_STATE();
    case 70:
      if (lookahead == 'C') ADVANCE(468);
      END_STATE();
    case 71:
      if (lookahead == 'C') ADVANCE(257);
      END_STATE();
    case 72:
      if (lookahead == 'C') ADVANCE(221);
      END_STATE();
    case 73:
      if (lookahead == 'C') ADVANCE(234);
      END_STATE();
    case 74:
      if (lookahead == 'C') ADVANCE(236);
      END_STATE();
    case 75:
      if (lookahead == 'C') ADVANCE(91);
      END_STATE();
    case 76:
      if (lookahead == 'C') ADVANCE(242);
      END_STATE();
    case 77:
      if (lookahead == 'C') ADVANCE(258);
      END_STATE();
    case 78:
      if (lookahead == 'C') ADVANCE(77);
      END_STATE();
    case 79:
      if (lookahead == 'D') ADVANCE(486);
      END_STATE();
    case 80:
      if (lookahead == 'D') ADVANCE(411);
      END_STATE();
    case 81:
      if (lookahead == 'D') ADVANCE(369);
      END_STATE();
    case 82:
      if (lookahead == 'D') ADVANCE(125);
      if (lookahead == 'L') ADVANCE(224);
      if (lookahead == 'N') ADVANCE(80);
      END_STATE();
    case 83:
      if (lookahead == 'E') ADVANCE(202);
      END_STATE();
    case 84:
      if (lookahead == 'E') ADVANCE(174);
      END_STATE();
    case 85:
      if (lookahead == 'E') ADVANCE(410);
      END_STATE();
    case 86:
      if (lookahead == 'E') ADVANCE(487);
      END_STATE();
    case 87:
      if (lookahead == 'E') ADVANCE(489);
      END_STATE();
    case 88:
      if (lookahead == 'E') ADVANCE(391);
      END_STATE();
    case 89:
      if (lookahead == 'E') ADVANCE(405);
      END_STATE();
    case 90:
      if (lookahead == 'E') ADVANCE(366);
      END_STATE();
    case 91:
      if (lookahead == 'E') ADVANCE(368);
      END_STATE();
    case 92:
      if (lookahead == 'E') ADVANCE(491);
      END_STATE();
    case 93:
      if (lookahead == 'E') ADVANCE(506);
      END_STATE();
    case 94:
      if (lookahead == 'E') ADVANCE(439);
      END_STATE();
    case 95:
      if (lookahead == 'E') ADVANCE(512);
      END_STATE();
    case 96:
      if (lookahead == 'E') ADVANCE(209);
      END_STATE();
    case 97:
      if (lookahead == 'E') ADVANCE(73);
      END_STATE();
    case 98:
      if (lookahead == 'E') ADVANCE(81);
      END_STATE();
    case 99:
      if (lookahead == 'E') ADVANCE(49);
      END_STATE();
    case 100:
      if (lookahead == 'E') ADVANCE(200);
      END_STATE();
    case 101:
      if (lookahead == 'E') ADVANCE(172);
      END_STATE();
    case 102:
      if (lookahead == 'E') ADVANCE(156);
      if (lookahead == 'T') ADVANCE(100);
      if (lookahead == 'U') ADVANCE(161);
      if (lookahead == 'Y') ADVANCE(185);
      if (lookahead == 'e') ADVANCE(343);
      if (lookahead == 'u') ADVANCE(331);
      END_STATE();
    case 103:
      if (lookahead == 'E') ADVANCE(210);
      END_STATE();
    case 104:
      if (lookahead == 'E') ADVANCE(225);
      END_STATE();
    case 105:
      if (lookahead == 'E') ADVANCE(267);
      END_STATE();
    case 106:
      if (lookahead == 'E') ADVANCE(211);
      END_STATE();
    case 107:
      if (lookahead == 'E') ADVANCE(218);
      END_STATE();
    case 108:
      if (lookahead == 'E') ADVANCE(178);
      END_STATE();
    case 109:
      if (lookahead == 'E') ADVANCE(233);
      END_STATE();
    case 110:
      if (lookahead == 'E') ADVANCE(219);
      END_STATE();
    case 111:
      if (lookahead == 'E') ADVANCE(235);
      END_STATE();
    case 112:
      if (lookahead == 'E') ADVANCE(173);
      END_STATE();
    case 113:
      if (lookahead == 'E') ADVANCE(237);
      END_STATE();
    case 114:
      if (lookahead == 'E') ADVANCE(239);
      if (lookahead == 'T') ADVANCE(217);
      END_STATE();
    case 115:
      if (lookahead == 'E') ADVANCE(247);
      END_STATE();
    case 116:
      if (lookahead == 'E') ADVANCE(74);
      END_STATE();
    case 117:
      if (lookahead == 'E') ADVANCE(108);
      END_STATE();
    case 118:
      if (lookahead == 'E') ADVANCE(76);
      END_STATE();
    case 119:
      if (lookahead == 'F') ADVANCE(407);
      if (lookahead == 'N') ADVANCE(246);
      END_STATE();
    case 120:
      if (lookahead == 'F') ADVANCE(122);
      if (lookahead == 'R') ADVANCE(367);
      END_STATE();
    case 121:
      if (lookahead == 'F') ADVANCE(122);
      if (lookahead == 'R') ADVANCE(367);
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 122:
      if (lookahead == 'F') ADVANCE(227);
      END_STATE();
    case 123:
      if (lookahead == 'G') ADVANCE(495);
      END_STATE();
    case 124:
      if (lookahead == 'G') ADVANCE(441);
      END_STATE();
    case 125:
      if (lookahead == 'G') ADVANCE(93);
      END_STATE();
    case 126:
      if (lookahead == 'H') ADVANCE(372);
      END_STATE();
    case 127:
      if (lookahead == 'H') ADVANCE(101);
      if (lookahead == 'O') ADVANCE(271);
      END_STATE();
    case 128:
      if (lookahead == 'H') ADVANCE(101);
      if (lookahead == 'O') ADVANCE(271);
      if (lookahead == 'R') ADVANCE(259);
      if (lookahead == 'U') ADVANCE(204);
      END_STATE();
    case 129:
      if (lookahead == 'H') ADVANCE(84);
      END_STATE();
    case 130:
      if (lookahead == 'H') ADVANCE(112);
      END_STATE();
    case 131:
      if (lookahead == 'I') ADVANCE(222);
      if (lookahead == 'O') ADVANCE(417);
      END_STATE();
    case 132:
      if (lookahead == 'I') ADVANCE(166);
      END_STATE();
    case 133:
      if (lookahead == 'I') ADVANCE(166);
      if (lookahead == 'i') ADVANCE(341);
      END_STATE();
    case 134:
      if (lookahead == 'I') ADVANCE(65);
      END_STATE();
    case 135:
      if (lookahead == 'I') ADVANCE(148);
      END_STATE();
    case 136:
      if (lookahead == 'I') ADVANCE(147);
      END_STATE();
    case 137:
      if (lookahead == 'I') ADVANCE(183);
      END_STATE();
    case 138:
      if (lookahead == 'I') ADVANCE(194);
      END_STATE();
    case 139:
      if (lookahead == 'I') ADVANCE(232);
      END_STATE();
    case 140:
      if (lookahead == 'I') ADVANCE(181);
      END_STATE();
    case 141:
      if (lookahead == 'I') ADVANCE(168);
      END_STATE();
    case 142:
      if (lookahead == 'I') ADVANCE(184);
      END_STATE();
    case 143:
      if (lookahead == 'I') ADVANCE(186);
      if (lookahead == 'U') ADVANCE(144);
      END_STATE();
    case 144:
      if (lookahead == 'I') ADVANCE(189);
      END_STATE();
    case 145:
      if (lookahead == 'I') ADVANCE(188);
      END_STATE();
    case 146:
      if (lookahead == 'J') ADVANCE(118);
      END_STATE();
    case 147:
      if (lookahead == 'K') ADVANCE(92);
      END_STATE();
    case 148:
      if (lookahead == 'K') ADVANCE(92);
      if (lookahead == 'M') ADVANCE(139);
      END_STATE();
    case 149:
      if (lookahead == 'L') ADVANCE(484);
      END_STATE();
    case 150:
      if (lookahead == 'L') ADVANCE(500);
      END_STATE();
    case 151:
      if (lookahead == 'L') ADVANCE(224);
      if (lookahead == 'N') ADVANCE(80);
      END_STATE();
    case 152:
      if (lookahead == 'L') ADVANCE(270);
      END_STATE();
    case 153:
      if (lookahead == 'L') ADVANCE(43);
      END_STATE();
    case 154:
      if (lookahead == 'L') ADVANCE(149);
      END_STATE();
    case 155:
      if (lookahead == 'L') ADVANCE(196);
      END_STATE();
    case 156:
      if (lookahead == 'L') ADVANCE(97);
      END_STATE();
    case 157:
      if (lookahead == 'L') ADVANCE(88);
      END_STATE();
    case 158:
      if (lookahead == 'L') ADVANCE(94);
      END_STATE();
    case 159:
      if (lookahead == 'L') ADVANCE(248);
      END_STATE();
    case 160:
      if (lookahead == 'L') ADVANCE(226);
      END_STATE();
    case 161:
      if (lookahead == 'M') ADVANCE(496);
      END_STATE();
    case 162:
      if (lookahead == 'M') ADVANCE(404);
      END_STATE();
    case 163:
      if (lookahead == 'M') ADVANCE(406);
      END_STATE();
    case 164:
      if (lookahead == 'M') ADVANCE(426);
      END_STATE();
    case 165:
      if (lookahead == 'M') ADVANCE(44);
      END_STATE();
    case 166:
      if (lookahead == 'M') ADVANCE(139);
      END_STATE();
    case 167:
      if (lookahead == 'M') ADVANCE(42);
      END_STATE();
    case 168:
      if (lookahead == 'M') ADVANCE(95);
      END_STATE();
    case 169:
      if (lookahead == 'N') ADVANCE(79);
      END_STATE();
    case 170:
      if (lookahead == 'N') ADVANCE(79);
      if (lookahead == 'S') ADVANCE(69);
      END_STATE();
    case 171:
      if (lookahead == 'N') ADVANCE(138);
      END_STATE();
    case 172:
      if (lookahead == 'N') ADVANCE(409);
      END_STATE();
    case 173:
      if (lookahead == 'N') ADVANCE(413);
      END_STATE();
    case 174:
      if (lookahead == 'N') ADVANCE(413);
      if (lookahead == 'R') ADVANCE(89);
      END_STATE();
    case 175:
      if (lookahead == 'N') ADVANCE(398);
      END_STATE();
    case 176:
      if (lookahead == 'N') ADVANCE(767);
      END_STATE();
    case 177:
      if (lookahead == 'N') ADVANCE(420);
      if (lookahead == 'S') ADVANCE(483);
      END_STATE();
    case 178:
      if (lookahead == 'N') ADVANCE(485);
      END_STATE();
    case 179:
      if (lookahead == 'N') ADVANCE(419);
      END_STATE();
    case 180:
      if (lookahead == 'N') ADVANCE(419);
      if (lookahead == 'S') ADVANCE(483);
      END_STATE();
    case 181:
      if (lookahead == 'N') ADVANCE(494);
      END_STATE();
    case 182:
      if (lookahead == 'N') ADVANCE(46);
      END_STATE();
    case 183:
      if (lookahead == 'N') ADVANCE(256);
      END_STATE();
    case 184:
      if (lookahead == 'N') ADVANCE(124);
      END_STATE();
    case 185:
      if (lookahead == 'N') ADVANCE(245);
      END_STATE();
    case 186:
      if (lookahead == 'N') ADVANCE(243);
      END_STATE();
    case 187:
      if (lookahead == 'N') ADVANCE(238);
      END_STATE();
    case 188:
      if (lookahead == 'N') ADVANCE(240);
      END_STATE();
    case 189:
      if (lookahead == 'N') ADVANCE(253);
      END_STATE();
    case 190:
      if (lookahead == 'O') ADVANCE(417);
      END_STATE();
    case 191:
      if (lookahead == 'O') ADVANCE(230);
      END_STATE();
    case 192:
      if (lookahead == 'O') ADVANCE(230);
      if (lookahead == 'U') ADVANCE(154);
      END_STATE();
    case 193:
      if (lookahead == 'O') ADVANCE(162);
      END_STATE();
    case 194:
      if (lookahead == 'O') ADVANCE(175);
      END_STATE();
    case 195:
      if (lookahead == 'O') ADVANCE(197);
      END_STATE();
    case 196:
      if (lookahead == 'O') ADVANCE(47);
      END_STATE();
    case 197:
      if (lookahead == 'O') ADVANCE(150);
      END_STATE();
    case 198:
      if (lookahead == 'O') ADVANCE(182);
      END_STATE();
    case 199:
      if (lookahead == 'O') ADVANCE(223);
      END_STATE();
    case 200:
      if (lookahead == 'P') ADVANCE(425);
      END_STATE();
    case 201:
      if (lookahead == 'P') ADVANCE(126);
      END_STATE();
    case 202:
      if (lookahead == 'P') ADVANCE(153);
      END_STATE();
    case 203:
      if (lookahead == 'P') ADVANCE(216);
      if (lookahead == 'S') ADVANCE(116);
      END_STATE();
    case 204:
      if (lookahead == 'P') ADVANCE(157);
      END_STATE();
    case 205:
      if (lookahead == 'Q') ADVANCE(152);
      END_STATE();
    case 206:
      if (lookahead == 'R') ADVANCE(40);
      if (lookahead == 'S') ADVANCE(205);
      if (lookahead == 'r') ADVANCE(334);
      END_STATE();
    case 207:
      if (lookahead == 'R') ADVANCE(367);
      END_STATE();
    case 208:
      if (lookahead == 'R') ADVANCE(371);
      END_STATE();
    case 209:
      if (lookahead == 'R') ADVANCE(268);
      END_STATE();
    case 210:
      if (lookahead == 'R') ADVANCE(203);
      END_STATE();
    case 211:
      if (lookahead == 'R') ADVANCE(476);
      END_STATE();
    case 212:
      if (lookahead == 'R') ADVANCE(99);
      END_STATE();
    case 213:
      if (lookahead == 'R') ADVANCE(134);
      END_STATE();
    case 214:
      if (lookahead == 'R') ADVANCE(41);
      END_STATE();
    case 215:
      if (lookahead == 'R') ADVANCE(214);
      END_STATE();
    case 216:
      if (lookahead == 'R') ADVANCE(111);
      END_STATE();
    case 217:
      if (lookahead == 'R') ADVANCE(142);
      END_STATE();
    case 218:
      if (lookahead == 'R') ADVANCE(229);
      END_STATE();
    case 219:
      if (lookahead == 'R') ADVANCE(252);
      END_STATE();
    case 220:
      if (lookahead == 'S') ADVANCE(400);
      END_STATE();
    case 221:
      if (lookahead == 'S') ADVANCE(261);
      END_STATE();
    case 222:
      if (lookahead == 'S') ADVANCE(244);
      END_STATE();
    case 223:
      if (lookahead == 'S') ADVANCE(231);
      END_STATE();
    case 224:
      if (lookahead == 'S') ADVANCE(85);
      END_STATE();
    case 225:
      if (lookahead == 'S') ADVANCE(70);
      END_STATE();
    case 226:
      if (lookahead == 'S') ADVANCE(87);
      END_STATE();
    case 227:
      if (lookahead == 'S') ADVANCE(109);
      END_STATE();
    case 228:
      if (lookahead == 'S') ADVANCE(198);
      END_STATE();
    case 229:
      if (lookahead == 'S') ADVANCE(116);
      END_STATE();
    case 230:
      if (lookahead == 'T') ADVANCE(481);
      END_STATE();
    case 231:
      if (lookahead == 'T') ADVANCE(24);
      END_STATE();
    case 232:
      if (lookahead == 'T') ADVANCE(416);
      END_STATE();
    case 233:
      if (lookahead == 'T') ADVANCE(427);
      END_STATE();
    case 234:
      if (lookahead == 'T') ADVANCE(402);
      END_STATE();
    case 235:
      if (lookahead == 'T') ADVANCE(376);
      END_STATE();
    case 236:
      if (lookahead == 'T') ADVANCE(399);
      END_STATE();
    case 237:
      if (lookahead == 'T') ADVANCE(262);
      END_STATE();
    case 238:
      if (lookahead == 'T') ADVANCE(435);
      END_STATE();
    case 239:
      if (lookahead == 'T') ADVANCE(382);
      END_STATE();
    case 240:
      if (lookahead == 'T') ADVANCE(502);
      END_STATE();
    case 241:
      if (lookahead == 'T') ADVANCE(437);
      END_STATE();
    case 242:
      if (lookahead == 'T') ADVANCE(508);
      END_STATE();
    case 243:
      if (lookahead == 'T') ADVANCE(272);
      END_STATE();
    case 244:
      if (lookahead == 'T') ADVANCE(213);
      END_STATE();
    case 245:
      if (lookahead == 'T') ADVANCE(39);
      END_STATE();
    case 246:
      if (lookahead == 'T') ADVANCE(103);
      END_STATE();
    case 247:
      if (lookahead == 'T') ADVANCE(141);
      END_STATE();
    case 248:
      if (lookahead == 'T') ADVANCE(106);
      END_STATE();
    case 249:
      if (lookahead == 'T') ADVANCE(90);
      END_STATE();
    case 250:
      if (lookahead == 'T') ADVANCE(98);
      END_STATE();
    case 251:
      if (lookahead == 'T') ADVANCE(115);
      END_STATE();
    case 252:
      if (lookahead == 'T') ADVANCE(105);
      END_STATE();
    case 253:
      if (lookahead == 'T') ADVANCE(273);
      END_STATE();
    case 254:
      if (lookahead == 'U') ADVANCE(66);
      END_STATE();
    case 255:
      if (lookahead == 'U') ADVANCE(96);
      END_STATE();
    case 256:
      if (lookahead == 'U') ADVANCE(220);
      END_STATE();
    case 257:
      if (lookahead == 'U') ADVANCE(163);
      END_STATE();
    case 258:
      if (lookahead == 'U') ADVANCE(164);
      END_STATE();
    case 259:
      if (lookahead == 'U') ADVANCE(86);
      END_STATE();
    case 260:
      if (lookahead == 'U') ADVANCE(250);
      END_STATE();
    case 261:
      if (lookahead == 'V') ADVANCE(498);
      END_STATE();
    case 262:
      if (lookahead == 'W') ADVANCE(117);
      END_STATE();
    case 263:
      if (lookahead == 'X') ADVANCE(493);
      END_STATE();
    case 264:
      if (lookahead == 'X') ADVANCE(373);
      END_STATE();
    case 265:
      if (lookahead == 'X') ADVANCE(765);
      END_STATE();
    case 266:
      if (lookahead == 'X') ADVANCE(763);
      END_STATE();
    case 267:
      if (lookahead == 'X') ADVANCE(504);
      END_STATE();
    case 268:
      if (lookahead == 'Y') ADVANCE(370);
      END_STATE();
    case 269:
      if (lookahead == 'Y') ADVANCE(510);
      END_STATE();
    case 270:
      if (lookahead == '_') ADVANCE(143);
      END_STATE();
    case 271:
      if (lookahead == '_') ADVANCE(72);
      END_STATE();
    case 272:
      if (lookahead == '_') ADVANCE(167);
      END_STATE();
    case 273:
      if (lookahead == '_') ADVANCE(165);
      END_STATE();
    case 274:
      if (lookahead == 'a') ADVANCE(337);
      END_STATE();
    case 275:
      if (lookahead == 'a') ADVANCE(362);
      END_STATE();
    case 276:
      if (lookahead == 'a') ADVANCE(333);
      if (lookahead == 'o') ADVANCE(339);
      END_STATE();
    case 277:
      if (lookahead == 'a') ADVANCE(314);
      if (lookahead == 'i') ADVANCE(342);
      END_STATE();
    case 278:
      if (lookahead == 'b') ADVANCE(363);
      END_STATE();
    case 279:
      if (lookahead == 'c') ADVANCE(345);
      END_STATE();
    case 280:
      if (lookahead == 'c') ADVANCE(279);
      END_STATE();
    case 281:
      if (lookahead == 'c') ADVANCE(347);
      END_STATE();
    case 282:
      if (lookahead == 'c') ADVANCE(281);
      END_STATE();
    case 283:
      if (lookahead == 'c') ADVANCE(348);
      END_STATE();
    case 284:
      if (lookahead == 'c') ADVANCE(283);
      END_STATE();
    case 285:
      if (lookahead == 'c') ADVANCE(349);
      END_STATE();
    case 286:
      if (lookahead == 'c') ADVANCE(285);
      END_STATE();
    case 287:
      if (lookahead == 'c') ADVANCE(350);
      END_STATE();
    case 288:
      if (lookahead == 'c') ADVANCE(287);
      END_STATE();
    case 289:
      if (lookahead == 'c') ADVANCE(351);
      END_STATE();
    case 290:
      if (lookahead == 'c') ADVANCE(289);
      END_STATE();
    case 291:
      if (lookahead == 'c') ADVANCE(352);
      END_STATE();
    case 292:
      if (lookahead == 'c') ADVANCE(291);
      END_STATE();
    case 293:
      if (lookahead == 'c') ADVANCE(353);
      END_STATE();
    case 294:
      if (lookahead == 'c') ADVANCE(293);
      END_STATE();
    case 295:
      if (lookahead == 'c') ADVANCE(354);
      END_STATE();
    case 296:
      if (lookahead == 'c') ADVANCE(295);
      END_STATE();
    case 297:
      if (lookahead == 'c') ADVANCE(355);
      END_STATE();
    case 298:
      if (lookahead == 'c') ADVANCE(297);
      END_STATE();
    case 299:
      if (lookahead == 'c') ADVANCE(356);
      END_STATE();
    case 300:
      if (lookahead == 'c') ADVANCE(299);
      END_STATE();
    case 301:
      if (lookahead == 'c') ADVANCE(357);
      END_STATE();
    case 302:
      if (lookahead == 'c') ADVANCE(301);
      END_STATE();
    case 303:
      if (lookahead == 'c') ADVANCE(358);
      END_STATE();
    case 304:
      if (lookahead == 'c') ADVANCE(303);
      END_STATE();
    case 305:
      if (lookahead == 'c') ADVANCE(359);
      END_STATE();
    case 306:
      if (lookahead == 'c') ADVANCE(305);
      END_STATE();
    case 307:
      if (lookahead == 'c') ADVANCE(360);
      END_STATE();
    case 308:
      if (lookahead == 'c') ADVANCE(307);
      END_STATE();
    case 309:
      if (lookahead == 'd') ADVANCE(48);
      END_STATE();
    case 310:
      if (lookahead == 'd') ADVANCE(63);
      END_STATE();
    case 311:
      if (lookahead == 'e') ADVANCE(274);
      END_STATE();
    case 312:
      if (lookahead == 'e') ADVANCE(276);
      END_STATE();
    case 313:
      if (lookahead == 'g') ADVANCE(50);
      END_STATE();
    case 314:
      if (lookahead == 'g') ADVANCE(51);
      END_STATE();
    case 315:
      if (lookahead == 'i') ADVANCE(340);
      END_STATE();
    case 316:
      if (lookahead == 'm') ADVANCE(449);
      END_STATE();
    case 317:
      if (lookahead == 'm') ADVANCE(451);
      END_STATE();
    case 318:
      if (lookahead == 'm') ADVANCE(447);
      END_STATE();
    case 319:
      if (lookahead == 'm') ADVANCE(461);
      END_STATE();
    case 320:
      if (lookahead == 'm') ADVANCE(463);
      END_STATE();
    case 321:
      if (lookahead == 'm') ADVANCE(443);
      END_STATE();
    case 322:
      if (lookahead == 'm') ADVANCE(445);
      END_STATE();
    case 323:
      if (lookahead == 'm') ADVANCE(459);
      END_STATE();
    case 324:
      if (lookahead == 'm') ADVANCE(433);
      END_STATE();
    case 325:
      if (lookahead == 'm') ADVANCE(465);
      END_STATE();
    case 326:
      if (lookahead == 'm') ADVANCE(457);
      END_STATE();
    case 327:
      if (lookahead == 'm') ADVANCE(471);
      END_STATE();
    case 328:
      if (lookahead == 'm') ADVANCE(469);
      END_STATE();
    case 329:
      if (lookahead == 'm') ADVANCE(453);
      END_STATE();
    case 330:
      if (lookahead == 'm') ADVANCE(455);
      END_STATE();
    case 331:
      if (lookahead == 'm') ADVANCE(57);
      END_STATE();
    case 332:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 333:
      if (lookahead == 'n') ADVANCE(310);
      END_STATE();
    case 334:
      if (lookahead == 'o') ADVANCE(346);
      END_STATE();
    case 335:
      if (lookahead == 'p') ADVANCE(278);
      END_STATE();
    case 336:
      if (lookahead == 'p') ADVANCE(53);
      if (lookahead == 'x') ADVANCE(54);
      END_STATE();
    case 337:
      if (lookahead == 'p') ADVANCE(58);
      END_STATE();
    case 338:
      if (lookahead == 'r') ADVANCE(275);
      END_STATE();
    case 339:
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 340:
      if (lookahead == 's') ADVANCE(312);
      END_STATE();
    case 341:
      if (lookahead == 's') ADVANCE(344);
      END_STATE();
    case 342:
      if (lookahead == 't') ADVANCE(361);
      END_STATE();
    case 343:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 344:
      if (lookahead == 't') ADVANCE(59);
      END_STATE();
    case 345:
      if (lookahead == 'u') ADVANCE(316);
      END_STATE();
    case 346:
      if (lookahead == 'u') ADVANCE(335);
      END_STATE();
    case 347:
      if (lookahead == 'u') ADVANCE(317);
      END_STATE();
    case 348:
      if (lookahead == 'u') ADVANCE(318);
      END_STATE();
    case 349:
      if (lookahead == 'u') ADVANCE(319);
      END_STATE();
    case 350:
      if (lookahead == 'u') ADVANCE(320);
      END_STATE();
    case 351:
      if (lookahead == 'u') ADVANCE(321);
      END_STATE();
    case 352:
      if (lookahead == 'u') ADVANCE(322);
      END_STATE();
    case 353:
      if (lookahead == 'u') ADVANCE(323);
      END_STATE();
    case 354:
      if (lookahead == 'u') ADVANCE(324);
      END_STATE();
    case 355:
      if (lookahead == 'u') ADVANCE(325);
      END_STATE();
    case 356:
      if (lookahead == 'u') ADVANCE(326);
      END_STATE();
    case 357:
      if (lookahead == 'u') ADVANCE(327);
      END_STATE();
    case 358:
      if (lookahead == 'u') ADVANCE(328);
      END_STATE();
    case 359:
      if (lookahead == 'u') ADVANCE(329);
      END_STATE();
    case 360:
      if (lookahead == 'u') ADVANCE(330);
      END_STATE();
    case 361:
      if (lookahead == 'w') ADVANCE(315);
      END_STATE();
    case 362:
      if (lookahead == 'y') ADVANCE(60);
      END_STATE();
    case 363:
      if (lookahead == 'y') ADVANCE(61);
      END_STATE();
    case 364:
      if (eof) ADVANCE(365);
      if (lookahead == '"') ADVANCE(770);
      if (lookahead == '%') ADVANCE(779);
      if (lookahead == '&') ADVANCE(784);
      if (lookahead == '\'') ADVANCE(771);
      if (lookahead == '(') ADVANCE(377);
      if (lookahead == ')') ADVANCE(378);
      if (lookahead == '*') ADVANCE(432);
      if (lookahead == '+') ADVANCE(780);
      if (lookahead == ',') ADVANCE(379);
      if (lookahead == '-') ADVANCE(428);
      if (lookahead == '.') ADVANCE(393);
      if (lookahead == '/') ADVANCE(778);
      if (lookahead == ':') ADVANCE(421);
      if (lookahead == ';') ADVANCE(392);
      if (lookahead == '<') ADVANCE(384);
      if (lookahead == '=') ADVANCE(380);
      if (lookahead == '>') ADVANCE(34);
      if (lookahead == '@') ADVANCE(475);
      if (lookahead == 'A') ADVANCE(68);
      if (lookahead == 'B') ADVANCE(277);
      if (lookahead == 'C') ADVANCE(212);
      if (lookahead == 'D') ADVANCE(131);
      if (lookahead == 'E') ADVANCE(151);
      if (lookahead == 'F') ADVANCE(36);
      if (lookahead == 'G') ADVANCE(206);
      if (lookahead == 'H') ADVANCE(311);
      if (lookahead == 'I') ADVANCE(119);
      if (lookahead == 'L') ADVANCE(133);
      if (lookahead == 'M') ADVANCE(37);
      if (lookahead == 'N') ADVANCE(192);
      if (lookahead == 'O') ADVANCE(121);
      if (lookahead == 'P') ADVANCE(199);
      if (lookahead == 'Q') ADVANCE(255);
      if (lookahead == 'R') ADVANCE(83);
      if (lookahead == 'S') ADVANCE(102);
      if (lookahead == 'T') ADVANCE(128);
      if (lookahead == 'U') ADVANCE(171);
      if (lookahead == 'V') ADVANCE(28);
      if (lookahead == 'W') ADVANCE(129);
      if (lookahead == '[') ADVANCE(423);
      if (lookahead == ']') ADVANCE(424);
      if (lookahead == 'v') ADVANCE(29);
      if (lookahead == '{') ADVANCE(388);
      if (lookahead == '|') ADVANCE(431);
      if (lookahead == '}') ADVANCE(389);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(772);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_CREATE);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_OR);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_REPLACE);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(anon_sym_DISTRIBUTED);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(anon_sym_QUERY);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(anon_sym_FOR);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(anon_sym_GRAPH);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(anon_sym_SYNTAX);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(anon_sym_V2);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(anon_sym_v2);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(anon_sym_INTERPRET);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(787);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(anon_sym_SET);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(782);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(782);
      if (lookahead == '=') ADVANCE(785);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(786);
      if (lookahead == '>') ADVANCE(783);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(anon_sym_TYPEDEF);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(anon_sym_TUPLE);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(anon_sym__);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(anon_sym_ANY);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(anon_sym_DOT_STAR);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(anon_sym_UNION);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(anon_sym_INTERSECT);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(anon_sym_MINUS);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(anon_sym_SELECT);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(anon_sym_SELECT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(anon_sym_FROM);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(anon_sym_WHERE);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(anon_sym_ACCUM);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(anon_sym_IF);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(anon_sym_IF);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(anon_sym_THEN);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(anon_sym_ELSE);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(anon_sym_END);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(anon_sym_CASE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(anon_sym_WHEN);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(anon_sym_WHEN);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(anon_sym_WHILE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(anon_sym_LIMIT);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(anon_sym_DO);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(anon_sym_FOREACH);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(anon_sym_IN);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(anon_sym_IN);
      if (lookahead == 'T') ADVANCE(107);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(anon_sym_RANGE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(anon_sym_STEP);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(anon_sym_POST_DASHACCUM);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(anon_sym_OFFSET);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(480);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(anon_sym_PIPE2);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(anon_sym_SumAccum);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(anon_sym_SumAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(anon_sym_INT);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(anon_sym_INT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(anon_sym_FLOAT);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(anon_sym_FLOAT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(anon_sym_DOUBLE);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(anon_sym_DOUBLE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(anon_sym_STRING);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(anon_sym_STRING);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(anon_sym_MaxAccum);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(anon_sym_MaxAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(anon_sym_MinAccum);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(anon_sym_MinAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(anon_sym_AvgAccum);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(anon_sym_AvgAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(anon_sym_OrAccum);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(anon_sym_OrAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(anon_sym_AndAccum);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(anon_sym_AndAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(anon_sym_BitwiseorAccum);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(anon_sym_BitwiseorAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(anon_sym_BitwiseandAccum);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(anon_sym_BitwiseandAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(anon_sym_ListAccum);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(anon_sym_ListAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(anon_sym_SetAccum);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(anon_sym_SetAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(anon_sym_BagAccum);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(anon_sym_BagAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(anon_sym_MapAccum);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_MapAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(anon_sym_HeapAccum);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(anon_sym_HeapAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(anon_sym_ASC);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(anon_sym_DESC);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(anon_sym_GroupbyAccum);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(anon_sym_GroupbyAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(anon_sym_ArrayAccum);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(anon_sym_ArrayAccum);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(anon_sym_AT_AT);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '@') ADVANCE(473);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(anon_sym_FILTER);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(anon_sym_COALESCE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(anon_sym_DISTINCT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(anon_sym_ISEMPTY);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(anon_sym_NOT);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_NOT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(anon_sym_IS);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(anon_sym_BETWEEN);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(anon_sym_AND);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(anon_sym_TRUE);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(anon_sym_TRUE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(anon_sym_FALSE);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(anon_sym_FALSE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(anon_sym_LIKE);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(anon_sym_COUNT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_MAX);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(anon_sym_MIN);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(anon_sym_AVG);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(anon_sym_SUM);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(anon_sym_PRINT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(anon_sym_TO_CSV);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(anon_sym_AS);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(anon_sym_BOOL);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(anon_sym_BOOL);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(anon_sym_UINT);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(anon_sym_UINT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(anon_sym_VERTEX);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(anon_sym_VERTEX);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(anon_sym_EDGE);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(anon_sym_EDGE);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(anon_sym_JSONOBJECT);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(anon_sym_JSONOBJECT);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(anon_sym_JSONARRAY);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(anon_sym_JSONARRAY);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(anon_sym_DATETIME);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(anon_sym_DATETIME);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(650);
      if (lookahead == 'O') ADVANCE(656);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(674);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(542);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(632);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(662);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(659);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(596);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(660);
      if (lookahead == 'I') ADVANCE(601);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(626);
      if (lookahead == 'O') ADVANCE(540);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(640);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(611);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(676);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(678);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(680);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(594);
      if (lookahead == 'U') ADVANCE(609);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(682);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 530:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(684);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 531:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(686);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 532:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(688);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 533:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(690);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 534:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(692);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 535:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(694);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 536:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(696);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 537:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(698);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 538:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(700);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 539:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'A') ADVANCE(702);
      if (sym_name_character_set_6(lookahead)) ADVANCE(762);
      END_STATE();
    case 540:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'B') ADVANCE(587);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 541:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'B') ADVANCE(593);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 542:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'C') ADVANCE(575);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 543:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'C') ADVANCE(642);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 544:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'C') ADVANCE(644);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 545:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'C') ADVANCE(646);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 546:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'C') ADVANCE(558);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 547:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'D') ADVANCE(573);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 548:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'D') ADVANCE(554);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 549:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(412);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 550:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(507);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 551:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(658);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 552:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(415);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 553:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(440);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 554:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(571);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 555:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(513);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 556:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(488);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 557:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(490);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 558:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(477);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 559:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(422);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 560:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(548);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 561:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(543);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 562:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(598);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 563:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(629);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 564:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(516);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 565:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(634);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 566:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(649);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 567:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(602);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 568:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(544);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 569:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'E') ADVANCE(595);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 570:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'F') ADVANCE(408);
      if (lookahead == 'N') ADVANCE(638);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 571:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'F') ADVANCE(390);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 572:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'G') ADVANCE(442);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 573:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'G') ADVANCE(550);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 574:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'G') ADVANCE(559);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 575:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'H') ADVANCE(418);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 576:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'H') ADVANCE(580);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 577:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'H') ADVANCE(567);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 578:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(606);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 579:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(600);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 580:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(592);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 581:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(605);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 582:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(636);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 583:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(613);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 584:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(608);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 585:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(610);
      if (lookahead == 'U') ADVANCE(586);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 586:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'I') ADVANCE(612);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 587:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'J') ADVANCE(561);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 588:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(501);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 589:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(665);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 590:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(619);
      if (lookahead == 'O') ADVANCE(627);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 591:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(619);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 592:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(552);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 593:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(553);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 594:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(565);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 595:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(568);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 596:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'L') ADVANCE(637);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 597:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'M') ADVANCE(521);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 598:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'M') ADVANCE(622);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 599:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'M') ADVANCE(519);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 600:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'M') ADVANCE(555);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 601:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(768);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 602:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(414);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 603:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(522);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 604:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(638);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 605:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(572);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 606:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(639);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 607:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(664);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 608:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(641);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 609:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(643);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 610:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(647);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 611:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(574);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 612:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(652);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 613:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'N') ADVANCE(545);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 614:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'O') ADVANCE(616);
      if (lookahead == 'a') ADVANCE(708);
      if (lookahead == 'i') ADVANCE(740);
      if (sym_name_character_set_7(lookahead)) ADVANCE(762);
      END_STATE();
    case 615:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'O') ADVANCE(616);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 616:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'O') ADVANCE(588);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 617:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'O') ADVANCE(528);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 618:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'O') ADVANCE(603);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 619:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'O') ADVANCE(523);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 620:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'O') ADVANCE(645);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 621:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'P') ADVANCE(560);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 622:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'P') ADVANCE(648);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 623:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'Q') ADVANCE(589);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 624:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'R') ADVANCE(657);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 625:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'R') ADVANCE(518);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 626:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'R') ADVANCE(625);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 627:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'R') ADVANCE(564);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 628:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'R') ADVANCE(581);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 629:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'R') ADVANCE(651);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 630:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'R') ADVANCE(584);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 631:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'S') ADVANCE(623);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 632:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'S') ADVANCE(549);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 633:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'S') ADVANCE(618);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 634:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'S') ADVANCE(546);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 635:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'S') ADVANCE(562);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 636:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'S') ADVANCE(653);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 637:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'S') ADVANCE(557);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 638:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(436);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 639:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(503);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 640:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(438);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 641:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(497);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 642:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(509);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 643:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(492);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 644:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(403);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 645:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(482);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 646:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(478);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 647:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(666);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 648:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(663);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 649:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(579);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 650:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(566);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 651:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(551);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 652:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(667);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 653:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(583);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 654:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(628);
      if (lookahead == 'e') ADVANCE(741);
      if (lookahead == 'u') ADVANCE(726);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 655:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'T') ADVANCE(628);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 656:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'U') ADVANCE(541);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 657:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'U') ADVANCE(556);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 658:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'X') ADVANCE(505);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 659:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'X') ADVANCE(766);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 660:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'X') ADVANCE(764);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 661:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'Y') ADVANCE(621);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 662:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'Y') ADVANCE(511);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 663:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'Y') ADVANCE(479);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 664:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'Y') ADVANCE(396);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 665:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == '_') ADVANCE(585);
      if (sym_name_character_set_8(lookahead)) ADVANCE(762);
      END_STATE();
    case 666:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == '_') ADVANCE(599);
      if (sym_name_character_set_8(lookahead)) ADVANCE(762);
      END_STATE();
    case 667:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == '_') ADVANCE(597);
      if (sym_name_character_set_8(lookahead)) ADVANCE(762);
      END_STATE();
    case 668:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(732);
      if (lookahead == 'i') ADVANCE(728);
      if (sym_name_character_set_7(lookahead)) ADVANCE(762);
      END_STATE();
    case 669:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(733);
      if (sym_name_character_set_7(lookahead)) ADVANCE(762);
      END_STATE();
    case 670:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(760);
      if (sym_name_character_set_7(lookahead)) ADVANCE(762);
      END_STATE();
    case 671:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(729);
      if (lookahead == 'o') ADVANCE(737);
      if (sym_name_character_set_7(lookahead)) ADVANCE(762);
      END_STATE();
    case 672:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'b') ADVANCE(761);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 673:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(743);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 674:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(673);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 675:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(745);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 676:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(675);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 677:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(746);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 678:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(677);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 679:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(747);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 680:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(679);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 681:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(748);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 682:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(681);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 683:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(749);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 684:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(683);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 685:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(750);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 686:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(685);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 687:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(751);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 688:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(687);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 689:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(752);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 690:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(689);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 691:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(753);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 692:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(691);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 693:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(754);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 694:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(693);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 695:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(755);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 696:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(695);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 697:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(756);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 698:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(697);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 699:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(757);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 700:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(699);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 701:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(758);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 702:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(701);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 703:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'd') ADVANCE(525);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 704:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'd') ADVANCE(539);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 705:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(669);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 706:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(671);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 707:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'g') ADVANCE(526);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 708:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'g') ADVANCE(527);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 709:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(739);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 710:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(738);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 711:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(450);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 712:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(452);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 713:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(448);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 714:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(462);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 715:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(464);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 716:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(444);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 717:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(446);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 718:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(460);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 719:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(434);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 720:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(466);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 721:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(458);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 722:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(472);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 723:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(470);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 724:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(454);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 725:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(456);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 726:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'm') ADVANCE(533);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 727:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(703);
      if (lookahead == 'r') ADVANCE(736);
      if (lookahead == 'v') ADVANCE(707);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 728:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(531);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 729:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(704);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 730:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'o') ADVANCE(744);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 731:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'p') ADVANCE(672);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 732:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'p') ADVANCE(529);
      if (lookahead == 'x') ADVANCE(530);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 733:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'p') ADVANCE(534);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 734:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(730);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 735:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(515);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 736:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(670);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 737:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(538);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 738:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 's') ADVANCE(706);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 739:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 's') ADVANCE(742);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 740:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(759);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 741:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(532);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 742:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(535);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 743:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(711);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 744:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(731);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 745:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(712);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 746:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(713);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 747:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(714);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 748:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(715);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 749:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(716);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 750:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(717);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 751:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(718);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 752:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(719);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 753:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(720);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 754:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(721);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 755:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(722);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 756:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(723);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 757:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(724);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 758:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(725);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 759:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'w') ADVANCE(710);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 760:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'y') ADVANCE(536);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 761:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'y') ADVANCE(537);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 762:
      ACCEPT_TOKEN(sym_name);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 763:
      ACCEPT_TOKEN(anon_sym_GSQL_UINT_MAX);
      END_STATE();
    case 764:
      ACCEPT_TOKEN(anon_sym_GSQL_UINT_MAX);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 765:
      ACCEPT_TOKEN(anon_sym_GSQL_INT_MAX);
      END_STATE();
    case 766:
      ACCEPT_TOKEN(anon_sym_GSQL_INT_MAX);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 767:
      ACCEPT_TOKEN(anon_sym_GSQL_UINT_MIN);
      END_STATE();
    case 768:
      ACCEPT_TOKEN(anon_sym_GSQL_UINT_MIN);
      if (sym_name_character_set_5(lookahead)) ADVANCE(762);
      END_STATE();
    case 769:
      ACCEPT_TOKEN(sym_digit);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(769);
      END_STATE();
    case 770:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 771:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 772:
      ACCEPT_TOKEN(sym_space);
      END_STATE();
    case 773:
      ACCEPT_TOKEN(sym_space);
      if (lookahead == '\n') ADVANCE(790);
      END_STATE();
    case 774:
      ACCEPT_TOKEN(sym_space);
      if (lookahead == '|') ADVANCE(3);
      END_STATE();
    case 775:
      ACCEPT_TOKEN(sym_space);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(794);
      END_STATE();
    case 776:
      ACCEPT_TOKEN(sym_string_fragment);
      END_STATE();
    case 777:
      ACCEPT_TOKEN(sym_string_fragment);
      if (lookahead == '*') ADVANCE(795);
      if (lookahead == '/') ADVANCE(798);
      END_STATE();
    case 778:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(795);
      if (lookahead == '/') ADVANCE(798);
      END_STATE();
    case 779:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 780:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 781:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '=') ADVANCE(401);
      END_STATE();
    case 782:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 783:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 784:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 785:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 786:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 787:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 788:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 789:
      ACCEPT_TOKEN(sym_newline);
      END_STATE();
    case 790:
      ACCEPT_TOKEN(sym_spacing_line);
      END_STATE();
    case 791:
      ACCEPT_TOKEN(sym_comment_contents);
      if (lookahead == '\n') ADVANCE(789);
      if (lookahead == '*') ADVANCE(793);
      if (lookahead == '/') ADVANCE(792);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(775);
      if (lookahead != 0) ADVANCE(794);
      END_STATE();
    case 792:
      ACCEPT_TOKEN(sym_comment_contents);
      if (lookahead == '*') ADVANCE(796);
      if (lookahead == '/') ADVANCE(794);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(794);
      END_STATE();
    case 793:
      ACCEPT_TOKEN(sym_comment_contents);
      if (lookahead == '/') ADVANCE(797);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(794);
      END_STATE();
    case 794:
      ACCEPT_TOKEN(sym_comment_contents);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(794);
      END_STATE();
    case 795:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      END_STATE();
    case 796:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(794);
      END_STATE();
    case 797:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(794);
      END_STATE();
    case 798:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(798);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 364},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 15},
  [6] = {.lex_state = 15},
  [7] = {.lex_state = 15},
  [8] = {.lex_state = 15},
  [9] = {.lex_state = 15},
  [10] = {.lex_state = 15},
  [11] = {.lex_state = 15},
  [12] = {.lex_state = 15},
  [13] = {.lex_state = 15},
  [14] = {.lex_state = 15},
  [15] = {.lex_state = 15},
  [16] = {.lex_state = 15},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 4},
  [23] = {.lex_state = 4},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 4},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 4},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 4},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 6},
  [38] = {.lex_state = 6},
  [39] = {.lex_state = 6},
  [40] = {.lex_state = 6},
  [41] = {.lex_state = 6},
  [42] = {.lex_state = 6},
  [43] = {.lex_state = 6},
  [44] = {.lex_state = 6},
  [45] = {.lex_state = 6},
  [46] = {.lex_state = 6},
  [47] = {.lex_state = 6},
  [48] = {.lex_state = 6},
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 6},
  [51] = {.lex_state = 6},
  [52] = {.lex_state = 6},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 6},
  [55] = {.lex_state = 6},
  [56] = {.lex_state = 6},
  [57] = {.lex_state = 6},
  [58] = {.lex_state = 6},
  [59] = {.lex_state = 6},
  [60] = {.lex_state = 6},
  [61] = {.lex_state = 6},
  [62] = {.lex_state = 6},
  [63] = {.lex_state = 6},
  [64] = {.lex_state = 6},
  [65] = {.lex_state = 6},
  [66] = {.lex_state = 6},
  [67] = {.lex_state = 6},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 10},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 364},
  [75] = {.lex_state = 25},
  [76] = {.lex_state = 25},
  [77] = {.lex_state = 25},
  [78] = {.lex_state = 25},
  [79] = {.lex_state = 25},
  [80] = {.lex_state = 25},
  [81] = {.lex_state = 25},
  [82] = {.lex_state = 25},
  [83] = {.lex_state = 25},
  [84] = {.lex_state = 25},
  [85] = {.lex_state = 25},
  [86] = {.lex_state = 25},
  [87] = {.lex_state = 25},
  [88] = {.lex_state = 12},
  [89] = {.lex_state = 12},
  [90] = {.lex_state = 9},
  [91] = {.lex_state = 9},
  [92] = {.lex_state = 12},
  [93] = {.lex_state = 12},
  [94] = {.lex_state = 9},
  [95] = {.lex_state = 6},
  [96] = {.lex_state = 12},
  [97] = {.lex_state = 12},
  [98] = {.lex_state = 12},
  [99] = {.lex_state = 9},
  [100] = {.lex_state = 12},
  [101] = {.lex_state = 12},
  [102] = {.lex_state = 12},
  [103] = {.lex_state = 12},
  [104] = {.lex_state = 12},
  [105] = {.lex_state = 9},
  [106] = {.lex_state = 9},
  [107] = {.lex_state = 9},
  [108] = {.lex_state = 12},
  [109] = {.lex_state = 12},
  [110] = {.lex_state = 12},
  [111] = {.lex_state = 9},
  [112] = {.lex_state = 12},
  [113] = {.lex_state = 9},
  [114] = {.lex_state = 9},
  [115] = {.lex_state = 9},
  [116] = {.lex_state = 12},
  [117] = {.lex_state = 13},
  [118] = {.lex_state = 12},
  [119] = {.lex_state = 9},
  [120] = {.lex_state = 9},
  [121] = {.lex_state = 9},
  [122] = {.lex_state = 12},
  [123] = {.lex_state = 9},
  [124] = {.lex_state = 12},
  [125] = {.lex_state = 12},
  [126] = {.lex_state = 9},
  [127] = {.lex_state = 9},
  [128] = {.lex_state = 9},
  [129] = {.lex_state = 9},
  [130] = {.lex_state = 9},
  [131] = {.lex_state = 9},
  [132] = {.lex_state = 9},
  [133] = {.lex_state = 9},
  [134] = {.lex_state = 6},
  [135] = {.lex_state = 9},
  [136] = {.lex_state = 9},
  [137] = {.lex_state = 6},
  [138] = {.lex_state = 9},
  [139] = {.lex_state = 5},
  [140] = {.lex_state = 9},
  [141] = {.lex_state = 9},
  [142] = {.lex_state = 9},
  [143] = {.lex_state = 9},
  [144] = {.lex_state = 9},
  [145] = {.lex_state = 5},
  [146] = {.lex_state = 5},
  [147] = {.lex_state = 9},
  [148] = {.lex_state = 5},
  [149] = {.lex_state = 5},
  [150] = {.lex_state = 5},
  [151] = {.lex_state = 9},
  [152] = {.lex_state = 9},
  [153] = {.lex_state = 5},
  [154] = {.lex_state = 9},
  [155] = {.lex_state = 9},
  [156] = {.lex_state = 5},
  [157] = {.lex_state = 9},
  [158] = {.lex_state = 9},
  [159] = {.lex_state = 26},
  [160] = {.lex_state = 6},
  [161] = {.lex_state = 9},
  [162] = {.lex_state = 5},
  [163] = {.lex_state = 9},
  [164] = {.lex_state = 9},
  [165] = {.lex_state = 9},
  [166] = {.lex_state = 9},
  [167] = {.lex_state = 9},
  [168] = {.lex_state = 5},
  [169] = {.lex_state = 9},
  [170] = {.lex_state = 9},
  [171] = {.lex_state = 5},
  [172] = {.lex_state = 9},
  [173] = {.lex_state = 9},
  [174] = {.lex_state = 9},
  [175] = {.lex_state = 9},
  [176] = {.lex_state = 9},
  [177] = {.lex_state = 9},
  [178] = {.lex_state = 9},
  [179] = {.lex_state = 9},
  [180] = {.lex_state = 9},
  [181] = {.lex_state = 9},
  [182] = {.lex_state = 9},
  [183] = {.lex_state = 26},
  [184] = {.lex_state = 26},
  [185] = {.lex_state = 9},
  [186] = {.lex_state = 9},
  [187] = {.lex_state = 9},
  [188] = {.lex_state = 9},
  [189] = {.lex_state = 5},
  [190] = {.lex_state = 26},
  [191] = {.lex_state = 5},
  [192] = {.lex_state = 5},
  [193] = {.lex_state = 364},
  [194] = {.lex_state = 5},
  [195] = {.lex_state = 364},
  [196] = {.lex_state = 5},
  [197] = {.lex_state = 5},
  [198] = {.lex_state = 7},
  [199] = {.lex_state = 5},
  [200] = {.lex_state = 5},
  [201] = {.lex_state = 5},
  [202] = {.lex_state = 5},
  [203] = {.lex_state = 7},
  [204] = {.lex_state = 5},
  [205] = {.lex_state = 7},
  [206] = {.lex_state = 7},
  [207] = {.lex_state = 7},
  [208] = {.lex_state = 7},
  [209] = {.lex_state = 7},
  [210] = {.lex_state = 7},
  [211] = {.lex_state = 7},
  [212] = {.lex_state = 7},
  [213] = {.lex_state = 7},
  [214] = {.lex_state = 7},
  [215] = {.lex_state = 7},
  [216] = {.lex_state = 7},
  [217] = {.lex_state = 7},
  [218] = {.lex_state = 7},
  [219] = {.lex_state = 7},
  [220] = {.lex_state = 7},
  [221] = {.lex_state = 7},
  [222] = {.lex_state = 7},
  [223] = {.lex_state = 7},
  [224] = {.lex_state = 7},
  [225] = {.lex_state = 7},
  [226] = {.lex_state = 7},
  [227] = {.lex_state = 7},
  [228] = {.lex_state = 7},
  [229] = {.lex_state = 7},
  [230] = {.lex_state = 7},
  [231] = {.lex_state = 7},
  [232] = {.lex_state = 7},
  [233] = {.lex_state = 7},
  [234] = {.lex_state = 7},
  [235] = {.lex_state = 7},
  [236] = {.lex_state = 7},
  [237] = {.lex_state = 7},
  [238] = {.lex_state = 7},
  [239] = {.lex_state = 364},
  [240] = {.lex_state = 364},
  [241] = {.lex_state = 364},
  [242] = {.lex_state = 5},
  [243] = {.lex_state = 5},
  [244] = {.lex_state = 9},
  [245] = {.lex_state = 9},
  [246] = {.lex_state = 19},
  [247] = {.lex_state = 364},
  [248] = {.lex_state = 364},
  [249] = {.lex_state = 23},
  [250] = {.lex_state = 23},
  [251] = {.lex_state = 364},
  [252] = {.lex_state = 364},
  [253] = {.lex_state = 23},
  [254] = {.lex_state = 364},
  [255] = {.lex_state = 364},
  [256] = {.lex_state = 364},
  [257] = {.lex_state = 364},
  [258] = {.lex_state = 364},
  [259] = {.lex_state = 19},
  [260] = {.lex_state = 364},
  [261] = {.lex_state = 23},
  [262] = {.lex_state = 364},
  [263] = {.lex_state = 23},
  [264] = {.lex_state = 23},
  [265] = {.lex_state = 364},
  [266] = {.lex_state = 23},
  [267] = {.lex_state = 23},
  [268] = {.lex_state = 364},
  [269] = {.lex_state = 23},
  [270] = {.lex_state = 23},
  [271] = {.lex_state = 15},
  [272] = {.lex_state = 15},
  [273] = {.lex_state = 16},
  [274] = {.lex_state = 23},
  [275] = {.lex_state = 364},
  [276] = {.lex_state = 23},
  [277] = {.lex_state = 23},
  [278] = {.lex_state = 16},
  [279] = {.lex_state = 23},
  [280] = {.lex_state = 23},
  [281] = {.lex_state = 23},
  [282] = {.lex_state = 364},
  [283] = {.lex_state = 364},
  [284] = {.lex_state = 23},
  [285] = {.lex_state = 364},
  [286] = {.lex_state = 15},
  [287] = {.lex_state = 364},
  [288] = {.lex_state = 19},
  [289] = {.lex_state = 15},
  [290] = {.lex_state = 15},
  [291] = {.lex_state = 19},
  [292] = {.lex_state = 364},
  [293] = {.lex_state = 19},
  [294] = {.lex_state = 19},
  [295] = {.lex_state = 364},
  [296] = {.lex_state = 16},
  [297] = {.lex_state = 16},
  [298] = {.lex_state = 19},
  [299] = {.lex_state = 22},
  [300] = {.lex_state = 16},
  [301] = {.lex_state = 16},
  [302] = {.lex_state = 364},
  [303] = {.lex_state = 364},
  [304] = {.lex_state = 364},
  [305] = {.lex_state = 364},
  [306] = {.lex_state = 364},
  [307] = {.lex_state = 364},
  [308] = {.lex_state = 364},
  [309] = {.lex_state = 364},
  [310] = {.lex_state = 16},
  [311] = {.lex_state = 364},
  [312] = {.lex_state = 364},
  [313] = {.lex_state = 16},
  [314] = {.lex_state = 364},
  [315] = {.lex_state = 16},
  [316] = {.lex_state = 364},
  [317] = {.lex_state = 16},
  [318] = {.lex_state = 364},
  [319] = {.lex_state = 19},
  [320] = {.lex_state = 16},
  [321] = {.lex_state = 16},
  [322] = {.lex_state = 364},
  [323] = {.lex_state = 16},
  [324] = {.lex_state = 364},
  [325] = {.lex_state = 364},
  [326] = {.lex_state = 364},
  [327] = {.lex_state = 16},
  [328] = {.lex_state = 364},
  [329] = {.lex_state = 364},
  [330] = {.lex_state = 364},
  [331] = {.lex_state = 364},
  [332] = {.lex_state = 364},
  [333] = {.lex_state = 364},
  [334] = {.lex_state = 364},
  [335] = {.lex_state = 364},
  [336] = {.lex_state = 364},
  [337] = {.lex_state = 364},
  [338] = {.lex_state = 364},
  [339] = {.lex_state = 364},
  [340] = {.lex_state = 364},
  [341] = {.lex_state = 364},
  [342] = {.lex_state = 364},
  [343] = {.lex_state = 364},
  [344] = {.lex_state = 364},
  [345] = {.lex_state = 364},
  [346] = {.lex_state = 364},
  [347] = {.lex_state = 364},
  [348] = {.lex_state = 364},
  [349] = {.lex_state = 17},
  [350] = {.lex_state = 11},
  [351] = {.lex_state = 364},
  [352] = {.lex_state = 364},
  [353] = {.lex_state = 364},
  [354] = {.lex_state = 364},
  [355] = {.lex_state = 364},
  [356] = {.lex_state = 17},
  [357] = {.lex_state = 364},
  [358] = {.lex_state = 364},
  [359] = {.lex_state = 364},
  [360] = {.lex_state = 364},
  [361] = {.lex_state = 11},
  [362] = {.lex_state = 18},
  [363] = {.lex_state = 364},
  [364] = {.lex_state = 364},
  [365] = {.lex_state = 16},
  [366] = {.lex_state = 364},
  [367] = {.lex_state = 364},
  [368] = {.lex_state = 16},
  [369] = {.lex_state = 364},
  [370] = {.lex_state = 364},
  [371] = {.lex_state = 364},
  [372] = {.lex_state = 364},
  [373] = {.lex_state = 364},
  [374] = {.lex_state = 364},
  [375] = {.lex_state = 364},
  [376] = {.lex_state = 364},
  [377] = {.lex_state = 364},
  [378] = {.lex_state = 11},
  [379] = {.lex_state = 364},
  [380] = {.lex_state = 364},
  [381] = {.lex_state = 11},
  [382] = {.lex_state = 11},
  [383] = {.lex_state = 11},
  [384] = {.lex_state = 11},
  [385] = {.lex_state = 364},
  [386] = {.lex_state = 364},
  [387] = {.lex_state = 11},
  [388] = {.lex_state = 11},
  [389] = {.lex_state = 364},
  [390] = {.lex_state = 16},
  [391] = {.lex_state = 11},
  [392] = {.lex_state = 364},
  [393] = {.lex_state = 364},
  [394] = {.lex_state = 11},
  [395] = {.lex_state = 11},
  [396] = {.lex_state = 364},
  [397] = {.lex_state = 11},
  [398] = {.lex_state = 364},
  [399] = {.lex_state = 364},
  [400] = {.lex_state = 364},
  [401] = {.lex_state = 364},
  [402] = {.lex_state = 364},
  [403] = {.lex_state = 11},
  [404] = {.lex_state = 11},
  [405] = {.lex_state = 364},
  [406] = {.lex_state = 2},
  [407] = {.lex_state = 11},
  [408] = {.lex_state = 364},
  [409] = {.lex_state = 2},
  [410] = {.lex_state = 364},
  [411] = {.lex_state = 2},
  [412] = {.lex_state = 364},
  [413] = {.lex_state = 2},
  [414] = {.lex_state = 364},
  [415] = {.lex_state = 2},
  [416] = {.lex_state = 364},
  [417] = {.lex_state = 2},
  [418] = {.lex_state = 364},
  [419] = {.lex_state = 364},
  [420] = {.lex_state = 2},
  [421] = {.lex_state = 11},
  [422] = {.lex_state = 364},
  [423] = {.lex_state = 364},
  [424] = {.lex_state = 2},
  [425] = {.lex_state = 2},
  [426] = {.lex_state = 364},
  [427] = {.lex_state = 11},
  [428] = {.lex_state = 364},
  [429] = {.lex_state = 11},
  [430] = {.lex_state = 2},
  [431] = {.lex_state = 791},
  [432] = {.lex_state = 364},
  [433] = {.lex_state = 364},
  [434] = {.lex_state = 11},
  [435] = {.lex_state = 364},
  [436] = {.lex_state = 364},
  [437] = {.lex_state = 364},
  [438] = {.lex_state = 15},
  [439] = {.lex_state = 364},
  [440] = {.lex_state = 364},
  [441] = {.lex_state = 364},
  [442] = {.lex_state = 364},
  [443] = {.lex_state = 11},
  [444] = {.lex_state = 364},
  [445] = {.lex_state = 791},
  [446] = {.lex_state = 15},
  [447] = {.lex_state = 364},
  [448] = {.lex_state = 364},
  [449] = {.lex_state = 11},
  [450] = {.lex_state = 364},
  [451] = {.lex_state = 11},
  [452] = {.lex_state = 11},
  [453] = {.lex_state = 364},
  [454] = {.lex_state = 364},
  [455] = {.lex_state = 11},
  [456] = {.lex_state = 11},
  [457] = {.lex_state = 364},
  [458] = {.lex_state = 364},
  [459] = {.lex_state = 364},
  [460] = {.lex_state = 364},
  [461] = {.lex_state = 2},
  [462] = {.lex_state = 10},
  [463] = {.lex_state = 364},
  [464] = {.lex_state = 364},
  [465] = {.lex_state = 364},
  [466] = {.lex_state = 791},
  [467] = {.lex_state = 11},
  [468] = {.lex_state = 11},
  [469] = {.lex_state = 11},
  [470] = {.lex_state = 364},
  [471] = {.lex_state = 364},
  [472] = {.lex_state = 11},
  [473] = {.lex_state = 364},
  [474] = {.lex_state = 364},
  [475] = {.lex_state = 11},
  [476] = {.lex_state = 364},
  [477] = {.lex_state = 19},
  [478] = {.lex_state = 364},
  [479] = {.lex_state = 364},
  [480] = {.lex_state = 11},
  [481] = {.lex_state = 364},
  [482] = {.lex_state = 11},
  [483] = {.lex_state = 14},
  [484] = {.lex_state = 364},
  [485] = {.lex_state = 364},
  [486] = {.lex_state = 364},
  [487] = {.lex_state = 364},
  [488] = {.lex_state = 364},
  [489] = {.lex_state = 364},
  [490] = {.lex_state = 364},
  [491] = {.lex_state = 364},
  [492] = {.lex_state = 364},
  [493] = {.lex_state = 364},
  [494] = {.lex_state = 11},
  [495] = {.lex_state = 14},
  [496] = {.lex_state = 364},
  [497] = {.lex_state = 364},
  [498] = {.lex_state = 364},
  [499] = {.lex_state = 364},
  [500] = {.lex_state = 364},
  [501] = {.lex_state = 11},
  [502] = {.lex_state = 11},
  [503] = {.lex_state = 2},
  [504] = {.lex_state = 364},
  [505] = {.lex_state = 14},
  [506] = {.lex_state = 364},
  [507] = {.lex_state = 364},
  [508] = {.lex_state = 364},
  [509] = {.lex_state = 10},
  [510] = {.lex_state = 11},
  [511] = {.lex_state = 364},
  [512] = {.lex_state = 19},
  [513] = {.lex_state = 364},
  [514] = {.lex_state = 10},
  [515] = {.lex_state = 10},
  [516] = {.lex_state = 10},
  [517] = {.lex_state = 364},
  [518] = {.lex_state = 15},
  [519] = {.lex_state = 10},
  [520] = {.lex_state = 11},
  [521] = {.lex_state = 364},
  [522] = {.lex_state = 2},
  [523] = {.lex_state = 364},
  [524] = {.lex_state = 364},
  [525] = {.lex_state = 364},
  [526] = {.lex_state = 364},
  [527] = {.lex_state = 364},
  [528] = {.lex_state = 11},
  [529] = {.lex_state = 364},
  [530] = {.lex_state = 364},
  [531] = {.lex_state = 14},
  [532] = {.lex_state = 364},
  [533] = {.lex_state = 364},
  [534] = {.lex_state = 364},
  [535] = {.lex_state = 364},
  [536] = {.lex_state = 11},
  [537] = {.lex_state = 364},
  [538] = {.lex_state = 364},
  [539] = {.lex_state = 10},
  [540] = {.lex_state = 364},
  [541] = {.lex_state = 364},
  [542] = {.lex_state = 364},
  [543] = {.lex_state = 364},
  [544] = {.lex_state = 364},
  [545] = {.lex_state = 364},
  [546] = {.lex_state = 364},
  [547] = {.lex_state = 364},
  [548] = {.lex_state = 364},
  [549] = {.lex_state = 10},
  [550] = {.lex_state = 10},
  [551] = {.lex_state = 11},
  [552] = {.lex_state = 364},
  [553] = {.lex_state = 10},
  [554] = {.lex_state = 364},
  [555] = {.lex_state = 364},
  [556] = {.lex_state = 364},
  [557] = {.lex_state = 364},
  [558] = {.lex_state = 364},
  [559] = {.lex_state = 11},
  [560] = {.lex_state = 364},
  [561] = {.lex_state = 2},
  [562] = {.lex_state = 791},
  [563] = {.lex_state = 11},
  [564] = {.lex_state = 364},
  [565] = {.lex_state = 364},
  [566] = {.lex_state = 10},
  [567] = {.lex_state = 364},
  [568] = {.lex_state = 364},
  [569] = {.lex_state = 364},
  [570] = {.lex_state = 364},
  [571] = {.lex_state = 11},
  [572] = {.lex_state = 14},
  [573] = {.lex_state = 364},
  [574] = {.lex_state = 364},
  [575] = {.lex_state = 364},
  [576] = {.lex_state = 364},
  [577] = {.lex_state = 10},
  [578] = {.lex_state = 10},
  [579] = {.lex_state = 364},
  [580] = {.lex_state = 364},
  [581] = {.lex_state = 364},
  [582] = {.lex_state = 364},
  [583] = {.lex_state = 6},
  [584] = {.lex_state = 364},
  [585] = {.lex_state = 364},
  [586] = {.lex_state = 364},
  [587] = {.lex_state = 14},
  [588] = {.lex_state = 364},
  [589] = {.lex_state = 364},
  [590] = {.lex_state = 364},
  [591] = {.lex_state = 10},
  [592] = {.lex_state = 364},
  [593] = {.lex_state = 364},
  [594] = {.lex_state = 364},
  [595] = {.lex_state = 364},
  [596] = {.lex_state = 10},
  [597] = {.lex_state = 364},
  [598] = {.lex_state = 364},
  [599] = {.lex_state = 364},
  [600] = {.lex_state = 10},
  [601] = {.lex_state = 364},
  [602] = {.lex_state = 364},
  [603] = {.lex_state = 15},
  [604] = {.lex_state = 364},
  [605] = {.lex_state = 364},
  [606] = {.lex_state = 364},
  [607] = {.lex_state = 364},
  [608] = {.lex_state = 364},
  [609] = {.lex_state = 6},
  [610] = {.lex_state = 364},
  [611] = {.lex_state = 364},
  [612] = {.lex_state = 364},
  [613] = {.lex_state = 5},
  [614] = {.lex_state = 364},
  [615] = {.lex_state = 364},
  [616] = {.lex_state = 364},
  [617] = {.lex_state = 364},
  [618] = {.lex_state = 364},
  [619] = {.lex_state = 2},
  [620] = {.lex_state = 364},
  [621] = {.lex_state = 5},
  [622] = {.lex_state = 364},
  [623] = {.lex_state = 364},
  [624] = {.lex_state = 364},
  [625] = {.lex_state = 6},
  [626] = {.lex_state = 364},
  [627] = {.lex_state = 364},
  [628] = {.lex_state = 364},
  [629] = {.lex_state = 364},
  [630] = {.lex_state = 364},
  [631] = {.lex_state = 364},
  [632] = {.lex_state = 364},
  [633] = {.lex_state = 364},
  [634] = {.lex_state = 364},
  [635] = {.lex_state = 364},
  [636] = {.lex_state = 364},
  [637] = {.lex_state = 364},
  [638] = {.lex_state = 364},
  [639] = {.lex_state = 364},
  [640] = {.lex_state = 364},
  [641] = {.lex_state = 6},
  [642] = {.lex_state = 364},
  [643] = {.lex_state = 364},
  [644] = {.lex_state = 364},
  [645] = {.lex_state = 364},
  [646] = {.lex_state = 15},
  [647] = {.lex_state = 364},
  [648] = {.lex_state = 11},
  [649] = {.lex_state = 364},
  [650] = {.lex_state = 10},
  [651] = {.lex_state = 364},
  [652] = {.lex_state = 364},
  [653] = {.lex_state = 11},
  [654] = {.lex_state = 364},
  [655] = {.lex_state = 364},
  [656] = {.lex_state = 11},
  [657] = {.lex_state = 364},
  [658] = {.lex_state = 364},
  [659] = {.lex_state = 364},
  [660] = {.lex_state = 11},
  [661] = {.lex_state = 11},
  [662] = {.lex_state = 10},
  [663] = {.lex_state = 364},
  [664] = {.lex_state = 10},
  [665] = {.lex_state = 364},
  [666] = {.lex_state = 364},
  [667] = {.lex_state = 11},
  [668] = {.lex_state = 364},
  [669] = {.lex_state = 364},
  [670] = {.lex_state = 11},
  [671] = {.lex_state = 364},
  [672] = {.lex_state = 364},
  [673] = {.lex_state = 364},
  [674] = {.lex_state = 364},
  [675] = {.lex_state = 364},
  [676] = {.lex_state = 364},
  [677] = {.lex_state = 364},
  [678] = {.lex_state = 11},
  [679] = {.lex_state = 364},
  [680] = {.lex_state = 364},
  [681] = {.lex_state = 364},
  [682] = {.lex_state = 364},
  [683] = {.lex_state = 364},
  [684] = {.lex_state = 364},
  [685] = {.lex_state = 11},
  [686] = {.lex_state = 364},
  [687] = {.lex_state = 364},
  [688] = {.lex_state = 11},
  [689] = {.lex_state = 11},
  [690] = {.lex_state = 364},
  [691] = {.lex_state = 11},
  [692] = {.lex_state = 364},
  [693] = {.lex_state = 364},
  [694] = {.lex_state = 11},
  [695] = {.lex_state = 364},
  [696] = {.lex_state = 364},
  [697] = {.lex_state = 364},
  [698] = {.lex_state = 364},
  [699] = {.lex_state = 364},
  [700] = {.lex_state = 364},
  [701] = {.lex_state = 364},
  [702] = {.lex_state = 11},
  [703] = {.lex_state = 364},
  [704] = {.lex_state = 11},
  [705] = {.lex_state = 11},
  [706] = {.lex_state = 364},
  [707] = {.lex_state = 364},
  [708] = {.lex_state = 364},
  [709] = {.lex_state = 364},
  [710] = {.lex_state = 364},
  [711] = {.lex_state = 364},
  [712] = {.lex_state = 364},
  [713] = {.lex_state = 364},
  [714] = {.lex_state = 364},
  [715] = {.lex_state = 364},
  [716] = {.lex_state = 364},
  [717] = {.lex_state = 364},
  [718] = {.lex_state = 6},
  [719] = {.lex_state = 364},
  [720] = {.lex_state = 11},
  [721] = {.lex_state = 364},
  [722] = {.lex_state = 11},
  [723] = {.lex_state = 364},
  [724] = {.lex_state = 11},
  [725] = {.lex_state = 364},
  [726] = {.lex_state = 364},
  [727] = {.lex_state = 364},
  [728] = {.lex_state = 364},
  [729] = {.lex_state = 364},
  [730] = {.lex_state = 11},
  [731] = {.lex_state = 364},
  [732] = {.lex_state = 364},
  [733] = {.lex_state = 11},
  [734] = {.lex_state = 364},
  [735] = {.lex_state = 364},
  [736] = {.lex_state = 11},
  [737] = {.lex_state = 11},
  [738] = {.lex_state = 10},
  [739] = {.lex_state = 364},
  [740] = {.lex_state = 11},
  [741] = {.lex_state = 364},
  [742] = {.lex_state = 364},
  [743] = {.lex_state = 11},
  [744] = {.lex_state = 11},
  [745] = {.lex_state = 364},
  [746] = {.lex_state = 11},
  [747] = {.lex_state = 11},
  [748] = {.lex_state = 364},
  [749] = {.lex_state = 364},
  [750] = {.lex_state = 11},
  [751] = {.lex_state = 364},
  [752] = {.lex_state = 364},
  [753] = {.lex_state = 364},
  [754] = {.lex_state = 364},
  [755] = {.lex_state = 27},
  [756] = {.lex_state = 364},
  [757] = {.lex_state = 364},
  [758] = {.lex_state = 364},
  [759] = {.lex_state = 364},
  [760] = {.lex_state = 364},
  [761] = {.lex_state = 364},
  [762] = {.lex_state = 364},
  [763] = {.lex_state = 364},
  [764] = {.lex_state = 364},
  [765] = {.lex_state = 364},
  [766] = {.lex_state = 11},
  [767] = {.lex_state = 11},
  [768] = {.lex_state = 364},
  [769] = {.lex_state = 364},
  [770] = {.lex_state = 364},
  [771] = {.lex_state = 364},
  [772] = {.lex_state = 364},
  [773] = {.lex_state = 364},
  [774] = {.lex_state = 11},
  [775] = {.lex_state = 364},
  [776] = {.lex_state = 364},
  [777] = {.lex_state = 364},
  [778] = {.lex_state = 11},
  [779] = {.lex_state = 364},
  [780] = {.lex_state = 364},
  [781] = {.lex_state = 364},
  [782] = {.lex_state = 364},
  [783] = {.lex_state = 364},
  [784] = {.lex_state = 364},
  [785] = {.lex_state = 364},
  [786] = {.lex_state = 364},
  [787] = {.lex_state = 11},
  [788] = {.lex_state = 364},
  [789] = {.lex_state = 11},
  [790] = {.lex_state = 11},
  [791] = {.lex_state = 364},
  [792] = {.lex_state = 364},
  [793] = {.lex_state = 364},
  [794] = {.lex_state = 364},
  [795] = {.lex_state = 364},
  [796] = {.lex_state = 364},
  [797] = {.lex_state = 364},
  [798] = {.lex_state = 11},
  [799] = {.lex_state = 11},
  [800] = {.lex_state = 364},
  [801] = {.lex_state = 11},
  [802] = {.lex_state = 364},
  [803] = {.lex_state = 364},
  [804] = {.lex_state = 364},
  [805] = {.lex_state = 364},
  [806] = {.lex_state = 11},
  [807] = {.lex_state = 364},
  [808] = {.lex_state = 364},
  [809] = {.lex_state = 364},
  [810] = {.lex_state = 364},
  [811] = {.lex_state = 364},
  [812] = {.lex_state = 364},
  [813] = {.lex_state = 364},
  [814] = {.lex_state = 364},
  [815] = {.lex_state = 364},
  [816] = {.lex_state = 364},
  [817] = {.lex_state = 10},
  [818] = {.lex_state = 364},
  [819] = {.lex_state = 364},
  [820] = {.lex_state = 364},
  [821] = {.lex_state = 364},
  [822] = {.lex_state = 364},
  [823] = {.lex_state = 364},
  [824] = {.lex_state = 11},
  [825] = {.lex_state = 364},
  [826] = {.lex_state = 364},
  [827] = {.lex_state = 11},
  [828] = {.lex_state = 11},
  [829] = {.lex_state = 11},
  [830] = {.lex_state = 364},
  [831] = {.lex_state = 364},
  [832] = {.lex_state = 364},
  [833] = {.lex_state = 364},
  [834] = {.lex_state = 364},
  [835] = {.lex_state = 364},
  [836] = {.lex_state = 364},
  [837] = {.lex_state = 364},
  [838] = {.lex_state = 364},
  [839] = {.lex_state = 364},
  [840] = {.lex_state = 364},
  [841] = {.lex_state = 364},
  [842] = {.lex_state = 11},
  [843] = {.lex_state = 11},
  [844] = {.lex_state = 11},
  [845] = {.lex_state = 364},
  [846] = {.lex_state = 364},
  [847] = {.lex_state = 364},
  [848] = {.lex_state = 11},
  [849] = {.lex_state = 11},
  [850] = {.lex_state = 364},
  [851] = {.lex_state = 364},
  [852] = {.lex_state = 364},
  [853] = {.lex_state = 364},
  [854] = {.lex_state = 364},
  [855] = {.lex_state = 27},
  [856] = {.lex_state = 10},
  [857] = {.lex_state = 11},
  [858] = {.lex_state = 364},
  [859] = {.lex_state = 364},
  [860] = {.lex_state = 364},
  [861] = {.lex_state = 364},
  [862] = {.lex_state = 364},
  [863] = {.lex_state = 364},
  [864] = {.lex_state = 364},
  [865] = {.lex_state = 364},
  [866] = {.lex_state = 364},
  [867] = {.lex_state = 364},
  [868] = {.lex_state = 364},
  [869] = {.lex_state = 364},
  [870] = {.lex_state = 364},
  [871] = {.lex_state = 11},
  [872] = {.lex_state = 364},
  [873] = {.lex_state = 364},
  [874] = {.lex_state = 364},
  [875] = {.lex_state = 364},
  [876] = {.lex_state = 11},
  [877] = {.lex_state = 11},
  [878] = {.lex_state = 364},
  [879] = {(TSStateId)(-1)},
  [880] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_block_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_PIPE2] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [sym_digit] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_space] = ACTIONS(3),
    [sym_string_fragment] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [sym_newline] = ACTIONS(1),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [sym_line_comment] = ACTIONS(7),
  },
  [1] = {
    [sym_gsql] = STATE(865),
    [sym__definition] = STATE(524),
    [sym_create_query] = STATE(601),
    [sym_interpret_query] = STATE(601),
    [sym_block_comment] = STATE(1),
    [aux_sym_gsql_repeat1] = STATE(359),
    [ts_builtin_sym_end] = ACTIONS(9),
    [anon_sym_CREATE] = ACTIONS(11),
    [anon_sym_INTERPRET] = ACTIONS(13),
    [sym_space] = ACTIONS(7),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [sym_line_comment] = ACTIONS(7),
  },
  [2] = {
    [sym_typedef] = STATE(72),
    [sym_query_body_stmt] = STATE(72),
    [sym_assign_stmt] = STATE(785),
    [sym_v_set_var_decl_stmt] = STATE(785),
    [sym_l_accum_assign_stmt] = STATE(785),
    [sym_g_accum_assign_stmt] = STATE(785),
    [sym_g_accum_accum_stmt] = STATE(785),
    [sym_func_call_stmt] = STATE(785),
    [sym__select_stmt] = STATE(785),
    [sym_gsql_select_block] = STATE(784),
    [sym_gsql_select_clause] = STATE(636),
    [sym_query_body_case_stmt] = STATE(785),
    [sym_query_body_if_stmt] = STATE(785),
    [sym_query_body_while_stmt] = STATE(785),
    [sym_query_body_for_each_stmt] = STATE(785),
    [sym_decl_stmt] = STATE(785),
    [sym_base_decl_stmt] = STATE(782),
    [sym_accum_decl_stmt] = STATE(782),
    [sym_accum_type] = STATE(448),
    [sym_global_accum_name] = STATE(462),
    [sym_local_accum_name] = STATE(634),
    [sym_print_stmt] = STATE(785),
    [sym_base_type] = STATE(778),
    [sym_block_comment] = STATE(2),
    [aux_sym_query_body_repeat1] = STATE(4),
    [anon_sym_RBRACE] = ACTIONS(15),
    [anon_sym_TYPEDEF] = ACTIONS(17),
    [anon_sym_IF] = ACTIONS(19),
    [anon_sym_CASE] = ACTIONS(21),
    [anon_sym_WHILE] = ACTIONS(23),
    [anon_sym_FOREACH] = ACTIONS(25),
    [anon_sym_SumAccum] = ACTIONS(27),
    [anon_sym_INT] = ACTIONS(29),
    [anon_sym_FLOAT] = ACTIONS(29),
    [anon_sym_DOUBLE] = ACTIONS(29),
    [anon_sym_STRING] = ACTIONS(29),
    [anon_sym_MaxAccum] = ACTIONS(31),
    [anon_sym_MinAccum] = ACTIONS(31),
    [anon_sym_AvgAccum] = ACTIONS(33),
    [anon_sym_OrAccum] = ACTIONS(33),
    [anon_sym_AndAccum] = ACTIONS(33),
    [anon_sym_BitwiseorAccum] = ACTIONS(33),
    [anon_sym_BitwiseandAccum] = ACTIONS(33),
    [anon_sym_ListAccum] = ACTIONS(35),
    [anon_sym_SetAccum] = ACTIONS(37),
    [anon_sym_BagAccum] = ACTIONS(37),
    [anon_sym_MapAccum] = ACTIONS(39),
    [anon_sym_HeapAccum] = ACTIONS(41),
    [anon_sym_GroupbyAccum] = ACTIONS(43),
    [anon_sym_ArrayAccum] = ACTIONS(45),
    [anon_sym_AT_AT] = ACTIONS(47),
    [anon_sym_AT] = ACTIONS(49),
    [anon_sym_PRINT] = ACTIONS(51),
    [anon_sym_BOOL] = ACTIONS(29),
    [anon_sym_UINT] = ACTIONS(29),
    [anon_sym_VERTEX] = ACTIONS(53),
    [anon_sym_EDGE] = ACTIONS(29),
    [anon_sym_JSONOBJECT] = ACTIONS(29),
    [anon_sym_JSONARRAY] = ACTIONS(29),
    [anon_sym_DATETIME] = ACTIONS(29),
    [sym_name] = ACTIONS(55),
    [sym_space] = ACTIONS(3),
    [sym_spacing_line] = ACTIONS(57),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [sym_line_comment] = ACTIONS(7),
  },
  [3] = {
    [sym_typedef] = STATE(72),
    [sym_query_body_stmt] = STATE(72),
    [sym_assign_stmt] = STATE(785),
    [sym_v_set_var_decl_stmt] = STATE(785),
    [sym_l_accum_assign_stmt] = STATE(785),
    [sym_g_accum_assign_stmt] = STATE(785),
    [sym_g_accum_accum_stmt] = STATE(785),
    [sym_func_call_stmt] = STATE(785),
    [sym__select_stmt] = STATE(785),
    [sym_gsql_select_block] = STATE(784),
    [sym_gsql_select_clause] = STATE(636),
    [sym_query_body_case_stmt] = STATE(785),
    [sym_query_body_if_stmt] = STATE(785),
    [sym_query_body_while_stmt] = STATE(785),
    [sym_query_body_for_each_stmt] = STATE(785),
    [sym_decl_stmt] = STATE(785),
    [sym_base_decl_stmt] = STATE(782),
    [sym_accum_decl_stmt] = STATE(782),
    [sym_accum_type] = STATE(448),
    [sym_global_accum_name] = STATE(462),
    [sym_local_accum_name] = STATE(634),
    [sym_print_stmt] = STATE(785),
    [sym_base_type] = STATE(778),
    [sym_block_comment] = STATE(3),
    [aux_sym_query_body_repeat1] = STATE(2),
    [anon_sym_RBRACE] = ACTIONS(59),
    [anon_sym_TYPEDEF] = ACTIONS(17),
    [anon_sym_IF] = ACTIONS(19),
    [anon_sym_CASE] = ACTIONS(21),
    [anon_sym_WHILE] = ACTIONS(23),
    [anon_sym_FOREACH] = ACTIONS(25),
    [anon_sym_SumAccum] = ACTIONS(27),
    [anon_sym_INT] = ACTIONS(29),
    [anon_sym_FLOAT] = ACTIONS(29),
    [anon_sym_DOUBLE] = ACTIONS(29),
    [anon_sym_STRING] = ACTIONS(29),
    [anon_sym_MaxAccum] = ACTIONS(31),
    [anon_sym_MinAccum] = ACTIONS(31),
    [anon_sym_AvgAccum] = ACTIONS(33),
    [anon_sym_OrAccum] = ACTIONS(33),
    [anon_sym_AndAccum] = ACTIONS(33),
    [anon_sym_BitwiseorAccum] = ACTIONS(33),
    [anon_sym_BitwiseandAccum] = ACTIONS(33),
    [anon_sym_ListAccum] = ACTIONS(35),
    [anon_sym_SetAccum] = ACTIONS(37),
    [anon_sym_BagAccum] = ACTIONS(37),
    [anon_sym_MapAccum] = ACTIONS(39),
    [anon_sym_HeapAccum] = ACTIONS(41),
    [anon_sym_GroupbyAccum] = ACTIONS(43),
    [anon_sym_ArrayAccum] = ACTIONS(45),
    [anon_sym_AT_AT] = ACTIONS(47),
    [anon_sym_AT] = ACTIONS(49),
    [anon_sym_PRINT] = ACTIONS(51),
    [anon_sym_BOOL] = ACTIONS(29),
    [anon_sym_UINT] = ACTIONS(29),
    [anon_sym_VERTEX] = ACTIONS(53),
    [anon_sym_EDGE] = ACTIONS(29),
    [anon_sym_JSONOBJECT] = ACTIONS(29),
    [anon_sym_JSONARRAY] = ACTIONS(29),
    [anon_sym_DATETIME] = ACTIONS(29),
    [sym_name] = ACTIONS(55),
    [sym_space] = ACTIONS(3),
    [sym_spacing_line] = ACTIONS(57),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [sym_line_comment] = ACTIONS(7),
  },
  [4] = {
    [sym_typedef] = STATE(72),
    [sym_query_body_stmt] = STATE(72),
    [sym_assign_stmt] = STATE(785),
    [sym_v_set_var_decl_stmt] = STATE(785),
    [sym_l_accum_assign_stmt] = STATE(785),
    [sym_g_accum_assign_stmt] = STATE(785),
    [sym_g_accum_accum_stmt] = STATE(785),
    [sym_func_call_stmt] = STATE(785),
    [sym__select_stmt] = STATE(785),
    [sym_gsql_select_block] = STATE(784),
    [sym_gsql_select_clause] = STATE(636),
    [sym_query_body_case_stmt] = STATE(785),
    [sym_query_body_if_stmt] = STATE(785),
    [sym_query_body_while_stmt] = STATE(785),
    [sym_query_body_for_each_stmt] = STATE(785),
    [sym_decl_stmt] = STATE(785),
    [sym_base_decl_stmt] = STATE(782),
    [sym_accum_decl_stmt] = STATE(782),
    [sym_accum_type] = STATE(448),
    [sym_global_accum_name] = STATE(462),
    [sym_local_accum_name] = STATE(634),
    [sym_print_stmt] = STATE(785),
    [sym_base_type] = STATE(778),
    [sym_block_comment] = STATE(4),
    [aux_sym_query_body_repeat1] = STATE(4),
    [anon_sym_RBRACE] = ACTIONS(61),
    [anon_sym_TYPEDEF] = ACTIONS(63),
    [anon_sym_IF] = ACTIONS(66),
    [anon_sym_CASE] = ACTIONS(69),
    [anon_sym_WHILE] = ACTIONS(72),
    [anon_sym_FOREACH] = ACTIONS(75),
    [anon_sym_SumAccum] = ACTIONS(78),
    [anon_sym_INT] = ACTIONS(81),
    [anon_sym_FLOAT] = ACTIONS(81),
    [anon_sym_DOUBLE] = ACTIONS(81),
    [anon_sym_STRING] = ACTIONS(81),
    [anon_sym_MaxAccum] = ACTIONS(84),
    [anon_sym_MinAccum] = ACTIONS(84),
    [anon_sym_AvgAccum] = ACTIONS(87),
    [anon_sym_OrAccum] = ACTIONS(87),
    [anon_sym_AndAccum] = ACTIONS(87),
    [anon_sym_BitwiseorAccum] = ACTIONS(87),
    [anon_sym_BitwiseandAccum] = ACTIONS(87),
    [anon_sym_ListAccum] = ACTIONS(90),
    [anon_sym_SetAccum] = ACTIONS(93),
    [anon_sym_BagAccum] = ACTIONS(93),
    [anon_sym_MapAccum] = ACTIONS(96),
    [anon_sym_HeapAccum] = ACTIONS(99),
    [anon_sym_GroupbyAccum] = ACTIONS(102),
    [anon_sym_ArrayAccum] = ACTIONS(105),
    [anon_sym_AT_AT] = ACTIONS(108),
    [anon_sym_AT] = ACTIONS(111),
    [anon_sym_PRINT] = ACTIONS(114),
    [anon_sym_BOOL] = ACTIONS(81),
    [anon_sym_UINT] = ACTIONS(81),
    [anon_sym_VERTEX] = ACTIONS(117),
    [anon_sym_EDGE] = ACTIONS(81),
    [anon_sym_JSONOBJECT] = ACTIONS(81),
    [anon_sym_JSONARRAY] = ACTIONS(81),
    [anon_sym_DATETIME] = ACTIONS(81),
    [sym_name] = ACTIONS(120),
    [sym_space] = ACTIONS(3),
    [sym_spacing_line] = ACTIONS(123),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [sym_line_comment] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(5), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(734), 1,
      sym_query_body_stmt,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [123] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(6), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(488), 1,
      sym_query_body_stmt,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [246] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(7), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(612), 1,
      sym_query_body_stmt,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [369] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    ACTIONS(126), 1,
      anon_sym_IF,
    STATE(8), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(712), 1,
      sym_query_body_stmt,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [492] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(9), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(486), 1,
      sym_query_body_stmt,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [615] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(10), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(498), 1,
      sym_query_body_stmt,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [738] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(11), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    STATE(878), 1,
      sym_query_body_stmt,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [861] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(12), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    STATE(813), 1,
      sym_query_body_stmt,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [984] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    ACTIONS(126), 1,
      anon_sym_IF,
    STATE(13), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(762), 1,
      sym_query_body_stmt,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [1107] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(14), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    STATE(825), 1,
      sym_query_body_stmt,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [1230] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(15), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    STATE(852), 1,
      sym_query_body_stmt,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [1353] = 31,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      anon_sym_IF,
    ACTIONS(21), 1,
      anon_sym_CASE,
    ACTIONS(23), 1,
      anon_sym_WHILE,
    ACTIONS(25), 1,
      anon_sym_FOREACH,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(51), 1,
      anon_sym_PRINT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(55), 1,
      sym_name,
    STATE(16), 1,
      sym_block_comment,
    STATE(448), 1,
      sym_accum_type,
    STATE(462), 1,
      sym_global_accum_name,
    STATE(508), 1,
      sym_query_body_stmt,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(778), 1,
      sym_base_type,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(782), 2,
      sym_base_decl_stmt,
      sym_accum_decl_stmt,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(800), 13,
      sym_assign_stmt,
      sym_v_set_var_decl_stmt,
      sym_l_accum_assign_stmt,
      sym_g_accum_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym__select_stmt,
      sym_query_body_case_stmt,
      sym_query_body_if_stmt,
      sym_query_body_while_stmt,
      sym_query_body_for_each_stmt,
      sym_decl_stmt,
      sym_print_stmt,
  [1476] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(17), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(130), 6,
      anon_sym_EQ,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
      anon_sym_PLUS,
    ACTIONS(128), 41,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_RBRACE,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PLUS_EQ,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_COLON,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1538] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(134), 1,
      anon_sym_LPAREN,
    ACTIONS(138), 1,
      anon_sym_DOT,
    STATE(18), 1,
      sym_block_comment,
    STATE(26), 1,
      aux_sym_name_dot_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(136), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(132), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1604] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(144), 1,
      anon_sym_DOT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(19), 2,
      sym_block_comment,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(142), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(140), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1665] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(151), 1,
      anon_sym_DOT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(20), 2,
      sym_block_comment,
      aux_sym_name_dot_repeat1,
    ACTIONS(149), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(147), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1726] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(158), 1,
      anon_sym_DOT,
    STATE(21), 1,
      sym_block_comment,
    STATE(24), 1,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(154), 35,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1791] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(158), 1,
      anon_sym_DOT,
    STATE(22), 1,
      sym_block_comment,
    STATE(24), 1,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(162), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(160), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1854] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(164), 1,
      anon_sym_DOT,
    STATE(23), 1,
      sym_block_comment,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(154), 35,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1919] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(158), 1,
      anon_sym_DOT,
    STATE(19), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(24), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(168), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(166), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1982] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(170), 1,
      anon_sym_LPAREN,
    STATE(25), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(149), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(147), 39,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2043] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(20), 1,
      aux_sym_name_dot_repeat1,
    STATE(26), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(174), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(172), 39,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2104] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(26), 1,
      aux_sym_name_dot_repeat1,
    STATE(27), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(136), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(132), 39,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2165] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(28), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(178), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(176), 39,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2223] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(180), 1,
      anon_sym_DOT,
    STATE(29), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(162), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(160), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2283] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(30), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(184), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(182), 39,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2341] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(31), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(188), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(186), 39,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2399] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(32), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(149), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(147), 39,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2457] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(33), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(154), 35,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2516] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(34), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(194), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(192), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2573] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(35), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(162), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(160), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2630] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(36), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(194), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(192), 38,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2687] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(196), 1,
      anon_sym_DOT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(37), 2,
      sym_block_comment,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(142), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(140), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2745] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(203), 1,
      sym_digit,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(38), 2,
      sym_block_comment,
      aux_sym_accum_type_repeat1,
    ACTIONS(201), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(199), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2803] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(164), 1,
      anon_sym_DOT,
    STATE(37), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(39), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(208), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(206), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2863] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    STATE(38), 1,
      aux_sym_accum_type_repeat1,
    STATE(40), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(213), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(210), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2923] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    STATE(38), 1,
      aux_sym_accum_type_repeat1,
    STATE(41), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(220), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(218), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2983] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(42), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(178), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(176), 37,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3038] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(228), 1,
      anon_sym_DOT,
    STATE(43), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(225), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(222), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3095] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(44), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(188), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(186), 37,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3150] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(234), 1,
      anon_sym_DOT,
    STATE(45), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(232), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(230), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3207] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(240), 1,
      anon_sym_DOT,
    STATE(46), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(238), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(236), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3264] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(47), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(244), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(242), 37,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      sym_digit,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3319] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(250), 1,
      anon_sym_DOT,
    STATE(48), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(248), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(246), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3376] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(49), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(254), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(252), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3430] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(50), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(258), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(256), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3484] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(51), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(262), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(260), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3538] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(52), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(266), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(264), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3592] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(53), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(270), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(268), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3646] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(54), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(274), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(272), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3700] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(55), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(278), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(276), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3754] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(56), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(238), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(236), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3808] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(57), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(282), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(280), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3862] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(58), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(286), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(284), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3916] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(59), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(291), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(288), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [3970] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(60), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(296), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(294), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4024] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(61), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(300), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(298), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4078] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(62), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(304), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(302), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4132] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(63), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(156), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(154), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4186] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(64), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(308), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(306), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4240] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(65), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(312), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(310), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4294] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(66), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(316), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(314), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4348] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(67), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(320), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(318), 36,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4402] = 6,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(68), 1,
      sym_block_comment,
    ACTIONS(322), 3,
      anon_sym_RBRACE,
      anon_sym_AT_AT,
      sym_spacing_line,
    ACTIONS(324), 34,
      anon_sym_TYPEDEF,
      anon_sym_IF,
      anon_sym_CASE,
      anon_sym_WHILE,
      anon_sym_FOREACH,
      anon_sym_SumAccum,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
      anon_sym_ListAccum,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
      anon_sym_MapAccum,
      anon_sym_HeapAccum,
      anon_sym_GroupbyAccum,
      anon_sym_ArrayAccum,
      anon_sym_AT,
      anon_sym_PRINT,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [4456] = 6,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(69), 1,
      sym_block_comment,
    ACTIONS(326), 3,
      anon_sym_RBRACE,
      anon_sym_AT_AT,
      sym_spacing_line,
    ACTIONS(328), 34,
      anon_sym_TYPEDEF,
      anon_sym_IF,
      anon_sym_CASE,
      anon_sym_WHILE,
      anon_sym_FOREACH,
      anon_sym_SumAccum,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
      anon_sym_ListAccum,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
      anon_sym_MapAccum,
      anon_sym_HeapAccum,
      anon_sym_GroupbyAccum,
      anon_sym_ArrayAccum,
      anon_sym_AT,
      anon_sym_PRINT,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [4510] = 32,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(330), 1,
      anon_sym_LPAREN,
    ACTIONS(332), 1,
      anon_sym_LBRACE,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(336), 1,
      anon_sym_SELECT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(350), 1,
      sym_name,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(70), 1,
      sym_block_comment,
    STATE(254), 1,
      sym_expr,
    STATE(428), 1,
      sym_simple_set,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(636), 1,
      sym_gsql_select_clause,
    STATE(753), 1,
      sym_aggregator,
    STATE(784), 1,
      sym_gsql_select_block,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    STATE(676), 2,
      sym_seed_set,
      sym__select_stmt,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [4616] = 6,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(71), 1,
      sym_block_comment,
    ACTIONS(358), 3,
      anon_sym_RBRACE,
      anon_sym_AT_AT,
      sym_spacing_line,
    ACTIONS(360), 34,
      anon_sym_TYPEDEF,
      anon_sym_IF,
      anon_sym_CASE,
      anon_sym_WHILE,
      anon_sym_FOREACH,
      anon_sym_SumAccum,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
      anon_sym_ListAccum,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
      anon_sym_MapAccum,
      anon_sym_HeapAccum,
      anon_sym_GroupbyAccum,
      anon_sym_ArrayAccum,
      anon_sym_AT,
      anon_sym_PRINT,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [4670] = 6,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(72), 1,
      sym_block_comment,
    ACTIONS(362), 3,
      anon_sym_RBRACE,
      anon_sym_AT_AT,
      sym_spacing_line,
    ACTIONS(364), 34,
      anon_sym_TYPEDEF,
      anon_sym_IF,
      anon_sym_CASE,
      anon_sym_WHILE,
      anon_sym_FOREACH,
      anon_sym_SumAccum,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
      anon_sym_ListAccum,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
      anon_sym_MapAccum,
      anon_sym_HeapAccum,
      anon_sym_GroupbyAccum,
      anon_sym_ArrayAccum,
      anon_sym_AT,
      anon_sym_PRINT,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [4724] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(366), 1,
      anon_sym_LPAREN,
    ACTIONS(368), 1,
      anon_sym_DOT,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(73), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_SLASH,
    ACTIONS(154), 26,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [4783] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(156), 1,
      anon_sym_SLASH,
    ACTIONS(366), 1,
      anon_sym_LPAREN,
    ACTIONS(368), 1,
      anon_sym_DOT,
    ACTIONS(370), 1,
      anon_sym_LT,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(74), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(154), 27,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_AND,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [4843] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(372), 1,
      anon_sym_IF,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    STATE(75), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    STATE(692), 1,
      sym_dml_sub_stmt_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [4918] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(76), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(677), 1,
      sym_dml_sub_stmt_list,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [4993] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(77), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(568), 1,
      sym_dml_sub_stmt_list,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5068] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(78), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(558), 1,
      sym_dml_sub_stmt_list,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5143] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(79), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(686), 1,
      sym_dml_sub_stmt_list,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5218] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(80), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(594), 1,
      sym_dml_sub_stmt_list,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5293] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(372), 1,
      anon_sym_IF,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    STATE(81), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(673), 1,
      sym_dml_sub_stmt_list,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5368] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(82), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(496), 1,
      sym_dml_sub_stmt_list,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5443] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(83), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(682), 1,
      sym_dml_sub_stmt_list,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5518] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(84), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(680), 1,
      sym_dml_sub_stmt_list,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5593] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(85), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(557), 1,
      sym_dml_sub_stmt_list,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5668] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(86), 1,
      sym_block_comment,
    STATE(345), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(569), 1,
      sym_dml_sub_stmt_list,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5743] = 17,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(374), 1,
      anon_sym_CASE,
    ACTIONS(376), 1,
      anon_sym_WHILE,
    ACTIONS(378), 1,
      anon_sym_FOREACH,
    ACTIONS(380), 1,
      sym_name,
    ACTIONS(382), 1,
      anon_sym_IF,
    STATE(87), 1,
      sym_block_comment,
    STATE(372), 1,
      sym_dml_sub_stmt,
    STATE(566), 1,
      sym_global_accum_name,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(689), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
    STATE(352), 11,
      sym_assign_stmt,
      sym_g_accum_accum_stmt,
      sym_func_call_stmt,
      sym_l_accum_accum_stmt,
      sym_attr_accum_stmt,
      sym_v_accum_func_call,
      sym_local_var_decl_stmt,
      sym_dml_sub_if_stmt,
      sym_dml_sub_case_stmt,
      sym_dml_sub_while_stmt,
      sym_dml_sub_for_each_stmt,
  [5815] = 30,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(384), 1,
      anon_sym_LPAREN,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(390), 1,
      anon_sym_DASH,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(402), 1,
      sym_name,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    STATE(88), 1,
      sym_block_comment,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(199), 1,
      sym_set_bag_expr,
    STATE(203), 1,
      sym_expr,
    STATE(556), 1,
      sym_condition,
    STATE(603), 1,
      sym_arg_list,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(400), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [5913] = 30,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(384), 1,
      anon_sym_LPAREN,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(390), 1,
      anon_sym_DASH,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(402), 1,
      sym_name,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    STATE(89), 1,
      sym_block_comment,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(198), 1,
      sym_expr,
    STATE(199), 1,
      sym_set_bag_expr,
    STATE(556), 1,
      sym_condition,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(646), 1,
      sym_arg_list,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(400), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6011] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(414), 1,
      anon_sym_RPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(90), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(739), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6104] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(418), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(91), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(837), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6197] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(92), 1,
      sym_block_comment,
    STATE(95), 1,
      sym_expr,
    STATE(545), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6292] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(93), 1,
      sym_block_comment,
    STATE(95), 1,
      sym_expr,
    STATE(325), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6387] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(428), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(94), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(697), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6480] = 15,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(434), 1,
      anon_sym_IN,
    ACTIONS(438), 1,
      anon_sym_NOT,
    ACTIONS(440), 1,
      anon_sym_IS,
    ACTIONS(442), 1,
      anon_sym_BETWEEN,
    ACTIONS(444), 1,
      anon_sym_LIKE,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(95), 1,
      sym_block_comment,
    STATE(166), 1,
      sym_comparison_operator,
    STATE(167), 1,
      sym_math_operator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(432), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(448), 4,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
    ACTIONS(430), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [6547] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(96), 1,
      sym_block_comment,
    STATE(379), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6642] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(97), 1,
      sym_block_comment,
    STATE(478), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6737] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(98), 1,
      sym_block_comment,
    STATE(529), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6832] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(450), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(99), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(669), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [6925] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(100), 1,
      sym_block_comment,
    STATE(567), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7020] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(101), 1,
      sym_block_comment,
    STATE(575), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7115] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(102), 1,
      sym_block_comment,
    STATE(318), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7210] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(103), 1,
      sym_block_comment,
    STATE(579), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7305] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(104), 1,
      sym_block_comment,
    STATE(479), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7400] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(452), 1,
      anon_sym_LPAREN,
    ACTIONS(454), 1,
      anon_sym_DASH,
    ACTIONS(456), 1,
      sym_name,
    STATE(105), 1,
      sym_block_comment,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(199), 1,
      sym_set_bag_expr,
    STATE(272), 1,
      sym_expr,
    STATE(440), 1,
      sym_simple_set,
    STATE(603), 1,
      sym_arg_list,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7493] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(458), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(106), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(851), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7586] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(107), 1,
      sym_block_comment,
    STATE(257), 1,
      sym_expr,
    STATE(399), 1,
      sym_print_expr,
    STATE(405), 1,
      sym_v_expr_set,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7679] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(108), 1,
      sym_block_comment,
    STATE(542), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7774] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(109), 1,
      sym_block_comment,
    STATE(485), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7869] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(110), 1,
      sym_block_comment,
    STATE(439), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [7964] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(111), 1,
      sym_block_comment,
    STATE(257), 1,
      sym_expr,
    STATE(405), 1,
      sym_v_expr_set,
    STATE(476), 1,
      sym_print_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8057] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(112), 1,
      sym_block_comment,
    STATE(458), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8152] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(460), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(113), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(665), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8245] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(462), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(114), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(818), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8338] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(464), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(115), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(776), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8431] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(116), 1,
      sym_block_comment,
    STATE(450), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8526] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(466), 1,
      anon_sym_WHEN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(117), 1,
      sym_block_comment,
    STATE(303), 1,
      sym_expr,
    STATE(463), 1,
      aux_sym_query_body_case_stmt_repeat1,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8619] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(118), 1,
      sym_block_comment,
    STATE(507), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8714] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(468), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(119), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(821), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8807] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(470), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(120), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(777), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8900] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(452), 1,
      anon_sym_LPAREN,
    ACTIONS(454), 1,
      anon_sym_DASH,
    ACTIONS(456), 1,
      sym_name,
    STATE(121), 1,
      sym_block_comment,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(199), 1,
      sym_set_bag_expr,
    STATE(271), 1,
      sym_expr,
    STATE(440), 1,
      sym_simple_set,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(646), 1,
      sym_arg_list,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [8993] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(122), 1,
      sym_block_comment,
    STATE(554), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9088] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(472), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(123), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(847), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9181] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(124), 1,
      sym_block_comment,
    STATE(433), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9276] = 29,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(398), 1,
      anon_sym_NOT,
    ACTIONS(420), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(95), 1,
      sym_expr,
    STATE(125), 1,
      sym_block_comment,
    STATE(565), 1,
      sym_condition,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(424), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 3,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9371] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(474), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(126), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(831), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9464] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(476), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(127), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(832), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9557] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(478), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(128), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(696), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9650] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(480), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(129), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(833), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9743] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(482), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(130), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(830), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9836] = 28,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(484), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(131), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(838), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [9929] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(454), 1,
      anon_sym_DASH,
    ACTIONS(486), 1,
      anon_sym_LPAREN,
    ACTIONS(488), 1,
      sym_name,
    STATE(132), 1,
      sym_block_comment,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(199), 1,
      sym_set_bag_expr,
    STATE(272), 1,
      sym_expr,
    STATE(603), 1,
      sym_arg_list,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10019] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(133), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(275), 1,
      sym_set_bag_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(765), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10109] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(134), 1,
      sym_block_comment,
    STATE(167), 1,
      sym_math_operator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(492), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
    ACTIONS(490), 19,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_POST_DASHACCUM,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [10161] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(135), 1,
      sym_block_comment,
    STATE(287), 1,
      sym_expr,
    STATE(527), 1,
      sym_v_set_proj,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10251] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(136), 1,
      sym_block_comment,
    STATE(287), 1,
      sym_expr,
    STATE(622), 1,
      sym_v_set_proj,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10341] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(137), 1,
      sym_block_comment,
    STATE(167), 1,
      sym_math_operator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(312), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(310), 27,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_IN,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_TO_CSV,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [10389] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(138), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(808), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10479] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(494), 1,
      anon_sym_LPAREN,
    ACTIONS(496), 1,
      anon_sym_DOT,
    STATE(139), 1,
      sym_block_comment,
    STATE(206), 1,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(154), 20,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [10533] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(454), 1,
      anon_sym_DASH,
    ACTIONS(486), 1,
      anon_sym_LPAREN,
    ACTIONS(488), 1,
      sym_name,
    STATE(140), 1,
      sym_block_comment,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(199), 1,
      sym_set_bag_expr,
    STATE(271), 1,
      sym_expr,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(646), 1,
      sym_arg_list,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10623] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(141), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    STATE(826), 1,
      sym_arg_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10713] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(142), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(275), 1,
      sym_set_bag_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(749), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10803] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(143), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(726), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10893] = 27,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(144), 1,
      sym_block_comment,
    STATE(268), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(721), 1,
      sym_arg_list,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [10983] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(498), 1,
      anon_sym_LPAREN,
    ACTIONS(500), 1,
      anon_sym_DOT,
    STATE(145), 1,
      sym_block_comment,
    STATE(156), 1,
      aux_sym_name_dot_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(136), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(132), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [11035] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(146), 1,
      sym_block_comment,
    STATE(156), 1,
      aux_sym_name_dot_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(136), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(132), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [11082] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(147), 1,
      sym_block_comment,
    STATE(248), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [11169] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(502), 1,
      anon_sym_DOT,
    STATE(148), 1,
      sym_block_comment,
    STATE(171), 1,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(168), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(166), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [11218] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(504), 1,
      anon_sym_DOT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(149), 2,
      sym_block_comment,
      aux_sym_name_dot_repeat1,
    ACTIONS(149), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(147), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [11265] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(507), 1,
      anon_sym_DOT,
    STATE(150), 1,
      sym_block_comment,
    STATE(206), 1,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(154), 20,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [11316] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(454), 1,
      anon_sym_DASH,
    ACTIONS(486), 1,
      anon_sym_LPAREN,
    ACTIONS(488), 1,
      sym_name,
    ACTIONS(509), 1,
      anon_sym_DOT,
    ACTIONS(511), 1,
      sym_digit,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(151), 1,
      sym_block_comment,
    STATE(168), 1,
      sym_name_dot,
    STATE(201), 1,
      sym_set_bag_expr,
    STATE(286), 1,
      sym_expr,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [11403] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(390), 1,
      anon_sym_DASH,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(402), 1,
      sym_name,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(486), 1,
      anon_sym_LPAREN,
    ACTIONS(509), 1,
      anon_sym_DOT,
    ACTIONS(511), 1,
      sym_digit,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(152), 1,
      sym_block_comment,
    STATE(168), 1,
      sym_name_dot,
    STATE(201), 1,
      sym_set_bag_expr,
    STATE(214), 1,
      sym_expr,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [11490] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(513), 1,
      anon_sym_LPAREN,
    STATE(153), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(149), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(147), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [11537] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(154), 1,
      sym_block_comment,
    STATE(305), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [11624] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(155), 1,
      sym_block_comment,
    STATE(307), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [11711] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(149), 1,
      aux_sym_name_dot_repeat1,
    STATE(156), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(174), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(172), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [11758] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(454), 1,
      anon_sym_DASH,
    ACTIONS(486), 1,
      anon_sym_LPAREN,
    ACTIONS(488), 1,
      sym_name,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(157), 1,
      sym_block_comment,
    STATE(168), 1,
      sym_name_dot,
    STATE(201), 1,
      sym_set_bag_expr,
    STATE(290), 1,
      sym_expr,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [11845] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    ACTIONS(515), 1,
      anon_sym_DOT,
    ACTIONS(517), 1,
      sym_digit,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(134), 1,
      sym_expr,
    STATE(158), 1,
      sym_block_comment,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [11932] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(519), 1,
      sym_name,
    STATE(159), 1,
      sym_block_comment,
    STATE(494), 1,
      sym_base_type,
    STATE(702), 1,
      sym_accum_type,
    STATE(746), 1,
      sym__element_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [12003] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(160), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(262), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(430), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
    ACTIONS(260), 17,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12050] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(161), 1,
      sym_block_comment,
    STATE(285), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12137] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(502), 1,
      anon_sym_DOT,
    STATE(148), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(162), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(162), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(160), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12186] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(163), 1,
      sym_block_comment,
    STATE(255), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12273] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(164), 1,
      sym_block_comment,
    STATE(241), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12360] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(165), 1,
      sym_block_comment,
    STATE(309), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12447] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(166), 1,
      sym_block_comment,
    STATE(239), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12534] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(422), 1,
      anon_sym_DASH,
    ACTIONS(426), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(137), 1,
      sym_expr,
    STATE(167), 1,
      sym_block_comment,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12621] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(502), 1,
      anon_sym_DOT,
    STATE(148), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(168), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(154), 20,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12672] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(169), 1,
      sym_block_comment,
    STATE(302), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12759] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(170), 1,
      sym_block_comment,
    STATE(256), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12846] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(521), 1,
      anon_sym_DOT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(171), 2,
      sym_block_comment,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(142), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(140), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12893] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(454), 1,
      anon_sym_DASH,
    ACTIONS(486), 1,
      anon_sym_LPAREN,
    ACTIONS(488), 1,
      sym_name,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(172), 1,
      sym_block_comment,
    STATE(201), 1,
      sym_set_bag_expr,
    STATE(289), 1,
      sym_expr,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [12980] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(173), 1,
      sym_block_comment,
    STATE(195), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13067] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(174), 1,
      sym_block_comment,
    STATE(292), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13154] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(175), 1,
      sym_block_comment,
    STATE(251), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13241] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(176), 1,
      sym_block_comment,
    STATE(312), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13328] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(177), 1,
      sym_block_comment,
    STATE(283), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13415] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(386), 1,
      anon_sym_DOT,
    ACTIONS(388), 1,
      anon_sym_LBRACK,
    ACTIONS(390), 1,
      anon_sym_DASH,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(394), 1,
      anon_sym_COALESCE,
    ACTIONS(396), 1,
      anon_sym_ISEMPTY,
    ACTIONS(402), 1,
      sym_name,
    ACTIONS(406), 1,
      sym_digit,
    ACTIONS(408), 1,
      anon_sym_DQUOTE,
    ACTIONS(410), 1,
      anon_sym_SQUOTE,
    ACTIONS(486), 1,
      anon_sym_LPAREN,
    STATE(150), 1,
      sym_global_accum_name,
    STATE(168), 1,
      sym_name_dot,
    STATE(178), 1,
      sym_block_comment,
    STATE(201), 1,
      sym_set_bag_expr,
    STATE(210), 1,
      sym_expr,
    STATE(642), 1,
      sym_local_accum_name,
    STATE(870), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(223), 2,
      sym__numeric,
      sym_string_literal,
    STATE(229), 2,
      sym_integer,
      sym_real,
    STATE(230), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(404), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13502] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(179), 1,
      sym_block_comment,
    STATE(308), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13589] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(180), 1,
      sym_block_comment,
    STATE(311), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13676] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(181), 1,
      sym_block_comment,
    STATE(304), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13763] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(182), 1,
      sym_block_comment,
    STATE(240), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [13850] = 18,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(519), 1,
      sym_name,
    STATE(183), 1,
      sym_block_comment,
    STATE(494), 1,
      sym_base_type,
    STATE(746), 1,
      sym__element_type,
    STATE(747), 1,
      sym_accum_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [13921] = 17,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(519), 1,
      sym_name,
    STATE(184), 1,
      sym_block_comment,
    STATE(494), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(662), 2,
      sym_accum_type,
      sym__element_type,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [13990] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(185), 1,
      sym_block_comment,
    STATE(254), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [14077] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    ACTIONS(515), 1,
      anon_sym_DOT,
    ACTIONS(517), 1,
      sym_digit,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(186), 1,
      sym_block_comment,
    STATE(193), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [14164] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(187), 1,
      sym_block_comment,
    STATE(252), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [14251] = 26,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(338), 1,
      anon_sym_LBRACK,
    ACTIONS(340), 1,
      anon_sym_DASH,
    ACTIONS(342), 1,
      anon_sym_COALESCE,
    ACTIONS(344), 1,
      anon_sym_ISEMPTY,
    ACTIONS(348), 1,
      anon_sym_COUNT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(412), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      sym_name,
    STATE(21), 1,
      sym_name_dot,
    STATE(23), 1,
      sym_global_accum_name,
    STATE(33), 1,
      sym_set_bag_expr,
    STATE(188), 1,
      sym_block_comment,
    STATE(306), 1,
      sym_expr,
    STATE(634), 1,
      sym_local_accum_name,
    STATE(753), 1,
      sym_aggregator,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    STATE(63), 2,
      sym_func_call_stmt,
      sym_constant,
    ACTIONS(346), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [14338] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(189), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(178), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(176), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14382] = 16,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(27), 1,
      anon_sym_SumAccum,
    ACTIONS(35), 1,
      anon_sym_ListAccum,
    ACTIONS(39), 1,
      anon_sym_MapAccum,
    ACTIONS(41), 1,
      anon_sym_HeapAccum,
    ACTIONS(43), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(45), 1,
      anon_sym_ArrayAccum,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(524), 1,
      sym_name,
    STATE(190), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(31), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(37), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    STATE(856), 2,
      sym_accum_type,
      sym_base_type,
    ACTIONS(33), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [14448] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(191), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(188), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(186), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14492] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(192), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(130), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(128), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14536] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(193), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
    ACTIONS(490), 19,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_AND,
      anon_sym_TO_CSV,
      anon_sym_AS,
  [14584] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(526), 1,
      anon_sym_DOT,
    STATE(194), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(162), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(160), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14630] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(312), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(195), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(310), 27,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POST_DASHACCUM,
      anon_sym_OFFSET,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_AND,
      anon_sym_TO_CSV,
      anon_sym_AS,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [14676] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(196), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(184), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(182), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14720] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(197), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(149), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(147), 24,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14764] = 19,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(434), 1,
      anon_sym_IN,
    ACTIONS(438), 1,
      anon_sym_NOT,
    ACTIONS(440), 1,
      anon_sym_IS,
    ACTIONS(442), 1,
      anon_sym_BETWEEN,
    ACTIONS(444), 1,
      anon_sym_LIKE,
    ACTIONS(468), 1,
      anon_sym_RPAREN,
    ACTIONS(528), 1,
      anon_sym_COMMA,
    ACTIONS(530), 1,
      anon_sym_DASH_GT,
    STATE(166), 1,
      sym_comparison_operator,
    STATE(178), 1,
      sym_math_operator,
    STATE(198), 1,
      sym_block_comment,
    STATE(438), 1,
      aux_sym_arg_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(430), 2,
      anon_sym_OR,
      anon_sym_AND,
    ACTIONS(432), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(446), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(448), 4,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(436), 7,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [14835] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(199), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(532), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(154), 20,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14880] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(200), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(162), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(160), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14923] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(201), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(532), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(156), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(154), 20,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [14968] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(202), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(194), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(192), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15011] = 19,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(434), 1,
      anon_sym_IN,
    ACTIONS(438), 1,
      anon_sym_NOT,
    ACTIONS(440), 1,
      anon_sym_IS,
    ACTIONS(442), 1,
      anon_sym_BETWEEN,
    ACTIONS(444), 1,
      anon_sym_LIKE,
    ACTIONS(464), 1,
      anon_sym_RPAREN,
    ACTIONS(528), 1,
      anon_sym_COMMA,
    ACTIONS(530), 1,
      anon_sym_DASH_GT,
    STATE(166), 1,
      sym_comparison_operator,
    STATE(178), 1,
      sym_math_operator,
    STATE(203), 1,
      sym_block_comment,
    STATE(438), 1,
      aux_sym_arg_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(430), 2,
      anon_sym_OR,
      anon_sym_AND,
    ACTIONS(432), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(446), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(448), 4,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(436), 7,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [15082] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(204), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(194), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_IN,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(192), 23,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15125] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(534), 1,
      sym_digit,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(205), 2,
      sym_block_comment,
      aux_sym_accum_type_repeat1,
    ACTIONS(201), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(199), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15169] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(507), 1,
      anon_sym_DOT,
    STATE(206), 1,
      sym_block_comment,
    STATE(207), 1,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(208), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(206), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15215] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(537), 1,
      anon_sym_DOT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(207), 2,
      sym_block_comment,
      aux_sym_func_call_stmt_repeat2,
    ACTIONS(142), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(140), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15259] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(540), 1,
      sym_digit,
    STATE(205), 1,
      aux_sym_accum_type_repeat1,
    STATE(208), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(213), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(210), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15305] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(540), 1,
      sym_digit,
    STATE(205), 1,
      aux_sym_accum_type_repeat1,
    STATE(209), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(220), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(218), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15351] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(178), 1,
      sym_math_operator,
    STATE(210), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(312), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(310), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15394] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(542), 1,
      anon_sym_DOT,
    STATE(211), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(248), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(246), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15437] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(544), 1,
      anon_sym_DOT,
    STATE(212), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(238), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(236), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15480] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(213), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(188), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(186), 22,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15521] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(178), 1,
      sym_math_operator,
    STATE(214), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(446), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(492), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(436), 7,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
    ACTIONS(490), 14,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15568] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(215), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(178), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(176), 22,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15609] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(546), 1,
      anon_sym_DOT,
    STATE(216), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(225), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(222), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15652] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(548), 1,
      anon_sym_DOT,
    STATE(217), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(232), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(230), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15695] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(218), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(244), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(242), 22,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      sym_digit,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15736] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(219), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(266), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(264), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15776] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(220), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(312), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(310), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15816] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(221), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(270), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(268), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15856] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(222), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(304), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(302), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15896] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(223), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(262), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(260), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15936] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(224), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(291), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(288), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [15976] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(225), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(316), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(314), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16016] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(226), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(282), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(280), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16056] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(227), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(278), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(276), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16096] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(228), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(238), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(236), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16136] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(229), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(258), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(256), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16176] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(230), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(156), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(154), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16216] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(231), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(430), 3,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_AND,
    ACTIONS(262), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(260), 18,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16258] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(232), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(254), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(252), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16298] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(233), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(286), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(284), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16338] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(234), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(320), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(318), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16378] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(235), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(300), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(298), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16418] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(236), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(296), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(294), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16458] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(237), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(308), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(306), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16498] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(238), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(274), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(272), 21,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_IN,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_NOT,
      anon_sym_IS,
      anon_sym_BETWEEN,
      anon_sym_AND,
      anon_sym_LIKE,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [16538] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(239), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
    ACTIONS(550), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [16577] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(240), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
    ACTIONS(552), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [16616] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(241), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
    ACTIONS(554), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [16655] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(494), 1,
      anon_sym_LPAREN,
    ACTIONS(496), 1,
      anon_sym_DOT,
    ACTIONS(556), 1,
      anon_sym_LT,
    STATE(206), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(242), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(156), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(558), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(154), 10,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [16699] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(494), 1,
      anon_sym_LPAREN,
    ACTIONS(496), 1,
      anon_sym_DOT,
    ACTIONS(556), 1,
      anon_sym_LT,
    STATE(206), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(243), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(156), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(160), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(154), 10,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [16743] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(244), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(560), 8,
      anon_sym_LPAREN,
      anon_sym_DOT,
      anon_sym_LBRACK,
      anon_sym_DASH,
      anon_sym_AT_AT,
      sym_digit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(562), 10,
      anon_sym_AT,
      anon_sym_COALESCE,
      anon_sym_ISEMPTY,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_COUNT,
      sym_name,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [16776] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(245), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(564), 8,
      anon_sym_LPAREN,
      anon_sym_DOT,
      anon_sym_LBRACK,
      anon_sym_DASH,
      anon_sym_AT_AT,
      sym_digit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(566), 10,
      anon_sym_AT,
      anon_sym_COALESCE,
      anon_sym_ISEMPTY,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_COUNT,
      sym_name,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [16809] = 11,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(568), 1,
      anon_sym_RPAREN,
    ACTIONS(570), 1,
      anon_sym_SET,
    ACTIONS(574), 1,
      anon_sym_VERTEX,
    STATE(246), 1,
      sym_block_comment,
    STATE(500), 1,
      sym_query_param,
    STATE(502), 1,
      sym_base_type,
    STATE(769), 1,
      sym_query_params,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(767), 2,
      sym_set_param,
      sym__type,
    ACTIONS(572), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [16854] = 11,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(156), 1,
      anon_sym_SLASH,
    ACTIONS(366), 1,
      anon_sym_LPAREN,
    ACTIONS(368), 1,
      anon_sym_DOT,
    ACTIONS(370), 1,
      anon_sym_LT,
    ACTIONS(576), 1,
      anon_sym_EQ,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(247), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(558), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(154), 9,
      anon_sym_SEMI,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [16899] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(248), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(578), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [16935] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(580), 1,
      anon_sym_GT,
    ACTIONS(585), 1,
      anon_sym_VERTEX,
    ACTIONS(588), 1,
      sym_name,
    STATE(266), 1,
      sym_tuple_field,
    STATE(284), 1,
      sym_tuple_fields,
    STATE(766), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(249), 2,
      sym_block_comment,
      aux_sym_typedef_repeat1,
    ACTIONS(582), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [16977] = 11,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(591), 1,
      anon_sym_GT,
    ACTIONS(593), 1,
      sym_name,
    STATE(249), 1,
      aux_sym_typedef_repeat1,
    STATE(250), 1,
      sym_block_comment,
    STATE(266), 1,
      sym_tuple_field,
    STATE(284), 1,
      sym_tuple_fields,
    STATE(766), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [17021] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(251), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(595), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17057] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(252), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(597), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17093] = 11,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(593), 1,
      sym_name,
    ACTIONS(599), 1,
      anon_sym_GT,
    STATE(250), 1,
      aux_sym_typedef_repeat1,
    STATE(253), 1,
      sym_block_comment,
    STATE(266), 1,
      sym_tuple_field,
    STATE(284), 1,
      sym_tuple_fields,
    STATE(766), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [17137] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(254), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(601), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17173] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(255), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(603), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17209] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(256), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(605), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17245] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(609), 1,
      anon_sym_LBRACK,
    ACTIONS(611), 1,
      anon_sym_AS,
    STATE(173), 1,
      sym_math_operator,
    STATE(257), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(607), 4,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_TO_CSV,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17284] = 13,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(613), 1,
      anon_sym_SumAccum,
    ACTIONS(619), 1,
      anon_sym_ListAccum,
    ACTIONS(623), 1,
      anon_sym_MapAccum,
    ACTIONS(625), 1,
      anon_sym_HeapAccum,
    ACTIONS(627), 1,
      anon_sym_GroupbyAccum,
    ACTIONS(629), 1,
      anon_sym_ArrayAccum,
    STATE(258), 1,
      sym_block_comment,
    STATE(660), 1,
      sym_accum_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(615), 2,
      anon_sym_MaxAccum,
      anon_sym_MinAccum,
    ACTIONS(621), 2,
      anon_sym_SetAccum,
      anon_sym_BagAccum,
    ACTIONS(617), 5,
      anon_sym_AvgAccum,
      anon_sym_OrAccum,
      anon_sym_AndAccum,
      anon_sym_BitwiseorAccum,
      anon_sym_BitwiseandAccum,
  [17331] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(570), 1,
      anon_sym_SET,
    ACTIONS(574), 1,
      anon_sym_VERTEX,
    STATE(259), 1,
      sym_block_comment,
    STATE(502), 1,
      sym_base_type,
    STATE(617), 1,
      sym_query_param,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(767), 2,
      sym_set_param,
      sym__type,
    ACTIONS(572), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [17370] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(631), 1,
      anon_sym_DASH,
    STATE(260), 1,
      sym_block_comment,
    STATE(602), 1,
      sym_constant,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    ACTIONS(633), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [17414] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(635), 1,
      anon_sym_COMMA,
    ACTIONS(638), 1,
      anon_sym_GT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(261), 2,
      sym_block_comment,
      aux_sym_tuple_fields_repeat1,
    ACTIONS(640), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [17446] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(631), 1,
      anon_sym_DASH,
    STATE(262), 1,
      sym_block_comment,
    STATE(805), 1,
      sym_constant,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    ACTIONS(633), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [17490] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(644), 1,
      anon_sym_LT,
    STATE(263), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(642), 2,
      anon_sym_COMMA,
      anon_sym_GT,
    ACTIONS(646), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [17522] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(648), 1,
      anon_sym_COMMA,
    ACTIONS(650), 1,
      anon_sym_GT,
    STATE(261), 1,
      aux_sym_tuple_fields_repeat1,
    STATE(264), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(652), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [17556] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(631), 1,
      anon_sym_DASH,
    STATE(265), 1,
      sym_block_comment,
    STATE(523), 1,
      sym_constant,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
    STATE(51), 2,
      sym__numeric,
      sym_string_literal,
    ACTIONS(633), 5,
      anon_sym_TRUE,
      anon_sym_FALSE,
      anon_sym_GSQL_UINT_MAX,
      anon_sym_GSQL_INT_MAX,
      anon_sym_GSQL_UINT_MIN,
  [17600] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(648), 1,
      anon_sym_COMMA,
    ACTIONS(654), 1,
      anon_sym_GT,
    STATE(264), 1,
      aux_sym_tuple_fields_repeat1,
    STATE(266), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(656), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [17634] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(519), 1,
      sym_name,
    STATE(267), 1,
      sym_block_comment,
    STATE(494), 1,
      sym_base_type,
    STATE(662), 1,
      sym__element_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [17669] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(658), 1,
      anon_sym_COMMA,
    STATE(173), 1,
      sym_math_operator,
    STATE(268), 1,
      sym_block_comment,
    STATE(471), 1,
      aux_sym_arg_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(530), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17706] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(519), 1,
      sym_name,
    STATE(269), 1,
      sym_block_comment,
    STATE(494), 1,
      sym_base_type,
    STATE(661), 1,
      sym__element_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [17741] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(270), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(642), 2,
      anon_sym_COMMA,
      anon_sym_GT,
    ACTIONS(646), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [17770] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(468), 1,
      anon_sym_RPAREN,
    ACTIONS(528), 1,
      anon_sym_COMMA,
    ACTIONS(530), 1,
      anon_sym_DASH_GT,
    STATE(172), 1,
      sym_math_operator,
    STATE(271), 1,
      sym_block_comment,
    STATE(438), 1,
      aux_sym_arg_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(446), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(436), 7,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17809] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(464), 1,
      anon_sym_RPAREN,
    ACTIONS(528), 1,
      anon_sym_COMMA,
    ACTIONS(530), 1,
      anon_sym_DASH_GT,
    STATE(172), 1,
      sym_math_operator,
    STATE(272), 1,
      sym_block_comment,
    STATE(438), 1,
      aux_sym_arg_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(446), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(436), 7,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17848] = 16,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(660), 1,
      anon_sym_LPAREN,
    ACTIONS(662), 1,
      anon_sym_LT,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(668), 1,
      sym_name,
    STATE(273), 1,
      sym_block_comment,
    STATE(409), 1,
      sym_edge_set_type,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(413), 1,
      sym_atomic_edge_pattern,
    STATE(415), 1,
      sym_atomic_edge_type,
    STATE(530), 1,
      sym_path_edge_pattern,
    STATE(532), 1,
      sym_disj_pattern,
    STATE(581), 1,
      sym_step_edge_types,
    STATE(663), 1,
      sym_step_edge_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym__,
      anon_sym_ANY,
  [17899] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(274), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(638), 2,
      anon_sym_COMMA,
      anon_sym_GT,
    ACTIONS(640), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [17928] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(156), 1,
      anon_sym_SLASH,
    STATE(275), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(154), 10,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [17959] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(519), 1,
      sym_name,
    STATE(276), 1,
      sym_block_comment,
    STATE(494), 1,
      sym_base_type,
    STATE(746), 1,
      sym__element_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [17994] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(519), 1,
      sym_name,
    STATE(277), 1,
      sym_block_comment,
    STATE(494), 1,
      sym_base_type,
    STATE(647), 1,
      sym__element_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [18029] = 15,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(670), 1,
      anon_sym_LPAREN,
    ACTIONS(674), 1,
      sym_name,
    STATE(278), 1,
      sym_block_comment,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(328), 1,
      sym_step_source_set,
    STATE(339), 1,
      sym_atomic_vertex_type,
    STATE(341), 1,
      sym_step_vertex_types,
    STATE(344), 1,
      sym_vertex_set_type,
    STATE(371), 1,
      sym_path_pattern,
    STATE(380), 1,
      sym_step_vertex_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(672), 2,
      anon_sym__,
      anon_sym_ANY,
    STATE(423), 2,
      sym_step,
      sym_step_v2,
  [18078] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(279), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(676), 2,
      anon_sym_COMMA,
      anon_sym_GT,
    ACTIONS(678), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [18107] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(280), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(680), 2,
      anon_sym_COMMA,
      anon_sym_GT,
    ACTIONS(682), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [18136] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(53), 1,
      anon_sym_VERTEX,
    ACTIONS(593), 1,
      sym_name,
    STATE(274), 1,
      sym_tuple_field,
    STATE(281), 1,
      sym_block_comment,
    STATE(766), 1,
      sym_base_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(29), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [18171] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(282), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(550), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [18199] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(283), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(684), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18231] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(686), 1,
      anon_sym_GT,
    STATE(284), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(688), 12,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_VERTEX,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
      sym_name,
  [18259] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(690), 1,
      anon_sym_COMMA,
    ACTIONS(692), 1,
      anon_sym_SEMI,
    STATE(173), 1,
      sym_math_operator,
    STATE(285), 1,
      sym_block_comment,
    STATE(489), 1,
      aux_sym_base_decl_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18295] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(172), 1,
      sym_math_operator,
    STATE(286), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(446), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(490), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
    ACTIONS(436), 7,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18327] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(696), 1,
      anon_sym_AS,
    STATE(173), 1,
      sym_math_operator,
    STATE(287), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(694), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18361] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(574), 1,
      anon_sym_VERTEX,
    STATE(288), 1,
      sym_block_comment,
    STATE(502), 1,
      sym_base_type,
    STATE(591), 1,
      sym__type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(572), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [18393] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(172), 1,
      sym_math_operator,
    STATE(289), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(312), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(310), 10,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_DASH_GT,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18423] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(172), 1,
      sym_math_operator,
    STATE(290), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(446), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(684), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
    ACTIONS(436), 7,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18455] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(574), 1,
      anon_sym_VERTEX,
    STATE(291), 1,
      sym_block_comment,
    STATE(502), 1,
      sym_base_type,
    STATE(539), 1,
      sym__type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(572), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [18487] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(700), 1,
      anon_sym_SEMI,
    STATE(173), 1,
      sym_math_operator,
    STATE(292), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(698), 2,
      anon_sym_COMMA,
      anon_sym_OFFSET,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18521] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(574), 1,
      anon_sym_VERTEX,
    STATE(293), 1,
      sym_block_comment,
    STATE(502), 1,
      sym_base_type,
    STATE(516), 1,
      sym__type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(572), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [18553] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(574), 1,
      anon_sym_VERTEX,
    STATE(294), 1,
      sym_block_comment,
    STATE(502), 1,
      sym_base_type,
    STATE(738), 1,
      sym__type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(572), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [18585] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(295), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
    ACTIONS(554), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [18613] = 14,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(662), 1,
      anon_sym_LT,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(668), 1,
      sym_name,
    ACTIONS(702), 1,
      anon_sym_LPAREN,
    STATE(296), 1,
      sym_block_comment,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(413), 1,
      sym_atomic_edge_pattern,
    STATE(424), 1,
      sym_edge_set_type,
    STATE(425), 1,
      sym_atomic_edge_type,
    STATE(532), 1,
      sym_disj_pattern,
    STATE(586), 1,
      sym_path_edge_pattern,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym__,
      anon_sym_ANY,
  [18658] = 14,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(662), 1,
      anon_sym_LT,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(668), 1,
      sym_name,
    ACTIONS(702), 1,
      anon_sym_LPAREN,
    STATE(297), 1,
      sym_block_comment,
    STATE(409), 1,
      sym_edge_set_type,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(413), 1,
      sym_atomic_edge_pattern,
    STATE(425), 1,
      sym_atomic_edge_type,
    STATE(499), 1,
      sym_path_edge_pattern,
    STATE(532), 1,
      sym_disj_pattern,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym__,
      anon_sym_ANY,
  [18703] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(706), 1,
      anon_sym_VERTEX,
    STATE(279), 1,
      sym_base_type,
    STATE(298), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(704), 10,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
      anon_sym_BOOL,
      anon_sym_UINT,
      anon_sym_EDGE,
      anon_sym_JSONOBJECT,
      anon_sym_JSONARRAY,
      anon_sym_DATETIME,
  [18732] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(299), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(182), 12,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_PLUS_EQ,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_IN,
      anon_sym_COLON,
      anon_sym_POST_DASHACCUM,
  [18757] = 14,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(662), 1,
      anon_sym_LT,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(668), 1,
      sym_name,
    ACTIONS(702), 1,
      anon_sym_LPAREN,
    STATE(300), 1,
      sym_block_comment,
    STATE(409), 1,
      sym_edge_set_type,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(413), 1,
      sym_atomic_edge_pattern,
    STATE(425), 1,
      sym_atomic_edge_type,
    STATE(532), 1,
      sym_disj_pattern,
    STATE(586), 1,
      sym_path_edge_pattern,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym__,
      anon_sym_ANY,
  [18802] = 14,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(662), 1,
      anon_sym_LT,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(668), 1,
      sym_name,
    ACTIONS(702), 1,
      anon_sym_LPAREN,
    STATE(301), 1,
      sym_block_comment,
    STATE(409), 1,
      sym_edge_set_type,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(413), 1,
      sym_atomic_edge_pattern,
    STATE(425), 1,
      sym_atomic_edge_type,
    STATE(530), 1,
      sym_path_edge_pattern,
    STATE(532), 1,
      sym_disj_pattern,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym__,
      anon_sym_ANY,
  [18847] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    STATE(173), 1,
      sym_math_operator,
    STATE(302), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(708), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18878] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(710), 1,
      anon_sym_WHEN,
    STATE(173), 1,
      sym_math_operator,
    STATE(303), 1,
      sym_block_comment,
    STATE(453), 1,
      aux_sym_query_body_case_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18911] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(712), 1,
      anon_sym_SEMI,
    STATE(173), 1,
      sym_math_operator,
    STATE(304), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18941] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(714), 1,
      anon_sym_SEMI,
    STATE(173), 1,
      sym_math_operator,
    STATE(305), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [18971] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(716), 1,
      anon_sym_COMMA,
    STATE(173), 1,
      sym_math_operator,
    STATE(306), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [19001] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(718), 1,
      anon_sym_RPAREN,
    STATE(173), 1,
      sym_math_operator,
    STATE(307), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [19031] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(712), 1,
      anon_sym_SEMI,
    STATE(173), 1,
      sym_math_operator,
    STATE(308), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [19061] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(720), 1,
      anon_sym_AND,
    STATE(173), 1,
      sym_math_operator,
    STATE(309), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [19091] = 13,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(670), 1,
      anon_sym_LPAREN,
    ACTIONS(722), 1,
      anon_sym_GT,
    ACTIONS(724), 1,
      sym_name,
    STATE(310), 1,
      sym_block_comment,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(339), 1,
      sym_atomic_vertex_type,
    STATE(341), 1,
      sym_step_vertex_types,
    STATE(344), 1,
      sym_vertex_set_type,
    STATE(392), 1,
      sym_step_vertex_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(672), 2,
      anon_sym__,
      anon_sym_ANY,
  [19133] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(726), 1,
      anon_sym_RBRACK,
    STATE(173), 1,
      sym_math_operator,
    STATE(311), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [19163] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(446), 1,
      anon_sym_SLASH,
    ACTIONS(728), 1,
      anon_sym_SEMI,
    STATE(173), 1,
      sym_math_operator,
    STATE(312), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(436), 8,
      anon_sym_DASH,
      anon_sym_PIPE2,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP,
  [19193] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(670), 1,
      anon_sym_LPAREN,
    ACTIONS(724), 1,
      sym_name,
    STATE(313), 1,
      sym_block_comment,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(339), 1,
      sym_atomic_vertex_type,
    STATE(341), 1,
      sym_step_vertex_types,
    STATE(344), 1,
      sym_vertex_set_type,
    STATE(398), 1,
      sym_step_vertex_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(672), 2,
      anon_sym__,
      anon_sym_ANY,
  [19232] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(314), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(550), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [19255] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(730), 1,
      anon_sym_LPAREN,
    ACTIONS(734), 1,
      sym_name,
    STATE(315), 1,
      sym_block_comment,
    STATE(581), 1,
      sym_step_edge_types,
    STATE(606), 1,
      sym_atomic_edge_type,
    STATE(632), 1,
      sym_edge_set_type,
    STATE(633), 1,
      sym_global_accum_name,
    STATE(731), 1,
      sym_step_edge_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(732), 2,
      anon_sym__,
      anon_sym_ANY,
  [19294] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(316), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(736), 10,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_COLON,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
      anon_sym_PIPE2,
  [19317] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(670), 1,
      anon_sym_LPAREN,
    ACTIONS(724), 1,
      sym_name,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(317), 1,
      sym_block_comment,
    STATE(339), 1,
      sym_atomic_vertex_type,
    STATE(341), 1,
      sym_step_vertex_types,
    STATE(344), 1,
      sym_vertex_set_type,
    STATE(347), 1,
      sym_step_vertex_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(672), 2,
      anon_sym__,
      anon_sym_ANY,
  [19356] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(318), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(550), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [19379] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(740), 1,
      anon_sym_DOT,
    ACTIONS(742), 1,
      anon_sym_PLUS_EQ,
    STATE(319), 1,
      sym_block_comment,
    STATE(326), 1,
      aux_sym_v_accum_func_call_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(738), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19408] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(670), 1,
      anon_sym_LPAREN,
    ACTIONS(724), 1,
      sym_name,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(320), 1,
      sym_block_comment,
    STATE(339), 1,
      sym_atomic_vertex_type,
    STATE(341), 1,
      sym_step_vertex_types,
    STATE(344), 1,
      sym_vertex_set_type,
    STATE(414), 1,
      sym_step_vertex_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(672), 2,
      anon_sym__,
      anon_sym_ANY,
  [19447] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(670), 1,
      anon_sym_LPAREN,
    ACTIONS(724), 1,
      sym_name,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(321), 1,
      sym_block_comment,
    STATE(339), 1,
      sym_atomic_vertex_type,
    STATE(341), 1,
      sym_step_vertex_types,
    STATE(344), 1,
      sym_vertex_set_type,
    STATE(348), 1,
      sym_step_vertex_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(672), 2,
      anon_sym__,
      anon_sym_ANY,
  [19486] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(322), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(554), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [19509] = 12,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(730), 1,
      anon_sym_LPAREN,
    ACTIONS(734), 1,
      sym_name,
    STATE(323), 1,
      sym_block_comment,
    STATE(581), 1,
      sym_step_edge_types,
    STATE(606), 1,
      sym_atomic_edge_type,
    STATE(632), 1,
      sym_edge_set_type,
    STATE(633), 1,
      sym_global_accum_name,
    STATE(663), 1,
      sym_step_edge_set,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(732), 2,
      anon_sym__,
      anon_sym_ANY,
  [19548] = 13,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(744), 1,
      anon_sym_SEMI,
    ACTIONS(746), 1,
      anon_sym_WHERE,
    ACTIONS(748), 1,
      anon_sym_ACCUM,
    ACTIONS(750), 1,
      anon_sym_LIMIT,
    ACTIONS(752), 1,
      anon_sym_POST_DASHACCUM,
    STATE(324), 1,
      sym_block_comment,
    STATE(338), 1,
      sym_where_clause,
    STATE(376), 1,
      sym_accum_clause,
    STATE(377), 1,
      aux_sym_gsql_select_block_repeat1,
    STATE(555), 1,
      sym_post_accum_clause,
    STATE(725), 1,
      sym_limit_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [19589] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(325), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(754), 10,
      anon_sym_OR,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_THEN,
      anon_sym_LIMIT,
      anon_sym_DO,
      anon_sym_POST_DASHACCUM,
      anon_sym_AND,
      anon_sym_TO_CSV,
  [19612] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(740), 1,
      anon_sym_DOT,
    STATE(326), 1,
      sym_block_comment,
    STATE(329), 1,
      aux_sym_v_accum_func_call_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(756), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19638] = 11,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(662), 1,
      anon_sym_LT,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(668), 1,
      sym_name,
    STATE(327), 1,
      sym_block_comment,
    STATE(409), 1,
      sym_edge_set_type,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(425), 1,
      sym_atomic_edge_type,
    STATE(461), 1,
      sym_atomic_edge_pattern,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym__,
      anon_sym_ANY,
  [19674] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(760), 1,
      anon_sym_DASH,
    STATE(328), 1,
      sym_block_comment,
    STATE(343), 1,
      aux_sym_path_pattern_repeat1,
    STATE(370), 1,
      aux_sym_step_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(758), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19702] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(764), 1,
      anon_sym_DOT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(329), 2,
      sym_block_comment,
      aux_sym_v_accum_func_call_repeat1,
    ACTIONS(762), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19726] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(330), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(767), 8,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_COLON,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [19747] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(331), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(769), 8,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19768] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(773), 1,
      anon_sym_DASH,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(332), 2,
      sym_block_comment,
      aux_sym_path_pattern_repeat1,
    ACTIONS(771), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19791] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(776), 1,
      anon_sym_DASH,
    STATE(333), 1,
      sym_block_comment,
    STATE(343), 1,
      aux_sym_path_pattern_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(758), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19816] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(780), 1,
      anon_sym_COLON,
    STATE(334), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(778), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [19839] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(782), 1,
      anon_sym_COMMA,
    STATE(335), 1,
      sym_block_comment,
    STATE(337), 1,
      aux_sym_dml_sub_stmt_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(784), 6,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19864] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(336), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(786), 8,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_COLON,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [19885] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(788), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(337), 2,
      sym_block_comment,
      aux_sym_dml_sub_stmt_list_repeat1,
    ACTIONS(791), 6,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19908] = 11,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(748), 1,
      anon_sym_ACCUM,
    ACTIONS(750), 1,
      anon_sym_LIMIT,
    ACTIONS(752), 1,
      anon_sym_POST_DASHACCUM,
    ACTIONS(793), 1,
      anon_sym_SEMI,
    STATE(338), 1,
      sym_block_comment,
    STATE(375), 1,
      aux_sym_gsql_select_block_repeat1,
    STATE(396), 1,
      sym_accum_clause,
    STATE(555), 1,
      sym_post_accum_clause,
    STATE(681), 1,
      sym_limit_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [19943] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(339), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(795), 8,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_COLON,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [19964] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(340), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(797), 8,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_DOT,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [19985] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(801), 1,
      anon_sym_COLON,
    STATE(341), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(799), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [20008] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(780), 1,
      anon_sym_COLON,
    STATE(342), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(778), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [20031] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(776), 1,
      anon_sym_DASH,
    STATE(332), 1,
      aux_sym_path_pattern_repeat1,
    STATE(343), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(803), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20056] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(344), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(805), 8,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_COLON,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [20077] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(782), 1,
      anon_sym_COMMA,
    STATE(335), 1,
      aux_sym_dml_sub_stmt_list_repeat1,
    STATE(345), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(807), 6,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20102] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(346), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(809), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20122] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(347), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(811), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [20142] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(348), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(813), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [20162] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym_DISTINCT,
    ACTIONS(819), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(349), 1,
      sym_block_comment,
    STATE(447), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20194] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(821), 1,
      anon_sym_LPAREN,
    ACTIONS(823), 1,
      anon_sym_AT_AT,
    ACTIONS(825), 1,
      sym_name,
    STATE(350), 1,
      sym_block_comment,
    STATE(811), 1,
      sym_for_each_control,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(625), 2,
      sym_global_accum_name,
      sym_local_accum_name,
  [20224] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(351), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(827), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20244] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(352), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(829), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20264] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(353), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(831), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20284] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(835), 1,
      anon_sym_DASH,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(354), 2,
      sym_block_comment,
      aux_sym_step_repeat1,
    ACTIONS(833), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20306] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(355), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(838), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [20326] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(819), 1,
      sym_name,
    ACTIONS(840), 1,
      anon_sym_DISTINCT,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(356), 1,
      sym_block_comment,
    STATE(465), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20358] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(842), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(357), 2,
      sym_block_comment,
      aux_sym_from_clause_repeat1,
    ACTIONS(845), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20380] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(358), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(847), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20400] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(11), 1,
      anon_sym_CREATE,
    ACTIONS(13), 1,
      anon_sym_INTERPRET,
    ACTIONS(849), 1,
      ts_builtin_sym_end,
    STATE(359), 1,
      sym_block_comment,
    STATE(363), 1,
      aux_sym_gsql_repeat1,
    STATE(524), 1,
      sym__definition,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(601), 2,
      sym_create_query,
      sym_interpret_query,
  [20430] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(360), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(851), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [20450] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(49), 1,
      anon_sym_AT,
    ACTIONS(821), 1,
      anon_sym_LPAREN,
    ACTIONS(823), 1,
      anon_sym_AT_AT,
    ACTIONS(825), 1,
      sym_name,
    STATE(361), 1,
      sym_block_comment,
    STATE(748), 1,
      sym_for_each_control,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(625), 2,
      sym_global_accum_name,
      sym_local_accum_name,
  [20480] = 10,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(819), 1,
      sym_name,
    ACTIONS(853), 1,
      anon_sym_RANGE,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(362), 1,
      sym_block_comment,
    STATE(432), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20512] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(855), 1,
      ts_builtin_sym_end,
    ACTIONS(857), 1,
      anon_sym_CREATE,
    ACTIONS(860), 1,
      anon_sym_INTERPRET,
    STATE(524), 1,
      sym__definition,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(363), 2,
      sym_block_comment,
      aux_sym_gsql_repeat1,
    STATE(601), 2,
      sym_create_query,
      sym_interpret_query,
  [20540] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(364), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(863), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20560] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(668), 1,
      sym_name,
    STATE(365), 1,
      sym_block_comment,
    STATE(409), 1,
      sym_edge_set_type,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(430), 1,
      sym_atomic_edge_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym__,
      anon_sym_ANY,
  [20590] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(366), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(865), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20610] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(367), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(867), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20630] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(869), 1,
      anon_sym_RBRACE,
    ACTIONS(873), 1,
      sym_name,
    STATE(368), 1,
      sym_block_comment,
    STATE(564), 1,
      sym_seed,
    STATE(592), 1,
      sym_global_accum_name,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(871), 2,
      anon_sym__,
      anon_sym_ANY,
  [20660] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(369), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(875), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20680] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(879), 1,
      anon_sym_DASH,
    STATE(354), 1,
      aux_sym_step_repeat1,
    STATE(370), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(877), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20704] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(881), 1,
      anon_sym_COMMA,
    STATE(371), 1,
      sym_block_comment,
    STATE(374), 1,
      aux_sym_from_clause_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(883), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20728] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(372), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(791), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20748] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(373), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(885), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20768] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(881), 1,
      anon_sym_COMMA,
    STATE(357), 1,
      aux_sym_from_clause_repeat1,
    STATE(374), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(887), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20792] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(750), 1,
      anon_sym_LIMIT,
    ACTIONS(752), 1,
      anon_sym_POST_DASHACCUM,
    ACTIONS(889), 1,
      anon_sym_SEMI,
    STATE(375), 1,
      sym_block_comment,
    STATE(416), 1,
      aux_sym_gsql_select_block_repeat1,
    STATE(555), 1,
      sym_post_accum_clause,
    STATE(802), 1,
      sym_limit_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20821] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(750), 1,
      anon_sym_LIMIT,
    ACTIONS(752), 1,
      anon_sym_POST_DASHACCUM,
    ACTIONS(793), 1,
      anon_sym_SEMI,
    STATE(375), 1,
      aux_sym_gsql_select_block_repeat1,
    STATE(376), 1,
      sym_block_comment,
    STATE(555), 1,
      sym_post_accum_clause,
    STATE(681), 1,
      sym_limit_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20850] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(750), 1,
      anon_sym_LIMIT,
    ACTIONS(752), 1,
      anon_sym_POST_DASHACCUM,
    ACTIONS(793), 1,
      anon_sym_SEMI,
    STATE(377), 1,
      sym_block_comment,
    STATE(416), 1,
      aux_sym_gsql_select_block_repeat1,
    STATE(555), 1,
      sym_post_accum_clause,
    STATE(681), 1,
      sym_limit_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20879] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(378), 1,
      sym_block_comment,
    STATE(465), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20908] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(379), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
    ACTIONS(895), 4,
      anon_sym_SEMI,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20929] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(899), 1,
      anon_sym_DASH,
    STATE(380), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(897), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [20950] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(381), 1,
      sym_block_comment,
    STATE(442), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [20979] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(392), 1,
      anon_sym_AT_AT,
    ACTIONS(901), 1,
      anon_sym_LPAREN,
    ACTIONS(903), 1,
      sym_name,
    STATE(162), 1,
      sym_name_dot,
    STATE(200), 1,
      sym_global_accum_name,
    STATE(202), 1,
      sym_set_bag_expr,
    STATE(382), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21008] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(383), 1,
      sym_block_comment,
    STATE(435), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21037] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(384), 1,
      sym_block_comment,
    STATE(436), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21066] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    STATE(38), 1,
      aux_sym_accum_type_repeat1,
    STATE(385), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(272), 4,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_THEN,
  [21089] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(334), 1,
      anon_sym_DOT,
    ACTIONS(352), 1,
      sym_digit,
    ACTIONS(631), 1,
      anon_sym_DASH,
    STATE(386), 1,
      sym_block_comment,
    STATE(585), 1,
      sym__numeric,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(50), 2,
      sym_integer,
      sym_real,
  [21116] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(295), 1,
      sym_set_bag_expr,
    STATE(387), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21145] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(388), 1,
      sym_block_comment,
    STATE(464), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21174] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(750), 1,
      anon_sym_LIMIT,
    ACTIONS(752), 1,
      anon_sym_POST_DASHACCUM,
    ACTIONS(905), 1,
      anon_sym_SEMI,
    STATE(389), 1,
      sym_block_comment,
    STATE(416), 1,
      aux_sym_gsql_select_block_repeat1,
    STATE(555), 1,
      sym_post_accum_clause,
    STATE(723), 1,
      sym_limit_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21203] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(873), 1,
      sym_name,
    STATE(390), 1,
      sym_block_comment,
    STATE(592), 1,
      sym_global_accum_name,
    STATE(620), 1,
      sym_seed,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(871), 2,
      anon_sym__,
      anon_sym_ANY,
  [21230] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(391), 1,
      sym_block_comment,
    STATE(432), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21259] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(392), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(907), 6,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [21278] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(393), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(845), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [21297] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(394), 1,
      sym_block_comment,
    STATE(447), 1,
      sym_set_bag_expr,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21326] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(282), 1,
      sym_set_bag_expr,
    STATE(395), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21355] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(750), 1,
      anon_sym_LIMIT,
    ACTIONS(752), 1,
      anon_sym_POST_DASHACCUM,
    ACTIONS(889), 1,
      anon_sym_SEMI,
    STATE(389), 1,
      aux_sym_gsql_select_block_repeat1,
    STATE(396), 1,
      sym_block_comment,
    STATE(555), 1,
      sym_post_accum_clause,
    STATE(802), 1,
      sym_limit_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21384] = 9,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      sym_name,
    STATE(22), 1,
      sym_name_dot,
    STATE(35), 1,
      sym_global_accum_name,
    STATE(36), 1,
      sym_set_bag_expr,
    STATE(397), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21413] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(398), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(909), 6,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
      anon_sym_DASH,
  [21432] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(911), 1,
      anon_sym_COMMA,
    ACTIONS(913), 1,
      anon_sym_SEMI,
    ACTIONS(915), 1,
      anon_sym_WHERE,
    ACTIONS(917), 1,
      anon_sym_TO_CSV,
    STATE(399), 1,
      sym_block_comment,
    STATE(412), 1,
      aux_sym_print_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21458] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(400), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(919), 5,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_TO_CSV,
      anon_sym_AS,
  [21476] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(401), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(921), 5,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_TO_CSV,
      anon_sym_AS,
  [21494] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(366), 1,
      anon_sym_LPAREN,
    ACTIONS(923), 1,
      anon_sym_EQ,
    ACTIONS(925), 1,
      anon_sym_LT,
    ACTIONS(927), 1,
      anon_sym_DOT,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(402), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21520] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(929), 1,
      sym_name,
    STATE(403), 1,
      sym_block_comment,
    STATE(768), 1,
      sym_string_literal,
    STATE(797), 1,
      sym_file_path,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21546] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(931), 1,
      sym_name,
    STATE(404), 1,
      sym_block_comment,
    STATE(699), 1,
      sym_file_path,
    STATE(768), 1,
      sym_string_literal,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21572] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(611), 1,
      anon_sym_AS,
    STATE(405), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(607), 4,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_TO_CSV,
  [21592] = 6,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(935), 1,
      anon_sym_PIPE,
    STATE(406), 2,
      sym_block_comment,
      aux_sym_disj_pattern_repeat1,
    ACTIONS(933), 3,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
  [21614] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(938), 1,
      sym_name,
    STATE(407), 1,
      sym_block_comment,
    STATE(768), 1,
      sym_string_literal,
    STATE(840), 1,
      sym_file_path,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21640] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(940), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(408), 2,
      sym_block_comment,
      aux_sym_print_stmt_repeat1,
    ACTIONS(943), 3,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_TO_CSV,
  [21660] = 5,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(409), 1,
      sym_block_comment,
    ACTIONS(945), 5,
      anon_sym_RPAREN,
      anon_sym_GT,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_PIPE,
  [21680] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(949), 1,
      anon_sym_DOT,
    STATE(410), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(947), 4,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_THEN,
  [21700] = 5,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(411), 1,
      sym_block_comment,
    ACTIONS(951), 5,
      anon_sym_RPAREN,
      anon_sym_GT,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_PIPE,
  [21720] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(911), 1,
      anon_sym_COMMA,
    ACTIONS(953), 1,
      anon_sym_SEMI,
    ACTIONS(955), 1,
      anon_sym_WHERE,
    ACTIONS(957), 1,
      anon_sym_TO_CSV,
    STATE(408), 1,
      aux_sym_print_stmt_repeat1,
    STATE(412), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21746] = 7,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(961), 1,
      anon_sym_PIPE,
    STATE(413), 1,
      sym_block_comment,
    STATE(420), 1,
      aux_sym_disj_pattern_repeat1,
    ACTIONS(959), 3,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
  [21770] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(414), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(963), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [21788] = 7,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(967), 1,
      anon_sym_GT,
    STATE(415), 1,
      sym_block_comment,
    ACTIONS(965), 2,
      anon_sym_RPAREN,
      anon_sym_COLON,
    ACTIONS(969), 2,
      anon_sym_DOT,
      anon_sym_PIPE,
  [21812] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(973), 1,
      anon_sym_POST_DASHACCUM,
    STATE(555), 1,
      sym_post_accum_clause,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(971), 2,
      anon_sym_SEMI,
      anon_sym_LIMIT,
    STATE(416), 2,
      sym_block_comment,
      aux_sym_gsql_select_block_repeat1,
  [21834] = 5,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(417), 1,
      sym_block_comment,
    ACTIONS(128), 5,
      anon_sym_RPAREN,
      anon_sym_GT,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_PIPE,
  [21854] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(418), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(976), 5,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [21872] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(366), 1,
      anon_sym_LPAREN,
    ACTIONS(925), 1,
      anon_sym_LT,
    ACTIONS(978), 1,
      anon_sym_EQ,
    ACTIONS(980), 1,
      anon_sym_DOT,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(419), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21898] = 7,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(961), 1,
      anon_sym_PIPE,
    STATE(406), 1,
      aux_sym_disj_pattern_repeat1,
    STATE(420), 1,
      sym_block_comment,
    ACTIONS(982), 3,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
  [21922] = 8,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_SQUOTE,
    ACTIONS(984), 1,
      sym_name,
    STATE(421), 1,
      sym_block_comment,
    STATE(742), 1,
      sym_file_path,
    STATE(768), 1,
      sym_string_literal,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [21948] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(422), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(976), 5,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [21966] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(423), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(883), 5,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_ACCUM,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [21984] = 8,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(986), 1,
      anon_sym_RPAREN,
    ACTIONS(988), 1,
      anon_sym_PIPE,
    STATE(424), 1,
      sym_block_comment,
    STATE(503), 1,
      aux_sym_step_edge_types_repeat1,
    ACTIONS(945), 2,
      anon_sym_GT,
      anon_sym_DOT,
  [22010] = 6,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(967), 1,
      anon_sym_GT,
    STATE(425), 1,
      sym_block_comment,
    ACTIONS(969), 4,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_PIPE,
  [22032] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(426), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(558), 5,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22050] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(992), 1,
      anon_sym_AT,
    STATE(427), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(990), 3,
      anon_sym_GT,
      anon_sym_AT_AT,
      sym_name,
  [22069] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(994), 1,
      anon_sym_SEMI,
    STATE(428), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(996), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22088] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(998), 1,
      sym_name,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(429), 1,
      sym_block_comment,
    STATE(535), 1,
      sym_vertex_set_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22111] = 5,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(430), 1,
      sym_block_comment,
    ACTIONS(1000), 4,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_PIPE,
  [22130] = 7,
    ACTIONS(1002), 1,
      sym_newline,
    ACTIONS(1004), 1,
      sym_comment_contents,
    ACTIONS(1006), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1008), 1,
      anon_sym_STAR_SLASH,
    STATE(431), 1,
      sym_block_comment,
    STATE(445), 1,
      aux_sym_block_comment_repeat1,
    ACTIONS(3), 2,
      sym_space,
      sym_line_comment,
  [22153] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1010), 1,
      anon_sym_DO,
    STATE(432), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22172] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1012), 1,
      anon_sym_SEMI,
    ACTIONS(1014), 1,
      anon_sym_TO_CSV,
    STATE(433), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [22193] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1018), 1,
      anon_sym_AT,
    STATE(434), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1016), 3,
      anon_sym_GT,
      anon_sym_AT_AT,
      sym_name,
  [22212] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1020), 1,
      anon_sym_DO,
    STATE(435), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22231] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1020), 1,
      anon_sym_DO,
    STATE(436), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22250] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(437), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1022), 4,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_THEN,
  [22267] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(528), 1,
      anon_sym_COMMA,
    STATE(438), 1,
      sym_block_comment,
    STATE(446), 1,
      aux_sym_arg_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1024), 2,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
  [22288] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1026), 1,
      anon_sym_SEMI,
    ACTIONS(1028), 1,
      anon_sym_TO_CSV,
    STATE(439), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [22309] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1030), 1,
      anon_sym_RPAREN,
    STATE(440), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(996), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22328] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    STATE(441), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(534), 2,
      sym_global_accum_name,
      sym_local_accum_name,
  [22349] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1032), 1,
      anon_sym_RPAREN,
    STATE(442), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22368] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    ACTIONS(1034), 1,
      sym_name,
    STATE(443), 1,
      sym_block_comment,
    STATE(544), 1,
      aux_sym_accum_type_repeat1,
    STATE(684), 1,
      sym_simple_size,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22391] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1038), 1,
      anon_sym_WHEN,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1036), 2,
      anon_sym_ELSE,
      anon_sym_END,
    STATE(444), 2,
      sym_block_comment,
      aux_sym_dml_sub_case_stmt_repeat1,
  [22410] = 6,
    ACTIONS(1006), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1041), 1,
      sym_newline,
    ACTIONS(1044), 1,
      sym_comment_contents,
    ACTIONS(1047), 1,
      anon_sym_STAR_SLASH,
    ACTIONS(3), 2,
      sym_space,
      sym_line_comment,
    STATE(445), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [22431] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1049), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(684), 2,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
    STATE(446), 2,
      sym_block_comment,
      aux_sym_arg_list_repeat1,
  [22450] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1052), 1,
      anon_sym_RPAREN,
    STATE(447), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22469] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(49), 1,
      anon_sym_AT,
    STATE(448), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(459), 2,
      sym_global_accum_name,
      sym_local_accum_name,
  [22490] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(47), 1,
      anon_sym_AT_AT,
    ACTIONS(998), 1,
      sym_name,
    STATE(316), 1,
      sym_global_accum_name,
    STATE(449), 1,
      sym_block_comment,
    STATE(615), 1,
      sym_vertex_set_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22513] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1054), 1,
      anon_sym_LIMIT,
    ACTIONS(1056), 1,
      anon_sym_DO,
    STATE(450), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [22534] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(1058), 1,
      sym_name,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(451), 1,
      sym_block_comment,
    STATE(561), 1,
      sym_edge_set_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22557] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1062), 1,
      anon_sym_AT,
    STATE(452), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1060), 3,
      anon_sym_GT,
      anon_sym_AT_AT,
      sym_name,
  [22576] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(710), 1,
      anon_sym_WHEN,
    ACTIONS(1064), 1,
      anon_sym_ELSE,
    ACTIONS(1066), 1,
      anon_sym_END,
    STATE(453), 1,
      sym_block_comment,
    STATE(460), 1,
      aux_sym_query_body_case_stmt_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22599] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1070), 1,
      anon_sym_WHEN,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1068), 2,
      anon_sym_ELSE,
      anon_sym_END,
    STATE(454), 2,
      sym_block_comment,
      aux_sym_query_body_case_stmt_repeat1,
  [22618] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1075), 1,
      anon_sym_AT,
    STATE(455), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1073), 3,
      anon_sym_GT,
      anon_sym_AT_AT,
      sym_name,
  [22637] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(666), 1,
      anon_sym_AT_AT,
    ACTIONS(1058), 1,
      sym_name,
    STATE(411), 1,
      sym_global_accum_name,
    STATE(456), 1,
      sym_block_comment,
    STATE(619), 1,
      sym_edge_set_type,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22660] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1077), 1,
      anon_sym_ELSE,
    ACTIONS(1079), 1,
      anon_sym_END,
    ACTIONS(1081), 1,
      anon_sym_WHEN,
    STATE(444), 1,
      aux_sym_dml_sub_case_stmt_repeat1,
    STATE(457), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22683] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1083), 1,
      anon_sym_LIMIT,
    ACTIONS(1085), 1,
      anon_sym_DO,
    STATE(458), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [22704] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1087), 1,
      anon_sym_COMMA,
    ACTIONS(1089), 1,
      anon_sym_EQ,
    ACTIONS(1091), 1,
      anon_sym_SEMI,
    STATE(459), 1,
      sym_block_comment,
    STATE(548), 1,
      aux_sym_accum_decl_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22727] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1095), 1,
      anon_sym_WHEN,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1093), 2,
      anon_sym_ELSE,
      anon_sym_END,
    STATE(460), 2,
      sym_block_comment,
      aux_sym_query_body_case_stmt_repeat2,
  [22746] = 5,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(461), 1,
      sym_block_comment,
    ACTIONS(933), 4,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_PIPE,
  [22765] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(164), 1,
      anon_sym_DOT,
    ACTIONS(1098), 1,
      anon_sym_EQ,
    ACTIONS(1100), 1,
      anon_sym_PLUS_EQ,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(462), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22788] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1102), 1,
      anon_sym_ELSE,
    ACTIONS(1104), 1,
      anon_sym_END,
    ACTIONS(1106), 1,
      anon_sym_WHEN,
    STATE(454), 1,
      aux_sym_query_body_case_stmt_repeat1,
    STATE(463), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22811] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1108), 1,
      anon_sym_RPAREN,
    STATE(464), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22830] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1110), 1,
      anon_sym_RPAREN,
    STATE(465), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_UNION,
      anon_sym_INTERSECT,
      anon_sym_MINUS,
  [22849] = 7,
    ACTIONS(1002), 1,
      sym_newline,
    ACTIONS(1004), 1,
      sym_comment_contents,
    ACTIONS(1006), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1112), 1,
      anon_sym_STAR_SLASH,
    STATE(431), 1,
      aux_sym_block_comment_repeat1,
    STATE(466), 1,
      sym_block_comment,
    ACTIONS(3), 2,
      sym_space,
      sym_line_comment,
  [22872] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    ACTIONS(1034), 1,
      sym_name,
    STATE(467), 1,
      sym_block_comment,
    STATE(544), 1,
      aux_sym_accum_type_repeat1,
    STATE(823), 1,
      sym_simple_size,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22895] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1116), 1,
      anon_sym_AT,
    STATE(468), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1114), 3,
      anon_sym_GT,
      anon_sym_AT_AT,
      sym_name,
  [22914] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1118), 1,
      anon_sym_LT,
    STATE(469), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(642), 3,
      anon_sym_COMMA,
      anon_sym_GT,
      sym_name,
  [22933] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(690), 1,
      anon_sym_COMMA,
    ACTIONS(1120), 1,
      anon_sym_EQ,
    ACTIONS(1122), 1,
      anon_sym_SEMI,
    STATE(470), 1,
      sym_block_comment,
    STATE(541), 1,
      aux_sym_base_decl_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [22956] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(658), 1,
      anon_sym_COMMA,
    STATE(471), 1,
      sym_block_comment,
    STATE(474), 1,
      aux_sym_arg_list_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1024), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [22977] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1126), 1,
      anon_sym_AT,
    STATE(472), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1124), 3,
      anon_sym_GT,
      anon_sym_AT_AT,
      sym_name,
  [22996] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(473), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1128), 4,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_TO_CSV,
  [23013] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1130), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(684), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
    STATE(474), 2,
      sym_block_comment,
      aux_sym_arg_list_repeat1,
  [23032] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1135), 1,
      anon_sym_AT,
    STATE(475), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1133), 3,
      anon_sym_GT,
      anon_sym_AT_AT,
      sym_name,
  [23051] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(476), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(943), 4,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_WHERE,
      anon_sym_TO_CSV,
  [23068] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(477), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1137), 4,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
      anon_sym_STRING,
  [23085] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1139), 1,
      anon_sym_RPAREN,
    STATE(478), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [23103] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1141), 1,
      anon_sym_THEN,
    STATE(479), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [23121] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1143), 1,
      anon_sym_AT,
    ACTIONS(1145), 1,
      sym_name,
    STATE(319), 1,
      sym_local_accum_name,
    STATE(480), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23141] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1147), 1,
      anon_sym_OR,
    ACTIONS(1149), 1,
      anon_sym_DISTRIBUTED,
    ACTIONS(1151), 1,
      anon_sym_QUERY,
    STATE(481), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23161] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(482), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(642), 3,
      anon_sym_COMMA,
      anon_sym_GT,
      sym_name,
  [23177] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(1153), 1,
      anon_sym_DQUOTE,
    ACTIONS(1155), 1,
      sym_space,
    ACTIONS(1157), 1,
      sym_string_fragment,
    STATE(483), 1,
      sym_block_comment,
    STATE(531), 1,
      aux_sym_string_literal_repeat1,
  [23199] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1159), 1,
      anon_sym_RPAREN,
    ACTIONS(1161), 1,
      anon_sym_COMMA,
    STATE(484), 1,
      sym_block_comment,
    STATE(560), 1,
      aux_sym_accum_type_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23219] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1163), 1,
      anon_sym_THEN,
    STATE(485), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [23237] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1165), 1,
      anon_sym_ELSE,
    ACTIONS(1167), 1,
      anon_sym_END,
    STATE(486), 1,
      sym_block_comment,
    STATE(490), 1,
      aux_sym_query_body_if_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23257] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1087), 1,
      anon_sym_COMMA,
    ACTIONS(1169), 1,
      anon_sym_SEMI,
    STATE(487), 1,
      sym_block_comment,
    STATE(491), 1,
      aux_sym_accum_decl_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23277] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1165), 1,
      anon_sym_ELSE,
    ACTIONS(1167), 1,
      anon_sym_END,
    STATE(488), 1,
      sym_block_comment,
    STATE(490), 1,
      aux_sym_query_body_if_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23297] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(690), 1,
      anon_sym_COMMA,
    ACTIONS(1171), 1,
      anon_sym_SEMI,
    STATE(489), 1,
      sym_block_comment,
    STATE(493), 1,
      aux_sym_base_decl_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23317] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1173), 1,
      anon_sym_ELSE,
    ACTIONS(1175), 1,
      anon_sym_END,
    STATE(490), 1,
      sym_block_comment,
    STATE(506), 1,
      aux_sym_query_body_if_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23337] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1177), 1,
      anon_sym_COMMA,
    ACTIONS(1180), 1,
      anon_sym_SEMI,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(491), 2,
      sym_block_comment,
      aux_sym_accum_decl_stmt_repeat1,
  [23355] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1184), 1,
      anon_sym_EQ,
    STATE(492), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1182), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [23373] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1182), 1,
      anon_sym_SEMI,
    ACTIONS(1186), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(493), 2,
      sym_block_comment,
      aux_sym_base_decl_stmt_repeat1,
  [23391] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(494), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1189), 3,
      anon_sym_COMMA,
      anon_sym_GT,
      sym_name,
  [23407] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(1191), 1,
      anon_sym_DQUOTE,
    ACTIONS(1193), 1,
      sym_space,
    ACTIONS(1196), 1,
      sym_string_fragment,
    STATE(495), 2,
      sym_block_comment,
      aux_sym_string_literal_repeat1,
  [23427] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(496), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1199), 3,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
  [23443] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1201), 1,
      anon_sym_ELSE,
    ACTIONS(1203), 1,
      anon_sym_END,
    STATE(497), 1,
      sym_block_comment,
    STATE(540), 1,
      aux_sym_dml_sub_if_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23463] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(498), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1205), 3,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
  [23479] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(499), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1207), 3,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
  [23495] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1209), 1,
      anon_sym_RPAREN,
    ACTIONS(1211), 1,
      anon_sym_COMMA,
    STATE(500), 1,
      sym_block_comment,
    STATE(547), 1,
      aux_sym_query_params_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23515] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1213), 1,
      anon_sym_AT,
    ACTIONS(1215), 1,
      sym_name,
    STATE(146), 1,
      sym_local_accum_name,
    STATE(501), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23535] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(502), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1217), 3,
      anon_sym_COMMA,
      anon_sym_GT,
      sym_name,
  [23551] = 7,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(988), 1,
      anon_sym_PIPE,
    ACTIONS(1219), 1,
      anon_sym_RPAREN,
    STATE(503), 1,
      sym_block_comment,
    STATE(522), 1,
      aux_sym_step_edge_types_repeat1,
  [23573] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(504), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1207), 3,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
  [23589] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(1155), 1,
      sym_space,
    ACTIONS(1157), 1,
      sym_string_fragment,
    ACTIONS(1221), 1,
      anon_sym_DQUOTE,
    STATE(505), 1,
      sym_block_comment,
    STATE(572), 1,
      aux_sym_string_literal_repeat1,
  [23611] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1223), 1,
      anon_sym_ELSE,
    ACTIONS(1226), 1,
      anon_sym_END,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(506), 2,
      sym_block_comment,
      aux_sym_query_body_if_stmt_repeat1,
  [23629] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1228), 1,
      anon_sym_THEN,
    STATE(507), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [23647] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(508), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1230), 3,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
  [23663] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1232), 1,
      anon_sym_COMMA,
    ACTIONS(1234), 1,
      anon_sym_GT,
    STATE(509), 1,
      sym_block_comment,
    STATE(519), 1,
      aux_sym_accum_type_repeat4,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23683] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1236), 1,
      anon_sym_AT,
    ACTIONS(1238), 1,
      sym_name,
    STATE(27), 1,
      sym_local_accum_name,
    STATE(510), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23703] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    ACTIONS(1240), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_accum_type_repeat1,
    STATE(511), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23723] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(512), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1137), 3,
      anon_sym_INT,
      anon_sym_FLOAT,
      anon_sym_DOUBLE,
  [23739] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1242), 1,
      anon_sym_RPAREN,
    ACTIONS(1244), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(513), 2,
      sym_block_comment,
      aux_sym_query_params_repeat1,
  [23757] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1232), 1,
      anon_sym_COMMA,
    ACTIONS(1234), 1,
      anon_sym_GT,
    STATE(514), 1,
      sym_block_comment,
    STATE(578), 1,
      aux_sym_accum_type_repeat4,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23777] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1247), 1,
      anon_sym_COMMA,
    ACTIONS(1249), 1,
      anon_sym_GT,
    STATE(515), 1,
      sym_block_comment,
    STATE(550), 1,
      aux_sym_func_call_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23797] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1247), 1,
      anon_sym_COMMA,
    ACTIONS(1251), 1,
      anon_sym_GT,
    STATE(515), 1,
      aux_sym_func_call_stmt_repeat1,
    STATE(516), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23817] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1253), 1,
      anon_sym_COMMA,
    ACTIONS(1256), 1,
      anon_sym_RBRACK,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(517), 2,
      sym_block_comment,
      aux_sym_v_expr_set_repeat1,
  [23835] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1260), 1,
      anon_sym_DOT_STAR,
    STATE(518), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1258), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [23853] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1159), 1,
      anon_sym_GT,
    ACTIONS(1232), 1,
      anon_sym_COMMA,
    STATE(519), 1,
      sym_block_comment,
    STATE(578), 1,
      aux_sym_accum_type_repeat4,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23873] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1143), 1,
      anon_sym_AT,
    ACTIONS(1262), 1,
      sym_name,
    STATE(520), 1,
      sym_block_comment,
    STATE(600), 1,
      sym_local_accum_name,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23893] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1264), 1,
      anon_sym_COMMA,
    ACTIONS(1267), 1,
      anon_sym_RBRACE,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(521), 2,
      sym_block_comment,
      aux_sym_seed_set_repeat1,
  [23911] = 6,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(1269), 1,
      anon_sym_RPAREN,
    ACTIONS(1271), 1,
      anon_sym_PIPE,
    STATE(522), 2,
      sym_block_comment,
      aux_sym_step_edge_types_repeat1,
  [23931] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1087), 1,
      anon_sym_COMMA,
    ACTIONS(1274), 1,
      anon_sym_SEMI,
    STATE(487), 1,
      aux_sym_accum_decl_stmt_repeat1,
    STATE(523), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [23951] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(524), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1276), 3,
      ts_builtin_sym_end,
      anon_sym_CREATE,
      anon_sym_INTERPRET,
  [23967] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1278), 1,
      anon_sym_RPAREN,
    ACTIONS(1280), 1,
      anon_sym_PIPE2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(525), 2,
      sym_block_comment,
      aux_sym_step_vertex_types_repeat1,
  [23985] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(526), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1283), 3,
      ts_builtin_sym_end,
      anon_sym_CREATE,
      anon_sym_INTERPRET,
  [24001] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1285), 1,
      anon_sym_COMMA,
    ACTIONS(1287), 1,
      anon_sym_RBRACK,
    STATE(527), 1,
      sym_block_comment,
    STATE(570), 1,
      aux_sym_v_expr_set_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24021] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1213), 1,
      anon_sym_AT,
    ACTIONS(1289), 1,
      sym_name,
    STATE(146), 1,
      sym_local_accum_name,
    STATE(528), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24041] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1291), 1,
      anon_sym_THEN,
    STATE(529), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24059] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1293), 1,
      anon_sym_RPAREN,
    ACTIONS(1295), 1,
      anon_sym_DOT,
    ACTIONS(1297), 1,
      anon_sym_COLON,
    STATE(530), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24079] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(1155), 1,
      sym_space,
    ACTIONS(1157), 1,
      sym_string_fragment,
    ACTIONS(1299), 1,
      anon_sym_DQUOTE,
    STATE(495), 1,
      aux_sym_string_literal_repeat1,
    STATE(531), 1,
      sym_block_comment,
  [24101] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(532), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(959), 3,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_COLON,
  [24117] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(533), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(322), 3,
      anon_sym_ELSE,
      anon_sym_END,
      anon_sym_WHEN,
  [24133] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1301), 1,
      anon_sym_EQ,
    STATE(534), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1180), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [24151] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1303), 1,
      anon_sym_RPAREN,
    ACTIONS(1305), 1,
      anon_sym_PIPE2,
    STATE(535), 1,
      sym_block_comment,
    STATE(543), 1,
      aux_sym_step_vertex_types_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24171] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1307), 1,
      anon_sym_LPAREN,
    ACTIONS(1309), 1,
      sym_name,
    STATE(418), 1,
      sym_simple_set,
    STATE(536), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24191] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1311), 1,
      anon_sym_RPAREN,
    ACTIONS(1313), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(537), 2,
      sym_block_comment,
      aux_sym_for_each_control_repeat1,
  [24209] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(538), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1316), 3,
      ts_builtin_sym_end,
      anon_sym_CREATE,
      anon_sym_INTERPRET,
  [24225] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1247), 1,
      anon_sym_COMMA,
    ACTIONS(1318), 1,
      anon_sym_GT,
    STATE(539), 1,
      sym_block_comment,
    STATE(553), 1,
      aux_sym_func_call_stmt_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24245] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1320), 1,
      anon_sym_ELSE,
    ACTIONS(1323), 1,
      anon_sym_END,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(540), 2,
      sym_block_comment,
      aux_sym_dml_sub_if_stmt_repeat1,
  [24263] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(690), 1,
      anon_sym_COMMA,
    ACTIONS(1325), 1,
      anon_sym_SEMI,
    STATE(493), 1,
      aux_sym_base_decl_stmt_repeat1,
    STATE(541), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24283] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1327), 1,
      anon_sym_THEN,
    STATE(542), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24301] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1305), 1,
      anon_sym_PIPE2,
    ACTIONS(1329), 1,
      anon_sym_RPAREN,
    STATE(525), 1,
      aux_sym_step_vertex_types_repeat1,
    STATE(543), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24321] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    ACTIONS(1331), 1,
      anon_sym_DO,
    STATE(38), 1,
      aux_sym_accum_type_repeat1,
    STATE(544), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24341] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1333), 1,
      anon_sym_THEN,
    STATE(545), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24359] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1335), 1,
      anon_sym_RPAREN,
    ACTIONS(1337), 1,
      anon_sym_COMMA,
    STATE(537), 1,
      aux_sym_for_each_control_repeat1,
    STATE(546), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24379] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1211), 1,
      anon_sym_COMMA,
    ACTIONS(1339), 1,
      anon_sym_RPAREN,
    STATE(513), 1,
      aux_sym_query_params_repeat1,
    STATE(547), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24399] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1087), 1,
      anon_sym_COMMA,
    ACTIONS(1341), 1,
      anon_sym_SEMI,
    STATE(491), 1,
      aux_sym_accum_decl_stmt_repeat1,
    STATE(548), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24419] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1343), 1,
      anon_sym_LPAREN,
    ACTIONS(1345), 1,
      anon_sym_EQ,
    ACTIONS(1347), 1,
      anon_sym_PLUS_EQ,
    STATE(549), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24439] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1349), 1,
      anon_sym_COMMA,
    ACTIONS(1352), 1,
      anon_sym_GT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(550), 2,
      sym_block_comment,
      aux_sym_func_call_stmt_repeat1,
  [24457] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(551), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(680), 3,
      anon_sym_COMMA,
      anon_sym_GT,
      sym_name,
  [24473] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1356), 1,
      anon_sym_EQ,
    STATE(552), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1354), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [24491] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1247), 1,
      anon_sym_COMMA,
    ACTIONS(1358), 1,
      anon_sym_GT,
    STATE(550), 1,
      aux_sym_func_call_stmt_repeat1,
    STATE(553), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24511] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1360), 1,
      anon_sym_RPAREN,
    STATE(554), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24529] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(555), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1362), 3,
      anon_sym_SEMI,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [24545] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1364), 1,
      anon_sym_RPAREN,
    STATE(556), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24563] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(557), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1366), 3,
      anon_sym_SEMI,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [24579] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1368), 1,
      anon_sym_ELSE,
    ACTIONS(1370), 1,
      anon_sym_END,
    STATE(497), 1,
      aux_sym_dml_sub_if_stmt_repeat1,
    STATE(558), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24599] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1372), 1,
      sym_name,
    STATE(333), 1,
      sym_step_source_set,
    STATE(393), 1,
      sym_path_pattern,
    STATE(559), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24619] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1161), 1,
      anon_sym_COMMA,
    ACTIONS(1374), 1,
      anon_sym_RPAREN,
    STATE(560), 1,
      sym_block_comment,
    STATE(576), 1,
      aux_sym_accum_type_repeat2,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24639] = 7,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(986), 1,
      anon_sym_RPAREN,
    ACTIONS(988), 1,
      anon_sym_PIPE,
    STATE(503), 1,
      aux_sym_step_edge_types_repeat1,
    STATE(561), 1,
      sym_block_comment,
  [24661] = 5,
    ACTIONS(1006), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1376), 1,
      sym_newline,
    STATE(562), 1,
      sym_block_comment,
    ACTIONS(3), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1378), 2,
      sym_comment_contents,
      anon_sym_STAR_SLASH,
  [24679] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1236), 1,
      anon_sym_AT,
    ACTIONS(1380), 1,
      sym_name,
    STATE(27), 1,
      sym_local_accum_name,
    STATE(563), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24699] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1382), 1,
      anon_sym_COMMA,
    ACTIONS(1384), 1,
      anon_sym_RBRACE,
    STATE(564), 1,
      sym_block_comment,
    STATE(573), 1,
      aux_sym_seed_set_repeat1,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24719] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1386), 1,
      anon_sym_THEN,
    STATE(565), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24737] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(164), 1,
      anon_sym_DOT,
    ACTIONS(1388), 1,
      anon_sym_PLUS_EQ,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(566), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24757] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1390), 1,
      anon_sym_THEN,
    STATE(567), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24775] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(497), 1,
      aux_sym_dml_sub_if_stmt_repeat1,
    STATE(568), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1392), 2,
      anon_sym_ELSE,
      anon_sym_END,
  [24793] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(569), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1394), 3,
      anon_sym_SEMI,
      anon_sym_LIMIT,
      anon_sym_POST_DASHACCUM,
  [24809] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1285), 1,
      anon_sym_COMMA,
    ACTIONS(1396), 1,
      anon_sym_RBRACK,
    STATE(517), 1,
      aux_sym_v_expr_set_repeat1,
    STATE(570), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24829] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1307), 1,
      anon_sym_LPAREN,
    ACTIONS(1309), 1,
      sym_name,
    STATE(440), 1,
      sym_simple_set,
    STATE(571), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24849] = 7,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(1155), 1,
      sym_space,
    ACTIONS(1157), 1,
      sym_string_fragment,
    ACTIONS(1398), 1,
      anon_sym_DQUOTE,
    STATE(495), 1,
      aux_sym_string_literal_repeat1,
    STATE(572), 1,
      sym_block_comment,
  [24871] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1382), 1,
      anon_sym_COMMA,
    ACTIONS(1400), 1,
      anon_sym_RBRACE,
    STATE(521), 1,
      aux_sym_seed_set_repeat1,
    STATE(573), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24891] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(574), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1402), 3,
      ts_builtin_sym_end,
      anon_sym_CREATE,
      anon_sym_INTERPRET,
  [24907] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1404), 1,
      anon_sym_RPAREN,
    STATE(575), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24925] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1406), 1,
      anon_sym_RPAREN,
    ACTIONS(1408), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(576), 2,
      sym_block_comment,
      aux_sym_accum_type_repeat2,
  [24943] = 6,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1232), 1,
      anon_sym_COMMA,
    ACTIONS(1411), 1,
      anon_sym_GT,
    STATE(514), 1,
      aux_sym_accum_type_repeat4,
    STATE(577), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [24963] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1413), 1,
      anon_sym_COMMA,
    ACTIONS(1416), 1,
      anon_sym_GT,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(578), 2,
      sym_block_comment,
      aux_sym_accum_type_repeat4,
  [24981] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1418), 1,
      anon_sym_RPAREN,
    STATE(579), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(893), 2,
      anon_sym_OR,
      anon_sym_AND,
  [24999] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(580), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1420), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [25014] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1422), 1,
      anon_sym_RPAREN,
    ACTIONS(1424), 1,
      anon_sym_COLON,
    STATE(581), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25031] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(582), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1426), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [25046] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1428), 1,
      anon_sym_IN,
    ACTIONS(1430), 1,
      anon_sym_LIKE,
    STATE(583), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25063] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1081), 1,
      anon_sym_WHEN,
    STATE(457), 1,
      aux_sym_dml_sub_case_stmt_repeat1,
    STATE(584), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25080] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(585), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1432), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [25095] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1295), 1,
      anon_sym_DOT,
    ACTIONS(1434), 1,
      anon_sym_RPAREN,
    STATE(586), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25112] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    ACTIONS(1438), 1,
      sym_string_fragment,
    STATE(587), 1,
      sym_block_comment,
    ACTIONS(1436), 2,
      anon_sym_DQUOTE,
      sym_space,
  [25129] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1440), 1,
      anon_sym_LPAREN,
    STATE(588), 1,
      sym_block_comment,
    STATE(819), 1,
      sym_parameter_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25146] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1442), 1,
      anon_sym_COMMA,
    STATE(589), 1,
      sym_block_comment,
    STATE(624), 1,
      aux_sym_accum_type_repeat3,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25163] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(590), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1444), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [25178] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(591), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1352), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [25193] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(592), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1258), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [25208] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    STATE(511), 1,
      aux_sym_accum_type_repeat1,
    STATE(593), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25225] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(594), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1392), 2,
      anon_sym_ELSE,
      anon_sym_END,
  [25240] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1364), 1,
      anon_sym_NULL,
    ACTIONS(1446), 1,
      anon_sym_NOT,
    STATE(595), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25257] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(596), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1448), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [25272] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1440), 1,
      anon_sym_LPAREN,
    STATE(597), 1,
      sym_block_comment,
    STATE(732), 1,
      sym_parameter_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25289] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1450), 1,
      anon_sym_SYNTAX,
    ACTIONS(1452), 1,
      anon_sym_LBRACE,
    STATE(598), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25306] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    STATE(40), 1,
      aux_sym_accum_type_repeat1,
    STATE(599), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25323] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(600), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1454), 2,
      anon_sym_EQ,
      anon_sym_PLUS_EQ,
  [25338] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1456), 1,
      anon_sym_LBRACE,
    STATE(574), 1,
      sym_query_body,
    STATE(601), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25355] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(602), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1458), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [25370] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1460), 1,
      anon_sym_RPAREN,
    ACTIONS(1462), 1,
      anon_sym_DASH_GT,
    STATE(603), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25387] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1464), 1,
      anon_sym_DISTRIBUTED,
    ACTIONS(1466), 1,
      anon_sym_QUERY,
    STATE(604), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25404] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1343), 1,
      anon_sym_LPAREN,
    ACTIONS(1345), 1,
      anon_sym_EQ,
    STATE(605), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25421] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(606), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(965), 2,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [25436] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1440), 1,
      anon_sym_LPAREN,
    STATE(607), 1,
      sym_block_comment,
    STATE(772), 1,
      sym_parameter_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25453] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1440), 1,
      anon_sym_LPAREN,
    STATE(608), 1,
      sym_block_comment,
    STATE(659), 1,
      sym_parameter_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25470] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1468), 1,
      anon_sym_IN,
    ACTIONS(1470), 1,
      anon_sym_COLON,
    STATE(609), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25487] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1472), 1,
      anon_sym_SYNTAX,
    ACTIONS(1474), 1,
      anon_sym_LBRACE,
    STATE(610), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25504] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(611), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1476), 2,
      anon_sym_V2,
      anon_sym_v2,
  [25519] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(612), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1478), 2,
      anon_sym_ELSE,
      anon_sym_END,
  [25534] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(613), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1480), 2,
      anon_sym_ASC,
      anon_sym_DESC,
  [25549] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(614), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1482), 2,
      anon_sym_V2,
      anon_sym_v2,
  [25564] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(615), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1278), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE2,
  [25579] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(540), 1,
      sym_digit,
    STATE(208), 1,
      aux_sym_accum_type_repeat1,
    STATE(616), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25596] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(617), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1242), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [25611] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(618), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1484), 2,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [25626] = 5,
    ACTIONS(3), 1,
      sym_space,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      sym_line_comment,
    STATE(619), 1,
      sym_block_comment,
    ACTIONS(1269), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [25643] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(620), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1267), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [25658] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(621), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1486), 2,
      anon_sym_ASC,
      anon_sym_DESC,
  [25673] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(622), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1256), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [25688] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(623), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1488), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [25703] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1490), 1,
      anon_sym_COMMA,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    STATE(624), 2,
      sym_block_comment,
      aux_sym_accum_type_repeat3,
  [25718] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1493), 1,
      anon_sym_IN,
    ACTIONS(1495), 1,
      anon_sym_COLON,
    STATE(625), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25735] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1497), 1,
      anon_sym_SYNTAX,
    ACTIONS(1499), 1,
      anon_sym_LBRACE,
    STATE(626), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25752] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(627), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1501), 2,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [25767] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1503), 1,
      anon_sym_COMMA,
    STATE(589), 1,
      aux_sym_accum_type_repeat3,
    STATE(628), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25784] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    STATE(41), 1,
      aux_sym_accum_type_repeat1,
    STATE(629), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25801] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1440), 1,
      anon_sym_LPAREN,
    STATE(630), 1,
      sym_block_comment,
    STATE(658), 1,
      sym_parameter_list,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25818] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(216), 1,
      sym_digit,
    STATE(385), 1,
      aux_sym_accum_type_repeat1,
    STATE(631), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25835] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(632), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(945), 2,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [25850] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(633), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(951), 2,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [25865] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(164), 1,
      anon_sym_DOT,
    STATE(39), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(634), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25882] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1505), 1,
      anon_sym_SYNTAX,
    ACTIONS(1507), 1,
      anon_sym_LBRACE,
    STATE(635), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25899] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1509), 1,
      anon_sym_FROM,
    STATE(324), 1,
      sym_from_clause,
    STATE(636), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25916] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(637), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1511), 2,
      anon_sym_V2,
      anon_sym_v2,
  [25931] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1513), 1,
      anon_sym_SYNTAX,
    ACTIONS(1515), 1,
      anon_sym_LBRACE,
    STATE(638), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25948] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(639), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(1517), 2,
      anon_sym_V2,
      anon_sym_v2,
  [25963] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1337), 1,
      anon_sym_COMMA,
    STATE(546), 1,
      aux_sym_for_each_control_repeat1,
    STATE(640), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [25980] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(641), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
    ACTIONS(128), 2,
      anon_sym_IN,
      anon_sym_COLON,
  [25995] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(507), 1,
      anon_sym_DOT,
    STATE(206), 1,
      aux_sym_func_call_stmt_repeat2,
    STATE(642), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26012] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1519), 1,
      anon_sym_DOT,
    ACTIONS(1521), 1,
      sym_digit,
    STATE(643), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26029] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1523), 1,
      anon_sym_DOT,
    ACTIONS(1525), 1,
      anon_sym_DO,
    STATE(644), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26046] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(540), 1,
      sym_digit,
    STATE(209), 1,
      aux_sym_accum_type_repeat1,
    STATE(645), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26063] = 5,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1527), 1,
      anon_sym_RPAREN,
    ACTIONS(1529), 1,
      anon_sym_DASH_GT,
    STATE(646), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26080] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1531), 1,
      anon_sym_COMMA,
    STATE(647), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26094] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1533), 1,
      sym_name,
    STATE(648), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26108] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1535), 1,
      anon_sym_RPAREN,
    STATE(649), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26122] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1537), 1,
      anon_sym_GT,
    STATE(650), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26136] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1026), 1,
      anon_sym_SEMI,
    STATE(651), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26150] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1539), 1,
      anon_sym_LBRACE,
    STATE(652), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26164] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1541), 1,
      sym_name,
    STATE(653), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26178] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1543), 1,
      anon_sym_LPAREN,
    STATE(654), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26192] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1545), 1,
      anon_sym_RPAREN,
    STATE(655), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26206] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1547), 1,
      sym_name,
    STATE(656), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26220] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1549), 1,
      anon_sym_GRAPH,
    STATE(657), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26234] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1551), 1,
      anon_sym_FOR,
    STATE(658), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26248] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1553), 1,
      anon_sym_FOR,
    STATE(659), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26262] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1555), 1,
      sym_name,
    STATE(660), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26276] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1557), 1,
      sym_name,
    STATE(661), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26290] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1559), 1,
      anon_sym_GT,
    STATE(662), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26304] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1561), 1,
      anon_sym_RPAREN,
    STATE(663), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26318] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1563), 1,
      anon_sym_GT,
    STATE(664), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26332] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1565), 1,
      anon_sym_RPAREN,
    STATE(665), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26346] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1567), 1,
      anon_sym_SEMI,
    STATE(666), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26360] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1569), 1,
      sym_name,
    STATE(667), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26374] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1571), 1,
      anon_sym_DASH,
    STATE(668), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26388] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1573), 1,
      anon_sym_RPAREN,
    STATE(669), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26402] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1575), 1,
      sym_name,
    STATE(670), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26416] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1577), 1,
      anon_sym_FILTER,
    STATE(671), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26430] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1579), 1,
      anon_sym_SEMI,
    STATE(672), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26444] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1581), 1,
      anon_sym_END,
    STATE(673), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26458] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1583), 1,
      anon_sym_LPAREN,
    STATE(674), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26472] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1585), 1,
      anon_sym_LBRACE,
    STATE(675), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26486] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(994), 1,
      anon_sym_SEMI,
    STATE(676), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26500] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1587), 1,
      anon_sym_END,
    STATE(677), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26514] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1589), 1,
      sym_name,
    STATE(678), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26528] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1591), 1,
      anon_sym_LBRACE,
    STATE(679), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26542] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1593), 1,
      anon_sym_END,
    STATE(680), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26556] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(889), 1,
      anon_sym_SEMI,
    STATE(681), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26570] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1595), 1,
      anon_sym_END,
    STATE(682), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26584] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1597), 1,
      anon_sym_STEP,
    STATE(683), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26598] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1599), 1,
      anon_sym_DO,
    STATE(684), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26612] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1601), 1,
      sym_name,
    STATE(685), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26626] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1603), 1,
      anon_sym_END,
    STATE(686), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26640] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1605), 1,
      anon_sym_DASH,
    STATE(687), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26654] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1607), 1,
      sym_name,
    STATE(688), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26668] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1609), 1,
      sym_name,
    STATE(689), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26682] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1611), 1,
      anon_sym_DASH,
    STATE(690), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26696] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1613), 1,
      sym_name,
    STATE(691), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26710] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1615), 1,
      anon_sym_END,
    STATE(692), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26724] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1617), 1,
      anon_sym_IF,
    STATE(693), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26738] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1619), 1,
      sym_name,
    STATE(694), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26752] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1621), 1,
      anon_sym_DASH,
    STATE(695), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26766] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1623), 1,
      anon_sym_RPAREN,
    STATE(696), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26780] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1625), 1,
      anon_sym_RPAREN,
    STATE(697), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26794] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1627), 1,
      anon_sym_V2,
    STATE(698), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26808] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1629), 1,
      anon_sym_SEMI,
    STATE(699), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26822] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1631), 1,
      anon_sym_LPAREN,
    STATE(700), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26836] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1629), 1,
      anon_sym_SEMI,
    STATE(701), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26850] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1633), 1,
      sym_name,
    STATE(702), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26864] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1635), 1,
      anon_sym_COMMA,
    STATE(703), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26878] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1637), 1,
      sym_name,
    STATE(704), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26892] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1639), 1,
      sym_name,
    STATE(705), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26906] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1641), 1,
      anon_sym_LPAREN,
    STATE(706), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26920] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1398), 1,
      anon_sym_SQUOTE,
    STATE(707), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26934] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1643), 1,
      anon_sym_LPAREN,
    STATE(708), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26948] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1645), 1,
      anon_sym_SEMI,
    STATE(709), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26962] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1647), 1,
      anon_sym_SEMI,
    STATE(710), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26976] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1649), 1,
      anon_sym_IF,
    STATE(711), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [26990] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1651), 1,
      anon_sym_END,
    STATE(712), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27004] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1653), 1,
      anon_sym_SEMI,
    STATE(713), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27018] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1655), 1,
      sym_digit,
    STATE(714), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27032] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1657), 1,
      anon_sym_FILTER,
    STATE(715), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27046] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1659), 1,
      anon_sym_DO,
    STATE(716), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27060] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1661), 1,
      anon_sym_SEMI,
    STATE(717), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27074] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1663), 1,
      anon_sym_MIN,
    STATE(718), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27088] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1665), 1,
      anon_sym_LBRACE,
    STATE(719), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27102] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1667), 1,
      sym_name,
    STATE(720), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27116] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(464), 1,
      anon_sym_RBRACK,
    STATE(721), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27130] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1669), 1,
      sym_name,
    STATE(722), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27144] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1671), 1,
      anon_sym_SEMI,
    STATE(723), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27158] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1673), 1,
      sym_name,
    STATE(724), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27172] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(793), 1,
      anon_sym_SEMI,
    STATE(725), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27186] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1108), 1,
      anon_sym_RPAREN,
    STATE(726), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27200] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1675), 1,
      anon_sym_FOR,
    STATE(727), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27214] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1677), 1,
      anon_sym_GRAPH,
    STATE(728), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27228] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1343), 1,
      anon_sym_LPAREN,
    STATE(729), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27242] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1679), 1,
      sym_name,
    STATE(730), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27256] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1681), 1,
      anon_sym_RPAREN,
    STATE(731), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27270] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1683), 1,
      anon_sym_FOR,
    STATE(732), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27284] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1685), 1,
      sym_name,
    STATE(733), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27298] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1687), 1,
      anon_sym_END,
    STATE(734), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27312] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1689), 1,
      anon_sym_GRAPH,
    STATE(735), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27326] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1691), 1,
      sym_name,
    STATE(736), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27340] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1693), 1,
      sym_name,
    STATE(737), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27354] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1695), 1,
      anon_sym_GT,
    STATE(738), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27368] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(428), 1,
      anon_sym_RPAREN,
    STATE(739), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27382] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1697), 1,
      sym_name,
    STATE(740), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27396] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1699), 1,
      anon_sym_SEMI,
    STATE(741), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27410] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1701), 1,
      anon_sym_SEMI,
    STATE(742), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27424] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1137), 1,
      sym_name,
    STATE(743), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27438] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1703), 1,
      sym_name,
    STATE(744), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27452] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1701), 1,
      anon_sym_SEMI,
    STATE(745), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27466] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1705), 1,
      sym_name,
    STATE(746), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27480] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1707), 1,
      sym_name,
    STATE(747), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27494] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1709), 1,
      anon_sym_DO,
    STATE(748), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27508] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1460), 1,
      anon_sym_RPAREN,
    STATE(749), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27522] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1711), 1,
      sym_name,
    STATE(750), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27536] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1713), 1,
      anon_sym_SEMI,
    STATE(751), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27550] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1715), 1,
      anon_sym_SEMI,
    STATE(752), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27564] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1717), 1,
      anon_sym_LPAREN,
    STATE(753), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27578] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1719), 1,
      sym_digit,
    STATE(754), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27592] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1721), 1,
      sym_string_fragment,
    STATE(755), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27606] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1723), 1,
      anon_sym_SUM,
    STATE(756), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27620] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1725), 1,
      anon_sym_MAX,
    STATE(757), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27634] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1727), 1,
      anon_sym_LPAREN,
    STATE(758), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27648] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1729), 1,
      anon_sym_LPAREN,
    STATE(759), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27662] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1731), 1,
      anon_sym_SEMI,
    STATE(760), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27676] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1733), 1,
      anon_sym_LT,
    STATE(761), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27690] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1735), 1,
      anon_sym_END,
    STATE(762), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27704] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1737), 1,
      anon_sym_GRAPH,
    STATE(763), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27718] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1739), 1,
      anon_sym_LPAREN,
    STATE(764), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27732] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1527), 1,
      anon_sym_RPAREN,
    STATE(765), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27746] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1741), 1,
      sym_name,
    STATE(766), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27760] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1743), 1,
      sym_name,
    STATE(767), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27774] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1745), 1,
      anon_sym_SEMI,
    STATE(768), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27788] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1747), 1,
      anon_sym_RPAREN,
    STATE(769), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27802] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1749), 1,
      anon_sym_LT,
    STATE(770), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27816] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1751), 1,
      anon_sym_FOR,
    STATE(771), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27830] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1753), 1,
      anon_sym_FOR,
    STATE(772), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27844] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1755), 1,
      sym_digit,
    STATE(773), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27858] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1757), 1,
      sym_name,
    STATE(774), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27872] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1759), 1,
      anon_sym_QUERY,
    STATE(775), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27886] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1110), 1,
      anon_sym_RPAREN,
    STATE(776), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27900] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1761), 1,
      anon_sym_RPAREN,
    STATE(777), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27914] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1763), 1,
      sym_name,
    STATE(778), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27928] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1765), 1,
      anon_sym_LPAREN,
    STATE(779), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27942] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1767), 1,
      anon_sym_AVG,
    STATE(780), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27956] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1769), 1,
      anon_sym_SEMI,
    STATE(781), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27970] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1771), 1,
      anon_sym_SEMI,
    STATE(782), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27984] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1773), 1,
      anon_sym_NULL,
    STATE(783), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [27998] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1775), 1,
      anon_sym_SEMI,
    STATE(784), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28012] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1777), 1,
      anon_sym_SEMI,
    STATE(785), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28026] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1779), 1,
      anon_sym_LBRACE,
    STATE(786), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28040] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1781), 1,
      sym_name,
    STATE(787), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28054] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1783), 1,
      anon_sym_GRAPH,
    STATE(788), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28068] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1785), 1,
      sym_name,
    STATE(789), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28082] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1787), 1,
      sym_name,
    STATE(790), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28096] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1789), 1,
      anon_sym_LT,
    STATE(791), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28110] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1791), 1,
      anon_sym_LT,
    STATE(792), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28124] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1793), 1,
      anon_sym_LT,
    STATE(793), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28138] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1795), 1,
      anon_sym_LT,
    STATE(794), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28152] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1797), 1,
      anon_sym_LT,
    STATE(795), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28166] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1799), 1,
      anon_sym_LT,
    STATE(796), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28180] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1026), 1,
      anon_sym_SEMI,
    STATE(797), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28194] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1801), 1,
      sym_name,
    STATE(798), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28208] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1803), 1,
      sym_name,
    STATE(799), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28222] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1805), 1,
      anon_sym_SEMI,
    STATE(800), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28236] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1807), 1,
      sym_name,
    STATE(801), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28250] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(905), 1,
      anon_sym_SEMI,
    STATE(802), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28264] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1809), 1,
      anon_sym_LT,
    STATE(803), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28278] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1811), 1,
      anon_sym_EQ,
    STATE(804), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28292] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1813), 1,
      anon_sym_THEN,
    STATE(805), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28306] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1815), 1,
      sym_name,
    STATE(806), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28320] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1817), 1,
      anon_sym_LT,
    STATE(807), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28334] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(468), 1,
      anon_sym_RBRACK,
    STATE(808), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28348] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1819), 1,
      anon_sym_SEMI,
    STATE(809), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28362] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1821), 1,
      anon_sym_TUPLE,
    STATE(810), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28376] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1823), 1,
      anon_sym_DO,
    STATE(811), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28390] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1825), 1,
      sym_digit,
    STATE(812), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28404] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1827), 1,
      anon_sym_END,
    STATE(813), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28418] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1299), 1,
      anon_sym_SQUOTE,
    STATE(814), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28432] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1331), 1,
      anon_sym_DO,
    STATE(815), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28446] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1829), 1,
      anon_sym_LPAREN,
    STATE(816), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28460] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1831), 1,
      anon_sym_GT,
    STATE(817), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28474] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1833), 1,
      anon_sym_RPAREN,
    STATE(818), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28488] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1835), 1,
      anon_sym_FOR,
    STATE(819), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28502] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1837), 1,
      sym_digit,
    STATE(820), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28516] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1052), 1,
      anon_sym_RPAREN,
    STATE(821), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28530] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1839), 1,
      anon_sym_LPAREN,
    STATE(822), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28544] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1841), 1,
      anon_sym_DO,
    STATE(823), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28558] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1843), 1,
      sym_name,
    STATE(824), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28572] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1845), 1,
      anon_sym_END,
    STATE(825), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28586] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1032), 1,
      anon_sym_RPAREN,
    STATE(826), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28600] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1847), 1,
      sym_name,
    STATE(827), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28614] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1849), 1,
      sym_name,
    STATE(828), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28628] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1851), 1,
      sym_name,
    STATE(829), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28642] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1853), 1,
      anon_sym_RPAREN,
    STATE(830), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28656] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1855), 1,
      anon_sym_RPAREN,
    STATE(831), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28670] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1857), 1,
      anon_sym_RPAREN,
    STATE(832), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28684] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(418), 1,
      anon_sym_RPAREN,
    STATE(833), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28698] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1859), 1,
      anon_sym_LPAREN,
    STATE(834), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28712] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1861), 1,
      anon_sym_LBRACK,
    STATE(835), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28726] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1863), 1,
      anon_sym_FILTER,
    STATE(836), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28740] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1865), 1,
      anon_sym_RPAREN,
    STATE(837), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28754] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1867), 1,
      anon_sym_RPAREN,
    STATE(838), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28768] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1869), 1,
      anon_sym_SEMI,
    STATE(839), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28782] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1012), 1,
      anon_sym_SEMI,
    STATE(840), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28796] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1012), 1,
      anon_sym_SEMI,
    STATE(841), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28810] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1871), 1,
      sym_name,
    STATE(842), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28824] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1873), 1,
      sym_name,
    STATE(843), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28838] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1875), 1,
      sym_name,
    STATE(844), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28852] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1877), 1,
      anon_sym_QUERY,
    STATE(845), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28866] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1879), 1,
      anon_sym_REPLACE,
    STATE(846), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28880] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1881), 1,
      anon_sym_RPAREN,
    STATE(847), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28894] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1883), 1,
      sym_name,
    STATE(848), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28908] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1885), 1,
      sym_name,
    STATE(849), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28922] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1887), 1,
      anon_sym_FILTER,
    STATE(850), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28936] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1889), 1,
      anon_sym_RPAREN,
    STATE(851), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28950] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1891), 1,
      anon_sym_END,
    STATE(852), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28964] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1893), 1,
      anon_sym_LPAREN,
    STATE(853), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28978] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1895), 1,
      anon_sym_LPAREN,
    STATE(854), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [28992] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1897), 1,
      sym_string_fragment,
    STATE(855), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29006] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1899), 1,
      anon_sym_GT,
    STATE(856), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29020] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1901), 1,
      sym_name,
    STATE(857), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29034] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1903), 1,
      anon_sym_SEMI,
    STATE(858), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29048] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1905), 1,
      anon_sym_SELECT,
    STATE(859), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29062] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1907), 1,
      anon_sym_LPAREN,
    STATE(860), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29076] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1909), 1,
      anon_sym_SEMI,
    STATE(861), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29090] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1911), 1,
      anon_sym_FROM,
    STATE(862), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29104] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1913), 1,
      anon_sym_LPAREN,
    STATE(863), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29118] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1915), 1,
      anon_sym_LPAREN,
    STATE(864), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29132] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1917), 1,
      ts_builtin_sym_end,
    STATE(865), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29146] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1919), 1,
      anon_sym_QUERY,
    STATE(866), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29160] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1921), 1,
      anon_sym_LPAREN,
    STATE(867), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29174] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1923), 1,
      anon_sym_LPAREN,
    STATE(868), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29188] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1925), 1,
      anon_sym_LPAREN,
    STATE(869), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29202] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1927), 1,
      anon_sym_LPAREN,
    STATE(870), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29216] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1929), 1,
      sym_name,
    STATE(871), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29230] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1931), 1,
      anon_sym_LPAREN,
    STATE(872), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29244] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1933), 1,
      anon_sym_SEMI,
    STATE(873), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29258] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1935), 1,
      anon_sym_LPAREN,
    STATE(874), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29272] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1937), 1,
      anon_sym_LPAREN,
    STATE(875), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29286] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1939), 1,
      sym_name,
    STATE(876), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29300] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1941), 1,
      sym_name,
    STATE(877), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29314] = 4,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(1943), 1,
      anon_sym_END,
    STATE(878), 1,
      sym_block_comment,
    ACTIONS(7), 2,
      sym_space,
      sym_line_comment,
  [29328] = 1,
    ACTIONS(1945), 1,
      ts_builtin_sym_end,
  [29332] = 1,
    ACTIONS(1947), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 123,
  [SMALL_STATE(7)] = 246,
  [SMALL_STATE(8)] = 369,
  [SMALL_STATE(9)] = 492,
  [SMALL_STATE(10)] = 615,
  [SMALL_STATE(11)] = 738,
  [SMALL_STATE(12)] = 861,
  [SMALL_STATE(13)] = 984,
  [SMALL_STATE(14)] = 1107,
  [SMALL_STATE(15)] = 1230,
  [SMALL_STATE(16)] = 1353,
  [SMALL_STATE(17)] = 1476,
  [SMALL_STATE(18)] = 1538,
  [SMALL_STATE(19)] = 1604,
  [SMALL_STATE(20)] = 1665,
  [SMALL_STATE(21)] = 1726,
  [SMALL_STATE(22)] = 1791,
  [SMALL_STATE(23)] = 1854,
  [SMALL_STATE(24)] = 1919,
  [SMALL_STATE(25)] = 1982,
  [SMALL_STATE(26)] = 2043,
  [SMALL_STATE(27)] = 2104,
  [SMALL_STATE(28)] = 2165,
  [SMALL_STATE(29)] = 2223,
  [SMALL_STATE(30)] = 2283,
  [SMALL_STATE(31)] = 2341,
  [SMALL_STATE(32)] = 2399,
  [SMALL_STATE(33)] = 2457,
  [SMALL_STATE(34)] = 2516,
  [SMALL_STATE(35)] = 2573,
  [SMALL_STATE(36)] = 2630,
  [SMALL_STATE(37)] = 2687,
  [SMALL_STATE(38)] = 2745,
  [SMALL_STATE(39)] = 2803,
  [SMALL_STATE(40)] = 2863,
  [SMALL_STATE(41)] = 2923,
  [SMALL_STATE(42)] = 2983,
  [SMALL_STATE(43)] = 3038,
  [SMALL_STATE(44)] = 3095,
  [SMALL_STATE(45)] = 3150,
  [SMALL_STATE(46)] = 3207,
  [SMALL_STATE(47)] = 3264,
  [SMALL_STATE(48)] = 3319,
  [SMALL_STATE(49)] = 3376,
  [SMALL_STATE(50)] = 3430,
  [SMALL_STATE(51)] = 3484,
  [SMALL_STATE(52)] = 3538,
  [SMALL_STATE(53)] = 3592,
  [SMALL_STATE(54)] = 3646,
  [SMALL_STATE(55)] = 3700,
  [SMALL_STATE(56)] = 3754,
  [SMALL_STATE(57)] = 3808,
  [SMALL_STATE(58)] = 3862,
  [SMALL_STATE(59)] = 3916,
  [SMALL_STATE(60)] = 3970,
  [SMALL_STATE(61)] = 4024,
  [SMALL_STATE(62)] = 4078,
  [SMALL_STATE(63)] = 4132,
  [SMALL_STATE(64)] = 4186,
  [SMALL_STATE(65)] = 4240,
  [SMALL_STATE(66)] = 4294,
  [SMALL_STATE(67)] = 4348,
  [SMALL_STATE(68)] = 4402,
  [SMALL_STATE(69)] = 4456,
  [SMALL_STATE(70)] = 4510,
  [SMALL_STATE(71)] = 4616,
  [SMALL_STATE(72)] = 4670,
  [SMALL_STATE(73)] = 4724,
  [SMALL_STATE(74)] = 4783,
  [SMALL_STATE(75)] = 4843,
  [SMALL_STATE(76)] = 4918,
  [SMALL_STATE(77)] = 4993,
  [SMALL_STATE(78)] = 5068,
  [SMALL_STATE(79)] = 5143,
  [SMALL_STATE(80)] = 5218,
  [SMALL_STATE(81)] = 5293,
  [SMALL_STATE(82)] = 5368,
  [SMALL_STATE(83)] = 5443,
  [SMALL_STATE(84)] = 5518,
  [SMALL_STATE(85)] = 5593,
  [SMALL_STATE(86)] = 5668,
  [SMALL_STATE(87)] = 5743,
  [SMALL_STATE(88)] = 5815,
  [SMALL_STATE(89)] = 5913,
  [SMALL_STATE(90)] = 6011,
  [SMALL_STATE(91)] = 6104,
  [SMALL_STATE(92)] = 6197,
  [SMALL_STATE(93)] = 6292,
  [SMALL_STATE(94)] = 6387,
  [SMALL_STATE(95)] = 6480,
  [SMALL_STATE(96)] = 6547,
  [SMALL_STATE(97)] = 6642,
  [SMALL_STATE(98)] = 6737,
  [SMALL_STATE(99)] = 6832,
  [SMALL_STATE(100)] = 6925,
  [SMALL_STATE(101)] = 7020,
  [SMALL_STATE(102)] = 7115,
  [SMALL_STATE(103)] = 7210,
  [SMALL_STATE(104)] = 7305,
  [SMALL_STATE(105)] = 7400,
  [SMALL_STATE(106)] = 7493,
  [SMALL_STATE(107)] = 7586,
  [SMALL_STATE(108)] = 7679,
  [SMALL_STATE(109)] = 7774,
  [SMALL_STATE(110)] = 7869,
  [SMALL_STATE(111)] = 7964,
  [SMALL_STATE(112)] = 8057,
  [SMALL_STATE(113)] = 8152,
  [SMALL_STATE(114)] = 8245,
  [SMALL_STATE(115)] = 8338,
  [SMALL_STATE(116)] = 8431,
  [SMALL_STATE(117)] = 8526,
  [SMALL_STATE(118)] = 8619,
  [SMALL_STATE(119)] = 8714,
  [SMALL_STATE(120)] = 8807,
  [SMALL_STATE(121)] = 8900,
  [SMALL_STATE(122)] = 8993,
  [SMALL_STATE(123)] = 9088,
  [SMALL_STATE(124)] = 9181,
  [SMALL_STATE(125)] = 9276,
  [SMALL_STATE(126)] = 9371,
  [SMALL_STATE(127)] = 9464,
  [SMALL_STATE(128)] = 9557,
  [SMALL_STATE(129)] = 9650,
  [SMALL_STATE(130)] = 9743,
  [SMALL_STATE(131)] = 9836,
  [SMALL_STATE(132)] = 9929,
  [SMALL_STATE(133)] = 10019,
  [SMALL_STATE(134)] = 10109,
  [SMALL_STATE(135)] = 10161,
  [SMALL_STATE(136)] = 10251,
  [SMALL_STATE(137)] = 10341,
  [SMALL_STATE(138)] = 10389,
  [SMALL_STATE(139)] = 10479,
  [SMALL_STATE(140)] = 10533,
  [SMALL_STATE(141)] = 10623,
  [SMALL_STATE(142)] = 10713,
  [SMALL_STATE(143)] = 10803,
  [SMALL_STATE(144)] = 10893,
  [SMALL_STATE(145)] = 10983,
  [SMALL_STATE(146)] = 11035,
  [SMALL_STATE(147)] = 11082,
  [SMALL_STATE(148)] = 11169,
  [SMALL_STATE(149)] = 11218,
  [SMALL_STATE(150)] = 11265,
  [SMALL_STATE(151)] = 11316,
  [SMALL_STATE(152)] = 11403,
  [SMALL_STATE(153)] = 11490,
  [SMALL_STATE(154)] = 11537,
  [SMALL_STATE(155)] = 11624,
  [SMALL_STATE(156)] = 11711,
  [SMALL_STATE(157)] = 11758,
  [SMALL_STATE(158)] = 11845,
  [SMALL_STATE(159)] = 11932,
  [SMALL_STATE(160)] = 12003,
  [SMALL_STATE(161)] = 12050,
  [SMALL_STATE(162)] = 12137,
  [SMALL_STATE(163)] = 12186,
  [SMALL_STATE(164)] = 12273,
  [SMALL_STATE(165)] = 12360,
  [SMALL_STATE(166)] = 12447,
  [SMALL_STATE(167)] = 12534,
  [SMALL_STATE(168)] = 12621,
  [SMALL_STATE(169)] = 12672,
  [SMALL_STATE(170)] = 12759,
  [SMALL_STATE(171)] = 12846,
  [SMALL_STATE(172)] = 12893,
  [SMALL_STATE(173)] = 12980,
  [SMALL_STATE(174)] = 13067,
  [SMALL_STATE(175)] = 13154,
  [SMALL_STATE(176)] = 13241,
  [SMALL_STATE(177)] = 13328,
  [SMALL_STATE(178)] = 13415,
  [SMALL_STATE(179)] = 13502,
  [SMALL_STATE(180)] = 13589,
  [SMALL_STATE(181)] = 13676,
  [SMALL_STATE(182)] = 13763,
  [SMALL_STATE(183)] = 13850,
  [SMALL_STATE(184)] = 13921,
  [SMALL_STATE(185)] = 13990,
  [SMALL_STATE(186)] = 14077,
  [SMALL_STATE(187)] = 14164,
  [SMALL_STATE(188)] = 14251,
  [SMALL_STATE(189)] = 14338,
  [SMALL_STATE(190)] = 14382,
  [SMALL_STATE(191)] = 14448,
  [SMALL_STATE(192)] = 14492,
  [SMALL_STATE(193)] = 14536,
  [SMALL_STATE(194)] = 14584,
  [SMALL_STATE(195)] = 14630,
  [SMALL_STATE(196)] = 14676,
  [SMALL_STATE(197)] = 14720,
  [SMALL_STATE(198)] = 14764,
  [SMALL_STATE(199)] = 14835,
  [SMALL_STATE(200)] = 14880,
  [SMALL_STATE(201)] = 14923,
  [SMALL_STATE(202)] = 14968,
  [SMALL_STATE(203)] = 15011,
  [SMALL_STATE(204)] = 15082,
  [SMALL_STATE(205)] = 15125,
  [SMALL_STATE(206)] = 15169,
  [SMALL_STATE(207)] = 15215,
  [SMALL_STATE(208)] = 15259,
  [SMALL_STATE(209)] = 15305,
  [SMALL_STATE(210)] = 15351,
  [SMALL_STATE(211)] = 15394,
  [SMALL_STATE(212)] = 15437,
  [SMALL_STATE(213)] = 15480,
  [SMALL_STATE(214)] = 15521,
  [SMALL_STATE(215)] = 15568,
  [SMALL_STATE(216)] = 15609,
  [SMALL_STATE(217)] = 15652,
  [SMALL_STATE(218)] = 15695,
  [SMALL_STATE(219)] = 15736,
  [SMALL_STATE(220)] = 15776,
  [SMALL_STATE(221)] = 15816,
  [SMALL_STATE(222)] = 15856,
  [SMALL_STATE(223)] = 15896,
  [SMALL_STATE(224)] = 15936,
  [SMALL_STATE(225)] = 15976,
  [SMALL_STATE(226)] = 16016,
  [SMALL_STATE(227)] = 16056,
  [SMALL_STATE(228)] = 16096,
  [SMALL_STATE(229)] = 16136,
  [SMALL_STATE(230)] = 16176,
  [SMALL_STATE(231)] = 16216,
  [SMALL_STATE(232)] = 16258,
  [SMALL_STATE(233)] = 16298,
  [SMALL_STATE(234)] = 16338,
  [SMALL_STATE(235)] = 16378,
  [SMALL_STATE(236)] = 16418,
  [SMALL_STATE(237)] = 16458,
  [SMALL_STATE(238)] = 16498,
  [SMALL_STATE(239)] = 16538,
  [SMALL_STATE(240)] = 16577,
  [SMALL_STATE(241)] = 16616,
  [SMALL_STATE(242)] = 16655,
  [SMALL_STATE(243)] = 16699,
  [SMALL_STATE(244)] = 16743,
  [SMALL_STATE(245)] = 16776,
  [SMALL_STATE(246)] = 16809,
  [SMALL_STATE(247)] = 16854,
  [SMALL_STATE(248)] = 16899,
  [SMALL_STATE(249)] = 16935,
  [SMALL_STATE(250)] = 16977,
  [SMALL_STATE(251)] = 17021,
  [SMALL_STATE(252)] = 17057,
  [SMALL_STATE(253)] = 17093,
  [SMALL_STATE(254)] = 17137,
  [SMALL_STATE(255)] = 17173,
  [SMALL_STATE(256)] = 17209,
  [SMALL_STATE(257)] = 17245,
  [SMALL_STATE(258)] = 17284,
  [SMALL_STATE(259)] = 17331,
  [SMALL_STATE(260)] = 17370,
  [SMALL_STATE(261)] = 17414,
  [SMALL_STATE(262)] = 17446,
  [SMALL_STATE(263)] = 17490,
  [SMALL_STATE(264)] = 17522,
  [SMALL_STATE(265)] = 17556,
  [SMALL_STATE(266)] = 17600,
  [SMALL_STATE(267)] = 17634,
  [SMALL_STATE(268)] = 17669,
  [SMALL_STATE(269)] = 17706,
  [SMALL_STATE(270)] = 17741,
  [SMALL_STATE(271)] = 17770,
  [SMALL_STATE(272)] = 17809,
  [SMALL_STATE(273)] = 17848,
  [SMALL_STATE(274)] = 17899,
  [SMALL_STATE(275)] = 17928,
  [SMALL_STATE(276)] = 17959,
  [SMALL_STATE(277)] = 17994,
  [SMALL_STATE(278)] = 18029,
  [SMALL_STATE(279)] = 18078,
  [SMALL_STATE(280)] = 18107,
  [SMALL_STATE(281)] = 18136,
  [SMALL_STATE(282)] = 18171,
  [SMALL_STATE(283)] = 18199,
  [SMALL_STATE(284)] = 18231,
  [SMALL_STATE(285)] = 18259,
  [SMALL_STATE(286)] = 18295,
  [SMALL_STATE(287)] = 18327,
  [SMALL_STATE(288)] = 18361,
  [SMALL_STATE(289)] = 18393,
  [SMALL_STATE(290)] = 18423,
  [SMALL_STATE(291)] = 18455,
  [SMALL_STATE(292)] = 18487,
  [SMALL_STATE(293)] = 18521,
  [SMALL_STATE(294)] = 18553,
  [SMALL_STATE(295)] = 18585,
  [SMALL_STATE(296)] = 18613,
  [SMALL_STATE(297)] = 18658,
  [SMALL_STATE(298)] = 18703,
  [SMALL_STATE(299)] = 18732,
  [SMALL_STATE(300)] = 18757,
  [SMALL_STATE(301)] = 18802,
  [SMALL_STATE(302)] = 18847,
  [SMALL_STATE(303)] = 18878,
  [SMALL_STATE(304)] = 18911,
  [SMALL_STATE(305)] = 18941,
  [SMALL_STATE(306)] = 18971,
  [SMALL_STATE(307)] = 19001,
  [SMALL_STATE(308)] = 19031,
  [SMALL_STATE(309)] = 19061,
  [SMALL_STATE(310)] = 19091,
  [SMALL_STATE(311)] = 19133,
  [SMALL_STATE(312)] = 19163,
  [SMALL_STATE(313)] = 19193,
  [SMALL_STATE(314)] = 19232,
  [SMALL_STATE(315)] = 19255,
  [SMALL_STATE(316)] = 19294,
  [SMALL_STATE(317)] = 19317,
  [SMALL_STATE(318)] = 19356,
  [SMALL_STATE(319)] = 19379,
  [SMALL_STATE(320)] = 19408,
  [SMALL_STATE(321)] = 19447,
  [SMALL_STATE(322)] = 19486,
  [SMALL_STATE(323)] = 19509,
  [SMALL_STATE(324)] = 19548,
  [SMALL_STATE(325)] = 19589,
  [SMALL_STATE(326)] = 19612,
  [SMALL_STATE(327)] = 19638,
  [SMALL_STATE(328)] = 19674,
  [SMALL_STATE(329)] = 19702,
  [SMALL_STATE(330)] = 19726,
  [SMALL_STATE(331)] = 19747,
  [SMALL_STATE(332)] = 19768,
  [SMALL_STATE(333)] = 19791,
  [SMALL_STATE(334)] = 19816,
  [SMALL_STATE(335)] = 19839,
  [SMALL_STATE(336)] = 19864,
  [SMALL_STATE(337)] = 19885,
  [SMALL_STATE(338)] = 19908,
  [SMALL_STATE(339)] = 19943,
  [SMALL_STATE(340)] = 19964,
  [SMALL_STATE(341)] = 19985,
  [SMALL_STATE(342)] = 20008,
  [SMALL_STATE(343)] = 20031,
  [SMALL_STATE(344)] = 20056,
  [SMALL_STATE(345)] = 20077,
  [SMALL_STATE(346)] = 20102,
  [SMALL_STATE(347)] = 20122,
  [SMALL_STATE(348)] = 20142,
  [SMALL_STATE(349)] = 20162,
  [SMALL_STATE(350)] = 20194,
  [SMALL_STATE(351)] = 20224,
  [SMALL_STATE(352)] = 20244,
  [SMALL_STATE(353)] = 20264,
  [SMALL_STATE(354)] = 20284,
  [SMALL_STATE(355)] = 20306,
  [SMALL_STATE(356)] = 20326,
  [SMALL_STATE(357)] = 20358,
  [SMALL_STATE(358)] = 20380,
  [SMALL_STATE(359)] = 20400,
  [SMALL_STATE(360)] = 20430,
  [SMALL_STATE(361)] = 20450,
  [SMALL_STATE(362)] = 20480,
  [SMALL_STATE(363)] = 20512,
  [SMALL_STATE(364)] = 20540,
  [SMALL_STATE(365)] = 20560,
  [SMALL_STATE(366)] = 20590,
  [SMALL_STATE(367)] = 20610,
  [SMALL_STATE(368)] = 20630,
  [SMALL_STATE(369)] = 20660,
  [SMALL_STATE(370)] = 20680,
  [SMALL_STATE(371)] = 20704,
  [SMALL_STATE(372)] = 20728,
  [SMALL_STATE(373)] = 20748,
  [SMALL_STATE(374)] = 20768,
  [SMALL_STATE(375)] = 20792,
  [SMALL_STATE(376)] = 20821,
  [SMALL_STATE(377)] = 20850,
  [SMALL_STATE(378)] = 20879,
  [SMALL_STATE(379)] = 20908,
  [SMALL_STATE(380)] = 20929,
  [SMALL_STATE(381)] = 20950,
  [SMALL_STATE(382)] = 20979,
  [SMALL_STATE(383)] = 21008,
  [SMALL_STATE(384)] = 21037,
  [SMALL_STATE(385)] = 21066,
  [SMALL_STATE(386)] = 21089,
  [SMALL_STATE(387)] = 21116,
  [SMALL_STATE(388)] = 21145,
  [SMALL_STATE(389)] = 21174,
  [SMALL_STATE(390)] = 21203,
  [SMALL_STATE(391)] = 21230,
  [SMALL_STATE(392)] = 21259,
  [SMALL_STATE(393)] = 21278,
  [SMALL_STATE(394)] = 21297,
  [SMALL_STATE(395)] = 21326,
  [SMALL_STATE(396)] = 21355,
  [SMALL_STATE(397)] = 21384,
  [SMALL_STATE(398)] = 21413,
  [SMALL_STATE(399)] = 21432,
  [SMALL_STATE(400)] = 21458,
  [SMALL_STATE(401)] = 21476,
  [SMALL_STATE(402)] = 21494,
  [SMALL_STATE(403)] = 21520,
  [SMALL_STATE(404)] = 21546,
  [SMALL_STATE(405)] = 21572,
  [SMALL_STATE(406)] = 21592,
  [SMALL_STATE(407)] = 21614,
  [SMALL_STATE(408)] = 21640,
  [SMALL_STATE(409)] = 21660,
  [SMALL_STATE(410)] = 21680,
  [SMALL_STATE(411)] = 21700,
  [SMALL_STATE(412)] = 21720,
  [SMALL_STATE(413)] = 21746,
  [SMALL_STATE(414)] = 21770,
  [SMALL_STATE(415)] = 21788,
  [SMALL_STATE(416)] = 21812,
  [SMALL_STATE(417)] = 21834,
  [SMALL_STATE(418)] = 21854,
  [SMALL_STATE(419)] = 21872,
  [SMALL_STATE(420)] = 21898,
  [SMALL_STATE(421)] = 21922,
  [SMALL_STATE(422)] = 21948,
  [SMALL_STATE(423)] = 21966,
  [SMALL_STATE(424)] = 21984,
  [SMALL_STATE(425)] = 22010,
  [SMALL_STATE(426)] = 22032,
  [SMALL_STATE(427)] = 22050,
  [SMALL_STATE(428)] = 22069,
  [SMALL_STATE(429)] = 22088,
  [SMALL_STATE(430)] = 22111,
  [SMALL_STATE(431)] = 22130,
  [SMALL_STATE(432)] = 22153,
  [SMALL_STATE(433)] = 22172,
  [SMALL_STATE(434)] = 22193,
  [SMALL_STATE(435)] = 22212,
  [SMALL_STATE(436)] = 22231,
  [SMALL_STATE(437)] = 22250,
  [SMALL_STATE(438)] = 22267,
  [SMALL_STATE(439)] = 22288,
  [SMALL_STATE(440)] = 22309,
  [SMALL_STATE(441)] = 22328,
  [SMALL_STATE(442)] = 22349,
  [SMALL_STATE(443)] = 22368,
  [SMALL_STATE(444)] = 22391,
  [SMALL_STATE(445)] = 22410,
  [SMALL_STATE(446)] = 22431,
  [SMALL_STATE(447)] = 22450,
  [SMALL_STATE(448)] = 22469,
  [SMALL_STATE(449)] = 22490,
  [SMALL_STATE(450)] = 22513,
  [SMALL_STATE(451)] = 22534,
  [SMALL_STATE(452)] = 22557,
  [SMALL_STATE(453)] = 22576,
  [SMALL_STATE(454)] = 22599,
  [SMALL_STATE(455)] = 22618,
  [SMALL_STATE(456)] = 22637,
  [SMALL_STATE(457)] = 22660,
  [SMALL_STATE(458)] = 22683,
  [SMALL_STATE(459)] = 22704,
  [SMALL_STATE(460)] = 22727,
  [SMALL_STATE(461)] = 22746,
  [SMALL_STATE(462)] = 22765,
  [SMALL_STATE(463)] = 22788,
  [SMALL_STATE(464)] = 22811,
  [SMALL_STATE(465)] = 22830,
  [SMALL_STATE(466)] = 22849,
  [SMALL_STATE(467)] = 22872,
  [SMALL_STATE(468)] = 22895,
  [SMALL_STATE(469)] = 22914,
  [SMALL_STATE(470)] = 22933,
  [SMALL_STATE(471)] = 22956,
  [SMALL_STATE(472)] = 22977,
  [SMALL_STATE(473)] = 22996,
  [SMALL_STATE(474)] = 23013,
  [SMALL_STATE(475)] = 23032,
  [SMALL_STATE(476)] = 23051,
  [SMALL_STATE(477)] = 23068,
  [SMALL_STATE(478)] = 23085,
  [SMALL_STATE(479)] = 23103,
  [SMALL_STATE(480)] = 23121,
  [SMALL_STATE(481)] = 23141,
  [SMALL_STATE(482)] = 23161,
  [SMALL_STATE(483)] = 23177,
  [SMALL_STATE(484)] = 23199,
  [SMALL_STATE(485)] = 23219,
  [SMALL_STATE(486)] = 23237,
  [SMALL_STATE(487)] = 23257,
  [SMALL_STATE(488)] = 23277,
  [SMALL_STATE(489)] = 23297,
  [SMALL_STATE(490)] = 23317,
  [SMALL_STATE(491)] = 23337,
  [SMALL_STATE(492)] = 23355,
  [SMALL_STATE(493)] = 23373,
  [SMALL_STATE(494)] = 23391,
  [SMALL_STATE(495)] = 23407,
  [SMALL_STATE(496)] = 23427,
  [SMALL_STATE(497)] = 23443,
  [SMALL_STATE(498)] = 23463,
  [SMALL_STATE(499)] = 23479,
  [SMALL_STATE(500)] = 23495,
  [SMALL_STATE(501)] = 23515,
  [SMALL_STATE(502)] = 23535,
  [SMALL_STATE(503)] = 23551,
  [SMALL_STATE(504)] = 23573,
  [SMALL_STATE(505)] = 23589,
  [SMALL_STATE(506)] = 23611,
  [SMALL_STATE(507)] = 23629,
  [SMALL_STATE(508)] = 23647,
  [SMALL_STATE(509)] = 23663,
  [SMALL_STATE(510)] = 23683,
  [SMALL_STATE(511)] = 23703,
  [SMALL_STATE(512)] = 23723,
  [SMALL_STATE(513)] = 23739,
  [SMALL_STATE(514)] = 23757,
  [SMALL_STATE(515)] = 23777,
  [SMALL_STATE(516)] = 23797,
  [SMALL_STATE(517)] = 23817,
  [SMALL_STATE(518)] = 23835,
  [SMALL_STATE(519)] = 23853,
  [SMALL_STATE(520)] = 23873,
  [SMALL_STATE(521)] = 23893,
  [SMALL_STATE(522)] = 23911,
  [SMALL_STATE(523)] = 23931,
  [SMALL_STATE(524)] = 23951,
  [SMALL_STATE(525)] = 23967,
  [SMALL_STATE(526)] = 23985,
  [SMALL_STATE(527)] = 24001,
  [SMALL_STATE(528)] = 24021,
  [SMALL_STATE(529)] = 24041,
  [SMALL_STATE(530)] = 24059,
  [SMALL_STATE(531)] = 24079,
  [SMALL_STATE(532)] = 24101,
  [SMALL_STATE(533)] = 24117,
  [SMALL_STATE(534)] = 24133,
  [SMALL_STATE(535)] = 24151,
  [SMALL_STATE(536)] = 24171,
  [SMALL_STATE(537)] = 24191,
  [SMALL_STATE(538)] = 24209,
  [SMALL_STATE(539)] = 24225,
  [SMALL_STATE(540)] = 24245,
  [SMALL_STATE(541)] = 24263,
  [SMALL_STATE(542)] = 24283,
  [SMALL_STATE(543)] = 24301,
  [SMALL_STATE(544)] = 24321,
  [SMALL_STATE(545)] = 24341,
  [SMALL_STATE(546)] = 24359,
  [SMALL_STATE(547)] = 24379,
  [SMALL_STATE(548)] = 24399,
  [SMALL_STATE(549)] = 24419,
  [SMALL_STATE(550)] = 24439,
  [SMALL_STATE(551)] = 24457,
  [SMALL_STATE(552)] = 24473,
  [SMALL_STATE(553)] = 24491,
  [SMALL_STATE(554)] = 24511,
  [SMALL_STATE(555)] = 24529,
  [SMALL_STATE(556)] = 24545,
  [SMALL_STATE(557)] = 24563,
  [SMALL_STATE(558)] = 24579,
  [SMALL_STATE(559)] = 24599,
  [SMALL_STATE(560)] = 24619,
  [SMALL_STATE(561)] = 24639,
  [SMALL_STATE(562)] = 24661,
  [SMALL_STATE(563)] = 24679,
  [SMALL_STATE(564)] = 24699,
  [SMALL_STATE(565)] = 24719,
  [SMALL_STATE(566)] = 24737,
  [SMALL_STATE(567)] = 24757,
  [SMALL_STATE(568)] = 24775,
  [SMALL_STATE(569)] = 24793,
  [SMALL_STATE(570)] = 24809,
  [SMALL_STATE(571)] = 24829,
  [SMALL_STATE(572)] = 24849,
  [SMALL_STATE(573)] = 24871,
  [SMALL_STATE(574)] = 24891,
  [SMALL_STATE(575)] = 24907,
  [SMALL_STATE(576)] = 24925,
  [SMALL_STATE(577)] = 24943,
  [SMALL_STATE(578)] = 24963,
  [SMALL_STATE(579)] = 24981,
  [SMALL_STATE(580)] = 24999,
  [SMALL_STATE(581)] = 25014,
  [SMALL_STATE(582)] = 25031,
  [SMALL_STATE(583)] = 25046,
  [SMALL_STATE(584)] = 25063,
  [SMALL_STATE(585)] = 25080,
  [SMALL_STATE(586)] = 25095,
  [SMALL_STATE(587)] = 25112,
  [SMALL_STATE(588)] = 25129,
  [SMALL_STATE(589)] = 25146,
  [SMALL_STATE(590)] = 25163,
  [SMALL_STATE(591)] = 25178,
  [SMALL_STATE(592)] = 25193,
  [SMALL_STATE(593)] = 25208,
  [SMALL_STATE(594)] = 25225,
  [SMALL_STATE(595)] = 25240,
  [SMALL_STATE(596)] = 25257,
  [SMALL_STATE(597)] = 25272,
  [SMALL_STATE(598)] = 25289,
  [SMALL_STATE(599)] = 25306,
  [SMALL_STATE(600)] = 25323,
  [SMALL_STATE(601)] = 25338,
  [SMALL_STATE(602)] = 25355,
  [SMALL_STATE(603)] = 25370,
  [SMALL_STATE(604)] = 25387,
  [SMALL_STATE(605)] = 25404,
  [SMALL_STATE(606)] = 25421,
  [SMALL_STATE(607)] = 25436,
  [SMALL_STATE(608)] = 25453,
  [SMALL_STATE(609)] = 25470,
  [SMALL_STATE(610)] = 25487,
  [SMALL_STATE(611)] = 25504,
  [SMALL_STATE(612)] = 25519,
  [SMALL_STATE(613)] = 25534,
  [SMALL_STATE(614)] = 25549,
  [SMALL_STATE(615)] = 25564,
  [SMALL_STATE(616)] = 25579,
  [SMALL_STATE(617)] = 25596,
  [SMALL_STATE(618)] = 25611,
  [SMALL_STATE(619)] = 25626,
  [SMALL_STATE(620)] = 25643,
  [SMALL_STATE(621)] = 25658,
  [SMALL_STATE(622)] = 25673,
  [SMALL_STATE(623)] = 25688,
  [SMALL_STATE(624)] = 25703,
  [SMALL_STATE(625)] = 25718,
  [SMALL_STATE(626)] = 25735,
  [SMALL_STATE(627)] = 25752,
  [SMALL_STATE(628)] = 25767,
  [SMALL_STATE(629)] = 25784,
  [SMALL_STATE(630)] = 25801,
  [SMALL_STATE(631)] = 25818,
  [SMALL_STATE(632)] = 25835,
  [SMALL_STATE(633)] = 25850,
  [SMALL_STATE(634)] = 25865,
  [SMALL_STATE(635)] = 25882,
  [SMALL_STATE(636)] = 25899,
  [SMALL_STATE(637)] = 25916,
  [SMALL_STATE(638)] = 25931,
  [SMALL_STATE(639)] = 25948,
  [SMALL_STATE(640)] = 25963,
  [SMALL_STATE(641)] = 25980,
  [SMALL_STATE(642)] = 25995,
  [SMALL_STATE(643)] = 26012,
  [SMALL_STATE(644)] = 26029,
  [SMALL_STATE(645)] = 26046,
  [SMALL_STATE(646)] = 26063,
  [SMALL_STATE(647)] = 26080,
  [SMALL_STATE(648)] = 26094,
  [SMALL_STATE(649)] = 26108,
  [SMALL_STATE(650)] = 26122,
  [SMALL_STATE(651)] = 26136,
  [SMALL_STATE(652)] = 26150,
  [SMALL_STATE(653)] = 26164,
  [SMALL_STATE(654)] = 26178,
  [SMALL_STATE(655)] = 26192,
  [SMALL_STATE(656)] = 26206,
  [SMALL_STATE(657)] = 26220,
  [SMALL_STATE(658)] = 26234,
  [SMALL_STATE(659)] = 26248,
  [SMALL_STATE(660)] = 26262,
  [SMALL_STATE(661)] = 26276,
  [SMALL_STATE(662)] = 26290,
  [SMALL_STATE(663)] = 26304,
  [SMALL_STATE(664)] = 26318,
  [SMALL_STATE(665)] = 26332,
  [SMALL_STATE(666)] = 26346,
  [SMALL_STATE(667)] = 26360,
  [SMALL_STATE(668)] = 26374,
  [SMALL_STATE(669)] = 26388,
  [SMALL_STATE(670)] = 26402,
  [SMALL_STATE(671)] = 26416,
  [SMALL_STATE(672)] = 26430,
  [SMALL_STATE(673)] = 26444,
  [SMALL_STATE(674)] = 26458,
  [SMALL_STATE(675)] = 26472,
  [SMALL_STATE(676)] = 26486,
  [SMALL_STATE(677)] = 26500,
  [SMALL_STATE(678)] = 26514,
  [SMALL_STATE(679)] = 26528,
  [SMALL_STATE(680)] = 26542,
  [SMALL_STATE(681)] = 26556,
  [SMALL_STATE(682)] = 26570,
  [SMALL_STATE(683)] = 26584,
  [SMALL_STATE(684)] = 26598,
  [SMALL_STATE(685)] = 26612,
  [SMALL_STATE(686)] = 26626,
  [SMALL_STATE(687)] = 26640,
  [SMALL_STATE(688)] = 26654,
  [SMALL_STATE(689)] = 26668,
  [SMALL_STATE(690)] = 26682,
  [SMALL_STATE(691)] = 26696,
  [SMALL_STATE(692)] = 26710,
  [SMALL_STATE(693)] = 26724,
  [SMALL_STATE(694)] = 26738,
  [SMALL_STATE(695)] = 26752,
  [SMALL_STATE(696)] = 26766,
  [SMALL_STATE(697)] = 26780,
  [SMALL_STATE(698)] = 26794,
  [SMALL_STATE(699)] = 26808,
  [SMALL_STATE(700)] = 26822,
  [SMALL_STATE(701)] = 26836,
  [SMALL_STATE(702)] = 26850,
  [SMALL_STATE(703)] = 26864,
  [SMALL_STATE(704)] = 26878,
  [SMALL_STATE(705)] = 26892,
  [SMALL_STATE(706)] = 26906,
  [SMALL_STATE(707)] = 26920,
  [SMALL_STATE(708)] = 26934,
  [SMALL_STATE(709)] = 26948,
  [SMALL_STATE(710)] = 26962,
  [SMALL_STATE(711)] = 26976,
  [SMALL_STATE(712)] = 26990,
  [SMALL_STATE(713)] = 27004,
  [SMALL_STATE(714)] = 27018,
  [SMALL_STATE(715)] = 27032,
  [SMALL_STATE(716)] = 27046,
  [SMALL_STATE(717)] = 27060,
  [SMALL_STATE(718)] = 27074,
  [SMALL_STATE(719)] = 27088,
  [SMALL_STATE(720)] = 27102,
  [SMALL_STATE(721)] = 27116,
  [SMALL_STATE(722)] = 27130,
  [SMALL_STATE(723)] = 27144,
  [SMALL_STATE(724)] = 27158,
  [SMALL_STATE(725)] = 27172,
  [SMALL_STATE(726)] = 27186,
  [SMALL_STATE(727)] = 27200,
  [SMALL_STATE(728)] = 27214,
  [SMALL_STATE(729)] = 27228,
  [SMALL_STATE(730)] = 27242,
  [SMALL_STATE(731)] = 27256,
  [SMALL_STATE(732)] = 27270,
  [SMALL_STATE(733)] = 27284,
  [SMALL_STATE(734)] = 27298,
  [SMALL_STATE(735)] = 27312,
  [SMALL_STATE(736)] = 27326,
  [SMALL_STATE(737)] = 27340,
  [SMALL_STATE(738)] = 27354,
  [SMALL_STATE(739)] = 27368,
  [SMALL_STATE(740)] = 27382,
  [SMALL_STATE(741)] = 27396,
  [SMALL_STATE(742)] = 27410,
  [SMALL_STATE(743)] = 27424,
  [SMALL_STATE(744)] = 27438,
  [SMALL_STATE(745)] = 27452,
  [SMALL_STATE(746)] = 27466,
  [SMALL_STATE(747)] = 27480,
  [SMALL_STATE(748)] = 27494,
  [SMALL_STATE(749)] = 27508,
  [SMALL_STATE(750)] = 27522,
  [SMALL_STATE(751)] = 27536,
  [SMALL_STATE(752)] = 27550,
  [SMALL_STATE(753)] = 27564,
  [SMALL_STATE(754)] = 27578,
  [SMALL_STATE(755)] = 27592,
  [SMALL_STATE(756)] = 27606,
  [SMALL_STATE(757)] = 27620,
  [SMALL_STATE(758)] = 27634,
  [SMALL_STATE(759)] = 27648,
  [SMALL_STATE(760)] = 27662,
  [SMALL_STATE(761)] = 27676,
  [SMALL_STATE(762)] = 27690,
  [SMALL_STATE(763)] = 27704,
  [SMALL_STATE(764)] = 27718,
  [SMALL_STATE(765)] = 27732,
  [SMALL_STATE(766)] = 27746,
  [SMALL_STATE(767)] = 27760,
  [SMALL_STATE(768)] = 27774,
  [SMALL_STATE(769)] = 27788,
  [SMALL_STATE(770)] = 27802,
  [SMALL_STATE(771)] = 27816,
  [SMALL_STATE(772)] = 27830,
  [SMALL_STATE(773)] = 27844,
  [SMALL_STATE(774)] = 27858,
  [SMALL_STATE(775)] = 27872,
  [SMALL_STATE(776)] = 27886,
  [SMALL_STATE(777)] = 27900,
  [SMALL_STATE(778)] = 27914,
  [SMALL_STATE(779)] = 27928,
  [SMALL_STATE(780)] = 27942,
  [SMALL_STATE(781)] = 27956,
  [SMALL_STATE(782)] = 27970,
  [SMALL_STATE(783)] = 27984,
  [SMALL_STATE(784)] = 27998,
  [SMALL_STATE(785)] = 28012,
  [SMALL_STATE(786)] = 28026,
  [SMALL_STATE(787)] = 28040,
  [SMALL_STATE(788)] = 28054,
  [SMALL_STATE(789)] = 28068,
  [SMALL_STATE(790)] = 28082,
  [SMALL_STATE(791)] = 28096,
  [SMALL_STATE(792)] = 28110,
  [SMALL_STATE(793)] = 28124,
  [SMALL_STATE(794)] = 28138,
  [SMALL_STATE(795)] = 28152,
  [SMALL_STATE(796)] = 28166,
  [SMALL_STATE(797)] = 28180,
  [SMALL_STATE(798)] = 28194,
  [SMALL_STATE(799)] = 28208,
  [SMALL_STATE(800)] = 28222,
  [SMALL_STATE(801)] = 28236,
  [SMALL_STATE(802)] = 28250,
  [SMALL_STATE(803)] = 28264,
  [SMALL_STATE(804)] = 28278,
  [SMALL_STATE(805)] = 28292,
  [SMALL_STATE(806)] = 28306,
  [SMALL_STATE(807)] = 28320,
  [SMALL_STATE(808)] = 28334,
  [SMALL_STATE(809)] = 28348,
  [SMALL_STATE(810)] = 28362,
  [SMALL_STATE(811)] = 28376,
  [SMALL_STATE(812)] = 28390,
  [SMALL_STATE(813)] = 28404,
  [SMALL_STATE(814)] = 28418,
  [SMALL_STATE(815)] = 28432,
  [SMALL_STATE(816)] = 28446,
  [SMALL_STATE(817)] = 28460,
  [SMALL_STATE(818)] = 28474,
  [SMALL_STATE(819)] = 28488,
  [SMALL_STATE(820)] = 28502,
  [SMALL_STATE(821)] = 28516,
  [SMALL_STATE(822)] = 28530,
  [SMALL_STATE(823)] = 28544,
  [SMALL_STATE(824)] = 28558,
  [SMALL_STATE(825)] = 28572,
  [SMALL_STATE(826)] = 28586,
  [SMALL_STATE(827)] = 28600,
  [SMALL_STATE(828)] = 28614,
  [SMALL_STATE(829)] = 28628,
  [SMALL_STATE(830)] = 28642,
  [SMALL_STATE(831)] = 28656,
  [SMALL_STATE(832)] = 28670,
  [SMALL_STATE(833)] = 28684,
  [SMALL_STATE(834)] = 28698,
  [SMALL_STATE(835)] = 28712,
  [SMALL_STATE(836)] = 28726,
  [SMALL_STATE(837)] = 28740,
  [SMALL_STATE(838)] = 28754,
  [SMALL_STATE(839)] = 28768,
  [SMALL_STATE(840)] = 28782,
  [SMALL_STATE(841)] = 28796,
  [SMALL_STATE(842)] = 28810,
  [SMALL_STATE(843)] = 28824,
  [SMALL_STATE(844)] = 28838,
  [SMALL_STATE(845)] = 28852,
  [SMALL_STATE(846)] = 28866,
  [SMALL_STATE(847)] = 28880,
  [SMALL_STATE(848)] = 28894,
  [SMALL_STATE(849)] = 28908,
  [SMALL_STATE(850)] = 28922,
  [SMALL_STATE(851)] = 28936,
  [SMALL_STATE(852)] = 28950,
  [SMALL_STATE(853)] = 28964,
  [SMALL_STATE(854)] = 28978,
  [SMALL_STATE(855)] = 28992,
  [SMALL_STATE(856)] = 29006,
  [SMALL_STATE(857)] = 29020,
  [SMALL_STATE(858)] = 29034,
  [SMALL_STATE(859)] = 29048,
  [SMALL_STATE(860)] = 29062,
  [SMALL_STATE(861)] = 29076,
  [SMALL_STATE(862)] = 29090,
  [SMALL_STATE(863)] = 29104,
  [SMALL_STATE(864)] = 29118,
  [SMALL_STATE(865)] = 29132,
  [SMALL_STATE(866)] = 29146,
  [SMALL_STATE(867)] = 29160,
  [SMALL_STATE(868)] = 29174,
  [SMALL_STATE(869)] = 29188,
  [SMALL_STATE(870)] = 29202,
  [SMALL_STATE(871)] = 29216,
  [SMALL_STATE(872)] = 29230,
  [SMALL_STATE(873)] = 29244,
  [SMALL_STATE(874)] = 29258,
  [SMALL_STATE(875)] = 29272,
  [SMALL_STATE(876)] = 29286,
  [SMALL_STATE(877)] = 29300,
  [SMALL_STATE(878)] = 29314,
  [SMALL_STATE(879)] = 29328,
  [SMALL_STATE(880)] = 29332,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(466),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(481),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(866),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(526),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(810),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(361),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(807),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(482),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(803),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(468),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(796),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(795),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(794),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(793),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(792),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(791),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(790),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(789),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(469),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(402),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(538),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_repeat1, 2),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(810),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(118),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(117),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(116),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(361),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(807),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(482),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(803),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(468),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(796),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(795),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(794),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(793),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(792),
  [105] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(791),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(790),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(789),
  [114] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(107),
  [117] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(469),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(402),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_body_repeat1, 2), SHIFT_REPEAT(72),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_global_accum_name, 2),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_global_accum_name, 2),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name_dot, 3),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name_dot, 3),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(806),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat2, 2),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_func_call_stmt_repeat2, 2),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat2, 2), SHIFT_REPEAT(871),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_name_dot_repeat1, 2),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_name_dot_repeat1, 2),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_name_dot_repeat1, 2), SHIFT_REPEAT(801),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 1),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 1),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(871),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_set_bag_expr, 1),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_set_bag_expr, 1),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(737),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_set_bag_expr, 2),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_set_bag_expr, 2),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name_dot, 4),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name_dot, 4),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat2, 4),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_func_call_stmt_repeat2, 4),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(510),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_local_accum_name, 2),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_local_accum_name, 2),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat2, 5),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_func_call_stmt_repeat2, 5),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(397),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_set_bag_expr, 3),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_set_bag_expr, 3),
  [196] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat2, 2), SHIFT_REPEAT(737),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat1, 2),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_accum_type_repeat1, 2),
  [203] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat1, 2), SHIFT_REPEAT(47),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_call_stmt, 2),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_call_stmt, 2),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_real, 2), REDUCE(sym_real, 3),
  [213] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_real, 2), REDUCE(sym_real, 3),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_real, 2),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_real, 2),
  [222] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_integer, 1), REDUCE(sym_integer, 2),
  [225] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_integer, 1), REDUCE(sym_integer, 2),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(773),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 6),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 6),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(671),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 5),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 5),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(715),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat1, 1),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_accum_type_repeat1, 1),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer, 1),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer, 1),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(714),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 10),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 10),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__numeric, 1),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__numeric, 1),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 1),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant, 1),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_call_stmt, 4),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_call_stmt, 4),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_real, 3),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_real, 3),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 11),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 11),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_call_stmt, 3),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_call_stmt, 3),
  [288] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_real, 3), REDUCE(sym_real, 4),
  [291] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_real, 3), REDUCE(sym_real, 4),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 7),
  [296] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 7),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_call_stmt, 8),
  [300] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_call_stmt, 8),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_call_stmt, 6),
  [304] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_call_stmt, 6),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_call_stmt, 7),
  [308] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_call_stmt, 7),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 3),
  [312] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 3),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 4),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 4),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 8),
  [320] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 8),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_stmt, 2),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_query_body_stmt, 2),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typedef, 7, .production_id = 18),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typedef, 7, .production_id = 18),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(368),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(629),
  [336] = {.entry = {.count = 1, .reusable = false}}, SHIFT(670),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [342] = {.entry = {.count = 1, .reusable = false}}, SHIFT(759),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(758),
  [346] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [348] = {.entry = {.count = 1, .reusable = false}}, SHIFT(757),
  [350] = {.entry = {.count = 1, .reusable = false}}, SHIFT(247),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(505),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(755),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typedef, 6, .production_id = 15),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typedef, 6, .production_id = 15),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_repeat1, 1),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_query_body_repeat1, 1),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(563),
  [370] = {.entry = {.count = 1, .reusable = false}}, SHIFT(291),
  [372] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [374] = {.entry = {.count = 1, .reusable = false}}, SHIFT(584),
  [376] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [378] = {.entry = {.count = 1, .reusable = false}}, SHIFT(350),
  [380] = {.entry = {.count = 1, .reusable = false}}, SHIFT(419),
  [382] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(645),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(843),
  [394] = {.entry = {.count = 1, .reusable = false}}, SHIFT(854),
  [396] = {.entry = {.count = 1, .reusable = false}}, SHIFT(869),
  [398] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [400] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [402] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [404] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(483),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(855),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [416] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [424] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [426] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 1),
  [432] = {.entry = {.count = 1, .reusable = false}}, SHIFT(245),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(395),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(583),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(595),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [446] = {.entry = {.count = 1, .reusable = false}}, SHIFT(244),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [456] = {.entry = {.count = 1, .reusable = false}}, SHIFT(242),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [466] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [488] = {.entry = {.count = 1, .reusable = false}}, SHIFT(243),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 2),
  [492] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr, 2),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(528),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(828),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(877),
  [504] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_name_dot_repeat1, 2), SHIFT_REPEAT(829),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(876),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(616),
  [511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(599),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [519] = {.entry = {.count = 1, .reusable = false}}, SHIFT(494),
  [521] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat2, 2), SHIFT_REPEAT(877),
  [524] = {.entry = {.count = 1, .reusable = false}}, SHIFT(856),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(501),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_list, 1),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(382),
  [534] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat1, 2), SHIFT_REPEAT(218),
  [537] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat2, 2), SHIFT_REPEAT(876),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [542] = {.entry = {.count = 1, .reusable = true}}, SHIFT(812),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(850),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(820),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(836),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 3),
  [552] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 5),
  [554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 4),
  [556] = {.entry = {.count = 1, .reusable = false}}, SHIFT(293),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_set, 1),
  [560] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_math_operator, 1),
  [562] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_math_operator, 1),
  [564] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comparison_operator, 1),
  [566] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comparison_operator, 1),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(771),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(770),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(482),
  [574] = {.entry = {.count = 1, .reusable = true}}, SHIFT(469),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(859),
  [578] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_g_accum_accum_stmt, 3, .production_id = 2),
  [580] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_typedef_repeat1, 2),
  [582] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_typedef_repeat1, 2), SHIFT_REPEAT(482),
  [585] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_typedef_repeat1, 2), SHIFT_REPEAT(469),
  [588] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_typedef_repeat1, 2), SHIFT_REPEAT(298),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(722),
  [593] = {.entry = {.count = 1, .reusable = false}}, SHIFT(298),
  [595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_l_accum_accum_stmt, 5, .production_id = 24),
  [597] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attr_accum_stmt, 5, .production_id = 24),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(648),
  [601] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_stmt, 3),
  [603] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_stmt, 5),
  [605] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_local_var_decl_stmt, 4, .production_id = 21),
  [607] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_expr, 1),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(656),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(807),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(803),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(468),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(796),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(795),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(794),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(793),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(792),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(791),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(643),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [635] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tuple_fields_repeat1, 2), SHIFT_REPEAT(281),
  [638] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tuple_fields_repeat1, 2),
  [640] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tuple_fields_repeat1, 2),
  [642] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_type, 1),
  [644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(857),
  [646] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_base_type, 1),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [650] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_fields, 2),
  [652] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_fields, 2),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_fields, 1),
  [656] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_fields, 1),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(365),
  [664] = {.entry = {.count = 1, .reusable = false}}, SHIFT(409),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(848),
  [668] = {.entry = {.count = 1, .reusable = false}}, SHIFT(411),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(429),
  [672] = {.entry = {.count = 1, .reusable = false}}, SHIFT(344),
  [674] = {.entry = {.count = 1, .reusable = false}}, SHIFT(342),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_field, 2),
  [678] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_field, 2),
  [680] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_type, 4),
  [682] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_base_type, 4),
  [684] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arg_list_repeat1, 2),
  [686] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_typedef_repeat1, 1),
  [688] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_typedef_repeat1, 1),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(730),
  [692] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_decl_stmt, 4),
  [694] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_v_set_proj, 1),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(849),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [700] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_clause, 2),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [708] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_base_decl_stmt_repeat1, 4),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [712] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_g_accum_assign_stmt, 3),
  [714] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_l_accum_assign_stmt, 5, .production_id = 10),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [718] = {.entry = {.count = 1, .reusable = true}}, SHIFT(716),
  [720] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [724] = {.entry = {.count = 1, .reusable = false}}, SHIFT(316),
  [726] = {.entry = {.count = 1, .reusable = true}}, SHIFT(644),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_clause, 4),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(451),
  [732] = {.entry = {.count = 1, .reusable = false}}, SHIFT(632),
  [734] = {.entry = {.count = 1, .reusable = false}}, SHIFT(633),
  [736] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vertex_set_type, 1),
  [738] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_v_accum_func_call, 3, .production_id = 16),
  [740] = {.entry = {.count = 1, .reusable = true}}, SHIFT(678),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [744] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql_select_block, 2),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [754] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 2),
  [756] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_v_accum_func_call, 4, .production_id = 20),
  [758] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path_pattern, 1),
  [760] = {.entry = {.count = 1, .reusable = true}}, SHIFT(708),
  [762] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_v_accum_func_call_repeat1, 2, .production_id = 25),
  [764] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_v_accum_func_call_repeat1, 2, .production_id = 25), SHIFT_REPEAT(678),
  [767] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_vertex_types, 3),
  [769] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_v_accum_func_call_repeat1, 4, .production_id = 26),
  [771] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_pattern_repeat1, 2, .production_id = 12),
  [773] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_pattern_repeat1, 2, .production_id = 12), SHIFT_REPEAT(822),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(822),
  [778] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_source_set, 1, .production_id = 1),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(667),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [784] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_stmt_list, 2),
  [786] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_vertex_types, 4),
  [788] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dml_sub_stmt_list_repeat1, 2), SHIFT_REPEAT(87),
  [791] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dml_sub_stmt_list_repeat1, 2),
  [793] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql_select_block, 3),
  [795] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_vertex_types, 1),
  [797] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_v_accum_func_call_repeat1, 5, .production_id = 26),
  [799] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_vertex_set, 1),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(705),
  [803] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path_pattern, 2, .production_id = 6),
  [805] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atomic_vertex_type, 1),
  [807] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_stmt_list, 1),
  [809] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_while_stmt, 5),
  [811] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_pattern_repeat1, 6),
  [813] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_pattern_repeat1, 8, .production_id = 27),
  [815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [817] = {.entry = {.count = 1, .reusable = false}}, SHIFT(381),
  [819] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(750),
  [823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(798),
  [825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(625),
  [827] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_while_stmt, 7),
  [829] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_stmt, 1),
  [831] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_if_stmt, 7),
  [833] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_step_repeat1, 2),
  [835] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_step_repeat1, 2), SHIFT_REPEAT(816),
  [838] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_vertex_set, 3, .production_id = 13),
  [840] = {.entry = {.count = 1, .reusable = false}}, SHIFT(388),
  [842] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_from_clause_repeat1, 2), SHIFT_REPEAT(559),
  [845] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_from_clause_repeat1, 2),
  [847] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_if_stmt, 6),
  [849] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql, 1),
  [851] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_source_set, 3, .production_id = 11),
  [853] = {.entry = {.count = 1, .reusable = false}}, SHIFT(835),
  [855] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gsql_repeat1, 2),
  [857] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gsql_repeat1, 2), SHIFT_REPEAT(481),
  [860] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gsql_repeat1, 2), SHIFT_REPEAT(866),
  [863] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_for_each_stmt, 5),
  [865] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_case_stmt, 5),
  [867] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_if_stmt, 5),
  [869] = {.entry = {.count = 1, .reusable = true}}, SHIFT(717),
  [871] = {.entry = {.count = 1, .reusable = false}}, SHIFT(592),
  [873] = {.entry = {.count = 1, .reusable = false}}, SHIFT(518),
  [875] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_case_stmt, 3),
  [877] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step, 2),
  [879] = {.entry = {.count = 1, .reusable = true}}, SHIFT(816),
  [881] = {.entry = {.count = 1, .reusable = true}}, SHIFT(559),
  [883] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_clause, 2),
  [885] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dml_sub_if_stmt, 8),
  [887] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_clause, 3),
  [889] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql_select_block, 4),
  [891] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [895] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_where_clause, 2),
  [897] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_v2, 1),
  [899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(706),
  [901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [903] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [905] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql_select_block, 5),
  [907] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_step_repeat1, 6),
  [909] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_step_repeat1, 7),
  [911] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [913] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_stmt, 2),
  [915] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [917] = {.entry = {.count = 1, .reusable = true}}, SHIFT(403),
  [919] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_v_expr_set, 4),
  [921] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_v_expr_set, 5),
  [923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(520),
  [929] = {.entry = {.count = 1, .reusable = true}}, SHIFT(651),
  [931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(701),
  [933] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_disj_pattern_repeat1, 2),
  [935] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_disj_pattern_repeat1, 2), SHIFT_REPEAT(327),
  [938] = {.entry = {.count = 1, .reusable = true}}, SHIFT(841),
  [940] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_print_stmt_repeat1, 2), SHIFT_REPEAT(111),
  [943] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_print_stmt_repeat1, 2),
  [945] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atomic_edge_type, 1),
  [947] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer, 2),
  [949] = {.entry = {.count = 1, .reusable = true}}, SHIFT(754),
  [951] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_edge_set_type, 1),
  [953] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_stmt, 3),
  [955] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [957] = {.entry = {.count = 1, .reusable = true}}, SHIFT(407),
  [959] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path_edge_pattern, 1),
  [961] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [963] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_v2, 7),
  [965] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_edge_types, 1),
  [967] = {.entry = {.count = 1, .reusable = true}}, SHIFT(430),
  [969] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atomic_edge_pattern, 1),
  [971] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gsql_select_block_repeat1, 2),
  [973] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gsql_select_block_repeat1, 2), SHIFT_REPEAT(85),
  [976] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_set, 3),
  [978] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [980] = {.entry = {.count = 1, .reusable = true}}, SHIFT(480),
  [982] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_disj_pattern, 2),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(745),
  [986] = {.entry = {.count = 1, .reusable = true}}, SHIFT(627),
  [988] = {.entry = {.count = 1, .reusable = true}}, SHIFT(456),
  [990] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_type, 10),
  [992] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accum_type, 10),
  [994] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_v_set_var_decl_stmt, 3),
  [996] = {.entry = {.count = 1, .reusable = true}}, SHIFT(536),
  [998] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [1000] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atomic_edge_pattern, 2),
  [1002] = {.entry = {.count = 1, .reusable = true}}, SHIFT(562),
  [1004] = {.entry = {.count = 1, .reusable = false}}, SHIFT(562),
  [1006] = {.entry = {.count = 1, .reusable = false}}, SHIFT(466),
  [1008] = {.entry = {.count = 1, .reusable = false}}, SHIFT(880),
  [1010] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_each_control, 3, .production_id = 4),
  [1012] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_stmt, 5),
  [1014] = {.entry = {.count = 1, .reusable = true}}, SHIFT(404),
  [1016] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_type, 11),
  [1018] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accum_type, 11),
  [1020] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_each_control, 6, .production_id = 19),
  [1022] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_real, 4),
  [1024] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_list, 2),
  [1026] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_stmt, 4),
  [1028] = {.entry = {.count = 1, .reusable = true}}, SHIFT(421),
  [1030] = {.entry = {.count = 1, .reusable = true}}, SHIFT(422),
  [1032] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [1034] = {.entry = {.count = 1, .reusable = true}}, SHIFT(815),
  [1036] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dml_sub_case_stmt_repeat1, 2),
  [1038] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dml_sub_case_stmt_repeat1, 2), SHIFT_REPEAT(108),
  [1041] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 2), SHIFT_REPEAT(562),
  [1044] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_comment_repeat1, 2), SHIFT_REPEAT(562),
  [1047] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_comment_repeat1, 2),
  [1049] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arg_list_repeat1, 2), SHIFT_REPEAT(157),
  [1052] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [1054] = {.entry = {.count = 1, .reusable = true}}, SHIFT(467),
  [1056] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [1058] = {.entry = {.count = 1, .reusable = true}}, SHIFT(411),
  [1060] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_type, 4),
  [1062] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accum_type, 4),
  [1064] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [1066] = {.entry = {.count = 1, .reusable = true}}, SHIFT(809),
  [1068] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_case_stmt_repeat1, 2),
  [1070] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_body_case_stmt_repeat1, 2), SHIFT_REPEAT(92),
  [1073] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_type, 8),
  [1075] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accum_type, 8),
  [1077] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [1079] = {.entry = {.count = 1, .reusable = true}}, SHIFT(369),
  [1081] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [1083] = {.entry = {.count = 1, .reusable = true}}, SHIFT(443),
  [1085] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [1087] = {.entry = {.count = 1, .reusable = true}}, SHIFT(441),
  [1089] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [1091] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_decl_stmt, 2),
  [1093] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_case_stmt_repeat2, 2),
  [1095] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_body_case_stmt_repeat2, 2), SHIFT_REPEAT(262),
  [1098] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [1100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [1102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [1104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(672),
  [1106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [1108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [1110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [1112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(879),
  [1114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_type, 1),
  [1116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accum_type, 1),
  [1118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(740),
  [1120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [1122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_decl_stmt, 2),
  [1124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_type, 9),
  [1126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accum_type, 9),
  [1128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_expr, 3),
  [1130] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arg_list_repeat1, 2), SHIFT_REPEAT(177),
  [1133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_type, 6),
  [1135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accum_type, 6),
  [1137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(662),
  [1139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [1141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [1143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(789),
  [1145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(549),
  [1147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(846),
  [1149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(845),
  [1151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(842),
  [1153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [1155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(587),
  [1157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(587),
  [1159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(427),
  [1161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(685),
  [1163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [1165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [1167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(751),
  [1169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_decl_stmt, 5),
  [1171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_decl_stmt, 5),
  [1173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [1175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(760),
  [1177] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_accum_decl_stmt_repeat1, 2), SHIFT_REPEAT(441),
  [1180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_decl_stmt_repeat1, 2),
  [1182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_base_decl_stmt_repeat1, 2),
  [1184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [1186] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_base_decl_stmt_repeat1, 2), SHIFT_REPEAT(730),
  [1189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__element_type, 1),
  [1191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [1193] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(587),
  [1196] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(587),
  [1199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dml_sub_case_stmt_repeat1, 4),
  [1201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [1203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(358),
  [1205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_case_stmt_repeat1, 4),
  [1207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path_edge_pattern, 3),
  [1209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_params, 1),
  [1211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [1213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(844),
  [1215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [1217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 1),
  [1219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(618),
  [1221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [1223] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_body_if_stmt_repeat1, 2), SHIFT_REPEAT(711),
  [1226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_if_stmt_repeat1, 2),
  [1228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_case_stmt_repeat2, 4),
  [1232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [1234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(472),
  [1236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(799),
  [1238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [1240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(704),
  [1242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_params_repeat1, 2),
  [1244] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_params_repeat1, 2), SHIFT_REPEAT(259),
  [1247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(288),
  [1249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(864),
  [1251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(863),
  [1253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_v_expr_set_repeat1, 2), SHIFT_REPEAT(136),
  [1256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_v_expr_set_repeat1, 2),
  [1258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_seed, 1),
  [1260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(582),
  [1262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(605),
  [1264] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_seed_set_repeat1, 2), SHIFT_REPEAT(390),
  [1267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_seed_set_repeat1, 2),
  [1269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_step_edge_types_repeat1, 2),
  [1271] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_step_edge_types_repeat1, 2), SHIFT_REPEAT(456),
  [1274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_decl_stmt, 4),
  [1276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gsql_repeat1, 1),
  [1278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_step_vertex_types_repeat1, 2),
  [1280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_step_vertex_types_repeat1, 2), SHIFT_REPEAT(449),
  [1283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body, 3),
  [1285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [1287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(400),
  [1289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [1291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [1293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(695),
  [1295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [1297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(691),
  [1299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [1301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [1303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [1305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(449),
  [1307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(571),
  [1309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(426),
  [1311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_for_each_control_repeat1, 2, .production_id = 9),
  [1313] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_for_each_control_repeat1, 2, .production_id = 9), SHIFT_REPEAT(827),
  [1316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body, 2),
  [1318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(853),
  [1320] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dml_sub_if_stmt_repeat1, 2), SHIFT_REPEAT(693),
  [1323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dml_sub_if_stmt_repeat1, 2),
  [1325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_decl_stmt, 3),
  [1327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [1329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [1331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_size, 1),
  [1333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [1335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(609),
  [1337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(827),
  [1339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_params, 2),
  [1341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_decl_stmt, 3),
  [1343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [1345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [1347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [1349] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat1, 2), SHIFT_REPEAT(288),
  [1352] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_call_stmt_repeat1, 2),
  [1354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_param, 2),
  [1356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(386),
  [1358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(834),
  [1360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [1362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gsql_select_block_repeat1, 1),
  [1364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [1366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_post_accum_clause, 2),
  [1368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [1370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(367),
  [1372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [1374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(434),
  [1376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 1),
  [1378] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_comment_repeat1, 1),
  [1380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [1382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(390),
  [1384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(839),
  [1386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [1388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [1390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [1392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dml_sub_if_stmt_repeat1, 5),
  [1394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accum_clause, 2),
  [1396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(401),
  [1398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [1400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(741),
  [1402] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__definition, 2),
  [1404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [1406] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat2, 2),
  [1408] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat2, 2), SHIFT_REPEAT(685),
  [1411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(455),
  [1413] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat4, 2), SHIFT_REPEAT(258),
  [1416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat4, 2),
  [1418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [1420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_for_each_control_repeat1, 2, .production_id = 8),
  [1422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_edge_set, 1),
  [1424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(688),
  [1426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_seed, 2),
  [1428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(387),
  [1430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [1432] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_param, 4),
  [1434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(504),
  [1436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 1),
  [1438] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 1),
  [1440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [1442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [1444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat2, 3),
  [1446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(783),
  [1448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat4, 3),
  [1450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(611),
  [1452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 9, .production_id = 17),
  [1454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [1456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [1458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_decl_stmt_repeat1, 4),
  [1460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [1462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [1464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(775),
  [1466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(774),
  [1468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(384),
  [1470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(383),
  [1472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(639),
  [1474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 10, .production_id = 22),
  [1476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(652),
  [1478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_body_if_stmt_repeat1, 5),
  [1480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(590),
  [1482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(675),
  [1484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_edge_types, 4),
  [1486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(484),
  [1488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_v_set_proj, 3),
  [1490] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat3, 2), SHIFT_REPEAT(276),
  [1493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(362),
  [1495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(391),
  [1497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(698),
  [1499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpret_query, 6, .production_id = 3),
  [1501] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_edge_types, 3),
  [1503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [1505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(637),
  [1507] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 7, .production_id = 7),
  [1509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [1511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(719),
  [1513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(614),
  [1515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 8, .production_id = 14),
  [1517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(679),
  [1519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(631),
  [1521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(410),
  [1523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(683),
  [1525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_each_control, 8, .production_id = 4),
  [1527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [1529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [1531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [1533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(709),
  [1535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_step_edge_set, 3, .production_id = 23),
  [1537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(872),
  [1539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 11, .production_id = 17),
  [1541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(638),
  [1543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [1545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(668),
  [1547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(473),
  [1549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(787),
  [1551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(735),
  [1553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(788),
  [1555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(596),
  [1557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(628),
  [1559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(452),
  [1561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(690),
  [1563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(551),
  [1565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [1567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_if_stmt, 8),
  [1569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(360),
  [1571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [1573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [1575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(862),
  [1577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(654),
  [1579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_case_stmt, 3),
  [1581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(353),
  [1583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [1585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 10, .production_id = 14),
  [1587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [1589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(764),
  [1591] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 12, .production_id = 22),
  [1593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(364),
  [1595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [1597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(700),
  [1599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [1601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(613),
  [1603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [1605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [1607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(649),
  [1609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(804),
  [1611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [1613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(655),
  [1615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(373),
  [1617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [1619] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_set_param, 4),
  [1621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [1623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [1625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [1627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(786),
  [1629] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_stmt, 7),
  [1631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [1633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(509),
  [1635] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_accum_type_repeat3, 3),
  [1637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(621),
  [1639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(355),
  [1641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [1643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [1645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [1647] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_while_stmt, 7),
  [1649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [1651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(666),
  [1653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_if_stmt, 7),
  [1655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [1657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(674),
  [1659] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_each_control, 13, .production_id = 4),
  [1661] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_seed_set, 2),
  [1663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(780),
  [1665] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_query, 9, .production_id = 7),
  [1667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(610),
  [1669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(781),
  [1671] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql_select_block, 6),
  [1673] = {.entry = {.count = 1, .reusable = true}}, SHIFT(626),
  [1675] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [1677] = {.entry = {.count = 1, .reusable = true}}, SHIFT(736),
  [1679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(492),
  [1681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(687),
  [1683] = {.entry = {.count = 1, .reusable = true}}, SHIFT(657),
  [1685] = {.entry = {.count = 1, .reusable = true}}, SHIFT(608),
  [1687] = {.entry = {.count = 1, .reusable = true}}, SHIFT(710),
  [1689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(653),
  [1691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(635),
  [1693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(729),
  [1695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(694),
  [1697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(664),
  [1699] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_seed_set, 4),
  [1701] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_print_stmt, 6),
  [1703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(650),
  [1705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(703),
  [1707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(577),
  [1709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [1711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(640),
  [1713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_if_stmt, 5),
  [1715] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_case_stmt, 6),
  [1717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(356),
  [1719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(437),
  [1721] = {.entry = {.count = 1, .reusable = false}}, SHIFT(707),
  [1723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(779),
  [1725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(718),
  [1727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(378),
  [1729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [1731] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_if_stmt, 6),
  [1733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [1735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(713),
  [1737] = {.entry = {.count = 1, .reusable = true}}, SHIFT(724),
  [1739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [1741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(279),
  [1743] = {.entry = {.count = 1, .reusable = true}}, SHIFT(552),
  [1745] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_path, 1),
  [1747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(727),
  [1749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [1751] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2),
  [1753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(728),
  [1755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [1757] = {.entry = {.count = 1, .reusable = true}}, SHIFT(597),
  [1759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(733),
  [1761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [1763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(470),
  [1765] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregator, 5),
  [1767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(756),
  [1769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [1771] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decl_stmt, 1),
  [1773] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [1775] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__select_stmt, 1),
  [1777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [1779] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpret_query, 8, .production_id = 3),
  [1781] = {.entry = {.count = 1, .reusable = true}}, SHIFT(598),
  [1783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(720),
  [1785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [1787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [1789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(743),
  [1791] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [1793] = {.entry = {.count = 1, .reusable = true}}, SHIFT(744),
  [1795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [1797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [1799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [1801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(641),
  [1803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [1805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(533),
  [1807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(512),
  [1811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [1813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [1815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [1817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(477),
  [1819] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_case_stmt, 4),
  [1821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(761),
  [1823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [1827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(873),
  [1829] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [1831] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [1833] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [1835] = {.entry = {.count = 1, .reusable = true}}, SHIFT(763),
  [1837] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [1839] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [1841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [1843] = {.entry = {.count = 1, .reusable = true}}, SHIFT(630),
  [1845] = {.entry = {.count = 1, .reusable = true}}, SHIFT(861),
  [1847] = {.entry = {.count = 1, .reusable = true}}, SHIFT(580),
  [1849] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [1851] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [1853] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [1855] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [1857] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [1859] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [1861] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [1863] = {.entry = {.count = 1, .reusable = true}}, SHIFT(875),
  [1865] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [1867] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [1869] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_seed_set, 3),
  [1871] = {.entry = {.count = 1, .reusable = true}}, SHIFT(607),
  [1873] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [1875] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [1877] = {.entry = {.count = 1, .reusable = true}}, SHIFT(824),
  [1879] = {.entry = {.count = 1, .reusable = true}}, SHIFT(604),
  [1881] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [1883] = {.entry = {.count = 1, .reusable = true}}, SHIFT(417),
  [1885] = {.entry = {.count = 1, .reusable = true}}, SHIFT(623),
  [1887] = {.entry = {.count = 1, .reusable = true}}, SHIFT(874),
  [1889] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [1891] = {.entry = {.count = 1, .reusable = true}}, SHIFT(858),
  [1893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [1895] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [1897] = {.entry = {.count = 1, .reusable = false}}, SHIFT(814),
  [1899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(475),
  [1901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(817),
  [1903] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_for_each_stmt, 5),
  [1905] = {.entry = {.count = 1, .reusable = true}}, SHIFT(670),
  [1907] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [1909] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_while_stmt, 5),
  [1911] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gsql_select_clause, 4, .production_id = 5),
  [1913] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [1915] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [1917] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1919] = {.entry = {.count = 1, .reusable = true}}, SHIFT(588),
  [1921] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [1923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [1925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(394),
  [1927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [1929] = {.entry = {.count = 1, .reusable = true}}, SHIFT(860),
  [1931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(593),
  [1933] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_body_case_stmt, 5),
  [1935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [1937] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [1939] = {.entry = {.count = 1, .reusable = true}}, SHIFT(867),
  [1941] = {.entry = {.count = 1, .reusable = true}}, SHIFT(868),
  [1943] = {.entry = {.count = 1, .reusable = true}}, SHIFT(752),
  [1945] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 2),
  [1947] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_gsql() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
