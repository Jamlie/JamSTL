#pragma once

#ifndef JAMSTL_BUFFEREDWRITER_H
#define JAMSTL_BUFFEREDWRITER_H
#include "../Macros.h"
#include "../Datatypes.h"
#include "Writer.h"

JAMSTL_NAMESPACE_BEGIN


class BufferedWriter extends Writer {
private:
    Writer out;
    static constexpr int defaultCharBufferSize = 8192;
    char* cb;
    usize nChars, nextChar;
public:
    BufferedWriter(Writer out) {
        BufferedWriter(out, defaultCharBufferSize);
    }

    BufferedWriter() {
        BufferedWriter(Writer());
    }

    BufferedWriter(Writer out, int sz) {
        this->out = out;
        cb = new char[sz];
        nChars = sz;
        nextChar = 0;
    }

    ~BufferedWriter() {
        flushBuffer();
        delete[] cb;
    }

    void flushBuffer() {
        if (nextChar == 0) {
            return;
        }
        out.write(cb, 0, nextChar);
        nextChar = 0;
    }

    void write(int c) {
        if (nextChar >= nChars) {
            flushBuffer();
        }
        cb[nextChar++] = (char)c;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }

    void write(const char* c, usize offset, usize length) {
        if (length >= nChars) {
            flushBuffer();
            out.write(c, offset, length);
            return;
        }
        int b = offset, t = offset + length;
        while (b < t) {
            int d = min(nChars - nextChar, t - b);
            for (int i = 0; i < d; ++i) {
                cb[nextChar + i] = c[b + i];
            }
            nextChar += d;
            b += d;
            if (nextChar >= nChars) {
                flushBuffer();
            }
        }
    }

    void write(String s) {
        write(s, 0, s.length());
    }

    void write(String s, usize offset, usize length) {
        int b = offset, t = offset + length;
        while (b < t) {
            int d = min(nChars - nextChar, t - b);
            for (int i = 0; i < d; ++i) {
                cb[nextChar + i] = s[b + i];
            }
            nextChar += d;
            b += d;
            if (nextChar >= nChars) {
                flushBuffer();
            }
        }
    }

    void newLine() {
        write('\r');
        write('\n');
    }

    void flush() {
        flushBuffer();
        out.flush();
    }

    void close() {
        flush();
        out.close();
    }

};


JAMSTL_NAMESPACE_END


#endif