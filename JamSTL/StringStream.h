#pragma once

#ifndef JAMSTL_STRINGSTREAM_H
#define JAMSTL_STRINGSTREAM_H

#include "Datatypes.h"
#include "String.h"
#include "Macros.h"
#include "ArrayList.h"

JAMSTL_NAMESPACE_BEGIN

    class StringStream {
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

        float toFloat() {
            float ToFloat = 0, Division = 1;
            int i;
            int LengthOfString = _str.Length;
            for(i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && (_str[i] == '.' || _str[i] == '-')) continue;
                if(i != 0 && _str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToFloat = ToFloat * 10 + _str[i] - '0';
            }

            float floatTempNumber = 0;
            if(_str[i] == '.') {
                floatTempNumber = readFractions(i + 1, _str.Length, Division);
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

        float toDouble() {
            double ToDouble = 0, Division = 1;
            int i;
            int LengthOfString = _str.Length;
            for(i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && (_str[i] == '.' || _str[i] == '-')) continue;
                if(i != 0 && _str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToDouble = ToDouble * 10 + _str[i] - '0';
            }

            double doubleTempNumber = 0;
            if(_str[i] == '.') {
                doubleTempNumber = readFractions(i + 1, _str.Length, Division);
            }

            if(_str[0] == '-') {
                if((ToDouble + doubleTempNumber) - 
                    (long long)(ToDouble + doubleTempNumber) == 0)
                        return -1 * (ToDouble);
                return -1 * (ToDouble + doubleTempNumber);
            }

            ToDouble = ToDouble + Division;
            if(ToDouble - (long long)ToDouble == 0) return ToDouble - 1;
            return ToDouble;
        }

        float toLDouble() {
            double ToLongDouble = 0, Division = 1;
            int i;
            int LengthOfString = _str.Length;
            for(i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && (_str[i] == '.' || _str[i] == '-')) continue;
                if(i != 0 && _str[i] == '.') break;
                if((_str[i] > '9' || _str[i] < '0')) break;
                ToLongDouble = ToLongDouble * 10 + _str[i] - '0';
            }

            double LongDoubleTempNumber = 0;
            if(_str[i] == '.') {
                LongDoubleTempNumber = readFractions(i + 1, _str.Length, Division);
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

        unsigned short int toUShortInt() {
            unsigned short int ToUShortInt = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToUShortInt = ToUShortInt * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return ToUShortInt;
            return ToUShortInt;
        }

        unsigned int toUInt() {
            unsigned int ToUnsignedInt = 0;

            for(int i = 0; _str[i] != '\0'; i++) {
                if(i == 0 && _str[i] == '-') continue;
                else if(_str[i] == '.') break;
                if(_str[i] > '9' || _str[i] < '0') break;
                ToUnsignedInt = ToUnsignedInt * 10 + _str[i] - '0';
            }

            if(_str[0] == '-') return ToUnsignedInt;
            return ToUnsignedInt;
        }

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

        StringStream& operator<<(const String& str) {
            _str += str;
            return *this;
        }

        StringStream& operator<<(const char* str) {
            _str += str;
            return *this;
        }

        StringStream& operator<<(const char& c) {
            _str += c;
            return *this;
        }

        StringStream& operator<<(const StringStream& stream) {
            _str += stream._str;
            return *this;
        }

        template<typename Type>
        StringStream& operator<<(const Type& num) {
            _str += toString(num);
            // Int = num;
            // UInt = num;
            // ULLong = num;
            // integer = num;
            // floatNumber = num;
            // doubleNumber = num;
            // shortNumber = num;
            // UShort = num;
            // longNumber = num;
            // ULong = num;
            // LongLong = num;
            // ULongLong = num;
            // shortNum = num;
            // longNum = num;
            // floatNum = num;
            // doubleNum = num;
            return *this;
        }



        StringStream& operator>>(String& str) {
            str = _str;
            return *this;
        }

        StringStream& operator>>(char* str) {
            str = _str.c_string();
            return *this;
        }

        StringStream& operator>>(char& c) {
            c = _str[0];
            return *this;
        }

        StringStream& operator>>(short& shortInt) {
            shortInt = toSInt();
            return *this;
        }

        StringStream& operator>>(int& valueType) {
            valueType = toInt();
            return *this;
        }

        StringStream& operator>>(long& valueType) {
            valueType = toLInt();
            return *this;
        }

        StringStream& operator>>(long long& valueType) {
            valueType = toLLInt();
            return *this;
        }

        StringStream& operator>>(unsigned short& valueType) {
            valueType = toUShortInt();
            return *this;
        }

        StringStream& operator>>(unsigned int& valueType) {
            valueType = toUInt();
            return *this;
        }

        StringStream& operator>>(unsigned long& valueType) {
            valueType = toULInt();
            return *this;
        }

        StringStream& operator>>(unsigned long long& valueType) {
            valueType = toULLInt();
            return *this;
        }

        StringStream& operator>>(float& valueType) {
            valueType = toFloat();
            return *this;
        }

        StringStream& operator>>(double& valueType) {
            valueType = toDouble();
            return *this;
        }

        StringStream& operator>>(long double& valueType) {
            valueType = toLDouble();
            return *this;
        }



        StringStream& operator>>(Short& valueType) {
            valueType = toSInt();
            return *this;
        }

        StringStream& operator>>(Integer& valueType) {
            valueType = toInt();
            return *this;
        }
        
        StringStream& operator>>(Long& valueType) {
            valueType = toLLInt();
            return *this;
        }

        StringStream& operator>>(Float& valueType) {
            valueType = toFloat();
            return *this;
        }

        StringStream& operator>>(Double& valueType) {
            valueType = toDouble();
            return *this;
        }


        
        String str() const {
            return _str;
        }

        StringStream& clear() {
            _str = "";
            return *this;
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