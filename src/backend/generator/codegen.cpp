/**
 * @file codegen.cpp
 * @author fuechs
 * @brief fux ast codegen functions
 * @version 0.1
 * @date 2023-01-19
 * 
 * @copyright Copyright (c) 2020-2023, Fuechs and Contributors. All rights reserved.
 * 
 */

#include "../../frontend/ast/ast.hpp"
#include "generator.hpp"

#ifdef FUX_BACKEND

Value *NullExprAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Value *BoolExprAST::codegen(LLVMWrapper *fuxLLVM) { return value->getLLVMValue(fuxLLVM); }

Value *NumberExprAST::codegen(LLVMWrapper *fuxLLVM) { return value->getLLVMValue(fuxLLVM); }

Value *CharExprAST::codegen(LLVMWrapper *fuxLLVM) { return value->getLLVMValue(fuxLLVM); }

Value *StringExprAST::codegen(LLVMWrapper *fuxLLVM) { return value->getLLVMValue(fuxLLVM); }

Value *ArrayExprAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Value *VariableExprAST::codegen(LLVMWrapper *fuxLLVM) { return fuxLLVM->namedValues[name]; }

Value *MemberExprAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Value *CallExprAST::codegen(LLVMWrapper *fuxLLVM) {
    // Function *calleeFunc = callee->codegen(fuxLLVM);
    // if (!calleeFunc)
        // return nullptr;
    
    // if (calleeFunc->arg_size() != args.size())
        // return nullptr;

    // ValueList argList;
    // for (size_t i = 0, e = args.size(); i != e; ++i) {
    //     argList.push_back(args[i]->codegen(fuxLLVM));
    //     if (!argList.back())    
    //         return nullptr;
    // }

    // return fuxLLVM->builder->CreateCall(calleeFunc, argList, "calltmp");
    return nullptr;
} 

Value *RangeExprAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Value *UnaryExprAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Value *BinaryExprAST::codegen(LLVMWrapper *fuxLLVM) {
    Value *L = LHS->codegen(fuxLLVM);
    Value *R = RHS->codegen(fuxLLVM);
    if (!L || !R)
        return nullptr;

    switch (op) {
        using enum BinaryOp;
        case ADD:   return fuxLLVM->builder->CreateAdd(L, R, "addtmp");
        case SUB:   return fuxLLVM->builder->CreateSub(L, R, "subtmp");
        case MUL:   return fuxLLVM->builder->CreateMul(L, R, "multmp");
        case DIV:   return fuxLLVM->builder->CreateFDiv(L, R, "divtmp");
        default:    return nullptr;
    }
}

Value *TypeCastExprAST::codegen(LLVMWrapper *fuxLLVM) {
    Value *valToCast = expr->codegen(fuxLLVM);
    return fuxLLVM->builder->CreateZExt(valToCast, Generator::getType(fuxLLVM, type));
}

Value *TernaryExprAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Value *VariableDeclAST::codegen(LLVMWrapper *fuxLLVM) {
    Value *that = fuxLLVM->builder->CreateAlloca(Generator::getType(fuxLLVM, type), 0, symbol);
    if (value) 
        fuxLLVM->builder->CreateStore(value->codegen(fuxLLVM), that);
    fuxLLVM->namedValues[symbol] = that;
    return that;
}

Value *InbuiltCallAST::codegen(LLVMWrapper *fuxLLVM) {
    switch (callee) {
        using enum Inbuilts;
        case RETURN:    return arguments.at(0)->codegen(fuxLLVM);
        default:        return nullptr;
    }
}

Value *IfElseAST::codegen(LLVMWrapper *fuxLLVM) {
    return nullptr;
}

Value *CodeBlockAST::codegen(LLVMWrapper *fuxLLVM) {
    Value *ret = nullptr;
    for (StmtAST::Ptr &stmt : body)
        ret = stmt->codegen(fuxLLVM);
    return ret;
}

Value *WhileLoopAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Value *ForLoopAST::codegen(LLVMWrapper *fuxLLVM) { return nullptr; }

Function *PrototypeAST::codegen(LLVMWrapper *fuxLLVM) {
    // TypeList argTypes(args.size(), fuxLLVM->builder->getInt32Ty());
    FunctionType *funcType = FunctionType::get(Generator::getType(fuxLLVM, type), false);
    Function *func = Function::Create(funcType, Function::ExternalLinkage, symbol == "main" ? "main" : "Usr_"+symbol, *fuxLLVM->module);
    return func;
}

Function *FunctionAST::codegen(LLVMWrapper *fuxLLVM) {
    Function *func = fuxLLVM->module->getFunction(proto->getSymbol());  
    if (!func)  func = proto->codegen(fuxLLVM);
    if (!func)  return nullptr; 
    
    if (!func->empty()) 
        return nullptr; // cannot be redefined

    BasicBlock *BB = BasicBlock::Create(*fuxLLVM->context, "entry", func);
    fuxLLVM->builder->SetInsertPoint(BB);

    fuxLLVM->namedValues.clear();
    for (auto &arg : func->args())
        fuxLLVM->namedValues[arg.getName().str()] = &arg;

    // FIXME: This does not work as expected, 
    // body of the function is missing in the IR
    Value *retVal = body->codegen(fuxLLVM);
    
    if (func->getReturnType()->isVoidTy()) 
        fuxLLVM->builder->CreateRetVoid();
    else if (retVal) {
        if (retVal->getType()->isPointerTy()) {
            retVal = fuxLLVM->builder->CreateZExt(retVal, func->getReturnType());
        }
        Type *retType;
        while ((retType = retVal->getType()) != func->getReturnType()) {
            if (retType->isPointerTy()) {
                // FIXME: need to get the value that is pointed to
                //        should probably find a better solution for this
                retVal = fuxLLVM->builder->CreateLoad(retType, retVal); 
            } else
                retVal = fuxLLVM->builder->CreateZExt(retVal, func->getReturnType()); 
                // TODO: analyser should add explicit type cast
        }
        fuxLLVM->builder->CreateRet(retVal);
    }
    else {
        // error reading body
        func->eraseFromParent();
        return nullptr;
    }
    
    verifyFunction(*func);
    return func;
}

Value *RootAST::codegen(LLVMWrapper *fuxLLVM) {
    for (StmtAST::Ptr &sub : program)
        sub->codegen(fuxLLVM);
    return nullptr;
}

#endif