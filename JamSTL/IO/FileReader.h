#pragma once

#ifndef JAMSTL_FILEREADER_H
#define JAMSTL_FILEREADER_H
#include "../Macros.h"
#include "../Datatypes.h"

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

    void newCopy(String fileName) {
        if(!fileName.startsWith("./")) {
            fileName = "./" + fileName;
        }
        FILE* newFile = fopen(fileName.constCharString(), "w");
        String str = this->read();
        fprintf(newFile, "%s", str.constCharString());
        fclose(newFile);
    }

    void copyFileInfoTo(String fileName) {
        if(!fileName.startsWith("./")) {
            fileName = "./" + fileName;
        }
        FILE* newFile = fopen(fileName.constCharString(), "w");
        String str = this->read();
        std::cout << str << std::endl;
        fprintf(newFile, "%s", str.constCharString());
        fclose(newFile);
    }

    String readLine(usize numberOfLine) {
        if(!this->file) {
            this->file = fopen(this->path.constCharString(), "r");
        }
        String str;
        char c;
        usize line = 0;
        while((c = fgetc(this->file)) != EOF) {
            if(c == '\n') {
                line++;
            }
            if(line == numberOfLine) {
                break;
            }
            str += c;
        }
        return str;
    }

    usize numberOfLines() {
        if(!this->file) {
            this->file = fopen(this->path.constCharString(), "r");
        }
        usize line = 0;
        char c;
        FILE* newFile = this->file;
        while((c = fgetc(newFile)) != EOF) {
            if(c == '\n') {
                line++;
            }
        }
        return line;
    }

    bool endOfFile() {
        if(!this->file) {
            this->file = fopen(this->path.constCharString(), "r");
        }
        return feof(this->file);
    }

private:
    String path;
    FILE* file;
};


JAMSTL_NAMESPACE_END

#endif