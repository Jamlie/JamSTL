#pragma once

#ifndef JAMSTL_STRINGINDEXOUTOFBOUNDSEXCEPTION_H
#define JAMSTL_STRINGINDEXOUTOFBOUNDSEXCEPTION_H
#include "Exception.h"

JAMSTL_NAMESPACE_BEGIN


class StringIndexOutOfBoundsException extends Exception {
public:
    StringIndexOutOfBoundsException() noexcept : Exception() {}
    StringIndexOutOfBoundsException(const char* message) noexcept : Exception(message) {}
    StringIndexOutOfBoundsException(const char* message, int) noexcept : Exception(message, 0) {}
    StringIndexOutOfBoundsException(const StringIndexOutOfBoundsException& other) noexcept : Exception(other) {}
    StringIndexOutOfBoundsException(StringIndexOutOfBoundsException&& other) noexcept : Exception(other) {}
    StringIndexOutOfBoundsException& operator=(const StringIndexOutOfBoundsException& other) noexcept {
        Exception::operator=(other);
        return *this;
    }
    StringIndexOutOfBoundsException& operator=(StringIndexOutOfBoundsException&& other) noexcept {
        Exception::operator=(other);
        return *this;
    }

    ~StringIndexOutOfBoundsException() noexcept {}

    const char* getMessage() const noexcept override {
        return "StringIndexOutOfBoundsException";
    }
};


JAMSTL_NAMESPACE_END

#endif