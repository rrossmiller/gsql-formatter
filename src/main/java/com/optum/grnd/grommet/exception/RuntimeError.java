package com.optum.grnd.grommet.exception;

import com.optum.grnd.grommet.types.Token;

public class RuntimeError extends RuntimeException {
    public final Token token;

    public RuntimeError(Token token, String message) {
        super(message);
        this.token = token;
    }
}