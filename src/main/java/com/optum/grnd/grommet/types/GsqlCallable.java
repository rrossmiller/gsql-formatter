package com.optum.grnd.grommet.types;

import java.util.List;

import com.optum.grnd.grommet.Interpreter;

public interface GsqlCallable {
    public Object call(Interpreter interpreter, List<Object> args);

    public int arity();
}