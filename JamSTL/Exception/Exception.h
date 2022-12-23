#pragma once

#ifndef JAMSTL_EXCEPTION_H
#define JAMSTL_EXCEPTION_H
#include "../Macros.h"
#include "../Object.h"

JAMSTL_NAMESPACE_BEGIN

    struct ExceptionData {
        const char* exceptionMessage;
        bool doFree;
    };

    void exceptionCopy(const ExceptionData& from, ExceptionData& to) {
        to.exceptionMessage = from.exceptionMessage;
        to.doFree = from.doFree;
    }

    void exceptionDestroy(ExceptionData& data) {
        if(data.doFree) {
            data.exceptionMessage = "";
        }
    }

    class Exception extends Object {
        private:
            ExceptionData exceptions;
        public:
            Exception() noexcept : exceptions() {}

            Exception(const char* message) noexcept : exceptions() {
                ExceptionData initData = { message, true };
                exceptionCopy(initData, exceptions);
            }

            Exception(const char* message, int) noexcept : exceptions() {
                exceptions.exceptionMessage = message;
                exceptions.doFree = false;
            }

            Exception(const Exception& other) noexcept : exceptions() {
                exceptionCopy(other.exceptions, exceptions);
            }

            Exception(Exception&& other) noexcept : exceptions() {
                exceptionCopy(other.exceptions, exceptions);
                other.exceptions.exceptionMessage = "";
                other.exceptions.doFree = false;
            }

            Exception& operator=(const Exception& other) noexcept {
                exceptionDestroy(exceptions);
                exceptionCopy(other.exceptions, exceptions);
                return *this;
            }

            Exception& operator=(Exception&& other) noexcept {
                exceptionDestroy(exceptions);
                exceptionCopy(other.exceptions, exceptions);
                other.exceptions.exceptionMessage = "";
                other.exceptions.doFree = false;
                return *this;
            }

            virtual ~Exception() noexcept {
                exceptionDestroy(exceptions);
            }

            virtual const char* getMessage() const noexcept {
                return exceptions.exceptionMessage;
            }

    };


JAMSTL_NAMESPACE_END


#endif