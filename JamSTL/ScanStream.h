#pragma once

#ifndef JAMSTL_SCANSTREAM_H
#define JAMSTL_SCANSTREAM_H
#include "Macros.h"
#include "String.h"
#include <cstdio>

JAMSTL_NAMESPACE_BEGIN

class ScanStream final {
private:
    FILE* file_;
public:
    ScanStream(FILE* file) : file_(file) {}

    int get() {
        return fgetc(file_);
    }

    int peek() {
        int c = get();
        ungetc(c, file_);
        return c;
    }

    ScanStream& operator>>(char& c) {
        c = get();
        return *this;
    }

    char nextChar() {
        return get();
    }


    ScanStream& operator>>(int& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    int nextInt() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }

    ScanStream& operator>>(short& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    short nextShort() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }

    ScanStream& operator>>(long& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        long res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    ScanStream& operator>>(long long& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        long long res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    long long nextLong() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        long long res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }

    ScanStream& operator>>(unsigned& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    unsigned nextUnsigned() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return res;
    }

    ScanStream& operator>>(unsigned short& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    unsigned short nextUShort() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return res;
    }

    ScanStream& operator>>(unsigned long& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned long res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    ScanStream& operator>>(unsigned long long& str) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned long long res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    unsigned long long nextULong() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned long long res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return res;
    }

    ScanStream& operator>>(float& num) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        float res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            float div = 1;
            while (c >= '0' && c <= '9') {
                res = res * 10 + c - '0';
                div *= 10;
                c = get();
            }
            res /= div;
        }
        ungetc(c, file_);
        num = neg ? -res : res;
        return *this;
    }

    float nextFloat() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        float res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            float div = 1;
            while (c >= '0' && c <= '9') {
                res = res * 10 + c - '0';
                div *= 10;
                c = get();
            }
            res /= div;
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }
    
    ScanStream& operator>>(double& num) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        double res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            double div = 1;
            while (c >= '0' && c <= '9') {
                res = res * 10 + c - '0';
                div *= 10;
                c = get();
            }
            res /= div;
        }
        ungetc(c, file_);
        num = neg ? -res : res;
        return *this;
    }

    double nextDouble() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        double res = 0;
        while (c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            double div = 1;
            while (c >= '0' && c <= '9') {
                res = res * 10 + c - '0';
                div *= 10;
                c = get();
            }
            res /= div;
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }


    ScanStream& operator>>(String& str) {
        str.empty();
        int c;
        while ((c = get()) != EOF && c != '\n') {
            str += c;
        }
        return *this;
    }

    String nextLine() {
        String str;
        int c;
        while ((c = get()) != EOF && c != '\n') {
            str += c;
        }
        return str;
    }

    // scan a bool
    ScanStream& operator>>(bool& boolean) {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        if (c == 't' || c == 'T') {
            boolean = true;
            c = get();
            if (c != 'r' && c != 'R') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'u' && c != 'U') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'e' && c != 'E') {
                ungetc(c, file_);
            }
        } else if (c == 'f' || c == 'F') {
            boolean = false;
            c = get();
            if (c != 'a' && c != 'A') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'l' && c != 'L') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 's' && c != 'S') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'e' && c != 'E') {
                ungetc(c, file_);
            }
        } else {
            boolean = false;
        }
        return *this;
    }

    bool nextBool() {
        int c = get();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        if (c == 't' || c == 'T') {
            c = get();
            if (c != 'r' && c != 'R') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'u' && c != 'U') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'e' && c != 'E') {
                ungetc(c, file_);
            }
            return true;
        } else if (c == 'f' || c == 'F') {
            c = get();
            if (c != 'a' && c != 'A') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'l' && c != 'L') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 's' && c != 'S') {
                ungetc(c, file_);
            }
            c = get();
            if (c != 'e' && c != 'E') {
                ungetc(c, file_);
            }
            return false;
        } else {
            return false;
        }
    }

  
};


JAMSTL_NAMESPACE_END


#endif