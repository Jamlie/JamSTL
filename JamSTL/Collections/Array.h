#pragma once

#ifndef JAMSTL_ARRAY_H
#define JAMSTL_ARRAY_H

#include "../Macros.h"
#include "../Object.h"
#include "../String.h"
#include "../Iterator.h"
#include "../Exception/IndexOutOfBoundsException.h"
#include "../Exception/ArrayIndexOutOfBoundsException.h"
#include "../bits/TypeTraits.h"
#include <initializer_list>

JAMSTL_NAMESPACE_BEGIN
    template<typename Type, usize Size = 10>
    class Array extends Object {
    private:
        Type array[Size];

        void heapify(Type arr[], usize arrSize, usize index) {
            usize largest = index;
            usize left = 2 * index + 1;
            usize right = 2 * index + 2;

            if (left < arrSize && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < arrSize && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != index) {
                Type temp = arr[index];
                arr[index] = arr[largest];
                arr[largest] = temp;

                heapify(arr, arrSize, largest);
            }
        }

    public:
        Array() {
            for (usize i = 0; i < Size; i++) {
                array[i] = Type();
            }
        }

        Array(std::initializer_list<Type> list) {
            if(list.size() > Size) {
                throw ArrayIndexOutOfBoundsException("Index out of bounds");
            }
            usize i = 0;
            for(auto& element : list) {
                array[i++] = element;
            }
            if(i != this->size()) {
                for (usize j = i; j < Size; j++) {

                }
            }
        }


        Array(const Array& other) {
            for (usize i = 0; i < Size; i++) {
                array[i] = other.array[i];
            }
        }

        Array(Array&& other) {
            for (usize i = 0; i < Size; i++) {
                array[i] = other.array[i];
            }
        }

        Array& operator=(const Array& other) {
            for (usize i = 0; i < Size; i++) {
                array[i] = other.array[i];
            }
            return *this;
        }

        Array& operator=(Array&& other) {
            for (usize i = 0; i < Size; i++) {
                array[i] = other.array[i];
            }
            return *this;
        }

        constexpr usize size() const {
            return Size;
        }

        Type& operator[](usize index) {
            if (index >= Size) {
                throw IndexOutOfBoundsException("Index out of bounds");
            }
            return array[index];
        }

        const Type& operator[](usize index) const {
            if (index >= Size) {
                throw IndexOutOfBoundsException("Index out of bounds");
            }
            return array[index];
        }

        void sort() {
            for (usize i = Size / 2 - 1; i >= 0; i--) {
                heapify(array, Size, i);
            }

            for (usize i = Size - 1; i >= 0; i--) {
                Type temp = array[0];
                array[0] = array[i];
                array[i] = temp;

                heapify(array, i, 0);
            }
        }

        Type* data() {
            return array;
        }

        String valueOf() const {
            String str = "[";
            for (usize i = 0; i < Size; i++) {
                str += String::valueOf(array[i]);
                if (i != Size - 1) {
                    str += ", ";
                }
            }
            str += "]";
            return str;
        }

        class iterator extends Iterator<ForwardIteratorTag, Type> {
        private:
            Type* ptr;
        public:
            iterator(Type* ptr) : ptr(ptr) {}

            iterator& operator++() {
                ptr++;
                return *this;
            }

            iterator operator++(int) {
                iterator temp = *this;
                ptr++;
                return temp;
            }

            Type& operator*() {
                return *ptr;
            }

            bool operator==(const iterator& other) const {
                return ptr == other.ptr;
            }

            bool operator!=(const iterator& other) const {
                return ptr != other.ptr;
            }

            Type* operator->() {
                return ptr;
            }

            iterator& operator=(const iterator& other) {
                ptr = other.ptr;
                return *this;
            }

            iterator& operator=(iterator&& other) {
                ptr = other.ptr;
                return *this;
            }

            iterator(const iterator& other) {
                ptr = other.ptr;
            }

            iterator(iterator&& other) {
                ptr = other.ptr;
            }

            ~iterator() {}
        }; 

        iterator begin() {
            return iterator(array);
        }

        iterator end() {
            return iterator(array + Size);
        }

    };

JAMSTL_NAMESPACE_END

#endif