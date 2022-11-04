package com.optum.grnd.grommet.types;

public class FunReturn extends RuntimeException {
    public final Object value;

    public FunReturn(Object value) {
        super(null, null, false, false);
        this.value = value;
    }
}