package com.optum.ghs.grommet;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

import com.optum.ghs.grommet.exception.RuntimeError;
import com.optum.ghs.grommet.types.Token;
import static com.optum.ghs.grommet.types.TokenType.*;

public class Grommet {
    // private static final Interpreter interpreter = new Interpreter();
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
        for (Token token : tokens) {
        System.out.println(token);
        }
        // System.out.println("***");

        // Parser parser = new Parser(tokens);
        // List<Stmt> statements = parser.parse();

        // // stop if there was a syntax error
        // if (hadError)
        //     return;

        // Resolver resolver = new Resolver(interpreter); // semantic analysis
        // resolver.resolve(statements);

        // // Stop if there was a resolution error.
        // if (hadError)
        //     return;

        // new AstPrinter().printTree(statements, false, true);
        //// interpreter.interpret(statements);
    }

    static void error(int line, String message) {
        report(line, "", message);
    }

    static void error(Token token, String message) {
        if (token.getType() == EOF) {
            report(token.getLine(), " at end", message);
        } else {
            report(token.getLine(), " at '" + token.getLexeme() + "'", message);
        }
    }

    static void runtimeError(RuntimeError error) {
        // System.err.println(error.getMessage() + "\n[line " + error.token.line + "]");
        System.err.println("[line " + error.token.getLine() + "] -->  " + error.getMessage());
        hadRuntimeError = true;
    }

    private static void report(int line, String where, String message) {
        System.err.println("[line " + line + "] Error" + where + ": " + message);
        hadError = true;
    }
}