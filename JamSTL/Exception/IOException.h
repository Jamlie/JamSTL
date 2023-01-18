#pragma once

#ifndef JAMSTL_IOEXCEPTION_H
#define JAMSTL_IOEXCEPTION_H
#include "Exception.h"

JAMSTL_NAMESPACE_BEGIN


class IOException extends Exception {
public:
    IOException() noexcept : Exception("IOException") {}
    IOException(const char* message) noexcept : Exception(message) {}
    IOException(const char* message, int) noexcept : Exception(message, 0) {}
    IOException(const IOException& other) noexcept : Exception(other) {}
    IOException(IOException&& other) noexcept : Exception(other) {}
    IOException& operator=(const IOException& other) noexcept {
        Exception::operator=(other);
        return *this;
    }
    IOException& operator=(IOException&& other) noexcept {
        Exception::operator=(other);
        return *this;
    }

    ~IOException() noexcept {}

    const char* getMessage() const noexcept override {
        return "IOException";
    }
};


JAMSTL_NAMESPACE_END

#endif