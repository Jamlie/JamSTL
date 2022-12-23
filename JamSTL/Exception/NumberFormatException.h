#pragma once

#ifndef JAMSTL_NUMBERFORMATEXCEPTION_H
#define JAMSTL_NUMBERFORMATEXCEPTION_H
#include "Exception.h"

JAMSTL_NAMESPACE_BEGIN

class NumberFormatException extends Exception {
public:
    NumberFormatException() noexcept : Exception() {}
    NumberFormatException(const char* message) noexcept : Exception(message) {}
    NumberFormatException(const char* message, int) noexcept : Exception(message, 0) {}
    NumberFormatException(const NumberFormatException& other) noexcept : Exception(other) {}
    NumberFormatException(NumberFormatException&& other) noexcept : Exception(other) {}
    NumberFormatException& operator=(const NumberFormatException& other) noexcept {
        Exception::operator=(other);
        return *this;
    }
    NumberFormatException& operator=(NumberFormatException&& other) noexcept {
        Exception::operator=(other);
        return *this;
    }

    ~NumberFormatException() noexcept {}

    const char* getMessage() const noexcept override {
        return "NumberFormatException";
    }
};

JAMSTL_NAMESPACE_END

#endif