#pragma once
#ifndef JAMSTL_MATH_H_
#define JAMSTL_MATH_H_
#include "Datatypes.h"
#include "Macros.h"
// #include "bits/FdLibm.h"
#include <cassert>

JAMSTL_NAMESPACE_BEGIN
    class math {
        const double HugeNumber  = 1e+308;
        double MinimumValue      = 2147483647;
        double MaximumValue      = -2147483647;

        long double nthRoot(long double numberUnderRoot, long double root) {
            if(numberUnderRoot < 0) return 0;
            if(numberUnderRoot == this->Infinity) return this->Infinity;
            if(root == 0) return 1;
            if(root == 1) return numberUnderRoot;
            if(root == this->Infinity && numberUnderRoot != this->Infinity) return 0;
            if(root == this->Infinity && numberUnderRoot == this->Infinity) return 1;
            if(root == this->Infinity) return this->Infinity;
            if(root == this->minInfinity) return 0;
            if(numberUnderRoot == 0) return 0;

            double result = this->Exp(this->ln(numberUnderRoot) / root);
            return result;
        }


        // To find the power of any number with any exponent
        // We can use the following formula:
        // y = x^n
        // Take ln() for both sizes
        // ln(y) = n * ln(x)
        // Take the Exp() for both sizes
        // y = Exp(n * ln(x))
        // Or Basically reverse engineer the nthRoot function


        /**
         * @brief A method to get the power of a function with an integer exponent
         *
         * @param numberUnderRoot  The number under root
         * @param root             The root
         *
         * @return long double
         */
        long double power(long double base, long long exponent) {
            long double result = 1;
            if(base == 0) return 0;
            if(base == 1) return 1;
            if(exponent == 0) return 1;

            if(exponent < 0) {
                while(exponent != 0) {
                    result = result / base;
                    exponent++;
                }
                return result;
            }

            while(exponent != 0) {
                result = result * base;
                exponent--;
            }
            return result;
        }

        long long EXP_BIT_MASK        = 0x7FF0000000000000L;
        int       SIGNIFICAND_WIDTH   = 53;
        int       EXP_BIAS            = 1023;
        long long SIGNIF_BIT_MASK     = 0x000FFFFFFFFFFFFFL;
        
    public: 
        const float Infinity        =      ((float)(this->HugeNumber * this->HugeNumber));
        const float NaN             =      ((float)Infinity * 0.0F);
        const float minInfinity     =      Infinity * -1;
        const double Pi             =      3.1415926535897932384626433832795028841971693;
        const double E              =      2.7182818284590452353602874713526624977572470;
        const double LN10           =      2.3025850929940456840179914546843642076011014;
        const double LN2            =      0.6931471805599453094172321214581765680755001;
        const double SQRT2          =      1.4142135623730950488016887242096980785696718;
        const double LOG2E          =      1.4426950408889634073599246810018921374266459;
        const double SQRT1_2        =      0.7071067811865475244008443621048490392848359;


        /* float fmod(float dividend, float divisor) {
            if(divisor == 0) return 0;
            if(dividend == 0) return 0;
            if(dividend == this->Infinity) return 0;
            if(dividend == this->NaN) return 0;
            if(dividend == this->minInfinity) return 0;
            if(divisor == this->Infinity) return dividend;
            if(divisor == this->NaN) return 0;
            if(divisor == this->minInfinity) return dividend;

            float mod;
            if(dividend < 0) mod = -dividend;
            else mod = dividend;
            if(divisor < 0) divisor = -divisor;

            while(mod >= divisor) {
                mod = mod - divisor;
            }

            if(dividend < 0) return -mod;

            return mod;
        } */

        /* double dmod(double dividend, double divisor) {
            if(divisor == 0) return 0;
            if(dividend == 0) return 0;
            if(dividend == this->Infinity) return 0;
            if(dividend == this->NaN) return 0;
            if(dividend == this->minInfinity) return 0;
            if(divisor == this->Infinity) return dividend;
            if(divisor == this->NaN) return 0;
            if(divisor == this->minInfinity) return dividend;

            double mod;
            if(dividend < 0) mod = -dividend;
            else mod = dividend;
            if(divisor < 0) divisor = -divisor;

            while(mod >= divisor) {
                mod = mod - divisor;
            }

            if(dividend < 0) return -mod;

            return mod;
        } */

        template<typename T, typename U>
        constexpr double fmod(T x, U mod) {
            return !mod ? x : x - mod * this->Floor(x / mod);
        }

        float intBitsToFloat(int32_t bits) {
            int32_t sign = (bits >> 31) & 0x1;
            int32_t exp = (bits >> 23) & 0xFF;
            int32_t mant = bits & 0x7FFFFF;
            if(exp == 0) {
                if(mant == 0) {
                    return 0;
                }
                else {
                    return this->minInfinity;
                }
            }
            else if(exp == 255) {
                if(mant == 0) {
                    return this->Infinity;
                }
                else {
                    return this->NaN;
                }
            }
            else {
                return this->power(2, exp - 127) * (1 + (mant / (1 << 23)));
            }
        }

        int floatToRawIntBits(float value) {
            int32_t bits = *(int32_t*)&value;
            int32_t sign = (bits >> 31) & 0x1;
            int32_t exp = (bits >> 23) & 0xFF;
            int32_t mant = bits & 0x7FFFFF;
            if(exp == 0) {
                if(mant == 0) {
                    return 0;
                }
                else {
                    return this->minInfinity;
                }
            }
            else if(exp == 255) {
                if(mant == 0) {
                    return this->Infinity;
                }
                else {
                    return this->NaN;
                }
            }
            else {
                return (sign << 31) | ((exp + 127) << 23) | (mant & 0x7FFFFF);
            }
        }

        long long doubleToRawLongBits(double bits) {
            long long result = 0;
            memcpy(&result, &bits, sizeof(double));
            return result;
        }

        double longBitsToDouble(long long bits) {
            double result = 0;
            memcpy(&result, &bits, sizeof(double));
            return result;
        }

        int getExponent(double value) {
            return (int)(((this->doubleToRawLongBits(value) & this->EXP_BIT_MASK) >> 
                          (this->SIGNIFICAND_WIDTH - 1)) - this->EXP_BIAS);
        }

        double getSignificand(double value) {
            return this->longBitsToDouble(this->doubleToRawLongBits(value) & 
                                          ~this->EXP_BIT_MASK);
        }


        /**
         * @brief A method to get the absolute value of a number
         *
         * @param value  The number
         *
         * @return double
         */
        template <typename Type>
        Type Abs(Type value) {
            return (value < 0) ? -value : value;
        }

        double Trunc(double value) {
            if(value < 0) return this->Ceil(value);
            return this->Floor(value);
        }

        float Trunc(float value) {
            if(value < 0) return this->Ceil(value);
            return this->Floor(value);
        }

        long double Trunc(long double value) {
            if(value < 0) return this->Ceil(value);
            return this->Floor(value);
        }



        double Modf(double value, unsigned short* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }

        double Modf(double value, short* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }

        double Modf(double value, unsigned int* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }

        double Modf(double value, int* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }

        double Modf(double value, unsigned long* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }
        
        double Modf(double value, long* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }

        double Modf(double value, unsigned long long* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }
        
        double Modf(double value, long long* intPart) {
            *intPart = this->Trunc(value);
            return value - *intPart;
        }


    private:
        double floorOrCeil(double a,
                           double negativeBoundary,
                           double positiveBoundary,
                           double sign) {

            int exponent = this->getExponent(a);

            if(exponent < 0) {
                return ((a == 0.0) ? a :
                        ( (a < 0.0) ? negativeBoundary : positiveBoundary) );  
            } else if(exponent >= 52) {
                return a;
            }

            assert(exponent >= 0 && exponent <= 51);

            long long doppel = this->doubleToRawLongBits(a);
            long long mask   = this->SIGNIF_BIT_MASK >> exponent;

            if( (mask & doppel) == 0LL) {
                return a;
            } else {
                double result = this->longBitsToDouble(doppel & (~mask));
                if(sign * a > 0.0) result = result + sign;
                return result;
            }
        }

        double floor(double a) {
            return this->floorOrCeil(a, -1.0, 0, -1.0);
        }

        double ceil(double a) {
            return this->floorOrCeil(a, 0, 1.0, 1.0);
        }

    public:

        double Floor(long double value) {
            return this->floor(value);
        }

        double Ceil(long double value) {
            return this->ceil(value);
        }

        double Round(long double value) {
            long long longBits  = this->doubleToRawLongBits(value);
            long long biasedExp = (longBits & this->EXP_BIT_MASK) 
                        >> (this->SIGNIFICAND_WIDTH - 1);
            long long shift     = (this->SIGNIFICAND_WIDTH - 2  
                        + this->EXP_BIAS) - biasedExp;
            if((shift & -64) == 0) {
                long long r = ((longBits & this->SIGNIF_BIT_MASK) 
                            |  (this->SIGNIF_BIT_MASK + 1));
                if(longBits < 0) { r = -r; }

                return ((r >> shift) + 1) >> 1;
            } else { return this->Floor(value); }
        }



        long double Sqrt(long double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value < 0) return 0;
            long double root = nthRoot(value, 2);
            return root;            
        }

        long double Cbrt(long double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value < 0) return 0;
            long double root = nthRoot(value, 3);
            return root;
        }



        long double Fact(unsigned int value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->NaN;
            if(value < 0) return this->NaN;
            if(value == 0) return 1;
            if(value == 1) return 1;
            
            return value * this->Fact(value - 1);
        }



        double ln(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity || value <= 0) return this->minInfinity;
            if(value == this->NaN) return this->NaN;

            int power = 0;
            while(value > 1.0) {
                value /= this->E;
                power++;
            }
            while(value < 0.25) {
                value *= this->E;
                power--;
            }
            value--;

            double semiResult   = 0;
            double oneMinusOne  = 1;
            double valueHandler = value;

            for(size_t i = 1; i <= 20; i++) {
                semiResult += valueHandler * (oneMinusOne / i);
                oneMinusOne *= -1;
                valueHandler *= value;
            }

            return semiResult + power;
        }

        double Log10(double value) {
            return this->ln(value) / this->LN10;
        }

        double Log2(double value) {
            return this->ln(value) / this->LN2;
        }

        double Logn(double value, double base) {
            return this->ln(value) / this->ln(base);
        }



        double Exp(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->minInfinity;
            if(value == this->NaN) return this->NaN;

            long double result = 0;
            for(size_t i = 0; i < 1300; i++) {
                long double power = this->power(value, i);
                long double factorial = this->Fact(i);
                result += power / factorial;
            }
            return result;
        }

        long double Pow(long double base, long double exponent) {
            if(base == this->Infinity) return this->Infinity;
            if(base == this->minInfinity && (long long)exponent % 2 == 0) return this->Infinity;
            if(base == this->minInfinity && (long long)exponent % 2 != 0) return this->minInfinity;
            if(base == this->NaN) return this->NaN;
            if(exponent == this->Infinity) return this->Infinity;
            if(exponent == this->minInfinity) return 0;
            if(exponent == this->NaN) return this->NaN;
            if(base == 0 && exponent == 0) return 1;
            if(base == 0 && exponent != 0) return 0;
            if(base == 1) return 1;

            if(exponent - (long long)exponent) {
                if(base < 0) {
                    long double semiResult = exponent * this->ln(-1 * base);
                    return this->Exp(semiResult); 
                }

                if(base - (long long)base == 0) {
                    long double semiResult = exponent * this->ln(base);
                    return this->Exp(semiResult); 
                }

                long double semiResult = exponent * this->ln(base);
                return this->Exp(semiResult);
            }

            return this->power(base, (long long)exponent);            
        }



        double Cos(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->minInfinity;
            if(value == this->NaN) return this->NaN;

            for(size_t i = 0; i < this->MinimumValue && value > 360; i++) {
                value -= 360;
            }

            double tempValue = value * this->Pi / 180;

            long double semiResult = 1;
            for(size_t i = 2; i <= 34; i += 2) {
                if(i == 4 || i == 8 || i == 12 ||
                   i == 16 || i == 20 || i == 24 ||
                   i == 28 || i == 32) {
                    semiResult += (this->Pow(tempValue, i) / this->Fact(i));
                }
                else semiResult -= (this->Pow(tempValue, i) / this->Fact(i));
            }

            long double result = semiResult;
            if(value - (long long)value == 0) {
                if((long long)value % 180 == 0 && 
                    (long long)value % 270 != 0 && 
                    (long long)value % 360 != 0) {
                    result = -1;
                }

                if((long long)value % 270 == 0) {
                    result = 0;
                }

                if((long long)value % -180 == 0 && 
                    (long long)value < 0 && 
                    (long long)value % 360 != 0) {
                    return 1;
                }

                if((long long)value % 360 == 0) {
                    return 1;
                }
            }
            
            if(result < 1e-4 && result > 0) return 0;
            else if(result > -1e-4 && result < 0) return 0;
            return result;
        }

        double Sin(double value) {
            if(value == this->Infinity) return this->NaN;
            if(value == this->minInfinity) return this->NaN;
            if(value == this->NaN) return this->NaN;

            for(size_t i = 0; i < this->MinimumValue && value > 360; i++) {
                value -= 360;
            }

            double tempValue = value * this->Pi / 180;

            long double semiResult = tempValue;
            for(size_t i = 3; i <= 35; i += 2) {
                if(i == 5 || i == 9 || i == 13 ||
                   i == 17 || i == 21 || i == 25 ||
                   i == 29 || i == 33) {
                    semiResult += (this->Pow(tempValue, i) / this->Fact(i));
                }
                else semiResult -= (this->Pow(tempValue, i) / this->Fact(i));
            }

            long double result = semiResult;
            if(value - (long long)value == 0) {
                if((long long)value % 180 == 0 && 
                    (long long)value % 270 != 0) {
                    return 0;
                }

                if((long long)value % 270 == 0 && value > 0) {
                    return -1;
                }

                if((long long)value % -270 == 0 && value < 0) {
                    return 0;
                }
            }
            
            if(result < 1e-4 && result > 0) return 0;
            else if(result > -1e-4 && result < 0) return 0;
            return result;
        }

        long double Tan(double value) {
            return this->Sin(value) / this->Cos(value);
        }

        double Csc(double value) {
            return 1 / this->Sin(value);
        }

        double Sec(double value) {
            return 1 / this->Cos(value);
        }

        long double Cot(double value) {
            return this->Cos(value) / this->Sin(value);
        }



        double Asin(double value) {
            if(value > 1 || value < -1) return this->NaN;
            if(value == 1) return 90;
            if(value == -1) return -90;
            if(value == 0) return 0;
            double semiResult = 0;
            double result;
            
            for(size_t i = 0; i < 300; i++) {
                long double Factorial         = this->Fact(2 * i);
                long double firstDenominator  = this->Pow(4, i);
                long double secondDenominator = this->Pow(this->Fact(i), 2);
                long double thirdDenominator  = (2 * i + 1);
                long double numerator         = this->Pow(value, thirdDenominator);
                semiResult += (Factorial * numerator) /
                              (firstDenominator * secondDenominator * thirdDenominator);
            }
            result = semiResult * 180 / this->Pi;
            return result;
        }

        double Acos(double value) {
            return 90 - this->Asin(value);
        }

        long double Atan(double value) {
            if(value == 1) return 45;
            if(value == -1) return -45;
            if(value == this->Infinity) return 90;
            if(value == this->minInfinity) return -90;

            long double semiResult = 0;
            long double result;
            for(size_t i = 0; i < 700; i++) {
                long double firstNumerator  = this->Pow(-1, i);
                long double secondNumerator = this->Pow(value, 2 * i + 1);
                long double denominator     = (2 * i + 1);
                semiResult += (firstNumerator * secondNumerator) / denominator;
            }
            result = semiResult * 180 / this->Pi;
            return result;
        }



        long double Sinh(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->minInfinity;
            if(value == this->NaN) return this->NaN;
            return (this->Exp(value) - this->Exp(-value)) / 2;
        }

        long double Cosh(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->minInfinity;
            if(value == this->NaN) return this->NaN;
            return (this->Exp(value) + this->Exp(-value)) / 2;
        }

        long double Tanh(double value) {
            return this->Sinh(value) / this->Cosh(value);
        }

        long double Csch(double value) {
            return 1 / this->Sinh(value);
        }

        long double Sech(double value) {
            return 1 / this->Cosh(value);
        }

        long double Coth(double value) {
            return this->Cosh(value) / this->Sinh(value);
        }



        long double Asinh(double value) {
            return this->ln(value + this->Sqrt(value * value + 1));
        }

        long double Acosh(double value) {
            return this->ln(value + this->Sqrt(value * value - 1));
        }

        long double Atanh(double value) {
            if(value == 1) return this->Infinity;
            if(value == -1) return this->minInfinity;
            if(value > 1 && value < -1) return this->NaN;
            return this->ln((1 + value) / (1 - value)) / 2.0;
        }



        template<typename Type>
        Type Min(const Type& value1, const Type& value2) {
            return value1 < value2 ? value1 : value2;
        }

        template<typename Type>
        Type Max(const Type& value1, const Type& value2) {
            return value1 > value2 ? value1 : value2;
        }

        template<typename Type, size_t size>
        Type Min(Type (&value)[size]) {
            Type result = value[0];
            for(size_t i = 1; i < size; i++) {
                result = this->Min(result, value[i]);
            }
            return result;
        }

        template<typename Type, size_t size>
        Type Max(Type (&value)[size]) {
            Type result = value[0];
            for(size_t i = 1; i < size; i++) {
                result = this->Max(result, value[i]);
            }
            return result;
        }



        bool isPrime(unsigned long long value) {
            if(value == 0 || value == 1) return false;
            if(value == this->Infinity || value == this->minInfinity) return false;
            if(value == this->NaN) return false;

            for(size_t i = 2; i < value / 2; i++) {
                if(value % i == 0) return false;
            }
            return true;
        }



        bool isEven(long long value) {
            return value % 2 == 0;
        }

        bool isOdd(long long value) {
            return value % 2 == 1;
        }



        unsigned Digits(long long value) {
            if(value == 0) return 1;
            unsigned result = 0;
            while(value != 0) {
                value /= 10;
                result++;
            }
            return result;
        }

    } Math;


    template<typename Type>
    void swap(Type& value1, Type& value2) {
        Type temp = value1;
        value1 = value2;
        value2 = temp;
    }

    template<typename Type>
    void heapify(Type array[], size_t size, size_t i) {
        int largest = i;
    
        int left = 2 * i + 1;
    
        int right = 2 * i + 2;
    
        if (left < size && array[left] > array[largest]) largest = left;
    
        if (right < size && array[right] > array[largest]) largest = right;
    
        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(array, size, largest);
        }
    }
 
    template<typename Type, size_t size>
    void sort(Type (&array)[size]) {
        for (int i = size / 2 - 1; i >= 0; i--) heapify(array, size, i);
    
        for (int i = size - 1; i > 0; i--) {
            swap(array[0], array[i]);
            heapify(array, i, 0);
        }
    }

JAMSTL_NAMESPACE_END

#endif