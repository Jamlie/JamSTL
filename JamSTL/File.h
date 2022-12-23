#pragma once

#ifndef JAMSTL_FILE_H
#define JAMSTL_FILE_H
#include "Macros.h"
#include "Datatypes.h"
#include "PrintStream.h"

JAMSTL_NAMESPACE_BEGIN


class File extends Object {
public:
    File() {
        this->path = "";
        this->mode = "";
        this->file = nullptr;
    }
    File(String path) {
        this->path = path;
        this->mode = "";
        this->file = nullptr;
    }
    File(String path, String mode) {
        this->path = path;
        this->mode = mode;
        this->file = nullptr;
    }
    ~File() {
        if(this->file != nullptr) {
            fclose(this->file);
        }
    }

    void open(String path) {
        this->path = path;
        this->mode = "";
        this->file = nullptr;
    }
    void open(String path, String mode) {
        this->path = path;
        this->mode = mode;
        this->file = nullptr;
    }
    void close() {
        if(this->file != nullptr) {
            fclose(this->file);
        }
    }

    void write(String str) {
        if(this->file == nullptr) {
            this->file = fopen(this->path.constCharString(), this->mode.constCharString());
        }
        fprintf(this->file, "%s", str.constCharString());
    }
    void writeLine(String str) {
        if(this->file == nullptr) {
            this->file = fopen(this->path.constCharString(), this->mode.constCharString());
        }
        fprintf(this->file, "%s\n", str.constCharString());
    }

    // contains method that checks if a file contains a certain string
    // bool contains(String str) {
    //     if(this->file == nullptr) {
    //         this->file = fopen(this->path.constCharString(), this->mode.constCharString());
    //     }
    //     char* line = nullptr;
    //     size_t len = 0;
    //     int read;
    //     while((read = getline(&line, &len, this->file)) != -1) {
    //         if(str.contains(line)) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    String getPath() const {
        return this->path;
    }
    void setPath(String path) {
        this->path = path;
    }

    String getMode() const {
        return this->mode;
    }
    void setMode(String mode) {
        this->mode = mode;
    }

    String toString() const {
        return this->path;
    }
    String valueOf() const {
        return this->path;
    }

    bool createNewFile(String path) {
        FILE* file = fopen(path.constCharString(), "w");
        if(file == nullptr) {
            return false;
        }
        fclose(file);
        return true;
    }

    bool deleteFile(String path) {
        return remove(path.constCharString()) == 0;
    }

    bool exists(String path) {
        FILE* file = fopen(path.constCharString(), "r");
        if(file == nullptr) {
            return false;
        }
        fclose(file);
        return true;
    }

    friend PrintStream& println(PrintStream& out, const File& file) {
        return out.println(file.path);
    }

private:
    String path;
    String mode;
    FILE* file;
};


JAMSTL_NAMESPACE_END


#endif