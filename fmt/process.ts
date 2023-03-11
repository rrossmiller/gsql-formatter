import {accumTypes, keywords} from './keywords';

/**
 * Only need to capture some cases. No need to label all tokens like a normal lexer
 *
 * Thanks to https://craftinginterpreters.com
 */
export class Preprocessor {
    tokens: string[] = [];
    sourceCode: string;
    start: number = 0;
    current: number = 0;
    constructor(sourceCode: string) {
        this.sourceCode = sourceCode;
    }

    // run the scanner
    scan(): string {
        while (!this.isAtEnd()) {
            this.start = this.current;
            // scan token
            this.scanToken();
        }
        return this.tokens.join('');
    }

    scanToken(): void {
        let c = this.advance();
        // console.log('--', c);

        switch (c) {
            case '/':
                // A comment goes to the end of the line
                if (this.findMatch('/')) {
                    while (this.peek() !== '\n' || this.isAtEnd()) {
                        this.advance();
                    }
                } else if (this.findMatch('*')) {
                    // A block comment goes until '*/' termination
                    while (!this.isAtEnd() && this.peek() != '*' && this.peekNext() != '/') {
                        this.advance();
                    }
                    // consume */
                    this.advanceN(2);
                }
                // this.numStatements++;
                this.addToken();
                break;

            case "'": // prefer double quote string literals
                this.sourceCode = this.sourceCode.slice(0, this.current - 1) + '"' + this.sourceCode.slice(this.current);
                this.addToken();
                break;
            case ' ':
            case '\t':
                // console.log(this.tokens);

                this.whiteSpace();
                break;
            case '\n':
                this.newline();
            default:
                if (this.isAlpha(c)) {
                    this.identifier();
                } else {
                    this.addToken();
                }
                break;
        }
    }

    whiteSpace() {
        if (!this.tokens[this.tokens.length - 1].match(/^[\ \t\n]$/)) {
            this.addToken();
        }
    }

    newline() {
        const prevTkn = this.tokens[this.tokens.length - 2];
        const prevEOL = this.tokens[this.tokens.length - 1];

        if (prevTkn !== undefined && prevEOL === '\n') {
            this.tokens.push('<_-_-_>');
        } else if (prevTkn !== undefined && prevTkn[prevTkn.length - 1] === ';' && prevEOL !== '\n') {
            console.log(prevTkn[prevTkn.length - 1], '-', prevEOL);
        }
    }

    identifier() {
        while (this.isAlphaNumeric()) {
            this.advance();
        }

        const text = this.sourceCode.slice(this.start, this.current).trim().toUpperCase();
        if (keywords.includes(text) && (this.peek() === ' ' || this.peek() === '\n' || this.isAtEnd())) {
            this.tokens.push(text);
            return;
        } else if (Object.keys(accumTypes).includes(text)) {
            this.tokens.push(text);
            return;
        }

        this.addToken();
    }

    findMatch(expected: string): boolean {
        if (this.isAtEnd()) return false;
        if (this.sourceCode.charAt(this.current) != expected) return false;

        this.current++;
        return true;
    }

    peek(): string {
        if (this.isAtEnd()) return '';
        return this.sourceCode.charAt(this.current);
    }

    peekNext(): string {
        if (this.current + 1 >= this.sourceCode.length) return '';
        return this.sourceCode.charAt(this.current + 1);
    }

    advance(): string {
        // return current, then advance current
        return this.sourceCode.charAt(this.current++);
    }

    advanceN(n: number): string {
        let rtn = '';
        for (let i = 0; i < n; i++) {
            rtn += this.advance();
        }
        return rtn;
    }

    isAtEnd(): boolean {
        return this.current >= this.sourceCode.length;
    }

    isAlpha(c: string): boolean {
        return c.match(/[a-zA-Z]/) !== null;
    }

    isDigit(c: string): boolean {
        return c.match(/[0-9]/) !== null;
    }

    isAlphaNumeric(): boolean {
        return this.isAlpha(this.peek()) || this.isDigit(this.peek());
    }

    addToken() {
        const text = this.sourceCode.slice(this.start, this.current);
        this.tokens.push(text);
    }
}

// post process to set accum names to be camel case
export class Postprocessor extends Preprocessor {
    tokens: string[] = [];
    start: number = 0;
    current: number = 0;
    constructor(sourceCode: string) {
        super(sourceCode);
    }

    scan(): string {
        while (!this.isAtEnd()) {
            this.start = this.current;
            // scan token
            this.scanToken();
        }
        return this.tokens.join('').replaceAll('<_-_-_>', '');
    }

    newline(): void {}

    whiteSpace() {
        this.addToken();
    }
    identifier() {
        while (this.isAlphaNumeric()) {
            this.advance();
        }

        const text = this.sourceCode.slice(this.start, this.current).trim().toUpperCase();
        if (keywords.includes(text) && (this.peek() === ' ' || this.peek() === '\n' || this.isAtEnd())) {
            this.tokens.push(text);
            return;
        } else if (Object.keys(accumTypes).includes(text)) {
            this.tokens.push(accumTypes[text]); // reset accum names to be camel case
            return;
        }

        this.addToken();
    }
}
