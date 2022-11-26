#pragma once

#ifndef JAMSTL_OBJECTSTRING_H
#define JAMSTL_OBJECTSTRING_H 1
#include "../Macros.h"
#include "../Math.h"
#include "../Iterator.h"

JAMSTL_NAMESPACE_BEGIN

    /**
    * @brief A const char* wrapper class
    * 
    */
    class InnerString {
    private:
        char* value;
        usize Length = 0;
        
        usize stringLength(const char* str) const {
            usize len = 0;
            while(str[len] != '\0') {
                len++;
            }
            return len;
        }

        /**
        * @brief A method that copies a char* into the stirng
        * 
        * @param other 
        */
        void copy(const char* other) {
            this->Length = stringLength(other);
            this->value = new char[this->Length + 1];
            for(usize i = 0; i <= this->Length; i++) {
                this->value[i] = other[i];
            }
            this->value[this->Length] = '\0';
        }

        /**
        * @brief A method that checks the equality between two strings
        * 
        * @param other 
        * @return bool
        */
        bool equalityCompare(const char* other) const {
            for(usize i = 0; i <= this->Length; i++) {
                if(this->value[i] != other[i]) {
                    return false;
                }
            }
            return true;
        }

        bool equalityCompareString(const InnerString& other) const {
            for(usize i = 0; i <= this->Length; i++) {
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
        void reAllocate(usize newLength) {
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < this->Length; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
        }

        char* stringCopy(char* Destination, InnerString Source, usize Length) {
            for(int i = 0; i < Length; i++) {
                Destination[i] = Source[i];
            }

            return Destination;
        }

        byte *byetValue;
        byte coder;

    public:
    
        InnerString() : value(nullptr), Length(0) {}

        
        InnerString(const char* value) {
            this->Length = stringLength(value);
            this->value = new char[this->Length + 1];
            copy(value);
        }

        InnerString(const InnerString& other) {
            this->Length = other.Length;
            this->value = new char[this->Length + 1];
            this->copy(other.value);
            this->value[this->Length] = '\0';
        }

        InnerString(const char& value) {
            this->Length = 1;
            this->value = new char[this->Length + 1];
            this->value[0] = value;
            this->value[1] = '\0';
        }

        InnerString(const char* value, usize Length) {
            this->Length = Length;
            this->value = new char[this->Length + 1];
            for(usize i = 0; i < this->Length; i++) {
                this->value[i] = value[i];
            }
            this->value[this->Length] = '\0';
        }

        template<typename T>
        InnerString(const T& value) {
            this->append(value);
        }

        InnerString(byte* byetValue, byte coder) {
            this->byetValue = byetValue;
            this->coder = coder;
        }

        ~InnerString() {
            if(this->value != nullptr) {
                delete[] this->value;
            }
        }



        /**
        * @brief The largest possible string
        * 
        */
        static const usize LargeValue = -1;

        /**
        * @brief The Length of the string
        * 
        */
        const usize& length = this->Length;

        static constexpr bool COMPACT_STRINGS = true;

        static constexpr byte LATIN1 = 0;

        operator char*() const {
            return this->value;
        }



        int getInteger() const {
            return atoi(this->value);
        }

        bool isInteger() const {
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] < '0' || this->value[i] > '9') {
                    return false;
                }
            }
            return true;
        }

        float getFloat() const {
            return atof(this->value);
        }

        double getDouble() const {
            return atof(this->value);
        }

        bool getBoolean() const {
            return atoi(this->value) != 0;
        }

        void getChars(int srcBegin, int srcEnd, char dst[], int dstBegin) {
            if(srcBegin > srcEnd) {
                return;
            }
            if(srcBegin < 0) {
                srcBegin = 0;
            }
            if(srcEnd > this->Length) {
                srcEnd = this->Length;
            }
            if(dstBegin < 0) {
                dstBegin = 0;
            }
            for(int i = srcBegin, j = 0; i < srcEnd; i++, j++) {
                dst[j] = this->value[i];
            }
            dst[srcEnd - srcBegin] = '\0';
        }

        static const InnerString& Empty() {
            static InnerString EmptyString;
            return EmptyString;
        }

        static InnerString valueOf(const char* value) {
            return InnerString(value);
        }

        static InnerString valueOf(const char& value) {
            return InnerString(value);
        }

        template<typename Type>
        static InnerString valueOf(Type value) {
            InnerString str = "";
            str = str + value;
            return str;
        }

        /**
        * @brief A method that returns the Length of the string
        * 
        * @return usize 
        */
        usize size() const {
            return this->Length;
        }

        /**
        * @brief Set the Value object
        * 
        * @param value 
        */
        void setValue(const char* value) {
            this->Length = stringLength(value);
            this->value = new char[this->Length + 1];
            this->copy(value);
            this->value[this->Length] = '\0';
        }

        /**
        * @brief Set the Value object
        * 
        * @param other 
        */
        void setValue(const InnerString& other) {
            this->Length = other.Length;
            this->value = new char[this->Length + 1];
            this->copy(other.value);
            this->value[this->Length] = '\0';
        }

        /**
        * @brief A method to return the value of the string
        * 
        * @return char* 
        */
        InnerString get() const {
            return *this;
        }



        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return InnerString&
        */
        InnerString& append(const char* other) {
            usize newLength = this->Length + stringLength(other);
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& append(const InnerString& other) {
            usize newLength = this->Length + other.Length;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other.value[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        InnerString& append(const short& shortNumber) {
            InnerString str = "";
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

            InnerString tempString = "";
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

        InnerString& append(const int& intNumber) {
            InnerString str = "";
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

            InnerString tempString = "";
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

        InnerString& append(const long& longNumber) {
            InnerString str = "";
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

            InnerString tempString = "";
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

        InnerString& append(const long long& longLongNumber) {
            InnerString str = "";
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

            InnerString tempString = "";
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

        InnerString& append(const unsigned short& USInt) {
            InnerString str = "";
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

        InnerString& append(const unsigned int& UInt) {
            InnerString str = "";
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

        InnerString& append(const unsigned long& ULNumber) {
            InnerString str = "";
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

        InnerString& append(const unsigned long long& ULLNumber) {
            InnerString str = "";
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

        InnerString& append(const float& floatNumber) {
            if(floatNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double FNumber = Math.floor(floatNumber);
            double tempFloat = floatNumber - FNumber;
            InnerString str = "";

            // To turn the integer part to string
            long long mainDigits = Math.log10(FNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(FNumber, 10)) + '0';
                FNumber /= 10;
                FNumber = Math.trunc(FNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkFloat = Math.floor(floatNumber);
            if(floatNumber - checkFloat == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            FNumber = Math.floor(floatNumber);
            tempFloat = floatNumber - FNumber;
            long long digits = 0;

            if(tempFloat < 0) {
                tempFloat *= -1;
            }
            
            tempFloat *= 100000;

            double number = Math.round(tempFloat);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.round(number);
                }
                else digits++;
            }
            InnerString tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        InnerString& append(const double& doubleNumber) {
            if(doubleNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double DNumber = Math.floor(doubleNumber);
            double tempDouble = doubleNumber - DNumber;
            InnerString str = "";

            // To turn the integer part to string
            long long mainDigits = Math.log10(DNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(DNumber, 10)) + '0';
                DNumber /= 10;
                DNumber = Math.trunc(DNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkDouble = Math.floor(doubleNumber);
            if(doubleNumber - checkDouble == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            DNumber = Math.floor(doubleNumber);
            tempDouble = doubleNumber - DNumber;
            long long digits = 0;

            if(tempDouble < 0) {
                tempDouble *= -1;
            }
            
            tempDouble *= 100000;

            double number = Math.round(tempDouble);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.round(number);
                }
                else digits++;
            }
            InnerString tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        InnerString& append(const long double& longDoubleNumber) {
            if(longDoubleNumber == 0.0) {
                this->append("0.0");
                return *this;
            }

            double LDNumber = Math.floor(longDoubleNumber);
            double tmepLongDouble = longDoubleNumber - LDNumber;
            InnerString str = "";

            // To turn the integer part to string
            long long mainDigits = Math.log10(LDNumber) + 1;
            for(int i = 0; i < mainDigits; i++) {
                str += (Math.fmod(LDNumber, 10)) + '0';
                LDNumber /= 10;
                LDNumber = Math.trunc(LDNumber);
            }
            str.reverse();

            // To check if the double value == int part
            double checkLongDouble = Math.floor(longDoubleNumber);
            if(longDoubleNumber - checkLongDouble == 0) {
                str.reverse();
                str.append(".0");
                this->append(str);
                return *this;
            }

            // To turn the decimal part to string
            str.append(".");
            LDNumber = Math.floor(longDoubleNumber);
            tmepLongDouble = longDoubleNumber - LDNumber;
            long long digits = 0;

            if(tmepLongDouble < 0) {
                tmepLongDouble *= -1;
            }
            
            tmepLongDouble *= 100000;

            double number = Math.round(tmepLongDouble);
            for(int i = 0; i < 5; i++) {
                if(Math.fmod(number, 10) == 0) {
                    number /= 10;
                    number = Math.round(number);
                }
                else digits++;
            }
            InnerString tempString = "";
            char tempCharacter;
            for(int i = 0; i < digits; i++) {
                tempCharacter = Math.fmod(number, 10) + '0';
                tempString += tempCharacter;
                number /= 10;
                number = Math.round(number);
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        

        /**
        * @brief A method that makes a string empty
        * 
        * @return InnerString& 
        */
        InnerString& empty() {
            delete[] this->value;
            this->value = nullptr;
            this->Length = 0;
            return *this;
        }

        /**
        * @brief A method that clears a string
        * 
        * @return InnerString& 
        */
        InnerString& clear() {
            this->value[0] = '\0';
            return *this;
        }

        /**
        * @brief A method that erases a string specified ina range
        * 
        * @param start 
        * @param end 
        * @return InnerString& 
        */
        InnerString& erase(const usize& start, const usize& end) {
            if(start > end) {
                throw;
            }
            if(start > this->Length) {
                throw;
            }
            if(end > this->Length) {
                throw;
            }
            usize newLength = this->Length - (end - start);
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < start; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = start; i <= newLength; i++) {
                newValue[i] = this->value[i + (end - start)];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that erases a string starting from 0 to a specified index
        * 
        * @param start 
        * @return InnerString& 
        */
        InnerString& erase(const usize& start) {
            if(start > this->Length) {
                throw;
            }
            usize newLength = this->Length - 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < start; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = start; i <= newLength; i++) {
                newValue[i] = this->value[i + 1];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that erases a string starting from a specified index to the
        *  end and replaces it with a specified char
        * 
        * @param start 
        * @param end 
        * @param replacement 
        * @return InnerString& 
        */
        InnerString& erase(const usize& start, const usize& end, const char& replacement) {
            if(start > end) {
                throw;
            }
            if(start > this->Length) {
                throw;
            }
            if(end > this->Length) {
                throw;
            }
            usize newLength = this->Length - (end - start) + 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < start; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = start; i <= newLength; i++) {
                newValue[i] = replacement;
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }



        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& joins(const InnerString& other) {
            usize newLength = this->Length + other.Length;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other.value[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& joins(const char* other) {
            usize newLength = this->Length + stringLength(other);
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that appends a character to the end of a string
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& joins(const char& other) {
            usize newLength = this->Length + 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength - 1] = other;
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& push(const InnerString& other) {
            usize newLength = this->Length + other.Length;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other.value[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that appends a string to the end of the string
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& push(const char* other) {
            usize newLength = this->Length + stringLength(other);
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that appends a character to the end of a string
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& push(const char& other) {
            usize newLength = this->Length + 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength - 1] = other;
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that removes the last character of a string
        * 
        * @return InnerString& 
        */
        InnerString& pop() {
            if(this->Length == 0) {
                throw;
            }
            usize newLength = this->Length - 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < newLength; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that removes a character specified in an index
        * 
        * @param count 
        * @return InnerString& 
        */
        InnerString& pop(const usize& index) {
            if(index >= this->Length) {
                throw;
            }
            usize newLength = this->Length - 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < index; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = index; i < newLength; i++) {
                newValue[i] = this->value[i + 1];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that returns a character specified in an index
        * 
        * @param index 
        * @return char 
        */
        char charAt(const usize& index) const {
            if(index > this->Length) {
                throw;
            }
            return this->value[index];
        }

        /**
        * @brief Returns the Unicode value of the character at the specified location.
        * 
        * @param index 
        * @return int 
        */
        int charCodeAt(const usize& index) const {
            if(index > this->Length) {
                throw;
            }
            return this->value[index];
        }

        /**
        * @brief Returns the hash code for this string.
        * 
        * @return long long 
        */
        static long long hashCode(const InnerString& str) {
            long long hash = 0;
            for(usize i = 0; i < str.Length; i++) {
                hash = 31 * hash + str[i];
            }
            return hash;
        }

        /**
        * @brief A method that checks if a string starts with a specified string
        * 
        * @param other 
        * @return bool
        */
        bool startsWith(const InnerString& other) const {
            if(other.Length > this->Length) {
                return false;
            }
            for(usize i = 0; i < other.Length; i++) {
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
            usize otherLength = stringLength(other);
            if(otherLength > this->Length) {
                return false;
            }
            for(usize i = 0; i < otherLength; i++) {
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
            if(this->Length < 1) {
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
        bool endsWith(const InnerString& other) const {
            if(other.Length > this->Length) {
                throw;
            }
            for(usize i = this->Length - other.Length; i < this->Length; i++) {
                if(this->value[i] != other.value[i - (this->Length - other.Length)]) {
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
            usize otherLength = stringLength(other);
            if(otherLength > this->Length) {
                throw;
            }
            for(usize i = this->Length - otherLength; i < this->Length; i++) {
                if(this->value[i] != other[i - (this->Length - otherLength)]) {
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
            if(this->Length < 1) {
                return false;
            }
            if(this->value[this->Length - 1] != other) {
                return false;
            }
            return true;
        }

        /**
        * @brief A method that makes a string lowercase
        * 
        * @return InnerString& 
        */
        InnerString& toLower() {
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] >= 'A' && this->value[i] <= 'Z') {
                    this->value[i] += 32;
                }
            }
            return *this;
        }

        /**
        * @brief A method that makes a string uppercase
        * 
        * @return InnerString& 
        */
        InnerString& toUpper() {
            for(usize i = 0; i < this->Length; i++) {
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
        * @return InnerString& 
        */
        InnerString& trim() {
            usize start = 0;
            usize end = this->Length;
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] != ' ' && this->value[i] != '\t' && this->value[i] != '\n' && this->value[i] != '\r') {
                    start = i;
                    break;
                }
            }
            for(usize i = this->Length - 1; i > 0; i--) {
                if(this->value[i] != ' ' && this->value[i] != '\t' && this->value[i] != '\n' && this->value[i] != '\r') {
                    end = i + 1;
                    break;
                }
            }
            if(start == 0 && end == this->Length) {
                return *this;
            }
            usize newLength = end - start;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < newLength; i++) {
                newValue[i] = this->value[i + start];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief Returns a string that contains the concatenation of two or more strings.
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& concat(const InnerString& other) {
            usize newLength = this->Length + other.Length;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other.value[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief Returns a string that contains the concatenation of two or more strings.
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& concat(const char* other) {
            usize otherLength = stringLength(other);
            usize newLength = this->Length + otherLength;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i <= newLength; i++) {
                newValue[i] = other[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief Returns a string that contains the concatenation of a string and a char
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& concat(const char& other) {
            usize newLength = this->Length + 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i <= this->Length; i++) {
                newValue[i] = this->value[i];
            }
            newValue[newLength - 1] = other;
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief Returns the last occurrence of a substring in the string.
        * 
        * @param other 
        * @return int 
        */
        int lastIndexOf(const char& other) const {
            for(int i = this->Length - 1; i >= 0; i--) {
                if(this->value[i] == other) {
                    return i;
                }
            }
            return -1;
        }

        /**
        * @brief Returns true if searchString appears as a substring of the result of converting this
        * object to a InnerString, at one or more positions that are
        * greater than or equal to position; otherwise, returns false.
        * 
        * @param other 
        * @return bool
        */
        bool includes(const char& other) const {
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == other) {
                    return true;
                }
            }
            return false;
        }

        /**
        * @brief Returns true if searchString appears as a substring of the result of converting this
        * object to a InnerString, at one or more positions that are
        * greater than or equal to position; otherwise, returns false.
        * 
        * @param other 
        * @return bool
        */
        bool includes(const InnerString& other) const {
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == other.value[0]) {
                    bool found = true;
                    for(usize j = 0; j < other.Length; j++) {
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
        * object to a InnerString, at one or more positions that are
        * greater than or equal to position; otherwise, returns false.
        * 
        * @param other 
        * @return bool
        */
        bool includes(const char* other) const {
            usize otherLength = stringLength(other);
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == other[0]) {
                    bool found = true;
                    for(usize j = 0; j < otherLength; j++) {
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
        * @brief Returns a InnerString value that is made from count copies appended together.
        * If count is 0, the empty string is returned.
        * 
        * @param count 
        * @return InnerString& 
        */
        InnerString& repeat(usize count) {
            usize newLength = this->Length * count;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < newLength; i++) {
                newValue[i] = this->value[i % this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief Returns the substring at the specified location within a InnerString object.
        * 
        * @param start 
        * @param end 
        * @return InnerString 
        */
        InnerString substring(usize start, usize end) const {
            if(start > end) {
                usize temp = start;
                start = end;
                end = temp;
            }
            if(start > this->Length) {
                start = this->Length;
            }
            if(end > this->Length) {
                end = this->Length;
            }
            usize newLength = end - start;
            InnerString newValue = "";
            for(usize i = 0; i < newLength; i++) {
                newValue += this->value[i + start];
            }
            return newValue;
        }

        /**
        * @brief Returns the substring at the specified location within a InnerString object.
        * 
        * @param start 
        * @return InnerString 
        */
        InnerString substring(usize start) const {
            return this->substring(start, this->Length);
        }

        /**
        * @brief A method that replaces a character in a string with another character.
        * 
        * @param old 
        * @param newChar 
        * @return InnerString& 
        */
        InnerString& replace(const char& old, const char& newChar) {
            for(usize i = 0; i < this->Length; i++) {
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
        * @return InnerString& 
        */
        InnerString& replace(const InnerString& old, const InnerString& newString) {
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == old.value[0]) {
                    bool found = true;
                    for(usize j = 0; j < old.Length; j++) {
                        if(this->value[i + j] != old.value[j]) {
                            found = false;
                            break;
                        }
                    }
                    if(found) {
                        this->value[i] = newString.value[0];
                        for(usize j = 1; j < newString.Length; j++) {
                            this->value[i + j] = newString.value[j];
                        }
                        i += newString.Length - 1;
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
        * @return InnerString& 
        */
        InnerString& replace(const char* old, const char* newString) {
            usize oldLength = stringLength(old);
            usize newLength = stringLength(newString);
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == old[0]) {
                    bool found = true;
                    for(usize j = 0; j < oldLength; j++) {
                        if(this->value[i + j] != old[j]) {
                            found = false;
                            break;
                        }
                    }
                    if(found) {
                        this->value[i] = newString[0];
                        for(usize j = 1; j < newLength; j++) {
                            this->value[i + j] = newString[j];
                        }
                        i += newLength - 1;
                    }
                }
            }
            return *this;
        }

        InnerString& replace(usize start, usize end, const InnerString& newString) {
            if(start > end) {
                usize temp = start;
                start = end;
                end = temp;
            }
            if(start > this->Length) {
                start = this->Length;
            }
            if(end > this->Length) {
                end = this->Length;
            }
            usize newLength = end - start;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < newLength; i++) {
                newValue[i] = this->value[i + start];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that replaces a character in a string with another character.
        * 
        * @param old 
        * @param newChar 
        * @return InnerString& 
        */
        InnerString& replaceFirst(const char& old, const char& newChar) {
            for(usize i = 0; i < this->Length; i++) {
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
        * @return InnerString& 
        */
        InnerString& replaceFirst(const InnerString& old, const InnerString& newString) {
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == old.value[0]) {
                    bool found = true;
                    for(usize j = 0; j < old.Length; j++) {
                        if(this->value[i + j] != old.value[j]) {
                            found = false;
                            break;
                        }
                    }
                    if(found) {
                        this->value[i] = newString.value[0];
                        for(usize j = 1; j < newString.Length; j++) {
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
        * @return InnerString& 
        */
        InnerString& replaceFirst(const char* old, const char* newString) {
            usize oldLength = stringLength(old);
            usize newLength = stringLength(newString);
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == old[0]) {
                    bool found = true;
                    for(usize j = 0; j < oldLength; j++) {
                        if(this->value[i + j] != old[j]) {
                            found = false;
                            break;
                        }
                    }
                    if(found) {
                        this->value[i] = newString[0];
                        for(usize j = 1; j < newLength; j++) {
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
            for(usize i = 0; i < this->Length; i++) {
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
        * @return InnerString& 
        */
        InnerString& swap(InnerString& other) {
            char* temp = this->value;
            this->value = other.value;
            other.value = temp;
            usize tempLength = this->Length;
            this->Length = other.Length;
            other.Length = tempLength;
            return *this;
        }

        /**
        * @brief A method that checks if a string is empty or not
        * 
        * @return bool
        */
        bool isEmpty() const {
            if(this->Length == 0) {
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
        bool compare(const InnerString& other) const {
            if(this->Length != other.Length) {
                return false;
            }
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] != other.value[i]) {
                    return false;
                }
            }
            return true;
        }

        /**
         * @brief A method checks if two strings are equal
         * 
         * @param other 
         * @return bool
         */
        bool equals(const InnerString& other) const {
            if(this->Length != other.Length) {
                return false;
            }
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] != other.value[i]) {
                    return false;
                }
            }
            return true;
        }

        /**
        * @brief A method checks if two strings are equal ignoring the case
        * 
        * @param other 
        * @return bool
        */
        bool equalIgnoreCase(const InnerString& other) const {
            if(this->Length != other.Length) {
                return false;
            }
            for(usize i = 0; i < this->Length; i++) {
                if(this->tolower(this->value[i]) != this->tolower(other.value[i])) {
                    return false;
                }
            }
            return true;
        }

        /**
        * @brief A method that reverses a string
        * 
        * @return InnerString& 
        */
        InnerString& reverse() {
            for(usize i = 0; i < this->Length / 2; i++) {
                char temp = this->value[i];
                this->value[i] = this->value[this->Length - i - 1];
                this->value[this->Length - i - 1] = temp;
            }
            return *this;
        }

        /**
        * @brief A method that returns the type of the object
        * 
        * @return const char* 
        */
        const char* type() const {
            return "InnerString";
        }

        /**
        * @brief A method Capitalize the first letter of a string and makes the rest 
        * of the letters lowercase
        * 
        * @return InnerString& 
        */
        InnerString& capitalize() {
            for(usize i = 0; i < this->Length; i++) {
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
        usize count(const char& other) const {
            usize count = 0;
            for(usize i = 0; i < this->Length; i++) {
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
        usize count(const InnerString& other) const {
            usize count = 0;
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == other.value[0]) {
                    bool found = true;
                    for(usize j = 0; j < other.Length; j++) {
                        if(this->value[i + j] != other.value[j]) {
                            found = false;
                            break;
                        }
                    }
                    if(found) {
                        count++;
                        i += other.Length - 1;
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
        usize count(const char* other) const {
            usize count = 0;
            usize otherLength = stringLength(other);
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == other[0]) {
                    bool found = true;
                    for(usize j = 0; j < otherLength; j++) {
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
        * @return InnerString 
        */
        InnerString casefold() const {
            InnerString result = *this;
            for(usize i = 0; i < this->Length; i++) {
                result.value[i] = tolower(this->value[i]);
            }
            return result;
        }

        /**
        * @brief Converts uppercase to lowercase and lowercase to uppercase
        * 
        * @return InnerString& 
        */
        InnerString& swapCase() {
            for(usize i = 0; i < this->Length; i++) {
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
            for(usize i = 0; i < this->Length; i++) {
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
        bool find(const InnerString& other) const {
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == other.value[0]) {
                    bool found = true;
                    for(usize j = 0; j < other.Length; j++) {
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
            usize otherLength = stringLength(other);
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] == other[0]) {
                    bool found = true;
                    for(usize j = 0; j < otherLength; j++) {
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
            for(usize i = 0; i < this->Length; i++) {
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
            for(usize i = 0; i < this->Length; i++) {
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
        * @return InnerString& 
        */
        InnerString& insert(usize index, const char* other) {
            if(index > this->Length) {
                return *this;
            }

            usize otherLength = stringLength(other);
            usize newLength = this->Length + otherLength;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < index; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = 0; i < otherLength; i++) {
                newValue[index + i] = other[i];
            }
            for(usize i = index; i < this->Length; i++) {
                newValue[otherLength + i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that inserts a string into another string at a specified index
        * 
        * @param index 
        * @param other 
        * @return InnerString& 
        */
        InnerString& insert(usize index, const InnerString& other) {
            if(index > this->Length) {
                return *this;
            }

            usize newLength = this->Length + other.Length;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < index; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = 0; i < other.Length; i++) {
                newValue[index + i] = other.value[i];
            }
            for(usize i = index; i < this->Length; i++) {
                newValue[other.Length + i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        /**
        * @brief A method that inserts a char into another string at a specified index
        * 
        * @param index 
        * @param other 
        * @return InnerString& 
        */
        InnerString& insert(usize index, const char& other) {
            if(index > this->Length) {
                return *this;
            }

            usize newLength = this->Length + 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < index; i++) {
                newValue[i] = this->value[i];
            }
            newValue[index] = other;
            for(usize i = index; i < this->Length; i++) {
                newValue[1 + i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
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
            return this->value[this->Length - 1];
        }

        /**
        * @brief A method that returns a C style string
        * 
        * @return const char* 
        */
        const char* cString() {
            char* cString = new char[this->Length + 1];
            for(usize i = 0; i < this->Length; i++) {
                cString[i] = this->value[i];
            }
            cString[this->Length] = '\0';
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
            char* cString = new char[this->Length + 1];
            for(usize i = 0; i < this->Length; i++) {
                cString[i] = this->value[i];
            }
            cString[this->Length] = '\0';
            delete[] this->value;
            this->value = cString;
            return this->value;
            return cString;
        }

        /**
        * @brief Returns a string with the given prefix removed if it exists
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& removePrefix(const char& other) {
            if(this->value[0] == other) {
                usize newLength = this->Length - 1;
                char* newValue = new char[newLength + 1];
                for(usize i = 1; i < this->Length; i++) {
                    newValue[i - 1] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->Length = newLength;
            }
            return *this;
        }

        /**
        * @brief Returns a string with the given prefix removed if it exists
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& removePrefix(const InnerString& other) {
            if(this->value[0] == other.value[0]) {
                usize otherLength = other.Length;
                usize newLength = this->Length - otherLength;
                char* newValue = new char[newLength + 1];
                for(usize i = otherLength; i < this->Length; i++) {
                    newValue[i - otherLength] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->Length = newLength;
            }
            return *this;
        }

        /**
        * @brief Returns a string with the given prefix removed if it exists
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& removePrefix(const char* other) {
            usize otherLength = stringLength(other);
            if(this->value[0] == other[0]) {
                usize newLength = this->Length - otherLength;
                char* newValue = new char[newLength + 1];
                for(usize i = otherLength; i < this->Length; i++) {
                    newValue[i - otherLength] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->Length = newLength;
            }
            return *this;
        }

        /**
        * @brief Returns a string with the given suffix removed if it exists
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& removeSuffix(const char& other) {
            if(this->value[this->Length - 1] == other) {
                usize newLength = this->Length - 1;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < newLength; i++) {
                    newValue[i] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->Length = newLength;
            }
            return *this;
        }

        /**
        * @brief Returns a string with the given suffix removed if it exists
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& removeSuffix(const InnerString& other) {
            if(this->value[this->Length - 1] == other.value[other.Length - 1]) {
                usize otherLength = other.Length;
                usize newLength = this->Length - otherLength;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < newLength; i++) {
                    newValue[i] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->Length = newLength;
            }
            return *this;
        }

        /**
        * @brief Returns a string with the given suffix removed if it exists
        * 
        * @param other 
        * @return InnerString& 
        */
        InnerString& removeSuffix(const char* other) {
            usize otherLength = stringLength(other);
            if(this->value[this->Length - 1] == other[otherLength - 1]) {
                usize newLength = this->Length - otherLength;
                char* newValue = new char[newLength + 1];
                for(usize i = 0; i < newLength; i++) {
                    newValue[i] = this->value[i];
                }
                newValue[newLength] = '\0';
                delete[] this->value;
                this->value = newValue;
                this->Length = newLength;
            }
            return *this;
        }

        /**
        * @brief A method that checks if all characters in the string are lowercase
        * 
        * @return bool
        */
        bool isLower() const {
            for(usize i = 0; i < this->Length; i++) {
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
            for(usize i = 0; i < this->Length; i++) {
                if(this->value[i] < 'A' || this->value[i] > 'Z') {
                    return false;
                }
            }
            return true;
        }



        InnerString& operator=(const char* value) {
            this->Length = stringLength(value);
            this->value = new char[this->Length + 1];
            this->copy(value);
            this->value[this->Length] = '\0';
            return *this;
        }

        InnerString& operator=(const InnerString& other) {
            this->Length = other.Length;
            this->value = new char[this->Length + 1];
            this->copy(other.value);
            return *this;
        }

        InnerString& operator=(const char& value) {
            this->Length = 1;
            this->value = new char[this->Length + 1];
            this->value[0] = value;
            this->value[1] = '\0';
            return *this;
        }



        InnerString& operator+=(const char* value) {
            usize newLength = this->Length + stringLength(value);
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i < newLength; i++) {
                newValue[i] = value[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        InnerString& operator+=(const InnerString& other) {
            usize newLength = this->Length + other.Length;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < this->Length; i++) {
                newValue[i] = this->value[i];
            }
            for(usize i = this->Length; i < newLength; i++) {
                newValue[i] = other.value[i - this->Length];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        InnerString& operator+=(const char& value) {
            usize newLength = this->Length + 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < this->Length; i++) {
                newValue[i] = this->value[i];
            }
            newValue[this->Length] = value;
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        InnerString& operator<<(const byte& value) {
            usize newLength = this->Length + 1;
            char* newValue = new char[newLength + 1];
            for(usize i = 0; i < this->Length; i++) {
                newValue[i] = this->value[i];
            }
            newValue[this->Length] = value;
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
            return *this;
        }

        InnerString& operator<<(const int& intNumber) {
            InnerString str = "";
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

            InnerString tempString = "";
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

        InnerString& operator<<(const unsigned& unsignedIntNumber) {
            InnerString str = "";
            unsigned number = unsignedIntNumber;
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

        InnerString& operator<<(const short& shortNumber) {
            InnerString str = "";
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
            InnerString tempString = "";
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

        InnerString& operator<<(const unsigned short& unsignedShortNumber) {
            InnerString str = "";
            unsigned short number = unsignedShortNumber;
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

        InnerString& operator<<(const long& longNumber) {
            InnerString str = "";
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
            InnerString tempString = "";
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

        InnerString& operator<<(const unsigned long& unsignedLongNumber) {
            InnerString str = "";
            unsigned long number = unsignedLongNumber;
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

        InnerString& operator<<(const long long& LLNumber) {
            InnerString str = "";
            InnerString newString = *this;
            long long number = LLNumber;
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
            InnerString tempString = "";
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

        InnerString& operator<<(const unsigned long long& ULLNumber) {
            InnerString str = "";
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





        InnerString operator+(const char* value) {
            InnerString newString = *this;
            newString += value;
            return newString;
        }

        InnerString operator+(const InnerString& other) {
            InnerString newString = *this;
            newString += other;
            return newString;
        }

        InnerString operator+(const char& value) {
            InnerString newString = *this;
            newString += value;
            return newString;
        }

        InnerString operator+(const byte& value) {
            InnerString newString = *this;
            newString += value;
            return newString;
        }

        InnerString operator+(const int& intNumber) {
            InnerString str = "";
            InnerString newString = *this;
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
                newString.append(str);
                return newString;
            }

            InnerString tempString = "";
            if(number == 0) {
                tempString = "0";
                newString.append(tempString);
                return newString;
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
            newString.append(str);
            return newString;
        }

        InnerString operator+(const unsigned& unsignedIntNumber) {
            InnerString str = "";
            InnerString newString = *this; 
            unsigned number = unsignedIntNumber;
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
                newString.append(str);
                return newString;
            }
            str = "0";
            newString.append(str);
            return newString;
        }

        InnerString operator+(const short& shortNumber) {
            InnerString str = "";
            InnerString newString = *this;
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
                newString.append(str);
                return newString;
            }
            InnerString tempString = "";
            if(number == 0) {
                tempString = "0";
                newString.append(tempString);
                return newString;
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
            newString.append(str);
            return newString;
        }

        InnerString operator+(const unsigned short& unsignedShortNumber) {
            InnerString str = "";
            InnerString newString = *this;
            unsigned short number = unsignedShortNumber;
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
                newString.append(str);
                return newString;
            }
            str = "0";
            newString.append(str);
            return newString;
        }

        InnerString operator+(const long& longNumber) {
            InnerString str = "";
            InnerString newString = *this;
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
                newString.append(str);
                return newString;
            }
            InnerString tempString = "";
            if(number == 0) {
                tempString = "0";
                newString.append(tempString);
                return newString;
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
            newString.append(str);
            return newString;
        }

        InnerString operator+(const unsigned long& unsignedLongNumber) {
            InnerString str = "";
            InnerString newString = *this;
            unsigned long number = unsignedLongNumber;
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
                newString.append(str);
                return newString;
            }
            str = "0";
            newString.append(str);
            return newString;
        }

        InnerString operator+(const long long& LLNumber) {
            InnerString str = "";
            InnerString newString = *this;
            long long number = LLNumber;
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
                newString.append(str);
                return newString;
            }
            InnerString tempString = "";
            if(number == 0) {
                tempString = "0";
                newString.append(tempString);
                return newString;
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
            newString.append(str);
            return newString;
        }

        InnerString operator+(const unsigned long long& ULLNumber) {
            InnerString str = "";
            InnerString newString = *this;
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
                newString.append(str);
                return newString;
            }
            str = "0";
            newString.append(str);
            return newString;
        }

        InnerString operator+(const float& floatNumber) {
            if(floatNumber == 0) {
                this->append("0");
                return *this;
            }
            if(floatNumber == (long long)floatNumber) {
                InnerString tempStr = "";
                tempStr = tempStr + (long long)floatNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = floatNumber;
            float tempFloat = floatNumber - LLNumber;
            InnerString str = "";
            str = str + LLNumber;
            str.append(".");
            long long digits = 0;

            tempFloat = floatNumber - LLNumber;
            if(tempFloat < 0) {
                tempFloat *= -1;
            }
            tempFloat *= 100000;

            long long number = Math.round(tempFloat);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            InnerString tempString = "";
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

        InnerString operator+(const double& doubleNumber) {
            if(doubleNumber == 0) {
                this->append("0");
                return *this;
            }
            if(doubleNumber == (long long)doubleNumber) {
                InnerString tempStr = "";
                tempStr = tempStr + (long long)doubleNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = doubleNumber;
            double tempDouble = doubleNumber - LLNumber;
            InnerString str = "";
            str = str + LLNumber;
            str += ".";
            long long digits = 0;

            tempDouble = doubleNumber - LLNumber;
            if(tempDouble < 0) {
                tempDouble *= -1;
            }
            tempDouble *= 100000;

            long long number = Math.round(tempDouble);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            InnerString tempString = "";
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }

        InnerString operator+(const long double& longDoubleNumber) {
            if(longDoubleNumber == 0) {
                this->append("0");
                return *this;
            }
            if(longDoubleNumber == (long long)longDoubleNumber) {
                InnerString tempStr = "";
                tempStr = tempStr + (long long)longDoubleNumber;
                this->append(tempStr);
                this->append(".0");
                return *this;
            }
            long long LLNumber = longDoubleNumber;
            long double tempLongDouble = longDoubleNumber - LLNumber;
            InnerString str = "";
            str = str + LLNumber;
            str += ".";
            long long digits = 0;

            tempLongDouble = longDoubleNumber - LLNumber;
            if(tempLongDouble < 0) {
                tempLongDouble *= -1;
            }
            tempLongDouble *= 100000;

            // long long number = Math.round(tempLongDouble);
            long long number = Math.round(tempLongDouble);
            for(int i = 0; i < 5; i++) {
                if(number % 10 == 0) {
                    number /= 10;
                }
                else digits++;
            }
            InnerString tempString = "";
            for(int i = 0; i < digits; i++) {
                tempString += (number % 10) + '0';
                number /= 10;
            }
            tempString.reverse();
            str += tempString;
            this->append(str);
            return *this;
        }



        InnerString operator*(usize times) const {
            InnerString result = *this;
            for(usize i = 0; i < times - 1; i++) {
                result += *this;
            }
            return result;
        }



        bool operator==(const char* other) const {
            return this->equalityCompare(other);
        }

        bool operator==(const InnerString& other) const {
            return this->equalityCompareString(other.value);
        }

        bool operator==(const char& other) const {
            return this->value[0] == other;
        }



        bool operator!=(const char* other) const {
            return !this->equalityCompare(other);
        }

        bool operator!=(const InnerString& other) const {
            return !this->equalityCompare(other.value);
        }

        bool operator!=(const char& other) const {
            return this->value[0] != other;
        }



        bool operator<(const char* other) const {
            return this->Length < stringLength(other);
        }

        bool operator<(const InnerString& other) const {
            return this->Length < other.Length;
        }

        bool operator<(const char& other) const {
            return this->value[0] < other;
        }



        bool operator>(const char* other) const {
            return this->Length > stringLength(other);
        }

        bool operator>(const InnerString& other) const {
            return this->Length > other.Length;
        }

        bool operator>(const char& other) const {
            return this->value[0] > other;
        }



        bool operator<=(const char* other) const {
            return this->Length <= stringLength(other);
        }

        bool operator<=(const InnerString& other) const {
            return this->Length <= other.Length;
        }

        bool operator<=(const char& other) const {
            return this->value[0] <= other;
        }



        bool operator>=(const char* other) const {
            return this->Length >= stringLength(other);
        }

        bool operator>=(const InnerString& other) const {
            return this->Length >= other.Length;
        }

        bool operator>=(const char& other) const {
            return this->value[0] >= other;
        }


        bool operator!() const {
            return this->Length == 0;
        }

        bool operator&&(const InnerString& other) const {
            return this->Length && other.Length;
        }

        bool operator||(const InnerString& other) const {
            return this->Length || other.Length;
        }

        bool operator&&(const char& other) const {
            return this->value[0] && other;
        }

        bool operator||(const char& other) const {
            return this->value[0] || other;
        }

        bool operator&&(const char* other) const {
            return this->Length && stringLength(other);
        }

        bool operator||(const char* other) const {
            return this->Length || stringLength(other);
        }

        bool operator&&(const bool& other) const {
            return this->Length && other;
        }

        bool operator||(const bool& other) const {
            return this->Length || other;
        }

        bool operator!=(const bool& other) const {
            return !this->Length == other;
        }

        bool operator==(const bool& other) const {
            return this->Length == other;
        }

        InnerString& operator--() {
            this->Length--;
            char* newValue = new char[this->Length + 1];
            for(usize i = 0; i < this->Length; i++) {
                newValue[i] = this->value[i + 1];
            }
            newValue[this->Length] = '\0';
            delete[] this->value;
            this->value = newValue;
            return *this;
        }

        InnerString operator--(int) {
            InnerString result = *this;
            this->Length--;
            char* newValue = new char[this->Length + 1];
            for(usize i = 0; i < this->Length; i++) {
                newValue[i] = this->value[i + 1];
            }
            newValue[this->Length] = '\0';
            delete[] this->value;
            this->value = newValue;
            return result;
        }



        // friend std::ostream& operator<<(std::ostream& out, const InnerString& string) {
        //     out << string.value;
        //     return out;
        // }

        // friend std::istream& operator>>(std::istream& in, InnerString& string) {
        //     string.reAllocate(0);
        //     char c;
        //     while (in.get(c)) {
        //         if(c == '\n') {
        //             break;
        //         }
        //         string += c;
        //     }
        //     return in;
        // }

        friend InnerString operator+(const char* string, const InnerString& other) {
            InnerString result = string;
            result += other;
            return result;
        }

        friend InnerString operator+(const InnerString& string, const char* other) {
            InnerString result = string;
            result += other;
            return result;
        }

        friend InnerString operator+(const char& string, const InnerString& other) {
            InnerString result = string;
            result += other;
            return result;
        }

        friend InnerString operator+(const InnerString& string, const char& other) {
            InnerString result = string;
            result += other;
            return result;
        }

        class _Iterator {
            friend class InnerString;
            private:
                char* value;
                usize Length;
                usize index;
                _Iterator(char* value, usize Length, usize index) {
                    this->value = value;
                    this->Length = Length;
                    this->index = index;
                }
            public:
                _Iterator& operator++() {
                    this->index++;
                    return *this;
                }
                _Iterator operator++(int) {
                    _Iterator result = *this;
                    this->index++;
                    return result;
                }
                _Iterator& operator--() {
                    this->index--;
                    return *this;
                }
                _Iterator operator--(int) {
                    _Iterator result = *this;
                    this->index--;
                    return result;
                }
                _Iterator& operator+=(usize offset) {
                    this->index += offset;
                    return *this;
                }
                _Iterator& operator-=(usize offset) {
                    this->index -= offset;
                    return *this;
                }
                _Iterator operator+(usize offset) {
                    _Iterator result = *this;
                    result += offset;
                    return result;
                }
                _Iterator operator-(usize offset) {
                    _Iterator result = *this;
                    result -= offset;
                    return result;
                }
                bool operator==(const _Iterator& other) const {
                    return this->index == other.index;
                }
                bool operator!=(const _Iterator& other) const {
                    return this->index != other.index;
                }
                bool operator<(const _Iterator& other) const {
                    return this->index < other.index;
                }
                bool operator>(const _Iterator& other) const {
                    return this->index > other.index;
                }
                bool operator<=(const _Iterator& other) const {
                    return this->index <= other.index;
                }
                bool operator>=(const _Iterator& other) const {
                    return this->index >= other.index;
                }
                char& operator*() {
                    return this->value[this->index];
                }
                char& operator[](usize index) {
                    return this->value[this->index + index];
                }
                char operator*() const {
                    return this->value[this->index];
                }
                char operator[](usize index) const {
                    return this->value[this->index + index];
                }
        };

        _Iterator begin() const {
            return _Iterator(this->value, this->Length, 0);
        }

        _Iterator end() const {
            return _Iterator(this->value, this->Length, this->Length);
        }

        _Iterator rbegin() const {
            return _Iterator(this->value, this->Length, this->Length - 1);
        }

        _Iterator rend() const {
            return _Iterator(this->value, this->Length, 0);
        }
        

        /**
         * @brief A helper function to resize the string
         *
         * @param newLength
         */
        void resize(usize newLength) {
            char *newValue = new char[newLength + 1];
            for (usize i = 0; i < this->Length; i++)
            {
                newValue[i] = this->value[i];
            }
            newValue[newLength] = '\0';
            delete[] this->value;
            this->value = newValue;
            this->Length = newLength;
        }
    };

JAMSTL_NAMESPACE_END


#endif