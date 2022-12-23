#pragma once

#ifndef JAMSTL_ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
#define JAMSTL_ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
#include "Exception.h"

JAMSTL_NAMESPACE_BEGIN

class ArrayIndexOutOfBoundsException extends Exception {
public:
    ArrayIndexOutOfBoundsException() noexcept : Exception("ArrayIndexOutOfBoundsException") {}
    ArrayIndexOutOfBoundsException(String message) noexcept : Exception(message) {}
    ArrayIndexOutOfBoundsException(const char* message, int) noexcept : Exception(message, 0) {}
    ArrayIndexOutOfBoundsException(const char* message) noexcept : Exception(message) {}
    ArrayIndexOutOfBoundsException(const ArrayIndexOutOfBoundsException& e) noexcept : Exception(e) {}
    ArrayIndexOutOfBoundsException(ArrayIndexOutOfBoundsException&& e) noexcept : Exception(e) {}
    ~ArrayIndexOutOfBoundsException() {}

    ArrayIndexOutOfBoundsException& operator=(const ArrayIndexOutOfBoundsException& e) {
        Exception::operator=(e);
        return *this;
    }

    ArrayIndexOutOfBoundsException& operator=(ArrayIndexOutOfBoundsException&& e) {
        Exception::operator=(e);
        return *this;
    }

    // getMessage
    const char* getMessage() const noexcept override {
        return "ArrayIndexOutOfBoundsException";
    }
};

JAMSTL_NAMESPACE_END


#endif