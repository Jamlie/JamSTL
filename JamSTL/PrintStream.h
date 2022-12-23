#pragma once

#ifndef JAMSTL_PRINTSTREAM_H
#define JAMSTL_PRINTSTREAM_H
#include "Macros.h"
#include "Datatypes.h"
#include <cstdio>

JAMSTL_NAMESPACE_BEGIN

class PrintStream final {
private:
    FILE* file_;
public:

    void put(char c) {
        fputc(c, file_);
    }

    PrintStream& operator<<(const char* str) {
        for (const char* p = str; *p; ++p) {
            put(*p);
        }
        return *this;
    }

    PrintStream& println() {
        return newLine();
    }

    PrintStream& operator<<(const String& str) {
        for (char c : str) {
            put(c);
        }
        return *this;
    }

    template<class T>
    PrintStream& operator<<(const T& t) {
        String str = String::valueOf(t);
        return *this << str;
    }

    PrintStream& operator<<(int num) {
        if(num == 0) {
            put('0');
            return *this;
        }
        if(num < 0) {
            put('-');
            num = -num;
        }
        char buf[20];
        usize i = 0;
        while(num) {
            buf[i++] = num % 10 + '0';
            num /= 10;
        }
        while(i) {
            put(buf[--i]);
        }
        return *this;
    }

    PrintStream& operator<<(const Integer& num) {
        return *this << num.valueOf();
    }

    PrintStream& operator<<(char ch) {
        put(ch);
        return *this;
    }

    PrintStream& operator<<(const Character& ch) {
        return *this << ch.valueOf();
    }

    PrintStream& operator<<(bool b) {
        return *this << (b ? "true" : "false");
    }

    PrintStream& operator<<(const Boolean& b) {
        return *this << b.valueOf();
    }

    PrintStream& operator<<(byte num) {
        return *this << (int)num;
    }

    PrintStream& operator<<(const Byte& num) {
        return *this << num.valueOf();
    }

    PrintStream& operator<<(short num) {
        return *this << (int)num;
    }

    PrintStream& operator<<(const Short& num) {
        return *this << num.valueOf();
    }

    PrintStream& operator<<(long num) {
        return *this << (int)num;
    }

    PrintStream& operator<<(long long num) {
        if(num == 0) {
            put('0');
            return *this;
        }
        if(num < 0) {
            put('-');
            num = -num;
        }
        char buf[24];
        usize i = 0;
        while(num) {
            buf[i++] = num % 10 + '0';
            num /= 10;
        }
        while(i) {
            put(buf[--i]);
        }
        return *this;
    }

    PrintStream& operator<<(const Long& num) {
        return *this << num.valueOf();
    }

    PrintStream& operator<<(unsigned num) {
        if(num == 0) {
            put('0');
            return *this;
        }
        char buf[20];
        usize i = 0;
        while(num) {
            buf[i++] = num % 10 + '0';
            num /= 10;
        }
        while(i) {
            put(buf[--i]);
        }
        return *this;
    }

    PrintStream& operator<<(unsigned short num) {
        return *this << (unsigned)num;
    }

    PrintStream& operator<<(unsigned long num) {
        return *this << (unsigned)num;
    }

    PrintStream& operator<<(unsigned long long num) {
        return *this << (unsigned)num;
    }

    void operator<<(float num) {
        printf("%.2f", num);
    }

    void operator<<(const Float& num) {
        printf("%.2f", num.valueOf());
    }

    void operator<<(double num) {
        printf("%.2lf", num);
    }
    
    void operator<<(const Double& num) {
        printf("%.2lf", num.valueOf());
    }

    template<usize size>
    PrintStream& operator<<(const char(&arr)[size]) {
        for (usize i = 0; i < size; ++i) {
            put(arr[i]);
        }
        return *this;
    }

    PrintStream(FILE* file) : file_(file) {}


    PrintStream& newLine() {
        return *this << '\n';
    }
    
    void flush() {
        fflush(file_);
    }


    PrintStream& println(const char* str) {
        return *this << str << '\n';
    }

    PrintStream& println(const String& str) {
        return *this << str << '\n';
    }
    PrintStream& println(int num) {
        return *this << num << '\n';
    }

    PrintStream& println(const Integer& num) {
        return *this << num << '\n';
    }

    PrintStream& println(char ch) {
        return *this << ch << '\n';
    }

    PrintStream& println(const Character& ch) {
        return *this << ch << '\n';
    }

    PrintStream& println(bool b) {
        return *this << b << '\n';
    }

    PrintStream& println(const Boolean& b) {
        return *this << b << '\n';
    }

    PrintStream& println(byte num) {
        return *this << num << '\n';
    }

    PrintStream& println(const Byte& num) {
        return *this << num << '\n';
    }

    PrintStream& println(short num) {
        return *this << num << '\n';
    }

    PrintStream& println(const Short& num) {
        return *this << num << '\n';
    }

    PrintStream& println(long num) {
        return *this << num << '\n';
    }

    PrintStream& println(long long num) {
        return *this << num << '\n';
    }

    PrintStream& println(const Long& num) {
        return *this << num << '\n';
    }

    PrintStream& println(unsigned num) {
        return *this << num << '\n';
    }

    PrintStream& println(unsigned short num) {
        return *this << num << '\n';
    }

    PrintStream& println(unsigned long num) {
        return *this << num << '\n';
    }

    PrintStream& println(unsigned long long num) {
        return *this << num << '\n';
    }


    void println(float num) {
        printf("%.2f", num);
    }

    void println(const Float& num) {
        printf("%.2f\n", num.valueOf());
    }

    void println(double num) {
        printf("%.2lf", num);
    }

    void println(const Double& num) {
        printf("%.2lf\n", num.valueOf());
    }

#ifdef DEFAULT_PRINTLN

    template<class T>
    PrintStream& println(const T& t) {
        String str = String::valueOf(t);
        return *this << str << '\n';
    }

#else

    template<class T>
    PrintStream& println(const T& t) {
        *this << t << '\n';
        return *this;
    }

#endif
        

    template<usize size>
    PrintStream& println(const int(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const short(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const long long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const unsigned(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const byte(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const unsigned short(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const unsigned long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const unsigned long long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const float(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<usize size>
    PrintStream& println(const double(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    template<class T, usize size>
    PrintStream& println(const T(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << String::valueOf(arr[i]);
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']' << '\n';
        return *this;
    }

    // formatting 
    template <typename... Types>
    PrintStream println(StringView str, const unsigned char& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const char& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const char* value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const short& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const int& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const long long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const unsigned short& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const unsigned int& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const unsigned long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const unsigned long long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const float& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const double& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const bool& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename... Types>
    PrintStream println(StringView str, const String& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string << '\n';
        return *this;
    }

    template <typename Type, typename... Types>
    PrintStream println(StringView str, const Type& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value.valueOf(), values...);
        *this << string << '\n';
        return *this;
    }

};


JAMSTL_NAMESPACE_END


#endif