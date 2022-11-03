package com.optum.ghs.grommet.types;

import java.util.List;

import com.optum.ghs.grommet.Interpreter;

public interface GsqlCallable {
    public Object call(Interpreter interpreter, List<Object> args);

    public int arity();
}