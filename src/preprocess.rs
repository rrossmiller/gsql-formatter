use crate::keywords::{contains_accum_type, KEYWORDS};

/// Only need to capture some cases. No need to label all tokens like a normal lexer
///
///  Thanks to https://craftinginterpreters.com

pub struct Processor {
    tokens: Vec<String>,
    src_chars: Vec<char>,
    current: usize,
    start: usize,
}
impl Processor {
    pub fn new(src: &String) -> Processor {
        Processor {
            tokens: Vec::new(),
            src_chars: src.chars().collect(),
            current: 0,
            start: 0,
        }
    }

    pub fn preprocess(&mut self) -> Result<String, String> {
        // run the scanner
        while !self.is_at_end() {
            self.start = self.current;
            //scan the token
            self.scan();
        }

        Ok(self.tokens.join(""))
    }
    fn scan(&mut self) {
        let c = self.advance();
        match c {
            '/' => {
                // A comment goes to the end of the line
                if self.find_match('/') {
                    while self.peek() != '\n' && !self.is_at_end() {
                        self.advance();
                    }
                } else if self.find_match('*') {
                    // A block comment goes until '*/' termination
                    while !self.is_at_end() && self.peek() != '*' || self.peek_next() != '/' {
                        self.advance();
                    }
                    // consume */
                    self.advance_n(2);
                }
                self.add_token();
            }
            '\'' => {
                // prefer double quote string literals
                self.src_chars[self.current - 1] = '"';
                self.add_token();
            }
            ' ' | '\t' => {
                self.add_token();
            }
            '\n' => {
                // self.new_line();
                self.add_token();
            }
            _ => {
                if c.is_alphabetic() {
                    self.identifier();
                } else {
                    self.add_token();
                }
            }
        }
    }

    fn advance(&mut self) -> char {
        let r = self.src_chars[self.current]; // get the current token
        self.current += 1; // "consume" the token
        r
    }

    fn advance_n(&mut self, n: usize) -> char {
        self.current += n;
        self.src_chars[self.current - 1]
    }

    fn peek(&self) -> char {
        if self.is_at_end() {
            return '√';
        }
        self.src_chars[self.current]
    }

    fn peek_next(&self) -> char {
        if self.current + 1 >= self.src_chars.len() {
            return '√';
        }
        return self.src_chars[self.current + 1];
    }

    fn identifier(&mut self) -> bool {
        while self.peek().is_alphanumeric() {
            self.advance();
        }

        let text = self.src_chars[self.start..self.current]
            .iter()
            .collect::<String>()
            .to_uppercase();

        if KEYWORDS.contains(&text.as_str())
            && (self.peek() == ' '
                || self.peek() == '\n'
                || self.peek() == '>'
                || self.peek() == '<'
                || self.peek() == ')'
                || self.peek() == '('
                || self.peek() == ','
                || self.is_at_end())
        {
            self.tokens.push(text);
            return true;
        } else if let Some(v) = contains_accum_type(text) {
            self.tokens.push(v);
            return true;
        }

        self.add_token();
        false
    }

    fn add_token(&mut self) {
        let text = self.src_chars[self.start..self.current].iter().collect();
        self.tokens.push(text);
    }

    fn find_match(&mut self, expected: char) -> bool {
        if self.is_at_end() || self.src_chars[self.current] != expected {
            return false;
        }

        self.current += 1; // consume the expected token
        true
    }

    fn is_at_end(&self) -> bool {
        return self.current >= self.src_chars.len();
    }

    // fn new_line(&mut self) {
    // handle too many new lines (max 2 new lines between things)

    // if self.tokens.len() >= 2 {
    //     let prev_eol = &self.tokens[self.tokens.len() - 1];
    //     // println!("prev: {}", prev_eol);
    //     if prev_eol == "\n" {
    //         // println!("newline");
    //         self.tokens.push("<_-_-_>".to_string());
    //     }
    // }
    // }
}
