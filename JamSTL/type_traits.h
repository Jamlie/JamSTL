#pragma once

#include "Macros.h"

#ifndef JAMSTL_TYPE_TRAITS_H
#define JAMSTL_TYPE_TRAITS_H 1

JAMSTL_NAMESPACE_BEGIN
    namespace type_traits {
        template<typename T>
        struct isFalse {
            static constexpr bool value = false;
        };

        template<>
        struct isFalse<bool> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct isTrue {
            static constexpr bool value = false;
        };

        template<>
        struct isTrue<bool> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct removeReference {
            typedef T type;
        };

        template<typename T>
        struct removeReference<T&> {
            typedef T type;
        };

        template<typename T>
        struct removeReference<T&&> {
            typedef T type;
        };

        template<typename T>
        struct removeConst {
            typedef T type;
        };

        template<typename T>
        struct removeConst<const T> {
            typedef T type;
        };

        template<typename T>
        struct removeConstT {
            typedef T type;
        };

        template<typename T>
        struct removeConstT<T const> {
            typedef T type;
        };

        template<typename T>
        struct removeConstT<T const&> {
            typedef T type;
        };

        template<typename T>
        struct removeConstT<T const&&> {
            typedef T type;
        };

        template<typename T>
        struct removeVolatile {
            typedef T type;
        };

        template<typename T>
        struct removeVolatile<volatile T> {
            typedef T type;
        };

        template<typename T>
        struct removeVolatileT {
            typedef T type;
        };

        template<typename T>
        struct removeVolatileT<T volatile> {
            typedef T type;
        };

        template<typename T>
        struct removeVolatileT<T volatile&> {
            typedef T type;
        };

        template<typename T>
        struct removeVolatileT<T volatile&&> {
            typedef T type;
        };

        template<typename T>
        struct removeConstVolatile {
            typedef typename removeConst<typename removeVolatile<T>::type>::type type;
        };

        template<typename T>
        struct removeConstVolatileT {
            typedef typename removeConst<typename removeVolatileT<T>::type>::type type;
        };

        

        template<typename T>
        struct removePointer {
            typedef T type;
        };

        template<typename T>
        struct removePointer<T*> {
            typedef T type;
        };

        template<typename T>
        struct removePointer<T* const> {
            typedef T type;
        };

        template<typename T>
        struct removePointer<T* volatile> {
            typedef T type;
        };

        template<typename T>
        struct removePointer<T* const volatile> {
            typedef T type;
        };

        template<typename T>
        struct removePointer<T const> {
            typedef T type;
        };

        template<typename T>
        struct removePointer<T volatile> {
            typedef T type;
        };

        template<typename firstType, typename secondType>
        struct isSame {
            static constexpr bool value = false;
        };


        template<typename firstType>
        struct isSame<firstType, firstType> {
            static constexpr bool value = true;
        };


        template<typename firstType, typename secondType>
        struct isBaseOf {
            static constexpr bool value = false;
        };

        struct isBaseOfHelper {
            template<typename firstType, typename secondType>
            static constexpr bool check(secondType*);

            template<typename firstType, typename secondType>
            static constexpr bool check(...);
        };

        template<typename T>
        struct isIntegral {
            static constexpr bool value = false;
        };

        template<>
        struct isIntegral<bool> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<char> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<short> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<int> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<long> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<long long> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<unsigned char> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<unsigned short> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<unsigned int> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<unsigned long> {
            static constexpr bool value = true;
        };

        template<>
        struct isIntegral<unsigned long long> {
            static constexpr bool value = true;
        };


        template<typename T>
        struct isNumber {
            static constexpr bool value = false;
        };

        template<>
        struct isNumber<bool> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<char> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<short> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<int> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<long> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<long long> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<unsigned char> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<unsigned short> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<unsigned int> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<unsigned long> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<unsigned long long> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<float> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<double> {
            static constexpr bool value = true;
        };

        template<>
        struct isNumber<long double> {
            static constexpr bool value = true;
        };

        template<typename Type, Type Value>
        struct integralConstant {
            static constexpr Type value = Value;
            typedef Type valueType;
            typedef integralConstant<Type, Value> type;

            constexpr operator valueType() const {
                return value;
            }

            constexpr valueType operator()() const {
                return value;
            }
        };

        template<typename Type, Type value>
        constexpr Type integralConstant<Type, value>::value;

        typedef integralConstant<bool, true> trueType;
        typedef integralConstant<bool, false> falseType;

        template<bool value>
        using boolConstant = integralConstant<bool, value>;



        template<typename>
        struct isFunction : falseType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...)> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...)&> : trueType {};
        
        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...)&&> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) const> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) const&> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) const&&> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) volatile> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) volatile&> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) volatile&&> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) const volatile> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) const volatile&> : trueType {};

        template<typename returnType, typename... arguments>
        struct isFunction<returnType(arguments...) const volatile&&> : trueType {};
        


        template<typename T>
        struct isUnsigned {
            static constexpr bool value = false;
        };

        template<>
        struct isUnsigned<unsigned char> {
            static constexpr bool value = true;
        };

        template<>
        struct isUnsigned<unsigned short> {
            static constexpr bool value = true;
        };

        template<>
        struct isUnsigned<unsigned int> {
            static constexpr bool value = true;
        };

        template<>
        struct isUnsigned<unsigned long> {
            static constexpr bool value = true;
        };

        template<>
        struct isUnsigned<unsigned long long> {
            static constexpr bool value = true;
        };
        

        template<typename T>
        struct numericLimits {
            static constexpr bool is_specialized = false;
            static constexpr T min() {
                return T();
            }
            static constexpr T max() {
                return T();
            }
        };
        

        template<typename T>
        using removeReferenceT = typename removeReference<T>::type;

        

        template<typename T>
        constexpr removeReferenceT<T>&& move(T&& t) noexcept {
            return static_cast<removeReferenceT<T>&&>(t);
        }

        template<typename T>
        constexpr removeReferenceT<T>&& move(removeReferenceT<T>&& t) noexcept {
            return static_cast<removeReferenceT<T>&&>(t);
        }

        template<typename T>
        constexpr removeReferenceT<T>&& move(removeReferenceT<T>& t) noexcept {
            return static_cast<removeReferenceT<T>&&>(t);
        }

        template<typename T>
        constexpr T&& forward(T& t) noexcept {
            return static_cast<T&&>(t);
        }

        template<typename T>
        constexpr T&& forward(T&& t) noexcept {
            return static_cast<T&&>(t);
        }

        template<typename T>
        constexpr T&& forward(removeReferenceT<T>&& t) noexcept {
            return static_cast<T&&>(t);
        }

        template<typename T>
        constexpr T&& forward(removeReferenceT<T>& t) noexcept {
            return static_cast<T&&>(t);
        }



        template<bool Condition, typename ifTrue, typename ifFalse>
        struct conditional {
            using type = ifTrue;
        };

        template<typename ifTrue, typename ifFalse>
        struct conditional<false, ifTrue, ifFalse> {
            using type = ifFalse;
        };



        template<typename...>
        struct or_;

        template<>
        struct or_<> : public falseType {};

        template<typename Type>
        struct or_<Type> : public Type {};

        template<typename Type1, typename Type2>
        struct or_<Type1, Type2> : public conditional<Type1::value, Type1, Type2>::value {};

        template<typename Type1, typename Type2, typename... Types>
        struct or_<Type1, Type2, Types...> 
            : public conditional<Type1::value, trueType, or_<Type2, Types...>> {};


        template<typename...>
        struct and_;

        template<>
        struct and_<> : public trueType {};

        template<typename Type>
        struct and_<Type> : public Type {};

        template<typename Type1, typename Type2>
        struct and_<Type1, Type2> : public conditional<Type1::value, Type2, Type1>::value {};

        template<typename Type1, typename Type2, typename Type3, typename... Types>
        struct and_<Type1, Type2, Type3, Types...> 
            : public conditional<Type1::value, and_<Type2, Type3, Types...>, Type1>::type {};

        template<typename...>
        struct addRvalueReference;

        template<typename T>
        struct addRvalueReference<T>::type declval() noexcept;


        template<typename T>
        struct isArray {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isArray<T[]> {
            static constexpr bool value = true;
        };

        template<typename T, size_t N>
        struct isArray<T[N]> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct isPointer {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isPointer<T*> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isPointer<T* const> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isPointer<T* volatile> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isPointer<T* const volatile> {
            static constexpr bool value = true;
        };


        template<typename T>
        struct isConst {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isConst<const T> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isConst<const T&> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isConst<const T&&> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct isVolatile {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isVolatile<volatile T> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isVolatile<volatile T&> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isVolatile<volatile T&&> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct isLvalueReference {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isLvalueReference<T&> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isLvalueReference<T&&> {
            static constexpr bool value = false;
        };



        template<typename T>
        struct isRvalueReference {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isRvalueReference<T&&> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct isRvalueReference<T&> {
            static constexpr bool value = false;
        };

        
        

        template<typename T>
        struct isReference {
            static constexpr bool value = false;
        };

        template<typename T>
        struct isReference<T&> {
            static constexpr bool value = true;
        };

        template <typename...>
        using voidT = void;

        template <typename T>
        struct isVoid {
            static constexpr bool value = false;
        };

        template <>
        struct isVoid<void> {
            static constexpr bool value = true;
        };

        template<typename Type>
        struct declvalProtector {
            static const bool stop = false;
            static typename addRvalueReference<Type>::type delegate();
        };

        template <typename From, typename To,
                  bool = or_<isVoid<From>, isFunction<To>, isArray<To>>::value>
        struct isConvertibleHelper {
            typedef typename isVoid<To>::type type;
        };

        template<typename Type>
        inline typename addRvalueReference<Type>::type declval() noexcept {
            static_assert(declvalProtector<Type>::stop,
                "declval() is not supported for this type");

            return declvalProtector<Type>::delegate();
        }

        template <typename From, typename To>
        class isConvertibleHelper<From, To, false> {
            template<typename To1>
            static void test_aux(To1);

            template<typename From1, typename To1,
                typename = decltype(test_aux<To1>(declval<From1>()))>

            static trueType test(int);

            template<typename, typename>
            static falseType test(...);

        public:
            typedef decltype(test<From, To>(0)) type;
        };

        template <typename From, typename To>
        struct isConvertible
            : isConvertibleHelper<From, To>::type {};    

        template<bool, typename Type = void>
        struct enableIf {};

        template<typename Type>
        struct enableIf<true, Type> {
            using type = Type;
        };
    }

JAMSTL_NAMESPACE_END
    


#endif