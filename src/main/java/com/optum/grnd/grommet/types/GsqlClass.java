package com.optum.grnd.grommet.types;

import java.util.List;
import java.util.Map;

import com.optum.grnd.grommet.Interpreter;

public class GsqlClass implements GsqlCallable {
    final String name;
    final GsqlClass superclass;
    private final Map<String, GsqlFunction> methods;

    public GsqlClass(String name, GsqlClass superclass, Map<String, GsqlFunction> methods) {
        this.superclass = superclass;
        this.name = name;
        this.methods = methods;
    }

    @Override
    public Object call(Interpreter interpreter,
            List<Object> arguments) {
        GsqlInstance instance = new GsqlInstance(this);
        GsqlFunction initializer = findMethod("init");
        if (initializer != null) {
            initializer.bind(instance).call(interpreter, arguments);
        }

        return instance;
    }

    @Override
    public int arity() {
        GsqlFunction initializer = findMethod("init");
        if (initializer == null)
            return 0;
        return initializer.arity();
    }

    public GsqlFunction findMethod(String name) {
        if (methods.containsKey(name)) {
            return methods.get(name);
        }

        if (superclass != null) {
            return superclass.findMethod(name);
        }

        return null;
    }

    @Override
    public String toString() {
        return name;
    }
}
