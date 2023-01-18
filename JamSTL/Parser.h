#pragma once

#ifndef JAMSTL_PARSER_H
#define JAMSTL_PARSER_H
#include "Macros.h"
#include "Datatypes.h"
#include "Exception/NumberFormatException.h"
#include "String/StringStream.h"

JAMSTL_NAMESPACE_BEGIN


/**
 * @brief Convert a string to an integer.
 * (Integer / int) number = parseInt("123"); std::cout << number; => 123
 * Can be used with input() to get an integer from the user by doing
 * (Integer / int) number = parseInt(input("Enter a number: "));
 * 
 * @param input 
 * @return int 
 */
int parseInt(String input) {
    if(!input.isNumeric() && input[0] != '-') {
        throw NumberFormatException();
    }
    Integer temp(0);
    StringStream stream;
    stream << input;
    stream >> temp;
    return temp;
}

/**
 * @brief Convert a string to a float
 * (Float / float) number = parseFloat("123.456"); std::cout << number; => 123.456
 * Can be used with input() to get a float from the user by doing
 * (Float / float) number = parseFloat(input("Enter a number: "));
 * 
 * @param input 
 * @return float 
 */
Float parseFloat(String input) {
    if(!input.isNumeric() && input.contains('.') && input[0] != '-');
    else if(!input.isNumeric() && !input.contains('.') && input[0] != '-') {
        throw NumberFormatException();
    }

    Float temp(0);
    StringStream stream;
    stream << input;
    stream >> temp;
    return temp;
}

/**
 * @brief Convert a string to a double
 * (Double / double) number = parseDouble("123.456"); std::cout << number; => 123.456
 * Can be used with input() to get a double from the user by doing
 * (Double / double) number = parseDouble(input("Enter a number: "));
 * 
 * @param input 
 * @return double 
 */
double parseDouble(String input) {
    if(!input.isNumeric() && input.contains('.') && input[0] != '-');
    else if(!input.isNumeric() && !input.contains('.') && input[0] != '-') {
        throw NumberFormatException();
    }
    Double temp(0);
    StringStream stream;
    stream << input;
    stream >> temp;
    return temp;
}

/**
 * @brief Convert a string to a short
 * (Short / short) number = parseShort("123"); std::cout << number; => 123
 * Can be used with input() to get a short from the user by doing
 * (Short / short) number = parseShort(input("Enter a number: "));
 * 
 * @param input 
 * @return short int 
 */
short int parseShort(String input) {
    if(!input.isNumeric() && input[0] != '-') {
        throw NumberFormatException();
    }
    Short temp(0);
    StringStream stream;
    stream << input;
    stream >> temp;
    return temp;
}

/**
 * @brief Convert a string to a long long
 * (Long / long long) number = parseLong("123"); std::cout << number; => 123
 * Can be used with input() to get a long long from the user by doing
 * (Long / long long) number = parseLong(input("Enter a number: "));
 * 
 * @param input 
 * @return long long 
 */
long long parseLong(String input) {
    if(!input.isNumeric() && input[0] != '-') {
        throw NumberFormatException();
    }
    Long temp(0);
    StringStream stream;
    stream << input;
    stream >> temp;
    return temp;
}

/**
 * @brief Convert any type into a string (except for wrapper classes)
 * 
 * @tparam Type The type to convert to a string.
 * @param input Input from user.
 * @return String 
 */
template<typename Type>
String parseString(Type input) {
    String temp;
    StringStream stream;
    stream << input;
    stream >> temp;
    return temp;
}


JAMSTL_NAMESPACE_END


#endif