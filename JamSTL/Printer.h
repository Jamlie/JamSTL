#pragma once

#ifndef JAMSTL_PRINTER_H
#define JAMSTL_PRINTER_H 1

#include <ostream>
#include "Datatypes.h"
#include "Collections/ArrayList.h"
#include "Macros.h"
#include "Collections/Array.h"
#include "Collections/LinkedList.h"
#include "String/StringHelper.h"
#include "./GarbageCollector/GarbageCollector.h"
#include "Object.h"
#undef println

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
            for(let it = list.begin(); it != list.end(); it++) {
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
            } else {std::cout << "[";
                for(usize i = 0; i < size; i++) {
                    if(i < size - 1) {
                        std::cout << array[i] << ", ";
                    } else {
                        std::cout << array[i] << "]";
                    }
                }
            }
        }


        // static void println() {
        //     std::cout << '\n';
        // }

        template <typename... Types>
        static void println(StringView str, const unsigned char& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const char& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const unsigned short& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const short& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const unsigned& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const int& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const unsigned long& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const long& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const unsigned long long& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const long long& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const float& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const double& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename... Types>
        static void println(StringView str, const char*& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value, values...);
            std::cout << string << '\n';
        }

        template <typename Type, typename... Types>
        static void println(StringView str, const Type& value, Types... values) {
            String strCopy = str;
            String string = strCopy.format(value.valueOf(), values...);
            std::cout << string << '\n';
        }


        static void println() {
            std::cout << '\n';
        }

        static void println(Object& obj) {
            std::cout << obj << '\n';
        }

        static void println(const byte& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const char& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const unsigned int& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const int& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const unsigned long& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const long& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const unsigned long long& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const long long& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const float& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const double& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const long double& value) {
            std::cout << value << ' ';
            println();
        }

        static void println(const bool& boolean) {
            if(boolean) {
                std::cout << "true\n";
                return;
            }
            std::cout << "false\n";
        }

        template<typename Type>
        static void println(const Type& value) {
            String str = String::valueOf(value);
            std::cout << str << ' ';
            println();
        }

        template<typename Type>
        static void println(const Type* value) {
            String str = String::valueOf(value);
            std::cout << str << ' ';
            println();
        }

        template<typename Type, usize size>
        static void println(const Array<Type, size>& arr) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << arr[i] << ", ";
                } else {
                    std::cout << arr[i] << "]";
                }
            }
        }

        template <typename Type>
        static void println(const ArrayList<Type>& arr) {
            std::cout << "[";
            for(usize i = 0; i < arr.size(); i++) {
                if(i < arr.size() - 1) {
                    std::cout << arr[i] << ", ";
                } else {
                    std::cout << arr[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template<class T>
        static void println(const ArrayList<Reference<T>>& arr) {
            std::cout << "[";
            for(usize i = 0; i < arr.size(); i++) {
                if(i < arr.size() - 1) {
                    std::cout << *(arr[i]) << ", ";
                } else {
                    std::cout << *(arr[i]) << "]";
                }
            }
            std::cout << '\n';
        }

        template <typename Type>
        static void println(const LinkedList<Type>& list) {
            std::cout << "[";
            for(let it = list.begin(); it != list.end(); it++) {
                if(it != list.begin()) {
                    std::cout << ", ";
                }
                std::cout << *it;
            }

            std::cout << "]";
        }

        static void println(const char* array) {
            std::cout << array << '\n';
        }

        template <usize size>
        static void println(const int(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const unsigned int(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const unsigned short(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const short(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const unsigned long(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const long(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const unsigned long long(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const long long(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const float(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const double(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const long double(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const byte(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <usize size>
        static void println(const char(&array)[size]) {
            // array[size + 1] = '\0';
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i] << ", ";
                } else {
                    std::cout << array[i] << "]";
                }
            }
            std::cout << '\n';
        }

        template <typename Type, usize size>
        static void println(const Type(&array)[size]) {
            std::cout << "[";
            for(usize i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << array[i].valueOf() << ", ";
                } else {
                    std::cout << array[i].valueOf() << "]";
                }
            }
            std::cout << '\n';
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