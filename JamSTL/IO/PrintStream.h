#pragma once

#ifndef JAMSTL_PRINTSTREAM_H
#define JAMSTL_PRINTSTREAM_H
#include "../Macros.h"
#include "../Datatypes.h"
#include "../String/StringStream.h"
#include <cstdio>

JAMSTL_NAMESPACE_BEGIN


class PrintStream final {
private:
    FILE* file_;
    void numberChangeColorOrange() {
        const char* intColor = "\033[33m";
        for (usize j = 0; j < 5; ++j) {
            put(intColor[j]);
        }
    }

    void stringChangeColorPurple() {
        const char* strColor = "\033[34m";
        for (usize j = 0; j < 5; ++j) {
            put(strColor[j]);
        }
    }

    void numberResetColor() {
        const char* resetColor = "\033[0m";
        for (usize j = 0; j < 5; ++j) {
            put(resetColor[j]);
        }
    }
public:

    void put(char c) {
        fputc(c, file_);
    }

    PrintStream& operator<<(const char* str) {
        stringChangeColorPurple();
        for (const char* p = str; *p; ++p) {
            put(*p);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& println() {
        return newLine();
    }

    PrintStream& operator<<(const String& str) {
        stringChangeColorPurple();
        if(str) {
            for (char c : str) {
                put(c);
            }
        } else {
            *this << "\033[30mnull\033[0m";
        }
        numberResetColor();
        return *this;
    }

    template<class T>
    PrintStream& operator<<(const T& t) {
        String str = String::valueOf(t);
        return *this << str;
    }

    PrintStream& operator<<(int num) {
        if(num == 0) {
            numberChangeColorOrange();
            put('0');
            numberResetColor();
            return *this;
        }
        if(num < 0) {
            numberChangeColorOrange();
            put('-');
            numberResetColor();
            num = -num;
        }
        numberChangeColorOrange();
        char buf[20];
        usize i = 0;
        while(num) {
            buf[i++] = num % 10 + '0';
            num /= 10;
        }
        while(i) {
            put(buf[--i]);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(const Integer& num) {
        return *this << num.valueOf();
    }

    PrintStream& operator<<(char ch) {
        stringChangeColorPurple();
        put(ch);
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(const Character& ch) {
        return *this << ch.valueOf();
    }

    PrintStream& operator<<(bool b) {
        return *this << "\033[33m" << (b ? "true" : "false") << "\033[0m";
    }

    PrintStream& operator<<(const Boolean& b) {
        return *this << b.valueOf();
    }

    PrintStream& operator<<(byte num) {
        return *this << "\033[33m" << (int)num << "\033[0m";
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
            numberChangeColorOrange();
            put('0');
            numberResetColor();
            return *this;
        }
        if(num < 0) {
            numberChangeColorOrange();
            put('-');
            numberResetColor();
            num = -num;
        }
        char buf[24];
        usize i = 0;
        while(num) {
            buf[i++] = num % 10 + '0';
            num /= 10;
        }
        numberChangeColorOrange();
        while(i) {
            put(buf[--i]);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(const Long& num) {
        return *this << num.valueOf();
    }

    PrintStream& operator<<(unsigned num) {
        if(num == 0) {
            numberChangeColorOrange();
            put('0');
            numberResetColor();
            return *this;
        }
        char buf[20];
        usize i = 0;
        while(num) {
            buf[i++] = num % 10 + '0';
            num /= 10;
        }
        numberChangeColorOrange();
        while(i) {
            put(buf[--i]);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(unsigned short num) {
        return *this << (unsigned)num;
    }

    PrintStream& operator<<(unsigned long num) {
        return *this << (unsigned)num;
    }

    PrintStream& operator<<(unsigned long long num) {
        if(num == 0) {
            numberChangeColorOrange();
            put('0');
            numberResetColor();
            return *this;
        }
        char buf[24];
        usize i = 0;
        while(num) {
            buf[i++] = num % 10 + '0';
            num /= 10;
        }
        numberChangeColorOrange();
        while(i) {
            put(buf[--i]);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(float num) {
        String toStr = toString(num);
        while(toStr[toStr.length() - 1] == '0') {
            toStr.pop();
        }
        if(toStr[toStr.length() - 1] == '.') {
            toStr.pop();
        }
        numberChangeColorOrange();
        for(char c : toStr) {
            put(c);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(const Float& num) {
        String toStr = toString(num.valueOf());
        numberChangeColorOrange();
        while(toStr[toStr.length() - 1] == '0') {
            toStr.pop();
        }
        if(toStr[toStr.length() - 1] == '.') {
            toStr.pop();
        }
        for(char c : toStr) {
            put(c);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(double num) {
        String toStr = toString(num);
        numberChangeColorOrange();
        while(toStr[toStr.length() - 1] == '0') {
            toStr.pop();
        }
        if(toStr[toStr.length() - 1] == '.') {
            toStr.pop();
        }
        for(char c : toStr) {
            put(c);
        }
        numberResetColor();
        return *this;
    }
    
    PrintStream& operator<<(long double num) {
        String toStr = toString(num);
        numberChangeColorOrange();
        while(toStr[toStr.length() - 1] == '0') {
            toStr.pop();
        }
        if(toStr[toStr.length() - 1] == '.') {
            toStr.pop();
        }
        for(char c : toStr) {
            put(c);
        }
        numberResetColor();
        return *this;
    }

    PrintStream& operator<<(const Double& num) {
        String toStr = toString(num.valueOf());
        numberChangeColorOrange();
        while(toStr[toStr.length() - 1] == '0') {
            toStr.pop();
        }
        if(toStr[toStr.length() - 1] == '.') {
            toStr.pop();
        }
        for(char c : toStr) {
            put(c);
        }
        numberResetColor();
        return *this;
    }

    template<usize size>
    PrintStream& operator<<(const char(&arr)[size]) {
        stringChangeColorPurple();
        for (usize i = 0; i < size; ++i) {
            put(arr[i]);
        }
        numberResetColor();
        return *this;
    }

    PrintStream(FILE* file) : file_(file) {}


    PrintStream& newLine() {
        return *this << '\n';
    }
    
    void flush() {
        fflush(file_);
    }




    PrintStream& print(const char* str) {
        return *this << str;
    }

    PrintStream& print(const String& str) {
        return *this << str;
    }
    PrintStream& print(int num) {
        return *this << num;
    }

    PrintStream& print(const Integer& num) {
        return *this << num;
    }

    PrintStream& print(char ch) {
        return *this << ch;
    }

    PrintStream& print(const Character& ch) {
        return *this << ch;
    }

    PrintStream& print(bool b) {
        return *this << b;
    }

    PrintStream& print(const Boolean& b) {
        return *this << b;
    }

    PrintStream& print(byte num) {
        return *this << num;
    }

    PrintStream& print(const Byte& num) {
        return *this << num;
    }

    PrintStream& print(short num) {
        return *this << num;
    }

    PrintStream& print(const Short& num) {
        return *this << num;
    }

    PrintStream& print(long num) {
        return *this << num;
    }

    PrintStream& print(long long num) {
        return *this << num;
    }

    PrintStream& print(const Long& num) {
        return *this << num;
    }

    PrintStream& print(unsigned num) {
        return *this << num;
    }

    PrintStream& print(unsigned short num) {
        return *this << num;
    }

    PrintStream& print(unsigned long num) {
        return *this << num;
    }

    PrintStream& print(unsigned long long num) {
        return *this << num;
    }


    PrintStream& print(float num) {
        return *this << num;
    }

    PrintStream& print(const Float& num) {
        return *this << num;
    }

    PrintStream& print(double num) {
        return *this << num;
    }

    PrintStream& print(long double num) {
        return *this << num;
    }

    PrintStream& print(const Double& num) {
        return *this << num;
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


    PrintStream& println(float num) {
        return *this << num << '\n';
    }

    PrintStream& println(const Float& num) {
        return *this << num << '\n';
    }

    PrintStream& println(double num) {
        return *this << num << '\n';
    }

    PrintStream& println(long double num) {
        return *this << num << '\n';
    }

    PrintStream& println(const Double& num) {
        return *this << num << '\n';
    }

    // nullptr_t
    PrintStream& println(std::nullptr_t) {
        return *this << "\033[35mnull\033[0m" << '\n';
    }

#ifdef DEFAULT_PRINTLN

    template<class T>
    PrintStream& println(const T& t) {
        String str = String::valueOf(t);
        return *this << str << '\n';
    }

    template<class T>
    PrintStream& print(const T& t) {
        String str = String::valueOf(t);
        return *this << str;
    }

#else

    template<class T>
    PrintStream& println(const T& t) {
        *this << t << '\n';
        return *this;
    }

    template<class T>
    PrintStream& print(const T& t) {
        *this << t;
        return *this;
    }

#endif
        

    template<usize size>
    PrintStream& print(const int(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const short(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const long long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const unsigned(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const byte(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const unsigned short(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const unsigned long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const unsigned long long(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const float(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<usize size>
    PrintStream& print(const double(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << arr[i];
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }

    template<class T, usize size>
    PrintStream& print(const T(&arr)[size]) {
        *this << '[';
        for (usize i = 0; i < size; ++i) {
            *this << String::valueOf(arr[i]);
            if (i != size - 1) {
                *this << ", ";
            }
        }
        *this << ']';
        return *this;
    }



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
    PrintStream print(StringView str, const unsigned char& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const char& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const char* value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const short& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const int& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const long long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const unsigned short& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const unsigned int& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const unsigned long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const unsigned long long& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const float& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const double& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const bool& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename... Types>
    PrintStream print(StringView str, const String& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value, values...);
        *this << string;
        return *this;
    }

    template <typename Type, typename... Types>
    PrintStream print(StringView str, const Type& value, Types... values) {
        String strCopy = str;
        String string = strCopy.format(value.valueOf(), values...);
        *this << string;
        return *this;
    }



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