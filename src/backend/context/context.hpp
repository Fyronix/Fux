/**
 * @file context.hpp
 * @author fuechs
 * @brief fux context header
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2020-2022, Fuechs. All rights reserved.
 * 
 */

#pragma once

#include "../llvmheader.hpp"
#include "../generator/generator.hpp"
#include "../compiler/compiler.hpp"

/**
 * Manages...
 * ...Generator
 * ...Optimizer
 * ...Compiler
 * ...LLVMContext
 * ...MLIRContext
 * 
 */
class FuxContext {
public:
    FuxContext(RootAST *root);
    ~FuxContext();

    LLVMContext *llvmContext;
    Module *module;
    string target;

    void run();

private:
    RootAST *root;
    Generator *generator;
    Compiler *compiler;

    /* generate IR */
    void generate();
    /* optimize IR */
    void optimize();
    /* compile to assembly */
    void compile();

    void debugPrint(const string message);
};