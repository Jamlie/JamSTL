#pragma once
#ifndef JAMSTL_MATH_H_
#define JAMSTL_MATH_H_ 1
#include "Macros.h"
#include <cstring>
#include <cassert>

JAMSTL_NAMESPACE_BEGIN

    class math {
        const double HugeNumber  = 1e+308;
        double MinimumValue      = 2147483647;
        double MaximumValue      = -2147483647;

        constexpr long double nthRoot(long double numberUnderRoot, long double root) {
            if(numberUnderRoot < 0) return 0;
            if(numberUnderRoot == this->Infinity) return this->Infinity;
            if(root == 0) return 1;
            if(root == 1) return numberUnderRoot;
            if(root == this->Infinity && numberUnderRoot != this->Infinity) return 0;
            if(root == this->Infinity && numberUnderRoot == this->Infinity) return 1;
            if(root == this->Infinity) return this->Infinity;
            if(root == this->minInfinity) return 0;
            if(numberUnderRoot == 0) return 0;

            double result = this->exp(this->ln(numberUnderRoot) / root);
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
        constexpr long double power(long double base, long long exponent) {
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

        long long EXP_BIT_MASK               = 0x7FF0000000000000L;
        long long SIGNIFICAND_WIDTH          = 53;
        int       FLOATING_SIGNIFICAND_WIDTH = 24;
        int       EXP_BIAS                   = 1023;
        int       FLOATING_EXP_BIAS          = 127;
        long long SIGNIF_BIT_MASK            = 0x000FFFFFFFFFFFFFL;
        int       FLOATING_SIGNIF_BIT_MASK   = 0x007FFFFF;
        long long SIGN_BIT_MASK              = 0x8000000000000000L;
        int       FLOATING_SIGN_BIT_MASK     = 0x80000000;
        int       FLOATING_EXP_BIT_MASK      = 0x7F800000;
        long long MAG_BIT_MASK               = ~SIGN_BIT_MASK;
        int       FLOATING_MAG_BIT_MASK      = ~FLOATING_SIGN_BIT_MASK;

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


        
        /**
         * @brief Returns the modulus of two numbers
         * 
         * @tparam T 
         * @tparam U 
         * @param x 
         * @param mod 
         * @return constexpr double 
         */
        template<typename T, typename U>
        constexpr double fmod(T x, U mod) {
            return !mod ? x : x - mod * this->Floor(x / mod);
        }

        /**
         * @brief Converts int bits to float
         * 
         * @param bits 
         * @return constexpr float 
         */
        constexpr float intBitsToFloat(int32_t bits) {
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

        /**
         * @brief Converts float to raw int bits
         * 
         * @param value 
         * @return int 
         */
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

        /**
         * @brief Converts double to raw long bits
         * 
         * @param bits 
         * @return long long 
         */
        long long doubleToRawLongBits(double bits) {
            long long result = 0;
            memcpy(&result, &bits, sizeof(double));
            return result;
        }

        /**
         * @brief Converts long bits to double
         * 
         * @param bits 
         * @return double 
         */
        double longBitsToDouble(long long bits) {
            double result = 0;
            memcpy(&result, &bits, sizeof(double));
            return result;
        }

        /**
         * @brief Returns the unbiased exponent used in the representation of a
         * {@code float}.
         * 
         * @param value 
         * @return int 
         */
        int getExponent(double value) {
            return (int)(((this->doubleToRawLongBits(value) & this->EXP_BIT_MASK) >> 
                          (this->SIGNIFICAND_WIDTH - 1)) - this->EXP_BIAS);
        }

        /**
         * @brief Returns the unbiased exponent used in the representation of a
         * {@code double}.
         * 
         * @param value 
         * @return int 
         */
        int getExponent(float value) {
            return (int)(((this->floatToRawIntBits(value) & this->EXP_BIT_MASK) >> 
                          (this->FLOATING_SIGNIFICAND_WIDTH - 1)) - this->FLOATING_EXP_BIAS);
        }

        /**
         * @brief Get the Significand object
         * 
         * @param value 
         * @return double 
         */
        double getSignificand(double value) {
            return this->longBitsToDouble(this->doubleToRawLongBits(value) & 
                                          ~this->EXP_BIT_MASK);
        }



        /**
         * @brief Returns the absolute value of the given value.
         * 
         * @param value 
         * @return constexpr short 
         */
        constexpr short abs(short value) {
            return value < 0 ? -value : value;
        }

        /**
         * @brief Returns the absolute value of the given value.
         * 
         * @param value 
         * @return constexpr int 
         */
        constexpr int abs(int value) {
            return value < 0 ? -value : value;
        }

        /**
         * @brief Returns the absolute value of the given value.
         * 
         * @param value 
         * @return constexpr long 
         */
        constexpr long abs(long value) {
            return value < 0 ? -value : value;
        }

        /**
         * @brief Returns the absolute value of the given value.
         * 
         * @param value 
         * @return constexpr long long 
         */
        constexpr long long abs(long long value) {
            return value < 0 ? -value : value;
        }

        // constexpr float abs(float value) {
        //     return this->intBitsToFloat(this->floatToRawIntBits(value) &
        //                                 this->FLOATING_MAG_BIT_MASK);
        // }

        /**
         * @brief Returns the absolute value of the given value.
         * 
         * @param value 
         * @return constexpr float 
         */
        constexpr float abs(float value) {
            return (value <= 0) ? -value : value;
        }

        // constexpr double abs(double value) {
        //     return this->longBitsToDouble(this->doubleToRawLongBits(value) & 
        //                                   this->MAG_BIT_MASK);
        // }

        /**
         * @brief Returns the absolute value of the given value.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double abs(double value) {
            return (value <= 0) ? -value : value;
        }

        // constexpr long double abs(long double value) {
        //     return this->longBitsToDouble(this->doubleToRawLongBits(value) & 
        //                                   this->MAG_BIT_MASK);
        // }

        /**
         * @brief Returns the absolute value of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double abs(long double value) {
            return (value <= 0) ? -value : value;
        }





        /**
         * @brief Returns the nearest integer to the argument.
         * 
         * @param value 
         * @return double 
         */
        double trunc(double value) {
            if(value < 0) return this->ceil(value);
            return this->floor(value);
        }

        /**
         * @brief Returns the nearest integer to the argument.
         * 
         * @param value 
         * @return float 
         */
        float trunc(float value) {
            if(value < 0) return this->ceil(value);
            return this->floor(value);
        }

        /**
         * @brief Returns the nearest integer to the argument.  
         * 
         * @param value 
         * @return long double 
         */
        long double trunc(long double value) {
            if(value < 0) return this->ceil(value);
            return this->floor(value);
        }



        /**
         * @brief eturns the first floating-point argument with the sign of the
         * second floating-point argument.
         * 
         * @param magnitude 
         * @param sign 
         * @return double 
         */
        double copySign(double magnitude, double sign) {
            return this->longBitsToDouble((this->doubleToRawLongBits(sign) &
                                            (this->SIGN_BIT_MASK)) |
                                            (this->doubleToRawLongBits(magnitude) &
                                            (this->EXP_BIT_MASK |
                                            this->SIGNIF_BIT_MASK)));
        }

        /**
         * @brief Returns the {@code double} value that is closest in value
         * to the argument and is equal to a mathematical integer. If two
         * {@code double} values that are mathematical integers are
         * equally close, the result is the integer value that is
         * even.
         * 
         * @param value 
         * @return double 
         */
        double rint(double value) {
            double twoToThe52 = (double)(1LL << 52);
            double sign       = this->copySign(1.0, value);
            value             = this->abs(value);
            if(value < twoToThe52) {
                value = ((twoToThe52 + value) - twoToThe52);
            }
            return sign * value;
        }



        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, unsigned short* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }

        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, short* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }

        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, unsigned int* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }

        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, int* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }

        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, unsigned long* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }

        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, long* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }

        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, unsigned long long* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }
        
        /**
         * @brief Returns the floating point remainder of the vlaue while
         *       saving the int part of the result.
         * 
         * @param value 
         * @param intPart 
         * @return double 
         */
        double modf(double value, long long* intPart) {
            *intPart = this->trunc(value);
            return value - *intPart;
        }


    private:
        /**
         * @brief Internal method to share logic between floor and ceil.
         * 
         * @param a 
         * @param negativeBoundary 
         * @param positiveBoundary 
         * @param sign 
         * @return double 
         */
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

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards positive infinity.
         * 
         * @param a 
         * @return long double 
         */
        long double Floor(long double a) {
            return this->floorOrCeil(a, -1.0, 0, -1.0);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards negative infinity.
         * 
         * @param a 
         * @return long double 
         */
        long double Ceil(long double a) {
            return this->floorOrCeil(a, 0, 1.0, 1.0);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards positive infinity.
         * 
         * @param a 
         * @return double 
         */
        double Floor(double a) {
            return this->floorOrCeil(a, -1.0, 0, -1.0);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards negative infinity.
         * 
         * @param a 
         * @return double 
         */
        double Ceil(double a) {
            return this->floorOrCeil(a, 0, 1.0, 1.0);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards positive infinity.
         * 
         * @param a 
         * @return float 
         */
        float Floor(float a) {
            return this->floorOrCeil(a, -1.0, 0, -1.0);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards negative infinity.
         * 
         * @param a 
         * @return float 
         */
        float Ceil(float a) {
            return this->floorOrCeil(a, 0, 1.0, 1.0);
        }

    public:

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards positive infinity.
         * 
         * @param value 
         * @return long double 
         */
        long double floor(long double value) {
            return this->Floor(value);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards negative infinity.
         * 
         * @param value 
         * @return long double 
         */
        long double ceil(long double value) {
            return this->Ceil(value);
        }
        
        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards positive infinity.
         * 
         * @param value 
         * @return double 
         */
        double floor(double value) {
            return this->Floor(value);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards negative infinity.
         * 
         * @param value 
         * @return double 
         */
        double ceil(double value) {
            return this->Ceil(value);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards positive infinity.
         * 
         * @param value 
         * @return float 
         */
        float floor(float value) {
            return this->Floor(value);
        }

        /**
         * @brief Returns the value of the floating-point number rounded to the
         * nearest integer towards negative infinity.
         * 
         * @param value 
         * @return float 
         */
        float ceil(float value) {
            return this->Ceil(value);
        }

        /**
         * @brief Returns the nearest integer to the argument.
         * 
         * @param value 
         * @return long double 
         */
        long double round(long double value) {
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

        /**
         * @brief Returns the nearest integer to the argument.
         * 
         * @param value 
         * @return double 
         */
        double round(double value) {
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



        /**
         * @brief Returns the square root of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double sqrt(long double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value < 0) return 0;
            long double root = nthRoot(value, 2);
            return root;
        }

        /**
         * @brief Returns the cube root of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double cbrt(long double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value < 0) return 0;
            long double root = nthRoot(value, 3);
            return root;
        }



        /**
         * @brief Returns the factorial of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double fact(unsigned int value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->NaN;
            if(value < 0) return this->NaN;
            if(value == 0) return 1;
            if(value == 1) return 1;
            
            return value * this->fact(value - 1);
        }



        /**
         * @brief Returns the natural logarithm of the absolute value of the
         * argument.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double ln(double value) {
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

        /**
         * @brief Returns the logarithm of the given value to the base of 10.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double log10(double value) {
            return this->ln(value) / this->LN10;
        }

        /**
         * @brief Returns the logarithm of a value to the base of 2.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double log2(double value) {
            return this->ln(value) / this->LN2;
        }

        /**
         * @brief Returns the logarithm of a value to the base of a given value.
         * 
         * @param value 
         * @param base 
         * @return constexpr double 
         */
        constexpr double logn(double value, double base) {
            return this->ln(value) / this->ln(base);
        }



        /**
         * @brief Returns the exponential function of the given value.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double exp(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->minInfinity;
            if(value == this->NaN) return this->NaN;

            long double result = 0;
            for(size_t i = 0; i < 1300; i++) {
                long double power = this->power(value, i);
                long double factorial = this->fact(i);
                result += power / factorial;
            }
            return result;
        }

        /**
         * @brief Returns the base raised to the power of the exponent.
         * 
         * @param base 
         * @param exponent 
         * @return constexpr long double 
         */
        constexpr long double pow(long double base, long double exponent) {
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

            if(exponent - (long long)exponent == 0) {
                if(base < 0) {
                    long double semiResult = exponent * this->ln(-1 * base);
                    return this->exp(semiResult); 
                }

                if(base - (long long)base == 0) {
                    long double semiResult = exponent * this->ln(base);
                    return this->exp(semiResult); 
                }

                long double semiResult = exponent * this->ln(base);
                return this->exp(semiResult);
            }

            return this->power(base, (long long)exponent); 
        }



        /**
         * @brief Returns the cosine of the given angle.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double cos(double value) {
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
                    semiResult += (this->pow(tempValue, i) / this->fact(i));
                }
                else semiResult -= (this->pow(tempValue, i) / this->fact(i));
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

        /**
         * @brief Returns the sine of the given value.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double sin(double value) {
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
                    semiResult += (this->pow(tempValue, i) / this->fact(i));
                }
                else semiResult -= (this->pow(tempValue, i) / this->fact(i));
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

        /**
         * @brief Returns the tangent of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double tan(double value) {
            return this->sin(value) / this->cos(value);
        }

        /**
         * @brief Returns the cosecant of the given value.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double csc(double value) {
            return 1 / this->sin(value);
        }

        /**
         * @brief Returns the secant of the given value.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double sec(double value) {
            return 1 / this->cos(value);
        }

        /**
         * @brief Returns the cotangent of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double cot(double value) {
            return this->cos(value) / this->sin(value);
        }



        /**
         * @brief Returns the arcsine of the value.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double asin(double value) {
            if(value > 1 || value < -1) return this->NaN;
            if(value == 1) return 90;
            if(value == -1) return -90;
            if(value == 0) return 0;
            double semiResult = 0;
            double result = 0;
            
            for(size_t i = 0; i < 300; i++) {
                long double Factorial         = this->fact(2 * i);
                long double firstDenominator  = this->pow(4, i);
                long double secondDenominator = this->pow(this->fact(i), 2);
                long double thirdDenominator  = (2 * i + 1);
                long double numerator         = this->pow(value, thirdDenominator);
                semiResult += (Factorial * numerator) /
                              (firstDenominator * secondDenominator * thirdDenominator);
            }
            result = semiResult * 180 / this->Pi;
            return result;
        }

        /**
         * @brief Returns the arccosine of the given value.
         * 
         * @param value 
         * @return constexpr double 
         */
        constexpr double acos(double value) {
            return 90 - this->asin(value);
        }

        /**
         * @brief Returns the arctangent of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double atan(double value) {
            if(value == 1) return 45;
            if(value == -1) return -45;
            if(value == this->Infinity) return 90;
            if(value == this->minInfinity) return -90;

            long double semiResult = 0;
            long double result = 0;
            for(size_t i = 0; i < 700; i++) {
                long double firstNumerator  = this->pow(-1, i);
                long double secondNumerator = this->pow(value, 2 * i + 1);
                long double denominator     = (2 * i + 1);
                semiResult += (firstNumerator * secondNumerator) / denominator;
            }
            result = semiResult * 180 / this->Pi;
            return result;
        }



        /**
         * @brief Returns the hyperbolic sine of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double sinh(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->minInfinity;
            if(value == this->NaN) return this->NaN;
            return (this->exp(value) - this->exp(-value)) / 2;
        }

        /**
         * @brief Returns the hyperbolic cosine of the specified angle.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double cosh(double value) {
            if(value == this->Infinity) return this->Infinity;
            if(value == this->minInfinity) return this->minInfinity;
            if(value == this->NaN) return this->NaN;
            return (this->exp(value) + this->exp(-value)) / 2;
        }

        /**
         * @brief Returns the hyperbolic tangent of the specified angle.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double tanh(double value) {
            return this->sinh(value) / this->cosh(value);
        }

        /**
         * @brief Returns the hyperbolic cosecant of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double csch(double value) {
            return 1 / this->sinh(value);
        }

        /**
         * @brief Returns the hyperbolic secant of a number.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double sech(double value) {
            return 1 / this->cosh(value);
        }

        /**
         * @brief Returns the hyperbolic cotangent of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double coth(double value) {
            return this->cosh(value) / this->sinh(value);
        }



        /**
         * @brief Returns the hyperbolic arcsine of the given value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double asinh(double value) {
            return this->ln(value + this->sqrt(value * value + 1));
        }

        /**
         * @brief Returns the hyperbolic arccosine of the specified value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double acosh(double value) {
            return this->ln(value + this->sqrt(value * value - 1));
        }

        /**
         * @brief Returns the hyperbolic arctangent of the value.
         * 
         * @param value 
         * @return constexpr long double 
         */
        constexpr long double atanh(double value) {
            if(value == 1) return this->Infinity;
            if(value == -1) return this->minInfinity;
            if(value > 1 && value < -1) return this->NaN;
            return this->ln((1 + value) / (1 - value)) / 2.0;
        }



        /**
         * @brief Gets the min value of two values.
         * 
         * @tparam Type 
         * @param value1 
         * @param value2 
         * @return constexpr Type 
         */
        template<typename Type>
        constexpr Type min(const Type& value1, const Type& value2) {
            return value1 < value2 ? value1 : value2;
        }

        /**
         * @brief Gets the max value of two values.
         * 
         * @tparam Type 
         * @param value1 
         * @param value2 
         * @return constexpr Type 
         */
        template<typename Type>
        constexpr Type max(const Type& value1, const Type& value2) {
            return value1 > value2 ? value1 : value2;
        }


        /**
         * @brief Gets the min value in an array.
         * 
         * @tparam Type 
         * @tparam size 
         * @return constexpr Type 
         */
        template<typename Type, size_t size>
        constexpr Type min(Type (&value)[size]) {
            Type result = value[0];
            for(size_t i = 1; i < size; i++) {
                result = this->min(result, value[i]);
            }
            return result;
        }

        /**
         * @brief Gets the max value in an array.
         * 
         * @tparam Type 
         * @tparam size 
         * @return constexpr Type 
         */
        template<typename Type, size_t size>
        constexpr Type max(Type (&value)[size]) {
            Type result = value[0];
            for(size_t i = 1; i < size; i++) {
                result = this->max(result, value[i]);
            }
            return result;
        }



        /**
         * @brief Checks if a number is prime.
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        constexpr bool isPrime(unsigned long long value) {
            if(value == 0 || value == 1) return false;
            if(value == this->Infinity || value == this->minInfinity) return false;
            if(value == this->NaN) return false;

            for(unsigned long long i = 2; i < value; i++) {
                if(value % i == 0) return false;
            }
            return true;
        }



        /**
         * @brief Checks if a number is even.
         * 
         * @param value 
         * @return bool
         */
        constexpr bool isEven(long long value) {
            return value % 2 == 0;
        }

        /**
         * @brief Checks if a number is odd.
         * 
         * @param value 
         * @return bool
         */
        constexpr bool isOdd(long long value) {
            return value % 2 == 1;
        }



        /**
         * @brief Counts the digits of a number.
         * 
         * @param value 
         * @return constexpr unsigned 
         */
        constexpr unsigned digits(long long value) {
            if(value == 0) return 1;
            unsigned result = 0;
            while(value != 0) {
                value /= 10;
                result++;
            }
            return result;
        }

    } Math;


    /**
     * @brief Swaps two values.
     * 
     * @tparam Type 
     * @param value1 
     * @param value2 
     */
    template<typename Type>
    void swap(Type& value1, Type& value2) {
        Type temp = value1;
        value1 = value2;
        value2 = temp;
    }
    

JAMSTL_NAMESPACE_END

#endif