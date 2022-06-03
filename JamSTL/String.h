#pragma once

#include "Datatypes.h"
#include "Macros.h"
#include "Math.h"

#ifndef JAMSTL_STRING_H
#define JAMSTL_STRING_H

JAMSTL_NAMESPACE_BEGIN

    size_t length(const char* str) {
        size_t len = 0;
        while(str[len] != '\0') {
            len++;
        }
        return len;
    }

    char* copy(char* dest, const char* src) {
        size_t len = length(src);
        for(size_t i = 0; i < len; i++) {
            dest[i] = src[i];
        }
        dest[len] = '\0';
        return dest;
    }

    int compare(const char* str1, const char* str2) {
        size_t len1 = length(str1);
        size_t len2 = length(str2);
        if(len1 > len2) {
            return 1;
        } else if(len1 < len2) {
            return -1;
        } else {
            for(size_t i = 0; i < len1; i++) {
                if(str1[i] > str2[i]) {
                    return 1;
                } else if(str1[i] < str2[i]) {
                    return -1;
                }
            }
            return 0;
        }
    }

    char* concat(char* dest, const char* src) {
        size_t len = length(dest);
        size_t len2 = length(src);
        for(size_t i = 0; i < len2; i++) {
            dest[len + i] = src[i];
        }
        dest[len + len2] = '\0';
        return dest;
    }

    char* concat(char* dest, const char* src, size_t len) {
        for(size_t i = 0; i < len; i++) {
            dest[length(dest) + i] = src[i];
        }
        dest[length(dest) + len] = '\0';
        return dest;
    }

    char toupper(const char& charatcer) {
        if(charatcer >= 'a' && charatcer <= 'z') {
            return charatcer - 32;
        }
        return charatcer;
    }

    char tolower(const char& charatcer) {
        if(charatcer >= 'A' && charatcer <= 'Z') {
            return charatcer + 32;
        }
        return charatcer;
    }

    char* toUpper(char* str) {
        size_t len = length(str);
        for(size_t i = 0; i < len; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
        return str;
    }

    char* toUpper(String str) {
        return toUpper(str.c_string());
    }

    char* toUpper(const char* str) {
        size_t len = length(str);
        char* newStr = new char[len + 1];
        for(size_t i = 0; i < len; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                newStr[i] = str[i] - 32;
            } else {
                newStr[i] = str[i];
            }
        }
        newStr[len] = '\0';
        return newStr;
    }

    char* toLower(char* str) {
        size_t len = length(str);
        for(size_t i = 0; i < len; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }

    char* toLower(String str) {
        return toLower(str.c_string());
    }

    char* toLower(const char* str) {
        size_t len = length(str);
        char* newStr = new char[len + 1];
        for(size_t i = 0; i < len; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                newStr[i] = str[i] + 32;
            } else {
                newStr[i] = str[i];
            }
        }
        newStr[len] = '\0';
        return newStr;
    }

    bool isNull(const char* str) {
        return str[0] == null;
    }

    bool isNull(String str) {
        return isNull(str.c_string());
    }

    bool isAscii(const char* str) {
        size_t len = length(str);
        for(size_t i = 0; i < len; i++) {
            if(str[i] < 0) {
                return false;
            }
        }
        return true;
    }


    

    String toString(int intNumber) {
        String str = "";
        int number = intNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = intNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        String tempString = "";
        if(number == 0) {
            tempString = "0";
        } else {
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -intNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
        }
        str += tempString;
        str.insert(0, '-');
        str.pop();
        return str;
    }

    String toString(unsigned int unsignedIntNumber) {
        String str = "";
        unsigned int number = unsignedIntNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = unsignedIntNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        str = "0";
        return str;
    }

    String toString(short shortNumber) {
        String str = "";
        short int number = shortNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = shortNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        String tempString = "";
        if(number == 0) {
            tempString = "0";
        } else {
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -shortNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
        }
        str += tempString;
        str.insert(0, '-');
        str.pop();
        return str;
    }

    String toString(unsigned short unsignedShortNumber) {
        String str = "";
        unsigned short int number = unsignedShortNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = unsignedShortNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        str = "0";
        return str;
    }

    String toString(long longNumber) {
        String str = "";
        long int number = longNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = longNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        String tempString = "";
        if(number == 0) {
            tempString = "0";
        } else {
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -longNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
        }
        str += tempString;
        str.insert(0, '-');
        str.pop();
        return str;
    }

    String toString(unsigned long unsignedLongNumber) {
        String str = "";
        unsigned long int number = unsignedLongNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = unsignedLongNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        str = "0";
        return str;
    }
    
    String toString(long long LLNumber) {
        String str = "";
        long long int number = LLNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = LLNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        String tempString = "";
        if(number == 0) {
            tempString = "0";
        } else {
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -LLNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
        }
        str += tempString;
        str.insert(0, '-');
        str.pop();
        return str;
    }

    String toString(unsigned long long ULLNumber) {
        String str = "";
        unsigned long long int number = ULLNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = ULLNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        str = "0";
        return str;
    }

    String toString(Integer integer) {
        String str = "";
        int number = integer;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = integer;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        String tempString = "";
        if(number == 0) {
            tempString = "0";
        } else {
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -integer;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
        }
        str += tempString;
        str.insert(0, '-');
        str.pop();
        return str;
    }

    String toString(Short shortNumber) {
        String str = "";
        short int number = shortNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = shortNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        String tempString = "";
        if(number == 0) {
            tempString = "0";
        } else {
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -shortNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
        }
        str += tempString;
        str.insert(0, '-');
        str.pop();
        return str;
    }

    String toString(Long longNumber) {
        String str = "";
        long long number = longNumber;
        if(number > 0) {
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = longNumber;
            for(int i = 0; i < digits; i++) {
                str += (number % 10) + '0';
                number /= 10;
            }
            str.reverse();
            return str;
        }
        String tempString = "";
        if(number == 0) {
            tempString = "0";
        } else {
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -longNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
        }
        str += tempString;
        str.insert(0, '-');
        str.pop();
        return str;
    }

    String toString(float floatNumber) {
        if(floatNumber == 0) {
            return "0";
        }
        if(floatNumber == (long long)floatNumber) {
            return toString((long long)floatNumber) + ".0";
        }
        long long LLNumber = floatNumber;
        float tempFloat = floatNumber - LLNumber;
        String str = toString(LLNumber);
        str += ".";
        int digits = 0;

        tempFloat = floatNumber - LLNumber;
        if(tempFloat < 0) {
            tempFloat *= -1;
        }
        tempFloat *= 100000;

        long long number = Math.Round(tempFloat);
        for(int i = 0; i < 5; i++) {
            if(number % 10 == 0) number /= 10;
            else digits++;
        }
        String tempString = "";
        for(int i = 0; i < digits; i++) {
            tempString += (number % 10) + '0';
            number /= 10;
        }
        tempString.reverse();
        str += tempString;
        return str;
    }

    String toString(double doubleNumber) {
        if(doubleNumber == 0) {
            return "0";
        }
        if(doubleNumber == (long long)doubleNumber) {
            return toString((long long)doubleNumber) + ".0";
        }
        long long LLNumber = doubleNumber;
        double tempDouble = doubleNumber - LLNumber;
        String str = toString(LLNumber);
        str += ".";
        int digits = 0;

        tempDouble = doubleNumber - LLNumber;
        if(tempDouble < 0) {
            tempDouble *= -1;
        }
        tempDouble *= 100000;

        long long number = Math.Round(tempDouble);
        for(int i = 0; i < 5; i++) {
            if(number % 10 == 0) number /= 10;
            else digits++;
        }
        String tempString = "";
        for(int i = 0; i < digits; i++) {
            tempString += (number % 10) + '0';
            number /= 10;
        }
        tempString.reverse();
        str += tempString;
        return str;
    }

    String toString(long double longDoubleNumber) {
        if(longDoubleNumber == 0) {
            return "0";
        }
        if(longDoubleNumber == (long long)longDoubleNumber) {
            return toString((long long)longDoubleNumber) + ".0";
        }
        long long LLNumber = longDoubleNumber;
        long double tempLongDouble = longDoubleNumber - LLNumber;
        String str = toString(LLNumber);
        str += ".";
        int digits = 0;

        tempLongDouble = longDoubleNumber - LLNumber;
        if(tempLongDouble < 0) {
            tempLongDouble *= -1;
        }
        tempLongDouble *= 100000;

        long long number = Math.Round(tempLongDouble);
        for(int i = 0; i < 5; i++) {
            if(number % 10 == 0) {
                digits++;
            }
            number /= 10;
        }
        String tempString = "";
        for(int i = 0; i < digits; i++) {
            tempString += (number % 10) + '0';
            number /= 10;
        }
        tempString.reverse();

        str += tempString;
        return str;
    }

    String toString(Float floatNumber) {
        if(floatNumber == 0) {
            return "0";
        }
        if(floatNumber == (long long)floatNumber) {
            return toString((long long)floatNumber) + ".0";
        }
        long long LLNumber = floatNumber;
        float tempFloat = floatNumber - LLNumber;
        String str = toString(LLNumber);
        str += ".";
        int digits = 0;

        tempFloat = floatNumber - LLNumber;
        if(tempFloat < 0) {
            tempFloat *= -1;
        }
        tempFloat *= 100000;

        long long number = Math.Round(tempFloat);
        for(int i = 0; i < 5; i++) {
            if(number % 10 == 0) number /= 10;
            else digits++;
        }

        String tempString = "";
        for(int i = 0; i < digits; i++) {
            tempString += (number % 10) + '0';
            number /= 10;
        }
        tempString.reverse();
        str += tempString;
        return str;
    }

    String toString(Double doubleNumber) {
        if(doubleNumber == 0) {
            return "0";
        }
        if(doubleNumber == (long long)doubleNumber) {
            return toString((long long)doubleNumber) + ".0";
        }
        long long LLNumber = doubleNumber;
        double tempDouble = doubleNumber - LLNumber;
        String str = toString(LLNumber);
        str += ".";
        int digits = 0;

        tempDouble = doubleNumber - LLNumber;
        if(tempDouble < 0) {
            tempDouble *= -1;
        }
        tempDouble *= 100000;

        long long number = Math.Round(tempDouble);
        for(int i = 0; i < 5; i++) {
            if(number % 10 == 0) number /= 10;
            else digits++;
        }
        String tempString = "";
        for(int i = 0; i < digits; i++) {
            tempString += (number % 10) + '0';
            number /= 10;
        }
        tempString.reverse();
        str += tempString;
        return str;
    }



JAMSTL_NAMESPACE_END

#endif