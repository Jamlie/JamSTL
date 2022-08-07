#pragma once

#ifndef JAMSTL_BOOLEAN_H
#define JAMSTL_BOOLEAN_H 1
#include <ostream>
#include <istream>
#include "Macros.h"
#include "Object.h"

JAMSTL_NAMESPACE_BEGIN

    /**
    * @brief A wrapper boolean class
    * 
    */
    class Boolean extends Object {
    private:
        bool value;
    public:
        Boolean() : value(false) {}
        template<typename Type>
        Boolean(const Type& value) : value(value) {}
        Boolean(const Boolean& other) : value(other.value) {}
        Boolean(Boolean&& other) noexcept : value(other.value) {}


        operator bool() const {
            return this->value;
        }

        void setValue(const bool& value) {
            this->value = value;
        }

        void setValue(bool&& value) {
            this->value = value;
        }

        bool getValue() const {
            return this->value;
        }

        const char* toString() const {
            return this->value ? "true" : "false";
        }

        const char* type() const {
            return "Boolean";
        }



        Boolean& operator=(const Boolean& other) {
            this->value = other.value;
            return *this;
        }

        Boolean& operator=(Boolean&& other) noexcept {
            this->value = other.value;
            return *this;
        }

        template<typename Type>
        Boolean& operator=(const Type& other) {
            this->value = other;
            return *this;
        }



        bool operator==(const Boolean& other) const {
            return this->value == other.value;
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }



        bool operator!=(const Boolean& other) const {
            return this->value != other.value;
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }



        friend std::ostream& operator<<(std::ostream& out, const Boolean& boolean) {
            if(boolean.value == true) {
                out << true;
                return out;
            }
            out << false;
            return out;
        }

        friend std::istream& operator>>(std::istream& in, Boolean& boolean) {
            in >> boolean.value;
            return in;
        }
    };



JAMSTL_NAMESPACE_END


#endif