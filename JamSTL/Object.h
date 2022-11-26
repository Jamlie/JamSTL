#pragma once

#ifndef JAMSTL_OBJECT_H
#define JAMSTL_OBJECT_H 1
#include "Macros.h"
#include "type_traits.h"
#include "String/ObjectString.h"
#include "bits/HashBytes.h"
// #include "bits/oldObject.h"
#include <typeinfo>

JAMSTL_NAMESPACE_BEGIN

    class Object {
    private:
        InnerString value = "";
        InnerString* valuePointer;
    public:
        Object() {}
        Object(const Object& other) {}
        Object(Object&& other) {}
        virtual ~Object() {}

        bool equals(const Object& other) const {
            return this == &other;
        }

        InnerString getThisClassName() {
            return typeid(*this).name();
        }

        bool operator==(const Object& other) const {
            return this == &other;
        }


        bool operator!=(const Object& other) const {
            return this != &other;
        }

        // void* operator new(size_t size) {
        //     return ::operator new(size);
        // }

        void operator delete(void* ptr) {
            ::operator delete(ptr);
        }

        void* operator new[](size_t size) {
            return ::operator new[](size);
        }

        void operator delete[](void* ptr) {
            ::operator delete[](ptr);
        }


        Object* operator->() {
            return this;
        }

        const Object* operator->() const {
            return this;
        }

        Object& operator*() {
            return *this;
        }

        const Object& operator*() const {
            return *this;
        }



        Object& operator=(const Object& other) {
            this->value = other.value;
            this->valuePointer = other.valuePointer;
            return *this;
        }
        

        Object& operator=(Object&& other) {
            this->value = jamstl::type_traits::move(other.value);
            this->valuePointer = other.valuePointer;
            return *this;
        }

        operator void*() {
            return this;
        }


        // usize hash() const {
        //     return hashBytes(*this, sizeof(this), 0);
        // }

        InnerString getClassName() const {
            InnerString className = typeid(*this).name();
            int i = 0;
            if((className[i] >= '0' || className[i] <= '9') 
                && className[className.length - 1] != 'E') {
                className.pop(i);
                i++;
                return className;
            }
            className.pop(0);
            className.pop(0);
            for(int j = 0; j < className.length; j++) {
                if(className[j] >= 'A' && className[j] <= 'Z') {
                    break;
                }
                if(className[j] > '9') {
                    className.pop(j);
                    j--;
                }
            }
            className.pop();
            className.pop(0);
            if(className[0] >= '0' && className[0] <= '9') {
                className.pop(0);
            }
            return className;
        }
    
        // InnerString toString() const {
        //     InnerString result;
        //     result = "";
        //     result += getClassName();
        //     result += '#';
        //     result << hash();
        //     return result;
        // }

        virtual const char* toCString() const {}

        friend std::ostream& operator<<(std::ostream& os, const Object& obj) {
            return os << obj.value;
        }
        friend std::ostream& operator<<(std::ostream& os, Object&& obj) {
            return os << obj.value;
        }
        friend std::ostream& operator<<(std::ostream& os, const Object* obj) {
            return os << *obj->value;
        }
        friend std::ostream& operator<<(std::ostream& os, Object*&& obj) {
            return os << obj->value;
        }
    };


JAMSTL_NAMESPACE_END

#endif