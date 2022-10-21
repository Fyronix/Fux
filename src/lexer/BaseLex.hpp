/**
 * @file baselex.hpp
 * @author fuechs 
 * @brief Basic C++ Lexer
 * @version 1.1 (modified)
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2020-2022 Fuechs. All rights reserved.
 * 
 * ! MODIFIED !
 */


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>

namespace BaseLex {

    using std::string, std::cout, std::vector;

    /**
     * @brief Every possible type of token
     * 
     */
    typedef enum TokenType_ENUM {
        LPAREN,         // (
        RPAREN,         // )
        LBRACE,         // {
        RBRACE,         // }
        LBRACKET,       // [
        RBRACKET,       // ]

        LESSTHAN,       // <
        GREATERTHAN,    // >
        COLON,          // :
        COLON_COLON,    // ::
        SEMICOLON,      // ;
        DOT,            // .
        TRIPLE_DOT,     // ...
        COMMA,          // ,
        EQUALS,         // =
        EQUALS_EQUALS,  // ==
        TRIPLE_EQUALS,  // ===
        NOT_EQUALS,     // !=
        PLUS,           // +
        PLUS_PLUS,      // ++
        MINUS,          // -
        MINUS_MINUS,    // --
        ASTERISK,       // *
        ASTERISK_ASTERISK,      // **
        SLASH,          // /
        PLUS_EQUALS,    // +=
        MINUS_EQUALS,   // -=
        SLASH_EQUALS,   // /=
        ASTERISK_EQUALS,// *=
        EXCLAMATION,    // !

        QUESTION,       // ?
        BACKSLASH,      /* \ */
        VERTICAL,       // |
        OR,             // ||
        HASH,           // #
        AMPERSAND,      // &
        AND,            // &&
        AT,             // @
        CARET,          // ^
        PERCENT,        // %

        LPOINTER,       // <-
        RPOINTER,       // ->
        LSHIFT,         // <<
        RSHIFT,         // >>
        LTRIPLE,        // <<<
        RTRIPLE,        // >>>

        CHARACTER,      // 'c'
        STRING,         // "string"
        INTEGER,        // 0
        FLOAT,          // 0.0
        IDENTIFIER,     // identifier  

        KEY_IF,         // if
        KEY_ELSE,       // else
        KEY_FOR,        // for
        KEY_IN,         // in
        KEY_WHILE,      // while
        KEY_DO,         // do
        KEY_SWITCH,     // switch
        KEY_CASE,       // case
        KEY_BREAK,      // break
        KEY_CONTINUE,   // continue
        KEY_RETURN,     // return
        KEY_LABEL,      // label
        KEY_GOTO,       // goto
        KEY_TRY,        // try
        KEY_CATCH,      // catch
        KEY_SELF,       // self
        KEY_USING,      // using
        KEY_TYPEDEF,    // typedef
        KEY_DELETE,     // delete
        KEY_PACKAGE,    // package

        KEY_GET,        // (#)get
        KEY_DEFINE,     // (#)define

        KEY_VOID,       // void
        KEY_BOOL,       // bool
        KEY_I8,         // i8
        KEY_U8,         // u8
        KEY_CHAR,       // char
        KEY_I16,        // i16
        KEY_U16,        // u16
        KEY_WCHAR,      // wchar
        KEY_I32,        // i32
        KEY_U32,        // u32
        KEY_FLOAT,      // float
        KEY_I64,        // i64
        KEY_U64,        // u64
        KEY_DOUBLE,     // double
        KEY_ENUM,       // enum
        KEY_STRUCT,     // struct

        EOS,            // end of source
        EOL,            // end of line
        UNKNOWN,        // initial type
    } TokenType;

    static const char *TokenTypeString[] = {
        "LPAREN", "RPAREN", "LBRACE",
        "RBRACE", "LBRACKET", "RBRACKET",

        "LESSTHAN", "GREATERTHAN", "COLON",
        "COLON_COLON", "SEMICOLON", "DOT", "TRIPLE_DOT",
        "COMMA", "EQUALS", "EQUALS_EQUALS", 
        "TRIPLE_EQUALS", "NOT_EQUALS", "PLUS", 
        "PLUS_PLUS", "MINUS", "MINUS_MINUS", 
        "ASTERISK", "ASTERISK_ASTERISK", "SLASH", 
        "PLUS_EQUALS", "MINUS_EQUALS", "SLASH_EQUALS", 
        "ASTERISK_EQUALS", "EXCLAMATION",  

        "QUESTION", "BACKSLASH", "VERTICAL",      
        "OR", "HASH", "AMPERSAND", 
        "AND", "AT", "CARET", "PERCENT",      

        "LPOINTER", "RPOINTER",
        "LSHIFT", "RSHIFT",  
        "LTRIPLE", "RTRIPLE",    

        "CHARACTER", "STRING",       
        "INTEGER", "FLOAT",          
        "IDENTIFIER", 

        "KEY_IF", "KEY_ELSE", "KEY_FOR", "KEY_IN",         
        "KEY_WHILE", "KEY_DO", "KEY_SWITCH",     
        "KEY_CASE", "KEY_BREAK", "KEY_CONTINUE",   
        "KEY_RETURN", "KEY_LABEL", "KEY_GOTO",    
        "KEY_TRY", "KEY_CATCH", "KEY_SELF",      
        "KEY_USING", "KEY_TYPEDEF", "KEY_DELETE",
        "KEY_PACKAGE",

        "KEY_GET", "KEY_DEFINE",   

        "KEY_VOID", "KEY_BOOL",
        "KEY_I8", "KEY_U8", "KEY_CHAR",      
        "KEY_I16", "KEY_U16", "KEY_WCHAR",  
        "KEY_I32", "KEY_U32", "KEY_FLOAT",  
        "KEY_I64", "KEY_U64", "KEY_DOUBLE",
        "KEY_ENUM", "KEY_STRUCT",

        "EOS", "EOL", "UNKNOWN",        
    };

    static const char *TokenTypeValue[] = {
        "(", ")", "{", "}", "[", "]",

        "<", ">", ":", "::", ";", ".", "...",
        ",", "=", "==", "===", "!=", "+", 
        "++", "-", "--", "*", "**", "/", 
        "+=", "-=", "/=", "*=", "!",  

        "?", "\\", "|", "||", "#", 
        "&", "&&", "@", "^", "%",        

        "->", "<-", "<<", ">>",  
        "<<<", ">>>",    

        "char", "str",       
        "int", "float",          
        "identifer", 

        "if", "else", "for", "in",         
        "while", "do", "switch",     
        "case", "break", "continue",   
        "return", "label", "goto",    
        "try", "catch", "self",      
        "using", "typedef", "delete",
        "package",

        "get", "define",

        "void", "bool",
        "i8", "u8", "char",      
        "i16", "u16", "wchar",  
        "i32", "u32", "float",  
        "i64", "u64", "double",
        "enum", "struct",

        "EOS", "\\n", "unknown", 
    };

    class Token {
    public:
        Token(TokenType type = UNKNOWN, string value = "") 
        : type(type), value(value) {}

        TokenType type;
        string value;

        /**
         * @brief Exact position of the token for error tracking
         * 
         */
        size_t line = 0;
        size_t col = 0;

        /**
         * @brief Prints out information about the token
         * 
         */
        void debugPrint() {
            cout    << "<Token, "
                    << TokenTypeString[type]
                    << ", '" 
                    << value 
                    << "', "
                    << "Line "
                    << line
                    << ":"
                    << col
                    << ">\n";
        }

    };

    typedef vector<Token> TokenList;

    class Lexer {
    public:
        Lexer(const string input = "", bool detectNewLine = false) 
        : source(input), detectNewLine(detectNewLine) {}

        /**
         * @brief Tokenizes the program source
         * 
         * @param source : Program source
         * @return TokenList : Vector of all tokens collected
         */
        TokenList lex() {

            TokenList tokens;
            Token currentToken;

            currentToken.line = 1;
            currentToken.col = 1;

            while (idx < source.length()) {

                tokenize(currentToken);

                switch (currentToken.type) {
                    
                    case IDENTIFIER: {
                        while (lex_identifier(currentToken) && idx < source.length())
                            advance();

                        // check for keywords
                        if      (currentToken.value == "if")        currentToken.type = KEY_IF;
                        else if (currentToken.value == "else")      currentToken.type = KEY_ELSE;
                        else if (currentToken.value == "for")       currentToken.type = KEY_FOR;
                        else if (currentToken.value == "in")        currentToken.type = KEY_IN;
                        else if (currentToken.value == "while")     currentToken.type = KEY_WHILE;
                        else if (currentToken.value == "do")        currentToken.type = KEY_DO;
                        else if (currentToken.value == "switch")    currentToken.type = KEY_SWITCH;
                        else if (currentToken.value == "case")      currentToken.type = KEY_CASE;
                        else if (currentToken.value == "break")     currentToken.type = KEY_BREAK;
                        else if (currentToken.value == "continue")  currentToken.type = KEY_CONTINUE;
                        else if (currentToken.value == "return")    currentToken.type = KEY_RETURN;
                        else if (currentToken.value == "label")     currentToken.type = KEY_LABEL;
                        else if (currentToken.value == "goto")      currentToken.type = KEY_GOTO;
                        else if (currentToken.value == "try")       currentToken.type = KEY_TRY;
                        else if (currentToken.value == "catch")     currentToken.type = KEY_CATCH;
                        else if (currentToken.value == "self")      currentToken.type = KEY_SELF;
                        else if (currentToken.value == "using")     currentToken.type = KEY_USING;
                        else if (currentToken.value == "typedef")   currentToken.type = KEY_TYPEDEF;
                        else if (currentToken.value == "delete")    currentToken.type = KEY_DELETE;
                        else if (currentToken.value == "package")   currentToken.type = KEY_PACKAGE;

                        else if (currentToken.value == "get")       currentToken.type = KEY_GET;
                        else if (currentToken.value == "define")    currentToken.type = KEY_DEFINE;

                        else if (currentToken.value == "void")      currentToken.type = KEY_VOID;
                        else if (currentToken.value == "bool")      currentToken.type = KEY_BOOL;
                        else if (currentToken.value == "i8")        currentToken.type = KEY_I8;
                        else if (currentToken.value == "u8")        currentToken.type = KEY_U8;
                        else if (currentToken.value == "char")      currentToken.type = KEY_CHAR;
                        else if (currentToken.value == "i16")       currentToken.type = KEY_I16;
                        else if (currentToken.value == "u16")       currentToken.type = KEY_U16;
                        else if (currentToken.value == "wchar")     currentToken.type = KEY_WCHAR;
                        else if (currentToken.value == "i32")       currentToken.type = KEY_I32;
                        else if (currentToken.value == "u32")       currentToken.type = KEY_U32;
                        else if (currentToken.value == "float")     currentToken.type = KEY_FLOAT;
                        else if (currentToken.value == "i64")       currentToken.type = KEY_I64;
                        else if (currentToken.value == "u64")       currentToken.type = KEY_U64;
                        else if (currentToken.value == "double")    currentToken.type = KEY_DOUBLE;
                        else if (currentToken.value == "enum")      currentToken.type = KEY_ENUM;
                        else if (currentToken.value == "struct")    currentToken.type = KEY_STRUCT;

                        endToken(currentToken, tokens);
                        currentToken.col = col;
                        currentToken.line = line;
                        break;
                    }

                    case STRING: {
                        advance();
                        while (current() != '"') {
                            currentToken.value.push_back(current());
                            advance();
                        }
                        endToken(currentToken, tokens);
                        advance();
                        currentToken.col = col;
                        currentToken.line = line;
                        break;
                    }

                    case FLOAT:
                    case INTEGER: {
                        while (isdigit(current()) || current() == '_') {
                            if (current() == '_')
                                advance();
                            else {
                                currentToken.value.push_back(current());
                                advance();
                            }
                        }
                        if (current() == '.') {
                            if (peek() == '.') {
                                std::cerr
                                << "Unexpected second '.' in float definition on Line "
                                << line << ":" << col << " .\n";
                                exit(1);
                            }

                            if (!isdigit(peek())) {
                                std::cerr
                                << "Unexpected character '"
                                << peek()
                                << "' in integer definition on Line "
                                << line << ":" << col << " .\n";
                                exit(1);
                            }

                            if (currentToken.type == FLOAT) {
                                std::cerr
                                << "Unexpected character '.' in float definition on Line "
                                << line << ":" << col << " .\n";
                                exit(1);
                            }

                            currentToken.type = FLOAT;
                            currentToken.value.push_back(current());
                            advance();
                            while (isdigit(current())) {
                                currentToken.value.push_back(current());
                                advance();
                            }
                        }
                        endToken(currentToken, tokens);
                        currentToken.col = col;
                        currentToken.line = line;
                        break;
                    }

                    default: {
                        endToken(currentToken, tokens);
                        currentToken.col = col;
                        currentToken.line = line;
                        break;
                    }

                }

            }

            currentToken.type = EOS;
            currentToken.value = "EOS";
            endToken(currentToken, tokens);

            return tokens;
        
        }

    private:
        const string source;
        size_t idx = 0; // character index in source
        size_t col = 1; // column; resets every newline
        size_t line = 1;

        bool detectNewLine;

        /**
         * @brief returns character in source at an offset
         * 
         * @param offset : provided offset
         * @return char : found character
         * 
         */
        char peek(int offset = 1) {
            return source[idx+offset];
        }

        /**
         * @brief advances the lexer
         * 
         * @param steps : advances N steps
         */
        void advance(int steps = 1) {
            idx += steps;
            col += steps;
        }

        /**
         * @brief resets token position
         * 
         */
        void resetPos() {
            col = 1;
            ++line;
        }

        /**
         * @brief returns current char 
         * 
         * @return char 
         */
        char current() {
            return source[idx];
        }

        /**
         * @brief reads source and detects one token
         * 
         * @param token : current token from Lexer::lex()
         * 
         */
        void tokenize(Token &token) {

            switch (current()) {
                    case '(': {
                        token.type = LPAREN;
                        token.value = "(";
                        advance();
                        break;
                    }

                    case ')': {
                        token.type = RPAREN;
                        token.value = ")";
                        advance();
                        break;
                    }

                    case '{': {
                        token.type = LBRACE;
                        token.value = "{";
                        advance();
                        break;
                    }

                    case '}': {
                        token.type = RBRACE;
                        token.value = "}";
                        advance();
                        break;
                    }

                    case '[': {
                        token.type = LBRACKET;
                        token.value = "[";
                        advance();
                        break;
                    }

                    case ']': {
                        token.type = RBRACKET;
                        token.value = "]";
                        advance();
                        break;
                    }

                    case '<': {
                        if (peek() == '<') {
                            if (peek(2) == '<') {
                                token.type = LTRIPLE;
                                token.value = "<<<";
                                advance(3);
                                break;
                            }

                            token.type = LSHIFT;
                            token.value = "<<";
                            advance(2);
                            break;
                        }

                        if (peek() == '-') {
                            token.type = LPOINTER;
                            token.value = "<-";
                            advance(2);
                            break;
                        }
                        
                        token.type = LESSTHAN;
                        token.value = "<";
                        advance();
                        break;
                    }

                    case '>': {
                        if (peek() == '>') {
                            if (peek(2) == '>') {
                                token.type = RTRIPLE;
                                token.value = ">>>";
                                advance(3);
                                break;
                            }

                            token.type = RSHIFT;
                            token.value = ">>";
                            advance(2);
                            break;
                        }
                        
                        token.type = GREATERTHAN;
                        token.value = ">";
                        advance();
                        break;
                    }

                    case ':': {
                        if (peek() == ':') {
                            token.type = COLON_COLON;
                            token.value = "::";
                            advance(2);
                            break;
                        }
                        
                        token.type = COLON;
                        token.value = ":";
                        advance();
                        break;
                    }

                    case ';': {
                        token.type = SEMICOLON;
                        token.value = ";";
                        advance();
                        break;
                    }

                    case '.': {
                        if (peek() == '.' && peek(2) == '.') {
                            token.type = TRIPLE_DOT;
                            token.value = "...";
                            advance(3);
                            break;
                        }
                        token.type = DOT;
                        token.value = ".";
                        advance();
                        break;
                    }

                    case ',': {
                        token.type = COMMA;
                        token.value = ",";
                        advance();
                        break;
                    }

                    case '=': {
                        if (peek() == '=') {
                            if (peek(2) == '=') {
                                token.type = TRIPLE_EQUALS;
                                token.value = "===";
                                advance(3);
                                break;
                            }

                            token.type = EQUALS_EQUALS;
                            token.value = "==";
                            advance(2);
                            break;
                        }
                        
                        token.type = EQUALS;
                        token.value = "=";
                        advance();
                        break;
                    }

                    case '+': {
                        if (peek() == '+') {
                            token.type = PLUS_PLUS;
                            token.value = "++";
                            advance(2);
                            break;
                        }  

                        if (peek() == '=') {
                            token.type = PLUS_EQUALS;
                            token.value = "+=";
                            advance(2);
                            break;
                        }

                        token.type = PLUS;
                        token.value = "+";
                        advance();
                        break;
                    }

                    case '-': {
                        if (peek() == '-') {
                            token.type = MINUS_MINUS;
                            token.value = "--";
                            advance(2);
                            break;
                        }

                        if (peek() == '=') {
                            token.type = MINUS_EQUALS;
                            token.value = "-=";
                            advance(2);
                            break;
                        }

                        if (peek() == '>') {
                            token.type = RPOINTER;
                            token.value = "->";
                            advance(2);
                            break;
                        }

                        token.type = MINUS;
                        token.value = "-";
                        advance();
                        break;
                    }

                    case '/': {
                        if (peek() == '/') {
                            idx += 2;
                            while (current() != '\n')
                                ++idx;
                            ++idx;
                            resetPos();
                            break;
                        } 
                        
                        if (peek() == '=') {
                            token.type = SLASH_EQUALS;
                            token.value = "/=";
                            advance(2);
                            break;
                        }

                        token.type = SLASH;
                        token.value = "/";    
                        advance();                  
                        break;
                    }

                    case '*': {
                        if (peek() == '*') {
                            token.type = ASTERISK_ASTERISK;
                            token.value = "**";
                            advance(2);
                            break;
                        }
                        
                        if (peek() == '=') {
                            token.type = ASTERISK_EQUALS;
                            token.value = "*=";
                            advance(2);
                            break;
                        }

                        token.type = ASTERISK;
                        token.value = "*";
                        advance();
                        break;
                    }

                    case '!': {
                        if (peek() == '=') {
                            token.type = NOT_EQUALS;
                            token.value = "!=";
                            advance(2);
                            break;
                        }

                        token.type = EXCLAMATION;
                        token.value = "!";
                        advance();
                        break;
                    }

                    case '?': {
                        token.type = QUESTION;
                        token.value = "?";
                        advance();
                        break;
                    }

                    case '\\': {
                        token.type = BACKSLASH;
                        token.value = "\\";
                        advance();
                        break;
                    }

                    case '|': {
                        if (peek() == '|') {
                            token.type = OR;
                            token.value = "||";
                            advance(2);
                            break;
                        }

                        token.type = VERTICAL;
                        token.value = "|";
                        advance();
                        break;
                    }

                    case '#': {
                        token.type = HASH;
                        token.value = "#";
                        advance();
                        break;
                    }

                    case '&': {
                        if (peek() == '&') {
                            token.type = AND;
                            token.value = "&&";
                            advance(2);
                            break;
                        }

                        token.type = AMPERSAND;
                        token.value = "&";
                        advance();
                        break;
                    }

                    case '@': {
                        token.type = AT;
                        token.value = "@";
                        advance();
                        break;
                    }

                    case '^': {
                        token.type = CARET;
                        token.value = "^";
                        advance();
                        break;
                    }

                    case '%': {
                        token.type = PERCENT;
                        token.value = "%";
                        advance();
                        break;
                    }

                    case '\'': {
                        token.type = CHARACTER;
                        advance();
                        token.value.push_back(current());
                        advance();
                        if (current() != '\'') {
                            // TODO: implement proper errors
                            std::cerr 
                            << "Invalid character expression at Line "
                            << line << ":" << col << ".\n";
                            exit(1);
                        }
                        advance();
                        break;
                    }

                    case '"': {
                        token.type = STRING;
                        advance();
                        token.value.push_back(current());
                        break;
                    }

                    case ' ':
                    case '\t': {
                        advance();
                        break;
                    }

                    case '\n':
                    case '\r': {
                        ++idx;
                        if (detectNewLine) {
                            token.type = EOL;
                            token.value = "\\n";
                        }
                        resetPos();
                        break;
                    }

                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9': {
                        token.type = INTEGER;
                        token.value.push_back(current());
                        advance();
                        break;
                    }

                    default: {                        
                        token.type = IDENTIFIER;
                        token.value.push_back(current());
                        advance();
                        break;
                    }

            }
        }

        /**
         * @brief Appends token to TokenList and resets current token
         * 
         * @param token : Token to append
         * @param tokens : TokenList to append to
         * 
         */
        void endToken(Token &token, TokenList &tokens) {
            if (token.type != UNKNOWN) 
                tokens.push_back(token);

            token.type = UNKNOWN;
            token.value.erase();
        }

        /**
         * @brief Lex one identifier
         * 
         * @param token : identifier token
         * @return true : continue lexing identifier
         * @return false : stop lexing identifier
         */
        bool lex_identifier(Token &token) {

            if (isalpha(current())
            ||  isdigit(current())
            ||  current() == '_') {
                token.value.push_back(current());
                return true;
            } else 
                return false;

        }

    };

}