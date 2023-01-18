#pragma once

#ifndef JAMSTL_STRINGSTREAM_H
#define JAMSTL_STRINGSTREAM_H 1

#include "../Datatypes.h"
#include "StringHelper.h"
#include "../Macros.h"
#include "../Object.h"

JAMSTL_NAMESPACE_BEGIN

    class StringStream extends Object {
    private:
        int                   Int;
        unsigned int          UInt;
        unsigned long long    ULLong;
        float                 floatNumber;
        double                doubleNumber;
        char                  Char;
        short                 shortNumber;
        unsigned short        UShort;
        long                  longNumber;
        unsigned long         ULong;
        long long             LongLong;
        unsigned long long    ULongLong;
        Integer               integer;
        Short                 shortNum;
        Long                  longNum;
        Float                 floatNum;
        Double                doubleNum;
        String                _str;


        /**
         * @brief To int method.
         * 
         * @return int 
         */
        int toInt() {
            int ToInt = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToInt = ToInt * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return -ToInt;
            return ToInt;
        }

        /**
         * @brief To short method.
         * 
         * @return short 
         */
        short toSInt() {
            int ToshortInt = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') continue;
                ToshortInt = ToshortInt * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return -ToshortInt;
            
            return ToshortInt;
        }

        /**
         * @brief Reads the floating points of a number method.
         * 
         * @param start 
         * @param end 
         * @param Division 
         * @return float 
         */
        float readFractions(int start, int end, float& Division) {
            float Fractions = 0;
            int j, Count = 0;

            for(int k = start; _str[k] != '\0'; k++) {
                if(_str[start] == '0' && _str[k] == '0') Count++;
                if(Count == (end - start)) return 0;
            }

            for(j = start; _str[j] != '\0'; j++) {
                if(_str[j] > '9' || _str[j] < '0') continue;
                Division = Division * 10;
                if(_str[j] != '.') Fractions = Fractions * 10 + _str[j] - '0';
            }
            Division = Fractions / Division;
            return Division;
        }

        /**
         * @brief Reads the floating points of a number method.
         * 
         * @param start 
         * @param end 
         * @param Division 
         * @return double 
         */
        double readFractions(int start, int end, double& Division) {
            double Fractions = 0;
            int j, Count = 0;

            for(int k = start; _str[k] != '\0'; k++) {
                if(_str[start] == '0' && _str[k] == '0') Count++;
                if(Count == (end - start)) return 0;
            }

            for(j = start; _str[j] != '\0'; j++) {
                if(_str[j] > '9' || _str[j] < '0') continue;
                Division = Division * 10;
                if(_str[j] != '.') Fractions = Fractions * 10 + _str[j] - '0';
                
            }
            Division = Fractions / Division;
            return Division;
        }

        /**
         * @brief Reads the floating points of a number method.
         * 
         * @param start 
         * @param end 
         * @param Division 
         * @return long double 
         */
        long double readFractions(int start, int end, long double& Division) {
            long double Fractions = 0;
            int j, Count = 0;

            for(int k = start; _str[k] != '\0'; k++) {
                if(_str[start] == '0' && _str[k] == '0') Count++;
                if(Count == (end - start)) return 0;
            }

            for(j = start; _str[j] != '\0'; j++) {
                if(_str[j] > '9' || _str[j] < '0') continue;
                Division = Division * 10;
                if(_str[j] != '.') Fractions = Fractions * 10 + _str[j] - '0';
                
            }
            Division = Fractions / Division;
            return Division;
        }

        /**
         * @brief To float method.
         * 
         * @return float 
         */
        float toFloat() {
            float ToFloat = 0, Division = 1;
            int i;
            usize lengthOfString = _str.length();
            for(i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && (_str[i] == '.' || _str[i] == '-')) continue;
                if(i != 0 && _str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToFloat = ToFloat * 10 + _str[i] - '0';
            }

            float floatTempNumber = 0;
            if(_str[i] == '.') {
                floatTempNumber = readFractions(i + 1, lengthOfString, Division);
            }

            if(_str[0] == '-') {
                if((ToFloat + floatTempNumber) - 
                    (long long)(ToFloat + floatTempNumber) == 0) 
                        return -1 * (ToFloat);
                return -1 * (ToFloat + floatTempNumber);
            }

            ToFloat = ToFloat + Division;
            if(ToFloat - (long long)ToFloat == 0) return ToFloat - 1;
            return ToFloat;
        }

        /**
         * @brief To double method.
         * 
         * @return double 
         */
        double toDouble() {
            double ToDouble = 0, Division = 1;
            int i;
            int lengthOfString = _str.length();
            for(i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && (_str[i] == '.' || _str[i] == '-')) continue;
                if(i != 0 && _str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToDouble = ToDouble * 10 + _str[i] - '0';
            }

            double doubleTempNumber = 0;
            if(_str[i] == '.') {
                doubleTempNumber = readFractions(i + 1, lengthOfString, Division);
            }

            double rintNumber;
            if((ToDouble + doubleTempNumber) < Math.rint(ToDouble + doubleTempNumber)) {
                rintNumber = Math.rint(ToDouble + doubleTempNumber) - 1;
            } else {
                rintNumber = Math.rint(ToDouble + doubleTempNumber);
            }

            if(_str[0] == '-') {
                if((ToDouble + doubleTempNumber) - rintNumber == 0)
                        return -1 * (ToDouble);
                return -1 * (ToDouble + doubleTempNumber);
            }

            ToDouble = ToDouble + Division;
            if(ToDouble - Math.rint(ToDouble) == 0) return ToDouble - 1;
            return ToDouble;
        }

        /**
         * @brief To long double method.
         * 
         * @return long double 
         */
        long double toLDouble() {
            double ToLongDouble = 0, Division = 1;
            int i;
            int lengthOfString = _str.length();
            for(i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && (_str[i] == '.' || _str[i] == '-')) continue;
                if(i != 0 && _str[i] == '.') break;
                if((_str[i] > '9' || _str[i] < '0')) break;
                ToLongDouble = ToLongDouble * 10 + _str[i] - '0';
            }

            double LongDoubleTempNumber = 0;
            if(_str[i] == '.') {
                LongDoubleTempNumber = readFractions(i + 1, lengthOfString, Division);
            }

            if(_str[0] == '-') {
                if((ToLongDouble + LongDoubleTempNumber) - 
                    (long long)(ToLongDouble + LongDoubleTempNumber) == 0)
                        return -1 * (ToLongDouble);
                return -1 * (ToLongDouble + LongDoubleTempNumber);
            }

            ToLongDouble = ToLongDouble + Division;
            if(ToLongDouble - (long long)ToLongDouble == 0) return ToLongDouble - 1;
            return ToLongDouble;
        }

        /**
         * @brief To long long method.
         * 
         * @return long long 
         */
        long long toLLInt() {
            long long ToLongLong = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToLongLong = ToLongLong * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return -ToLongLong;
            return ToLongLong;
        }

        /**
         * @brief To long method.
         * 
         * @return unsigned long long 
         */
        long toLInt() {
            long ToLong = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToLong = ToLong * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return -ToLong;
            return ToLong;
        }

        /**
         * @brief To unsigned short method.
         * 
         * @return unsigned long long 
         */
        unsigned short toUShortInt() {
            unsigned short ToUShortInt = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToUShortInt = ToUShortInt * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return ToUShortInt;
            return ToUShortInt;
        }

        /**
         * @brief To unsigned int method.
         * 
         * @return unsigned long long 
         */
        unsigned toUInt() {
            unsigned ToUnsignedInt = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToUnsignedInt = ToUnsignedInt * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return ToUnsignedInt;
            return ToUnsignedInt;
        }

        /**
         * @brief To unsigned long method.
         * 
         * @return unsigned long long 
         */
        unsigned long toULInt() {
            unsigned long ToUnsignedLong = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToUnsignedLong = ToUnsignedLong * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return ToUnsignedLong;
            return ToUnsignedLong;
        }

        /**
         * @brief To unsigned long long method.
         * 
         * @return unsigned long long 
         */
        unsigned long long toULLInt() {
            unsigned long long ToUnsignedLongLong = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToUnsignedLongLong = ToUnsignedLongLong * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return ToUnsignedLongLong;
            return ToUnsignedLongLong;
        }

    public:

        StringStream() 
        : Int(0), UInt(0), ULLong(0), floatNumber(0), 
        doubleNumber(0), Char('\0'), shortNumber(0), 
        UShort(0), longNumber(0), ULong(0), 
        LongLong(0), ULongLong(0), integer(0),
        shortNum(0), longNum(0), floatNum(0),
        doubleNum(0), _str("") {}

        StringStream(const StringStream& _strStream) {
            _str = _strStream._str;
            Int = _strStream.Int;
            UInt = _strStream.UInt;
            ULLong = _strStream.ULLong;
            floatNumber = _strStream.floatNumber;
            doubleNumber = _strStream.doubleNumber;
            Char = _strStream.Char;
            shortNumber = _strStream.shortNumber;
            UShort = _strStream.UShort;
            longNumber = _strStream.longNumber;
            ULong = _strStream.ULong;
            LongLong = _strStream.LongLong;
            ULongLong = _strStream.ULongLong;
            integer = _strStream.integer;
            shortNum = _strStream.shortNum;
            longNum = _strStream.longNum;
            floatNum = _strStream.floatNum;
            doubleNum = _strStream.doubleNum;
        }

        StringStream(const String& _str) {
            this->_str = _str;
            Int = toInt();
            UInt = toUInt();
            ULLong = toULLInt();
            floatNumber = toFloat();
            doubleNumber = toDouble();
            shortNumber = toSInt();
            UShort = toUShortInt();
            longNumber = toLInt();
            ULong = toULInt();
            LongLong = toLLInt();
            ULongLong = toULLInt();
            integer = toInt();
            shortNum = toSInt();
            longNum = toLInt();
            floatNum = toFloat();
            doubleNum = toDouble();
        }

        /**
         * @brief To store in a string stream.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator<<(const String& str) {
            _str += str;
            return *this;
        }

        /**
         * @brief To store in a string stream.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator<<(const char* str) {
            _str += str;
            return *this;
        }

        /**
         * @brief To store in a string stream.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator<<(const char& c) {
            _str += c;
            return *this;
        }

        /**
         * @brief To store in a string stream.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator<<(const StringStream& stream) {
            _str += stream._str;
            return *this;
        }

        /**
         * @brief To store in a string stream.
         * 
         * @param str 
         * @tparam Type
         * @return StringStream& 
         */
        template<typename Type>
        StringStream& operator<<(const Type& num) {
            _str += toString(num);
            return *this;
        }


        /**
         * @brief To load to a string.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(String& str) {
            str = _str;
            return *this;
        }

        /**
         * @brief To load to a char*.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(char* str) {
            str = _str.charString();
            return *this;
        }

        /**
         * @brief To load to a char.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(char& c) {
            c = _str[0];
            return *this;
        }

        /**
         * @brief To load to a short.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(short& shortInt) {
            shortInt = toSInt();
            return *this;
        }

        /**
         * @brief To load to an int.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(int& valueType) {
            valueType = toInt();
            return *this;
        }

        /**
         * @brief To load to a long.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(long& valueType) {
            valueType = toLInt();
            return *this;
        }

        /**
         * @brief To load to a long long.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(long long& valueType) {
            valueType = toLLInt();
            return *this;
        }

        /**
         * @brief To load to a unsigned short.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(unsigned short& valueType) {
            valueType = toUShortInt();
            return *this;
        }

        /**
         * @brief To load to a unsigned int.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(unsigned& valueType) {
            valueType = toUInt();
            return *this;
        }

        /**
         * @brief To load to a unsigned long.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(unsigned long& valueType) {
            valueType = toULInt();
            return *this;
        }

        /**
         * @brief To load to a unsigned long long.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(unsigned long long& valueType) {
            valueType = toULLInt();
            return *this;
        }

        /**
         * @brief To load to a float.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(float& valueType) {
            valueType = toFloat();
            return *this;
        }

        /**
         * @brief To load to a double.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(double& valueType) {
            valueType = toDouble();
            return *this;
        }

        /**
         * @brief To load to a long double.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(long double& valueType) {
            valueType = toLDouble();
            return *this;
        }



        /**
         * @brief To load to a Short Wrapper Class.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(Short& valueType) {
            valueType = toSInt();
            return *this;
        }

        /**
         * @brief To load to an Integer Wrapper Class.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(Integer& valueType) {
            valueType = toInt();
            return *this;
        }

        /**
         * @brief To load to a Long Wrapper Class.
         * 
         * @param str 
         * @return StringStream& 
         */ 
        StringStream& operator>>(Long& valueType) {
            valueType = toLLInt();
            return *this;
        }

        /**
         * @brief To load to a Float Wrapper Class.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(Float& valueType) {
            valueType = toFloat();
            return *this;
        }

        /**
         * @brief To load to a Double Wrapper Class.
         * 
         * @param str 
         * @return StringStream& 
         */
        StringStream& operator>>(Double& valueType) {
            valueType = toDouble();
            return *this;
        }


        
        /**
         * @brief Returns the string that stores the data.
         * 
         * @return String 
         */
        String str() const {
            return _str;
        }

        /**
         * @brief Clears the string stream.
         * 
         * @return StringStream& 
         */
        StringStream& clear() {
            _str = "";
            return *this;
        }

        /**
         * @brief Get the Class Name object.
         * 
         * @return String 
         */
        String getClassName() const {
            String className = typeid(this).name();
            className.erase(0, 12);
            className.pop();
            return className;
        }

        StringStream& operator=(const StringStream& stream) {
            _str = stream._str;
            return *this;
        }

        StringStream& operator=(const String& str) {
            _str = str;
            return *this;
        }

        StringStream& operator=(const char* str) {
            _str = str;
            return *this;
        }

        StringStream& operator=(const char& c) {
            _str = c;
            return *this;
        }

        template<typename Type>
        StringStream& operator=(const Type& valueType) {
            _str = toString(valueType);
            return *this;
        }

    };

JAMSTL_NAMESPACE_END



#endif