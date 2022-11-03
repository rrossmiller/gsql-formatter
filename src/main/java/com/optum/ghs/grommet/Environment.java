package com.optum.ghs.grommet;

import java.util.HashMap;
import java.util.Map;

import com.optum.ghs.grommet.types.Token;
import com.optum.ghs.grommet.exception.RuntimeError;

public class Environment {
    final Environment enclosing;
    private final Map<String, Object> values = new HashMap<>();

    public Environment() {
        this.enclosing = null;
    }

    public Environment(Environment enclosing) {
        this.enclosing = enclosing;
    }

    public void define(String name, Object value) {
        // TODO static type. Variable object with type attr instead of object
        values.put(name, value); // var a = 0; var a = 1; ... second will overwrite the var. Change this for
                                 // redefining assignment
    }

    public Object get(Token name) {
        if (values.containsKey(name.lexeme))
            return values.get(name.lexeme);

        if (enclosing != null)
            return enclosing.get(name);

        throw new RuntimeError(name, "Undefined variable '" + name.lexeme + "'.");
    }

    public Object getAt(int distance, String name) {
        return ancestor(distance).values.get(name);
    }

    public Environment ancestor(int distance) {
        Environment environment = this;
        for (int i = 0; i < distance; i++) {
            environment = environment.enclosing;
        }

        return environment;
    }

    public void assign(Token name, Object value) {
        if (values.containsKey(name.lexeme)) {
            values.put(name.lexeme, value);
            return;
        }

        if (enclosing != null) {
            enclosing.assign(name, value);
            return;
        }

        throw new RuntimeError(name, "Undefined variable '" + name.lexeme + "'.");
    }

    public void assignAt(int distance, Token name, Object value) {
        ancestor(distance).values.put(name.lexeme, value);
    }

    @Override
    public String toString() {
        System.out.println("this");
        for (String k : values.keySet()) {
            System.out.println("\t" + k + " " + values.get(k));
        }
        System.out.println("enclosing");
        if (enclosing != null)
            for (String k : enclosing.values.keySet()) {
                System.out.println("\t" + k + " " + enclosing.values.get(k));
            }

        return "";
    }
}
