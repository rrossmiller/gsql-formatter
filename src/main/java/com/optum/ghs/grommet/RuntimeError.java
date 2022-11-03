package com.optum.ghs.grommet;

import com.optum.ghs.grommet.types.Token;

class RuntimeError extends RuntimeException{
    final Token token;
    
    RuntimeError(Token token, String message){
        super(message);
        this.token = token;
    }
}