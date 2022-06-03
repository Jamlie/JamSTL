#pragma once

#include "Datatypes.h"
#include "ArrayList.h"
#include "Macros.h"

#ifndef JAMSTL_TYPE_TRAITS_H
#define JAMSTL_TYPE_TRAITS_H

JAMSTL_NAMESPACE_BEGIN
    namespace type_traits {
        template<typename T>
        struct is_false {
            static constexpr bool value = false;
        };

        template<>
        struct is_false<bool> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct is_true {
            static constexpr bool value = false;
        };

        template<>
        struct is_true<bool> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct remove_reference {
            typedef T type;
        };

        template<typename T>
        struct remove_reference<T&> {
            typedef T type;
        };

        template<typename T>
        struct remove_reference<T&&> {
            typedef T type;
        };

        template<typename T>
        struct remove_const {
            typedef T type;
        };

        template<typename T>
        struct remove_const<const T> {
            typedef T type;
        };

        template<typename firstType, typename secondType>
        struct is_same {
            static constexpr bool value = false;
        };


        template<typename firstType>
        struct is_same<firstType, firstType> {
            static constexpr bool value = true;
        };


        template<typename firstType, typename secondType>
        struct is_base_of {
            static constexpr bool value = false;
        };

        struct is_base_of_helper {
            template<typename firstType, typename secondType>
            static constexpr bool check(secondType*);

            template<typename firstType, typename secondType>
            static constexpr bool check(...);
        };

        template<typename T>
        struct is_integral {
            static constexpr bool value = false;
        };

        template<>
        struct is_integral<bool> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<char> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<short> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<int> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<long> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<long long> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<unsigned char> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<unsigned short> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<unsigned int> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<unsigned long> {
            static constexpr bool value = true;
        };

        template<>
        struct is_integral<unsigned long long> {
            static constexpr bool value = true;
        };



        template<typename Type, Type Value>
        struct integral_constant {
            static constexpr Type value = Value;
            typedef Type value_type;
            typedef integral_constant<Type, Value> type;

            constexpr operator value_type() const {
                return value;
            }

            constexpr value_type operator()() const {
                return value;
            }
        };

        template<typename Type, Type value>
        constexpr Type integral_constant<Type, value>::value;

        typedef integral_constant<bool, true> true_type;
        typedef integral_constant<bool, false> false_type;

        template<bool value>
        using bool_constant = integral_constant<bool, value>;



        template<typename>
        struct is_function : false_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...)> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...)&> : true_type {};
        
        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...)&&> : true_type {};
        
        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......)> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......)&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......)&&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) const> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) const&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) const&&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) const> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) const&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) const&&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) volatile> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) volatile&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) volatile&&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) volatile> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) volatile&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) volatile&&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) const volatile> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) const volatile&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments...) const volatile&&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) const volatile> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) const volatile&> : true_type {};

        template<typename returnType, typename... arguments>
        struct is_function<returnType(arguments......) const volatile&&> : true_type {};



        template<typename T>
        struct is_unsigned {
            static constexpr bool value = false;
        };

        template<>
        struct is_unsigned<unsigned char> {
            static constexpr bool value = true;
        };

        template<>
        struct is_unsigned<unsigned short> {
            static constexpr bool value = true;
        };

        template<>
        struct is_unsigned<unsigned int> {
            static constexpr bool value = true;
        };

        template<>
        struct is_unsigned<unsigned long> {
            static constexpr bool value = true;
        };

        template<>
        struct is_unsigned<unsigned long long> {
            static constexpr bool value = true;
        };
        

        template<typename T>
        struct numeric_limits {
            static constexpr bool is_specialized = false;
            static constexpr T min() {
                return T();
            }
            static constexpr T max() {
                return T();
            }
        };
        

        template<typename T>
        using remove_reference_t = typename remove_reference<T>::type;

        

        template<typename T>
        constexpr remove_reference_t<T>&& move(T&& t) noexcept {
            return static_cast<remove_reference_t<T>&&>(t);
        }

        template<typename T>
        constexpr remove_reference_t<T>&& move(remove_reference_t<T>&& t) noexcept {
            return static_cast<remove_reference_t<T>&&>(t);
        }

        template<typename T>
        constexpr remove_reference_t<T>&& move(remove_reference_t<T>& t) noexcept {
            return static_cast<remove_reference_t<T>&&>(t);
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
        constexpr T&& forward(remove_reference_t<T>&& t) noexcept {
            return static_cast<T&&>(t);
        }

        template<typename T>
        constexpr T&& forward(remove_reference_t<T>& t) noexcept {
            return static_cast<T&&>(t);
        }



        template<bool Condition, typename if_true, typename if_false>
        struct conditional {
            using type = if_true;
        };

        template<typename if_true, typename if_false>
        struct conditional<false, if_true, if_false> {
            using type = if_false;
        };



        template<typename...>
        struct or_;

        template<>
        struct or_<> : public false_type {};

        template<typename Type>
        struct or_<Type> : public Type {};

        template<typename Type1, typename Type2>
        struct or_<Type1, Type2> : public conditional<Type1::value, Type1, Type2>::value {};

        template<typename Type1, typename Type2, typename... Types>
        struct or_<Type1, Type2, Types...> 
            : public conditional<Type1::value, true_type, or_<Type2, Types...>> {};


        template<typename...>
        struct add_rvalue_reference;

        template<typename T>
        struct add_rvalue_reference<T>::type declval() noexcept;


        template<typename T>
        struct is_array {
            static constexpr bool value = false;
        };

        template<typename T>
        struct is_array<T[]> {
            static constexpr bool value = true;
        };

        template<typename T, size_t N>
        struct is_array<T[N]> {
            static constexpr bool value = true;
        };



        template<typename T>
        struct is_pointer {
            static constexpr bool value = false;
        };

        template<typename T>
        struct is_pointer<T*> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct is_pointer<T* const> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct is_pointer<T* volatile> {
            static constexpr bool value = true;
        };

        template<typename T>
        struct is_pointer<T* const volatile> {
            static constexpr bool value = true;
        };

        

        template<typename T>
        struct is_reference {
            static constexpr bool value = false;
        };

        template<typename T>
        struct is_reference<T&> {
            static constexpr bool value = true;
        };

        template <typename...>
        using void_t = void;

        template <typename T>
        struct is_void {
            static constexpr bool value = false;
        };

        template <>
        struct is_void<void> {
            static constexpr bool value = true;
        };

        template<typename Type>
        struct declval_protector {
            static const bool stop = false;
            static typename add_rvalue_reference<Type>::type delegate();
        };

        template <typename From, typename To,
                  bool = or_<is_void<From>, is_function<To>, is_array<To>>::value>
        struct is_convertible_helper {
            typedef typename is_void<To>::type type;
        };

        template<typename Type>
        inline typename add_rvalue_reference<Type>::type declval() noexcept {
            static_assert(declval_protector<Type>::stop,
                "declval() is not supported for this type");

            return declval_protector<Type>::delegate();
        }

        template <typename From, typename To>
        class is_convertible_helper<From, To, false> {
            template<typename To1>
            static void test_aux(To1);

            template<typename From1, typename To1,
                typename = decltype(test_aux<To1>(declval<From1>()))>

            static true_type test(int);

            template<typename, typename>
            static false_type test(...);

        public:
            typedef decltype(test<From, To>(0)) type;
        };

        template <typename From, typename To>
        struct is_convertible
            : is_convertible_helper<From, To>::type {};    
    }

JAMSTL_NAMESPACE_END
    


#endif