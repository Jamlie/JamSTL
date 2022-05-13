#pragma once
// ! Omar Estietie

#include <iostream>
#include <cstring>
#include <stdarg.h>

#ifndef _INTEGER_HPP_
#define _INTEGER_HPP_

class Integer {
private:
    int value;
    friend class Long;
    friend class Float;
    friend class Double;
public:
    Integer() {
        value = 0;
    }

    Integer(int value) {
        this->value = value;
    }

    Integer(const float& value) {
        this->value = value;
    }

    Integer(const double& value) {
        this->value = value;
    }

    Integer(const long& value) {
        this->value = value;
    }

    Integer(const long long& value) {
        this->value = value;
    }

    Integer(const unsigned int& value) {
        this->value = value;
    }

    Integer(const unsigned long& value) {
        this->value = value;
    }

    Integer(const unsigned long long& value) {
        this->value = value;
    }

    Integer(const char* value) {
        this->value = atoi(value);
    }

    Integer(const long double value) {
        this->value = value;
    }


    Integer& operator=(const Integer& other) {
        this->value = other.value;
        return *this;
    }

    Integer& operator=(int other) {
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



    auto toString() const {
        return std::to_string(value);
    }

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

    Integer& parseInt(const char* string) {
        value = atoi(string);
        return *this;
    }

    Integer length() {
        int length = 0;
        int original = value;
        while (original != 0) {
            original /= 10;
            length++;
        }
        return length;
    }

    const char* type() const {
        return "Integer";
    }

    Integer largestIntValue() {
        return 2147483647;
    }

    Integer smallestIntValue() {
        return -2147483648;
    }

    Integer signum() {
        if (this->value > 0) {
            return 1;
        } else if (value < 0) {
            return -1;
        } else {
            return 0;
        }
    }

    Integer& abs() {
        if (this->value < 0) {
            this->value = -this->value;
        }
        return *this;
    }

    Integer& negate() {
        this->value = -this->value;
        return *this;
    }

    Integer& add(const Integer& other) {
        this->value += other.value;
        return *this;
    }

    Integer& add(int other) {
        this->value += other;
        return *this;
    }

    Integer& add(const float& other) {
        this->value += other;
        return *this;
    }

    Integer& swap(Integer& other) {
        Integer temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }
    
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

    Integer& operator+=(int other) {
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



    Integer& operator-=(const Integer& other) {
        this->value -= other.value;
        return *this;
    }

    Integer& operator-=(int other) {
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



    Integer& operator*=(const Integer& other) {
        this->value *= other.value;
        return *this;
    }

    Integer& operator*=(int other) {
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



    Integer& operator/=(const Integer& other) {
        this->value /= other.value;
        return *this;
    }

    Integer& operator/=(int other) {
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



    Integer& operator%=(const Integer& other) {
        this->value %= other.value;
        return *this;
    }

    Integer& operator%=(int other) {
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

    Integer operator+(int other) const {
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



    Integer operator-(const Integer& other) const {
        return Integer(this->value - other.value);
    }

    Integer operator-(int other) const {
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



    Integer operator*(const Integer& other) const {
        return Integer(this->value * other.value);
    }

    Integer operator*(int other) const {
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



    Integer operator/(const Integer& other) const {
        return Integer(this->value / other.value);
    }

    Integer operator/(int other) const {
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



    Integer operator%(const Integer& other) const {
        return Integer(this->value % other.value);
    }

    Integer operator%(int other) const {
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



    bool operator==(const Integer& other) const {
        return this->value == other.value;
    }

    bool operator==(int other) const {
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



    bool operator!=(const Integer& other) const {
        return this->value != other.value;
    }

    bool operator!=(int other) const {
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



    bool operator<(const Integer& other) const {
        return this->value < other.value;
    }

    bool operator<(int other) const {
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



    bool operator>(const Integer& other) const {
        return this->value > other.value;
    }

    bool operator>(int other) const {
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



    bool operator<=(const Integer& other) const {
        return this->value <= other.value;
    }

    bool operator<=(int other) const {
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



    bool operator>=(const Integer& other) const {
        return this->value >= other.value;
    }

    bool operator>=(int other) const {
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

    bool operator&&(int other) const {
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

    bool operator||(const Integer& other) const {
        return this->value || other.value;
    }

    bool operator||(int other) const {
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

    Integer operator&(const Integer& other) const {
        return Integer(this->value & other.value);
    }

    Integer operator&(int other) const {
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

    Integer operator|(const Integer& other) const {
        return Integer(this->value | other.value);
    }

    Integer operator|(int other) const {
        return Integer(this->value | other);
    }

    Integer operator^(const Integer& other) const {
        return Integer(this->value ^ other.value);
    }

    Integer operator^(int other) const {
        return Integer(this->value ^ other);
    }



    Integer operator<<(const Integer& other) const {
        return Integer(this->value << other.value);
    }

    Integer operator<<(int other) const {
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



    Integer operator>>(const Integer& other) const {
        return Integer(this->value >> other.value);
    }

    Integer operator>>(int other) const {
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

    friend std::ostream& operator<<(std::ostream& out, const Integer& integer) {
        out << integer.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Integer& integer) {
        in >> integer.value;
        return in;
    }
};

class Float {
private:
    float value;
    friend class Integer;
    friend class Long;
    friend class Double;
public:
    Float() {
        value = 0;
    }

    Float(float value) {
        this->value = value;
    }

    Float(const Integer& integer) {
        this->value = integer.value;
    }

    Float(const long long& LL) {
        this->value = LL;
    }

    Float(const long& L) {
        this->value = L;
    }

    Float(const int& I) {
        this->value = I;
    }

    Float(const double& double_) {
        this->value = double_;
    }

    Float(const long double& long_double) {
        this->value = long_double;
    }

    Float(const unsigned int &UI) {
        this->value = UI;
    }

    Float(const unsigned long &UL) {
        this->value = UL;
    }

    Float(const unsigned long long &ULL) {
        this->value = ULL;
    }



    Float& operator=(const Float& other) {
        this->value = other.value;
        return *this;
    }

    Float& operator=(float other) {
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



    auto toString() {
        return std::to_string(this->value);
    }

    const char* type() const {
        return "Float";
    }

    Float& parseFloat(const char* str) {
        this->value = atof(str);
        return *this;
    }

    Float& intValue(const Integer& other) {
        this->value = other.value;
        return *this;
    }

    Float& intValue(int other) {
        this->value = other;
        return *this;
    }

    Float& intValue() {
        this->value = (int) this->value;
        return *this;
    }

    Float& longValue(const long long& other) {
        this->value = other;
        return *this;
    }

    Float signum() {
        if(this->value > 0) {
            return 1;
        } else if(this->value < 0) {
            return -1;
        } else {
            return 0;
        }
    }  

    Float& negate() {
        this->value = -this->value;
        return *this;
    }

    Float& abs() {
        if(this->value < 0) {
            this->value = -this->value;
        }
        return *this;
    }

    size_t length() {
        return std::to_string(this->value).length();
    }

    long long floor() {
        long long result;
        if(this->value < 0) {
            result = (long long)this->value - 1;
            return result;
        }
        return this->value;                
    }

    long long ceil() {
        if(this->value - (long long)this->value == 0) return this->value;
        return this->floor() + 1;
    }

    long long round() {
        if(this->value - (long long)this->value == 0) return this->value;
        double number = this->value - (long long)this->value;
        if(this->value < 0) {
            double negativeValue = this->value - (long long)this->value;
            long long result;
            if(negativeValue <= -0.5 && negativeValue > -1) result = this->floor();
            else if(negativeValue > -0.5 && negativeValue < 0) result = this->ceil();
            return result;
        }
        long long result;
        if(number >= 0.5 && number < 1) result = this->ceil();
        else if(number < 0.5 && number > 0) result = this->floor();
        return result;
    }

    Float& swap(Float& other) {
        Float temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

    Float& swap(Integer& other) {
        Float temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

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

    Float& operator+=(float other) {
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



    Float& operator-=(const Float& other) {
        this->value -= other.value;
        return *this;
    }

    Float& operator-=(float other) {
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



    Float& operator*=(const Float& other) {
        this->value *= other.value;
        return *this;
    }

    Float& operator*=(float other) {
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



    Float& operator/=(const Float& other) {
        this->value /= other.value;
        return *this;
    }

    Float& operator/=(float other) {
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

    Float operator+(float other) const {
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



    Float operator-(const Float& other) const {
        return Float(this->value - other.value);
    }

    Float operator-(float other) const {
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



    Float operator*(const Float& other) const {
        return Float(this->value * other.value);
    }

    Float operator*(float other) const {
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



    Float operator/(const Float& other) const {
        return Float(this->value / other.value);
    }

    Float operator/(float other) const {
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



    bool operator==(const Float& other) const {
        return this->value == other.value;
    }

    bool operator==(float other) const {
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



    bool operator!=(const Float& other) const {
        return this->value != other.value;
    }

    bool operator!=(float other) const {
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

    bool operator<(float other) const {
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



    bool operator>(const Float& other) const {
        return this->value > other.value;
    }

    bool operator>(float other) const {
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



    bool operator<=(const Float& other) const {
        return this->value <= other.value;
    }

    bool operator<=(float other) const {
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



    bool operator>=(const Float& other) const {
        return this->value >= other.value;
    }

    bool operator>=(float other) const {
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


    bool operator!() const {
        return !this->value;
    }

    bool operator&&(const Float& other) const {
        return this->value && other.value;
    }

    bool operator&&(float other) const {
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

    bool operator||(const Float& other) const {
        return this->value || other.value;
    }

    bool operator||(float other) const {
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


    friend std::ostream& operator<<(std::ostream& out, const Float& floatNum) {
        out << floatNum.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Float& floatNum) {
        in >> floatNum.value;
        return in;
    }
};

class Double {
private:
    double value;
    friend class Integer;
    friend class Long;
    friend class Float;
public:
    public:
    Double() {
        value = 0;
    }

    Double(double value) {
        this->value = value;
    }

    Double(const Integer& integer) {
        this->value = integer.value;
    }

    Double(const Float& floatNum) {
        this->value = floatNum.value;
    }

    Double(const long long& longNum) {
        this->value = longNum;
    }

    Double(const long& longNum) {
        this->value = longNum;
    }

    Double(const int& intNum) {
        this->value = intNum;
    }

    Double(const Double& other) {
        this->value = other.value;
    }

    Double(const unsigned long long& unsignedLongNum) {
        this->value = unsignedLongNum;
    }

    Double(const unsigned long& unsignedLongNum) {
        this->value = unsignedLongNum;
    }

    Double(const unsigned int& unsignedIntNum) {
        this->value = unsignedIntNum;
    }

    Double(const long double& longDoubleNum) {
        this->value = longDoubleNum;
    }



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

    

    auto toString() const {
        return std::to_string(this->value);
    }

    Double& negate() {
        this->value = -this->value;
        return *this;
    }

    Double& abs() {
        if(this->value < 0) {
            this->value = -this->value;
        }
        return *this;
    }

    Double& intValue() {
        this->value = (int) this->value;
        return *this;
    }

    Double& longValue() {
        this->value = (long long) this->value;
        return *this;
    }

    long long floor() {
        long long result;
        if(this->value < 0) {
            result = (long long)this->value - 1;
            return result;
        }
        return this->value;                
    }

    long long ceil() {
        if(this->value - (long long)this->value == 0) return this->value;
        return this->floor() + 1;
    }

    long long round() {
        if(this->value - (long long)this->value == 0) return this->value;
        double number = this->value - (long long)this->value;
        if(this->value < 0) {
            double negativeValue = this->value - (long long)this->value;
            long long result;
            if(negativeValue <= -0.5 && negativeValue > -1) result = this->floor();
            else if(negativeValue > -0.5 && negativeValue < 0) result = this->ceil();
            return result;
        }
        long long result;
        if(number >= 0.5 && number < 1) result = this->ceil();
        else if(number < 0.5 && number > 0) result = this->floor();
        return result;
    }

    Double& signum() {
        if(this->value < 0) {
            this->value = -1;
        } else if(this->value > 0) {
            this->value = 1;
        } else {
            this->value = 0;
        }
        return *this;
    }

    const char* type() const {
        return "Double";
    }

    Double& parseDouble(const char* string) {
        this->value = std::stod(string);
        return *this;
    }

    Double& swap(Integer& other) {
        Double temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }
    Double& swap(Float& other) {
        Double temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }
    Double& swap(Double& other) {
        Double temp;
        temp.value = this->value;
        this->value = other.value;
        other.value = temp.value;
        return *this;
    }

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



    friend std::ostream& operator<<(std::ostream& out, const Double& floatNum) {
        out << floatNum.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Double& floatNum) {
        in >> floatNum.value;
        return in;
    }

};

class Boolean {
private:
    bool value;
public:
    Boolean() : value(false) {}

    Boolean(bool value) : value(value) {}

    Boolean(const Boolean& other) : value(other.value) {}

    Boolean(const std::string& value) {
        if(value != "false") {
            this->value = true;
        } else if(value == "false") {
            this->value = false;
        } else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }



    operator bool() {
        return this->value;
    }

    void setValue(bool value) {
        this->value = value;
    }

    bool getValue() const {
        return this->value;
    }

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
        if(value == "true") {
            this->value = true;
            return *this;
        }
        this->value = false;
        return *this;
    }

    Boolean& operator=(const char* value) {
        if(value != "false") {
            this->value = true;
            return *this;
        } 
        this->value = false;
        return *this;
    }

    Boolean& operator=(const char& value) {
        if(value == 'f' || value == '0') {
            this->value = false;
            return *this;
        } 
        this->value = true;
        return *this;
    }

    Boolean& operator=(const int& other) {
        if(other != 0) {
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
        if(other == "true" || other == "1") {
            return this->value == true;
        } else if (other == "false" || other == "0") {
            return this->value == false;
        } else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator==(const char* other) const {
        if(other != "false" || other != "0") {
            return this->value == true;
        }
        return this->value == false;
    }

    bool operator==(const char& other) const {
        if(other == 'f' || other == '0') {
            return this->value == false;
        }
        return this->value == true;
    }

    template<typename type>
    bool operator==(const type& other) const {
        if(other != "false" || other != "0" || other != '0' || other != 'f' || other != 0) {
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
        if(other == "true" || other == "1") {
            return this->value != true;
        } else if (other == "false" || other == "0") {
            return this->value != false;
        } else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator!=(const char* other) const {
        if(other != "false" || other != "0") {
            return this->value != true;
        }
        return this->value != false;
    }

    bool operator!=(const char& other) const {
        if(other == 'f' || other == '0') {
            return this->value != false;
        }
        return this->value != true;
    }

    bool operator!=(const long double& other) const {
        if(other != 0) {
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
        if(other == "true" || other == "1") {
            return this->value && true;
        } else if (other == "false" || other == "0") {
            return this->value && false;
        } else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator&&(const char* other) const {
        if(other != "false" || other != "0") {
            return this->value && true;
        }
        return this->value && false;
    }

    bool operator&&(const char& other) const {
        if(other == 'f' || other == '0') {
            return this->value && false;
        }
        return this->value && true;
    }

    bool operator&&(const long double& other) const {
        if(other != 0) {
            return this->value && true;
        }
        return this->value && false;
    }

    bool operator&&(const int& other) const {
        if(other != 0) {
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
        if(other == "true" || other == "1") {
            return this->value || true;
        } else if (other == "false" || other == "0") {
            return this->value || false;
        } else {
            throw std::invalid_argument("Invalid boolean value");
        }
    }

    bool operator||(const char* other) const {
        if(other != "false" || other != "0") {
            return this->value || true;
        }
        return this->value || false;
    }

    bool operator||(const char& other) const {
        if(other == 'f' || other == '0') {
            return this->value || false;
        }
        return this->value || true;
    }

    bool operator||(const long double& other) const {
        if(other != 0) {
            return this->value || true;
        }
        return this->value || false;
    }



    friend std::ostream& operator<<(std::ostream &out, const Boolean &boolean) {
        if(boolean.value == true) {
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

class String {
private:
    char* value;
    size_t length = 0;

    void copy(const char* other) {
        this->length = strlen(other);
        this->value = new char[this->length + 1];
        for(size_t i = 0; i <= this->length; i++) {
            this->value[i] = other[i];
        }
        this->value[this->length] = '\0';
    }

    bool equalityCompare(const char* other) const {
        for(size_t i = 0; i <= this->length; i++) {
            if(this->value[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    char tolower(const char& other) const {
        if(other >= 'A' && other <= 'Z') {
            return other + 32;
        }
        return other;
    }

    char tolower(char& other) const {
        if(other >= 'A' && other <= 'Z') {
            return other + 32;
        }
        return other;
    }

    char toupper(const char& other) const {
        if(other >= 'a' && other <= 'z') {
            return other - 32;
        }
        return other;
    
    }
    char toupper(char& other) const {
        if(other >= 'a' && other <= 'z') {
            return other - 32;
        }
        return other;
    }

    void reAllocate(size_t newLength) {
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
    }

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

    String(const String& other) {
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

    ~String() {
        delete[] this->value;
    }



    operator std::string() {
        return std::string(this->value);
    }

    operator char*() const {
        return this->value;
    }

    size_t size() const {
        return this->length;
    }

    void setValue(const char* value) {
        this->length = strlen(value);
        this->value = new char[this->length + 1];
        this->copy(value);
        this->value[this->length] = '\0';
    }

    void setValue(const String& other) {
        this->length = other.length;
        this->value = new char[this->length + 1];
        this->copy(other.value);
        this->value[this->length] = '\0';
    }

    char* get() const {
        return this->value;
    }

    char* append(const char* other) {
        size_t newLength = this->length + strlen(other);
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return this->value;
    }

    char* append(const String& other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return this->value;
    }

    char* empty() {
        delete[] this->value;
        this->value = nullptr;
        this->length = 0;
        return this->value;
    }

    char* clear() {
        this->value[0] = '\0';
        return this->value;
    }

    String& erase(const size_t& start, const size_t& end) {
        if(start > end) {
            throw std::invalid_argument("Start index must be smaller than end index");
        }
        if(start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        if(end > this->length) {
            throw std::invalid_argument("End index must be smaller than length of string");
        }
        size_t newLength = this->length - (end - start);
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = start; i <= newLength; i++) {
            newValue[i] = this->value[i + (end - start)];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& erase(const size_t& start) {
        if(start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        size_t newLength = this->length - 1;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = start; i <= newLength; i++) {
            newValue[i] = this->value[i + 1];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& erase(const size_t& start, const size_t& end, const char& replacement) {
        if(start > end) {
            throw std::invalid_argument("Start index must be smaller than end index");
        }
        if(start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        if(end > this->length) {
            throw std::invalid_argument("End index must be smaller than length of string");
        }
        size_t newLength = this->length - (end - start) + 1;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = start; i <= newLength; i++) {
            newValue[i] = replacement;
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& erase(const size_t& start, const char& replacement) {
        if(start > this->length) {
            throw std::invalid_argument("Start index must be smaller than length of string");
        }
        size_t newLength = this->length - 1 + 1;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < start; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = start; i <= newLength; i++) {
            newValue[i] = replacement;
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& joins(const String& other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& joins(const char* other) {
        size_t newLength = this->length + strlen(other);
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& joins(const char& other) {
        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength - 1] = other;
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    char charAt(const size_t& index) const {
        if(index > this->length) {
            throw std::invalid_argument("Index must be smaller than length of string");
        }
        return this->value[index];
    }

    bool startsWith(const String& other) const {
        if(other.length > this->length) {
            return false;
        }
        for(size_t i = 0; i < other.length; i++) {
            if(this->value[i] != other.value[i]) {
                return false;
            }
        }
        return true;
    }

    bool startsWith(const char* other) const {
        size_t otherLength = strlen(other);
        if(otherLength > this->length) {
            return false;
        }
        for(size_t i = 0; i < otherLength; i++) {
            if(this->value[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    bool startsWith(const char& other) const {
        if(this->length < 1) {
            return false;
        }
        if(this->value[0] != other) {
            return false;
        }
        return true;
    }

    bool endsWith(const String& other) const {
        if(other.length > this->length) {
            throw std::invalid_argument("Other string must be smaller than length of string");
        }
        for(size_t i = this->length - other.length; i < this->length; i++) {
            if(this->value[i] != other.value[i - (this->length - other.length)]) {
                return false;
            }
        }
        return true;
    }

    bool endsWith(const char* other) const {
        size_t otherLength = strlen(other);
        if(otherLength > this->length) {
            throw std::invalid_argument("Other string must be smaller than length of string");
        }
        for(size_t i = this->length - otherLength; i < this->length; i++) {
            if(this->value[i] != other[i - (this->length - otherLength)]) {
                return false;
            }
        }
        return true;
    }

    bool endsWith(const char& other) const {
        if(this->length < 1) {
            return false;
        }
        if(this->value[this->length - 1] != other) {
            return false;
        }
        return true;
    }

    String& toLower() {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] >= 'A' && this->value[i] <= 'Z') {
                this->value[i] += 32;
            }
        }
        return *this;
    }

    String& toUpper() {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] >= 'a' && this->value[i] <= 'z') {
                this->value[i] -= 32;
            }
        }
        return *this;
    }

    String& trim() {
        size_t start = 0;
        size_t end = this->length;
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] != ' ' && this->value[i] != '\t' && this->value[i] != '\n' && this->value[i] != '\r') {
                start = i;
                break;
            }
        }
        for(size_t i = this->length - 1; i > 0; i--) {
            if(this->value[i] != ' ' && this->value[i] != '\t' && this->value[i] != '\n' && this->value[i] != '\r') {
                end = i + 1;
                break;
            }
        }
        if(start == 0 && end == this->length) {
            return *this;
        }
        size_t newLength = end - start;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i + start];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& concat(const String& other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other.value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& concat(const char* other) {
        size_t otherLength = strlen(other);
        size_t newLength = this->length + otherLength;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i <= newLength; i++) {
            newValue[i] = other[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& concat(const char& other) {
        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i <= this->length; i++) {
            newValue[i] = this->value[i];
        }
        newValue[newLength - 1] = other;
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    int lastIndexOf(const char& other) const {
        for(int i = this->length - 1; i >= 0; i--) {
            if(this->value[i] == other) {
                return i;
            }
        }
        return -1;
    }

    bool includes(const char& other) const {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other) {
                return true;
            }
        }
        return false;
    }

    bool includes(const String& other) const {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other.value[0]) {
                bool found = true;
                for(size_t j = 0; j < other.length; j++) {
                    if(this->value[i + j] != other.value[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    return true;
                }
            }
        }
        return false;
    }

    bool includes(const char* other) const {
        size_t otherLength = strlen(other);
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other[0]) {
                bool found = true;
                for(size_t j = 0; j < otherLength; j++) {
                    if(this->value[i + j] != other[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    return true;
                }
            }
        }
        return false;
    }

    String& repeat(size_t count) {
        size_t newLength = this->length * count;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i % this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String substring(size_t start, size_t end) const {
        if(start > end) {
            size_t temp = start;
            start = end;
            end = temp;
        }
        if(start > this->length) {
            start = this->length;
        }
        if(end > this->length) {
            end = this->length;
        }
        size_t newLength = end - start;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < newLength; i++) {
            newValue[i] = this->value[i + start];
        }
        newValue[newLength] = '\0';
        String result = newValue;
        delete[] newValue;
        return result;
    }

    String substring(size_t start) const {
        return this->substring(start, this->length);
    }

    String& split(const char& separator, String& result) const {
        size_t start = 0;
        size_t end = 0;
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == separator) {
                end = i;
                result.concat(this->substring(start, end));
                start = i + 1;
            }
        }
        result.concat(this->substring(start));
        return result;
    }

    String& replace(const char& old, const char& newChar) {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == old) {
                this->value[i] = newChar;
            }
        }
        return *this;
    }

    String& replace(const String& old, const String& newString) {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == old.value[0]) {
                bool found = true;
                for(size_t j = 0; j < old.length; j++) {
                    if(this->value[i + j] != old.value[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    this->value[i] = newString.value[0];
                    for(size_t j = 1; j < newString.length; j++) {
                        this->value[i + j] = newString.value[j];
                    }
                    i += newString.length - 1;
                }
            }
        }
        return *this;
    }

    String& replace(const char* old, const char* newString) {
        size_t oldLength = strlen(old);
        size_t newLength = strlen(newString);
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == old[0]) {
                bool found = true;
                for(size_t j = 0; j < oldLength; j++) {
                    if(this->value[i + j] != old[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    this->value[i] = newString[0];
                    for(size_t j = 1; j < newLength; j++) {
                        this->value[i + j] = newString[j];
                    }
                    i += newLength - 1;
                }
            }
        }
        return *this;
    }

    String& replaceFirst(const char& old, const char& newChar) {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == old) {
                this->value[i] = newChar;
                return *this;
            }
        }
        return *this;
    }

    String& replaceFirst(const String& old, const String& newString) {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == old.value[0]) {
                bool found = true;
                for(size_t j = 0; j < old.length; j++) {
                    if(this->value[i + j] != old.value[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    this->value[i] = newString.value[0];
                    for(size_t j = 1; j < newString.length; j++) {
                        this->value[i + j] = newString.value[j];
                    }
                    return *this;
                }
            }
        }
        return *this;
    }

    String& replaceFirst(const char* old, const char* newString) {
        size_t oldLength = strlen(old);
        size_t newLength = strlen(newString);
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == old[0]) {
                bool found = true;
                for(size_t j = 0; j < oldLength; j++) {
                    if(this->value[i + j] != old[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    this->value[i] = newString[0];
                    for(size_t j = 1; j < newLength; j++) {
                        this->value[i + j] = newString[j];
                    }
                    return *this;
                }
            }
        }
        return *this;
    }

    int indexOf(const char& other) const {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other) {
                return i;
            }
        }
        return -1;
    }

    String& swap(String& other) {
        char* temp = this->value;
        this->value = other.value;
        other.value = temp;
        size_t tempLength = this->length;
        this->length = other.length;
        other.length = tempLength;
        return *this;
    }

    bool isEmpty() const {
        if(this->length == 0) {
            return true;
        }
        return false;
    }

    bool compare(const String& other) const {
        if(this->length != other.length) {
            return false;
        }
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] != other.value[i]) {
                return false;
            }
        }
        return true;
    }

    String& forEach(const std::function<void(char&)>& func) {
        for(size_t i = 0; i < this->length; i++) {
            func(this->value[i]);
        }
        return *this;
    }

    bool equalIgnoreCase(const String& other) const {
        if(this->length != other.length) {
            return false;
        }
        for(size_t i = 0; i < this->length; i++) {
            if(this->tolower(this->value[i]) != this->tolower(other.value[i])) {
                return false;
            }
        }
        return true;
    }

    String& reverse() {
        for(size_t i = 0; i < this->length / 2; i++) {
            char temp = this->value[i];
            this->value[i] = this->value[this->length - i - 1];
            this->value[this->length - i - 1] = temp;
        }
        return *this;
    }

    const char* type() const {
        return "String";
    }

    String& capitalize() {
        for(size_t i = 0; i < this->length; i++) {
            if(i == 0) {
                this->value[i] = toupper(this->value[i]);
            } else {
                this->value[i] = tolower(this->value[i]);
            }
        }
        return *this;
    }

    int count(const char& other) const {
        int count = 0;
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other) {
                count++;
            }
        }
        return count;
    }

    int count(const String& other) const {
        int count = 0;
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other.value[0]) {
                bool found = true;
                for(size_t j = 0; j < other.length; j++) {
                    if(this->value[i + j] != other.value[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    count++;
                    i += other.length - 1;
                }
            }
        }
        return count;
    }

    int count(const char* other) const {
        int count = 0;
        size_t otherLength = strlen(other);
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other[0]) {
                bool found = true;
                for(size_t j = 0; j < otherLength; j++) {
                    if(this->value[i + j] != other[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    count++;
                    i += otherLength - 1;
                }
            }
        }
        return count;
    }

    String casefold() const {
        String result = *this;
        for(size_t i = 0; i < this->length; i++) {
            result.value[i] = tolower(this->value[i]);
        }
        return result;
    }

    String& swapCase() {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] >= 'a' && this->value[i] <= 'z') {
                this->value[i] = toupper(this->value[i]);
            } else if(this->value[i] >= 'A' && this->value[i] <= 'Z') {
                this->value[i] = tolower(this->value[i]);
            }
        }
        return *this;
    }

    bool find(const char& other) const {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other) {
                return true;
            }
        }
        return false;
    }

    bool find(const String& other) const {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other.value[0]) {
                bool found = true;
                for(size_t j = 0; j < other.length; j++) {
                    if(this->value[i + j] != other.value[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    return true;
                }
            }
        }
        return false;
    }

    bool find(const char* other) const {
        size_t otherLength = strlen(other);
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] == other[0]) {
                bool found = true;
                for(size_t j = 0; j < otherLength; j++) {
                    if(this->value[i + j] != other[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isAlphabet() const {
        for(size_t i = 0; i < this->length; i++) {
            if(!isalpha(this->value[i])) {
                return false;
            }
        }
        return true;
    }

    bool isNumeric() const {
        for(size_t i = 0; i < this->length; i++) {
            if(!isalnum(this->value[i])) {
                return false;
            }
        }
        return true;
    }

    String& insert(size_t index, const char* other) {
        if(index > this->length) {
            return *this;
        }

        size_t otherLength = strlen(other);
        size_t newLength = this->length + otherLength;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < index; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = 0; i < otherLength; i++) {
            newValue[index + i] = other[i];
        }
        for(size_t i = index; i < this->length; i++) {
            newValue[otherLength + i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& insert(size_t index, const String& other) {
        if(index > this->length) {
            return *this;
        }

        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < index; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = 0; i < other.length; i++) {
            newValue[index + i] = other.value[i];
        }
        for(size_t i = index; i < this->length; i++) {
            newValue[other.length + i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& insert(size_t index, const char& other) {
        if(index > this->length) {
            return *this;
        }

        size_t newLength = this->length + 1;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < index; i++) {
            newValue[i] = this->value[i];
        }
        newValue[index] = other;
        for(size_t i = index; i < this->length; i++) {
            newValue[1 + i] = this->value[i];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    char front() const {
        return this->value[0];
    }

    char back() const {
        return this->value[this->length - 1];
    }

    const char* cString() const {
        return this->value;
    }

    String& removePrefix(const char& other) {
        if(this->value[0] == other) {
            size_t newLength = this->length - 1;
            char* newValue = new char[newLength + 1];
            for(size_t i = 1; i < this->length; i++) {
                newValue[i - 1] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    String& removePrefix(const String& other) {
        if(this->value[0] == other.value[0]) {
            size_t otherLength = other.length;
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for(size_t i = otherLength; i < this->length; i++) {
                newValue[i - otherLength] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    String& removePrefix(const char* other) {
        size_t otherLength = strlen(other);
        if(this->value[0] == other[0]) {
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for(size_t i = otherLength; i < this->length; i++) {
                newValue[i - otherLength] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    String& removeSuffix(const char& other) {
        if(this->value[this->length - 1] == other) {
            size_t newLength = this->length - 1;
            char* newValue = new char[newLength + 1];
            for(size_t i = 0; i < newLength; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    String& removeSuffix(const String& other) {
        if(this->value[this->length - 1] == other.value[other.length - 1]) {
            size_t otherLength = other.length;
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for(size_t i = 0; i < newLength; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    String& removeSuffix(const char* other) {
        size_t otherLength = strlen(other);
        if(this->value[this->length - 1] == other[otherLength - 1]) {
            size_t newLength = this->length - otherLength;
            char* newValue = new char[newLength + 1];
            for(size_t i = 0; i < newLength; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
        return *this;
    }

    bool isLower() const {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] < 'a' || this->value[i] > 'z') {
                return false;
            }
        }
        return true;
    }

    bool isUpper() const {
        for(size_t i = 0; i < this->length; i++) {
            if(this->value[i] < 'A' || this->value[i] > 'Z') {
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

    String& operator=(const String& other) {
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
        for(size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i < newLength; i++) {
            newValue[i] = value[i - this->length];
        }
        newValue[newLength] = '\0';
        delete[] this->value;
        this->value = newValue;
        this->length = newLength;
        return *this;
    }

    String& operator+=(const String& other) {
        size_t newLength = this->length + other.length;
        char* newValue = new char[newLength + 1];
        for(size_t i = 0; i < this->length; i++) {
            newValue[i] = this->value[i];
        }
        for(size_t i = this->length; i < newLength; i++) {
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
        for(size_t i = 0; i < this->length; i++) {
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

    String operator+(const String& other) const {
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
        for(size_t i = 0; i < times - 1; i++) {
            result += *this;
        }
        return result;
    }


    
    bool operator==(const char* other) const {
        return this->equalityCompare(other);
    }

    bool operator==(const String& other) const {
        return this->equalityCompare(other.value);
    }

    bool operator==(const char& other) const {
        return this->value[0] == other;
    }

    bool operator!=(const char* other) const {
        return !this->equalityCompare(other);
    }

    bool operator!=(const String& other) const {
        return !this->equalityCompare(other.value);
    }

    bool operator!=(const char& other) const {
        return this->value[0] != other;
    }
    


    bool operator<(const char* other) const {
        return this->length < strlen(other);
    }

    bool operator<(const String& other) const {
        return this->length < other.length;
    }

    bool operator<(const char& other) const {
        return this->value[0] < other;
    }



    bool operator>(const char* other) const {
        return this->length > strlen(other);
    }

    bool operator>(const String& other) const {
        return this->length > other.length;
    }

    bool operator>(const char& other) const {
        return this->value[0] > other;
    }



    bool operator<=(const char* other) const {
        return this->length <= strlen(other);
    }

    bool operator<=(const String& other) const {
        return this->length <= other.length;
    }

    bool operator<=(const char& other) const {
        return this->value[0] <= other;
    }



    bool operator>=(const char* other) const {
        return this->length >= strlen(other);
    }

    bool operator>=(const String& other) const {
        return this->length >= other.length;
    }

    bool operator>=(const char& other) const {
        return this->value[0] >= other;
    }


    bool operator!() const {
        return this->length == 0;
    }

    bool operator&&(const String& other) const {
        return this->length && other.length;
    }

    bool operator||(const String& other) const {
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



    friend std::ostream& operator<<(std::ostream &out, const String &string) {
        out << string.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, String& string) {
        string.reAllocate(0);
        char c;
        while(in.get(c)) {
            if(c == '\n') {
                break;
            }
            string += c;
        }
        return in;
    }
};

#endif
