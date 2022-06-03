#pragma once

#include <ostream>
#include <stdarg.h>

#ifndef JAMSTL_PRINTER_H
#define JAMSTL_PRINTER_H

#include "Datatypes.h"
#include "ArrayList.h"
#include "Macros.h"
#include "Array.h"
#include "LinkedList.h"
#include "String.h"

JAMSTL_NAMESPACE_BEGIN

    class Printer {
    public:
        Printer() = default;

        static void print()
        {
            std::cout << '\n';
        }

        template <typename Type, typename... Types>
        static void print(const Type& value, Types... values)
        {
            std::cout << value << ' ';
            print(values...);
        }

        template<typename Type, size_t size, typename... Types>
        static void print(const Array<Type, size>& arr, Types... values) {
            std::cout << "[ ";
            for(size_t i = 0; i < size; i++) {
                if(i < size - 1) {
                    std::cout << arr[i] << ", ";
                } else {
                    std::cout << arr[i] << " ]" << ' ';
                }
            }
            print(values...);
        }

        template <typename Type, typename... Types>
        static void print(const ArrayList<Type>& arr, Types... values)
        {
            std::cout << "[ ";
            for(size_t i = 0; i < arr.size(); i++) {
                if(i < arr.size() - 1) {
                    std::cout << arr[i] << ", ";
                } else {
                    std::cout << arr[i] << " ]" << ' ';
                }
            }
            print(values...);
        }

        template <typename Type, typename... Types>
        static void print(const LinkedList<Type>& list, Types... values)
        {
            std::cout << "[ ";
            for (LinkedList<int>::Iterator it = list.begin(); it != list.end(); it++)
            {
                if(it != list.begin()) {
                    std::cout << ", ";
                }
                std::cout << *it;
            }

            std::cout << " ]" << ' ';
            print(values...);
        }

        template <typename Type, size_t size, typename... Types>
        static void print(const Type (&array)[size], Types... values)
        {
            if(std::is_same<Type, char>::value) {
                std::cout << array << ' ';
            } else {std::cout << "[ ";
                for(size_t i = 0; i < size; i++) {
                    if(i < size - 1) {
                        std::cout << array[i] << ", ";
                    } else {
                        std::cout << array[i] << " ]" << ' ';
                    }
                }
            }
            print(values...);
        }

        template<typename... Types>
        static void print(StringView str, Types... values) {
            std::cout << str << ' ';
            print(values...);
        }

        template <typename... Types>
        static void print(const Integer& value, Types... values) {
            std::cout << value << ' ';
            print(values...);
        }

        template <typename... Types>
        static void print(const Double& value, Types... values) {
            std::cout << value << ' ';
            print(values...);
        }

        template <typename... Types>
        static void print(const Float& value, Types... values) {
            std::cout << value << ' ';
            print(values...);
        }

        template <typename... Types>
        static void print(const Boolean& value, Types... values) {
            std::cout << value << ' ';
            print(values...);
        }

        template <typename... Types>
        static void print(const Character& value, Types... values) {
            std::cout << value << ' ';
            print(values...);
        }

        template <typename... Types>
        static void print(const Long& value, Types... values) {
            std::cout << value << ' ';
            print(values...);
        }

        template <typename... Types>
        static void print(const Short& value, Types... values) {
            std::cout << value << ' ';
            print(values...);
        }

        static void println() {
            std::cout << '\n';
        }

        static void println(StringView string) {
            for(auto& c : string) {
                std::cout << c;
            }
        }

        template<typename Type, typename... Types>
        static void println(const Type& value, Types... values) {
            std::cout << value << ' ';
            println(values...);
        }

        static void printf(const char *format, ...) {
            va_list args;
            va_start(args, format);
            vprintf(format, args);
            va_end(args);
        }

        static void fmt(String str, String word) {
            str.replace("{}"_s, word);
            std::cout << str;
        }



        static Double hash(const String& value) {
            Double hash = 0;
            for (int i = 0; i < value.Length; i++) {
                hash += 10 * hash + value[i];
            }
            return hash;
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