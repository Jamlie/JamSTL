#pragma once

#include <iostream>

#ifndef _SCANNER_H
#define _SCANNER_H

#include "Datatypes.h"

class Scanner {
public:
    Scanner() = default;

    String nextLine() {
        String temp;
        std::cin >> temp;
        return temp;
    }

    int nextInt() {
        Integer temp(0);
        std::cin >> temp;
        return temp;
    }

    unsigned short nextUShort() {
        unsigned short temp(0);
        std::cin >> temp;
        return temp;
    }

    unsigned nextUnsigned() {
        unsigned temp(0);
        std::cin >> temp;
        return temp;
    }

    unsigned long long nextULong() {
        unsigned long long temp(0);
        std::cin >> temp;
        return temp;
    }

    float nextFloat() {
        Float temp(0);
        std::cin >> temp;
        return temp;
    }

    long double nextDouble() {
        Double temp(0);
        std::cin >> temp;
        return temp;
    }

    short nextShort() {
        Short temp(0);
        std::cin >> temp;
        return temp;
    }

    long long nextLong() {
        Long temp(0);
        std::cin >> temp;
        return temp;
    }

    char nextChar() {
        char temp(0);
        std::cin >> temp;
        return temp;
    }

    unsigned char nextUChar() {
        unsigned char temp(0);
        std::cin >> temp;
        return temp;
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
};

#endif
