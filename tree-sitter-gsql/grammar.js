module.exports = grammar({
	name: 'gsql',
	word: ($) => $.name,

	rules: {
		source_file: ($) => repeat($._definition),

		_definition: ($) =>
			choice(
				$.create_query
				//$.interpretQuery
			),

		create_query: ($) => seq(
			caseInsensitive('create'),
			optional(
				seq(caseInsensitive('or'), caseInsensitive('replace'))
			),
			optional(caseInsensitive('distributed')),
			caseInsensitive('query'),
			field('queryName', $.name),
			$.parameter_list,
			caseInsensitive('for'),
			caseInsensitive('graph'),
			field('graphName', $.name),
			optional(
				seq(caseInsensitive('syntax'), caseInsensitive('v2'))
			),
			$.query_body
		),

		parameter_list: ($) => seq(
			'(',
			repeat($.query_params),
			')'
		),

		query_params: $ => seq(
			$.query_param,
			optional(
				repeat(seq(',', $.query_param))
			)
		),

		query_param: ($) => seq(
			$._type,
			$.name,
			optional(seq('=', $.number))
		),

		query_body: ($) =>
			seq(
				'{',
				optional(seq(repeat($.typedef), ';')),
				// optional($.declaration_except_stmts),
				$.query_body_stmts,
				'}'
			),

		typedef: $ => seq(
			caseInsensitive("typedef"),
			caseInsensitive("tuple"),
			"<",
			repeat($.tuple_fields),
			">",
			field('tuple_type', $.name)
		),

		tuple_fields: $ => seq(
			$.tuple_field,
			repeat(
				seq(',', $.tuple_field)
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
			$.assign_stmt,
			$.v_set_var_decl_stmt
			// declStmts 
			// lAccumAssignStmt 
			// gAccumAssignStmt 
			// gAccumAccumStmt 
			// funcCallStmt 
			// selectStmt 
			// queryBodyCaseStmt 
			// queryBodyIfStmt 
			// queryBodyWhileStmt 
			// queryBodyForEachStmt 
			// "BREAK" 
			// "CONTINUE" 
			// updateStmt 
			// insertStmt 
			// queryBodyDeleteStmt 
			// printStmt 
			// printlnStmt 
			// logStmt 
			// returnStmt 
			// raiseStmt 
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
			'_',
			"ANY",
			// vertexSetName,
			// globalAccumName,
			// vertexType ".*",
			// paramName,
			// "SelectVertex" selectVertParams 
		),

		global_accum_name: $ => seq(
			'@@',
			$.name
		),

		local_accum_name: $ => seq(
			'@',
			$.name
		),

		arg_list: $ => seq(
			$.expr,
			repeat(seq(",", $.expr))
		),

		// ------
		expr: $ => choice(
			$.name,
			$.global_accum_name,
			seq($.name, ".", $.name),
			seq($.name, ".", $.local_accum_name),//what's this -> ("\'")? ),
			seq($.name, ".", $.name, ".", $.name, "(", optional($.arg_list), ")"),
			// name "." name "(" (argList)? ")" ( "." "FILTER" "(" condition ")" )? 
			// name ("<" type ("," type)* ">")? "(" (argList)? ")" 
			// name "." localAccumName ("." name "(" (argList)? ")")+ ("." name)? 
			// globalAccumName ("." name "(" (argList)? ")")+ ("." name)? 
			// "COALESCE" "(" (argList)? ")" 
			// aggregator "(" ("DISTINCT")? setBagExpr ")" 
			// "ISEMPTY" "(" setBagExpr ")" 
			// expr mathOperator expr 
			// "-" expr 
			// "(" expr ")" 
			// "(" argList "->" argList ")" 
			// "[" argList "]" 
			// constant 
			// setBagExpr 
			// name "(" argList ")",
		),
		_type: $ => choice(
			$.base_type,
		),

		base_type: $ => choice(
			caseInsensitive('bool'),
			caseInsensitive('int'),
			caseInsensitive('uint'),
			caseInsensitive('float'),
			caseInsensitive('double'),
			caseInsensitive('string'),
			caseInsensitive('bool'),
			// caseInsensitive("VERTEX" ("<" vertexType ">")?,
			caseInsensitive('edge'),
			caseInsensitive('JSONOBJECT'),
			caseInsensitive('JSONARRAY'),
			caseInsensitive('DATETIME')
		),

		name: $ => /[\p{L}_$][\p{L}\p{Nd}_$]*/, // thanks, java --> https://github.com/tree-sitter/tree-sitter-java/blob/master/grammar.js#:~:text=%5B%5Cp%7BL%7D_%24%5D%5B%5Cp%7BL%7D%5Cp%7BNd%7D_%24%5D*
		number: $ => /\d+/,
	},
});

function caseInsensitive(keyword) {
	return new RegExp(
		keyword
			.split('')
			.map((letter) => `[${letter}${letter.toUpperCase()}]`)
			.join('')
	);
}
