#pragma once

#ifndef JAMSTL_FILEREADER_H
#define JAMSTL_FILEREADER_H
#include "Macros.h"
#include "Datatypes.h"

JAMSTL_NAMESPACE_BEGIN


class FileReader extends Object {
public:
    FileReader() {
        this->path = "";
        this->file = nullptr;
    }
    FileReader(String path) {
        this->path = path;
        this->file = nullptr;
    }
    ~FileReader() {
        if(this->file != nullptr) {
            fclose(this->file);
        }
    }

    void open(String path) {
        this->path = path;
        this->file = nullptr;
    }
    void close() {
        if(this->file != nullptr) {
            fclose(this->file);
        }
    }

    String read() {
        if(this->file == nullptr) {
            this->file = fopen(this->path.constCharString(), "r");
        }
        String str;
        char c;
        while((c = fgetc(this->file)) != EOF) {
            str += c;
        }
        return str;
    }

    String readLine() {
        if(!this->file) {
            this->file = fopen(this->path.constCharString(), "r");
        }
        String str;
        char c;
        while((c = fgetc(this->file)) != EOF) {
            if(c == '\n') {
                break;
            }
            str += c;
        }
        return str;
    }

    FileReader operator>>(String str) {
        str = this->read();
        return *this;
    }

private:
    String path;
    FILE* file;
};

JAMSTL_NAMESPACE_END

#endif