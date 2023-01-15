/**
 * @file expr.hpp
 * @author fuechs
 * @brief expr ast class header
 * @version 0.1
 * @date 2023-01-14
 * 
 * @copyright Copyright (c) 2020-2023, Fux programming language and authors. All rights reserved.
 * 
 */

#pragma once

#include "../../backend/generator/wrapper.hpp"
#include "position.hpp"
#include "stmt.hpp"

class ExprAST : public StmtAST {
public:
    virtual ~ExprAST() {}
    virtual Value *codegen(LLVMWrapper *fuxLLVM) = 0;
    virtual StmtPtr analyse() = 0;
    virtual void debugPrint() = 0;

    Position pos = Position();
};

typedef unique_ptr<ExprAST> ExprPtr;
typedef vector<ExprPtr> ExprList;

extern ExprPtr nullExpr;