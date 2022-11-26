#pragma once

#ifndef JAMSTL_CHARACTER_H
#define JAMSTL_CHARACTER_H 1
#include <ostream>
#include <istream>
#include "Macros.h"
#include "BasicString.h"
#include "Object.h"

JAMSTL_NAMESPACE_BEGIN

    /**
    * @brief A wrapper char class
    * @author Omar Estietie
    * 
    */
    class Character extends Object {
    private:
        char value;
    public:
        Character() : value('\0') {}

        template<typename Type>
        Character(const Type& other) : value(other) {}

        Character(const Character& other) : value(other.value) {}

        Character(const char* other) : value(other[0]) {}

        Character(const String& other) : value(other[0]) {}

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
         * @brief Get the Class Name object
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
        
        char valueOf() {
            return this->value;
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

        String operator+(const String& other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append( other);
            return temp;
        }

        String operator+(const char* other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append( other);
            return temp;
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



JAMSTL_NAMESPACE_END

#endif