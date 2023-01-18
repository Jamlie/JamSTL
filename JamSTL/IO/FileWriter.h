#pragma once

#ifndef JAMSTL_FILEWRITER_H
#define JAMSTL_FILEWRITER_H
#include "../Macros.h"
#include "../Datatypes.h"

JAMSTL_NAMESPACE_BEGIN


class FileWriter extends Object {
public:
    FileWriter() {
        this->path = "";
        this->file = nullptr;
    }

    FileWriter(String path) {
        this->path = path;
        this->file = nullptr;
    }

    ~FileWriter() {
        if(this->file != nullptr) {
            fclose(this->file);
            this->file = nullptr;
        }
    }

    void open(String path) {
        this->path = path;
        this->file = nullptr;
    }

    void close() {
        if(this->file != nullptr) {
            fclose(this->file);
            this->file = nullptr;
        }
    }

    void write(String str) {
        if(this->file == nullptr) {
            this->file = fopen(this->path.constCharString(), "w");
        }
        fprintf(this->file, "%s", str.constCharString());
    }
    
    void writeLine(String str = "") {
        if(this->file == nullptr) {
            this->file = fopen(this->path.constCharString(), "w");
        }
        fprintf(this->file, "%s\n", str.constCharString());
    }

    void writeAtTheEndOfFile(String str) {
        if(this->file == nullptr) {
            this->file = fopen(this->path.constCharString(), "a");
        }
        fprintf(this->file, "%s", str.constCharString());
    }

private:
    String path;
    FILE* file;
};


JAMSTL_NAMESPACE_END

#endif