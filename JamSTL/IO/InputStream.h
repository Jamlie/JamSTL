#pragma once

#ifndef JAMSTL_SCANSTREAM_H
#define JAMSTL_SCANSTREAM_H
#include "../Macros.h"
#include "../String.h"
#include <cstdio>

JAMSTL_NAMESPACE_BEGIN

class InputStream final {
private:
    FILE* file_;
    static int count;
public:
    InputStream(FILE* file) : file_(file) {}

    int get() {
        return fgetc(file_);
    }

    int peek() {
        int c = get();
        ungetc(c, file_);
        return c;
    }

    void flush() {
        count = 0;
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    InputStream& operator>>(char& c) {
        if(count != 0)
            this->flush();
        count++;
        c = get();
        return *this;
    }

    char nextChar() {
        if(count != 0)
            this->flush();
        count++;
        return get();
    }


    InputStream& operator>>(int& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    int nextInt() {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }

    InputStream& operator>>(short& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    short nextShort() {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }

    InputStream& operator>>(long& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        long res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    InputStream& operator>>(long long& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        long long res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = neg ? -res : res;
        return *this;
    }

    long long nextLong() {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        long long res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }

    InputStream& operator>>(unsigned& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    unsigned nextUnsigned() {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return res;
    }

    InputStream& operator>>(unsigned short& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    unsigned short nextUShort() {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned int res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return res;
    }

    InputStream& operator>>(unsigned long& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned long res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    InputStream& operator>>(unsigned long long& str) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned long long res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        str = res;
        return *this;
    }

    unsigned long long nextULong() {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        unsigned long long res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        ungetc(c, file_);
        return res;
    }

    InputStream& operator>>(float& num) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        float res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            float div = 1;
            while(c >= '0' && c <= '9') {
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
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        float res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            float div = 1;
            while(c >= '0' && c <= '9') {
                res = res * 10 + c - '0';
                div *= 10;
                c = get();
            }
            res /= div;
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }
    
    InputStream& operator>>(double& num) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        double res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            double div = 1;
            while(c >= '0' && c <= '9') {
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
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
            c = get();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = get();
        }
        double res = 0;
        while(c >= '0' && c <= '9') {
            res = res * 10 + c - '0';
            c = get();
        }
        if (c == '.') {
            c = get();
            double div = 1;
            while(c >= '0' && c <= '9') {
                res = res * 10 + c - '0';
                div *= 10;
                c = get();
            }
            res /= div;
        }
        ungetc(c, file_);
        return neg ? -res : res;
    }


    InputStream& operator>>(String& str) {
        str.empty();
        if(count != 0)
            this->flush();
        // count++;
        int c;
        while((c = get()) != EOF && c != '\n') {
            str += c;
        }
        return *this;
    }

    String nextLine() {
        if(count != 0)
            this->flush();
        String str;
        int c;
        while((c = get()) != EOF && c != '\n') {
            str += c;
        }
        return str;
    }

    // scan a bool
    InputStream& operator>>(bool& boolean) {
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
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
        if(count != 0)
            this->flush();
        count++;
        int c = get();
        while(c == ' ' || c == '\t' || c == '\n') {
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

int InputStream::count = 0;


JAMSTL_NAMESPACE_END


#endif