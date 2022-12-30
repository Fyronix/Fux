/**
 * @file source.cpp
 * @author fuechs
 * @brief fux source file
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2020-2023, Fuechs. All rights reserved.
 * 
 */

#include "source.hpp"

#include <filesystem>

SourceFile::SourceFile(const string& filePath, const bool mainFile) {
    this->filePath = filePath;
    this->fileName = getFileName(filePath);
    this->fileDir = getDirectory(filePath);
    this->contents = readFile(filePath);
    this->mainFile = mainFile;
}

SourceFile::~SourceFile() {
    filePath.clear();
    fileName.clear();
    fileDir.clear();
    contents.clear();
    error->panic();
    delete parser;
    delete analyser;
}

void SourceFile::parse() {
    error = new ErrorManager(filePath, vector<string>());
    parser = new Parser(error, filePath, contents, mainFile);
    root = parser->parse();
    analyser = new Analyser(error, root);
    analyser->analyse();
}

bool SourceFile::hasErrors() {
    return error->hasErrors();
}

size_t SourceFile::getFileSize() {
    std::__fs::filesystem::path p {filePath};
    return (size_t) std::__fs::filesystem::file_size(p);
}