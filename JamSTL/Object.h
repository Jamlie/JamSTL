#pragma once

#ifndef JAMSTL_OBJECT_H
#define JAMSTL_OBJECT_H
#include "Macros.h"
#include "TypeTraits.h"
#include "String/ObjectString.h"
#include "bits/HashBytes.h"
#include <typeinfo>

JAMSTL_NAMESPACE_BEGIN

    class Object {
    public:
        Object() = default;
        virtual ~Object() = default;

        virtual bool equals(const Object& obj) const {
            return this == &obj;
        }

        virtual bool equals(Object* obj) const {
            return this == obj;
        }


        ObjectString getClassName() const {
            ObjectString className = typeid(*this).name();
            int i = 0;
            if((className[i] >= '0' || className[i] <= '9') 
                && className[className.length - 1] != 'E') {
                className.pop(i);
                i++;
                return className;
            }
            className.pop(0);
            className.pop(0);
            for(unsigned int j = 0; j < className.length; j++) {
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

            if(!className.contains("INS")) {
                return className;
            }
            
            int index = className.indexOf("INS");
            className = className.substring(0, index);
            return className;
        }

        virtual usize hashCode() const {
            return reinterpret_cast<usize>(this);
        }

        template<class T, class U>
        static bool instanceof(const U* value) {
            return dynamic_cast<const T*>(value) != nullptr;
        }

        template<class T>
        T* cast() {
            return dynamic_cast<T*>(this);
        }

        virtual const char* getTypeName() const {
            return typeid(*this).name();
        }

        friend bool operator==(Object& lhs, Object& rhs) {
            return lhs.equals(rhs);
        }

        friend bool operator!=(Object& lhs, Object& rhs) {
            return !(lhs == rhs);
        }

        friend bool operator<(const Object& lhs, const Object& rhs) {
            return lhs.hashCode() < rhs.hashCode();
        }

        friend bool operator>(const Object& lhs, const Object& rhs) {
            return rhs < lhs;
        }

        friend bool operator<=(const Object& lhs, const Object& rhs) {
            return !(lhs > rhs);
        }

        friend bool operator>=(const Object& lhs, const Object& rhs) {
            return !(lhs < rhs);
        }

    };

JAMSTL_NAMESPACE_END

#endif