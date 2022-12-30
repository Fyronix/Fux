/**
 * @file compiler.hpp
 * @author fuechs
 * @brief fux compiler header
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2020-2023, Fuechs. All rights reserved.
 * 
 */

#pragma once

#include "../../fux.hpp"
#include "../llvmheader.hpp"

class Compiler {
public:
    Compiler(const string &fileName, Module *module);
    ~Compiler();

    void compile();

private:
    string fileName;
    Module *module;

    void debugPrint(const string message);
};