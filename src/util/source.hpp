/**
 * @file source.hpp
 * @author fyronix
 * @brief fux source file header
 * @version 0.1
 * @date 2023-03-02
 * 
 * @copyright Copyright (c) 2020-2023, Fuechs and Contributors. All rights reserved.
 * 
 */

#pragma once

#include "../fux.hpp"
#include "../frontend/error/error.hpp"
#include "../frontend/parser/parser.hpp"
#include "../frontend/analyser/analyser.hpp"

class SourceFile {
public:
    using Vec = vector<SourceFile*>;
    using Groups = vector<Vec>;

    SourceFile(ErrorManager* error, const string& filePath, bool mainFile = false);
    ~SourceFile();

    // Get std::thread to run this->parse
    void operator()() { parse(); }

    // Parse file and save RootAST in root
    // Will be called for every file that's referenced
    void parse();

    // Check if file has errors
    size_t errors() const;

    // Return file size in bytes
    // From https://stackoverflow.com/a/32286531
    size_t getFileSize() const;

    string fileName;
    string filePath;
    string fileDir;

    RootAST::Ptr root;
    StmtAST::Ptr analysed;

private:
    ErrorManager* error;
    Parser* parser;
    Analyser* analyser;
    string contents;
    bool mainFile;
};
