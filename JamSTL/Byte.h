#pragma once

#ifndef JAMSTL_BYTE_H
#define JAMSTL_BYTE_H 1
#include "Macros.h"
#include "String.h"
#include "Object.h"

JAMSTL_NAMESPACE_BEGIN

    /**
     * @brief An integer wrapper class
     * 
     */
    class Byte extends Object {
    private:
        unsigned char value;
    public:
        Byte() : value('\0') {}

        template <typename Type>
        Byte(const Type &other) : value(other) {};
        Byte(const Byte &other) : value(other.value) {}
        Byte(unsigned char other) : value(other) {}
        Byte(const String& other) : value(other[0]) {}
        Byte(const char* other) : value(other[0]) {}
        ~Byte() {}

        template<typename Type>
        Byte& operator=(const Type& other) {
            value = other;
            return *this;
        }

        Byte& operator=(const Byte& other) {
            value = other.value;
            return *this;
        }

        Byte& operator=(unsigned char other) {
            value = other;
            return *this;
        }



        operator unsigned char() const {
            return value;
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
         * @brief Converts an unsigned char to an upper case char.
         * 
         * @return Byte& 
         */
        Byte& toUpper() {
            value = static_cast<unsigned char>(toupper(value));
            return *this;
        }

        /**
         * @brief Converts an unsigned char to a lower case char.
         * 
         * @return Byte& 
         */
        Byte& toLower() {
            value = static_cast<unsigned char>(tolower(value));
            return *this;
        }

        /**
         * @brief Checks if an unsigned char is an alphabet.
         * 
         * @return bool
         */
        bool isAlphabet() const {
            return isalpha(value);
        }

        /**
         * @brief Check if an unsigned char is a digit.
         * 
         * @return bool
         */
        bool isDigit() const {
            return isdigit(value);
        }

        /**
         * @brief Check if an unsigned char is a letter or digit.
         * 
         * @return bool
         */
        bool isAlphanumeric() const {
            return isalnum(value);
        }

        /**
         * @brief Checks if an unsigned char is a space.
         * 
         * @return bool
         */
        bool isSpace() const {
            return isspace(value);
        }

        /**
         * @brief Checks if an unsigned char is a punctuation.
         * 
         * @return bool
         */
        bool isPunctuation() const {
            return ispunct(value);
        }

        /**
         * @brief Checks if an unsigned char is a printable character.
         * 
         * @return bool
         */
        bool isPrintable() const {
            return isprint(value);
        }

        /**
         * @brief Checks if an unsigned char is blank.
         * 
         * @return bool
         */
        bool isBlank() const {
            return isblank(value);
        }

        /**
         * @brief Converts an unsigned char to a string.
         * 
         * @return bool
         */
        String toString() const {
            return String(value);
        }

        /**
         * @brief Clears the unsigned char and gives it a value of null.
         * 
         * @return Byte 
         */
        Byte clear() {
            value = '\0';
            return *this;
        }

        /**
         * @brief Clears the unsigned char and gives it a value of null.
         * 
         * @return bool
         */
        Byte& empty() {
            value = '\0';
            return *this;
        }

        /**
         * @brief Swaps the value of two bytes.
         * 
         * @param other 
         */
        void swap(Byte& other) {
            unsigned char temp = value;
            value = other.value;
            other.value = temp;
        }

        /**
         * @brief Sets the value of the unsigned char.
         * 
         * @param other 
         */
        void set(unsigned char other) {
            value = other;
        }

        /**
         * @brief Sets the value of the byte.
         * 
         * @return unsigned char
         */
        void set(const Byte& other) {
            value = other.value;
        }
        
        /**
         * @brief Sets the value of the byte.
         * 
         * @return unsigned char
         */
        void set(const int& other) {
            value = static_cast<unsigned char>(other);
        }

        /**
         * @brief Gets the value of the unsigned char.
         * 
         * @return unsigned char 
         */
        unsigned char get() const {
            return value;
        }

        byte valueOf() const {
            return value;
        }

        /**
         * @brief Checks if the unsigned char is equal to another unsigned char.
         * 
         * @param other 
         * @return bool
         */
        bool isSameByte(const Byte& other) const {
            return value == other.value;
        }

        /**
         * @brief Checks if two bytes are equal no matter the case.
         * 
         * @param other 
         * @return bool
         */
        bool equalIgnoreCase(const Byte& other) const {
            return tolower(value) == tolower(other.value);
        }

        /**
         * @brief Checks if two bytes are equal no matter the case.
         * 
         * @param other
         * @return bool
         */
        bool equalIgnoreCase(const unsigned char& other) const {
            return tolower(value) == tolower(other);
        }

        /**
         * @brief Checks if a byte is empty.
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty() const {
            return value == '\0';
        }

        /**
         * @brief Converts a byte into int.
         * 
         * @return int 
         */
        int toInt() const {
            return value;
        }
        
        /**
         * @brief Converts a byte into a short.
         * 
         * @return short 
         */
        short toShort() const {
            return value;
        }

        /**
         * @brief Converts a byte into a long.
         * 
         * @return long 
         */
        long long toLong() const {
            return value;
        }



        template<typename Type>
        Byte& operator+=(const int& other) {
            this->value += other;
            return *this;
        }

        Byte& operator+=(const Byte& other) {
            this->value += other.value;
            return *this;
        }



        template<typename Type>
        Byte& operator-=(const int& other) {
            this->value -= other;
            return *this;
        }

        Byte& operator-=(const Byte& other) {
            this->value -= other.value;
            return *this;
        }



        template<typename Type>
        Byte& operator*=(const Type& other) {
            this->value *= other;
            return *this;
        }

        Byte& operator*=(const Byte& other) {
            this->value *= other.value;
            return *this;
        }



        template<typename Type>
        Byte& operator/=(const Type& other) {
            this->value /= other;
            return *this;
        }

        Byte& operator/=(const Byte& other) {
            this->value /= other.value;
            return *this;
        }



        template<typename Type>
        Byte& operator%=(const Type& other) {
            this->value %= other;
            return *this;
        }

        Byte& operator%=(const Byte& other) {
            this->value %= other.value;
            return *this;
        }



        Byte& operator++() {
            this->value++;
            return *this;
        }

        Byte& operator--() {
            this->value--;
            return *this;
        }

        Byte operator++(int) {
            Byte temp = *this;
            this->value++;
            return temp;
        }

        Byte operator--(int) {
            Byte temp = *this;
            this->value--;
            return temp;
        }
        


        template<typename Type>
        Byte operator+(const Type& other) const {
            return this->value + other;
        }

        Byte operator+(const Byte& other) const {
            return this->value + other.value;
        }

        String operator+(const String& other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append(other);
            return temp;
        }

        String operator+(const char* other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append(other);
            return temp;
        }



        template<typename Type>
        Byte operator-(const Type& other) const {
            return this->value - other;
        }
        
        Byte operator-(const Byte& other) const {
            return this->value - other.value;
        }



        template<typename Type>
        Byte operator*(const Type& other) const {
            return this->value * other;
        }

        Byte operator*(const Byte& other) const {
            return this->value * other.value;
        }



        template<typename Type>
        Byte operator/(const Type& other) const {
            return this->value / other;
        }

        Byte operator/(const Byte& other) const {
            return this->value / other.value;
        }



        template<typename Type>
        Byte operator%(const Type& other) const {
            return this->value % other;
        }

        Byte operator%(const Byte& other) const {
            return this->value % other.value;
        }



        template<typename Type>
        bool operator^(const Type& other) const {
            return this->value ^ other;
        }

        bool operator^(const Byte& other) const {
            return this->value ^ other.value;
        }



        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }

        bool operator==(const Byte& other) const {
            return this->value == other.value;
        }



        template<typename Type>
        Byte operator&(const Type& other) const {
            return this->value & other;
        }

        Byte operator&(const Byte& other) const {
            return this->value & other.value;
        }



        template<typename Type>
        Byte operator|(const Type& other) const {
            return this->value | other;
        }

        Byte operator|(const Byte& other) const {
            return this->value | other.value;
        }



        Byte operator~() const {
            return ~this->value;
        }

        bool operator!() const {
            return !this->value;
        }



        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }

        bool operator!=(const Byte& other) const {
            return this->value != other.value;
        }



        template<typename Type>
        bool operator<(const Type& other) const {
            return this->value < other;
        }

        bool operator<(const Byte& other) const {
            return this->value < other.value;
        }

        

        template<typename Type>
        bool operator>(const Type& other) const {
            return this->value > other;
        }

        bool operator>(const Byte& other) const {
            return this->value > other.value;
        }

        

        template<typename Type>
        bool operator<=(const Type& other) const {
            return this->value <= other;
        }

        bool operator<=(const Byte& other) const {
            return this->value <= other.value;
        }



        template<typename Type>
        bool operator>=(const Type& other) const {
            return this->value >= other;
        }

        bool operator>=(const Byte& other) const {
            return this->value >= other.value;
        }
        
    };



JAMSTL_NAMESPACE_END

#endif