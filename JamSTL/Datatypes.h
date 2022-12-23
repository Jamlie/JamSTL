#pragma once

#ifndef JAMSTL_DATATYPES_H
#define JAMSTL_DATATYPES_H 1
#include "Macros.h"
#include "Byte.h"
#include "Short.h"
#include "Character.h"
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"
#include "Boolean.h"
#include "String.h"

JAMSTL_NAMESPACE_BEGIN


    String operator""_s(const char* str, size_t len) {
        return String(str, len);
    }

    Character operator""_c(const char c) {
        return Character(c);
    }

    Byte operator""_b(const char c) {
        return Byte(c);
    }

    Short operator""_s(unsigned long long i) {
        return Short(i);
    }

    Integer operator""_i(unsigned long long i) {
        return Integer(i);
    }

    Long operator""_l(unsigned long long i) {
        return Long(i);
    }

    Float operator""_f(long double d) {
        return Float(d);
    }

    Double operator""_D(long double d) {
        return Double(d);
    }



    using StringView  = const String&;

    using DoubleView  = const Double&;

    using FloatView   = const Float&;

    using IntegerView = const Integer&;

    using ShortView   = const Short&;

    using BooleanView = const Boolean&;

    using LongView    = const Long&;

    const String _ = "";

JAMSTL_NAMESPACE_END

#endif