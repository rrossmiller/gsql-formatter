package com.optum.ghs.grommet.types;

import java.util.List;

import com.optum.ghs.grommet.Environment;
import com.optum.ghs.grommet.Interpreter;

public class GsqlFunction implements GsqlCallable {
    private final Stmt.Function declaration;
    private final Environment closure;
    private final boolean isInitializer;

    public GsqlFunction(Stmt.Function declaration, Environment closure, boolean isInitializer) {
        this.isInitializer = isInitializer;
        this.declaration = declaration;
        this.closure = closure;
    }

    @Override
    public Object call(Interpreter interpreter, List<Object> arguments) {
        Environment environment = new Environment(closure); // each function gets its own env where params
                                                            // and internal vars are stored

        for (int i = 0; i < declaration.params.size(); i++) {
            environment.define(declaration.params.get(i).lexeme, arguments.get(i));
        }

        try {
            interpreter.executeBlock(declaration.body, environment);
        } catch (FunReturn returnValue) {
            if (isInitializer)
                return closure.getAt(0, "this");
                
            return returnValue.value;
        }
        if (isInitializer)
            return closure.getAt(0, "this");
        return null;
    }

    @Override
    public int arity() {
        return declaration.params.size();
    }

    GsqlFunction bind(GsqlInstance instance) {
        Environment environment = new Environment(closure);
        environment.define("this", instance);
        return new GsqlFunction(declaration, environment, isInitializer);
    }

    @Override
    public String toString() {
        return "<fn " + declaration.name.lexeme + ">";
    }
}