#pragma once 

#ifndef JAMSTL_SHORT_H
#define JAMSTL_SHORT_H 
#include "Number.h"

JAMSTL_NAMESPACE_BEGIN

    /**
     * @brief A short wrapper class
     * 
     */
    class Short extends Number {
    private:
        short value;
        short toSInt(String string) {
            int ToShort = 0;

            for (int i = 0; string[i] != '\0'; i++) {
                if (i == 0 && (string[i] == '.' || string[i] == '-')) continue;
                else if(string[i] == '.') break;
                if (string[i] > '9' || string[i] < '0') break;
                ToShort = ToShort * 10 + string[i] - '0';
            }

            if (string[0] == '-') return -ToShort;
            
            return ToShort;
        }

    public:
        Short() : value(0) {}

        template<typename Type>
        Short(const Type& value) {
            this->value = static_cast<short>(value);
        }

        Short(const char* other) {
            this->value = toSInt(other);
        }

        Short(String other) {
            this->value = toSInt(other);
        }

        Short(const Short& other) : value(other.value) {}




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


        int intValue() const override {
            return static_cast<int>(value);
        }

        long long longValue() const override {
            return static_cast<long long>(value);
        }

        float floatValue() const override {
            return static_cast<float>(value);
        }

        double doubleValue() const override {
            return static_cast<double>(value);
        }

        bool equals(const Object& other) const override {
            if(Object::instanceof<Number>(&other)) {
                return value == static_cast<const Number&>(other).intValue();
            }
            return false;
        }


        /**
         * @brief Returns the hash code of the object
         * 
         * @param value 
         * @return int 
         */
        static int hashCode(short value) {
            return static_cast<int>(value);
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

        short valueOf() const {
            return this->value;
        }

        operator short() const {
            return this->value;
        }

        operator short() {
            return this->value;
        }



        Short& operator=(const Short& other) {
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

        Number& operator=(const int& other) override {
            this->value = other;
            return *this;
        }

        Number& operator=(const float& other) override {
            this->value = other;
            return *this;
        }

        Number& operator=(const double& other) override {
            this->value = other;
            return *this;
        }

        Number& operator=(const long& other) override {
            this->value = other;
            return *this;
        }

        Number& operator=(const long long& other) override {
            this->value = other;
            return *this;
        }

        Number& operator=(const short& other) override {
            this->value = other;
            return *this;
        }

        Number& operator=(const Number& number) override {
            this->value = static_cast<short>(number.intValue());
            return *this;
        }




        
        Short& operator+=(const Short& other) {
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
        Short operator+(const Type& other) const {
            return Short(this->value + other);
        }




        Short operator-(const Short& other) const {
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
            return short(!this->value);
        }
        
    };



JAMSTL_NAMESPACE_END


#endif