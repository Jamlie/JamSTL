#pragma once

#ifndef JAMSTL_TYPE_TRAITS_TWO_H
#define JAMSTL_TYPE_TRAITS_TWO_H 1
#include "../TypeTraits.h"
#include "../Collections/Stack.h"
#include "../Collections/Queue.h"
#include "../Macros.h"

JAMSTL_NAMESPACE_BEGIN

    namespace TypeTraits {

        template<typename T>
        struct isLinkedList {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isStack {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isStack<Stack<T>> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isQueue {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isQueue<Queue<T>> {
            static constexpr bool value = true;
        };


        template<typename T>
        struct isPrimitive {
            static constexpr bool value = false;
        };

        template<>
        struct isPrimitive<char> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<short> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<int> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<long> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<long long> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<float> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<double> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<long double> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<bool> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<unsigned char> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<unsigned short> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<unsigned int> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<unsigned long> {
            static constexpr bool value = true;
        };

        template<>
        struct isPrimitive<unsigned long long> {
            static constexpr bool value = true;
        };

        template<typename E>
        struct isPrimitive<E&> {
            static constexpr bool value = isPrimitive<removeReferenceT<E>>::value;
        };

        template<typename E>
        struct isPrimitive<E&&> {
            static constexpr bool value = isPrimitive<removeReferenceT<E>>::value;
        };

        template<typename E>
        struct isPrimitive<E const> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        template<typename E>
        struct isPrimitive<E volatile> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        template<typename E>
        struct isPrimitive<E const volatile> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        template<typename E>
        struct isPrimitive<E*> {
            static constexpr bool value = isPrimitive<E>::value;
        };
        
        template<typename E>
        struct isPrimitive<E* const> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        template<typename E>
        struct isPrimitive<E* volatile> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        template<typename E>
        struct isPrimitive<E* const volatile> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        template<typename E>
        struct isPrimitive<E[]> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        template<typename E>
        struct isPrimitive<const E[]> {
            static constexpr bool value = isPrimitive<E>::value;
        };

        
        
        template<typename T>
        struct isObject {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T*> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T volatile> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const volatile> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T* const> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T* volatile> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T* const volatile> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const&&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T volatile&&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const volatile&&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T&&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T volatile&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const volatile&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T&> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const*> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T volatile*> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T const volatile*> {
            static constexpr bool value = !isPrimitive<T>::value;
        };

        template<typename T>
        struct isObject<T[]> {
            static constexpr bool value = !isPrimitive<T[]>::value && 
                                    isArray<T[]>::value;
        };

        template<typename T>
        struct isObject<const T[]> {
            static constexpr bool value = !isPrimitive<const T[]>::value &&
                                    isArray<const T[]>::value;
        };



    }

JAMSTL_NAMESPACE_END

#endif