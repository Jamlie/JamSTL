#pragma once

#ifndef JAMSTL_NULLPOINTEREXCEPTION_H
#define JAMSTL_NULLPOINTEREXCEPTION_H
#include "Exception.h"

JAMSTL_NAMESPACE_BEGIN

    class NullPointerException extends Exception {
        public:
            NullPointerException() noexcept : Exception("NullPointerException") {}
            NullPointerException(const char* message) noexcept : Exception(message) {}
            NullPointerException(const char* message, int) noexcept : Exception(message, 0) {}
            NullPointerException(const NullPointerException& other) noexcept : Exception(other) {}
            NullPointerException(NullPointerException&& other) noexcept : Exception(other) {}
            NullPointerException& operator=(const NullPointerException& other) noexcept {
                Exception::operator=(other);
                return *this;
            }
            NullPointerException& operator=(NullPointerException&& other) noexcept {
                Exception::operator=(other);
                return *this;
            }

            ~NullPointerException() noexcept {}

            const char* getMessage() const noexcept override {
                return "NullPointerException";
            }
    };

JAMSTL_NAMESPACE_END

#endif