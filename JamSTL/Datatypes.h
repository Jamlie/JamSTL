#pragma once

// ! Omar Estietie

#include <iostream>


#ifndef JAMSTL_DATATYPES_H_
#define JAMSTL_DATATYPES_H_

#include <cstring>
#include <functional>
#include <iterator>
#include "type_traits.h"
#include "Macros.h"
#include "Math.h"
#include <cmath>

JAMSTL_NAMESPACE_BEGIN

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
        friend class Boolean;
    public:
        Integer() : value(0) {}

        template<typename Type>
        Integer(const Type& value) {
            this->value = static_cast<int>(value);
        }

        Integer(const char* value) : value(atoi(value)) {}



        Integer& operator=(const Integer& other) {
            this->value = other.value;
            return *this;
        }

        Integer& operator=(const char* other) {
            this->value = atoi(other);
            return *this;
        }

        template<typename Type>
        Integer& operator=(const Type& other) {
            this->value = static_cast<int>(other);
            return *this;
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

        // Max value of an Integer
        static constexpr int MAX_VALUE = 0x7fffffff;
        
        // Min value of an Integer
        static constexpr int MIN_VALUE = 0x80000000;


        /**
         * @brief A method that checks if an Integer is positive, negative or zero
         * 
         * @return Integer 
         */
        Integer signum() {
            if(this->value > 0) {
                return 1;
            }
            else if(value < 0) {
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
            if(this->value < 0) {
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

        operator int() const {
            return value;
        }



        Integer& operator+=(const Integer& other) {
            this->value += other.value;
            return *this;
        }

        template<typename Type>
        Integer& operator+=(const Type& other) {
            this->value += other;
            return *this;
        }   

        Integer& operator+=(const char* other) {
            this->value += atoi(other);
            return *this;
        }



        Integer& operator-=(const Integer& other) {
            this->value -= other.value;
            return *this;
        }

        template<typename Type>
        Integer& operator-=(const Type& other) {
            this->value -= other;
            return *this;
        }

        Integer& operator-=(const char* other) {
            this->value -= atoi(other);
            return *this;
        }



        Integer& operator*=(const Integer& other) {
            this->value *= other.value;
            return *this;
        }

        template<typename Type>
        Integer& operator*=(const Type& other) {
            this->value *= other;
            return *this;
        }

        Integer& operator*=(const char* other) {
            this->value *= atoi(other);
            return *this;
        }



        Integer& operator/=(const Integer& other) {
            this->value /= other.value;
            return *this;
        }

        template<typename Type>
        Integer& operator/=(const Type& other) {
            this->value /= other;
            return *this;
        }

        Integer& operator/=(const char* other) {
            this->value /= atoi(other);
            return *this;
        }



        Integer& operator%=(const Integer& other) {
            this->value %= other.value;
            return *this;
        }

        template<typename Type>
        Integer& operator%=(const Type& other) {
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

        template<typename Type>
        Integer operator+(const Type& other) const {
            return Integer(this->value + other);
        }

        Integer operator+(const char* other) const {
            return Integer(this->value + atoi(other));
        }



        Integer operator-(const Integer& other) const {
            return Integer(this->value - other.value);
        }

        template<typename Type>
        Integer operator-(const Type& other) const {
            return Integer(this->value - other);
        }

        Integer operator-(const char* other) const {
            return Integer(this->value - atoi(other));
        }



        Integer operator*(const Integer& other) const {
            return Integer(this->value * other.value);
        }

        template<typename Type>
        Integer operator*(const Type& other) const {
            return Integer(this->value * other);
        }

        Integer operator*(const char* other) const {
            return Integer(this->value * atoi(other));
        }



        Integer operator/(const Integer& other) const {
            return Integer(this->value / other.value);
        }

        template<typename Type>
        Integer operator/(const Type& other) const {
            return Integer(this->value / other);
        }

        Integer operator/(const char* other) const {
            return Integer(this->value / atoi(other));
        }



        Integer operator%(const Integer& other) const {
            return Integer(this->value % other.value);
        }

        template<typename Type>
        Integer operator%(const Type& other) const {
            return Integer(this->value % other);
        }

        Integer operator%(const char* other) const {
            return Integer(this->value % atoi(other));
        }



        bool operator==(const Integer& other) const {
            return this->value == other.value;
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }

        bool operator==(const char* other) const {
            return this->value == atoi(other);
        }



        bool operator!=(const Integer& other) const {
            return this->value != other.value;
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }
        
        bool operator!=(const char* other) const {
            return this->value != atoi(other);
        }



        bool operator<(const Integer& other) const {
            return this->value < other.value;
        }

        template<typename Type>
        bool operator<(const Type& other) const {
            return this->value < other;
        }

        bool operator<(const char* other) const {
            return this->value < atoi(other);
        }



        bool operator>(const Integer& other) const {
            return this->value > other.value;
        }

        template<typename Type>
        bool operator>(const Type& other) const {
            return this->value > other;
        }

        bool operator>(const char* other) const {
            return this->value > atoi(other);
        }



        bool operator<=(const Integer& other) const {
            return this->value <= other.value;
        }

        template<typename Type>
        bool operator<=(const Type& other) const {
            return this->value <= other;
        }

        bool operator<=(const char* other) const {
            return this->value <= atoi(other);
        }



        bool operator>=(const Integer& other) const {
            return this->value >= other.value;
        }

        template<typename Type>
        bool operator>=(const Type& other) const {
            return this->value >= other;
        }

        bool operator>=(const char* other) const {
            return this->value >= atoi(other);
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

        template<typename Type>
        bool operator&&(const Type& other) const {
            return this->value && other;
        }

        bool operator&&(const char* other) const {
            return this->value && atoi(other);
        }



        bool operator||(const Integer& other) const {
            return this->value || other.value;
        }

        template<typename Type>
        bool operator||(const Type& other) const {
            return this->value || other;
        }



        Integer operator&(const Integer& other) const {
            return Integer(this->value & other.value);
        }

        template<typename Type>
        Integer operator&(const Type& other) const {
            return Integer(this->value & other);
        }

        Integer operator&(const char* other) const {
            return Integer(this->value & atoi(other));
        }



        Integer operator|(const Integer& other) const {
            return Integer(this->value | other.value);
        }

        template<typename Type>
        Integer operator|(const Type& other) const {
            return Integer(this->value | other);
        }

        Integer operator|(const char* other) const {
            return Integer(this->value | atoi(other));
        }



        Integer operator^(const Integer& other) const {
            return Integer(this->value ^ other.value);
        }

        template<typename Type>
        Integer operator^(const Type& other) const {
            return Integer(this->value ^ other);
        }

        Integer operator^(const char* other) const {
            return Integer(this->value ^ atoi(other));
        }



        Integer operator<<(const Integer& other) const {
            return Integer(this->value << other.value);
        }

        template<typename Type>
        Integer operator<<(const Type& other) const {
            return Integer(this->value << other);
        }

        Integer operator<<(const char* other) const {
            return Integer(this->value << atoi(other));
        }



        Integer operator>>(const Integer& other) const {
            return Integer(this->value >> other.value);
        }

        template<typename Type>
        Integer operator>>(const int& other) const {
            return Integer(this->value >> other);
        }

        Integer operator>>(const char* other) const {
            return Integer(this->value >> atoi(other));
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
        short int value;
        friend class Integer;
        friend class Float;
        friend class Double;
        friend class Long;
        friend class Boolean;
    public:
        Short() : value(0) {}

        template<typename Type>
        Short(const Type& value) {
            this->value = static_cast<short int>(value);
        }

        Short(const Short& other) : value(other.value) {}

        Short(const Integer& other) : value(other.value) {}

        Short(const char* other) : value(atoi(other)) {}



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


        // Max value of an Short
        static constexpr short MAX_VALUE = 32767;
        
        // Min value of an Short
        static constexpr short MIN_VALUE = -32768;


        /**
         * @brief A method that checks if a Short is positive, negative or zero
         * 
         * @return Short 
         */
        Short signum() {
            if(this->value > 0) {
                return 1;
            }
            else if(value < 0) {
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
            if(this->value < 0) {
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
        


        Short& operator=(const Short& other) {
            this->value = other.value;
            return *this;
        }

        Short& operator=(const Integer& other) {
            this->value = other.value;
            return *this;
        }

        Short& operator=(const char* other) {
            this->value = atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator=(const Type& other) {
            this->value = static_cast<short int>(other);
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

        Short& operator+=(const char* other) {
            this->value += atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator+=(const Type& other) {
            this->value += other;
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

        Short& operator-=(const char* other) {
            this->value -= atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator-=(const Type& other) {
            this->value -= other;
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

        Short& operator*=(const char* other) {
            this->value *= atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator*=(const Type& other) {
            this->value *= other;
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

        Short& operator/=(const char* other) {
            this->value /= atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator/=(const Type& other) {
            this->value /= other;
            return *this;
        }



        Short& operator%=(const Short& other) {
            this->value %= other.value;
            return *this;
        }

        Short& operator%=(const Integer& other) {
            this->value %= other.value;
            return *this;
        }

        Short& operator%=(const char* other) {
            this->value %= atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator%=(const Type& other) {
            this->value %= other;
            return *this;
        }



        Short& operator&=(const Short& other) {
            this->value &= other.value;
            return *this;
        }

        Short& operator&=(const Integer& other) {
            this->value &= other.value;
            return *this;
        }

        Short& operator&=(const char* other) {
            this->value &= atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator&=(const Type& other) {
            this->value &= other;
            return *this;
        }



        Short& operator|=(const Short& other) {
            this->value |= other.value;
            return *this;
        }

        Short& operator|=(const Integer& other) {
            this->value |= other.value;
            return *this;
        }

        Short& operator|=(const char* other) {
            this->value |= atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator|=(const Type& other) {
            this->value |= other;
            return *this;
        }



        Short& operator^=(const Short& other) {
            this->value ^= other.value;
            return *this;
        }

        Short& operator^=(const Integer& other) {
            this->value ^= other.value;
            return *this;
        }

        Short& operator^=(const char* other) {
            this->value ^= atoi(other);
            return *this;
        }

        template<typename Type>
        Short& operator^=(const Type& other) {
            this->value ^= other;
            return *this;
        }



        Short operator+(const Short& other) const {
            return Short(this->value + other.value);
        }

        Short operator+(const Integer& other) const {
            return Short(this->value + other.value);
        }

        Short operator+(const char* other) const {
            return Short(this->value + atoi(other));
        }

        template<typename Type>
        Short operator+(const Type& other) const {
            return Short(this->value + other);
        }



        Short operator-(const Short& other) const {
            return Short(this->value - other.value);
        }

        Short operator-(const Integer& other) const {
            return Short(this->value - other.value);
        }

        Short operator-(const char* other) const {
            return Short(this->value - atoi(other));
        }

        template<typename Type>
        Short operator-(const Type& other) const {
            return Short(this->value - other);
        }



        Short operator*(const Short& other) const {
            return Short(this->value * other.value);
        }

        Short operator*(const Integer& other) const {
            return Short(this->value * other.value);
        }

        Short operator*(const char* other) const {
            return Short(this->value * atoi(other));
        }

        template<typename Type>
        Short operator*(const Type& other) const {
            return Short(this->value * other);
        }



        Short operator/(const Short& other) const {
            return Short(this->value / other.value);
        }

        Short operator/(const Integer& other) const {
            return Short(this->value / other.value);
        }

        Short operator/(const char* other) const {
            return Short(this->value / atoi(other));
        }

        template<typename Type>
        Short operator/(const Type& other) const {
            return Short(this->value / other);
        }



        Short operator%(const Short& other) const {
            return Short(this->value % other.value);
        }

        Short operator%(const Integer& other) const {
            return Short(this->value % other.value);
        }

        Short operator%(const char* other) const {
            return Short(this->value % atoi(other));
        }

        template<typename Type>
        Short operator%(const Type& other) const {
            return Short(this->value % other);
        }



        Short operator&(const Short& other) const {
            return Short(this->value & other.value);
        }

        Short operator&(const Integer& other) const {
            return Short(this->value & other.value);
        }

        Short operator&(const char* other) const {
            return Short(this->value & atoi(other));
        }

        template<typename Type>
        Short operator&(const Type& other) const {
            return Short(this->value & other);
        }



        Short operator|(const Short& other) const {
            return Short(this->value | other.value);
        }

        Short operator|(const Integer& other) const {
            return Short(this->value | other.value);
        }

        Short operator|(const char* other) const {
            return Short(this->value | atoi(other));
        }

        template<typename Type>
        Short operator|(const Type& other) const {
            return Short(this->value | other);
        }



        Short operator^(const Short& other) const {
            return Short(this->value ^ other.value);
        }

        Short operator^(const Integer& other) const {
            return Short(this->value ^ other.value);
        }

        Short operator^(const char* other) const {
            return Short(this->value ^ atoi(other));
        }

        template<typename Type>
        Short operator^(const Type& other) const {
            return Short(this->value ^ other);
        }



        bool operator==(const Short& other) const {
            return this->value == other.value;
        }

        bool operator==(const Integer& other) const {
            return this->value == other.value;
        }

        bool operator==(const char* other) const {
            return this->value == atoi(other);
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }



        bool operator!=(const Short& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Integer& other) const {
            return this->value != other.value;
        }

        bool operator!=(const char* other) const {
            return this->value != atoi(other);
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }



        bool operator<(const Short& other) const {
            return this->value < other.value;
        }

        bool operator<(const Integer& other) const {
            return this->value < other.value;
        }

        bool operator<(const char* other) const {
            return this->value < atoi(other);
        }

        template<typename Type>
        bool operator<(const Type& other) const {
            return this->value < other;
        }



        bool operator<=(const Short& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const Integer& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const char* other) const {
            return this->value <= atoi(other);
        }

        template<typename Type>
        bool operator<=(const Type& other) const {
            return this->value <= other;
        }



        bool operator>(const Short& other) const {
            return this->value > other.value;
        }

        bool operator>(const Integer& other) const {
            return this->value > other.value;
        }

        bool operator>(const char* other) const {
            return this->value > atoi(other);
        }

        template<typename Type>
        bool operator>(const Type& other) const {
            return this->value > other;
        }



        bool operator>=(const Short& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const Integer& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const char* other) const {
            return this->value >= atoi(other);
        }

        template<typename Type>
        bool operator>=(const Type& other) const {
            return this->value >= other;
        }



        Short operator<<(const Short& other) const {
            return Short(this->value << other.value);
        }

        Short operator<<(const Integer& other) const {
            return Short(this->value << other.value);
        }

        Short operator<<(const char* other) const {
            return Short(this->value << atoi(other));
        }

        template<typename Type>
        Short operator<<(const Type& other) const {
            return Short(this->value << other);
        }



        Short operator>>(const Short& other) const {
            return Short(this->value >> other.value);
        }

        Short operator>>(const Integer& other) const {
            return Short(this->value >> other.value);
        }

        Short operator>>(const char* other) const {
            return Short(this->value >> atoi(other));
        }

        template<typename Type>
        Short operator>>(const Type& other) const {
            return Short(this->value >> other);
        }



        Short operator~() const {
            return Short(~this->value);
        }

        Short operator-() const {
            return Short(-this->value);
        }

        Short operator++() {
            this->value++;
            return *this;
        }

        Short operator++(int) {
            Short tmp = *this;
            this->value++;
            return tmp;
        }

        Short operator--() {
            this->value--;
            return *this;
        }

        Short operator--(int) {
            Short tmp = *this;
            this->value--;
            return tmp;
        }



        bool operator!() const {
            return Short(!this->value);
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
     * @brief A long long wrapper class
     * 
     */
    class Long {
    private:
        long long value;
        friend class Integer;
        friend class Short;
        friend class Float;
        friend class Double;
        friend class Boolean;
    public:
        Long() : value(0) {}
        Long(const Long& other) : value(other.value) {}
        Long(const Integer& other) : value(other.value) {}
        Long(const Short& other) : value(other.value) {}
        template<typename Type>
        Long(const Type& other) {
            this->value = static_cast<long long>(other);
        }
        Long(const char* other) : value(atoi(other)) {}


        Long& operator=(const Long& other) {
            this->value = other.value;
            return *this;
        }

        Long& operator=(const Integer& other) {
            this->value = other.value;
            return *this;
        }

        Long& operator=(const Short& other) {
            this->value = other.value;
            return *this;
        }

        Long& operator=(const char* other) {
            this->value = atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator=(const Type& other) {
            this->value = static_cast<long long>(other);
            return *this;
        }


        /**
         * @brief A method that reverses the order of the digits of a Long
         * 
         * @return Long& 
         */
        Long& reverse() {
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
         * @brief A method that converts a String to a Long
         * 
         * @param string 
         * @return Long& 
         */
        Long& parseLong(const char* string) {
            value = atoi(string);
            return *this;
        }

        /**
         * @brief A method that returns the number of digits of a given Long
         * 
         * @return Long 
         */
        Long length() {
            int length = 0;
            int original = value;
            while (original != 0) {
                original /= 10;
                length++;
            }
            return length;
        }

        /**
         * @brief A method that returns the type of a Long
         * 
         * @return const char* 
         */
        const char* type() const {
            return "Integer";
        }

        // Max value of a Long
        static constexpr long long MAX_VALUE = 0x7fffffffffffffffLL;

        // Min value of a Long
        static constexpr long long MIN_VALUE = -0x8000000000000000LL;



        /**
         * @brief A method that checks if a Long is positive, negative or zero
         * 
         * @return Long 
         */
        Long signum() {
            if(this->value > 0) {
                return 1;
            }
            else if(value < 0) {
                return -1;
            }
            else {
                return 0;
            }
        }

        /**
         * @brief Absolute value of a Long
         * 
         * @return Long& 
         */
        Long& abs() {
            if(this->value < 0) {
                this->value = -this->value;
            }
            return *this;
        }

        /**
         * @brief Make a Long negative
         * 
         * @return Long& 
         */
        Long& negate() {
            this->value = -this->value;
            return *this;
        }

        /**
         * @brief A method that adds two Longs
         * 
         * @param other 
         * @return Long& 
         */
        Long& add(const Long& other) {
            this->value += other.value;
            return *this;
        }

        /**
         * @brief A method that adds two longs
         * 
         * @param other 
         * @return Long& 
         */
        Long& add(const long long& other) {
            this->value += other;
            return *this;
        }

        /**
         * @brief A method that adds two numbers
         * 
         * @param other 
         * @return Long& 
         */
        Long& add(const float& other) {
            this->value += other;
            return *this;
        }

        /**
         * @brief A method that swaps the value of two Longs
         * 
         * @param other 
         * @return Long& 
         */
        Long& swap(Long& other) {
            Long temp;
            temp.value = this->value;
            this->value = other.value;
            other.value = temp.value;
            return *this;
        }

        /**
         * @brief A method that swaps the value of Long and another type
         * 
         * @tparam T 
         * @param other 
         * @return Long& 
         */
        template <typename T>
        Long& swap(T& other) {
            Long temp;
            temp.value = this->value;
            this->value = other;
            other = temp.value;
            return *this;
        }



        Long operator+(const Long& other) const {
            return this->value + other.value;
        }

        Long operator+(const Integer& other) const {
            return this->value + other.value;
        }

        Long operator+(const Short& other) const {
            return this->value + other.value;
        }

        Long operator+(const char* other) const {
            return this->value + atoi(other);
        }

        template<typename Type>
        Long operator+(const Type& other) const {
            return this->value + other;
        }



        Long operator-(const Long& other) const {
            return this->value - other.value;
        }

        Long operator-(const Integer& other) const {
            return this->value - other.value;
        }

        Long operator-(const Short& other) const {
            return this->value - other.value;
        }

        Long operator-(const char* other) const {
            return this->value - atoi(other);
        }

        template<typename Type>
        Long operator-(const Type& other) const {
            return this->value - other;
        }



        Long operator*(const Long& other) const {
            return this->value * other.value;
        }

        Long operator*(const Integer& other) const {
            return this->value * other.value;
        }

        Long operator*(const Short& other) const {
            return this->value * other.value;
        }

        Long operator*(const char* other) const {
            return this->value * atoi(other);
        }

        template<typename Type>
        Long operator*(const Type& other) const {
            return this->value * other;
        }
        


        Long operator/(const Long& other) const {
            return this->value / other.value;
        }

        Long operator/(const Integer& other) const {
            return this->value / other.value;
        }

        Long operator/(const Short& other) const {
            return this->value / other.value;
        }

        Long operator/(const char* other) const {
            return this->value / atoi(other);
        }

        template<typename Type>
        Long operator/(const Type& other) const {
            return this->value / other;
        }



        Long operator%(const Long& other) const {
            return this->value % other.value;
        }

        Long operator%(const Integer& other) const {
            return this->value % other.value;
        }

        Long operator%(const Short& other) const {
            return this->value % other.value;
        }

        Long operator%(const char* other) const {
            return this->value % atoi(other);
        }

        template<typename Type>
        Long operator%(const Type& other) const {
            return this->value % other;
        }
        


        Long operator&(const Long& other) const {
            return this->value & other.value;
        }

        Long operator&(const Integer& other) const {
            return this->value & other.value;
        }

        Long operator&(const Short& other) const {
            return this->value & other.value;
        }

        Long operator&(const char* other) const {
            return this->value & atoi(other);
        }

        template<typename Type>
        Long operator&(const Type& other) const {
            return this->value & other;
        }
        


        Long operator|(const Long& other) const {
            return this->value | other.value;
        }

        Long operator|(const Integer& other) const {
            return this->value | other.value;
        }

        Long operator|(const Short& other) const {
            return this->value | other.value;
        }

        Long operator|(const char* other) const {
            return this->value | atoi(other);
        }

        template<typename Type>
        Long operator|(const Type& other) const {
            return this->value | other;
        }
        


        Long operator^(const Long& other) const {
            return this->value ^ other.value;
        }

        Long operator^(const Integer& other) const {
            return this->value ^ other.value;
        }

        Long operator^(const Short& other) const {
            return this->value ^ other.value;
        }

        Long operator^(const char* other) const {
            return this->value ^ atoi(other);
        }

        template<typename Type>
        Long operator^(const Type& other) const {
            return this->value ^ other;
        }

        

        Long operator<<(const Long& other) const {
            return this->value << other.value;
        }

        Long operator<<(const Integer& other) const {
            return this->value << other.value;
        }

        Long operator<<(const Short& other) const {
            return this->value << other.value;
        }

        Long operator<<(const char* other) const {
            return this->value << atoi(other);
        }

        template<typename Type>
        Long operator<<(const Type& other) const {
            return this->value << other;
        }



        Long operator>>(const Long& other) const {
            return this->value >> other.value;
        }

        Long operator>>(const Integer& other) const {
            return this->value >> other.value;
        }

        Long operator>>(const Short& other) const {
            return this->value >> other.value;
        }

        Long operator>>(const char* other) const {
            return this->value >> atoi(other);
        }

        template<typename Type>
        Long operator>>(const Type& other) const {
            return this->value >> other;
        }
        


        Long operator~() const {
            return ~this->value;
        }



        Long& operator+=(const Long& other) {
            this->value += other.value;
            return *this;
        }

        Long& operator+=(const Integer& other) {
            this->value += other.value;
            return *this;
        }

        Long& operator+=(const Short& other) {
            this->value += other.value;
            return *this;
        }

        Long& operator+=(const char* other) {
            this->value += atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator+=(const Type& other) {
            this->value += other;
            return *this;
        }
        


        Long& operator-=(const Long& other) {
            this->value -= other.value;
            return *this;
        }

        Long& operator-=(const Integer& other) {
            this->value -= other.value;
            return *this;
        }

        Long& operator-=(const Short& other) {
            this->value -= other.value;
            return *this;
        }

        Long& operator-=(const char* other) {
            this->value -= atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator-=(const Type& other) {
            this->value -= other;
            return *this;
        }
        


        Long& operator*=(const Long& other) {
            this->value *= other.value;
            return *this;
        }

        Long& operator*=(const Integer& other) {
            this->value *= other.value;
            return *this;
        }

        Long& operator*=(const Short& other) {
            this->value *= other.value;
            return *this;
        }

        Long& operator*=(const char* other) {
            this->value *= atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator*=(const Type& other) {
            this->value *= other;
            return *this;
        }



        Long& operator/=(const Long& other) {
            this->value /= other.value;
            return *this;
        }

        Long& operator/=(const Integer& other) {
            this->value /= other.value;
            return *this;
        }

        Long& operator/=(const Short& other) {
            this->value /= other.value;
            return *this;
        }

        Long& operator/=(const char* other) {
            this->value /= atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator/=(const Type& other) {
            this->value /= other;
            return *this;
        }
        


        Long& operator%=(const Long& other) {
            this->value %= other.value;
            return *this;
        }

        Long& operator%=(const Integer& other) {
            this->value %= other.value;
            return *this;
        }

        Long& operator%=(const Short& other) {
            this->value %= other.value;
            return *this;
        }

        Long& operator%=(const char* other) {
            this->value %= atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator%=(const Type& other) {
            this->value %= other;
            return *this;
        }
        


        Long& operator&=(const Long& other) {
            this->value &= other.value;
            return *this;
        }

        Long& operator&=(const Integer& other) {
            this->value &= other.value;
            return *this;
        }

        Long& operator&=(const Short& other) {
            this->value &= other.value;
            return *this;
        }

        Long& operator&=(const char* other) {
            this->value &= atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator&=(const Type& other) {
            this->value &= other;
            return *this;
        }
        


        Long& operator|=(const Long& other) {
            this->value |= other.value;
            return *this;
        }

        Long& operator|=(const Integer& other) {
            this->value |= other.value;
            return *this;
        }

        Long& operator|=(const Short& other) {
            this->value |= other.value;
            return *this;
        }

        Long& operator|=(const char* other) {
            this->value |= atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator|=(const Type& other) {
            this->value |= other;
            return *this;
        }
        


        Long& operator^=(const Long& other) {
            this->value ^= other.value;
            return *this;
        }

        Long& operator^=(const Integer& other) {
            this->value ^= other.value;
            return *this;
        }

        Long& operator^=(const Short& other) {
            this->value ^= other.value;
            return *this;
        }

        Long& operator^=(const char* other) {
            this->value ^= atoi(other);
            return *this;
        }

        template<typename Type>
        Long& operator^=(const Type& other) {
            this->value ^= other;
            return *this;
        }
        


        bool operator==(const Long& other) const {
            return this->value == other.value;
        }

        bool operator==(const Integer& other) const {
            return this->value == other.value;
        }

        bool operator==(const Short& other) const {
            return this->value == other.value;
        }

        bool operator==(const char* other) const {
            return this->value == atoi(other);
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }
        


        bool operator!=(const Long& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Integer& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Short& other) const {
            return this->value != other.value;
        }

        bool operator!=(const char* other) const {
            return this->value != atoi(other);
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }
        


        bool operator<(const Long& other) const {
            return this->value < other.value;
        }

        bool operator<(const Integer& other) const {
            return this->value < other.value;
        }

        bool operator<(const Short& other) const {
            return this->value < other.value;
        }

        bool operator<(const char* other) const {
            return this->value < atoi(other);
        }

        template<typename Type>
        bool operator<(const Type& other) const {
            return this->value < other;
        }
        


        bool operator<=(const Long& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const Integer& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const Short& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const char* other) const {
            return this->value <= atoi(other);
        }

        template<typename Type>
        bool operator<=(const Type& other) const {
            return this->value <= other;
        }
        


        bool operator>(const Long& other) const {
            return this->value > other.value;
        }

        bool operator>(const Integer& other) const {
            return this->value > other.value;
        }

        bool operator>(const Short& other) const {
            return this->value > other.value;
        }

        bool operator>(const char* other) const {
            return this->value > atoi(other);
        }

        template<typename Type>
        bool operator>(const Type& other) const {
            return this->value > other;
        }
        


        bool operator>=(const Long& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const Integer& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const Short& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const char* other) const {
            return this->value >= atoi(other);
        }

        template<typename Type>
        bool operator>=(const Type& other) const {
            return this->value >= other;
        }
        


        bool operator!() const {
            return !this->value;
        }

        bool operator&&(const Long& other) const {
            return this->value && other.value;
        }

        bool operator&&(const Integer& other) const {
            return this->value && other.value;
        }

        bool operator&&(const Short& other) const {
            return this->value && other.value;
        }

        bool operator&&(const char* other) const {
            return this->value && atoi(other);
        }

        template<typename Type>
        bool operator&&(const Type& other) const {
            return this->value && other;
        }
        


        bool operator||(const Long& other) const {
            return this->value || other.value;
        }

        bool operator||(const Integer& other) const {
            return this->value || other.value;
        }

        bool operator||(const Short& other) const {
            return this->value || other.value;
        }

        bool operator||(const char* other) const {
            return this->value || atoi(other);
        }

        template<typename Type>
        bool operator||(const Type& other) const {
            return this->value || other;
        }
        


        operator long long() const {
            return this->value;
        }



        friend std::ostream& operator<<(std::ostream& os, const Long& longLong) {
            os << longLong.value;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Long& longLong) {
            is >> longLong.value;
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
        friend class Boolean;
    public:
        Float() : value(0) {}

        Float(const Integer& integer) : value(integer.value) {}

        Float(const Short& SHORT) : value(SHORT.value) {}

        Float(const Long& LONG) : value(LONG.value) {}

        template<typename Type>
        Float(const Type& other) {
            this->value = static_cast<float>(other);
        }

        Float(const char* other) : value(atof(other)) {}



        Float& operator=(const Float& other) {
            this->value = other.value;
            return *this;
        }

        Float& operator=(const Integer& other) {
            this->value = other.value;
            return *this;
        }

        Float& operator=(const Short& other) {
            this->value = other.value;
            return *this;
        }

        Float& operator=(const Long& other) {
            this->value = other.value;
            return *this;
        }

        template<typename Type>
        Float& operator=(const Type& other) {
            this->value = static_cast<float>(other);
            return *this;
        }

        Float& operator=(const char* other) {
            this->value = atof(other);
            return *this;
        }


        // Positive Infinity
        // static constexpr float POSITIVE_INFINITY = 1.0f / 0.0f;

        // // Negative Infinity
        // static constexpr float NEGATIVE_INFINITY = -1.0f / 0.0f;

        // Not a Number
        // static constexpr float NaN               = 0.0f / 0.0f;

        // Max value of a float
        static constexpr float MAX_VALUE         = 0x1.fffffeP+127f;  // 3.4028235e+38f

        // A constant holding the smallest positive normal value of type float
        static constexpr float MIN_NORMAL        = 0x1.0p-126f;       // 1.17549435e-38f

        // Min value of a float
        static constexpr float MIN_VALUE         = 0x0.000002P-126f; // 1.4e-45f


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
            if(this->value > 0) {
                return 1;
            }
            else if(this->value < 0) {
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
            if(this->value < 0) {
                this->value = -this->value;
            }
            return *this;
        }

        

        /**
         * @brief A method that returns the floor value of an object
         * 
         * @return long long 
         */
        long long floor() {
            long long result;
            if(this->value < 0) {
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
            if(this->value - (long long)this->value == 0) return this->value;
            return this->floor() + 1;
        }

        /**
         * @brief A method that returns the round value of an object
         * 
         * @return long long 
         */
        long long round() {
            if(this->value - (long long)this->value == 0) return this->value;
            double number = this->value - (long long)this->value;
            long long result = 0;
            if(this->value < 0) {
                double negativeValue = this->value - (long long)this->value;
                if(negativeValue <= -0.5 && negativeValue > -1) result = this->floor();
                else if(negativeValue > -0.5 && negativeValue < 0) result = this->ceil();
                return result;
            }
            if(number >= 0.5 && number < 1) result = this->ceil();
            else if(number < 0.5 && number > 0) result = this->floor();
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

        operator float() const {
            return value;
        }



        Float& operator+=(const Float& other) {
            this->value += other.value;
            return *this;
        }

        Float& operator+=(const Integer& other) {
            this->value += other.value;
            return *this;
        }

        Float& operator+=(const Short& other) {
            this->value += other.value;
            return *this;
        }

        Float& operator+=(const Long& other) {
            this->value += other.value;
            return *this;
        }
        
        Float& operator+=(const char* other) {
            this->value += atof(other);
            return *this;
        }

        template<typename Type>
        Float& operator+=(const Type& other) {
            this->value += other;
            return *this;
        }



        Float& operator-=(const Float& other) {
            this->value -= other.value;
            return *this;
        }

        Float& operator-=(const Integer& other) {
            this->value -= other.value;
            return *this;
        }

        Float& operator-=(const Short& other) {
            this->value -= other.value;
            return *this;
        }

        Float& operator-=(const Long& other) {
            this->value -= other.value;
            return *this;
        }

        Float& operator-=(const char* other) {
            this->value -= atof(other);
            return *this;
        }

        template<typename Type>
        Float& operator-=(const Type& other) {
            this->value -= other;
            return *this;
        }



        Float& operator*=(const Float& other) {
            this->value *= other.value;
            return *this;
        }

        Float& operator*=(const Integer& other) {
            this->value *= other.value;
            return *this;
        }

        Float& operator*=(const Short& other) {
            this->value *= other.value;
            return *this;
        }

        Float& operator*=(const Long& other) {
            this->value *= other.value;
            return *this;
        }

        Float& operator*=(const char* other) {
            this->value *= atof(other);
            return *this;
        }

        template<typename Type>
        Float& operator*=(const Type& other) {
            this->value *= other;
            return *this;
        }



        Float& operator/=(const Float& other) {
            this->value /= other.value;
            return *this;
        }

        Float& operator/=(const Integer& other) {
            this->value /= other.value;
            return *this;
        }

        Float& operator/=(const Short& other) {
            this->value /= other.value;
            return *this;
        }

        Float& operator/=(const Long& other) {
            this->value /= other.value;
            return *this;
        }

        Float& operator/=(const char* other) {
            this->value /= atof(other);
            return *this;
        }

        template<typename Type>
        Float& operator/=(const Type& other) {
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

        Float operator+(const Integer& other) const {
            return Float(this->value + other.value);
        }

        Float operator+(const Short& other) const {
            return Float(this->value + other.value);
        }

        Float operator+(const Long& other) const {
            return Float(this->value + other.value);
        }

        Float operator+(const char* other) const {
            return Float(this->value + atof(other));
        }

        template<typename Type>
        Float operator+(const Type& other) const {
            return Float(this->value + other);
        }



        Float operator-(const Float& other) const {
            return Float(this->value - other.value);
        }

        Float operator-(const Integer& other) const {
            return Float(this->value - other.value);
        }

        Float operator-(const Short& other) const {
            return Float(this->value - other.value);
        }

        Float operator-(const Long& other) const {
            return Float(this->value - other.value);
        }

        Float operator-(const char* other) const {
            return Float(this->value - atof(other));
        }

        template<typename Type>
        Float operator-(const Type& other) const {
            return Float(this->value - other);
        }



        Float operator*(const Float& other) const {
            return Float(this->value * other.value);
        }

        Float operator*(const Integer& other) const {
            return Float(this->value * other.value);
        }

        Float operator*(const Short& other) const {
            return Float(this->value * other.value);
        }

        Float operator*(const Long& other) const {
            return Float(this->value * other.value);
        }

        Float operator*(const char* other) const {
            return Float(this->value * atof(other));
        }

        template<typename Type>
        Float operator*(const Type& other) const {
            return Float(this->value * other);
        }



        Float operator/(const Float& other) const {
            return Float(this->value / other.value);
        }

        Float operator/(const Integer& other) const {
            return Float(this->value / other.value);
        }

        Float operator/(const Short& other) const {
            return Float(this->value / other.value);
        }

        Float operator/(const Long& other) const {
            return Float(this->value / other.value);
        }

        Float operator/(const char* other) const {
            return Float(this->value / atof(other));
        }

        template<typename Type>
        Float operator/(const Type& other) const {
            return Float(this->value / other);
        }



        bool operator==(const Float& other) const {
            return this->value == other.value;
        }

        bool operator==(const Integer& other) const {
            return this->value == other.value;
        }

        bool operator==(const Short& other) const {
            return this->value == other.value;
        }

        bool operator==(const Long& other) const {
            return this->value == other.value;
        }

        bool operator==(const char* other) const {
            return this->value == atof(other);
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }



        bool operator!=(const Float& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Integer& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Short& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Long& other) const {
            return this->value != other.value;
        }

        bool operator!=(const char* other) const {
            return this->value != atof(other);
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }
        


        bool operator<(const Float& other) const {
            return this->value < other.value;
        }

        bool operator<(const Integer& other) const {
            return this->value < other.value;
        }

        bool operator<(const Short& other) const {
            return this->value < other.value;
        }

        bool operator<(const Long& other) const {
            return this->value < other.value;
        }

        bool operator<(const char* other) const {
            return this->value < atof(other);
        }

        template<typename Type>
        bool operator<(const Type& other) const {
            return this->value < other;
        }



        bool operator>(const Float& other) const {
            return this->value > other.value;
        }

        bool operator>(const Integer& other) const {
            return this->value > other.value;
        }

        bool operator>(const Short& other) const {
            return this->value > other.value;
        }

        bool operator>(const Long& other) const {
            return this->value > other.value;
        }

        bool operator>(const char* other) const {
            return this->value > atof(other);
        }

        template<typename Type>
        bool operator>(const Type& other) const {
            return this->value > other;
        }
        


        bool operator<=(const Float& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const Integer& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const Short& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const Long& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const char* other) const {
            return this->value <= atof(other);
        }

        template<typename Type>
        bool operator<=(const Type& other) const {
            return this->value <= other;
        }
        


        bool operator>=(const Float& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const Integer& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const Short& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const Long& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const char* other) const {
            return this->value >= atof(other);
        }

        template<typename Type>
        bool operator>=(const Type& other) const {
            return this->value >= other;
        }



        bool operator!() const {
            return !this->value;
        }



        bool operator&&(const Float& other) const {
            return this->value && other.value;
        }

        bool operator&&(const Integer& other) const {
            return this->value && other.value;
        }

        bool operator&&(const Short& other) const {
            return this->value && other.value;
        }

        bool operator&&(const Long& other) const {
            return this->value && other.value;
        }

        bool operator&&(const char* other) const {
            return this->value && atof(other);
        }

        template<typename Type>
        bool operator&&(const Type& other) const {
            return this->value && other;
        }



        bool operator||(const Float& other) const {
            return this->value || other.value;
        }

        bool operator||(const Integer& other) const {
            return this->value || other.value;
        }

        bool operator||(const Short& other) const {
            return this->value || other.value;
        }

        bool operator||(const Long& other) const {
            return this->value || other.value;
        }

        bool operator||(const char* other) const {
            return this->value || atof(other);
        }

        template<typename Type>
        bool operator||(const Type& other) const {
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
        friend class Boolean;
    public:
        Double() : value(0) {}

        Double(const Integer& integer) : value(integer.value) {}

        Double(const Float& floatNum) : value(floatNum.value) {}

        Double(const Double& other) : value(other.value) {}

        Double(const Short& shortNum) : value(shortNum.value) {}

        Double(const Long& other) : value(other.value) {}

        Double(const char* other) : value(atof(other)) {}

        template<typename Type>
        Double(const Type& other) {
            this->value = static_cast<double>(other);
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

        Double& operator=(const Short& other) {
            this->value = other.value;
            return *this;
        }

        Double& operator=(const Long& other) {
            this->value = other.value;
            return *this;
        }

        Double& operator=(const char* other) {
            this->value = atof(other);
            return *this;
        }

        template<typename Type>
        Double& operator=(const Type& other) {
            this->value = static_cast<double>(other);
            return *this;
        }

        // Positive Infinity
        // static constexpr double POSITIVE_INFINITY = 1.0 / 0.0;
        
        // Negative Infinity
        // static constexpr double NEGATIVE_INFINITY = -1.0 / 0.0;

        // Not a number
        // static constexpr double NaN               = 0.0 / 0.0;

        // Max value of a double 1.7976931348623157e+308
        static constexpr double MAX_VALUE         = 0x1.fffffffffffffP+1023; 

        // A constant holding the smallest positive normal value of type
        // double. It is the value closest to zero that is greater than zero.
        static constexpr double MIN_NORMAL        = 0x1.0p-1022; // 2.2250738585072014E-308

        // Min value of a double.
        static constexpr double MIN_VALUE         = 0x0.0000000000001P-1022; // 4.9e-324



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
            if(this->value < 0) {
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
            this->value = Math.Trunc(this->value);
            return *this;
        }

        /**
        * @brief The long value of the object
        * 
        * @return Double& 
        */
        Double& longValue() {
            this->value = Math.Trunc(this->value);
            return *this;
        }

        /**
        * @brief A method that returns the floor value of the double.
        * 
        * @return long long 
        */
        long long floor() {
            long long result;
            if(this->value < 0) {
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
            if(this->value - (long long)this->value == 0) return this->value;
            return this->floor() + 1;
        }

        /**
        * @brief A method that returns the round of the double
        * 
        * @return long long 
        */
        long long round() {
            if(this->value - (long long)this->value == 0) return this->value;
            double number = this->value - (long long)this->value;
            long long result = 0;
            if(this->value < 0) {
                double negativeValue = this->value - (long long)this->value;
                if(negativeValue <= -0.5 && negativeValue > -1) result = this->floor();
                else if(negativeValue > -0.5 && negativeValue < 0) result = this->ceil();
                return result;
            }
            if(number >= 0.5 && number < 1) result = this->ceil();
            else if(number < 0.5 && number > 0) result = this->floor();
            return result;
        }

        /**
        * @brief A method that checks if the double is positive, negative or zero.
        * 
        * @return Double& 
        */
        Double& signum() {
            if(this->value < 0) {
                this->value = -1;
            }
            else if(this->value > 0) {
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

        operator double() const {
            return this->value;
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

        Double& operator+=(const Short& other) {
            this->value += other.value;
            return *this;
        }

        Double& operator+=(const Long& other) {
            this->value += other.value;
            return *this;
        }

        template<typename Type>
        Double& operator+=(const Type& other) {
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

        Double& operator-=(const Short& other) {
            this->value -= other.value;
            return *this;
        }

        Double& operator-=(const Long& other) {
            this->value -= other.value;
            return *this;
        }

        template<typename Type>
        Double& operator-=(const Type& other) {
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

        Double& operator*=(const Short& other) {
            this->value *= other.value;
            return *this;
        }

        Double& operator*=(const Long& other) {
            this->value *= other.value;
            return *this;
        }

        template<typename Type>
        Double& operator*=(const Type& other) {
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

        Double& operator/=(const Short& other) {
            this->value /= other.value;
            return *this;
        }

        Double& operator/=(const Long& other) {
            this->value /= other.value;
            return *this;
        }

        template<typename Type>
        Double& operator/=(const Type& other) {
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

        Double operator+(const Short& other) const {
            return Double(this->value + other.value);
        }

        Double operator+(const Long& other) const {
            return Double(this->value + other.value);
        }

        template<typename Type>
        Double operator+(const Type& other) const {
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

        Double operator-(const Short& other) const {
            return Double(this->value - other.value);
        }

        Double operator-(const Long& other) const {
            return Double(this->value - other.value);
        }

        template<typename Type>
        Double operator-(const Type& other) const {
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

        Double operator*(const Short& other) const {
            return Double(this->value * other.value);
        }

        Double operator*(const Long& other) const {
            return Double(this->value * other.value);
        }

        template<typename Type>
        Double operator*(const Type& other) const {
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

        Double operator/(const Short& other) const {
            return Double(this->value / other.value);
        }

        Double operator/(const Long& other) const {
            return Double(this->value / other.value);
        }

        template<typename Type>
        Double operator/(const Type& other) const {
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

        bool operator==(const Short& other) const {
            return this->value == other.value;
        }

        bool operator==(const Long& other) const {
            return this->value == other.value;
        }

        template<typename Type>
        bool operator==(const Type& other) const {
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

        bool operator!=(const Short& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Long& other) const {
            return this->value != other.value;
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
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

        bool operator<(const Short& other) const {
            return this->value < other.value;
        }

        bool operator<(const Long& other) const {
            return this->value < other.value;
        }
        
        template<typename Type>
        bool operator<(const Type& other) const {
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

        bool operator>(const Short& other) const {
            return this->value > other.value;
        }

        bool operator>(const Long& other) const {
            return this->value > other.value;
        }

        template<typename Type>
        bool operator>(const Type& other) const {
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

        bool operator<=(const Short& other) const {
            return this->value <= other.value;
        }

        bool operator<=(const Long& other) const {
            return this->value <= other.value;
        }

        template<typename Type>
        bool operator<=(const Type& other) const {
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

        bool operator>=(const Short& other) const {
            return this->value >= other.value;
        }

        bool operator>=(const Long& other) const {
            return this->value >= other.value;
        }

        template<typename Type>
        bool operator>=(const Type& other) const {
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

        bool operator&&(const Short& other) const {
            return this->value && other.value;
        }

        bool operator&&(const Long& other) const {
            return this->value && other.value;
        }
        
        template<typename Type>
        bool operator&&(const Type& other) const {
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

        bool operator||(const Short& other) const {
            return this->value || other.value;
        }

        bool operator||(const Long& other) const {
            return this->value || other.value;
        }

        bool operator||(const char* other) const {
            return this->value || std::stod(other);
        }

        template<typename Type>
        bool operator||(const Type& other) const {
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
        friend class Integer;
        friend class Short;
        friend class Long;
        friend class Float;
        friend class Double;
    public:
        Boolean() : value(false) {}
        template<typename Type>
        Boolean(const Type& value) : value(value) {}
        Boolean(const Boolean& other) : value(other.value) {}
        Boolean(Boolean&& other) noexcept : value(other.value) {}
        Boolean(const Integer& other) noexcept : value(other.value) {}
        Boolean(const Short& other) : value(other.value) {}
        Boolean(const Long& other) : value(other.value) {}
        Boolean(const Float& other) : value(other.value) {}
        Boolean(const Double& other) : value(other.value) {}



        operator bool() const {
            return this->value;
        }

        void setValue(const bool& value) {
            this->value = value;
        }

        void setValue(bool&& value) {
            this->value = value;
        }

        bool getValue() const {
            return this->value;
        }

        const char* toString() const {
            return this->value ? "true" : "false";
        }

        const char* type() const {
            return "Boolean";
        }



        Boolean& operator=(const Boolean& other) {
            this->value = other.value;
            return *this;
        }

        Boolean& operator=(Boolean&& other) noexcept {
            this->value = other.value;
            return *this;
        }

        Boolean& operator=(const Integer& other) {
            this->value = other.value;
            return *this;
        }

        Boolean& operator=(const Short& other) {
            this->value = other.value;
            return *this;
        }

        Boolean& operator=(const Long& other) {
            this->value = other.value;
            return *this;
        }

        Boolean& operator=(const Float& other) {
            this->value = other.value;
            return *this;
        }

        Boolean& operator=(const Double& other) {
            this->value = other.value;
            return *this;
        }
        
        template<typename Type>
        Boolean& operator=(const Type& other) {
            this->value = other;
            return *this;
        }



        bool operator==(const Boolean& other) const {
            return this->value == other.value;
        }

        bool operator==(const Integer& other) const {
            return this->value == other.value;
        }

        bool operator==(const Short& other) const {
            return this->value == other.value;
        }

        bool operator==(const Long& other) const {
            return this->value == other.value;
        }

        bool operator==(const Float& other) const {
            return this->value == other.value;
        }

        bool operator==(const Double& other) const {
            return this->value == other.value;
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }



        bool operator!=(const Boolean& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Integer& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Short& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Long& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Float& other) const {
            return this->value != other.value;
        }

        bool operator!=(const Double& other) const {
            return this->value != other.value;
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }



        friend std::ostream& operator<<(std::ostream& out, const Boolean& boolean) {
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

        template<typename Type>
        Character(const Type& other) : value(other) {}

        Character(const Character& other) : value(other.value) {}

        Character(const char* other) : value(other[0]) {}

        ~Character() {}



        template<typename Type>
        Character& operator=(const Type& other) {
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
            if(isalpha(this->value)) {
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
            if(isdigit(this->value)) {
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
            if(isalnum(this->value)) {
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
            if(isspace(this->value)) {
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
            if(ispunct(this->value)) {
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
            if(isprint(this->value)) {
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
            if(isblank(this->value)) {
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
            if(this->value == other) {
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
            if(this->value == other.value) {
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
            if(toupper(this->value) == toupper(other.value)) {
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
            if(toupper(this->value) == toupper(other)) {
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
            if(toupper(this->value) == toupper(other)) {
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



        template<typename Type>
        Character& operator+=(const int& other) {
            this->value += other;
            return *this;
        }

        Character& operator+=(const Character& other) {
            this->value += other.value;
            return *this;
        }



        template<typename Type>
        Character& operator-=(const int& other) {
            this->value -= other;
            return *this;
        }

        Character& operator-=(const Character& other) {
            this->value -= other.value;
            return *this;
        }



        template<typename Type>
        Character& operator*=(const Type& other) {
            this->value *= other;
            return *this;
        }

        Character& operator*=(const Character& other) {
            this->value *= other.value;
            return *this;
        }



        template<typename Type>
        Character& operator/=(const Type& other) {
            this->value /= other;
            return *this;
        }

        Character& operator/=(const Character& other) {
            this->value /= other.value;
            return *this;
        }



        template<typename Type>
        Character& operator%=(const Type& other) {
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
        


        template<typename Type>
        Character operator+(const Type& other) const {
            return this->value + other;
        }

        Character operator+(const Character& other) const {
            return this->value + other.value;
        }



        template<typename Type>
        Character operator-(const Type& other) const {
            return this->value - other;
        }
        
        Character operator-(const Character& other) const {
            return this->value - other.value;
        }



        template<typename Type>
        Character operator*(const Type& other) const {
            return this->value * other;
        }

        Character operator*(const Character& other) const {
            return this->value * other.value;
        }



        template<typename Type>
        Character operator/(const Type& other) const {
            return this->value / other;
        }

        Character operator/(const Character& other) const {
            return this->value / other.value;
        }



        template<typename Type>
        Character operator%(const Type& other) const {
            return this->value % other;
        }

        Character operator%(const Character& other) const {
            return this->value % other.value;
        }



        template<typename Type>
        bool operator^(const Type& other) const {
            return this->value ^ other;
        }

        bool operator^(const Character& other) const {
            return this->value ^ other.value;
        }



        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }

        bool operator==(const Character& other) const {
            return this->value == other.value;
        }



        template<typename Type>
        Character operator&(const Type& other) const {
            return this->value & other;
        }

        Character operator&(const Character& other) const {
            return this->value & other.value;
        }



        template<typename Type>
        Character operator|(const Type& other) const {
            return this->value | other;
        }

        Character operator|(const Character& other) const {
            return this->value | other.value;
        }



        Character operator~() const {
            return ~this->value;
        }

        bool operator!() const {
            return !this->value;
        }



        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }

        bool operator!=(const Character& other) const {
            return this->value != other.value;
        }



        template<typename Type>
        bool operator<(const Type& other) const {
            return this->value < other;
        }

        bool operator<(const Character& other) const {
            return this->value < other.value;
        }

        

        template<typename Type>
        bool operator>(const Type& other) const {
            return this->value > other;
        }

        bool operator>(const Character& other) const {
            return this->value > other.value;
        }

        

        template<typename Type>
        bool operator<=(const Type& other) const {
            return this->value <= other;
        }

        bool operator<=(const Character& other) const {
            return this->value <= other.value;
        }



        template<typename Type>
        bool operator>=(const Type& other) const {
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
            for(size_t i = 0; i <= this->length; i++) {
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
            for(size_t i = 0; i <= this->length; i++) {
                if(this->value[i] != other[i]) {
                    return false;
                }
            }
            return true;
        }

        bool equalityCompareString(const String& other) const {
            for(size_t i = 0; i <= this->length; i++) {
                if(this->value[i] != other.value[i]) {
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
            if(other >= 'A' && other <= 'Z') {
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
            if(other >= 'A' && other <= 'Z') {
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
            if(other >= 'a' && other <= 'z') {
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
            if(other >= 'a' && other <= 'z') {
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
            for(size_t i = 0; i < this->length; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }

        char* stringCopy(char* Destination, String Source, size_t Length) {
            for(int i = 0; i < Length; i++) {
                Destination[i] = Source[i];
            }

            return Destination;
        }


        using _StringView = const String&;

    public:
        String() : value(nullptr), length(0) {}

        String(const char* value) {
            this->length = strlen(value);
            this->value = new char[this->length + 1];
            copy(value);
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
            for(size_t i = 0; i < this->length; i++) {
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
        static const size_t LargeValue = -1;

        /**
        * @brief The length of the string
        * 
        */
        const size_t& Length = this->length;

        

        operator char*() const {
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
        String get() const {
            return *this;
        }



        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return String&
        */
        String& append(const char* other) {
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

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return String& 
        */
        String& append(_StringView other) {
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

        String& append(const short& shortNumber) {
            String str = "";
            short number = shortNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = shortNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }

            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -shortNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String& append(const int& intNumber) {
            String str = "";
            int number = intNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = intNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }

            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -intNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String& append(const long& longNumber) {
            String str = "";
            long number = longNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = longNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }

            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -longNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String& append(const long long& longLongNumber) {
            String str = "";
            long  long number = longLongNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = longLongNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }

            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -longLongNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String& append(const unsigned short& USInt) {
            String str = "";
            unsigned short number = USInt;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = USInt;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String& append(const unsigned int& UInt) {
            String str = "";
            unsigned int number = UInt;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = UInt;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String& append(const unsigned long& ULNumber) {
            String str = "";
            unsigned long number = ULNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = ULNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String& append(const unsigned long long& ULLNumber) {
            String str = "";
            unsigned long long number = ULLNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = ULLNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String& append(const float& floatNumber) {
            if(floatNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double FNumber = Math.Floor(floatNumber);
            double tempFloat = floatNumber - FNumber;
            String str = "";

            // To turn the integer part to string
            long long mainDigits = Math.Log10(FNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(FNumber, 10)) + '0';
                FNumber /= 10;
                FNumber = Math.Trunc(FNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkFloat = Math.Floor(floatNumber);
            if(floatNumber - checkFloat == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            FNumber = Math.Floor(floatNumber);
            tempFloat = floatNumber - FNumber;
            long long digits = 0;

            if(tempFloat < 0) {
                tempFloat *= -1;
            }
            
            tempFloat *= 100000;

            double number = Math.Round(tempFloat);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.Round(number);
                }
                else digits++;
            }
            String tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.Round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String& append(const double& doubleNumber) {
            if(doubleNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double DNumber = Math.Floor(doubleNumber);
            double tempDouble = doubleNumber - DNumber;
            String str = "";

            // To turn the integer part to string
            long long mainDigits = Math.Log10(DNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(DNumber, 10)) + '0';
                DNumber /= 10;
                DNumber = Math.Trunc(DNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkDouble = Math.Floor(doubleNumber);
            if(doubleNumber - checkDouble == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            DNumber = Math.Floor(doubleNumber);
            tempDouble = doubleNumber - DNumber;
            long long digits = 0;

            if(tempDouble < 0) {
                tempDouble *= -1;
            }
            
            tempDouble *= 100000;

            double number = Math.Round(tempDouble);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.Round(number);
                }
                else digits++;
            }
            String tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.Round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String& append(const long double& longDoubleNumber) {
            if(longDoubleNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double LDNumber = Math.Floor(longDoubleNumber);
            double tmepLongDouble = longDoubleNumber - LDNumber;
            String str = "";

            // To turn the integer part to string
            long long mainDigits = Math.Log10(LDNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(LDNumber, 10)) + '0';
                LDNumber /= 10;
                LDNumber = Math.Trunc(LDNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkLongDouble = Math.Floor(longDoubleNumber);
            if(longDoubleNumber - checkLongDouble == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            LDNumber = Math.Floor(longDoubleNumber);
            tmepLongDouble = longDoubleNumber - LDNumber;
            long long digits = 0;

            if(tmepLongDouble < 0) {
                tmepLongDouble *= -1;
            }
            
            tmepLongDouble *= 100000;

            double number = Math.Round(tmepLongDouble);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.Round(number);
                }
                else digits++;
            }
            String tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.Round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String& append(Integer integer) {
            String str = "";
            int number = integer;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = integer;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -integer;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String& append(Short shortNumber) {
            String str = "";
            short number = shortNumber;
            if(number > 0) {
                short digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = shortNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -shortNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String& append(Long longNumber) {
            String str = "";
            long long number = longNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = longNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -longNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String& append(Float floatNumber) {
            if(floatNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double FNumber = Math.Floor(floatNumber);
            double tempFloat = floatNumber - FNumber;
            String str = "";

            // To turn the integer part to string
            long long mainDigits = Math.Log10(FNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(FNumber, 10)) + '0';
                FNumber /= 10;
                FNumber = Math.Trunc(FNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkFloat = Math.Floor(floatNumber);
            if(floatNumber - checkFloat == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            FNumber = Math.Floor(floatNumber);
            tempFloat = floatNumber - FNumber;
            long long digits = 0;

            if(tempFloat < 0) {
                tempFloat *= -1;
            }
            
            tempFloat *= 100000;

            double number = Math.Round(tempFloat);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.Round(number);
                }
                else digits++;
            }
            String tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.Round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String& append(Double doubleNumber) {
            if(doubleNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double DNumber = Math.Floor(doubleNumber);
            double tempDouble = doubleNumber - DNumber;
            String str = "";

            // To turn the integer part to string
            long long mainDigits = Math.Log10(DNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(DNumber, 10)) + '0';
                DNumber /= 10;
                DNumber = Math.Trunc(DNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkDouble = Math.Floor(doubleNumber);
            if(doubleNumber - checkDouble == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            DNumber = Math.Floor(doubleNumber);
            tempDouble = doubleNumber - DNumber;
            long long digits = 0;

            if(tempDouble < 0) {
                tempDouble *= -1;
            }
            
            tempDouble *= 100000;

            double number = Math.Round(tempDouble);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.Round(number);
                }
                else digits++;
            }
            String tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.Round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }


        /**
        * @brief A method that makes a string empty
        * 
        * @return String& 
        */
        String& empty() {
            delete[] this->value;
            this->value = nullptr;
            this->length = 0;
            return *this;
        }

        /**
        * @brief A method that clears a string
        * 
        * @return String& 
        */
        String& clear() {
            this->value[0] = '\0';
            return *this;
        }

        /**
        * @brief A method that erases a string specified ina range
        * 
        * @param start 
        * @param end 
        * @return String& 
        */
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

        /**
        * @brief A method that erases a string starting from 0 to a specified index
        * 
        * @param start 
        * @return String& 
        */
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

        /**
        * @brief A method that erases a string starting from 0 to a specified index
        *  and replaces it with a specified char
        * 
        * @param start 
        * @param replacement 
        * @return String& 
        */
        // String& erase(const size_t& start, const char& replacement) {
        //     if(start > this->length) {
        //         throw std::invalid_argument("Start index must be smaller than length of string");
        //     }
        //     size_t newLength = this->length - 1 + 1;
        //     char* newValue = new char[newLength + 1];
        //     for(size_t i = 0; i < start; i++) {
        //         newValue[i] = this->value[i];
        //     }
        //     for(size_t i = start; i <= newLength; i++) {
        //         newValue[i] = replacement;
        //     }
        //     newValue[newLength] = '\0';
        //     delete[] this->value;
        //     this->value = newValue;
        //     this->length = newLength;
        //     return *this;
        // }

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return String& 
        */
        String& joins(_StringView other) {
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

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return String& 
        */
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

        /**
        * @brief A method that appends a character to the end of a string
        * 
        * @param other 
        * @return String& 
        */
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

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return String& 
        */
        String& push(_StringView other) {
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

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return String& 
        */
        String& push(const char* other) {
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

        /**
        * @brief A method that appends a character to the end of a string
        * 
        * @param other 
        * @return String& 
        */
        String& push(const char& other) {
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

        /**
        * @brief A method that removes the last character of a string
        * 
        * @return String& 
        */
        String& pop() {
            if(this->length == 0) {
                throw std::out_of_range("Cannot pop from empty string");
            }
            size_t newLength = this->length - 1;
            char* newValue = new char[newLength + 1];
            for(size_t i = 0; i < newLength; i++) {
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
            if(count > this->length) {
                throw std::out_of_range("Cannot pop more than length of string");
            }
            size_t newLength = this->length - count;
            char* newValue = new char[newLength + 1];
            for(size_t i = 0; i < newLength; i++) {
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
            if(index > this->length) {
                throw std::invalid_argument("Index must be smaller than length of string");
            }
            return this->value[index];
        }

        /**
        * @brief Returns the Unicode value of the character at the specified location.
        * 
        * @param index 
        * @return int 
        */
        int charCodeAt(const size_t& index) const {
            if(index > this->length) {
                throw std::invalid_argument("Index must be smaller than length of string");
            }
            return this->value[index];
        }

        /**
        * @brief Returns the hash code for this string.
        * 
        * @return long long 
        */
        Long hashCode() const {
            long long hash = 0;
            for(size_t i = 0; i < this->length; i++) {
                hash = 31 * hash + this->value[i];
            }
            return hash;
        }

        /**
        * @brief A method that checks if a string starts with a specified string
        * 
        * @param other 
        * @return bool
        */
        bool startsWith(_StringView other) const {
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

        /**
        * @brief A method that checks if a string starts with a specified string
        * 
        * @param other 
        * @return bool
        */
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

        /**
        * @brief A method that checks if a string starts with a specified char
        * 
        * @param other 
        * @return bool
        */
        bool startsWith(const char& other) const {
            if(this->length < 1) {
                return false;
            }
            if(this->value[0] != other) {
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

        /**
        * @brief A method that checks if a string ends with a specified string
        * 
        * @param other 
        * @return bool 
        */
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

        /**
        * @brief A method that checks if a string ends with a specified char
        * 
        * @param other 
        * @return bool
        */
        bool endsWith(const char& other) const {
            if(this->length < 1) {
                return false;
            }
            if(this->value[this->length - 1] != other) {
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
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] >= 'A' && this->value[i] <= 'Z') {
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
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] >= 'a' && this->value[i] <= 'z') {
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

        /**
        * @brief Returns a string that contains the concatenation of two or more strings.
        * 
        * @param other 
        * @return String& 
        */
        String& concat(_StringView other) {
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

        /**
        * @brief Returns a string that contains the concatenation of a string and a char
        * 
        * @param other 
        * @return String& 
        */
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

        /**
        * @brief Returns the last occurrence of a substring in the string.
        * 
        * @param other 
        * @return int 
        */
        int lastIndexOf(const char& other) const {
            for(int i = this->length - 1; i >= 0; i--) {
                if(this->value[i] == other) {
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
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] == other) {
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
            for(size_t i = 0; i < newLength; i++) {
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
        * @brief A method that replaces a character in a string with another character.
        * 
        * @param old 
        * @param newChar 
        * @return String& 
        */
        String& replace(const char& old, const char& newChar) {
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] == old) {
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

        String& replace(size_t start, size_t end, _StringView newString) {
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
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
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
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] == old) {
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

        /**
        * @brief Returns the position of the first occurrence of a substring.
        * 
        * @param other 
        * @return int 
        */
        int indexOf(const char& other) const {
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] == other) {
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
            if(this->length == 0) {
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

        /**
        * @brief A method that iterates through a string
        * 
        * @param func 
        * @return String& 
        */
        String& forEach(const std::function<void(char&)>& func) {
            for(size_t i = 0; i < this->length; i++) {
                func(this->value[i]);
            }
            return *this;
        }

        /**
        * @brief A map method that iterates through a string and applies a function to each character
        * 
        * @param func 
        * @return String& 
        */
        String& map(const std::function<char(char&)>& func) {
            for(size_t i = 0; i < this->length; i++) {
                this->value[i] = func(this->value[i]);
            }
            return *this;
        }

        /**
        * @brief A method that filters a string
        * 
        * @param func 
        * @return String& 
        */
        String& filter(const std::function<bool(char&)>& func) {
            for(size_t i = 0; i < this->length; i++) {
                if(!func(this->value[i])) {
                    this->value[i] = '\0';
                }
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

        /**
        * @brief A method that reverses a string
        * 
        * @return String& 
        */
        String& reverse() {
            for(size_t i = 0; i < this->length / 2; i++) {
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
            for(size_t i = 0; i < this->length; i++) {
                if(i == 0) {
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
        size_t count(const char& other) const {
            size_t count = 0;
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] == other) {
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
        size_t count(_StringView other) const {
            size_t count = 0;
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

        /**
        * @brief A method that counts the number of a specified string in a string
        * 
        * @param other 
        * @return int 
        */
        size_t count(const char* other) const {
            size_t count = 0;
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

        /**
        * @brief Returns a version of the string suitable for caseless comparison 
        * 
        * @return String 
        */
        String casefold() const {
            String result = *this;
            for(size_t i = 0; i < this->length; i++) {
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
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] >= 'a' && this->value[i] <= 'z') {
                    this->value[i] = toupper(this->value[i]);
                }
                else if(this->value[i] >= 'A' && this->value[i] <= 'Z') {
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
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] == other) {
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

        /**
        * @brief A method that finds the first index of a specified string in a string
        * 
        * @param other 
        * @return bool
        */
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

        /**
        * @brief A method that checks if all the characters in a string are alphabet
        * 
        * @return bool
        */
        bool isAlphabet() const {
            for(size_t i = 0; i < this->length; i++) {
                if(!isalpha(this->value[i])) {
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
            for(size_t i = 0; i < this->length; i++) {
                if(!isalnum(this->value[i])) {
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

        /**
        * @brief A method that inserts a string into another string at a specified index
        * 
        * @param index 
        * @param other 
        * @return String& 
        */
        String& insert(size_t index, _StringView other) {
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

        /**
        * @brief A method that inserts a char into another string at a specified index
        * 
        * @param index 
        * @param other 
        * @return String& 
        */
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
        const char* cString() {
            char* cString = new char[this->length + 1];
            for(size_t i = 0; i < this->length; i++) {
                cString[i] = this->value[i];
            }
            cString[this->length] = '\0';
            delete[] this->value;
            this->value = cString;
            return this->value;
            return cString;
        }

        /**
        * @brief A method that returns a C style string
        * 
        * @return char* 
        */
        char* c_string() {
            char* cString = new char[this->length + 1];
            for(size_t i = 0; i < this->length; i++) {
                cString[i] = this->value[i];
            }
            cString[this->length] = '\0';
            delete[] this->value;
            this->value = cString;
            return this->value;
            return cString;
        }

        /**
        * @brief Returns a string with the given prefix removed if it exists
        * 
        * @param other 
        * @return String& 
        */
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

        /**
        * @brief Returns a string with the given prefix removed if it exists
        * 
        * @param other 
        * @return String& 
        */
        String& removePrefix(_StringView other) {
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

        /**
        * @brief Returns a string with the given prefix removed if it exists
        * 
        * @param other 
        * @return String& 
        */
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

        /**
        * @brief Returns a string with the given suffix removed if it exists
        * 
        * @param other 
        * @return String& 
        */
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

        /**
        * @brief Returns a string with the given suffix removed if it exists
        * 
        * @param other 
        * @return String& 
        */
        String& removeSuffix(_StringView other) {
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

        /**
        * @brief Returns a string with the given suffix removed if it exists
        * 
        * @param other 
        * @return String& 
        */
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

        /**
        * @brief A method that checks if all characters in the string are lowercase
        * 
        * @return bool
        */
        bool isLower() const {
            for(size_t i = 0; i < this->length; i++) {
                if(this->value[i] < 'a' || this->value[i] > 'z') {
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

        String& operator+=(_StringView other) {
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



        String operator+(const char* value) {
            String newString = *this;
            newString += value;
            return newString;
        }

        String operator+(_StringView other) {
            String newString = *this;
            newString += other;
            return newString;
        }

        String operator+(const char& value) {
            String newString = *this;
            newString += value;
            return newString;
        }

        String operator+(const int& intNumber) {
            String str = "";
            int number = intNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = intNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }

            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -intNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String operator+(const unsigned int& unsignedIntNumber) {
            String str = "";
            unsigned int number = unsignedIntNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = unsignedIntNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String operator+(const short& shortNumber) {
            String str = "";
            short int number = shortNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = shortNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -shortNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String operator+(const unsigned short& unsignedShortNumber) {
            String str = "";
            unsigned short int number = unsignedShortNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = unsignedShortNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String operator+(const long& longNumber) {
            String str = "";
            long int number = longNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = longNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            } 
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -longNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String operator+(const unsigned long& unsignedLongNumber) {
            String str = "";
            unsigned long int number = unsignedLongNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = unsignedLongNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String operator+(const long long& LLNumber) {
            String str = "";
            long long int number = LLNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = LLNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -LLNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String operator+(const unsigned long long& ULLNumber) {
            String str = "";
            unsigned long long int number = ULLNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = ULLNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            str = "0";
            this->append(str);
            return *this;
        }

        String operator+(Integer integer) {
            String str = "";
            int number = integer;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = integer;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -integer;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String operator+(Short shortNumber){
            String str = "";
            short number = shortNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = shortNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -shortNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String operator+(Long longNumber) {
            String str = "";
            long long number = longNumber;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = longNumber;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                this->append(str);
                return *this;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
                this->append(tempString);
                return *this;
            }
            tempString = "-";
            number = -number;
            int digits = 0;
            while(number > 0) {
                number /= 10;
                digits++;
            }
            number = -longNumber;
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            str.insert(0, '-');
            str.pop();
            this->append(str);
            return *this;
        }

        String operator+(const float& floatNumber) {
            if(floatNumber == 0) {
                this->append("0");
                return *this;
            }
            if(floatNumber == (long long)floatNumber) {
                String tempStr = "";
                tempStr = tempStr + (long long)floatNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = floatNumber;
            float tempFloat = floatNumber - LLNumber;
            String str = "";
            str = str + LLNumber;
            str.append(".");
            long long digits = 0;

            tempFloat = floatNumber - LLNumber;
            if(tempFloat < 0) {
                tempFloat *= -1;
            }
            tempFloat *= 100000;

            long long number = Math.Round(tempFloat);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            String tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = (number % 10) + '0';
                tempString += tempCharacter;
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String operator+(const double& doubleNumber) {
            if(doubleNumber == 0) {
                this->append("0");
                return *this;
            }
            if(doubleNumber == (long long)doubleNumber) {
                String tempStr = "";
                tempStr = tempStr + (long long)doubleNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = doubleNumber;
            double tempDouble = doubleNumber - LLNumber;
            String str = "";
            str = str + LLNumber;
            str += ".";
            long long digits = 0;

            tempDouble = doubleNumber - LLNumber;
            if(tempDouble < 0) {
                tempDouble *= -1;
            }
            tempDouble *= 100000;

            long long number = Math.Round(tempDouble);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            String tempString = "";
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String operator+(const long double& longDoubleNumber) {
            if(longDoubleNumber == 0) {
                this->append("0");
                return *this;
            }
            if(longDoubleNumber == (long long)longDoubleNumber) {
                String tempStr = "";
                tempStr = tempStr + (long long)longDoubleNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = longDoubleNumber;
            long double tempLongDouble = longDoubleNumber - LLNumber;
            String str = "";
            str = str + LLNumber;
            str += ".";
            long long digits = 0;

            tempLongDouble = longDoubleNumber - LLNumber;
            if(tempLongDouble < 0) {
                tempLongDouble *= -1;
            }
            tempLongDouble *= 100000;

            long long number = Math.Round(tempLongDouble);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            String tempString = "";
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String operator+(Float floatNumber) {
            if(floatNumber == 0) {
                this->append("0");
                return *this;
            }
            if(floatNumber == (long long)floatNumber) {
                String tempStr = "";
                tempStr = tempStr + (long long)floatNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = floatNumber;
            float tempFloat = floatNumber - LLNumber;
            String str = "";
            str = str + LLNumber;
            str += ".";
            long long digits = 0;

            tempFloat = floatNumber - LLNumber;
            if(tempFloat < 0) {
                tempFloat *= -1;
            }
            tempFloat *= 100000;

            long long number = Math.Round(tempFloat);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            String tempString = "";
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        String operator+(Double doubleNumber) {
            if(doubleNumber == 0) {
                this->append("0");
                return *this;
            }
            if(doubleNumber == (long long)doubleNumber) {
                String tempStr = "";
                tempStr = tempStr + (long long)doubleNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = doubleNumber;
            double tempDouble = doubleNumber - LLNumber;
            String str = "";
            str = str + LLNumber;
            str += ".";
            long long digits = 0;

            tempDouble = doubleNumber - LLNumber;
            if(tempDouble < 0) {
                tempDouble *= -1;
            }
            tempDouble *= 100000;

            long long number = Math.Round(tempDouble);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            String tempString = "";
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
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

        bool operator==(_StringView other) const {
            return this->equalityCompareString(other.value);
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
            for(size_t i = 0; i < this->length; i++) {
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
            for(size_t i = 0; i < this->length; i++) {
                newValue[i] = this->value[i + 1];
            }
            newValue[this->length] = '\0';
            delete[] this->value;
            this->value = newValue;
            return result;
        }



        friend std::ostream& operator<<(std::ostream& out, _StringView string) {
            out << string.value;
            return out;
        }

        friend std::istream& operator>>(std::istream& in, String& string) {
            string.reAllocate(0);
            char c;
            while (in.get(c)) {
                if(c == '\n') {
                    break;
                }
                string += c;
            }
            return in;
        }

        class Iterator : public std::iterator<std::forward_iterator_tag, char> {
        public:
            Iterator(char* value) : value(value) {}
            Iterator(const Iterator& other) : value(other.value) {}

            Iterator& operator++() {
                this->value++;
                return *this;
            }

            Iterator operator++(int) {
                Iterator result = *this;
                this->value++;
                return result;
            }

            bool operator==(const Iterator& other) {
                return this->value == other.value;
            }

            bool operator!=(const Iterator& other) {
                return this->value != other.value;
            }

            char& operator*() {
                return *this->value;
            }

            char* operator->() {
                return this->value;
            }

            String operator*() const {
                return String(this->value);
            }

        private:
            char* value;
        };



        Iterator begin() {
            return Iterator(this->value);
        }

        Iterator begin() const {
            return Iterator(this->value);
        }

        Iterator end() {
            return Iterator(this->value + this->size());
        }

        Iterator end() const {
            return Iterator(this->value + this->size());
        }

        Iterator cbegin() const {
            return Iterator(this->value);
        }

        Iterator cend() const {
            return Iterator(this->value + this->size());
        }

        /**
         * @brief A helper function to resize the string
         *
         * @param newLength
         */
        void resize(size_t newLength) {
            char *newValue = new char[newLength + 1];
            for (size_t i = 0; i < this->length; i++)
            {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->length = newLength;
        }
    };

    String operator""_s(const char* str, size_t len)
    {
        return String(str, len);
    }

    Character operator""_c(const char* str, size_t len)
    {
        return Character(str[0]);
    }

    Double operator""_d(long double value)
    {
        return Double(value);
    }

    Long operator""_L(unsigned long long value)
    {
        return Long(value);
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

    using LongView    = const Long&;

    template<typename WrapperClass>
    String type(const WrapperClass& wrapper) {
        using namespace jamstl::type_traits;
        if(is_same<int, WrapperClass>::value) {
            return "int";
        }

        if(is_same<short int, WrapperClass>::value) {
            return "short int";
        }

        if(is_same<long, WrapperClass>::value) {
            return "long";
        }

        if(is_same<long long, WrapperClass>::value) {
            return "long long";
        }

        if(is_same<unsigned int, WrapperClass>::value) {
            return "unsigned int";
        }

        if(is_same<unsigned short int, WrapperClass>::value) {
            return "unsigned short int";
        }

        if(is_same<unsigned long, WrapperClass>::value) {
            return "unsigned long";
        }

        if(is_same<unsigned long long, WrapperClass>::value) {
            return "unsigned long long";
        }

        if(is_same<float, WrapperClass>::value) {
            return "float";
        }

        if(is_same<double, WrapperClass>::value) {
            return "double";
        }

        if(is_same<bool, WrapperClass>::value) {
            return "bool";
        }
        
        if(is_same<char, WrapperClass>::value) {
            return "char";
        }

        if(is_same<unsigned char, WrapperClass>::value) {
            return "unsigned char";
        }

        if(is_same<String, WrapperClass>::value) {
            return "String";
        }

        if(is_same<Character, WrapperClass>::value) {
            return "Character";
        }

        if(is_same<Double, WrapperClass>::value) {
            return "Double";
        }
        
        if(is_same<Float, WrapperClass>::value) {
            return "Float";
        }

        if(is_same<Integer, WrapperClass>::value) {
            return "Integer";
        }

        if(is_same<Short, WrapperClass>::value) {
            return "Short";
        }

        if(is_same<Boolean, WrapperClass>::value) {
            return "Boolean";
        }

        if(is_same<Long, WrapperClass>::value) {
            return "Long";
        }

        if(is_array<WrapperClass>::value) {
            return "Array";
        }

        if(is_pointer<WrapperClass>::value) {
            return "Pointer";
        }

        return "Unknown";
    }

JAMSTL_NAMESPACE_END

#include "String.h"

#endif