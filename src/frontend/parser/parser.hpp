/**
 * @file parser.hpp
 * @author fuechs
 * @brief fux parser header
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2020-2022, Fuechs. All rights reserved.
 * 
 */

#pragma once

#include "../../fux.hpp"
#include "ast.hpp"
#include "../error/error.hpp"
#include "../lexer/lexer.hpp"
#include "../lexer/token.hpp"

class Parser {
public:
    Parser(ErrorManager *error, string fileName, string source, bool mainFile = false) 
    : error(error) {
        lexer = new Lexer(source, fileName, error);
        if (mainFile)
            fux.options.fileLines = lexer->getLines();
        root = new AST(nullptr, AST_ROOT);
    }

    ~Parser() {
        delete lexer;
        tokens.clear();
    }

    // parse the Tokens and return AST root
    AST *parse();

private:
    TokenList tokens;
    TokenIter current;
    ErrorManager *error;
    Lexer *lexer;
    AST *root;

    // parse a statement
    AST *parseStmt(AST *parent);
    // parse a variable declaration
    AST *parseVarDecl(AST *parent);
    // parse a type
    AST *parseType(AST *parent);

    // parse an expression
    AST *parseExpr(AST *parent);
    // parse an additive expression 
    // + || -
    AST *parseAdditiveExpr(AST *parent);
    // parse a multiplicative expression
    // / || * || %
    AST *parseMultiplicativeExpr(AST *parent);
    // parse a primary expression
    AST *parsePrimaryExpr(AST *parent);
    
    // int64_t parseNumber(string str);

    // get next token
    Token eat();
    // expect an token
    Token expect(TokenType type, ErrorType errType = UNEXPECTED_TOKEN);
    // check wether end of file is reached
    bool notEOF();
};