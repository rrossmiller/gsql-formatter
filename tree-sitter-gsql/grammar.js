module.exports = grammar({
	name: "gsql",
	word: ($) => $.name,
	extras: $ => [
		/\s/,
		$.line_comment,
		// $.block_comment,
	],

	conflicts: $ => [
		[$.integer],
		[$.expr],
		[$.real]
	],
	rules: {
		source_file: ($) => repeat($._definition),

		_definition: ($) =>
			choice(
				$.create_query
				//$.interpretQuery
			),

		create_query: ($) => seq(
			caseInsensitive("create"),
			optional(
				seq(caseInsensitive("or"), caseInsensitive("replace"))
			),
			optional(caseInsensitive("distributed")),
			caseInsensitive("query"),
			field("queryName", $.name),
			$.parameter_list,
			caseInsensitive("for"),
			caseInsensitive("graph"),
			field("graphName", $.name),
			optional(
				seq(caseInsensitive("syntax"), caseInsensitive("v2"))
			),
			$.query_body
		),

		parameter_list: ($) => seq(
			"(",
			repeat($.query_params),
			")"
		),

		query_params: $ => seq(
			$.query_param,
			optional(
				repeat(seq(",", $.query_param))
			)
		),

		query_param: ($) => seq(
			$._type,
			$.name,
			optional(seq("=", $.digit))
		),

		query_body: ($) =>
			seq(
				"{",
				optional(repeat(seq($.typedef, ";"))),
				// optional($.declaration_except_stmts),
				repeat($.query_body_stmts),
				"}"
			),

		typedef: $ => seq(
			caseInsensitive("typedef"),
			caseInsensitive("tuple"),
			"<",
			repeat($.tuple_fields),
			">",
			field("tuple_type", $.name)
		),

		tuple_fields: $ => seq(
			$.tuple_field,
			repeat(
				seq(",", $.tuple_field)
			)
		),

		tuple_field: $ => choice(
			seq($.base_type, $.name),
			seq($.name, $.base_type)
		),

		query_body_stmts: $ => seq(
			$.query_body_stmt,
			';'
		),

		query_body_stmt: $ => choice(
			// !bookmark
			// these need to be repeat 1 because if the pattern is chosen, it must complete at least once
			repeat1($.assign_stmt),
			repeat1($.v_set_var_decl_stmt),
			repeat1($.decl_stmt),
			repeat1($.l_accum_assign_stmt),
			repeat1($.g_accum_assign_stmt),
			repeat1($.g_accum_accum_stmt),
			repeat1($.func_call_stmt),
			repeat1($.select_stmt),
			// queryBodyCaseStmt ,
			// queryBodyIfStmt ,
			// queryBodyWhileStmt, 
			// queryBodyForEachStmt, 
			// "BREAK" ,
			// "CONTINUE", 
			// updateStmt ,
			// insertStmt ,
			// queryBodyDeleteStmt ,
			// printStmt ,
			// printlnStmt ,
			// logStmt ,
			// returnStmt, 
			// raiseStmt ,
			// tryStmt 
		),

		assign_stmt: $ => choice(
			seq($.name, "=", $.expr),
			seq($.name, ".", $.name, "=", $.expr)
		),

		v_set_var_decl_stmt: $ => seq(
			// vertexSetName
			$.name,
			optional(
				seq("(", $.name, ")")
			),
			"=",
			choice($.seed_set)//, $.simple_set, $.select_stmt)
		),

		seed_set: $ => seq(
			"{",
			optional(
				seq($.seed, repeat(seq(",", $.seed)))
			),
			"}"
		),

		seed: $ => choice(
			"_",
			"ANY",
			$.name,
			$.global_accum_name,
			seq($.name, ".*"),
			// $.param_name,
			// seq("SelectVertex", selectVertParams)
		),

		l_accum_assign_stmt: $ => seq(
			// vertexAlias "." localAccumName ("+=" | "=") expr ;
			$.name,
			".",
			$.local_accum_name,
			choice("+=", "="),
			$.expr
		),

		g_accum_assign_stmt: $ => prec(1, seq(
			$.global_accum_name,
			choice("+=", "="),
			$.expr
		)),

		g_accum_accum_stmt: $ => seq(
			$.global_accum_name,
			"+=",
			$.expr
		),

		func_call_stmt: $ => choice(
			seq(
				// name ("<" type ("," type)* ">")? "(" (argList)? ")" | 
				$.name,
				optional(seq(
					"<",
					$._type,
					repeat(seq(",", $._type)),
					">"
				)),
				"(",
				optional($.arg_list),
				")"
			),
			// globalAccumName ("." funcName "(" (argList)? ")")+ 
			seq(
				$.global_accum_name,
				repeat1(seq(".", $.name, "(", optional($.arg_list), ")")
				)
			)
		),

		select_stmt: $ => choice(
			$.gsql_select_block,
			// $.sqlSelectBlock 
		),

		gsql_select_block: $ => seq(
			$.gsql_select_clause,
			$.from_clause,
			// optional($.sample_clause),
			// optional($.where_clause),
			// optional($.accum_clause),
			// repeat($.post_accum_clause),
			// optional($.having_clause),
			// optional($.order_clause),
			// optional($.limit_clause),
		),
		gsql_select_clause: $ => seq(
			$.name,
			"=",
			caseInsensitive("select"),
			$.name
		),

		from_clause: $ => seq(
			caseInsensitive("from"),
			choice(
				$.step,
				// $.step_v2,
				// seq($path_pattern, repeat(seq(",", $path_pattern))),
			)
		),

		step: $ => seq(
			$.step_source_set,
			optional(seq(
				"-",
				"(",
				$.step_set,
				")",
				"-",
				optional('>'),
				$.step_set
			))
		),
		step_source_set: $ => seq(
			$.name,
			optional(seq(":", $.name))
		),

		step_set: $ => seq(
			$.step_type,
			optional(seq(":", field("alias", $.name)))
		),
		step_type: $ => choice(
			$.atomic_type,
			seq("(", $.set_type, repeat(seq(" | ", $.set_type)), ")")
		),
		atomic_type: $ => choice(
			"_",
			caseInsensitive("ANY"),
			$.set_type
		),
		set_type: $ => choice(
			$.name,
			$.global_accum_name
		),

		// !book bottom
		//---
		install_query: $ => seq(
			caseInsensitive("INSTALL"),
			caseInsensitive("QUERY"),
			choice("*", "ALL", seq($.name, repeat(seq(",", $.name))))
		),

		decl_stmt: $ => choice(
			$.base_decl_stmt,
			$.accum_decl_stmt,
			// $.file_decl_stmt
		),

		base_decl_stmt: $ => seq(
			$.base_type,
			$.name,
			optional(seq("=", $.expr)),
			repeat(seq(",", $.name, optional(seq("=", $.expr))))
		),

		accum_decl_stmt: $ => choice(
			seq(
				$.accum_type,
				$.local_accum_name,
				optional(seq("=", $.constant)),
				repeat(
					seq(
						",",
						$.local_accum_name,
						optional(seq("=", $.constant))
					)
				)
			),
			seq(
				$.accum_type,
				$.global_accum_name,
				optional(seq("=", $.constant)),
				repeat(seq(",", $.global_accum_name, optional(seq("=", $.constant))))
			)
		),

		accum_type: $ => choice(
			seq(
				caseInsensitive("SumAccum"), "<", choice(caseInsensitive("INT"), caseInsensitive("FLOAT"), caseInsensitive("DOUBLE"), caseInsensitive("STRING")), ">"
			),
			seq(caseInsensitive("MaxAccum"), "<", choice(caseInsensitive("INT"), caseInsensitive("FLOAT"), caseInsensitive("DOUBLE")), ">"),
			seq(caseInsensitive("MinAccum"), "<", choice(caseInsensitive("INT"), caseInsensitive("FLOAT"), caseInsensitive("DOUBLE")), ">"),
			caseInsensitive("AvgAccum"),
			caseInsensitive("OrAccum"),
			caseInsensitive("AndAccum"),
			caseInsensitive("BitwiseOrAccum"),
			caseInsensitive("BitwiseAndAccum"),
			seq(caseInsensitive("ListAccum"), "<", $._type, ">"),
			seq(caseInsensitive("SetAccum"), "<", $._element_type, ">"),
			seq(caseInsensitive("BagAccum"), "<", $._element_type, ">"),
			seq(caseInsensitive("MapAccum"), "<", $._element_type, ",", choice($.base_type, $.accum_type, $.name), ">"),
			seq(caseInsensitive("HeapAccum"), "<", $.name, ">", "(", $.simple_size, ",", $.name, choice(caseInsensitive("ASC"), caseInsensitive("DESC")), repeat(seq(",", $.name, choice(caseInsensitive("ASC"), caseInsensitive("DESC")))), ")"),
			seq(caseInsensitive("GroupByAccum"), "<", $._element_type, $.name, repeat(seq(",", $._element_type, $.name)), $.accum_type, $.name, repeat(seq(",", $.accum_type, $.name)), ">"),
			seq(caseInsensitive("ArrayAccum"), "<", $.name, ">")
		),

		global_accum_name: $ => seq(
			"@@",
			$.name
		),

		local_accum_name: $ => seq(
			"@",
			$.name
		),

		arg_list: $ => seq(
			$.expr,
			repeat(seq(",", $.expr))
		),

		// ------
		simple_size: $ => choice(
			repeat1($.digit),
			$.name
		),

		expr: $ => prec(1, choice(
			$.name,
			$.global_accum_name,
			seq($.name, ".", $.name),
			seq($.name, ".", $.local_accum_name),
			seq($.name, ".", $.name, ".", $.name, "(", optional($.arg_list), ")"),
			// seq($.name, ".", $.name, "(",optional(argList) , ")",optional(".", "FILTER", "(", condition, ")")  ), // todo condition
			seq($.name, optional(seq("<", $._type, repeat(seq(",", $._type)), ">")), "(", optional(seq($.arg_list, ")"))),
			seq($.name, ".", $.local_accum_name, repeat1(seq(".", $.name, "(", optional($.arg_list), ")")), optional(seq(".", $.name))),
			seq($.global_accum_name, repeat1(seq(".", $.name, "(", optional($.arg_list), ")")), optional(seq(".", $.name))),
			seq(caseInsensitive("COALESCE"), "(", optional($.arg_list), ")"),
			// seq(aggregator, "(", optional("DISTINCT"), $.setBagExpr, ")"), todo setbag
			// seq("ISEMPTY", "(", $.setBagExpr, ")"),
			prec.left(2, seq($.expr, $.math_operator, $.expr)),
			prec.left(1, seq("-", $.expr)),
			seq("(", $.expr, ")"),
			seq("(", $.arg_list, "->", $.arg_list, ")"),
			seq("[", $.arg_list, "]"),
			$.constant,
			// $.setBagExpr 
			seq($.name, "(", $.arg_list, ")"),
		)),
		_type: $ => choice(
			$.base_type
		),
		_element_type: $ => choice(
			$.base_type,
			$.name
		),
		base_type: $ => choice(
			caseInsensitive("bool"),
			caseInsensitive("int"),
			caseInsensitive("uint"),
			caseInsensitive("float"),
			caseInsensitive("double"),
			caseInsensitive("string"),
			caseInsensitive("bool"),
			// caseInsensitive("VERTEX" ("<" vertexType ">")?,
			caseInsensitive("edge"),
			caseInsensitive("JSONOBJECT"),
			caseInsensitive("JSONARRAY"),
			caseInsensitive("DATETIME")
		),

		name: $ => /[\p{L}_$][\p{L}\p{Nd}_$]*/, // thanks, java --> https://github.com/tree-sitter/tree-sitter-java/blob/master/grammar.js#:~:text=%5B%5Cp%7BL%7D_%24%5D%5B%5Cp%7BL%7D%5Cp%7BNd%7D_%24%5D*
		constant: $ => choice(
			$.numeric,
			$.string_literal,
			//TODO caseInsensitive
			"TRUE",
			"FALSE",
			"GSQL_UINT_MAX",
			"GSQL_INT_MAX",
			"GSQL_INT_MIN",
			seq("TO_DATETIME", "(", $.string_literal, ")")
		),

		numeric: $ => choice(
			$.integer,
			$.real
		),

		integer: $ => seq(
			optional('-'),
			repeat1($.digit)
		),
		real: $ => choice(
			seq(optional("-"), seq(".", repeat1($.digit))),
			seq(optional("-"), repeat1($.digit), seq(".", repeat1($.digit))),// (* prev start paren is part of the lang?
		),
		digit: $ => /\d/,
		// number: $ => /\d+/,

		string_literal: $ => seq(
			'"',
			repeat(/[^"&]/),
			'"'
		),
		math_operator: $ => choice(
			"*",
			"/",
			"%",
			"+",
			"-",
			"<<",
			">>",
			"&",
			" | "),

		// http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890

		comment: $ => choice(
			$.line_comment,
			// $.block_comment,
		),

		line_comment: $ => token(seq(
			'//', /.*/
		)),

		// block_comment: $ => token(seq(
		// 	'/*',
		// 	/[^*]*\*+([^/*][^*]*\*+)*/,
		// 	'/'
		// )),
	},
});

function caseInsensitive(keyword) {
	return new RegExp(
		keyword
			.split("")
			.map((letter) => `[${letter}${letter.toUpperCase()}]`)
			.join("")
	);
}
