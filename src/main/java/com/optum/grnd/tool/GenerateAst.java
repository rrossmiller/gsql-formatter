package com.optum.grnd.tool;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;

//CHECKME translate EBNF to the types/statements arrays???
public class GenerateAst {
    public static void main(String[] args) throws IOException {
        String outputDir = "src/main/java/com/optum/ghs/grommet/types";
        if (args.length == 1) {
            // System.err.println("Usage: generate_ast <output directory>");
            // System.exit(64);
            outputDir = args[0];
        }

        // expression nodes in the AST
        List<String> types = Arrays.asList(
                "Assign   : Token name, Expr value",
                "Binary   : Expr left, Token operator, Expr right",
                "Call     : Expr callee, Token paren, List<Expr> arguments",
                "Get      : Expr object, Token name",
                "Grouping : Expr expression",
                "Literal  : Object value",
                "Logical  : Expr left, Token operator, Expr right",
                "Set      : Expr object, Token name, Expr value",
                "This     : Token keyword",
                "Unary    : Token operator, Expr right",
                "Variable : Token name"

        );
        defineAst(outputDir, "Expr", types);

        // statement nodes in the AST
        List<String> stmts = Arrays.asList(
                "Block        : List<Stmt> statements",
                "Class        : Token name, List<Function> methods",
                "Expression   : Expr expression",
                "Function     : Token name, List<Token> params, List<Stmt> body",
                "If           : Expr condition, Stmt thenBranch, Stmt elseBranch",
                "Print        : Expr expression",
                "Return       : Token keyword, Expr value",
                "Var          : Token name, Expr initializer",
                "While        : Expr condition, Stmt body");
        defineAst(outputDir, "Stmt", stmts);
    }

    private static void defineAst(String outputDir, String baseName, List<String> types) throws IOException {
        String path = outputDir + "/" + baseName + ".java";
        final File f = new File(path);
        f.createNewFile();
        PrintWriter writer = new PrintWriter(path, "UTF-8");

        writer.println("package com.optum.ghs.grommet.types;");
        writer.println();
        writer.println("import java.util.List;");
        // writer.println("import lombok.Getter;");
        writer.println();
        writer.println("public abstract class " + baseName + " {");

        // The base accept() method.
        writer.println("    public abstract <R> R accept(Visitor<R> visitor);");
        writer.println();

        defineVisitor(writer, baseName, types);

        // The AST classes.
        for (String type : types) {
            String className = type.split(":")[0].trim();
            String fields = type.split(":")[1].trim();
            defineType(writer, baseName, className, fields);
        }

        writer.println("}");
        writer.close();
    }

    private static void defineVisitor(PrintWriter writer, String baseName, List<String> types) {
        writer.println("    public interface Visitor<R> {");

        for (String type : types) {
            String typeName = type.split(":")[0].trim();

            writer.println(
                    "        public R visit" + typeName + baseName + "(" + typeName + " " + baseName.toLowerCase()
                            + ");\n");
        }

        writer.println("    }\n");
    }

    private static void defineType(PrintWriter writer, String baseName, String className, String fieldList) {

        // writer.println("    @Getter");
        writer.println("    public static class " + className + " extends " + baseName + " {");
        String[] fields = fieldList.split(", ");

        // Fields.
        for (String field : fields) {
            writer.println("        public final " + field + ";");
        }
        writer.println();
        // Constructor.
        writer.println("        public " + className + "(" + fieldList + ") {");

        // Store parameters in fields.
        for (String field : fields) {
            String name = field.split(" ")[1];
            writer.println("            this." + name + " = " + name + ";");
        }

        writer.println("        }");

        // Visitor pattern.
        writer.println();
        writer.println("        @Override");
        writer.println("        public <R> R accept(Visitor<R> visitor) {");
        writer.println("            return visitor.visit" +
                className + baseName + "(this);");
        writer.println("        }\n");

        writer.println("    }\n");
    }

}