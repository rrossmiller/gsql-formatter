package com.optum.grnd.grommet.types;

import java.util.HashMap;
import java.util.Map;

public class Keywords {

    public static final Map<String, TokenType> keywords;
    static {
        keywords = new HashMap<>();
        keywords.put("and", TokenType.AND);
        keywords.put("class", TokenType.CLASS);
        keywords.put("else", TokenType.ELSE);
        keywords.put("false", TokenType.FALSE);
        keywords.put("for", TokenType.FOR);
        keywords.put("fun", TokenType.FUN);
        keywords.put("if", TokenType.IF);
        keywords.put("nil", TokenType.NIL);
        keywords.put("or", TokenType.OR);
        keywords.put("print", TokenType.PRINT);
        keywords.put("return", TokenType.RETURN);
        keywords.put("super", TokenType.SUPER);
        keywords.put("this", TokenType.THIS);
        keywords.put("true", TokenType.TRUE);
        keywords.put("var", TokenType.VAR);
        keywords.put("while", TokenType.WHILE);

        // graphy
        keywords.put("create", TokenType.CREATE);
        keywords.put("interpret", TokenType.INTERPRET);
        keywords.put("replace", TokenType.REPLACE);
        keywords.put("distributed", TokenType.DISTRIBUTED);
        keywords.put("query", TokenType.QUERY);
        keywords.put("graph", TokenType.GRAPH);
        keywords.put("returns", TokenType.RETURNS);
        // keywords.put("api", TokenType.API);
        keywords.put("syntax", TokenType.SYNTAX);

    }
    public static final Map<String, TokenType> types;
    static {
        types = new HashMap<>();
        types.put("int", TokenType.TYPE);
        types.put("uint", TokenType.TYPE);
        types.put("float", TokenType.TYPE);
        types.put("double", TokenType.TYPE);
        types.put("string", TokenType.TYPE);
        types.put("bool", TokenType.TYPE);
        types.put("vertex", TokenType.TYPE);
        types.put("edge", TokenType.TYPE);
        types.put("jsonobject", TokenType.TYPE);
        types.put("jsonarray", TokenType.TYPE);
        types.put("datetime", TokenType.TYPE);
    }

}