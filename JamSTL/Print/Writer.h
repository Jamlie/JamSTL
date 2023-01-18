#pragma once

#ifndef JAMSTL_WRITER_H
#define JAMSTL_WRITER_H
#include "../Macros.h"
#include "../Datatypes.h"

JAMSTL_NAMESPACE_BEGIN


class Writer {
private:
    static constexpr usize BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    usize bufferIndex = 0;
    usize bufferLength = 0;

    usize stringLength(const char* c) {
        usize i = 0;
        while (c[i] != '\0') {
            ++i;
        }
        return i;
    }

public:
    Writer() = default;
    Writer(const Writer& writer) {
        bufferIndex = writer.bufferIndex;
        bufferLength = writer.bufferLength;
        for (usize i = 0; i < bufferLength; ++i) {
            buffer[i] = writer.buffer[i];
        }
    }
    // void write(char c) {
    //     if (bufferIndex >= bufferLength) {
    //         flush();
    //     }
    //     buffer[bufferIndex++] = c;
    // }

    // void write(String x) {
    //     for (usize i = 0; i < x.length(); ++i) {
    //         write(x[i]);
    //     }
    // }

    void flush() {
        bufferIndex = 0;
        bufferLength = 0;
    }

    void write(int c) {
        if (bufferIndex >= bufferLength) {
            flush();
        }
        buffer[0] = (char)c;
        write(buffer, 0, 1);
    }

    void write(const char* c, usize offset, usize length) {
        if (length >= BUFFER_SIZE) {
            flush();
            write(c, offset, length);
        } else {
            if (bufferIndex + length >= BUFFER_SIZE) {
                flush();
            }
            for (usize i = 0; i < length; ++i) {
                buffer[bufferIndex++] = c[offset + i];
            }
        }
    }

    void write(const char* c) {
        write(c, 0, stringLength(c));
    }

    void write(String x, usize offset, usize length) {
        char* cbuf;
        if(length <=BUFFER_SIZE) {
            if (bufferIndex + length >= BUFFER_SIZE) {
                flush();
            }
            cbuf = buffer;
        } else {
            flush();
            cbuf = new char[length];
        }
        for (usize i = 0; i < length; ++i) {
            cbuf[i] = x[offset + i];
        }
        write(cbuf, 0, length);
    }

    void write(String str) {
        write(str, 0, str.length());
    }

    void close() {
        flush();
    }


};


JAMSTL_NAMESPACE_END


#endif