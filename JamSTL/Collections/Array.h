#pragma once

#ifndef JAMSTL_ARRAY_H
#define JAMSTL_ARRAY_H 1

#include "../Datatypes.h"
#include "../Macros.h"
#include <initializer_list>

JAMSTL_NAMESPACE_BEGIN
    template<typename Type, size_t Size>
    class Array {
    private:
        Type array[Size];

        void heapify(size_t index) {
            size_t left = index * 2 + 1;
            size_t right = index * 2 + 2;
            size_t largest = index;

            if (left < Size && array[left] > array[largest]) {
                largest = left;
            }

            if (right < Size && array[right] > array[largest]) {
                largest = right;
            }

            if (largest != index) {
                Type temp = array[index];
                array[index] = array[largest];
                array[largest] = temp;
                heapify(largest);
            }
        }

        constexpr void setTempValue() {
            for (size_t i = 0; i < Size; i++) {
                array[i] = 0;
            }
        }

    public:
        Array() 
        {
            setTempValue();
        }

        Array(std::initializer_list<Type> list) {
            size_t i = 0;
            for (auto it = list.begin(); it != list.end(); it++) {
                array[i] = *it;
                i++;
            }
        }

        constexpr size_t size() const {
            return Size;
        }

        Type& operator[](size_t index) {
            return array[index];
        }

        const Type& operator[](size_t index) const {
            return array[index];
        }

        void sort() {
            for (size_t i = size() / 2; i >= 0; i--) {
                heapify(i);
            }

            for (size_t i = size() - 1; i > 0; i--) {
                Type temp = array[0];
                array[0] = array[i];
                array[i] = temp;
                heapify(0);
            }
        }

        Type* Data() {
            return array;
        }
    };
JAMSTL_NAMESPACE_END

#endif