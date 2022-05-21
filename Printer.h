#pragma once

#include <ostream>

#ifndef _PRINTER_H
#define _PRINTER_H

#include "../Datatypes/Datatypes.h"
#include <array>
#include <vector>

class Printer {
public:
    Printer() = default;

    void print() {
        std::cout << '\n';
    }

    template<typename Type, typename... Types>
    void print(Type& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    template<typename Type, size_t size, typename... Types>
    void print(std::array<Type, size> arr, Types... values) {
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

    template<typename Type, typename... Types>
    void print(std::vector<Type> arr, Types... values) {
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

    template<typename Type, size_t size, typename... Types>
    void print(const Type (&array)[size] , Types... values) {
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
    void print(StringView str, Types... values) {
        std::cout << str << ' ';
        print(values...);
    }

    template<typename... Types>
    void print(const Integer& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    template<typename... Types>
    void print(const Double& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    template<typename... Types>
    void print(const Float& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    template<typename... Types>
    void print(const Boolean& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    template<typename... Types>
    void print(const Character& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    template<typename... Types>
    void print(const Long& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    template<typename... Types>
    void print(const Short& value, Types... values) {
        std::cout << value << ' ';
        print(values...);
    }

    
    Double hash(const String& value) {
        Double hash = 0;
        for (int i = 0; i < value.Length; i++) {
            hash += 10 * hash + value[i];
        }
        return hash;
    }

    void flush() {
        std::cout.flush();
    }

    void clear() {
        std::cout.clear();
    }
};

#endif
