#pragma once

// ! Omar Estietie

#ifndef JAMSTL_STACK_H
#define JAMSTL_STACK_H 1
#include <iostream>
#include "../Datatypes.h"
#include "../type_traits.h"
#include "../Macros.h"

JAMSTL_NAMESPACE_BEGIN
    template<typename T>
    class Stack {
    private:
        T* stack = nullptr;
        size_t Size = 0;
        size_t Capacity = 0;

        /**
         * @brief A method to reallocate the memory
         * 
         * @param newCapacity 
         */
        void reAllocate(size_t newCapacity) {
            T* newBlock = new T[newCapacity];

            if (newCapacity < Size) Size = newCapacity;

            for (size_t i = 0; i < Size; i++) newBlock[i] = 
                                        jamstl::type_traits::move(stack[i]);

            ::operator delete(stack, newCapacity * sizeof(T));
            stack = newBlock;
            Capacity = newCapacity;
        }

    public:
        Stack() {
            reAllocate(2);
        }

        ~Stack() { ::operator delete(stack, Capacity * sizeof(T)); }

        /**
         * @brief A push method to enter elements into the list to the end of it
         * 
         * @param VALUE The value
         */
        void push(const T& value) {
            if (Size > Capacity) reAllocate(Capacity + Capacity / 2);

            stack[Size] = value;
            Size++;
        }

        /**
         * @brief A push method to enter elements into the list to the end of it
         * 
         * @param VALUE The value
         */
        void push(T&& value) {

            if (Size >= Capacity) reAllocate(Capacity + Capacity / 2);
            

            stack[Size] = move(value);
            Size++;
        }

        /**
         * @brief A pop method to remove the last element of a list
         */
        void pop() {
            if (Size > 0) {
                Size--;
                stack[Size].~T();
            }
        }

        /**
         * @brief Returns the last value of the stack
         * 
         * @return T 
         */
        T top() {
            return stack[Size - 1];
        }

        /**
         * @brief An empty method to make a list empty
         * 
         * @return bool
         */
        bool empty() {
            for (size_t i = 0; i < Size; i++) stack[i].~T();

            Size = 0;
            return true;
        }

        /**
         * @brief A method that determines if a list is empty and returns true or false
         * 
         * @return bool
         */
        bool is_empty() {
            if(Size != 0) return 0;
            return 1;
        }

        /**
         * @brief A method to return the size of the list
         * 
         * @return size_t 
         */
        size_t size() { return Size; }

        /**
         * @brief A method that checks if a stack is sorted
         * 
         * @return bool
         */
        bool is_sorted() {
            if(this->size() == 0) return false;
            if(this->size() == 1) return true;

            for(size_t i = 1; i < this->size(); i++) if(this->queue[i - 1] > this->queue[i]) return false;

            return true;
        }

        /**
         * @brief A method that reverses a list
         */
        void reverse() {
            T temp;

            for(size_t i = 0; i < Size / 2; i++){
                temp = stack[i];
                stack[i] = stack[Size-i-1];
                stack[Size-i-1] = temp;
            }
        }

        /**
         * @brief A method that assigns a stack with a given value to a given index
         * 
         * @param indecies The index
         * @param any The value
         */
        void assign(size_t indecies, T any) {
            for(size_t i = 0; i < indecies; i++) {
                push(any);
            }
        }

        /**
         * @brief An emplace method
         * 
         * @tparam Arguments 
         * @param ARGS 
         * @return T& 
         */
        template <typename... Arguments>
        T& emplace(Arguments&&... ARGS) {
            if (Size >= Capacity) reAllocate(Capacity + Capacity / 2);

            new(&stack[Size]) T(std::forward<Arguments>(ARGS)...);
            return stack[Size++];
        }

        // class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
        // private:
        //     T* ptr;
        //     size_t index;
        //     size_t size;
        // public:
        //     Iterator(T* ptr, size_t index, size_t size) : ptr(ptr), index(index), size(size) {}

        //     Iterator(const Iterator& other) : ptr(other.ptr), index(other.index), size(other.size) {}

        //     Iterator& operator++() {
        //         index++;
        //         return *this;
        //     }

        //     Iterator& operator--() {
        //         index--;
        //         return *this;
        //     }

        //     Iterator& operator+=(size_t n) {
        //         index += n;
        //         return *this;
        //     }

        //     Iterator& operator-=(size_t n) {
        //         index -= n;
        //         return *this;
        //     }

        //     Iterator& operator+(size_t n) {
        //         index += n;
        //         return *this;
        //     }

        //     Iterator& operator-(size_t n) {
        //         index -= n;
        //         return *this;
        //     }

        //     T& operator*() {
        //         return ptr[index];
        //     }

        //     bool operator==(const Iterator& other) {
        //         return ptr == other.ptr && index == other.index;
        //     }

        //     bool operator!=(const Iterator& other) {
        //         return ptr != other.ptr || index != other.index;
        //     }

        //     bool operator<(const Iterator& other) {
        //         return index < other.index;
        //     }

        //     bool operator>(const Iterator& other) {
        //         return index > other.index;
        //     }

        //     bool operator<=(const Iterator& other) {
        //         return index <= other.index;
        //     }

        //     bool operator>=(const Iterator& other) {
        //         return index >= other.index;
        //     }

        //     size_t operator-(const Iterator& other) {
        //         return index - other.index;
        //     }

        //     T& operator[](size_t n) {
        //         return ptr[index + n];
        //     }

        //     Iterator operator+(size_t n) {
        //         return Iterator(ptr, index + n, size);
        //     }

        //     Iterator operator-(size_t n) {
        //         return Iterator(ptr, index - n, size);
        //     }

        //     Iterator operator++(int) {
        //         Iterator temp = *this;
        //         index++;
        //         return temp;
        //     }

        //     Iterator operator--(int) {
        //         Iterator temp = *this;
        //         index--;
        //         return temp;
        //     }
        // };

        // Iterator begin() {
        //     return Iterator(stack, 0, Size);
        // }

        // Iterator end() {
        //     return Iterator(stack, Size, Size);
        // }
    };
JAMSTL_NAMESPACE_END


#endif