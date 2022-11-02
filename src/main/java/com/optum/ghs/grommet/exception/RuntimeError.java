package com.optum.ghs.grommet.exception;

import com.optum.ghs.grommet.types.Token;

public class RuntimeError extends RuntimeException {
    public final Token token;

    public RuntimeError(Token token, String message) {
        super(message);
        this.token = token;
    }
}