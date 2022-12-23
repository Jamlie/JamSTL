#pragma once

#ifndef JAMSTLCPP_H
#define JAMSTLCPP_H 1

#include "Macros.h"
#include "Collections/ArrayList.h"
#include "Exception/Exception.h"
#include "Datatypes.h"
#include "Math.h"
#include "Printer.h"
#include "Scanner.h"
#include "String/StringHelper.h"
#include "Collections/Array.h"
#include "Collections/LinkedList.h"
#include "type_traits.h"
#include "bits/type_traits.h"
#include "String/StringStream.h"
#include "Collections/Stack.h"
#include "Collections/Queue.h"
#include "Collections/HashMap.h"
#include "Arrays.h"
#include "GarbageCollector/GarbageCollector.h"
#include "Random.h"

JAMSTL_NAMESPACE_BEGIN

    template<typename WrapperClass>
    String type(const WrapperClass& wrapper) {
        using namespace jamstl::type_traits;

        if(isFunction<WrapperClass>::value) {
            return "Function";
        }

        if(isSame<unsigned short, WrapperClass>::value) {
            return "Unsigned Short";
        }

        if(isSame<unsigned int, WrapperClass>::value) {
            return "Unsigned";
        }

        if(isSame<unsigned long, WrapperClass>::value) {
            return "Unsigned Long";
        }

        if(isSame<unsigned long long, WrapperClass>::value) {
            return "Unsigned Long Long";
        }

        if(isSame<String, WrapperClass>::value ||
           isSame<const char*, WrapperClass>::value ||
           isSame<char*, WrapperClass>::value) {
            return "String";
        }

        if(isSame<Character, WrapperClass>::value ||
            isSame<char, WrapperClass>::value) {
            return "Character";
        }

        if(isSame<Double, WrapperClass>::value ||
            isSame<double, WrapperClass>::value ||
            isSame<long double, WrapperClass>::value) {
            return "Double";
        }
        
        if(isSame<Float, WrapperClass>::value ||
            isSame<float, WrapperClass>::value) {
            return "Float";
        }

        if(isSame<Integer, WrapperClass>::value ||
            isSame<int, WrapperClass>::value ||
            isSame<long, WrapperClass>::value) {
            return "Integer";
        }

        if(isSame<Short, WrapperClass>::value || 
            isSame<short, WrapperClass>::value) {
            return "Short";
        }

        if(isSame<Boolean, WrapperClass>::value ||
            isSame<bool, WrapperClass>::value) {
            return "Boolean";
        }

        if(isSame<Long, WrapperClass>::value || 
            isSame<long long, WrapperClass>::value) {
            return "Long";
        }

        if(isSame<Byte, WrapperClass>::value ||
            isSame<unsigned char, WrapperClass>::value) {
            return "Byte";
        }

        if(isArrayList<WrapperClass>::value) {
            return "ArrayList";
        }

        if(isLinkedList<WrapperClass>::value) {
            return "LinkedList";
        }

        if(isStack<WrapperClass>::value) {
            return "Stack";
        }

        if(isQueue<WrapperClass>::value) {
            return "Queue";
        }

        if(isArray<WrapperClass>::value) {
            if(isPrimitive<WrapperClass>::value) {
                return "Array";
            }
        }

        if(isPointer<WrapperClass>::value) {
            return "Pointer";
        }

        if(isObject<WrapperClass>::value) {
            return "Object";
        }
        

        return "Unknown";
    }

    template<class T, class U>
    bool instanceof(U object) {
        return dynamic_cast<T*>(object) != nullptr;
    } 


JAMSTL_NAMESPACE_END

#endif