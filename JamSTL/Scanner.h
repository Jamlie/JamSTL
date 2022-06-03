#pragma once

#include <istream>

#ifndef JAMSTL_SCANNER_H
#define JAMSTL_SCANNER_H

#include "Datatypes.h"
#include "Macros.h"
#include "StringStream.h"

JAMSTL_NAMESPACE_BEGIN
    class Scanner {
    public:
        Scanner() = default;

        String scan() {
            String result;
            char c;
            while (std::cin.get(c)) {
                if (c == '\n') return result;
                result += c;
            }
            return result;
        }

        String nextLine() {
            String temp;
            std::cin >> temp;
            String result = temp;
            return result;
        }

        int nextInt() {
            Integer temp(0);
            std::cin >> temp;
            Integer result = temp;
            std::cin.ignore();
            return temp;
        }

        unsigned short nextUShort() {
            unsigned short temp(0);
            std::cin >> temp;
            unsigned short result = temp;
            std::cin.ignore();
            return result;
        }

        unsigned nextUnsigned() {
            unsigned temp(0);
            std::cin >> temp;
            unsigned result = temp;
            std::cin.ignore();
            return result;
        }

        unsigned long long nextULong() {
            unsigned long long temp(0);
            std::cin >> temp;
            unsigned long long result = temp;
            std::cin.ignore();
            return result;
        }

        float nextFloat() {
            Float temp(0);
            std::cin >> temp;
            Float result = temp;
            std::cin.ignore();
            return result;
        }

        long double nextDouble() {
            Double temp(0);
            std::cin >> temp;
            Double result = temp;
            std::cin.ignore();
            return result;
        }

        short nextShort() {
            Short temp(0);
            std::cin >> temp;
            Short result = temp;
            std::cin.ignore();
            return result;
        }

        long long nextLong() {
            Long temp(0);
            std::cin >> temp;
            Long result = temp;
            std::cin.ignore();
            return result;
        }

        char nextChar() {
            char temp(0);
            std::cin >> temp;
            char result = temp;
            std::cin.ignore();
            return result;
        }

        unsigned char nextUChar() {
            unsigned char temp(0);
            std::cin >> temp;
            unsigned char result = temp;
            std::cin.ignore();
            return result;
        }

        void wait() {
            std::cin.get();
        }

        void clear() {
            std::cin.clear();
        }

        void ignore() {
            std::cin.ignore();
        }

        void ignore(int n) {
            std::cin.ignore(n);
        }

        void ignore(char c) {
            std::cin.ignore(1, c);
        }

        void ignore(char c, int n) {
            std::cin.ignore(n, c);
        }
    };

    String input(StringView prompt) {
        std::cout << prompt;
        return Scanner().scan();
    }

    /**
     * @brief Convert a string to an integer.
     * (Integer / int) number = parseInt("123"); std::cout << number; => 123
     * Can be used with input() to get an integer from the user by doing
     * (Integer / int) number = parseInt(input("Enter a number: "));
     * 
     * @param input 
     * @return int 
     */
    int parseInt(String input) {
        Integer temp(0);
        StringStream stream;
        stream << input;
        stream >> temp;
        return temp;
    }

    /**
     * @brief Convert a string to a float
     * (Float / float) number = parseFloat("123.456"); std::cout << number; => 123.456
     * Can be used with input() to get a float from the user by doing
     * (Float / float) number = parseFloat(input("Enter a number: "));
     * 
     * @param input 
     * @return float 
     */
    Float parseFloat(String input) {
        Float temp(0);
        StringStream stream;
        stream << input;
        stream >> temp;
        return temp;
    }

    /**
     * @brief Convert a string to a double
     * (Double / double) number = parseDouble("123.456"); std::cout << number; => 123.456
     * Can be used with input() to get a double from the user by doing
     * (Double / double) number = parseDouble(input("Enter a number: "));
     * 
     * @param input 
     * @return double 
     */
    double parseDouble(String input) {
        Double temp(0);
        StringStream stream;
        stream << input;
        stream >> temp;
        return temp;
    }

    /**
     * @brief Convert a string to a short
     * (Short / short) number = parseShort("123"); std::cout << number; => 123
     * Can be used with input() to get a short from the user by doing
     * (Short / short) number = parseShort(input("Enter a number: "));
     * 
     * @param input 
     * @return short int 
     */
    short int parseShort(String input) {
        Short temp(0);
        StringStream stream;
        stream << input;
        stream >> temp;
        return temp;
    }

    /**
     * @brief Convert a string to a long long
     * (Long / long long) number = parseLong("123"); std::cout << number; => 123
     * Can be used with input() to get a long long from the user by doing
     * (Long / long long) number = parseLong(input("Enter a number: "));
     * 
     * @param input 
     * @return long long 
     */
    long long parseLong(String input) {
        Long temp(0);
        StringStream stream;
        stream << input;
        stream >> temp;
        return temp;
    }

    /**
     * @brief Convert any type into a string (except for wrapper classes)
     * 
     * @tparam Type The type to convert to a string.
     * @param input Input from user.
     * @return String 
     */
    template<typename Type>
    String parseString(Type input) {
        String temp;
        StringStream stream;
        stream << input;
        stream >> temp;
        return temp;
    }

JAMSTL_NAMESPACE_END

#endif