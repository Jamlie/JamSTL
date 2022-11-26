#pragma once

#ifndef JAMSTL_DOUBLE_H
#define JAMSTL_DOUBLE_H 1
#include "Macros.h"
#include "BasicString.h"
#include "Math.h"
#include "Object.h"
#include <ostream>
#include <istream>
#include <cstring>

JAMSTL_NAMESPACE_BEGIN

    /**
    * @brief A double wrapper class.
    * 
    */
    class Double extends Object {
    private:
        double value;

        double readFractions(String string, int start, int end, double &division) {
            double fractions = 0;
            int j;
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

        double toDouble(String string) {
            double ToDouble = 0, division = 1;
            usize Length = string.length;
            int i = 0;

            for (i = 0; string[i] != '\0'; i++) {
                if (i == 0 && string[i] == '.') continue;
                if (i != 0 && string[i] == '.') break;
                if (string[i] > '9' || string[i] < '0') continue;
                ToDouble = ToDouble * 10 + string[i] - '0';
            }

            if (string[i] == '.') {
                readFractions(string, i + 1, Length, division);
            }

            ToDouble = ToDouble + division;
            if (string[0] == '-') {
                if (ToDouble - (long long)ToDouble == 0) return -1 * (ToDouble - 1);
                return -ToDouble;
            }

            if (ToDouble - (long long)ToDouble == 0) return ToDouble - 1;
            return ToDouble;
        }

    public:
        Double() : value(0) {}

        Double(const Double& other) : value(other.value) {}

        Double(const char* other) { value = toDouble(other); }

        Double(const String& other) { value = toDouble(other); }

        template<typename Type>
        Double(const Type& other) {
            this->value = static_cast<double>(other);
        }

        

        Double& operator=(const Double& other) {
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



        // Max value of a double 1.7976931348623157e+308
        static constexpr double MAX_VALUE         = 0x1.fffffffffffffP+1023; 

        // A constant holding the smallest positive normal value of type
        // double. It is the value closest to zero that is greater than zero.
        static constexpr double MIN_NORMAL        = 0x1.0p-1022; // 2.2250738585072014E-308

        // Min value of a double.
        static constexpr double MIN_VALUE         = 0x0.0000000000001P-1022; // 4.9e-324

        static constexpr long long EXP_BIT_MASK               = 0x7FF0000000000000L;
        static constexpr long long SIGNIFICAND_WIDTH          = 53;
        static constexpr int       EXP_BIAS                   = 1023;
        static constexpr long long SIGNIF_BIT_MASK            = 0x000FFFFFFFFFFFFFL;
        static constexpr long long SIGN_BIT_MASK              = 0x8000000000000000L;


        /**
         * @brief Converts a double to raw long bits.
         * 
         * @param bits 
         * @return long long 
         */
        static long long doubleToRawLongBits(double bits) {
            long long result = 0;
            memcpy(&result, &bits, sizeof(double));
            return result;
        }

        /**
         * @brief Converts long bits to double.
         * 
         * @param bits 
         * @return double 
         */
        static double longBitsToDouble(long long bits) {
            double result = 0;
            memcpy(&result, &bits, sizeof(double));
            return result;
        }

        /**
         * @brief Returns if the double is NaN (Not a Number).
         * 
         * @param value 
         * @return bool
         */
        static bool isNaN(const double& value) {
            return value != value;
        }

        /**
         * @brief Returns true if the double is a finite value.
         * 
         * @param value 
         * @return bool
         */
        static bool isFinite(const double& value) {
            return Math.abs(value) <= MAX_VALUE;
        }

        /**
         * @brief Returns the hash code for the specified double.
         * 
         * @param value 
         * @return int 
         */
        static int hashCode(double value) {
            return Long::hashCode(doubleToRawLongBits(value));
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
         * @brief A method that returns the const char* of the value
         * 
         */
        const char* toCString() const override {
            String string = String::valueOf(value);
            return string.toCString();
        }

        /**
         * @brief A method that returns the (double) value
         * 
         * @return double 
         */
        double valueOf() const {
            return value;
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
            if(this->value < 0) {
                this->value = -this->value;
            }
            return *this;
        }

        /**
        * @brief The int value of the object
        * 
        * @return Double
        */
        static Double intValue(double value) {
            return Math.rint(value);
        }

        /**
        * @brief The long value of the object
        * 
        * @return Double
        */
        static Double longValue(const Double& value) {
            return Math.rint(value);
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

        template<typename Type>
        Double& operator+=(const Type& other) {
            this->value += other;
            return *this;
        }



        Double& operator-=(const Double& other) {
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

        template<typename Type>
        Double& operator*=(const Type& other) {
            this->value *= other;
            return *this;
        }



        Double& operator/=(const Double& other) {
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

        template<typename Type>
        Double operator+(const Type& other) const {
            return Double(this->value + other);
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

        



        Double operator-(const Double& other) const {
            return Double(this->value - other.value);
        }

        template<typename Type>
        Double operator-(const Type& other) const {
            return Double(this->value - other);
        }
        


        Double operator*(const Double& other) const {
            return Double(this->value * other.value);
        }

        template<typename Type>
        Double operator*(const Type& other) const {
            return Double(this->value * other);
        }
        


        Double operator/(const Double& other) const {
            return Double(this->value / other.value);
        }

        template<typename Type>
        Double operator/(const Type& other) const {
            return Double(this->value / other);
        }



        bool operator==(const Double& other) const {
            return this->value == other.value;
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }

        

        bool operator!=(const Double& other) const {
            return this->value != other.value;
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }
        


        bool operator<(const Double& other) const {
            return this->value < other.value;
        }

        template<typename Type>
        bool operator<(const Type& other) const {
            return this->value < other;
        }
        


        bool operator>(const Double& other) const {
            return this->value > other.value;
        }

        template<typename Type>
        bool operator>(const Type& other) const {
            return this->value > other;
        }
        


        bool operator<=(const Double& other) const {
            return this->value <= other.value;
        }

        template<typename Type>
        bool operator<=(const Type& other) const {
            return this->value <= other;
        }
        


        bool operator>=(const Double& other) const {
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

        template<typename Type>
        bool operator&&(const Type& other) const {
            return this->value && other;
        }
        


        bool operator||(const Double& other) const {
            return this->value || other.value;
        }

        bool operator||(const char* other) const {
            if(other == nullptr) {
                return false;
            }
            return this->value || other;
        }

        template<typename Type>
        bool operator||(const Type& other) const {
            return this->value || other;
        }

        double getValue() const {
            return this->value;
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



JAMSTL_NAMESPACE_END


#endif