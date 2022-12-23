#pragma once

#ifndef JAMSTL_STRING_H
#define JAMSTL_STRING_H 1
#include "../Datatypes.h"
#include "../Macros.h"
#include "../Math.h"
#include "../bits/type_traits.h"

JAMSTL_NAMESPACE_BEGIN

    usize strlen(const char* str) {
        usize lenOfArray = 0;
        while(str[lenOfArray] != '\0') {
            lenOfArray++;
        }
        return lenOfArray;
    }

    template<typename T, usize size>
    usize len(const T(&array)[size]) {
        return size;
    }

    char* copy(char* dest, const char* src) {
        usize lenOfArray = strlen(src);
        for(usize i = 0; i < lenOfArray; i++) {
            dest[i] = src[i];
        }
        dest[lenOfArray] = '\0';
        return dest;
    }

    int compare(const char* str1, const char* str2) {
        usize len1 = strlen(str1);
        usize len2 = strlen(str2);
        if(len1 > len2) {
            return 1;
        } else if(len1 < len2) {
            return -1;
        } else {
            for(usize i = 0; i < len1; i++) {
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
        usize lenOfArray = strlen(dest);
        usize len2 = strlen(src);
        for(usize i = 0; i < len2; i++) {
            dest[lenOfArray + i] = src[i];
        }
        dest[lenOfArray + len2] = '\0';
        return dest;
    }

    char* concat(char* dest, const char* src, usize lenOfArray) {
        for(usize i = 0; i < lenOfArray; i++) {
            dest[strlen(dest) + i] = src[i];
        }
        dest[strlen(dest) + lenOfArray] = '\0';
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
        usize lenOfArray = strlen(str);
        for(usize i = 0; i < lenOfArray; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
        return str;
    }

    char* toUpper(String str) {
        return toUpper(str.charString());
    }

    char* toUpper(const char* str) {
        usize lenOfArray = strlen(str);
        char* newStr = new char[lenOfArray + 1];
        for(usize i = 0; i < lenOfArray; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                newStr[i] = str[i] - 32;
            } else {
                newStr[i] = str[i];
            }
        }
        newStr[lenOfArray] = '\0';
        return newStr;
    }

    char* toLower(char* str) {
        usize lenOfArray = strlen(str);
        for(usize i = 0; i < lenOfArray; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }

    char* toLower(String str) {
        return toLower(str.charString());
    }

    char* toLower(const char* str) {
        usize lenOfArray = strlen(str);
        char* newStr = new char[lenOfArray + 1];
        for(usize i = 0; i < lenOfArray; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                newStr[i] = str[i] + 32;
            } else {
                newStr[i] = str[i];
            }
        }
        newStr[lenOfArray] = '\0';
        return newStr;
    }

    bool isNull(const char* str) {
        return str == null;
    }

    bool isNull(String str) {
        return isNull(str.charString());
    }

    bool isAscii(const char* str) {
        usize lenOfArray = strlen(str);
        for(usize i = 0; i < lenOfArray; i++) {
            if(str[i] < 0) {
                return false;
            }
        }
        return true;
    }




    String stringAdder() {
        return String("");
    }

    template<typename E, typename... T>
    String stringAdder(E e, T... t) {
        String str = ""_s + e;
        return str + stringAdder(t...);
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
            return "0.0";
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

        long long number = Math.round(tempFloat);
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

        long long number = Math.round(tempDouble);
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

        long long number = Math.round(tempLongDouble);
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

        long long number = Math.round(tempFloat);
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

        long long number = Math.round(tempDouble);
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