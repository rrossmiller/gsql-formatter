package com.optum.ghs.grommet;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import com.optum.ghs.grommet.types.Expr;
import com.optum.ghs.grommet.types.Stmt;
import com.optum.ghs.grommet.types.Token;
import com.optum.ghs.grommet.exception.RuntimeError;

class AstPrinter implements Expr.Visitor<String>, Stmt.Visitor<String> {
  // accepts a list of statment, otherwise called a program ;)
  public void printTree(List<Stmt> statements, boolean print, boolean save) {
    StringBuilder stringBuilder = new StringBuilder();
    try {
      for (Stmt statement : statements) {
        stringBuilder.append(print(statement));
      }
    } catch (RuntimeError error) {
      Grommet.runtimeError(error);
    }

    if (print)
      System.out.println(stringBuilder.toString());

    if (save) {
      String outputDir = ".";
      String path = outputDir + "/AST.txt";
      PrintWriter writer = null;
      try {
        final File f = new File(path);
        f.createNewFile();
        writer = new PrintWriter(path, "UTF-8");
        writer.print(stringBuilder.toString());

      } catch (IOException e) {
        System.err.println(e.getMessage());
      } finally {
        if (writer != null)
          writer.close();
      }
    }
  }

  String print(Expr expr) {
    return expr.accept(this);
  }

  String print(Stmt stmt) {
    return stmt.accept(this);
  }

  @Override
  public String visitBlockStmt(Stmt.Block stmt) {
    StringBuilder builder = new StringBuilder();
    builder.append("(block ");

    for (Stmt statement : stmt.statements) {
      builder.append(statement.accept(this));
    }

    builder.append(")");
    return builder.toString();
  }

  @Override
  public String visitClassStmt(Stmt.Class stmt) {
    StringBuilder builder = new StringBuilder();
    builder.append("(class " + stmt.name.lexeme);

    // if (stmt.superclass != null) {
    // builder.append(" < " + print(stmt.superclass));
    // }

    for (Stmt.Function method : stmt.methods) {
      builder.append(" " + print(method));
    }

    builder.append(")");
    return builder.toString();
  }

  @Override
  public String visitExpressionStmt(Stmt.Expression stmt) {
    return parenthesize(";", stmt.expression);
  }

  @Override
  public String visitFunctionStmt(Stmt.Function stmt) {
    StringBuilder builder = new StringBuilder();
    builder.append("(fun " + stmt.name.lexeme + "(");

    for (Token param : stmt.params) {
      if (param != stmt.params.get(0))
        builder.append(" ");
      builder.append(param.lexeme);
    }

    builder.append(") ");

    for (Stmt body : stmt.body) {
      builder.append(body.accept(this));
    }

    builder.append(")");
    return builder.toString();
  }

  @Override
  public String visitIfStmt(Stmt.If stmt) {
    if (stmt.elseBranch == null) {
      return parenthesize2("if", stmt.condition, stmt.thenBranch);
    }

    return parenthesize2("if-else", stmt.condition, stmt.thenBranch,
        stmt.elseBranch);
  }

  @Override
  public String visitPrintStmt(Stmt.Print stmt) {
    return parenthesize("print", stmt.expression);
  }

  @Override
  public String visitReturnStmt(Stmt.Return stmt) {
    if (stmt.value == null)
      return "(return)";
    return parenthesize("return", stmt.value);
  }

  @Override
  public String visitVarStmt(Stmt.Var stmt) {
    if (stmt.initializer == null) {
      return parenthesize2("var", stmt.name);
    }

    return parenthesize2("var", stmt.name, "=", stmt.initializer);
  }

  @Override
  public String visitWhileStmt(Stmt.While stmt) {
    return parenthesize2("while", stmt.condition, stmt.body);
  }

  @Override
  public String visitAssignExpr(Expr.Assign expr) {
    return parenthesize2("=", expr.name.lexeme, expr.value);
  }

  @Override
  public String visitBinaryExpr(Expr.Binary expr) {
    return parenthesize(expr.operator.lexeme,
        expr.left, expr.right);
  }

  @Override
  public String visitCallExpr(Expr.Call expr) {
    return parenthesize2("call", expr.callee, expr.arguments);
  }

  @Override
  public String visitGetExpr(Expr.Get expr) {
    return parenthesize2(".", expr.object, expr.name.lexeme);
  }

  @Override
  public String visitGroupingExpr(Expr.Grouping expr) {
    return parenthesize("group", expr.expression);
  }

  @Override
  public String visitLiteralExpr(Expr.Literal expr) {
    if (expr.value == null)
      return "nil";
    return expr.value.toString();
  }

  @Override
  public String visitLogicalExpr(Expr.Logical expr) {
    return parenthesize(expr.operator.lexeme, expr.left, expr.right);
  }

  @Override
  public String visitSetExpr(Expr.Set expr) {
    return parenthesize2("=",
        expr.object, expr.name.lexeme, expr.value);
  }

  // @Override
  // public String visitSuperExpr(Expr.Super expr) {
  // return parenthesize2("super", expr.method);
  // }

  @Override
  public String visitThisExpr(Expr.This expr) {
    return "this";
  }

  @Override
  public String visitUnaryExpr(Expr.Unary expr) {
    return parenthesize(expr.operator.lexeme, expr.right);
  }

  @Override
  public String visitVariableExpr(Expr.Variable expr) {
    return expr.name.lexeme;
  }

  private String parenthesize(String name, Expr... exprs) {
    StringBuilder builder = new StringBuilder();

    builder.append("(").append(name);
    for (Expr expr : exprs) {
      builder.append(" ");
      builder.append(expr.accept(this));
    }
    builder.append(")");

    return builder.toString();
  }

  // Note: AstPrinting other types of syntax trees is not shown in the
  // book, but this is provided here as a reference for those reading
  // the full code.
  private String parenthesize2(String name, Object... parts) {
    StringBuilder builder = new StringBuilder();

    builder.append("(").append(name);
    transform(builder, parts);
    builder.append(")");

    return builder.toString();
  }

  private void transform(StringBuilder builder, Object... parts) {
    for (Object part : parts) {
      builder.append(" ");
      if (part instanceof Expr) {
        builder.append(((Expr) part).accept(this));
      } else if (part instanceof Stmt) {
        builder.append(((Stmt) part).accept(this));
      } else if (part instanceof Token) {
        builder.append(((Token) part).lexeme);
      } else if (part instanceof List) {
        transform(builder, ((List) part).toArray());
      } else {
        builder.append(part);
      }
    }
  }
  // < omit
  /*
   * Representing Code printer-main < Representing Code omit
   * public static void main(String[] args) {
   * Expr expression = new Expr.Binary(
   * new Expr.Unary(
   * new Token(TokenType.MINUS, "-", null, 1),
   * new Expr.Literal(123)),
   * new Token(TokenType.STAR, "*", null, 1),
   * new Expr.Grouping(
   * new Expr.Literal(45.67)));
   * 
   * System.out.println(new AstPrinter().print(expression));
   * }
   */
}
