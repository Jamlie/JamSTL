#pragma once

#ifndef JAMSTL_ARITHMETICEXCEPTION_H
#define JAMSTL_ARITHMETICEXCEPTION_H
#include "Exception.h"

JAMSTL_NAMESPACE_BEGIN


class ArithmeticException extends Exception {
public:
    ArithmeticException() noexcept : Exception("ArithmeticException") {}
    ArithmeticException(const char* message) noexcept : Exception(message) {}
    ArithmeticException(const char* message, int) noexcept : Exception(message, 0) {}
    ArithmeticException(const ArithmeticException& other) noexcept : Exception(other) {}
    ArithmeticException(ArithmeticException&& other) noexcept : Exception(other) {}
    ArithmeticException& operator=(const ArithmeticException& other) noexcept {
        Exception::operator=(other);
        return *this;
    }

    ArithmeticException& operator=(ArithmeticException&& other) noexcept {
        Exception::operator=(other);
        return *this;
    }

    ~ArithmeticException() noexcept {}

    const char* getMessage() const noexcept override {
        return "ArithmeticException";
    }

};


JAMSTL_NAMESPACE_END

#endif