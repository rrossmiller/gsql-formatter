package com.optum.grnd.grommet;

import static com.optum.grnd.grommet.types.TokenType.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

import com.optum.grnd.grommet.exception.RuntimeError;
import com.optum.grnd.grommet.types.Stmt;
import com.optum.grnd.grommet.types.Token;
import com.optum.grnd.grommet.types.TokenType.*;

public class Grommet {
    private static final Interpreter interpreter = new Interpreter();
    static boolean hadError = false;
    static boolean hadRuntimeError = false;

    public static void main(String[] args) throws IOException {
        if (args.length > 1) {
            System.out.println("Usage: jlox [script]");
            System.exit(64);
        } else if (args.length == 1) {
            runFile(args[0]);
        } else {
            error(0, "you must supply a file");
        }
    }

    private static void runFile(String path) throws IOException {
        String gsql = Files.readString(Paths.get(path));
        run(gsql);

        // Indicate an error in the exit code.
        if (hadError)
            System.exit(65);
    }

    private static void run(String source) {
        Scanner scanner = new Scanner(source);
        List<Token> tokens = scanner.scanTokens();

        // For now, just print the tokens.
        System.out.println("type" + " | " + "lexeme" + " | " + "literal");
        for (Token token : tokens) {
            if (token.type == BLOCK_COMMENT) {
                Token tkn = new Token(BLOCK_COMMENT, token.lexeme.replaceAll("\n", " "), null, token.line);
               System.out.println(tkn);
            } else
                System.out.println(token);
        }
        System.out.println("***");

        // System.out.println("parse");
        Parser parser = new Parser(tokens);
        List<Stmt> statements = parser.parse();

        // stop if there was a syntax error
        if (hadError)
            return;

        // System.out.println("ast");
        new AstPrinter().printTree(statements, false, true);
        System.exit(0);

        // System.out.println("resolve");
        Resolver resolver = new Resolver(interpreter); // semantic analysis
        resolver.resolve(statements);

        // Stop if there was a resolution error.
        if (hadError)
            return;

        // System.out.println("interpret");
        interpreter.interpret(statements);
    }

    public static void error(int line, String message) {
        report(line, "", message);
    }

    public static void error(Token token, String message) {
        if (token.type == EOF) {
            report(token.line, " at end", message);
        } else {
            report(token.line, " at '" + token.lexeme + "'", message);
        }
    }

    public static void runtimeError(RuntimeError error) {
        System.err.println("[line " + error.token.line + "] -->  " + error.getMessage());
        hadRuntimeError = true;
    }

    private static void report(int line, String where, String message) {
        System.err.println("[line " + line + "] Error" + where + ": " + message);
        hadError = true;
    }
}