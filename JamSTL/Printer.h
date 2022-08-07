#pragma once

#ifndef JAMSTL_PRINTER_H
#define JAMSTL_PRINTER_H 1

#include <ostream>
#include "Datatypes.h"
#include "Collections/ArrayList.h"
#include "Macros.h"
#include "Collections/Array.h"
#include "Collections/LinkedList.h"
#include "String/String.h"
#include "Object.h"

JAMSTL_NAMESPACE_BEGIN

    class Printer extends Object {
    public:
        Printer() = default;

        template <typename Type>
        static void print(const Type& value)
        {
            std::cout << value;
        }

        template<typename Type, usize size>
        static void print(const Array<Type, size>& arr) {
            std::cout << "[ ";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << arr[i] << ", ";
                } else {
                    std::cout << arr[i] << " ]";
                }
            }
        }

        // template <typename Type>
        // static void print(const ArrayList<Type>& arr) {
        //     std::cout << "[ ";
        //     for(usize i = 0; i < arr.size(); i++) {
        //         if(i < arr.size() - 1) {
        //             std::cout << arr[i] << ", ";
        //         } else {
        //             std::cout << arr[i] << " ]";
        //         }
        //     }
        // }

        template <typename Type>
        static void print(const LinkedList<Type>& list) {
            std::cout << "[ ";
            for(LinkedList<int>::Iterator it = list.begin(); it != list.end(); it++) {
                if(it != list.begin()) {
                    std::cout << ", ";
                }
                std::cout << *it;
            }

            std::cout << " ]";
        }

        template <typename Type, usize size>
        static void print(const Type (&array)[size]) {
            if(jamstl::type_traits::isSame<Type, char>::value ||
             jamstl::type_traits::isSame<Type, unsigned char>::value) {
                std::cout << array;
            } else {std::cout << "[ ";
                for(usize i = 0; i < size; i++) {
                    if(i < size - 1) {
                        std::cout << array[i] << ", ";
                    } else {
                        std::cout << array[i] << " ]";
                    }
                }
            }
        }



        static void println() {
            std::cout << '\n';
        }

        static void println(Object& obj) {
            std::cout << obj << '\n';
        }

        template<typename Type>
        static void println(const Type& value) {
            std::cout << value << ' ';
            println();
        }

        template<typename Type, usize size>
        static void println(const Array<Type, size>& arr) {
            std::cout << "[ ";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << arr[i] << ", ";
                } else {
                    std::cout << arr[i] << " ]";
                }
            }
        }

        // static void println(const ArrayList<Object>& arr) {
        //     std::cout << "[ ";
        //     for(usize i = 0; i < arr.size(); i++) {
        //         if(i < arr.size() - 1) {
        //             std::cout << arr[i] << ", ";
        //         } else {
        //             std::cout << arr[i] << " ]";
        //         }
        //     }
        // }

        // template <typename Type>
        // static void println(const ArrayList<Type>& arr) {
        //     std::cout << "[ ";
        //     for(usize i = 0; i < arr.size(); i++) {
        //         if(i < arr.size() - 1) {
        //             std::cout << arr[i] << ", ";
        //         } else {
        //             std::cout << arr[i] << " ]";
        //         }
        //     }
        // }

        template <typename Type>
        static void println(const LinkedList<Type>& list) {
            std::cout << "[ ";
            for(LinkedList<int>::Iterator it = list.begin(); it != list.end(); it++) {
                if(it != list.begin()) {
                    std::cout << ", ";
                }
                std::cout << *it;
            }

            std::cout << " ]";
        }

        template <typename Type, usize size>
        static void println(const Type(&array)[size]) {
            if(jamstl::type_traits::isSame<Type, char>::value ||
             jamstl::type_traits::isSame<Type, unsigned char>::value) {
                std::cout << array;
            } else {std::cout << "[ ";
                for(usize i = 0; i < size; i++) {
                    if(i < size - 1) {
                        std::cout << array[i] << ", ";
                    } else {
                        std::cout << array[i] << " ]";
                    }
                }
            }
        }



        static void flush() {
            std::cout.flush();
        }

        static void clear() {
            std::cout.clear();
        }

    } printer;
    
JAMSTL_NAMESPACE_END

#endif