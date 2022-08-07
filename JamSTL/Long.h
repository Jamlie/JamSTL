#pragma once

#ifndef JAMSTL_LONG_H
#define JAMSTL_LONG_H 1
#include "Macros.h"
#include "BasicString.h"
#include <ostream>
#include <istream>

JAMSTL_NAMESPACE_BEGIN

    /**
     * @brief A long long wrapper class
     * 
     */
    class Long extends Object {
    private:
        long long value;
        long long toLInt(String string) {
            long long TOINT = 0;

            for (int i = 0; string[i] != '\0'; i++) {
                if (i == 0 && (string[i] == '.' || string[i] == '-')) continue;
                else if(string[i] == '.') break;
                if (string[i] > '9' || string[i] < '0') break;
                TOINT = TOINT * 10 + string[i] - '0';
            }

            if (string[0] == '-') return -TOINT;
            
            return TOINT;
        }

    public:
        Long() : value(0) {}
        Long(const Long& other) : value(other.value) {}
        Long(const char* other) {
            this->value = toLInt(other);
        }
        Long(const String& other) {
            this->value = toLInt(other);
        }
        template<typename Type>
        Long(const Type& other) {
            this->value = static_cast<long long>(other);
        }


        Long& operator=(const Long& other) {
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
         * @brief Get the Class Name object.
         * 
         * @return String 
         */
        String getClassName() const {
            String className = typeid(this).name();
            className.erase(0, 11);
            className.pop();
            return className;
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

        static int hashCode(long long value) {
            return (int)(value ^ (value >> 32));
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
        static constexpr long long MIN_VALUE = 0x8000000000000000LL;


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
        
        String operator+(const char* other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append(other);
            return temp;
        }

        String operator+(const String& other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append(other);
            return temp;
        }

        template<typename Type>
        Long operator+(const Type& other) const {
            return this->value + other;
        }




        Long operator-(const Long& other) const {
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


JAMSTL_NAMESPACE_END



#endif