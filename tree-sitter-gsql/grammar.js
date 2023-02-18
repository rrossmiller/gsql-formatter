module.exports = grammar({
  name: 'gsql',
  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      // $.function_definition
      $.create_query
      //$.interpretQuery
    ),

    create_query: $ => seq(
      'CREATE',
      optional(seq('OR', 'REPLACE')),
      optional('DISTRIBUTED'),
      'QUERY',
      field('queryName', $.identifier),
      $.parameter_list,
      'FOR',
      'GRAPH',
      field('graphName', $.identifier),
      optional(seq('SYNTAX', 'V2')),
      $.block
    ),

    parameter_list: $ => seq(
      '(',
      // $._type,
      // $.identifier,
      ')'
    ),

    block: $ => seq(
      '{',
      // repeat($._statement),
      '}'
    ),

    // _statement: $ => choice(
    //   $.return_statement,
    //   $.if_statement,
    //   $._expression
    //   // TODO: other kinds of statements
    // ),

    // if_statement: $ => seq(
    //   'if',
    //   '(',
    //   ')',
    //   $.block,
    // ),
    // return_statement: $ => seq(
    //   'return',
    //   $._expression,
    //   ';'
    // ),

    // _expression: $ => choice(
    //   $.identifier,
    //   field('num', $.number),
    //   ';'
    //   // TODO: other kinds of expressions
    // ),

    identifier: $ => /[a-z]+/,

    number: $ => /\d+/,

    // _type: $ => choice(
    //   $.primitive_type,
    //   $.array_type,
    // ),

    // primitive_type: $ => choice(
    //   'bool',
    //   'int'
    // ),

    // array_type: $ => seq(
    //   '[',
    //   ']',
    //   $._type
    // )
  }
});