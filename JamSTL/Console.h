#pragma once

#ifndef JAMSTL_CONSOLE_H
#define JAMSTL_CONSOLE_H
#include "IO/InputStream.h"
#include "IO/PrintStream.h"

JAMSTL_NAMESPACE_BEGIN


class Console extends Object {
private:
    InputStream in;
    PrintStream out;
public:
    Console() : in(stdin), out(stdout) {}

    ~Console() {
        this->colorDefault();
    }

    void wait() {
        in.nextLine();
    }

    void wait(const char* message) {
        out.println(message);
        wait();
    }

    void wait(const String& message) {
        out.println(message);
        wait();
    }

    void colorOrange() {
        out << "\033[33m";
    }

    void colorLightBlue() {
        #ifdef _WIN32
            out << "\033[36m";
        #else
            out << "\033[96m";
        #endif
    }

    void colorPurple() {
        #ifdef _WIN32
            out << "\033[34m";
        #else
            out << "\033[34m";
        #endif
    }

    void colorRed() {
        #ifdef _WIN32
            out << "\033[91m";
        #else
            out << "\033[91m";
        #endif
    }

    void colorGreen() {
        #ifdef _WIN32
            out << "\033[32m";
        #else
            out << "\033[92m";
        #endif
    }

    void colorMagenta() {
        #ifdef _WIN32
            out << "\033[31m";
        #else
            out << "\033[31m";
        #endif
    }

    void colorWhite() {

        #ifdef _WIN32
            out << "\033[37m";
        #else
            out << "\033[97m";
        #endif
    }

    void colorDefault() {
        out << "\033[0m";
    }
};


JAMSTL_NAMESPACE_END


#endif