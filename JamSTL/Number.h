#pragma once

#ifndef JAMSTL_NUMBER_H
#define JAMSTL_NUMBER_H
#include "Macros.h"
#include "String.h"
#include "Object.h"

JAMSTL_NAMESPACE_BEGIN


abstract class Number extends Object {
public:

    Number() {}

    Number(const Number& number) {}

    virtual ~Number() = default;

    virtual int intValue() const = 0;
    virtual long long longValue() const = 0;
    virtual float floatValue() const = 0;
    virtual double doubleValue() const = 0;
    virtual bool equals(const Object& obj) const = 0; 

    virtual Number& operator=(const short& number) = 0;
    virtual Number& operator=(const int& number) = 0;
    virtual Number& operator=(const long& number) = 0;
    virtual Number& operator=(const long long& number) = 0;
    virtual Number& operator=(const float& number) = 0;
    virtual Number& operator=(const double& number) = 0;
    virtual Number& operator=(const Number& number) = 0;

};


JAMSTL_NAMESPACE_END

#endif