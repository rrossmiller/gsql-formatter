package com.optum.ghs.grommet.types;

import java.util.HashMap;
import java.util.Map;

import com.optum.ghs.grommet.exception.RuntimeError;

public class GsqlInstance {
    private GsqlClass klass;
    private final Map<String, Object> fields = new HashMap<>();

    public GsqlInstance(GsqlClass klass) {
        this.klass = klass;
    }

    public Object get(Token name) {
        if (fields.containsKey(name.lexeme)) {
            return fields.get(name.lexeme);
        }
        GsqlFunction method = klass.findMethod(name.lexeme);
        if (method != null)
            return method.bind(this);

        throw new RuntimeError(name, "Undefined property '" + name.lexeme + "'.");
    }

    public void set(Token name, Object value) {
        fields.put(name.lexeme, value);
    }

    @Override
    public String toString() {
        return klass.name + " instance";
    }
}