package com.optum.ghs.grommet.types;

import java.util.List;
import java.util.Map;

import com.optum.ghs.grommet.Interpreter;

public class GsqlClass implements GsqlCallable {
    final String name;
    private final Map<String, GsqlFunction> methods;

    public GsqlClass(String name, Map<String, GsqlFunction> methods) {
        this.name = name;
        this.methods = methods;
    }

    @Override
    public Object call(Interpreter interpreter, List<Object> arguments) {
        GsqlInstance instance = new GsqlInstance(this);
        return instance;
    }

    @Override
    public int arity() {
        return 0;
    }

    GsqlFunction findMethod(String name) {
        if (methods.containsKey(name)) {
            return methods.get(name);
        }

        return null;
    }

    @Override
    public String toString() {
        return name;
    }
}