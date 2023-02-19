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
			optional(repeat($.query_params)),
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
				// optional($.query_body_stmts),
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
			optional(
				repeat(
					seq(',', $.tuple_field)
				)
			)
		),

		tuple_field: $ => choice(
			seq($.base_type, $.name),
			seq($.name, $.base_type)
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
