#pragma once

#ifndef JAMSTL_FLOAT_H
#define JAMSTL_FLOAT_H 1
#include "Macros.h"
#include "Math.h"
#include "Object.h"

JAMSTL_NAMESPACE_BEGIN

    /**
     * @brief A float wrapper class
     * 
     */
    class Float extends Object {
    private:
        float value;
        float readFractions(String string, int start, int end, float &division) {
            float fractions = 0;
            int Count = 0;

            for (int k = start; string[k] != '\0'; k++) {
                if (string[start] == '0' && string[k] == '0') Count++;
                if (Count == (end - start)) return 0;
            }

            for (int j = start; string[j] != '\0'; j++) {
                if (string[j] > '9' || string[j] < '0') continue;
                division = division * 10;
                if(string[j] != '.') fractions = fractions * 10 + string[j] - '0';
                
            }
            division = fractions / division;
            return division;
        }

        float toFloat(String string) {
            float ToFloat = 0, division = 1;
            int i;
            usize Length = string.length();
            for (i = 0; string[i] != '\0'; i++) {
                if (i == 0 && string[i] == '.') continue;
                if (i != 0 && string[i] == '.') break;
                if (string[i] > '9' || string[i] < '0') continue;
                ToFloat = ToFloat * 10 + string[i] - '0';
            }
        
            if (string[i] == '.') {
                readFractions(string, i + 1, Length, division);
            }

            ToFloat = ToFloat + division;

            if (string[0] == '-') {
                if (ToFloat - (long long)ToFloat == 0) return -1 * (ToFloat - 1);
                return -ToFloat;
            }

            if (ToFloat - (long long)ToFloat == 0) return ToFloat - 1;
            return ToFloat;
        }

    public:
        Float() : value(0) {}
        Float(float value) : value(value) {}
        Float(const Float& other) : value(other.value) {}
        Float(const char* other) {
            this->value = toFloat(other);
        }

        Float(const String& other) {
            this->value = toFloat(other);
        }
        template<typename Type>
        Float(const Type& other) {
            this->value = static_cast<float>(other);
        }

        /**
         * @brief A method that returns the const char* of the value
         * 
         */
        // const char* toCString() const override {
        //     String string = String::valueOf(value);
        //     return string.toCString();
        // }




        Float& operator=(const Float& other) {
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



        // Max value of a float
        static constexpr float MAX_VALUE         = 0x1.fffffeP+127f;  // 3.4028235e+38f

        // A constant holding the smallest positive normal value of type float
        static constexpr float MIN_NORMAL        = 0x1.0p-126f;       // 1.17549435e-38f

        // Min value of a float
        static constexpr float MIN_VALUE         = 0x0.000002P-126f; // 1.4e-45f

        static constexpr int SIGNIFICAND_WIDTH   = 24;
        static constexpr int EXP_BIAS            = 127;
        static constexpr int SIGNIF_BIT_MASK     = 0x007FFFFF;
        static constexpr int SIGN_BIT_MASK       = 0x80000000;
        static constexpr int EXP_BIT_MASK        = 0x7F800000;


        /**
         * @brief Converts int bits to float
         * 
         * @param bits 
         * @return constexpr float 
         */
        static constexpr float intBitsToFloat(int32_t bits) {
            int32_t exp = (bits >> 23) & 0xFF;
            int32_t mant = bits & 0x7FFFFF;
            if(exp == 0) {
                if(mant == 0) {
                    return 0;
                }
                else {
                    return Math.minInfinity;
                }
            }
            else if(exp == 255) {
                if(mant == 0) {
                    return Math.Infinity;
                }
                else {
                    return Math.NaN;
                }
            }
            else {
                return Math.pow(2, exp - 127) * (1 + (mant / (1 << 23)));
            }
        }

        /**
         * @brief Converts float to raw int bits
         * 
         * @param value 
         * @return int 
         */
        static int floatToRawIntBits(float value) {
            int bits = (int)value;
            int sign = (bits >> 31) & 0x1;
            int exp = (bits >> 23) & 0xFF;
            int mant = bits & 0x7FFFFF;
            if(exp == 0) {
                if(mant == 0) {
                    return 0;
                }
                else {
                    return Math.minInfinity;
                }
            }
            else if(exp == 255) {
                if(mant == 0) {
                    return Math.Infinity;
                }
                else {
                    return Math.NaN;
                }
            }
            else {
                return (sign << 31) | ((exp + 127) << 23) | (mant & 0x7FFFFF);
            }
        }

        /**
         * @brief Converts float to int bits
         * 
         * @param value 
         * @return int 
         */
        static int floatToIntBits(float value) {
            if(!isNaN(value)) {
                return floatToRawIntBits(value);
            }
            return 0x7fc00000;
        }

        /**
         * @brief Returns if the float is NaN
         * 
         * @param value 
         * @return bool
         */
        static bool isNaN(float value) {
            return value != value;
        }

        /**
         * @brief Returns hash code of the float
         * 
         * @param value 
         * @return int 
         */
        static int hashCode(float value) {
            return floatToIntBits(value);
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
         * @brief A method that returns the (float) value
         * 
         * @return float 
         */
        float valueOf() const {
            return this->value;
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
            return Float(value).value;
        }

        operator float() {
            return Float(value).value;
        }



        Float& operator+=(const Float& other) {
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
        Float operator+(const Type& other) const {
            return Float(this->value + other);
        }




        Float operator-(const Float& other) const {
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

        bool operator||(const char* other) const {
            return this->value || atof(other);
        }

        template<typename Type>
        bool operator||(const Type& other) const {
            return this->value || other;
        }
        
    };


JAMSTL_NAMESPACE_END


#endif