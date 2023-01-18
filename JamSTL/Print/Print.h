#pragma once

#ifndef JAMSTL_PRINTSTREAM2_H
#define JAMSTL_PRINTSTREAM2_H
#include "../Macros.h"
#include "../Datatypes.h"
#include "BufferedWriter.h"

JAMSTL_NAMESPACE_BEGIN


class Print {
private:
    BufferedWriter textOut;
    void write(String x) {
        textOut.write(x);
        textOut.flushBuffer();
    }
public:
    Print(Writer out) : textOut(out) {}
    Print() {
        textOut = BufferedWriter(Writer());
    }
    
    void println(String x) {
        print(x);
        // newLine();
    }

    void print(String x) {
        write(String::valueOf(x));
    }

    
};


JAMSTL_NAMESPACE_END



#endif