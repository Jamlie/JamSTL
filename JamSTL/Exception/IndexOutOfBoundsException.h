#pragma once

#ifndef JAMSTL_INDEXOUTOFBOUNDSEXCEPTION_H
#define JAMSTL_INDEXOUTOFBOUNDSEXCEPTION_H
#include "Exception.h"

JAMSTL_NAMESPACE_BEGIN

class IndexOutOfBoundsException extends Exception {
    public:
        IndexOutOfBoundsException() noexcept : Exception("IndexOutOfBoundsException") {}
        IndexOutOfBoundsException(const char* message) noexcept : Exception(message) {}
        IndexOutOfBoundsException(const char* message, int) noexcept : Exception(message, 0) {}
        IndexOutOfBoundsException(const IndexOutOfBoundsException& other) noexcept : Exception(other) {}
        IndexOutOfBoundsException(IndexOutOfBoundsException&& other) noexcept : Exception(other) {}
        IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException& other) noexcept {
            Exception::operator=(other);
            return *this;
        }
        IndexOutOfBoundsException& operator=(IndexOutOfBoundsException&& other) noexcept {
            Exception::operator=(other);
            return *this;
        }

        ~IndexOutOfBoundsException() noexcept {}

        const char* getMessage() const noexcept override {
            return "IndexOutOfBoundsException";
        }
};

JAMSTL_NAMESPACE_END



#endif