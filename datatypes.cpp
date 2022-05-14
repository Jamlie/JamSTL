#pragma once

// ! Omar Estietie

#include <iostream>
#include <cstring>
#include <string>
#include <functional>

#ifndef _INTEGER_HPP_
#define _INTEGER_HPP_

/**
 * @brief An integer wrapper class
 * 
 */
class Integer {
private:
    int value;
    friend class Long;
    friend class Float;
    friend class Double;
    friend class Short;
public:
    Integer() : value(0) {}

    Integer(const short& value) : value(value) {}
    
    Integer(const int& value) : value(value) {}

    Integer(const float& value) : value(value) {}

    Integer(const double& value) : value(value) {}

    Integer(const long& value) : value(value) {}

    Integer(const long long& value) : value(value) {}

    Integer(const unsigned int& value) : value(value) {}

    Integer(const unsigned long& value) : value(value) {}

    Integer(const unsigned long long& value) : value(value) {}

    Integer(const char* value) : value(atoi(value)) {}

    Integer(const long double value) : value(value) {}


    Integer& operator=(const Integer& other) {
        this->value = other.value;
        return *this;
    }

    Integer& operator=(const int& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const float& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const double& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const long& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const long long& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const unsigned int& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const unsigned long& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const unsigned long long& other) {
        this->value = other;
        return *this;
    }

    Integer& operator=(const char* other) {
        this->value = atoi(other);
        return *this;
    }

    Integer& operator=(const long double other) {
        this->value = other;
        return *this;
    }

    Integer& operator+=(const short& other) {
        this->value += other;
        return *this;
    }


    /**
     * @brief A method that converts an Integer to a String
     * 
     * @return auto 
     */
    auto toString() const {
        return std::to_string(value);
    }

    /**
     * @brief A method that reverses the order of the digits of an Integer
     * 
     * @return Integer& 
     */
    Integer& reverse() {
        int temp = 0;
        int remainder = 0;
        int original = value;
        while (original != 0) {
            remainder = original % 10;
            temp = temp * 10 + remainder;
            original /= 10;
        }
        value = temp;
        return *this;
    }

    /**
     * @brief A method that converts a String to an Integer.
     * 
     * @param string 
     * @return Integer& 
     */
    Integer& parseInt(const char* string) {
        value = atoi(string);
        return *this;
    }

    /**
     * @brief A method that returns the number of digits of a given Integer
     * 
     * @return Integer 
     */
    Integer length() {
        int length = 0;
        int original = value;
        while (original != 0) {
            original /= 10;
            length++;
        }
        return length;
    }

    /**
     * @brief A method that returns the type of an Integer
     * 
     * @return const char* 
     */
    const char* type() const {
        return "Integer";
    }

    /**
     * @brief Max value of an Integer
     * 
     * @return Integer 
     */
    Integer largestIntValue() {
        return 2147483647;
    }

    /**
     * @brief Min value of an
     * 
     * @return Integer 
     */
    Integer smallestIntValue() {
        return -2147483648;
    }

    /**
     * @brief A method that checks if an Integer is positive, negative or zero
     * 
     * @return Integer 
     */
    Integer signum() {
        if (this->value > 0) {
            return 1;
        }
        else if (value < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }

    /**
     * @brief Absolute value of an integer
     * 
     * @return Integer& 
     */
    Integer& abs() {
        if (this->value < 0) {
            this->value = -this->value;
        }
        return *this;
    }

    /**
     * @brief Make an Integer negative
     * 
     * @return Integer& 
     */
    Integer& negate() {
        this->value = -this->value;
        return *this;
    }

    /**
     * @brief A method that adds two Integers
     * 
     * @param other 
     * @return Integer& 
     */
    Integer& add(const Integer& other) {
        this->value += other.value;
        return *this;
    }

    /**
     * @brief A method that adds two Integers
     * 
     * @param other 
     * @return Integer& 
     */
    Integer& add(const int& other) {
        this->value += other;
        return *this;
    }

    /**
     * @brief A method that adds two numbers
     * 
     * @param other 
     * @return Integer& 
     */
    Integer& add(const float& other) {
        this->value += other;
        return *this;
    }

    /**
     * @brief A method that swaps the value of two integers
     * 
     * @param other 
     * @return Integer& 
     */
    Integer& swap(Integer& other) {
        Integer temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    /**
     * @brief A method that swaps the value of integer and another type
     * 
     * @tparam T 
     * @param other 
     * @return Integer& 
     */
    template <typename T>
    Integer& swap(T& other) {
        Integer temp;
        temp.value = this->value;
        this->value = other;
        other = temp.value;
        return *this;
    }

    operator int() {
        return value;
    }



    Integer& operator+=(const Integer& other) {
        this->value += other.value;
        return *this;
    }

    Integer& operator+=(const int& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const float& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const double& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const long& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const long long& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const unsigned int& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const unsigned long& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const unsigned long long& other) {
        this->value += other;
        return *this;
    }

    Integer& operator+=(const char* other) {
        this->value += atoi(other);
        return *this;
    }

    Integer& operator+=(const long double other) {
        this->value += other;
        return *this;
    }

    Integer& operator-=(const short& other) {
        this->value -= other;
        return *this;
    }



    Integer& operator-=(const Integer& other) {
        this->value -= other.value;
        return *this;
    }

    Integer& operator-=(const int& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const float& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const double& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const long& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const long long& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const unsigned int& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const unsigned long& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const unsigned long long& other) {
        this->value -= other;
        return *this;
    }

    Integer& operator-=(const char* other) {
        this->value -= atoi(other);
        return *this;
    }

    Integer& operator-=(const long double other) {
        this->value -= other;
        return *this;
    }

    Integer& operator*=(const short& other) {
        this->value *= other;
        return *this;
    }



    Integer& operator*=(const Integer& other) {
        this->value *= other.value;
        return *this;
    }

    Integer& operator*=(const int& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const float& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const double& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const long& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const long long& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const unsigned int& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const unsigned long& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const unsigned long long& other) {
        this->value *= other;
        return *this;
    }

    Integer& operator*=(const char* other) {
        this->value *= atoi(other);
        return *this;
    }

    Integer& operator*=(const long double other) {
        this->value *= other;
        return *this;
    }

    Integer& operator/=(const short& other) {
        this->value /= other;
        return *this;
    }



    Integer& operator/=(const Integer& other) {
        this->value /= other.value;
        return *this;
    }

    Integer& operator/=(const int& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const float& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const double& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const long& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const long long& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const unsigned int& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const unsigned long& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const unsigned long long& other) {
        this->value /= other;
        return *this;
    }

    Integer& operator/=(const char* other) {
        this->value /= atoi(other);
        return *this;
    }

    Integer& operator/=(const long double other) {
        this->value /= other;
        return *this;
    }

    Integer& operator%=(const short& other) {
        this->value %= other;
        return *this;
    }



    Integer& operator%=(const Integer& other) {
        this->value %= other.value;
        return *this;
    }

    Integer& operator%=(const int& other) {
        this->value %= other;
        return *this;
    }

    Integer& operator%=(const long& other) {
        this->value %= other;
        return *this;
    }

    Integer& operator%=(const long long& other) {
        this->value %= other;
        return *this;
    }

    Integer& operator%=(const unsigned int& other) {
        this->value %= other;
        return *this;
    }

    Integer& operator%=(const unsigned long& other) {
        this->value %= other;
        return *this;
    }

    Integer& operator%=(const unsigned long long& other) {
        this->value %= other;
        return *this;
    }

    Integer& operator%=(const char* other) {
        this->value %= atoi(other);
        return *this;
    }



    Integer& operator++() {
        this->value++;
        return *this;
    }

    Integer& operator--() {
        this->value--;
        return *this;
    }

    Integer operator++(int) {
        Integer temp = *this;
        this->value++;
        return temp;
    }

    Integer operator--(int) {
        Integer temp = *this;
        this->value--;
        return temp;
    }



    Integer operator+(const Integer& other) const {
        return Integer(this->value + other.value);
    }

    Integer operator+(const int& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const float& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const double& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const long& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const long long& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const unsigned int& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const unsigned long& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const unsigned long long& other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const char* other) const {
        return Integer(this->value + atoi(other));
    }

    Integer operator+(const long double other) const {
        return Integer(this->value + other);
    }

    Integer operator+(const short& other) const {
        return Integer(this->value + other);
    }



    Integer operator-(const Integer& other) const {
        return Integer(this->value - other.value);
    }

    Integer operator-(const int& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const float& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const double& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const long& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const long long& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const unsigned int& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const unsigned long& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const unsigned long long& other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const char* other) const {
        return Integer(this->value - atoi(other));
    }

    Integer operator-(const long double other) const {
        return Integer(this->value - other);
    }

    Integer operator-(const short& other) const {
        return Integer(this->value - other);
    }



    Integer operator*(const Integer& other) const {
        return Integer(this->value * other.value);
    }

    Integer operator*(const int& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const float& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const double& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const long& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const long long& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const unsigned int& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const unsigned long& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const unsigned long long& other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const char* other) const {
        return Integer(this->value * atoi(other));
    }

    Integer operator*(const long double other) const {
        return Integer(this->value * other);
    }

    Integer operator*(const short& other) const {
        return Integer(this->value * other);
    }



    Integer operator/(const Integer& other) const {
        return Integer(this->value / other.value);
    }

    Integer operator/(const int& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const float& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const double& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const long& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const long long& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const unsigned int& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const unsigned long& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const unsigned long long& other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const char* other) const {
        return Integer(this->value / atoi(other));
    }

    Integer operator/(const long double other) const {
        return Integer(this->value / other);
    }

    Integer operator/(const short& other) const {
        return Integer(this->value / other);
    }



    Integer operator%(const Integer& other) const {
        return Integer(this->value % other.value);
    }

    Integer operator%(const int& other) const {
        return Integer(this->value % other);
    }

    Integer operator%(const long& other) const {
        return Integer(this->value % other);
    }

    Integer operator%(const long long& other) const {
        return Integer(this->value % other);
    }

    Integer operator%(const unsigned int& other) const {
        return Integer(this->value % other);
    }

    Integer operator%(const unsigned long& other) const {
        return Integer(this->value % other);
    }

    Integer operator%(const unsigned long long& other) const {
        return Integer(this->value % other);
    }

    Integer operator%(const char* other) const {
        return Integer(this->value % atoi(other));
    }

    Integer operator%(const short other) const {
        return Integer(this->value % other);
    }



    bool operator==(const Integer& other) const {
        return this->value == other.value;
    }

    bool operator==(const int& other) const {
        return this->value == other;
    }

    bool operator==(const float& other) const {
        return this->value == other;
    }

    bool operator==(const double& other) const {
        return this->value == other;
    }

    bool operator==(const long& other) const {
        return this->value == other;
    }

    bool operator==(const long long& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned int& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long long& other) const {
        return this->value == other;
    }

    bool operator==(const char* other) const {
        return this->value == atoi(other);
    }

    bool operator==(const long double other) const {
        return this->value == other;
    }

    bool operator==(const short other) const {
        return this->value == other;
    }



    bool operator!=(const Integer& other) const {
        return this->value != other.value;
    }

    bool operator!=(const int& other) const {
        return this->value != other;
    }

    bool operator!=(const float& other) const {
        return this->value != other;
    }

    bool operator!=(const double& other) const {
        return this->value != other;
    }

    bool operator!=(const long& other) const {
        return this->value != other;
    }

    bool operator!=(const long long& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned int& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long long& other) const {
        return this->value != other;
    }

    bool operator!=(const char* other) const {
        return this->value != atoi(other);
    }

    bool operator!=(const long double other) const {
        return this->value != other;
    }

    bool operator!=(const short other) const {
        return this->value != other;
    }



    bool operator<(const Integer& other) const {
        return this->value < other.value;
    }

    bool operator<(const int& other) const {
        return this->value < other;
    }

    bool operator<(const float& other) const {
        return this->value < other;
    }

    bool operator<(const double& other) const {
        return this->value < other;
    }

    bool operator<(const long& other) const {
        return this->value < other;
    }

    bool operator<(const long long& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned int& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long long& other) const {
        return this->value < other;
    }

    bool operator<(const char* other) const {
        return this->value < atoi(other);
    }

    bool operator<(const long double other) const {
        return this->value < other;
    }

    bool operator<(const short other) const {
        return this->value < other;
    }



    bool operator>(const Integer& other) const {
        return this->value > other.value;
    }

    bool operator>(const int& other) const {
        return this->value > other;
    }

    bool operator>(const float& other) const {
        return this->value > other;
    }

    bool operator>(const double& other) const {
        return this->value > other;
    }

    bool operator>(const long& other) const {
        return this->value > other;
    }

    bool operator>(const long long& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned int& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long long& other) const {
        return this->value > other;
    }

    bool operator>(const char* other) const {
        return this->value > atoi(other);
    }

    bool operator>(const long double other) const {
        return this->value > other;
    }

    bool operator>(const short other) const {
        return this->value > other;
    }



    bool operator<=(const Integer& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const int& other) const {
        return this->value <= other;
    }

    bool operator<=(const float& other) const {
        return this->value <= other;
    }

    bool operator<=(const double& other) const {
        return this->value <= other;
    }

    bool operator<=(const long& other) const {
        return this->value <= other;
    }

    bool operator<=(const long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned int& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const char* other) const {
        return this->value <= atoi(other);
    }

    bool operator<=(const long double other) const {
        return this->value <= other;
    }

    bool operator<=(const short other) const {
        return this->value <= other;
    }



    bool operator>=(const Integer& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const int& other) const {
        return this->value >= other;
    }

    bool operator>=(const float& other) const {
        return this->value >= other;
    }

    bool operator>=(const double& other) const {
        return this->value >= other;
    }

    bool operator>=(const long& other) const {
        return this->value >= other;
    }

    bool operator>=(const long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned int& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const char* other) const {
        return this->value >= atoi(other);
    }

    bool operator>=(const long double other) const {
        return this->value >= other;
    }

    bool operator>=(const short other) const {
        return this->value >= other;
    }



    bool operator!() const {
        return !this->value;
    }

    Integer operator~() const {
        return Integer(~this->value);
    }

    Integer operator-() const {
        return Integer(-this->value);
    }

    Integer operator+() const {
        return Integer(+this->value);
    }

    bool operator&&(const Integer& other) const {
        return this->value && other.value;
    }

    bool operator&&(const int& other) const {
        return this->value && other;
    }

    bool operator&&(const long double& other) const {
        return this->value && other;
    }

    bool operator&&(const float& other) const {
        return this->value && other;
    }

    bool operator&&(const double& other) const {
        return this->value && other;
    }

    bool operator&&(const long& other) const {
        return this->value && other;
    }

    bool operator&&(const long long& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned int& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned long& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned long long& other) const {
        return this->value && other;
    }

    bool operator&&(const char* other) const {
        return this->value && atoi(other);
    }

    bool operator&&(const short other) const {
        return this->value && other;
    }



    bool operator||(const Integer& other) const {
        return this->value || other.value;
    }

    bool operator||(const int& other) const {
        return this->value || other;
    }

    bool operator||(const long double& other) const {
        return this->value || other;
    }

    bool operator||(const float& other) const {
        return this->value || other;
    }

    bool operator||(const double& other) const {
        return this->value || other;
    }

    bool operator||(const long& other) const {
        return this->value || other;
    }

    bool operator||(const long long& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned int& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned long& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned long long& other) const {
        return this->value || other;
    }

    bool operator||(const char* other) const {
        return this->value || atoi(other);
    }

    bool operator||(const short other) const {
        return this->value || other;
    }



    Integer operator&(const Integer& other) const {
        return Integer(this->value & other.value);
    }

    Integer operator&(const int& other) const {
        return Integer(this->value & other);
    }

    Integer operator&(const long& other) const {
        return Integer(this->value & other);
    }

    Integer operator&(const long long& other) const {
        return Integer(this->value & other);
    }

    Integer operator&(const unsigned int& other) const {
        return Integer(this->value & other);
    }

    Integer operator&(const unsigned long& other) const {
        return Integer(this->value & other);
    }

    Integer operator&(const unsigned long long& other) const {
        return Integer(this->value & other);
    }

    Integer operator&(const char* other) const {
        return Integer(this->value & atoi(other));
    }

    Integer operator&(const short other) const {
        return Integer(this->value & other);
    }



    Integer operator|(const Integer& other) const {
        return Integer(this->value | other.value);
    }

    Integer operator|(const int& other) const {
        return Integer(this->value | other);
    }

    Integer operator|(const long& other) const {
        return Integer(this->value | other);
    }

    Integer operator|(const long long& other) const {
        return Integer(this->value | other);
    }

    Integer operator|(const unsigned int& other) const {
        return Integer(this->value | other);
    }

    Integer operator|(const unsigned long& other) const {
        return Integer(this->value | other);
    }

    Integer operator|(const unsigned long long& other) const {
        return Integer(this->value | other);
    }

    Integer operator|(const char* other) const {
        return Integer(this->value | atoi(other));
    }

    Integer operator|(const short other) const {
        return Integer(this->value | other);
    }



    Integer operator^(const Integer& other) const {
        return Integer(this->value ^ other.value);
    }

    Integer operator^(const int& other) const {
        return Integer(this->value ^ other);
    }

    Integer operator^(const long& other) const {
        return Integer(this->value ^ other);
    }

    Integer operator^(const long long& other) const {
        return Integer(this->value ^ other);
    }

    Integer operator^(const unsigned int& other) const {
        return Integer(this->value ^ other);
    }

    Integer operator^(const unsigned long& other) const {
        return Integer(this->value ^ other);
    }

    Integer operator^(const unsigned long long& other) const {
        return Integer(this->value ^ other);
    }

    Integer operator^(const char* other) const {
        return Integer(this->value ^ atoi(other));
    }

    Integer operator^(const short other) const {
        return Integer(this->value ^ other);
    }



    Integer operator<<(const Integer& other) const {
        return Integer(this->value << other.value);
    }

    Integer operator<<(const int& other) const {
        return Integer(this->value << other);
    }

    Integer operator<<(const long& other) const {
        return Integer(this->value << other);
    }

    Integer operator<<(const long long& other) const {
        return Integer(this->value << other);
    }

    Integer operator<<(const unsigned int& other) const {
        return Integer(this->value << other);
    }

    Integer operator<<(const unsigned long& other) const {
        return Integer(this->value << other);
    }

    Integer operator<<(const unsigned long long& other) const {
        return Integer(this->value << other);
    }

    Integer operator<<(const char* other) const {
        return Integer(this->value << atoi(other));
    }

    Integer operator<<(const short other) const {
        return Integer(this->value << other);
    }



    Integer operator>>(const Integer& other) const {
        return Integer(this->value >> other.value);
    }

    Integer operator>>(const int& other) const {
        return Integer(this->value >> other);
    }

    Integer operator>>(const long& other) const {
        return Integer(this->value >> other);
    }

    Integer operator>>(const long long& other) const {
        return Integer(this->value >> other);
    }

    Integer operator>>(const unsigned int& other) const {
        return Integer(this->value >> other);
    }

    Integer operator>>(const unsigned long& other) const {
        return Integer(this->value >> other);
    }

    Integer operator>>(const unsigned long long& other) const {
        return Integer(this->value >> other);
    }

    Integer operator>>(const char* other) const {
        return Integer(this->value >> atoi(other));
    }

    Integer operator>>(const short other) const {
        return Integer(this->value >> other);
    }



    friend std::ostream& operator<<(std::ostream& out, const Integer& integer) {
        out << integer.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Integer& integer) {
        in >> integer.value;
        return in;
    }
};

/**
 * @brief A short wrapper class
 * 
 */
class Short {
private:
    short value;
    friend class Integer;
    friend class Float;
    friend class Double;
public:
    Short() : value(0) {}

    Short(short value) : value(value) {}

    Short(const Short& other) : value(other.value) {}

    Short(const Integer& other) : value(other.value) {}

    Short(const int& other) : value(other) {}

    Short(const long& other) : value(other) {}

    Short(const long long& other) : value(other) {}

    Short(const unsigned int& other) : value(other) {}

    Short(const unsigned long& other) : value(other) {}

    Short(const unsigned long long& other) : value(other) {}

    Short(const char* other) : value(atoi(other)) {}

    Short(const float& other) : value(other) {}

    Short(const double& other) : value(other) {}

    Short(const char& other) : value(other) {}

    Short(const bool& other) : value(other) {}



    /**
     * @brief A method that converts a Short to a String
     * 
     * @return auto 
     */
    auto toString() const {
        return std::to_string(value);
    }

    /**
     * @brief A method that reverses the order of the digits of a Short
     * 
     * @return Short& 
     */
    Short& reverse() {
        int temp = 0;
        int remainder = 0;
        int original = value;
        while (original != 0) {
            remainder = original % 10;
            temp = temp * 10 + remainder;
            original /= 10;
        }
        value = temp;
        return *this;
    }

    /**
     * @brief A method that converts a String to a Short.
     * 
     * @param string 
     * @return Short& 
     */
    Short& parseShort(const char* string) {
        value = atoi(string);
        return *this;
    }

    /**
     * @brief A method that returns the number of digits of a given Short
     * 
     * @return Short 
     */
    Short length() {
        int length = 0;
        int original = value;
        while (original != 0) {
            original /= 10;
            length++;
        }
        return length;
    }

    /**
     * @brief A method that returns the type of a Short
     * 
     * @return const char* 
     */
    const char* type() const {
        return "Integer";
    }

    /**
     * @brief Max value of an Short
     * 
     * @return Short 
     */
    Short largestIntValue() {
        return __SHRT_MAX__;
    }

    /**
     * @brief Min value of a Short
     * 
     * @return Integer 
     */
    Short smallestIntValue() {
        return -__SHRT_MAX__;
    }

    /**
     * @brief A method that checks if a Short is positive, negative or zero
     * 
     * @return Short 
     */
    Short signum() {
        if (this->value > 0) {
            return 1;
        }
        else if (value < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }

    /**
     * @brief Absolute value of an short
     * 
     * @return Short& 
     */
    Short& abs() {
        if (this->value < 0) {
            this->value = -this->value;
        }
        return *this;
    }

    /**
     * @brief Make an Short negative
     * 
     * @return Short& 
     */
    Short& negate() {
        this->value = -this->value;
        return *this;
    }

    /**
     * @brief A method that adds two Shorts
     * 
     * @param other 
     * @return Short& 
     */
    Short& add(const Short& other) {
        this->value += other.value;
        return *this;
    }

    /**
     * @brief A method that adds two Shorts
     * 
     * @param other 
     * @return Short& 
     */
    Short& add(const int& other) {
        this->value += other;
        return *this;
    }

    /**
     * @brief A method that adds two numbers
     * 
     * @param other 
     * @return Short& 
     */
    Short& add(const float& other) {
        this->value += other;
        return *this;
    }

    /**
     * @brief A method that swaps the value of two shorts
     * 
     * @param other 
     * @return Short& 
     */
    Short& swap(Short& other) {
        Short temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    /**
     * @brief A method that swaps the value of short and another type
     * 
     * @tparam T 
     * @param other 
     * @return Short& 
     */
    template <typename T>
    Short& swap(T& other) {
        Short temp;
        temp.value = this->value;
        this->value = other;
        other = temp.value;
        return *this;
    }

    operator short() const {
        return this->value;
    }
    


    Short operator+(const short& other) const {
        return Short(this->value + other);
    }

    Short& operator=(const Short& other) {
        this->value = other.value;
        return *this;
    }

    Short& operator=(const Integer& other) {
        this->value = other.value;
        return *this;
    }

    Short& operator=(const int& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const long& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const long long& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const unsigned int& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const unsigned long& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const unsigned long long& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const char* other) {
        this->value = atoi(other);
        return *this;
    }

    Short& operator=(const float& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const double& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const char& other) {
        this->value = other;
        return *this;
    }

    Short& operator=(const bool& other) {
        this->value = other;
        return *this;
    }



    Short& operator+=(const Short& other) {
        this->value += other.value;
        return *this;
    }

    Short& operator+=(const Integer& other) {
        this->value += other.value;
        return *this;
    }

    Short& operator+=(const int& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const long& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const long long& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const unsigned int& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const unsigned long& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const unsigned long long& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const char* other) {
        this->value += atoi(other);
        return *this;
    }

    Short& operator+=(const float& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const double& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const char& other) {
        this->value += other;
        return *this;
    }

    Short& operator+=(const bool& other) {
        this->value += other;
        return *this;
    }



    Short& operator-=(const short& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const Short& other) {
        this->value -= other.value;
        return *this;
    }

    Short& operator-=(const Integer& other) {
        this->value -= other.value;
        return *this;
    }

    Short& operator-=(const int& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const long& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const long long& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const unsigned int& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const unsigned long& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const unsigned long long& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const char* other) {
        this->value -= atoi(other);
        return *this;
    }

    Short& operator-=(const float& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const double& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const char& other) {
        this->value -= other;
        return *this;
    }

    Short& operator-=(const bool& other) {
        this->value -= other;
        return *this;
    }

    

    Short& operator*=(const short& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const Short& other) {
        this->value *= other.value;
        return *this;
    }

    Short& operator*=(const Integer& other) {
        this->value *= other.value;
        return *this;
    }

    Short& operator*=(const int& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const long& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const long long& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const unsigned int& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const unsigned long& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const unsigned long long& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const char* other) {
        this->value *= atoi(other);
        return *this;
    }

    Short& operator*=(const float& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const double& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const char& other) {
        this->value *= other;
        return *this;
    }

    Short& operator*=(const bool& other) {
        this->value *= other;
        return *this;
    }



    Short& operator/=(const short& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const Short& other) {
        this->value /= other.value;
        return *this;
    }

    Short& operator/=(const Integer& other) {
        this->value /= other.value;
        return *this;
    }

    Short& operator/=(const int& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const long& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const long long& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const unsigned int& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const unsigned long& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const unsigned long long& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const char* other) {
        this->value /= atoi(other);
        return *this;
    }

    Short& operator/=(const float& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const double& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const char& other) {
        this->value /= other;
        return *this;
    }

    Short& operator/=(const bool& other) {
        this->value /= other;
        return *this;
    }



    Short& operator%=(const short& other) {
        this->value %= other;
        return *this;
    }

    Short operator+(const Short& other) const {
        return Short(this->value + other.value);
    }

    Short operator+(const Integer& other) const {
        return Short(this->value + other.value);
    }

    Short operator+(const int& other) const {
        return Short(this->value + other);
    }

    Short operator+(const long& other) const {
        return Short(this->value + other);
    }

    Short operator+(const long long& other) const {
        return Short(this->value + other);
    }

    Short operator+(const unsigned int& other) const {
        return Short(this->value + other);
    }

    Short operator+(const unsigned long& other) const {
        return Short(this->value + other);
    }

    Short operator+(const unsigned long long& other) const {
        return Short(this->value + other);
    }

    Short operator+(const char* other) const {
        return Short(this->value + atoi(other));
    }

    Short operator+(const float& other) const {
        return Short(this->value + other);
    }

    Short operator+(const double& other) const {
        return Short(this->value + other);
    }

    Short operator+(const char& other) const {
        return Short(this->value + other);
    }

    Short operator+(const bool& other) const {
        return Short(this->value + other);
    }



    Short operator-(const short& other) const {
        return Short(this->value - other);
    }

    Short operator-(const Short& other) const {
        return Short(this->value - other.value);
    }

    Short operator-(const Integer& other) const {
        return Short(this->value - other.value);
    }

    Short operator-(const int& other) const {
        return Short(this->value - other);
    }

    Short operator-(const long& other) const {
        return Short(this->value - other);
    }

    Short operator-(const long long& other) const {
        return Short(this->value - other);
    }

    Short operator-(const unsigned int& other) const {
        return Short(this->value - other);
    }

    Short operator-(const unsigned long& other) const {
        return Short(this->value - other);
    }

    Short operator-(const unsigned long long& other) const {
        return Short(this->value - other);
    }

    Short operator-(const char* other) const {
        return Short(this->value - atoi(other));
    }

    Short operator-(const float& other) const {
        return Short(this->value - other);
    }

    Short operator-(const double& other) const {
        return Short(this->value - other);
    }

    Short operator-(const char& other) const {
        return Short(this->value - other);
    }

    Short operator-(const bool& other) const {
        return Short(this->value - other);
    }



    Short operator*(const short& other) const {
        return Short(this->value * other);
    }

    Short operator*(const Short& other) const {
        return Short(this->value * other.value);
    }

    Short operator*(const Integer& other) const {
        return Short(this->value * other.value);
    }

    Short operator*(const int& other) const {
        return Short(this->value * other);
    }

    Short operator*(const long& other) const {
        return Short(this->value * other);
    }

    Short operator*(const long long& other) const {
        return Short(this->value * other);
    }

    Short operator*(const unsigned int& other) const {
        return Short(this->value * other);
    }

    Short operator*(const unsigned long& other) const {
        return Short(this->value * other);
    }

    Short operator*(const unsigned long long& other) const {
        return Short(this->value * other);
    }

    Short operator*(const char* other) const {
        return Short(this->value * atoi(other));
    }

    Short operator*(const float& other) const {
        return Short(this->value * other);
    }

    Short operator*(const double& other) const {
        return Short(this->value * other);
    }

    Short operator*(const char& other) const {
        return Short(this->value * other);
    }

    Short operator*(const bool& other) const {
        return Short(this->value * other);
    }



    Short operator/(const short& other) const {
        return Short(this->value);
    }

    Short operator/(const Short& other) const {
        return Short(this->value / other.value);
    }

    Short operator/(const Integer& other) const {
        return Short(this->value / other.value);
    }

    Short operator/(const int& other) const {
        return Short(this->value / other);
    }

    Short operator/(const long& other) const {
        return Short(this->value / other);
    }

    Short operator/(const long long& other) const {
        return Short(this->value / other);
    }

    Short operator/(const unsigned int& other) const {
        return Short(this->value / other);
    }

    Short operator/(const unsigned long& other) const {
        return Short(this->value / other);
    }

    Short operator/(const unsigned long long& other) const {
        return Short(this->value / other);
    }

    Short operator/(const char* other) const {
        return Short(this->value / atoi(other));
    }

    Short operator/(const float& other) const {
        return Short(this->value / other);
    }

    Short operator/(const double& other) const {
        return Short(this->value / other);
    }

    Short operator/(const char& other) const {
        return Short(this->value / other);
    }

    Short operator/(const bool& other) const {
        return Short(this->value / other);
    }



    Short operator%(const short& other) const {
        return Short(this->value % other);
    }

    Short operator%(const Short& other) const {
        return Short(this->value % other.value);
    }

    Short operator%(const Integer& other) const {
        return Short(this->value % other.value);
    }

    Short operator%(const int& other) const {
        return Short(this->value % other);
    }

    Short operator%(const long& other) const {
        return Short(this->value % other);
    }

    Short operator%(const long long& other) const {
        return Short(this->value % other);
    }

    Short operator%(const unsigned int& other) const {
        return Short(this->value % other);
    }

    Short operator%(const unsigned long& other) const {
        return Short(this->value % other);
    }

    Short operator%(const unsigned long long& other) const {
        return Short(this->value % other);
    }

    Short operator%(const char* other) const {
        return Short(this->value % atoi(other));
    }

    Short operator%(const char& other) const {
        return Short(this->value % other);
    }

    Short operator%(const bool& other) const {
        return Short(this->value % other);
    }




    Short operator&(const short& other) const {
        return Short(this->value & other);
    }

    Short operator&(const Short& other) const {
        return Short(this->value & other.value);
    }

    Short operator&(const Integer& other) const {
        return Short(this->value & other.value);
    }

    Short operator&(const int& other) const {
        return Short(this->value & other);
    }

    Short operator&(const long& other) const {
        return Short(this->value & other);
    }

    Short operator&(const long long& other) const {
        return Short(this->value & other);
    }

    Short operator&(const unsigned int& other) const {
        return Short(this->value & other);
    }

    Short operator&(const unsigned long& other) const {
        return Short(this->value & other);
    }

    Short operator&(const unsigned long long& other) const {
        return Short(this->value & other);
    }

    Short operator&(const char* other) const {
        return Short(this->value & atoi(other));
    }

    Short operator&(const char& other) const {
        return Short(this->value & other);
    }

    Short operator&(const bool& other) const {
        return Short(this->value & other);
    }



    Short operator|(const short& other) const {
        return Short(this->value | other);
    }

    Short operator|(const Short& other) const {
        return Short(this->value | other.value);
    }

    Short operator|(const Integer& other) const {
        return Short(this->value | other.value);
    }

    Short operator|(const int& other) const {
        return Short(this->value | other);
    }

    Short operator|(const long& other) const {
        return Short(this->value | other);
    }

    Short operator|(const long long& other) const {
        return Short(this->value | other);
    }

    Short operator|(const unsigned int& other) const {
        return Short(this->value | other);
    }

    Short operator|(const unsigned long& other) const {
        return Short(this->value | other);
    }

    Short operator|(const unsigned long long& other) const {
        return Short(this->value | other);
    }

    Short operator|(const char* other) const {
        return Short(this->value | atoi(other));
    }

    Short operator|(const char& other) const {
        return Short(this->value | other);
    }

    Short operator|(const bool& other) const {
        return Short(this->value | other);
    }



    Short operator^(const short& other) const {
        return Short(this->value ^ other);
    }

    Short operator^(const Short& other) const {
        return Short(this->value ^ other.value);
    }

    Short operator^(const Integer& other) const {
        return Short(this->value ^ other.value);
    }

    Short operator^(const int& other) const {
        return Short(this->value ^ other);
    }

    Short operator^(const long& other) const {
        return Short(this->value ^ other);
    }

    Short operator^(const long long& other) const {
        return Short(this->value ^ other);
    }

    Short operator^(const unsigned int& other) const {
        return Short(this->value ^ other);
    }

    Short operator^(const unsigned long& other) const {
        return Short(this->value ^ other);
    }
    
    Short operator^(const unsigned long long& other) const {
        return Short(this->value ^ other);
    }

    Short operator^(const char* other) const {
        return Short(this->value ^ atoi(other));
    }

    Short operator^(const char& other) const {
        return Short(this->value ^ other);
    }

    Short operator^(const bool& other) const {
        return Short(this->value ^ other);
    }



    Short operator<<(const short& other) const {
        return Short(this->value << other);
    }

    Short operator<<(const Short& other) const {
        return Short(this->value << other.value);
    }

    Short operator<<(const Integer& other) const {
        return Short(this->value << other.value);
    }

    Short operator<<(const int& other) const {
        return Short(this->value << other);
    }

    Short operator<<(const long& other) const {
        return Short(this->value << other);
    }

    Short operator<<(const long long& other) const {
        return Short(this->value << other);
    }

    Short operator<<(const unsigned int& other) const {
        return Short(this->value << other);
    }

    Short operator<<(const unsigned long& other) const {
        return Short(this->value << other);
    }

    Short operator<<(const unsigned long long& other) const {
        return Short(this->value << other);
    }

    Short operator<<(const char* other) const {
        return Short(this->value << atoi(other));
    }



    Short operator>>(const short& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const Short& other) const {
        return Short(this->value >> other.value);
    }

    Short operator>>(const Integer& other) const {
        return Short(this->value >> other.value);
    }

    Short operator>>(const int& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const long& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const long long& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const unsigned int& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const unsigned long& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const unsigned long long& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const char* other) const {
        return Short(this->value >> atoi(other));
    }

    Short operator>>(const char& other) const {
        return Short(this->value >> other);
    }

    Short operator>>(const bool& other) const {
        return Short(this->value >> other);
    }



    Short operator~() const {
        return Short(~this->value);
    }

    Short operator!() const {
        return Short(!this->value);
    }

    Short operator++() {
        this->value++;
        return *this;
    }

    Short operator++(int) {
        Short temp = *this;
        this->value++;
        return temp;
    }

    Short operator--() {
        this->value--;
        return *this;
    }

    Short operator--(int) {
        Short temp = *this;
        this->value--;
        return temp;
    }



    bool operator==(const Short& other) const {
        return this->value == other.value;
    }

    bool operator==(const int& other) const {
        return this->value == other;
    }

    bool operator==(const long& other) const {
        return this->value == other;
    }

    bool operator==(const long long& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned int& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long long& other) const {
        return this->value == other;
    }

    bool operator==(const char* other) const {
        return this->value == atoi(other);
    }

    bool operator==(const char& other) const {
        return this->value == other;
    }

    bool operator==(const bool& other) const {
        return this->value == other;
    }

    bool operator!=(const Short& other) const {
        return this->value != other.value;
    }

    bool operator!=(const int& other) const {
        return this->value != other;
    }

    bool operator!=(const long& other) const {
        return this->value != other;
    }

    bool operator!=(const long long& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned int& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long long& other) const {
        return this->value != other;
    }

    bool operator!=(const char* other) const {
        return this->value != atoi(other);
    }

    bool operator!=(const char& other) const {
        return this->value != other;
    }

    bool operator!=(const bool& other) const {
        return this->value != other;
    }

    bool operator<(const Short& other) const {
        return this->value < other.value;
    }

    bool operator<(const int& other) const {
        return this->value < other;
    }

    bool operator<(const long& other) const {
        return this->value < other;
    }

    bool operator<(const long long& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned int& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long long& other) const {
        return this->value < other;
    }

    bool operator<(const char* other) const {
        return this->value < atoi(other);
    }

    bool operator<(const char& other) const {
        return this->value < other;
    }

    bool operator<(const bool& other) const {
        return this->value < other;
    }

    bool operator>(const Short& other) const {
        return this->value > other.value;
    }

    bool operator>(const int& other) const {
        return this->value > other;
    }

    bool operator>(const long& other) const {
        return this->value > other;
    }

    bool operator>(const long long& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned int& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long long& other) const {
        return this->value > other;
    }

    bool operator>(const char* other) const {
        return this->value > atoi(other);
    }

    bool operator>(const char& other) const {
        return this->value > other;
    }

    bool operator>(const bool& other) const {
        return this->value > other;
    }

    bool operator<=(const Short& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const int& other) const {
        return this->value <= other;
    }

    bool operator<=(const long& other) const {
        return this->value <= other;
    }

    bool operator<=(const long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned int& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const char* other) const {
        return this->value <= atoi(other);
    }

    bool operator<=(const char& other) const {
        return this->value <= other;
    }

    bool operator<=(const bool& other) const {
        return this->value <= other;
    }

    bool operator>=(const Short& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const int& other) const {
        return this->value >= other;
    }

    bool operator>=(const long& other) const {
        return this->value >= other;
    }

    bool operator>=(const long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned int& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const char* other) const {
        return this->value >= atoi(other);
    }

    bool operator>=(const char& other) const {
        return this->value >= other;
    }

    bool operator>=(const bool& other) const {
        return this->value >= other;
    }

    
    friend std::ostream& operator<<(std::ostream& os, const Short& shrt) {
        os << shrt.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Short& shrt) {
        is >> shrt.value;
        return is;
    }
};

/**
 * @brief A float wrapper class
 * 
 */
class Float {
private:
    float value;
    friend class Integer;
    friend class Long;
    friend class Double;
    friend class Short;
public:
    Float() : value(0) {}

    Float(float value) : value(value) {}

    Float(const Integer& integer) : value(integer.value) {}

    Float(const long long& LL) : value(LL) {}

    Float(const long& L) : value(L) {}

    Float(const int& I) : value(I) {}

    Float(const short& S) : value(S) {}

    Float(const Short& SHORT) : value(SHORT.value) {}

    Float(const char* str) : value(atof(str)) {}

    Float(const double& double_) : value(double_) {}

    Float(const long double& long_double) : value(long_double) {}

    Float(const unsigned int& UI) : value(UI) {}

    Float(const unsigned long& UL) : value(UL) {}

    Float(const unsigned long long& ULL) : value(ULL) {}



    Float& operator=(const Float& other) {
        this->value = other.value;
        return *this;
    }

    Float& operator=(const float& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const Integer& other) {
        this->value = other.value;
        return *this;
    }

    Float& operator=(const long long& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const long& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const int& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const double& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const long double& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const unsigned int& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const unsigned long& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const unsigned long long& other) {
        this->value = other;
        return *this;
    }

    Float& operator=(const Short& other) {
        this->value = other.value;
        return *this;
    }

    Float& operator=(const char* other) {
        this->value = atof(other);
        return *this;
    }

    Float& operator=(const short& other) {
        this->value = other;
        return *this;
    }


    /**
     * @brief A method that converts a float to a string
     * 
     * @return auto 
     */
    auto toString() {
        return std::to_string(this->value);
    }

    /**
     * @brief A method that returns the type of the object
     * 
     * @return const char* 
     */
    const char* type() const {
        return "Float";
    }

    /**
     * @brief A method that converts a string into a float
     * 
     * @param str 
     * @return Float& 
     */
    Float& parseFloat(const char* str) {
        this->value = atof(str);
        return *this;
    }

    /**
     * @brief A method that returns the int value of the object
     * 
     * @param other 
     * @return Float& 
     */
    Float& intValue(const Integer& other) {
        this->value = other.value;
        return *this;
    }

    /**
     * @brief A method that returns the int value of the object
     * 
     * @param other 
     * @return Float& 
     */
    Float& intValue(const int& other) {
        this->value = other;
        return *this;
    }

    /**
     * @brief A method that returns the int value of the object
     * 
     * @param other 
     * @return Float& 
     */
    Float& intValue() {
        this->value = (int)this->value;
        return *this;
    }

    /**
     * @brief A method that returns the long value of the object
     * 
     * @param other 
     * @return Float& 
     */
    Float& longValue(const long long& other) {
        this->value = other;
        return *this;
    }

    /**
     * @brief A method that checks if a float is positive, negative or zero
     * 
     * @return Float 
     */
    Float signum() {
        if (this->value > 0) {
            return 1;
        }
        else if (this->value < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }

    /**
     * @brief A method that returns the negative value of the object
     * 
     * @return Float& 
     */
    Float& negate() {
        this->value = -this->value;
        return *this;
    }

    /**
     * @brief Absolute value of the object
     * 
     * @return Float& 
     */
    Float& abs() {
        if (this->value < 0) {
            this->value = -this->value;
        }
        return *this;
    }

    /**
     * @brief A method that returns the size of the string
     * 
     * @return size_t 
     */
    size_t length() {
        return std::to_string(this->value).length();
    }

    /**
     * @brief A method that returns the floor value of an object
     * 
     * @return long long 
     */
    long long floor() {
        long long result;
        if (this->value < 0) {
            result = (long long)this->value - 1;
            return result;
        }
        return this->value;
    }

    /**
     * @brief A method that returns the ceil value of an object
     * 
     * @return long long 
     */
    long long ceil() {
        if (this->value - (long long)this->value == 0) return this->value;
        return this->floor() + 1;
    }

    /**
     * @brief A method that returns the round value of an object
     * 
     * @return long long 
     */
    long long round() {
        if (this->value - (long long)this->value == 0) return this->value;
        double number = this->value - (long long)this->value;
        if (this->value < 0) {
            double negativeValue = this->value - (long long)this->value;
            long long result;
            if (negativeValue <= -0.5 && negativeValue > -1) result = this->floor();
            else if (negativeValue > -0.5 && negativeValue < 0) result = this->ceil();
            return result;
        }
        long long result;
        if (number >= 0.5 && number < 1) result = this->ceil();
        else if (number < 0.5 && number > 0) result = this->floor();
        return result;
    }

    /**
     * @brief A method that swaps two objects
     * 
     * @param other 
     * @return Float& 
     */
    Float& swap(Float& other) {
        Float temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    /**
     * @brief A method that swaps two objects
     * 
     * @param other 
     * @return Float& 
     */
    Float& swap(Integer& other) {
        Float temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    /**
     * @brief A method that swaps the value of two data types
     * 
     * @tparam T 
     * @param other 
     * @return Float& 
     */
    template<typename T>
    Float& swap(T& other) {
        Float temp;
        temp.value = this->value;
        this->value = other;
        other = temp.value;
        return *this;
    }

    operator float() {
        return value;
    }



    Float& operator+=(const Float& other) {
        this->value += other.value;
        return *this;
    }

    Float& operator+=(const float& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const Integer& other) {
        this->value += other.value;
        return *this;
    }

    Float& operator+=(const long long& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const long& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const int& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const double& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const long double& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const unsigned int& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const unsigned long& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const unsigned long long& other) {
        this->value += other;
        return *this;
    }

    Float& operator+=(const Short& other) {
        this->value += other.value;
        return *this;
    }

    Float& operator+=(const char* other) {
        this->value += atof(other);
        return *this;
    }

    Float& operator+=(const short& other) {
        this->value += other;
        return *this;
    }



    Float& operator-=(const Float& other) {
        this->value -= other.value;
        return *this;
    }

    Float& operator-=(const float& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const Integer& other) {
        this->value -= other.value;
        return *this;
    }

    Float& operator-=(const long long& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const long& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const int& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const double& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const long double& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const unsigned int& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const unsigned long& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const unsigned long long& other) {
        this->value -= other;
        return *this;
    }

    Float& operator-=(const Short& other) {
        this->value -= other.value;
        return *this;
    }

    Float& operator-=(const char* other) {
        this->value -= atof(other);
        return *this;
    }

    Float& operator-=(const short& other) {
        this->value -= other;
        return *this;
    }



    Float& operator*=(const Float& other) {
        this->value *= other.value;
        return *this;
    }

    Float& operator*=(const float& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const Integer& other) {
        this->value *= other.value;
        return *this;
    }

    Float& operator*=(const long long& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const long& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const int& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const double& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const long double& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const unsigned int& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const unsigned long& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const unsigned long long& other) {
        this->value *= other;
        return *this;
    }

    Float& operator*=(const Short& other) {
        this->value *= other.value;
        return *this;
    }

    Float& operator*=(const char* other) {
        this->value *= atof(other);
        return *this;
    }

    Float& operator*=(const short& other) {
        this->value *= other;
        return *this;
    }



    Float& operator/=(const Float& other) {
        this->value /= other.value;
        return *this;
    }

    Float& operator/=(const float& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const Integer& other) {
        this->value /= other.value;
        return *this;
    }

    Float& operator/=(const long long& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const long& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const int& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const double& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const long double& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const unsigned int& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const unsigned long& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const unsigned long long& other) {
        this->value /= other;
        return *this;
    }

    Float& operator/=(const Short& other) {
        this->value /= other.value;
        return *this;
    }

    Float& operator/=(const char* other) {
        this->value /= atof(other);
        return *this;
    }

    Float& operator/=(const short& other) {
        this->value /= other;
        return *this;
    }



    Float& operator++() {
        this->value++;
        return *this;
    }

    Float& operator--() {
        this->value--;
        return *this;
    }

    Float operator++(int) {
        Float temp = *this;
        this->value++;
        return temp;
    }

    Float operator--(int) {
        Float temp = *this;
        this->value--;
        return temp;
    }



    Float operator+(const Float& other) const {
        return Float(this->value + other.value);
    }

    Float operator+(const float& other) const {
        return Float(this->value + other);
    }

    Float operator+(const Integer& other) const {
        return Float(this->value + other.value);
    }

    Float operator+(const long long& other) const {
        return Float(this->value + other);
    }

    Float operator+(const long& other) const {
        return Float(this->value + other);
    }

    Float operator+(const int& other) const {
        return Float(this->value + other);
    }

    Float operator+(const double& other) const {
        return Float(this->value + other);
    }

    Float operator+(const long double& other) const {
        return Float(this->value + other);
    }

    Float operator+(const unsigned int& other) const {
        return Float(this->value + other);
    }

    Float operator+(const unsigned long& other) const {
        return Float(this->value + other);
    }

    Float operator+(const unsigned long long& other) const {
        return Float(this->value + other);
    }

    Float operator+(const Short& other) const {
        return Float(this->value + other.value);
    }

    Float operator+(const char* other) const {
        return Float(this->value + atof(other));
    }

    Float operator+(const short& other) const {
        return Float(this->value + other);
    }



    Float operator-(const Float& other) const {
        return Float(this->value - other.value);
    }

    Float operator-(const float& other) const {
        return Float(this->value - other);
    }

    Float operator-(const Integer& other) const {
        return Float(this->value - other.value);
    }

    Float operator-(const long long& other) const {
        return Float(this->value - other);
    }

    Float operator-(const long& other) const {
        return Float(this->value - other);
    }

    Float operator-(const int& other) const {
        return Float(this->value - other);
    }

    Float operator-(const double& other) const {
        return Float(this->value - other);
    }

    Float operator-(const long double& other) const {
        return Float(this->value - other);
    }

    Float operator-(const unsigned int& other) const {
        return Float(this->value - other);
    }

    Float operator-(const unsigned long& other) const {
        return Float(this->value - other);
    }

    Float operator-(const unsigned long long& other) const {
        return Float(this->value - other);
    }

    Float operator-(const Short& other) const {
        return Float(this->value - other.value);
    }

    Float operator-(const char* other) const {
        return Float(this->value - atof(other));
    }

    Float operator-(const short& other) const {
        return Float(this->value - other);
    }



    Float operator*(const Float& other) const {
        return Float(this->value * other.value);
    }

    Float operator*(const float& other) const {
        return Float(this->value * other);
    }

    Float operator*(const Integer& other) const {
        return Float(this->value * other.value);
    }

    Float operator*(const long long& other) const {
        return Float(this->value * other);
    }

    Float operator*(const long& other) const {
        return Float(this->value * other);
    }

    Float operator*(const int& other) const {
        return Float(this->value * other);
    }

    Float operator*(const double& other) const {
        return Float(this->value * other);
    }

    Float operator*(const long double& other) const {
        return Float(this->value * other);
    }

    Float operator*(const unsigned int& other) const {
        return Float(this->value * other);
    }

    Float operator*(const unsigned long& other) const {
        return Float(this->value * other);
    }

    Float operator*(const unsigned long long& other) const {
        return Float(this->value * other);
    }

    Float operator*(const Short& other) const {
        return Float(this->value * other.value);
    }

    Float operator*(const char* other) const {
        return Float(this->value * atof(other));
    }

    Float operator*(const short& other) const {
        return Float(this->value * other);
    }



    Float operator/(const Float& other) const {
        return Float(this->value / other.value);
    }

    Float operator/(const float& other) const {
        return Float(this->value / other);
    }

    Float operator/(const Integer& other) const {
        return Float(this->value / other.value);
    }

    Float operator/(const long long& other) const {
        return Float(this->value / other);
    }

    Float operator/(const long& other) const {
        return Float(this->value / other);
    }

    Float operator/(const int& other) const {
        return Float(this->value / other);
    }

    Float operator/(const double& other) const {
        return Float(this->value / other);
    }

    Float operator/(const long double& other) const {
        return Float(this->value / other);
    }

    Float operator/(const unsigned int& other) const {
        return Float(this->value / other);
    }

    Float operator/(const unsigned long& other) const {
        return Float(this->value / other);
    }

    Float operator/(const unsigned long long& other) const {
        return Float(this->value / other);
    }

    Float operator/(const Short& other) const {
        return Float(this->value / other.value);
    }

    Float operator/(const char* other) const {
        return Float(this->value / atof(other));
    }

    Float operator/(const short& other) const {
        return Float(this->value / other);
    }



    bool operator==(const Float& other) const {
        return this->value == other.value;
    }

    bool operator==(const float& other) const {
        return this->value == other;
    }

    bool operator==(const Integer& other) const {
        return this->value == other.value;
    }

    bool operator==(const long long& other) const {
        return this->value == other;
    }

    bool operator==(const long& other) const {
        return this->value == other;
    }

    bool operator==(const int& other) const {
        return this->value == other;
    }

    bool operator==(const double& other) const {
        return this->value == other;
    }

    bool operator==(const long double& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned int& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long long& other) const {
        return this->value == other;
    }

    bool operator==(const Short& other) const {
        return this->value == other.value;
    }

    bool operator==(const char* other) const {
        return this->value == atof(other);
    }

    bool operator==(const short& other) const {
        return this->value == other;
    }



    bool operator!=(const Float& other) const {
        return this->value != other.value;
    }

    bool operator!=(const float& other) const {
        return this->value != other;
    }

    bool operator!=(const Integer& other) const {
        return this->value != other.value;
    }

    bool operator!=(const long long& other) const {
        return this->value != other;
    }

    bool operator!=(const long& other) const {
        return this->value != other;
    }

    bool operator!=(const int& other) const {
        return this->value != other;
    }

    bool operator!=(const double& other) const {
        return this->value != other;
    }

    bool operator!=(const long double& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned int& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long long& other) const {
        return this->value != other;
    }



    bool operator<(const Float& other) const {
        return this->value < other.value;
    }

    bool operator<(const float& other) const {
        return this->value < other;
    }

    bool operator<(const Integer& other) const {
        return this->value < other.value;
    }

    bool operator<(const long long& other) const {
        return this->value < other;
    }

    bool operator<(const long& other) const {
        return this->value < other;
    }

    bool operator<(const int& other) const {
        return this->value < other;
    }

    bool operator<(const double& other) const {
        return this->value < other;
    }

    bool operator<(const long double& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned int& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long long& other) const {
        return this->value < other;
    }

    bool operator<(const Short& other) const {
        return this->value < other.value;
    }

    bool operator<(const char* other) const {
        return this->value < atof(other);
    }

    bool operator<(const short& other) const {
        return this->value < other;
    }



    bool operator>(const Float& other) const {
        return this->value > other.value;
    }

    bool operator>(const float& other) const {
        return this->value > other;
    }

    bool operator>(const Integer& other) const {
        return this->value > other.value;
    }

    bool operator>(const long long& other) const {
        return this->value > other;
    }

    bool operator>(const long& other) const {
        return this->value > other;
    }

    bool operator>(const int& other) const {
        return this->value > other;
    }

    bool operator>(const double& other) const {
        return this->value > other;
    }

    bool operator>(const long double& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned int& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long long& other) const {
        return this->value > other;
    }

    bool operator>(const Short& other) const {
        return this->value > other.value;
    }

    bool operator>(const char* other) const {
        return this->value > atof(other);
    }

    bool operator>(const short& other) const {
        return this->value > other;
    }



    bool operator<=(const Float& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const float& other) const {
        return this->value <= other;
    }

    bool operator<=(const Integer& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const long& other) const {
        return this->value <= other;
    }

    bool operator<=(const int& other) const {
        return this->value <= other;
    }

    bool operator<=(const double& other) const {
        return this->value <= other;
    }

    bool operator<=(const long double& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned int& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const Short& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const char* other) const {
        return this->value <= atof(other);
    }

    bool operator<=(const short& other) const {
        return this->value <= other;
    }



    bool operator>=(const Float& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const float& other) const {
        return this->value >= other;
    }

    bool operator>=(const Integer& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const long& other) const {
        return this->value >= other;
    }

    bool operator>=(const int& other) const {
        return this->value >= other;
    }

    bool operator>=(const double& other) const {
        return this->value >= other;
    }

    bool operator>=(const long double& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned int& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const Short& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const char* other) const {
        return this->value >= atof(other);
    }

    bool operator>=(const short& other) const {
        return this->value >= other;
    }



    bool operator!() const {
        return !this->value;
    }



    bool operator&&(const Float& other) const {
        return this->value && other.value;
    }

    bool operator&&(const float& other) const {
        return this->value && other;
    }

    bool operator&&(const Integer& other) const {
        return this->value && other.value;
    }

    bool operator&&(const long long& other) const {
        return this->value && other;
    }

    bool operator&&(const long& other) const {
        return this->value && other;
    }

    bool operator&&(const int& other) const {
        return this->value && other;
    }

    bool operator&&(const double& other) const {
        return this->value && other;
    }

    bool operator&&(const long double& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned int& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned long& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned long long& other) const {
        return this->value && other;
    }

    bool operator&&(const Short& other) const {
        return this->value && other.value;
    }

    bool operator&&(const char* other) const {
        return this->value && atof(other);
    }

    bool operator&&(const short& other) const {
        return this->value && other;
    }



    bool operator||(const Float& other) const {
        return this->value || other.value;
    }

    bool operator||(const float& other) const {
        return this->value || other;
    }

    bool operator||(const Integer& other) const {
        return this->value || other.value;
    }

    bool operator||(const long long& other) const {
        return this->value || other;
    }

    bool operator||(const long& other) const {
        return this->value || other;
    }

    bool operator||(const int& other) const {
        return this->value || other;
    }

    bool operator||(const double& other) const {
        return this->value || other;
    }

    bool operator||(const long double& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned int& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned long& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned long long& other) const {
        return this->value || other;
    }

    bool operator||(const Short& other) const {
        return this->value || other.value;
    }

    bool operator||(const char* other) const {
        return this->value || atof(other);
    }

    bool operator||(const short& other) const {
        return this->value || other;
    }


    friend std::ostream& operator<<(std::ostream& out, const Float& floatNum) {
        out << floatNum.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Float& floatNum) {
        in >> floatNum.value;
        return in;
    }
};

/**
 * @brief A double wrapper class.
 * 
 */
class Double {
private:
    double value;
    friend class Integer;
    friend class Long;
    friend class Float;
    friend class Short;
public:
    Double() : value(0) {}

    Double(double value) : value(value) {}

    Double(const Integer& integer) : value(integer.value) {}

    Double(const Float& floatNum) : value(floatNum.value) {}

    Double(const long long& longNum) : value(longNum) {}

    Double(const long& longNum) : value(longNum) {}

    Double(const int& intNum) : value(intNum) {}

    Double(const Double& other) : value(other.value) {}

    Double(const unsigned int& unsignedIntNum) : value(unsignedIntNum) {}

    Double(const long double& longDoubleNum) : value(longDoubleNum) {}

    Double(const unsigned long long& unsignedLongNum) : value(unsignedLongNum) {}

    Double(const unsigned long& unsignedLongNum) : value(unsignedLongNum) {}

    Double(const short& shortNum) : value(shortNum) {}

    Double(const char* string) : value(atof(string)) {}

    Double(const Short& shortNum) : value(shortNum.value) {}



    Double& operator=(const Double& other) {
        this->value = other.value;
        return *this;
    }

    Double& operator=(const Float& other) {
        this->value = other.value;
        return *this;
    }

    Double& operator=(const Integer& other) {
        this->value = other.value;
        return *this;
    }

    Double& operator=(const long long& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const long& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const double& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const int& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const unsigned long long& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const unsigned long& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const unsigned int& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const long double& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const short& other) {
        this->value = other;
        return *this;
    }

    Double& operator=(const char* other) {
        this->value = atof(other);
        return *this;
    }

    Double& operator=(const Short& other) {
        this->value = other.value;
        return *this;
    }


    /**
     * @brief A method that converts a double into a string.
     * 
     * @return auto 
     */
    auto toString() const {
        return std::to_string(this->value);
    }

    /**
     * @brief A method that returns the negative value of the double.
     * 
     * @return Double& 
     */
    Double& negate() {
        this->value = -this->value;
        return *this;
    }

    /**
     * @brief Absolute value of the double.
     * 
     * @return Double& 
     */
    Double& abs() {
        if (this->value < 0) {
            this->value = -this->value;
        }
        return *this;
    }

    /**
     * @brief The int value of the object
     * 
     * @return Double& 
     */
    Double& intValue() {
        this->value = (int)this->value;
        return *this;
    }

    /**
     * @brief The long value of the object
     * 
     * @return Double& 
     */
    Double& longValue() {
        this->value = (long long)this->value;
        return *this;
    }

    /**
     * @brief A method that returns the floor value of the double.
     * 
     * @return long long 
     */
    long long floor() {
        long long result;
        if (this->value < 0) {
            result = (long long)this->value - 1;
            return result;
        }
        return this->value;
    }

    /**
     * @brief A method that returns the ceil of the double
     * 
     * @return long long 
     */
    long long ceil() {
        if (this->value - (long long)this->value == 0) return this->value;
        return this->floor() + 1;
    }

    /**
     * @brief A method that returns the round of the double
     * 
     * @return long long 
     */
    long long round() {
        if (this->value - (long long)this->value == 0) return this->value;
        double number = this->value - (long long)this->value;
        if (this->value < 0) {
            double negativeValue = this->value - (long long)this->value;
            long long result;
            if (negativeValue <= -0.5 && negativeValue > -1) result = this->floor();
            else if (negativeValue > -0.5 && negativeValue < 0) result = this->ceil();
            return result;
        }
        long long result;
        if (number >= 0.5 && number < 1) result = this->ceil();
        else if (number < 0.5 && number > 0) result = this->floor();
        return result;
    }

    /**
     * @brief A method that checks if the double is positive, negative or zero.
     * 
     * @return Double& 
     */
    Double& signum() {
        if (this->value < 0) {
            this->value = -1;
        }
        else if (this->value > 0) {
            this->value = 1;
        }
        else {
            this->value = 0;
        }
        return *this;
    }

    /**
     * @brief A method that returns the type of the object
     * 
     * @return const char* 
     */
    const char* type() const {
        return "Double";
    }

    /**
     * @brief A method that converts a string into a double
     * 
     * @param string 
     * @return Double& 
     */
    Double& parseDouble(const char* string) {
        this->value = std::stod(string);
        return *this;
    }

    /**
     * @brief A method that swaps the value of the double with Integer.
     * 
     * @param other 
     * @return Double& 
     */
    Double& swap(Integer& other) {
        Double temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    /**
     * @brief A method that swaps the value of the double with a Float
     * 
     * @param other 
     * @return Double& 
     */
    Double& swap(Float& other) {
        Double temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    /**
     * @brief A method that swaps the value of the double with another double
     * 
     * @param other 
     * @return Double& 
     */
    Double& swap(Double& other) {
        Double temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    /**
     * @brief A method that swaps the value of the double with another data type
     * 
     * @tparam T 
     * @param other 
     * @return Double& 
     */
    template<typename T>
    Double& swap(T& other) {
        Double temp;
        temp.value = this->value;
        this->value = other;
        other = temp.value;
        return *this;
    }

    operator double() {
        return value;
    }



    Double& operator+=(const Double& other) {
        this->value += other.value;
        return *this;
    }

    Double& operator+=(const Float& other) {
        this->value += other.value;
        return *this;
    }

    Double& operator+=(const Integer& other) {
        this->value += other.value;
        return *this;
    }

    Double& operator+=(const long long& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const long& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const double& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const int& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const unsigned long long& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const unsigned long& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const unsigned int& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const long double& other) {
        this->value += other;
        return *this;
    }

    Double& operator+=(const char* other) {
        this->value += atof(other);
        return *this;
    }

    Double& operator+=(const Short& other) {
        this->value += other.value;
        return *this;
    }

    Double& operator+=(const short& other) {
        this->value += other;
        return *this;
    }



    Double& operator-=(const Double& other) {
        this->value -= other.value;
        return *this;
    }

    Double& operator-=(const Float& other) {
        this->value -= other.value;
        return *this;
    }

    Double& operator-=(const Integer& other) {
        this->value -= other.value;
        return *this;
    }

    Double& operator-=(const long long& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const long& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const double& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const int& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const unsigned long long& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const unsigned long& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const unsigned int& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const long double& other) {
        this->value -= other;
        return *this;
    }

    Double& operator-=(const char* other) {
        this->value -= atof(other);
        return *this;
    }

    Double& operator-=(const Short& other) {
        this->value -= other.value;
        return *this;
    }

    Double& operator-=(const short& other) {
        this->value -= other;
        return *this;
    }



    Double& operator*=(const Double& other) {
        this->value *= other.value;
        return *this;
    }

    Double& operator*=(const Float& other) {
        this->value *= other.value;
        return *this;
    }

    Double& operator*=(const Integer& other) {
        this->value *= other.value;
        return *this;
    }

    Double& operator*=(const long long& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const long& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const double& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const int& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const unsigned long long& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const unsigned long& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const unsigned int& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const long double& other) {
        this->value *= other;
        return *this;
    }

    Double& operator*=(const char* other) {
        this->value *= atof(other);
        return *this;
    }

    Double& operator*=(const Short& other) {
        this->value *= other.value;
        return *this;
    }

    Double& operator*=(const short& other) {
        this->value *= other;
        return *this;
    }



    Double& operator/=(const Double& other) {
        this->value /= other.value;
        return *this;
    }

    Double& operator/=(const Float& other) {
        this->value /= other.value;
        return *this;
    }

    Double& operator/=(const Integer& other) {
        this->value /= other.value;
        return *this;
    }

    Double& operator/=(const long long& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const long& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const double& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const int& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const unsigned long long& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const unsigned long& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const unsigned int& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const long double& other) {
        this->value /= other;
        return *this;
    }

    Double& operator/=(const char* other) {
        this->value /= atof(other);
        return *this;
    }

    Double& operator/=(const Short& other) {
        this->value /= other.value;
        return *this;
    }

    Double& operator/=(const short& other) {
        this->value /= other;
        return *this;
    }



    Double& operator++() {
        this->value++;
        return *this;
    }

    Double& operator--() {
        this->value--;
        return *this;
    }

    Double operator++(int) {
        Double temp = *this;
        this->value++;
        return temp;
    }

    Double operator--(int) {
        Double temp = *this;
        this->value--;
        return temp;
    }



    Double operator+(const Double& other) const {
        return Double(this->value + other.value);
    }

    Double operator+(const Float& other) const {
        return Double(this->value + other.value);
    }

    Double operator+(const Integer& other) const {
        return Double(this->value + other.value);
    }

    Double operator+(const long long& other) const {
        return Double(this->value + other);
    }

    Double operator+(const long& other) const {
        return Double(this->value + other);
    }

    Double operator+(const double& other) const {
        return Double(this->value + other);
    }

    Double operator+(const int& other) const {
        return Double(this->value + other);
    }

    Double operator+(const unsigned long long& other) const {
        return Double(this->value + other);
    }

    Double operator+(const unsigned long& other) const {
        return Double(this->value + other);
    }

    Double operator+(const unsigned int& other) const {
        return Double(this->value + other);
    }

    Double operator+(const long double& other) const {
        return Double(this->value + other);
    }

    Double operator+(const char* other) const {
        return Double(this->value + atof(other));
    }

    Double operator+(const Short& other) const {
        return Double(this->value + other.value);
    }

    Double operator+(const short& other) const {
        return Double(this->value + other);
    }



    Double operator-(const Double& other) const {
        return Double(this->value - other.value);
    }

    Double operator-(const Float& other) const {
        return Double(this->value - other.value);
    }

    Double operator-(const Integer& other) const {
        return Double(this->value - other.value);
    }

    Double operator-(const long long& other) const {
        return Double(this->value - other);
    }

    Double operator-(const long& other) const {
        return Double(this->value - other);
    }

    Double operator-(const double& other) const {
        return Double(this->value - other);
    }

    Double operator-(const int& other) const {
        return Double(this->value - other);
    }

    Double operator-(const unsigned long long& other) const {
        return Double(this->value - other);
    }

    Double operator-(const unsigned long& other) const {
        return Double(this->value - other);
    }

    Double operator-(const unsigned int& other) const {
        return Double(this->value - other);
    }

    Double operator-(const long double& other) const {
        return Double(this->value - other);
    }

    Double operator-(const char* other) const {
        return Double(this->value - atof(other));
    }

    Double operator-(const Short& other) const {
        return Double(this->value - other.value);
    }

    Double operator-(const short& other) const {
        return Double(this->value - other);
    }



    Double operator*(const Double& other) const {
        return Double(this->value * other.value);
    }

    Double operator*(const Float& other) const {
        return Double(this->value * other.value);
    }

    Double operator*(const Integer& other) const {
        return Double(this->value * other.value);
    }

    Double operator*(const long long& other) const {
        return Double(this->value * other);
    }

    Double operator*(const long& other) const {
        return Double(this->value * other);
    }

    Double operator*(const double& other) const {
        return Double(this->value * other);
    }

    Double operator*(const int& other) const {
        return Double(this->value * other);
    }

    Double operator*(const unsigned long long& other) const {
        return Double(this->value * other);
    }

    Double operator*(const unsigned long& other) const {
        return Double(this->value * other);
    }

    Double operator*(const unsigned int& other) const {
        return Double(this->value * other);
    }

    Double operator*(const long double& other) const {
        return Double(this->value * other);
    }

    Double operator*(const char* other) const {
        return Double(this->value * atof(other));
    }

    Double operator*(const Short& other) const {
        return Double(this->value * other.value);
    }

    Double operator*(const short& other) const {
        return Double(this->value * other);
    }



    Double operator/(const Double& other) const {
        return Double(this->value / other.value);
    }

    Double operator/(const Float& other) const {
        return Double(this->value / other.value);
    }

    Double operator/(const Integer& other) const {
        return Double(this->value / other.value);
    }

    Double operator/(const long long& other) const {
        return Double(this->value / other);
    }

    Double operator/(const long& other) const {
        return Double(this->value / other);
    }

    Double operator/(const double& other) const {
        return Double(this->value / other);
    }

    Double operator/(const int& other) const {
        return Double(this->value / other);
    }

    Double operator/(const unsigned long long& other) const {
        return Double(this->value / other);
    }

    Double operator/(const unsigned long& other) const {
        return Double(this->value / other);
    }

    Double operator/(const unsigned int& other) const {
        return Double(this->value / other);
    }

    Double operator/(const long double& other) const {
        return Double(this->value / other);
    }

    Double operator/(const char* other) const {
        return Double(this->value / atof(other));
    }

    Double operator/(const Short& other) const {
        return Double(this->value / other.value);
    }

    Double operator/(const short& other) const {
        return Double(this->value / other);
    }



    bool operator==(const Double& other) const {
        return this->value == other.value;
    }

    bool operator==(const Float& other) const {
        return this->value == other.value;
    }

    bool operator==(const Integer& other) const {
        return this->value == other.value;
    }

    bool operator==(const long long& other) const {
        return this->value == other;
    }

    bool operator==(const long& other) const {
        return this->value == other;
    }

    bool operator==(const double& other) const {
        return this->value == other;
    }

    bool operator==(const int& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long long& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned long& other) const {
        return this->value == other;
    }

    bool operator==(const unsigned int& other) const {
        return this->value == other;
    }

    bool operator==(const bool& other) const {
        return this->value == other;
    }

    bool operator==(const long double& other) const {
        return this->value == other;
    }

    bool operator==(const char* other) const {
        return this->value == atof(other);
    }

    bool operator==(const Short& other) const {
        return this->value == other.value;
    }

    bool operator==(const short& other) const {
        return this->value == other;
    }



    bool operator!=(const Double& other) const {
        return this->value != other.value;
    }

    bool operator!=(const Float& other) const {
        return this->value != other.value;
    }

    bool operator!=(const Integer& other) const {
        return this->value != other.value;
    }

    bool operator!=(const long long& other) const {
        return this->value != other;
    }

    bool operator!=(const long& other) const {
        return this->value != other;
    }

    bool operator!=(const double& other) const {
        return this->value != other;
    }

    bool operator!=(const int& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long long& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned long& other) const {
        return this->value != other;
    }

    bool operator!=(const unsigned int& other) const {
        return this->value != other;
    }

    bool operator!=(const bool& other) const {
        return this->value != other;
    }

    bool operator!=(const long double& other) const {
        return this->value != other;
    }

    bool operator!=(const char* other) const {
        return this->value != atof(other);
    }

    bool operator!=(const Short& other) const {
        return this->value != other.value;
    }

    bool operator!=(const short& other) const {
        return this->value != other;
    }



    bool operator<(const Double& other) const {
        return this->value < other.value;
    }

    bool operator<(const Float& other) const {
        return this->value < other.value;
    }

    bool operator<(const Integer& other) const {
        return this->value < other.value;
    }

    bool operator<(const long long& other) const {
        return this->value < other;
    }

    bool operator<(const long& other) const {
        return this->value < other;
    }

    bool operator<(const double& other) const {
        return this->value < other;
    }

    bool operator<(const int& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long long& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned long& other) const {
        return this->value < other;
    }

    bool operator<(const unsigned int& other) const {
        return this->value < other;
    }

    bool operator<(const long double& other) const {
        return this->value < other;
    }

    bool operator<(const char* other) const {
        return this->value < atof(other);
    }

    bool operator<(const Short& other) const {
        return this->value < other.value;
    }

    bool operator<(const short& other) const {
        return this->value < other;
    }



    bool operator>(const Double& other) const {
        return this->value > other.value;
    }

    bool operator>(const Float& other) const {
        return this->value > other.value;
    }

    bool operator>(const Integer& other) const {
        return this->value > other.value;
    }

    bool operator>(const long long& other) const {
        return this->value > other;
    }

    bool operator>(const long& other) const {
        return this->value > other;
    }

    bool operator>(const double& other) const {
        return this->value > other;
    }

    bool operator>(const int& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long long& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned long& other) const {
        return this->value > other;
    }

    bool operator>(const unsigned int& other) const {
        return this->value > other;
    }

    bool operator>(const long double& other) const {
        return this->value > other;
    }

    bool operator>(const char* other) const {
        return this->value > atof(other);
    }

    bool operator>(const Short& other) const {
        return this->value > other.value;
    }

    bool operator>(const short& other) const {
        return this->value > other;
    }



    bool operator<=(const Double& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const Float& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const Integer& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const long& other) const {
        return this->value <= other;
    }

    bool operator<=(const double& other) const {
        return this->value <= other;
    }

    bool operator<=(const int& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long long& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned long& other) const {
        return this->value <= other;
    }

    bool operator<=(const unsigned int& other) const {
        return this->value <= other;
    }

    bool operator<=(const long double& other) const {
        return this->value <= other;
    }

    bool operator<=(const char* other) const {
        return this->value <= atof(other);
    }

    bool operator<=(const Short& other) const {
        return this->value <= other.value;
    }

    bool operator<=(const short& other) const {
        return this->value <= other;
    }



    bool operator>=(const Double& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const Float& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const Integer& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const long& other) const {
        return this->value >= other;
    }

    bool operator>=(const double& other) const {
        return this->value >= other;
    }

    bool operator>=(const int& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long long& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned long& other) const {
        return this->value >= other;
    }

    bool operator>=(const unsigned int& other) const {
        return this->value >= other;
    }

    bool operator>=(const long double& other) const {
        return this->value >= other;
    }

    bool operator>=(const char* other) const {
        return this->value >= atof(other);
    }

    bool operator>=(const Short& other) const {
        return this->value >= other.value;
    }

    bool operator>=(const short& other) const {
        return this->value >= other;
    }



    bool operator!() const {
        return !this->value;
    }

    bool operator&&(const Double& other) const {
        return this->value && other.value;
    }

    bool operator&&(const Float& other) const {
        return this->value && other.value;
    }

    bool operator&&(const Integer& other) const {
        return this->value && other.value;
    }

    bool operator&&(const long long& other) const {
        return this->value && other;
    }

    bool operator&&(const long& other) const {
        return this->value && other;
    }

    bool operator&&(const double& other) const {
        return this->value && other;
    }

    bool operator&&(const int& other) const {
        return this->value && other;
    }

    bool operator&&(const bool& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned int& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned long& other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned long long& other) const {
        return this->value && other;
    }

    bool operator&&(const char& other) const {
        return this->value && other;
    }

    bool operator&&(const char* other) const {
        return this->value && other;
    }

    bool operator&&(const unsigned char& other) const {
        return this->value && other;
    }

    bool operator&&(const long double& other) const {
        return this->value && other;
    }

    bool operator&&(const Short& other) const {
        return this->value && other.value;
    }

    bool operator&&(const short& other) const {
        return this->value && other;
    }



    bool operator||(const Double& other) const {
        return this->value || other.value;
    }

    bool operator||(const Float& other) const {
        return this->value || other.value;
    }

    bool operator||(const Integer& other) const {
        return this->value || other.value;
    }

    bool operator||(const long long& other) const {
        return this->value || other;
    }

    bool operator||(const long& other) const {
        return this->value || other;
    }

    bool operator||(const double& other) const {
        return this->value || other;
    }

    bool operator||(const int& other) const {
        return this->value || other;
    }

    bool operator||(const bool& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned long long& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned long& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned int& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned short& other) const {
        return this->value || other;
    }

    bool operator||(const unsigned char& other) const {
        return this->value || other;
    }

    bool operator||(const char& other) const {
        return this->value || other;
    }

    bool operator||(const char* other) const {
        return this->value || other;
    }

    bool operator||(const long double& other) const {
        return this->value || other;
    }

    bool operator||(const Short& other) const {
        return this->value || other.value;
    }

    bool operator||(const short& other) const {
        return this->value || other;
    }



    friend std::ostream& operator<<(std::ostream& out, const Double& floatNum) {
        out << floatNum.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Double& floatNum) {
        in >> floatNum.value;
        return in;
    }

};

/**
 * @brief A wrapper boolean class
 * 
 */
class Boolean {
private:
    bool value;
public:
    Boolean() : value(false) {}

    Boolean(const bool& value) : value(value) {}

    Boolean(const int& value) : value(value) {}

    Boolean(const Boolean& other) : value(other.value) {}

    Boolean(const std::string& value) {
        if (value != "false") {
            this->value = true;
        }
        else if (value == "false") {
            this->value = false;
        }
        else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }



    operator bool() {
        return this->value;
    }

    /**
     * @brief Set the Value object
     * 
     * @param value 
     */
    void setValue(bool value) {
        this->value = value;
    }

    /**
     * @brief Get the Value object
     * 
     * @return true 
     * @return false 
     */
    bool getValue() const {
        return this->value;
    }

    /**
     * @brief A method that returns the type of the object
     * 
     * @return const char* 
     */
    const char* type() {
        return "Boolean";
    }



    Boolean& operator=(const bool& other) {
        this->value = other;
        return *this;
    }

    Boolean& operator=(const Boolean& other) {
        this->value = other.value;
        return *this;
    }

    Boolean& operator=(const std::string& value) {
        if (value == "true") {
            this->value = true;
            return *this;
        }
        this->value = false;
        return *this;
    }

    Boolean& operator=(const char* value) {
        if (value != "false") {
            this->value = true;
            return *this;
        }
        this->value = false;
        return *this;
    }

    Boolean& operator=(const char& value) {
        if (value == 'f' || value == '0') {
            this->value = false;
            return *this;
        }
        this->value = true;
        return *this;
    }

    Boolean& operator=(const int& other) {
        if (other != 0) {
            this->value = true;
            return *this;
        }
        this->value = false;
        return *this;
    }


    operator bool() const {
        return this->value;
    }



    bool operator==(const bool& other) const {
        return this->value == other;
    }

    bool operator==(const Boolean& other) const {
        return this->value == other.value;
    }

    bool operator==(const std::string& other) const {
        if (other == "true" || other == "1") {
            return this->value == true;
        }
        else if (other == "false" || other == "0") {
            return this->value == false;
        }
        else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator==(const char* other) const {
        if (other != "false" || other != "0") {
            return this->value == true;
        }
        return this->value == false;
    }

    bool operator==(const char& other) const {
        if (other == 'f' || other == '0') {
            return this->value == false;
        }
        return this->value == true;
    }

    template<typename type>
    bool operator==(const type& other) const {
        if (other != "false" || other != "0" || other != '0' || other != 'f' || other != 0) {
            return this->value == true;
        }
        return this->value == false;
    }


    bool operator!=(const bool& other) const {
        return this->value != other;
    }

    bool operator!=(const Boolean& other) const {
        return this->value != other.value;
    }

    bool operator!=(const std::string& other) const {
        if (other == "true" || other == "1") {
            return this->value != true;
        }
        else if (other == "false" || other == "0") {
            return this->value != false;
        }
        else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator!=(const char* other) const {
        if (other != "false" || other != "0") {
            return this->value != true;
        }
        return this->value != false;
    }

    bool operator!=(const char& other) const {
        if (other == 'f' || other == '0') {
            return this->value != false;
        }
        return this->value != true;
    }

    bool operator!=(const long double& other) const {
        if (other != 0) {
            return this->value != true;
        }
        return this->value != false;
    }

    bool operator!() const {
        return !this->value;
    }

    bool operator&&(const bool& other) const {
        return this->value && other;
    }

    bool operator&&(const Boolean& other) const {
        return this->value && other.value;
    }

    bool operator&&(const std::string& other) const {
        if (other == "true" || other == "1") {
            return this->value && true;
        }
        else if (other == "false" || other == "0") {
            return this->value && false;
        }
        else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator&&(const char* other) const {
        if (other != "false" || other != "0") {
            return this->value && true;
        }
        return this->value && false;
    }

    bool operator&&(const char& other) const {
        if (other == 'f' || other == '0') {
            return this->value && false;
        }
        return this->value && true;
    }

    bool operator&&(const long double& other) const {
        if (other != 0) {
            return this->value && true;
        }
        return this->value && false;
    }

    bool operator&&(const int& other) const {
        if (other != 0) {
            return this->value && true;
        }
        return this->value && false;
    }



    bool operator||(const bool& other) const {
        return this->value || other;
    }

    bool operator||(const Boolean& other) const {
        return this->value || other.value;
    }

    bool operator||(const std::string& other) const {
        if (other == "true" || other == "1") {
            return this->value || true;
        }
        else if (other == "false" || other == "0") {
            return this->value || false;
        }
        else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator||(const char* other) const {
        if (other != "false" || other != "0") {
            return this->value || true;
        }
        return this->value || false;
    }

    bool operator||(const char& other) const {
        if (other == 'f' || other == '0') {
            return this->value || false;
        }
        return this->value || true;
    }

    bool operator||(const long double& other) const {
        if (other != 0) {
            return this->value || true;
        }
        return this->value || false;
    }



    friend std::ostream& operator<<(std::ostream& out, const Boolean& boolean) {
        if (boolean.value == true) {
            out << true;
            return out;
        }
        out << false;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Boolean& boolean) {
        in >> boolean.value;
        return in;
    }
};


/**
 * @brief A wrapper char class
 * @author Omar Estietie
 * 
 */
class Character {
private:
    char value;
public:
    Character() : value('\0') {}

    Character(const int& other) : value(other) {}

    Character(const char& value) : value(value) {} 

    Character(const Character& other) : value(other.value) {}



    Character& operator=(const int& other) {
        this->value = other;
        return *this;
    }

    Character& operator=(const char& other) {
        this->value = other;
        return *this;
    }

    Character& operator=(const Character& other) {
        this->value = other.value;
        return *this;
    }


    /**
     * @brief A method that makes a character in a upper case
     * 
     * @return Character& 
     */
    Character& toUpper() {
        this->value = toupper(this->value);
        return *this;
    }

    /**
     * @brief A method that makes a character in a lower case
     * 
     * @return Character& 
     */
    Character& toLower() {
        this->value = tolower(this->value);
        return *this;
    }

    /**
     * @brief A method that checks if a character is an alphabet
     * 
     * @return Character& 
     */
    Character& isAlphabet() {
        if (isalpha(this->value)) {
            return *this;
        }
        throw std::invalid_argument("Invalid alphabet");
    }

    /**
     * @brief A method that checks if a character is a digit
     * 
     * @return Character& 
     */
    Character& isDigit() {
        if (isdigit(this->value)) {
            return *this;
        }
        throw std::invalid_argument("Invalid digit");
    }

    /**
     * @brief A method that checks if a character is alphanumeric
     * 
     * @return Character& 
     */
    Character& isAlphanumeric() {
        if (isalnum(this->value)) {
            return *this;
        }
        throw std::invalid_argument("Invalid alphanumeric");
    }

    /**
     * @brief A method that checks if a character is a space
     * 
     * @return Character& 
     */
    Character& isSpace() {
        if (isspace(this->value)) {
            return *this;
        }
        throw std::invalid_argument("Invalid space");
    }

    /**
     * @brief A method that checks if a character is a punctuation
     * 
     * @return Character& 
     */
    Character& isPunctuation() {
        if (ispunct(this->value)) {
            return *this;
        }
        throw std::invalid_argument("Invalid punctuation");
    }

    /**
     * @brief A method that checks if a character is printable
     * 
     * @return Character& 
     */
    Character& isPrintable() {
        if (isprint(this->value)) {
            return *this;
        }
        throw std::invalid_argument("Invalid printable");
    }

    /**
     * @brief A method that checks if a character is a blank
     * 
     * @return Character& 
     */
    Character& isBlank() {
        if (isblank(this->value)) {
            return *this;
        }
        throw std::invalid_argument("Invalid blank");
    }

    /**
     * @brief A method that returns a string of the character
     * 
     * @return Character& 
     */
    const char* toString() const {
        return &this->value;
    }

    /**
     * @brief A method that clears the character
     * 
     * @return Character& 
     */
    Character& clear() {
        this->value = '\0';
        return *this;
    }

    /**
     * @brief A method that sets the character to a new value
     * 
     * @param other 
     */
    void set(const int& other) {
        this->value = other;
    }

    /**
     * @brief A method that sets the character to a new value
     * 
     * @param other 
     */
    void set(const char& other) {
        this->value = other;
    }

    /**
     * @brief A method that sets the character to a new value
     * 
     * @param other 
     */
    void set(const Character& other) {
        this->value = other.value;
    }

    /**
     * @brief A method that returns the character
     * 
     * @return Character 
     */
    Character get() const {
        return this->value;
    }

    /**
     * @brief A method that makes a character empty
     * 
     * @return Character 
     */
    Character& empty() {
        this->value = '\0';
        return *this;
    }

    /**
     * @brief A method that checks if a character is empty
     * 
     * @return bool 
     */
    bool isEmpty() const {
        if(this->value == '\0') {
            return true;
        }
        return false;
    }
    
    /**
     * @brief A method that checks if a character is equal to another
     * 
     * @param other 
     * @return bool 
     */
    bool isSameChar(const char& other) const {
        if (this->value == other) {
            return true;
        }
        return false;
    }

    /**
     * @brief A method that checks if a character is equal to another
     * 
     * @param other 
     * @return bool
     */
    bool isSameChar(const Character& other) const {
        if (this->value == other.value) {
            return true;
        }
        return false;
    }

    /**
     * @brief A method that returns the type of the data type
     * 
     * @return const char* 
     */
    const char* type() const {
        return "Character";
    }
    
    /**
     * @brief A method that checks if 2 characters are equal regardless of case
     * 
     * @param other 
     * @return bool
     */
    bool equalsIgnoreCase(const Character& other) const {
        if (toupper(this->value) == toupper(other.value)) {
            return true;
        }
        return false;
    }

    /**
     * @brief A method that checks if 2 characters are equal regardless of case
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool equalsIgnoreCase(const char& other) const {
        if (toupper(this->value) == toupper(other)) {
            return true;
        }
        return false;
    }

    /**
     * @brief A method that checks if 2 characters are equal regardless of case
     * 
     * @param other 
     * @return bool
     */
    bool equalsIgnoreCase(const int& other) const {
        if (toupper(this->value) == toupper(other)) {
            return true;
        }
        return false;
    }

    /**
     * @brief A method that converts a character to short
     * 
     * @return int 
     */
    int toInt() const {
        return this->value;
    }
    
    /**
     * @brief A method that converts a character to short 
     * 
     * @return short 
     */
    short toShort() const {
        return this->value;
    }

    operator char() const {
        return this->value;
    }



    Character& operator+=(const int& other) {
        this->value += other;
        return *this;
    }

    Character& operator+=(const char& other) {
        this->value += other;
        return *this;
    }

    Character& operator+=(const Character& other) {
        this->value += other.value;
        return *this;
    }



    Character& operator-=(const int& other) {
        this->value -= other;
        return *this;
    }

    Character& operator-=(const char& other) {
        this->value -= other;
        return *this;
    }

    Character& operator-=(const Character& other) {
        this->value -= other.value;
        return *this;
    }



    Character& operator*=(const int& other) {
        this->value *= other;
        return *this;
    }

    Character& operator*=(const char& other) {
        this->value *= other;
        return *this;
    }

    Character& operator*=(const Character& other) {
        this->value *= other.value;
        return *this;
    }



    Character& operator/=(const int& other) {
        this->value /= other;
        return *this;
    }

    Character& operator/=(const char& other) {
        this->value /= other;
        return *this;
    }

    Character& operator/=(const Character& other) {
        this->value /= other.value;
        return *this;
    }



    Character& operator%=(const int& other) {
        this->value %= other;
        return *this;
    }

    Character& operator%=(const char& other) {
        this->value %= other;
        return *this;
    }

    Character& operator%=(const Character& other) {
        this->value %= other.value;
        return *this;
    }



    Character& operator++() {
        this->value++;
        return *this;
    }

    Character& operator--() {
        this->value--;
        return *this;
    }

    Character operator++(int) {
        Character temp = *this;
        this->value++;
        return temp;
    }

    Character operator--(int) {
        Character temp = *this;
        this->value--;
        return temp;
    }
    


    Character operator+(const int& other) const {
        return this->value + other;
    }

    Character operator+(const char& other) const {
        return this->value + other;
    }

    Character operator+(const Character& other) const {
        return this->value + other.value;
    }



    Character operator-(const int& other) const {
        return this->value - other;
    }

    Character operator-(const char& other) const {
        return this->value - other;
    }

    Character operator-(const Character& other) const {
        return this->value - other.value;
    }



    Character operator*(const int& other) const {
        return this->value * other;
    }

    Character operator*(const char& other) const {
        return this->value * other;
    }

    Character operator*(const Character& other) const {
        return this->value * other.value;
    }



    Character operator/(const int& other) const {
        return this->value / other;
    }

    Character operator/(const char& other) const {
        return this->value / other;
    }

    Character operator/(const Character& other) const {
        return this->value / other.value;
    }



    Character operator%(const int& other) const {
        return this->value % other;
    }

    Character operator%(const char& other) const {
        return this->value % other;
    }

    Character operator%(const Character& other) const {
        return this->value % other.value;
    }



    Character operator^(const int& other) const {
        return this->value ^ other;
    }

    Character operator^(const char& other) const {
        return this->value ^ other;
    }

    Character operator^(const Character& other) const {
        return this->value ^ other.value;
    }



    Character operator&(const int& other) const {
        return this->value & other;
    }

    Character operator&(const char& other) const {
        return this->value & other;
    }

    Character operator&(const Character& other) const {
        return this->value & other.value;
    }



    Character operator|(const int& other) const {
        return this->value | other;
    }

    Character operator|(const char& other) const {
        return this->value | other;
    }

    Character operator|(const Character& other) const {
        return this->value | other.value;
    }



    Character operator~() const {
        return ~this->value;
    }

    Character operator!() const {
        return !this->value;
    }



    bool operator==(const int& other) const {
        return this->value == other;
    }

    bool operator==(const char& other) const {
        return this->value == other;
    }

    bool operator==(const Character& other) const {
        return this->value == other.value;
    }



    bool operator!=(const int& other) const {
        return this->value != other;
    }

    bool operator!=(const char& other) const {
        return this->value != other;
    }

    bool operator!=(const Character& other) const {
        return this->value != other.value;
    }



    bool operator<(const int& other) const {
        return this->value < other;
    }

    bool operator<(const char& other) const {
        return this->value < other;
    }

    bool operator<(const Character& other) const {
        return this->value < other.value;
    }

    

    bool operator>(const int& other) const {
        return this->value > other;
    }

    bool operator>(const char& other) const {
        return this->value > other;
    }

    bool operator>(const Character& other) const {
        return this->value > other.value;
    }

    

    bool operator<=(const int& other) const {
        return this->value <= other;
    }

    bool operator<=(const char& other) const {
        return this->value <= other;
    }

    bool operator<=(const Character& other) const {
        return this->value <= other.value;
    }



    bool operator>=(const int& other) const {
        return this->value >= other;
    }

    bool operator>=(const char& other) const {
        return this->value >= other;
    }

    bool operator>=(const Character& other) const {
        return this->value >= other.value;
    }


    

    friend std::ostream& operator<<(std::ostream& out, const Character& character) {
        out << character.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Character& character) {
        in >> character.value;
        return in;
    }
};

/**
 * @brief A const char* wrapper class
 * 
 */
class String {
private:
    char* value;
    size_t length = 0;

    /**
     * @brief A method that copies a char* into the stirng
     * 
     * @param other 
     */
    void copy(const char* other) {
        this->length = strlen(other);
        this->value = new char[this->length + 1];
        for (size_t i = 0; i <= this->length; i++) {
            this->value[i] = other[i];
        }
        this->value[this->length] = '\0';
    }

    /**
     * @brief A method that checks the equality between two strings
     * 
     * @param other 
     * @return bool
     */
    bool equalityCompare(const char* other) const {
        for (size_t i = 0; i <= this->length; i++) {
            if (this->value[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that converts a character into a lowercase
     * 
     * @param other 
     * @return char 
     */
    char tolower(const char& other) const {
        if (other >= 'A' && other <= 'Z') {
            return other + 32;
        }
        return other;
    }

    /**
     * @brief A methid that converts a character into a lowercase
     * 
     * @param other 
     * @return char 
     */
    char tolower(char& other) const {
        if (other >= 'A' && other <= 'Z') {
            return other + 32;
        }
        return other;
    }

    /**
     * @brief A method that converts a character into a uppercase
     * 
     * @param other 
     * @return char 
     */
    char toupper(const char& other) const {
        if (other >= 'a' && other <= 'z') {
            return other - 32;
        }
        return other;

    }

    /**
     * @brief A method that converts a character into a uppercase
     * 
     * @param other 
     * @return char 
     */
    char toupper(char& other) const {
        if (other >= 'a' && other <= 'z') {
            return other - 32;
        }
        return other;
    }

    /**
     * @brief A helper function to resize the string
     * 
     * @param newLength 
     */
    void reAllocate(size_t newLength) {
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
    }

    using _StringView = const String&;

public:
    String() : value(nullptr), length(0) {}

    String(const char* value) {
        this->length = strlen(value);
        this->value = new char[this->length + 1];
        copy(value);
    }

    String(const std::string& value) {
        this->length = value.length();
        this->value = new char[this->length + 1];
        this->copy(value.c_str());
        this->value[this->length] = '\0';
    }

    String(_StringView other) {
        this->length = other.length;
        this->value = new char[this->length + 1];
        this->copy(other.value);
        this->value[this->length] = '\0';
    }

    String(const char& value) {
        this->length = 1;
        this->value = new char[this->length + 1];
        this->value[0] = value;
        this->value[1] = '\0';
    }

    String(const char* value, size_t length) {
        this->length = length;
        this->value = new char[this->length + 1];
        for (size_t i = 0; i < this->length; i++) {
            this->value[i] = value[i];
        }
        this->value[this->length] = '\0';
    }

    ~String() {
        delete[] this->value;
    }

    /**
     * @brief The largest possible string
     * 
     */
    const size_t LargeValue = -1;

    /**
     * @brief The length of the string
     * 
     */
    const size_t& Length = this->length;

    

    operator std::string() {
        return std::string(this->value);
    }

    operator char* () const {
        return this->value;
    }

    /**
     * @brief A method that returns the length of the string
     * 
     * @return size_t 
     */
    size_t size() const {
        return this->length;
    }

    /**
     * @brief Set the Value object
     * 
     * @param value 
     */
    void setValue(const char* value) {
        this->length = strlen(value);
        this->value = new char[this->length + 1];
        this->copy(value);
        this->value[this->length] = '\0';
    }

    /**
     * @brief Set the Value object
     * 
     * @param other 
     */
    void setValue(_StringView other) {
        this->length = other.length;
        this->value = new char[this->length + 1];
        this->copy(other.value);
        this->value[this->length] = '\0';
    }

    /**
     * @brief A method to return the value of the string
     * 
     * @return char* 
     */
    char* get() const {
        return this->value;
    }

    /**
     * @brief A method that appends a string to the end of the string
     * 
     * @param other 
     * @return char* 
     */
    char* append(const char* other) {
        size_t newLength = this->length + strlen(other);
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return this->value;
    }

    /**
     * @brief A method that appends a string to the end of the string
     * 
     * @param other 
     * @return char* 
     */
    char* append(_StringView other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return this->value;
    }

    /**
     * @brief A method that makes a string empty
     * 
     * @return char* 
     */
    char* empty() {
        delete[] this->value;
        this->value = nullptr;
        this->length = 0;
        return this->value;
    }

    /**
     * @brief A method that clears a string
     * 
     * @return char* 
     */
    char* clear() {
        this->value[0] = '\0';
        return this->value;
    }

    /**
     * @brief A method that erases a string specified ina range
     * 
     * @param start 
     * @param end 
     * @return String& 
     */
    String& erase(const size_t& start, const size_t& end) {
        if (start > end) {
            throw std::invalid_argument("Start index must be smaller than end index");
        }
        if (start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        if (end > this->length) {
            throw std::invalid_argument("End index must be smaller than length of string");
        }
        size_t newLength = this->length - (end - start);
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = start; i <= newLength; i++) {
            newValue[i] = this->value[i + (end - start)];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that erases a string starting from 0 to a specified index
     * 
     * @param start 
     * @return String& 
     */
    String& erase(const size_t& start) {
        if (start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        size_t newLength = this->length - 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = start; i <= newLength; i++) {
            newValue[i] = this->value[i + 1];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that erases a string starting from a specified index to the
     *  end and replaces it with a specified char
     * 
     * @param start 
     * @param end 
     * @param replacement 
     * @return String& 
     */
    String& erase(const size_t& start, const size_t& end, const char& replacement) {
        if (start > end) {
            throw std::invalid_argument("Start index must be smaller than end index");
        }
        if (start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        if (end > this->length) {
            throw std::invalid_argument("End index must be smaller than length of string");
        }
        size_t newLength = this->length - (end - start) + 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = start; i <= newLength; i++) {
            newValue[i] = replacement;
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that erases a string starting from 0 to a specified index
     *  and replaces it with a specified char
     * 
     * @param start 
     * @param replacement 
     * @return String& 
     */
    String& erase(const size_t& start, const char& replacement) {
        if (start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        size_t newLength = this->length - 1 + 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = start; i <= newLength; i++) {
            newValue[i] = replacement;
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that appends a string to the end of the string
     * 
     * @param other 
     * @return String& 
     */
    String& joins(_StringView other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that appends a string to the end of the string
     * 
     * @param other 
     * @return String& 
     */
    String& joins(const char* other) {
        size_t newLength = this->length + strlen(other);
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that appends a character to the end of a string
     * 
     * @param other 
     * @return String& 
     */
    String& joins(const char& other) {
        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength - 1] = other;
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that appends a string to the end of the string
     * 
     * @param other 
     * @return String& 
     */
    String& push(_StringView other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that appends a string to the end of the string
     * 
     * @param other 
     * @return String& 
     */
    String& push(const char* other) {
        size_t newLength = this->length + strlen(other);
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that appends a character to the end of a string
     * 
     * @param other 
     * @return String& 
     */
    String& push(const char& other) {
        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength - 1] = other;
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that removes the last character of a string
     * 
     * @return String& 
     */
    String& pop() {
        if (this->length == 0) {
            throw std::out_of_range("Cannot pop from empty string");
        }
        size_t newLength = this->length - 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that removes a character specified in an index
     * 
     * @param count 
     * @return String& 
     */
    String& pop(const size_t& count) {
        if (count > this->length) {
            throw std::out_of_range("Cannot pop more than length of string");
        }
        size_t newLength = this->length - count;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that returns a character specified in an index
     * 
     * @param index 
     * @return char 
     */
    char charAt(const size_t& index) const {
        if (index > this->length) {
            throw std::invalid_argument("Index must be smaller than length of string");
        }
        return this->value[index];
    }

    /**
     * @brief A method that converts from a string to int
     * 
     * @return int 
     */
    int toInt() const {
        return std::atoi(this->value);
    }

    /**
     * @brief A method that converts from a string to float
     * 
     * @return float 
     */
    float toFloat() const {
        return std::atof(this->value);
    }

    /**
     * @brief A method that converts from a string to double
     * 
     * @return double 
     */
    double toDouble() const {
        return std::atof(this->value);
    }

    /**
     * @brief A method that converts from a string to short
     * 
     * @return short 
     */
    short toShort() const {
        return std::atoi(this->value);
    }

    /**
     * @brief A method that checks if a string starts with a specified string
     * 
     * @param other 
     * @return bool
     */
    bool startsWith(_StringView other) const {
        if (other.length > this->length) {
            return false;
        }
        for (size_t i = 0; i < other.length; i++) {
            if (this->value[i] != other.value[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that checks if a string starts with a specified string
     * 
     * @param other 
     * @return bool
     */
    bool startsWith(const char* other) const {
        size_t otherLength = strlen(other);
        if (otherLength > this->length) {
            return false;
        }
        for (size_t i = 0; i < otherLength; i++) {
            if (this->value[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that checks if a string starts with a specified char
     * 
     * @param other 
     * @return bool
     */
    bool startsWith(const char& other) const {
        if (this->length < 1) {
            return false;
        }
        if (this->value[0] != other) {
            return false;
        }
        return true;
    }

    /**
     * @brief A method that checks if a string ends with a specified string
     * 
     * @param other 
     * @return bool
     */
    bool endsWith(_StringView other) const {
        if (other.length > this->length) {
            throw std::invalid_argument("Other string must be smaller than length of string");
        }
        for (size_t i = this->length - other.length; i < this->length; i++) {
            if (this->value[i] != other.value[i - (this->length - other.length)]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that checks if a string ends with a specified string
     * 
     * @param other 
     * @return bool 
     */
    bool endsWith(const char* other) const {
        size_t otherLength = strlen(other);
        if (otherLength > this->length) {
            throw std::invalid_argument("Other string must be smaller than length of string");
        }
        for (size_t i = this->length - otherLength; i < this->length; i++) {
            if (this->value[i] != other[i - (this->length - otherLength)]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that checks if a string ends with a specified char
     * 
     * @param other 
     * @return bool
     */
    bool endsWith(const char& other) const {
        if (this->length < 1) {
            return false;
        }
        if (this->value[this->length - 1] != other) {
            return false;
        }
        return true;
    }

    /**
     * @brief A method that makes a string lowercase
     * 
     * @return String& 
     */
    String& toLower() {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] >= 'A' && this->value[i] <= 'Z') {
                this->value[i] += 32;
            }
        }
        return *this;
    }

    /**
     * @brief A method that makes a string uppercase
     * 
     * @return String& 
     */
    String& toUpper() {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] >= 'a' && this->value[i] <= 'z') {
                this->value[i] -= 32;
            }
        }
        return *this;
    }

    /**
     * @brief Removes the leading and trailing white space
     *  and line terminator characters from a string.
     * 
     * @return String& 
     */
    String& trim() {
        size_t start = 0;
        size_t end = this->length;
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] != ' ' && this->value[i] != '\t' && this->value[i] != '\n' && this->value[i] != '\r') {
                start = i;
                break;
            }
        }
        for (size_t i = this->length - 1; i > 0; i--) {
            if (this->value[i] != ' ' && this->value[i] != '\t' && this->value[i] != '\n' && this->value[i] != '\r') {
                end = i + 1;
                break;
            }
        }
        if (start == 0 && end == this->length) {
            return *this;
        }
        size_t newLength = end - start;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i + start];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief Returns a string that contains the concatenation of two or more strings.
     * 
     * @param other 
     * @return String& 
     */
    String& concat(_StringView other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief Returns a string that contains the concatenation of two or more strings.
     * 
     * @param other 
     * @return String& 
     */
    String& concat(const char* other) {
        size_t otherLength = strlen(other);
        size_t newLength = this->length + otherLength;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief Returns a string that contains the concatenation of a string and a char
     * 
     * @param other 
     * @return String& 
     */
    String& concat(const char& other) {
        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength - 1] = other;
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief Returns the last occurrence of a substring in the string.
     * 
     * @param other 
     * @return int 
     */
    int lastIndexOf(const char& other) const {
        for (int i = this->length - 1; i >= 0; i--) {
            if (this->value[i] == other) {
                return i;
            }
        }
        return -1;
    }

    /**
     * @brief Returns true if searchString appears as a substring of the result of converting this
     * object to a String, at one or more positions that are
     * greater than or equal to position; otherwise, returns false.
     * 
     * @param other 
     * @return bool
     */
    bool includes(const char& other) const {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Returns true if searchString appears as a substring of the result of converting this
     * object to a String, at one or more positions that are
     * greater than or equal to position; otherwise, returns false.
     * 
     * @param other 
     * @return bool
     */
    bool includes(_StringView other) const {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other.value[0]) {
                bool found = true;
                for (size_t j = 0; j < other.length; j++) {
                    if (this->value[i + j] != other.value[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @brief Returns true if searchString appears as a substring of the result of converting this
     * object to a String, at one or more positions that are
     * greater than or equal to position; otherwise, returns false.
     * 
     * @param other 
     * @return bool
     */
    bool includes(const char* other) const {
        size_t otherLength = strlen(other);
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other[0]) {
                bool found = true;
                for (size_t j = 0; j < otherLength; j++) {
                    if (this->value[i + j] != other[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @brief Returns a String value that is made from count copies appended together.
     * If count is 0, the empty string is returned.
     * 
     * @param count 
     * @return String& 
     */
    String& repeat(size_t count) {
        size_t newLength = this->length * count;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i % this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief Returns the substring at the specified location within a String object.
     * 
     * @param start 
     * @param end 
     * @return String 
     */
    String substring(size_t start, size_t end) const {
        if (start > end) {
            size_t temp = start;
            start = end;
            end = temp;
        }
        if (start > this->length) {
            start = this->length;
        }
        if (end > this->length) {
            end = this->length;
        }
        size_t newLength = end - start;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i + start];
        }
        newValue[newLength] = '\0';
        String result = newValue;
        delete[] newValue;
        return result;
    }

    /**
     * @brief Returns the substring at the specified location within a String object.
     * 
     * @param start 
     * @return String 
     */
    String substring(size_t start) const {
        return this->substring(start, this->length);
    }

    /**
     * @brief Split a string into substrings using the
     * specified separator and return them as an array.
     * 
     * @param separator 
     * @param result 
     * @return String& 
     */
    String& split(const char& separator, String& result) const {
        size_t start = 0;
        size_t end = 0;
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == separator) {
                end = i;
                result.concat(this->substring(start, end));
                start = i + 1;
            }
        }
        result.concat(this->substring(start));
        return result;
    }

    /**
     * @brief A method that replaces a character in a string with another character.
     * 
     * @param old 
     * @param newChar 
     * @return String& 
     */
    String& replace(const char& old, const char& newChar) {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == old) {
                this->value[i] = newChar;
            }
        }
        return *this;
    }

    /**
     * @brief A method that replaces a substring in a string with another substring.
     * 
     * @param old 
     * @param newString 
     * @return String& 
     */
    String& replace(_StringView old, _StringView newString) {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == old.value[0]) {
                bool found = true;
                for (size_t j = 0; j < old.length; j++) {
                    if (this->value[i + j] != old.value[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    this->value[i] = newString.value[0];
                    for (size_t j = 1; j < newString.length; j++) {
                        this->value[i + j] = newString.value[j];
                    }
                    i += newString.length - 1;
                }
            }
        }
        return *this;
    }

    /**
     * @brief A method that replaces a substring in a string with another substring.
     * 
     * @param old 
     * @param newString 
     * @return String& 
     */
    String& replace(const char* old, const char* newString) {
        size_t oldLength = strlen(old);
        size_t newLength = strlen(newString);
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == old[0]) {
                bool found = true;
                for (size_t j = 0; j < oldLength; j++) {
                    if (this->value[i + j] != old[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    this->value[i] = newString[0];
                    for (size_t j = 1; j < newLength; j++) {
                        this->value[i + j] = newString[j];
                    }
                    i += newLength - 1;
                }
            }
        }
        return *this;
    }

    /**
     * @brief A method that replaces a character in a string with another character.
     * 
     * @param old 
     * @param newChar 
     * @return String& 
     */
    String& replaceFirst(const char& old, const char& newChar) {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == old) {
                this->value[i] = newChar;
                return *this;
            }
        }
        return *this;
    }

    /**
     * @brief A method that replaces a substring in a string with another substring.
     * 
     * @param old 
     * @param newString 
     * @return String& 
     */
    String& replaceFirst(_StringView old, _StringView newString) {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == old.value[0]) {
                bool found = true;
                for (size_t j = 0; j < old.length; j++) {
                    if (this->value[i + j] != old.value[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    this->value[i] = newString.value[0];
                    for (size_t j = 1; j < newString.length; j++) {
                        this->value[i + j] = newString.value[j];
                    }
                    return *this;
                }
            }
        }
        return *this;
    }

    /**
     * @brief A method that replaces a substring in a string with another substring.
     * 
     * @param old 
     * @param newString 
     * @return String& 
     */
    String& replaceFirst(const char* old, const char* newString) {
        size_t oldLength = strlen(old);
        size_t newLength = strlen(newString);
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == old[0]) {
                bool found = true;
                for (size_t j = 0; j < oldLength; j++) {
                    if (this->value[i + j] != old[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    this->value[i] = newString[0];
                    for (size_t j = 1; j < newLength; j++) {
                        this->value[i + j] = newString[j];
                    }
                    return *this;
                }
            }
        }
        return *this;
    }

    /**
     * @brief Returns the position of the first occurrence of a substring.
     * 
     * @param other 
     * @return int 
     */
    int indexOf(const char& other) const {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other) {
                return i;
            }
        }
        return -1;
    }

    /**
     * @brief A method that swaps a string with another string
     * 
     * @param other 
     * @return String& 
     */
    String& swap(String& other) {
        char* temp = this->value;
        this->value = other.value;
        other.value = temp;
        size_t tempLength = this->length;
        this->length = other.length;
        other.length = tempLength;
        return *this;
    }

    /**
     * @brief A method that checks if a string is empty or not
     * 
     * @return bool
     */
    bool isEmpty() const {
        if (this->length == 0) {
            return true;
        }
        return false;
    }

    /**
     * @brief A method that compares two strings
     * 
     * @param other 
     * @return bool
     */
    bool compare(_StringView other) const {
        if (this->length != other.length) {
            return false;
        }
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] != other.value[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that iterates through a string
     * 
     * @param func 
     * @return String& 
     */
    String& forEach(const std::function<void(char&)>& func) {
        for (size_t i = 0; i < this->length; i++) {
            func(this->value[i]);
        }
        return *this;
    }

    /**
     * @brief A method checks if two strings are equal ignoring the case
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool equalIgnoreCase(_StringView other) const {
        if (this->length != other.length) {
            return false;
        }
        for (size_t i = 0; i < this->length; i++) {
            if (this->tolower(this->value[i]) != this->tolower(other.value[i])) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that reverses a string
     * 
     * @return String& 
     */
    String& reverse() {
        for (size_t i = 0; i < this->length / 2; i++) {
            char temp = this->value[i];
            this->value[i] = this->value[this->length - i - 1];
            this->value[this->length - i - 1] = temp;
        }
        return *this;
    }

    /**
     * @brief A method that returns the type of the object
     * 
     * @return const char* 
     */
    const char* type() const {
        return "String";
    }

    /**
     * @brief A method Capitalize the first letter of a string and makes the rest 
     * of the letters lowercase
     * 
     * @return String& 
     */
    String& capitalize() {
        for (size_t i = 0; i < this->length; i++) {
            if (i == 0) {
                this->value[i] = toupper(this->value[i]);
            }
            else {
                this->value[i] = tolower(this->value[i]);
            }
        }
        return *this;
    }

    /**
     * @brief A method that counts the number of a specified char in a string
     * 
     * @param other 
     * @return int 
     */
    int count(const char& other) const {
        int count = 0;
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other) {
                count++;
            }
        }
        return count;
    }

    /**
     * @brief A method that counts the number of a specified string in a string
     * 
     * @param other 
     * @return int 
     */
    int count(_StringView other) const {
        int count = 0;
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other.value[0]) {
                bool found = true;
                for (size_t j = 0; j < other.length; j++) {
                    if (this->value[i + j] != other.value[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    count++;
                    i += other.length - 1;
                }
            }
        }
        return count;
    }

    /**
     * @brief A method that counts the number of a specified string in a string
     * 
     * @param other 
     * @return int 
     */
    int count(const char* other) const {
        int count = 0;
        size_t otherLength = strlen(other);
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other[0]) {
                bool found = true;
                for (size_t j = 0; j < otherLength; j++) {
                    if (this->value[i + j] != other[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    count++;
                    i += otherLength - 1;
                }
            }
        }
        return count;
    }

    /**
     * @brief Returns a version of the string suitable for caseless comparison 
     * 
     * @return String 
     */
    String casefold() const {
        String result = *this;
        for (size_t i = 0; i < this->length; i++) {
            result.value[i] = tolower(this->value[i]);
        }
        return result;
    }

    /**
     * @brief Converts uppercase to lowercase and lowercase to uppercase
     * 
     * @return String& 
     */
    String& swapCase() {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] >= 'a' && this->value[i] <= 'z') {
                this->value[i] = toupper(this->value[i]);
            }
            else if (this->value[i] >= 'A' && this->value[i] <= 'Z') {
                this->value[i] = tolower(this->value[i]);
            }
        }
        return *this;
    }

    /**
     * @brief A method that finds the first index of a specified char in a string
     * 
     * @param other 
     * @return bool
     */
    bool find(const char& other) const {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief A method that finds the first index of a specified string in a string
     * 
     * @param other 
     * @return bool
     */
    bool find(_StringView other) const {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other.value[0]) {
                bool found = true;
                for (size_t j = 0; j < other.length; j++) {
                    if (this->value[i + j] != other.value[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @brief A method that finds the first index of a specified string in a string
     * 
     * @param other 
     * @return bool
     */
    bool find(const char* other) const {
        size_t otherLength = strlen(other);
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] == other[0]) {
                bool found = true;
                for (size_t j = 0; j < otherLength; j++) {
                    if (this->value[i + j] != other[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @brief A method that checks if all the characters in a string are alphabet
     * 
     * @return bool
     */
    bool isAlphabet() const {
        for (size_t i = 0; i < this->length; i++) {
            if (!isalpha(this->value[i])) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that checks if all the characters in a string are numeric
     * 
     * @return true 
     * @return false 
     */
    bool isNumeric() const {
        for (size_t i = 0; i < this->length; i++) {
            if (!isalnum(this->value[i])) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that inserts a string into another string at a specified index
     * 
     * @param index 
     * @param other 
     * @return String& 
     */
    String& insert(size_t index, const char* other) {
        if (index > this->length) {
            return *this;
        }

        size_t otherLength = strlen(other);
        size_t newLength = this->length + otherLength;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < index; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = 0; i < otherLength; i++) {
            newValue[index + i] = other[i];
        }
        for (size_t i = index; i < this->length; i++) {
            newValue[otherLength + i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that inserts a string into another string at a specified index
     * 
     * @param index 
     * @param other 
     * @return String& 
     */
    String& insert(size_t index, _StringView other) {
        if (index > this->length) {
            return *this;
        }

        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < index; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = 0; i < other.length; i++) {
            newValue[index + i] = other.value[i];
        }
        for (size_t i = index; i < this->length; i++) {
            newValue[other.length + i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that inserts a char into another string at a specified index
     * 
     * @param index 
     * @param other 
     * @return String& 
     */
    String& insert(size_t index, const char& other) {
        if (index > this->length) {
            return *this;
        }

        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < index; i++) {
            newValue[i] = this->value[i];
        }
        newValue[index] = other;
        for (size_t i = index; i < this->length; i++) {
            newValue[1 + i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    /**
     * @brief A method that returns the first index's value
     * 
     * @return char 
     */
    char front() const {
        return this->value[0];
    }

    /**
     * @brief A method that returns the last index's value
     * 
     * @return char 
     */
    char back() const {
        return this->value[this->length - 1];
    }

    /**
     * @brief A method that returns a C style string
     * 
     * @return const char* 
     */
    const char* cString() const {
        return this->value;
    }

    /**
     * @brief Returns a string with the given prefix removed if it exists
     * 
     * @param other 
     * @return String& 
     */
    String& removePrefix(const char& other) {
        if (this->value[0] == other) {
            size_t newLength = this->length - 1;
            char* newValue = new char[newLength + 1];
            for (size_t i = 1; i < this->length; i++) {
                newValue[i - 1] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    /**
     * @brief Returns a string with the given prefix removed if it exists
     * 
     * @param other 
     * @return String& 
     */
    String& removePrefix(_StringView other) {
        if (this->value[0] == other.value[0]) {
            size_t otherLength = other.length;
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for (size_t i = otherLength; i < this->length; i++) {
                newValue[i - otherLength] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    /**
     * @brief Returns a string with the given prefix removed if it exists
     * 
     * @param other 
     * @return String& 
     */
    String& removePrefix(const char* other) {
        size_t otherLength = strlen(other);
        if (this->value[0] == other[0]) {
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for (size_t i = otherLength; i < this->length; i++) {
                newValue[i - otherLength] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    /**
     * @brief Returns a string with the given suffix removed if it exists
     * 
     * @param other 
     * @return String& 
     */
    String& removeSuffix(const char& other) {
        if (this->value[this->length - 1] == other) {
            size_t newLength = this->length - 1;
            char* newValue = new char[newLength + 1];
            for (size_t i = 0; i < newLength; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    /**
     * @brief Returns a string with the given suffix removed if it exists
     * 
     * @param other 
     * @return String& 
     */
    String& removeSuffix(_StringView other) {
        if (this->value[this->length - 1] == other.value[other.length - 1]) {
            size_t otherLength = other.length;
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for (size_t i = 0; i < newLength; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    /**
     * @brief Returns a string with the given suffix removed if it exists
     * 
     * @param other 
     * @return String& 
     */
    String& removeSuffix(const char* other) {
        size_t otherLength = strlen(other);
        if (this->value[this->length - 1] == other[otherLength - 1]) {
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for (size_t i = 0; i < newLength; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    /**
     * @brief A method that checks if all characters in the string are lowercase
     * 
     * @return bool
     */
    bool isLower() const {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] < 'a' || this->value[i] > 'z') {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief A method that checks if all characters in the string are uppercase
     * 
     * @return bool
     */
    bool isUpper() const {
        for (size_t i = 0; i < this->length; i++) {
            if (this->value[i] < 'A' || this->value[i] > 'Z') {
                return false;
            }
        }
        return true;
    }




    String& operator=(const char* value) {
        this->length = strlen(value);
        this->value = new char[this->length + 1];
        this->copy(value);
        this->value[this->length] = '\0';
        return *this;
    }

    String& operator=(_StringView other) {
        this->length = other.length;
        this->value = new char[this->length + 1];
        this->copy(other.value);
        return *this;
    }

    String& operator=(const char& value) {
        this->length = 1;
        this->value = new char[this->length + 1];
        this->value[0] = value;
        this->value[1] = '\0';
        return *this;
    }



    String& operator+=(const char* value) {
        size_t newLength = this->length + strlen(value);
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i < newLength; i++) {
            newValue[i] = value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& operator+=(_StringView other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i];
        }
        for (size_t i = this->length; i < newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& operator+=(const char& value) {
        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for (size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[this->length] = value;
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }



    String operator+(const char* value) const {
        String result = *this;
        result += value;
        return result;
    }

    String operator+(_StringView other) const {
        String result = *this;
        result += other;
        return result;
    }

    String operator+(const char& value) const {
        String result = *this;
        result += value;
        return result;
    }



    String operator*(size_t times) const {
        String result = *this;
        for (size_t i = 0; i < times - 1; i++) {
            result += *this;
        }
        return result;
    }



    bool operator==(const char* other) const {
        return this->equalityCompare(other);
    }

    bool operator==(_StringView other) const {
        return this->equalityCompare(other.value);
    }

    bool operator==(const char& other) const {
        return this->value[0] == other;
    }

    bool operator!=(const char* other) const {
        return !this->equalityCompare(other);
    }

    bool operator!=(_StringView other) const {
        return !this->equalityCompare(other.value);
    }

    bool operator!=(const char& other) const {
        return this->value[0] != other;
    }



    bool operator<(const char* other) const {
        return this->length < strlen(other);
    }

    bool operator<(_StringView other) const {
        return this->length < other.length;
    }

    bool operator<(const char& other) const {
        return this->value[0] < other;
    }



    bool operator>(const char* other) const {
        return this->length > strlen(other);
    }

    bool operator>(_StringView other) const {
        return this->length > other.length;
    }

    bool operator>(const char& other) const {
        return this->value[0] > other;
    }



    bool operator<=(const char* other) const {
        return this->length <= strlen(other);
    }

    bool operator<=(_StringView other) const {
        return this->length <= other.length;
    }

    bool operator<=(const char& other) const {
        return this->value[0] <= other;
    }



    bool operator>=(const char* other) const {
        return this->length >= strlen(other);
    }

    bool operator>=(_StringView other) const {
        return this->length >= other.length;
    }

    bool operator>=(const char& other) const {
        return this->value[0] >= other;
    }


    bool operator!() const {
        return this->length == 0;
    }

    bool operator&&(_StringView other) const {
        return this->length && other.length;
    }

    bool operator||(_StringView other) const {
        return this->length || other.length;
    }

    bool operator&&(const char& other) const {
        return this->value[0] && other;
    }

    bool operator||(const char& other) const {
        return this->value[0] || other;
    }

    bool operator&&(const char* other) const {
        return this->length && strlen(other);
    }

    bool operator||(const char* other) const {
        return this->length || strlen(other);
    }

    bool operator&&(const bool& other) const {
        return this->length && other;
    }

    bool operator||(const bool& other) const {
        return this->length || other;
    }

    bool operator!=(const bool& other) const {
        return !this->length == other;
    }

    bool operator==(const bool& other) const {
        return this->length == other;
    }

    String& operator--() {
        this->length--;
        char* newValue = new char[this->length + 1];
        for (size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i + 1];
        }
        newValue[this->length] = '\0';
        delete[] this->value;
        this->value = newValue;
        return *this;
    }

    String operator--(int) {
        String result = *this;
        this->length--;
        char* newValue = new char[this->length + 1];
        for (size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i + 1];
        }
        newValue[this->length] = '\0';
        delete[] this->value;
        this->value = newValue;
        return result;
    }

    class StringStream {
    private:
        String* string;
        size_t position;
    public:
        StringStream(String* string) : string(string), position(0) {}

        StringStream& operator<<(const char* value) {
            size_t length = strlen(value);
            char* newValue = new char[this->string->length + length + 1];
            for (size_t i = 0; i < this->position; i++) {
                newValue[i] = this->string->value[i];
            }
            for (size_t i = 0; i < length; i++) {
                newValue[i + this->position] = value[i];
            }
            for (size_t i = this->position + length; i < this->string->length + length; i++) {
                newValue[i] = this->string->value[i - length];
            }
            newValue[this->string->length + length] = '\0';
            delete[] this->string->value;
            this->string->value = newValue;
            this->string->length += length;
            this->position += length;
            return *this;
        }

        StringStream& operator<<(_StringView value) {
            size_t length = value.length;
            char* newValue = new char[this->string->length + length + 1];
            for (size_t i = 0; i < this->position; i++) {
                newValue[i] = this->string->value[i];
            }
            for (size_t i = 0; i < length; i++) {
                newValue[i + this->position] = value.value[i];
            }
            for (size_t i = this->position + length; i < this->string->length + length; i++) {
                newValue[i] = this->string->value[i - length];
            }
            newValue[this->string->length + length] = '\0';
            delete[] this->string->value;
            this->string->value = newValue;
            this->string->length += length;
            this->position += length;
            return *this;
        }

        StringStream& operator<<(const char& value) {
            char* newValue = new char[this->string->length + 2];
            for (size_t i = 0; i < this->position; i++) {
                newValue[i] = this->string->value[i];
            }
            newValue[this->position] = value;
            newValue[this->position + 1] = '\0';
            for (size_t i = this->position + 1; i < this->string->length + 1; i++) {
                newValue[i + 1] = this->string->value[i];
            }
            delete[] this->string->value;
            this->string->value = newValue;
            this->string->length++;
            this->position++;
            return *this;
        }

        StringStream& operator>>(const char* value) {
            size_t length = strlen(value);
            if (this->position + length > this->string->length) {
                return *this;
            }
            for (size_t i = 0; i < length; i++) {
                if (this->string->value[this->position + i] != value[i]) {
                    return *this;
                }
            }
            this->position += length;
            return *this;
        }

        StringStream& operator>>(_StringView value) {
            size_t length = value.length;
            if (this->position + length > this->string->length) {
                return *this;
            }
            for (size_t i = 0; i < length; i++) {
                if (this->string->value[this->position + i] != value.value[i]) {
                    return *this;
                }
            }
            this->position += length;
            return *this;
        }

        StringStream& operator>>(const char& value) {
            if (this->position + 1 > this->string->length) {
                return *this;
            }
            if (this->string->value[this->position] != value) {
                return *this;
            }
            this->position++;
            return *this;
        }
    };

    StringStream operator<<(const char* value) {
        return StringStream(this) << value;
    }

    StringStream operator<<(_StringView value) {
        return StringStream(this) << value;
    }

    StringStream operator<<(const char& value) {
        return StringStream(this) << value;
    }

    StringStream operator>>(const char* value) {
        return StringStream(this) >> value;
    }

    StringStream operator>>(_StringView value) {
        return StringStream(this) >> value;
    }

    StringStream operator>>(const char& value) {
        return StringStream(this) >> value;
    }

    friend std::ostream& operator<<(std::ostream& out, _StringView string) {
        out << string.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, String& string) {
        string.reAllocate(0);
        char c;
        while (in.get(c)) {
            if (c == '\n') {
                break;
            }
            string += c;
        }
        return in;
    }
};

String operator"" _s(const char* str, size_t len)
{
    return String(str, len);
}

Double operator""_d(long double value)
{
    return Double(value);
}

Float operator""_f(long double value)
{
    return Float(value);
}

Integer operator""_i(unsigned long long value)
{
    return Integer(value);
}

Short operator""_si(unsigned long long value)
{
    return Short(value);
}

using StringView  = const String&;

using DoubleView  = const Double&;

using FloatView   = const Float&;

using IntegerView = const Integer&;

using ShortView   = const Short&;

using BooleanView = const Boolean&;


#endif
