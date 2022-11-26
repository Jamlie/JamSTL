#pragma once

#ifndef JAMSTL_INTEGER_H
#define JAMSTL_INTEGER_H 1
#include "Macros.h"
#include "BasicString.h"
#include "Math.h"
#include "type_traits.h"
#include "Object.h"
#include <ostream>
#include <istream>

JAMSTL_NAMESPACE_BEGIN
        
    /**
     * @brief An integer wrapper class
     * 
     */
    class Integer extends Object {
    private:
        class BasicString {
            char* value;
            usize length = 0;
            usize stringLength(const char* str) {
                usize len = 0;
                while (str[len] != '\0') {
                    len++;
                }
                return len;
            }
            void copy(const char* str) {
                length = stringLength(str);
                value = new char[length + 1];
                for (usize i = 0; i < length; i++) {
                    value[i] = str[i];
                }
                value[length] = '\0';
            }

        public:
            BasicString() : value(nullptr), length(0) {}
            BasicString(const char* value) {
                this->length = stringLength(value);
                this->value = new char[this->length + 1];
                copy(value);
            }
            BasicString(const BasicString& other) {
                this->length = other.length;
                this->value = new char[this->length + 1];
                this->copy(other.value);
                this->value[this->length] = '\0';
            }
            BasicString(BasicString&& other) {
                this->length = other.length;
                this->value = other.value;
                other.value = nullptr;
            }
            BasicString(byte value[], usize length) {
                this->length = length;
                this->value = new char[this->length + 1];
                for (usize i = 0; i < length; i++) {
                    this->value[i] = value[i];
                }
                this->value[length] = '\0';
            }
            BasicString(BasicString value, usize length) {
                this->length = length;
                this->value = new char[this->length + 1];
                for (usize i = 0; i < length; i++) {
                    this->value[i] = value.value[i];
                }
                this->value[length] = '\0';
            }
            
            ~BasicString() {
                if(this->value != nullptr) {
                    delete[] this->value;
                }
            }


            static constexpr bool COMPACT_STRING = true;
            static constexpr byte LATIN1         = 0;
            operator char*() const {
                return this->value;
            }

            BasicString& operator=(const BasicString& other) {
                if(this->value != nullptr) {
                    delete[] this->value;
                }
                this->length = other.length;
                this->value = new char[this->length + 1];
                this->copy(other.value);
                this->value[this->length] = '\0';
                return *this;
            }

            BasicString& operator=(const char* other) {
                if(this->value != nullptr) {
                    delete[] this->value;
                }
                this->length = stringLength(other);
                this->value = new char[this->length + 1];
                this->copy(other);
                this->value[this->length] = '\0';
                return *this;
            }

            BasicString& operator+=(const char& value) {
                usize newLength = this->length + 1;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < this->length; i++) {
                    newValue[i] = this->value[i];
                }
                newValue[this->length] = value;
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->length = newLength;
                return *this;
            }

            BasicString& operator+=(const BasicString& other) {
                usize newLength = this->length + other.length;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < this->length; i++) {
                    newValue[i] = this->value[i];
                }
                for(usize i = 0; i < other.length; i++) {
                    newValue[this->length + i] = other.value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->length = newLength;
                return *this;
            }

            BasicString& operator+=(const char* other) {
                usize newLength = this->length + stringLength(other);
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < this->length; i++) {
                    newValue[i] = this->value[i];
                }
                for(usize i = 0; i < stringLength(other); i++) {
                    newValue[this->length + i] = other[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->length = newLength;
                return *this;
            }

            BasicString operator+(const char& value) {
                usize newLength = this->length + 1;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < this->length; i++) {
                    newValue[i] = this->value[i];
                }
                newValue[this->length] = value;
                newValue[newLength] = '\0';
                return BasicString(newValue, newLength);
            }

            BasicString operator+(const BasicString& other) {
                usize newLength = this->length + other.length;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < this->length; i++) {
                    newValue[i] = this->value[i];
                }
                for(usize i = 0; i < other.length; i++) {
                    newValue[this->length + i] = other.value[i];
                }
                newValue[newLength] = '\0';
                return BasicString(newValue, newLength);
            }

            BasicString operator+(const char* other) {
                usize newLength = this->length + stringLength(other);
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < this->length; i++) {
                    newValue[i] = this->value[i];
                }
                for(usize i = 0; i < stringLength(other); i++) {
                    newValue[this->length + i] = other[i];
                }
                newValue[newLength] = '\0';
                return BasicString(newValue, newLength);
            }

            BasicString& reverse() {
                for(usize i = 0; i < this->length / 2; i++) {
                    char temp = this->value[i];
                    this->value[i] = this->value[this->length - i - 1];
                    this->value[this->length - i - 1] = temp;
                }
                return *this;
            }

            BasicString& insert(usize index, const char& other) {
                if(index > this->length) {
                    return *this;
                }

                usize newLength = this->length + 1;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < index; i++) {
                    newValue[i] = this->value[i];
                }
                newValue[index] = other;
                for(usize i = index; i < this->length; i++) {
                    newValue[1 + i] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->length = newLength;
                return *this;
            }

            BasicString& pop() {
                if(this->length == 0) {
                    throw std::out_of_range("Cannot pop from empty string");
                }
                usize newLength = this->length - 1;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < newLength; i++) {
                    newValue[i] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->length = newLength;
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& os, const BasicString& str) {
                os << str.value;
                return os;
            }
        };

        int value;
        static constexpr unsigned char DigitTens[] = {
            '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
            '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
            '2', '2', '2', '2', '2', '2', '2', '2', '2', '2',
            '3', '3', '3', '3', '3', '3', '3', '3', '3', '3',
            '4', '4', '4', '4', '4', '4', '4', '4', '4', '4',
            '5', '5', '5', '5', '5', '5', '5', '5', '5', '5',
            '6', '6', '6', '6', '6', '6', '6', '6', '6', '6',
            '7', '7', '7', '7', '7', '7', '7', '7', '7', '7',
            '8', '8', '8', '8', '8', '8', '8', '8', '8', '8',
            '9', '9', '9', '9', '9', '9', '9', '9', '9', '9',
        };

        static constexpr unsigned char DigitOnes[] = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        };

        static constexpr char digits[] = {
            '0' , '1' , '2' , '3' , '4' , '5' ,
            '6' , '7' , '8' , '9' , 'a' , 'b' ,
            'c' , 'd' , 'e' , 'f' , 'g' , 'h' ,
            'i' , 'j' , 'k' , 'l' , 'm' , 'n' ,
            'o' , 'p' , 'q' , 'r' , 's' , 't' ,
            'u' , 'v' , 'w' , 'x' , 'y' , 'z'
        };

        BasicString toString(int integer) {
            BasicString str = "";
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
                return str;
            }
            BasicString tempString = "";
            if(number == 0) {
                tempString = "0";
            } else {
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
            }
            str += tempString;
            str.insert(0, '-');
            str.pop();
            return str;
        }


        int toInt(String string) {
            int ToInt = 0;

            for (int i = 0; string[i] != '\0'; i++) {
                if (i == 0 && (string[i] == '.' || string[i] == '-')) continue;
                else if(string[i] == '.') break;
                if (string[i] > '9' || string[i] < '0') break;
                ToInt = ToInt * 10 + string[i] - '0';
            }

            if (string[0] == '-') return -ToInt;
            
            return ToInt;
        }


        static constexpr usize SIZE = 32;

    public:

        String toString() {
            String str = "";
            int number = this->value;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = this->value;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                return str;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
            } else {
                tempString = "-";
                number = -number;
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = -this->value;
                for(int i = 0; i < digits; i++) {
                    tempString += (number % 10) + '0';
                    number /= 10;
                }
                tempString.reverse();
            }
            str += tempString;
            str.insert(0, '-');
            str.pop();
            return str;
        }

        Integer() : value(0) {}

        Integer(const int& value) : value(value) {}

        Integer(const Integer& integer) : value(integer.value) {}

        Integer(String str) {
           this->value = toInt(str);
        }

        Integer(const char* str) {
           this->value = toInt(str);
        }

        template<typename Type>
        Integer(Type value) {
            this->value = static_cast<int>(value);
        }



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
         * @brief Returns the number of trailing zeros in the binary representation of 
         * this Integer.
         * 
         * @param i 
         * @return int 
         */
        static int numberOfLeadingZeros(int i) {
            if(i <= 0) {
                return i == 0 ? 32 : 0;
            }
            int n = 31;
            if(i >= 1 << 16) {n -= 16; i >>= 16;}
            if(i >= 1 << 8) {n -= 8; i >>= 8;}
            if(i >= 1 << 4) {n -= 4; i >>= 4;}
            if(i >= 1 << 2) {n -= 2; i >>= 2;}
            return n - (i >> 1);
        }

        /**
         * @brief Returns the hash code for this instance.
         * 
         * @param value 
         * @return int 
         */
        static constexpr int hashCode(int value) {
            return value;
        }

        /**
         * @brief Returns the number of digits of an int
         * 
         * @param value 
         * @return const Integer 
         */
        static const Integer stringSize(int value) {
            int d = 1;
            if(value >= 0) {
                d = 0;
                value = -value;
            }
            int p = -10;
            for(int i = 1; i < 10; i++) {
                if(value > p) { return i + d; }
                p = p * 10;
            }
            return 10 + d;
        }

        template<class T>
        int retrieve() const {
            return this->value;
        }

        /**
         * @brief Get the Chars object
         * 
         * @param i 
         * @param index 
         * @param buf 
         * @return int 
         */
        static int getChars(int i, int index, unsigned char buf[]) {
            int q, r;
            int charPos = index;

            bool negative = i < 0;
            if (!negative) {
                i = -i;
            }

            while(i <= -100) {
                q = i / 100;
                r = (q * 100) - i;
                i = q;
                buf[--charPos] = DigitOnes[r];
                buf[--charPos] = DigitTens[r];
            }

            q = i / 10;
            r = (q * 10) - i;
            buf[--charPos] = (unsigned char)('0' + r);

            if (q < 0) {
                buf[--charPos] = (unsigned char)('0' - q);
            }

            if (negative) {
                buf[--charPos] = (unsigned char)'-';
            }

            return charPos;
        }

        /**
         * @brief Returns a const char* representing this Integer's value.
         * 
         * @return String 
         */
        const char* toCString() const override {
            String str = "";
            int number = this->value;
            if(number > 0) {
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = this->value;
                for(int i = 0; i < digits; i++) {
                    str += (number % 10) + '0';
                    number /= 10;
                }
                str.reverse();
                return str;
            }
            String tempString = "";
            if(number == 0) {
                tempString = "0";
            } else {
                tempString = "-";
                number = -number;
                int digits = 0;
                while(number > 0) {
                    number /= 10;
                    digits++;
                }
                number = -this->value;
                for(int i = 0; i < digits; i++) {
                    tempString += (number % 10) + '0';
                    number /= 10;
                }
                tempString.reverse();
            }
            str += tempString;
            str.insert(0, '-');
            str.pop();
            return str.cString();
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

        int valueOf() const {
            return this->value;
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
            return Integer(value).value;
        }

        operator int() {
            return Integer(value).value;
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

        String operator+(const char* other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append(other);
            return temp;
        }
        
        String operator+(String other) const {
            String temp = "";
            temp = temp + this->value;
            temp.append(other);
            return temp;
        }
        
        template<typename Type>
        double operator+(const Type& other) const {
            return Integer(this->value + other);
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


JAMSTL_NAMESPACE_END



#endif