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
        Boolean(const char* trueOfFalse) {
            if(trueOfFalse == "false") {
                value = false;
            } else {
                value = true;
            }
        }


        operator bool() const {
            return this->value;
        }

        const char* valueOf() const {
            if(this->value) {
                return "true";
            }
            return "false";
        }

        const char* toString() const {
            return this->value ? "true" : "false";
        }

        const char* toCString() const {
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

        Boolean& operator=(const char* trueOrFalse) {
            if(trueOrFalse == "false") this->value = false;
            else this->value = true;
            return *this;
        }



        bool operator==(const Boolean& other) const {
            return this->value == other.value;
        }

        template<typename Type>
        bool operator==(const Type& other) const {
            return this->value == other;
        }

        bool operator==(const char* other) const {
            return this->value == (other == "true");
        }



        bool operator!=(const Boolean& other) const {
            return this->value != other.value;
        }

        template<typename Type>
        bool operator!=(const Type& other) const {
            return this->value != other;
        }



        friend std::ostream& operator<<(std::ostream& out, const Boolean& boolean) {
            if(boolean.value) {
                out << "true";
                return out;
            }
            out << "false";
            return out;
        }

        friend std::istream& operator>>(std::istream& in, Boolean& boolean) {
            in >> boolean.value;
            return in;
        }
    };



JAMSTL_NAMESPACE_END


#endif