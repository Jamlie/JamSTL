#pragma once

// ! Omar Estietie

#ifndef JAMSTL_QUEUE_H
#define JAMSTL_QUEUE_H 1
#include <iostream>
#include "../type_traits.h"
#include "../Datatypes.h"
#include "../Macros.h"

JAMSTL_NAMESPACE_BEGIN
    template <typename T>
    class Queue {
    private:
        T* queue = nullptr;
        size_t Size = 0;
        size_t capacity = 0;

        /**
         * @brief A method to reallocate the memory
         * 
         * @param newCapacity 
         */
        void reAllocate(size_t newCapacity) {
            T* newBlock = new T[newCapacity];

            if(newCapacity < Size) Size = newCapacity;

            for (size_t i = 0; i < Size; i++) queue[i] 
                                    = jamstl::type_traits::move(queue[i]);

            ::operator delete(queue, newCapacity * sizeof(T));
            queue = newBlock;
            capacity = newCapacity;
        }

        void heapify(T QUEUE[], size_t SIZE, size_t index) {
            size_t largest = index; 
            size_t member = 2 * index + 1; 
            size_t other_member = 2 * index + 2; 
            
            if (member < SIZE && QUEUE[member] > QUEUE[largest])
                largest = member;

            if (other_member < SIZE && QUEUE[other_member] > QUEUE[largest])
                largest = other_member;

            if (largest != index) {
                std::swap(QUEUE[index], QUEUE[largest]);

                heapify(QUEUE, SIZE, largest);
            }
        }

    public:
        Queue() { reAllocate(2); }

        ~Queue() { ::operator delete(queue, capacity * sizeof(T)); }

        /**
         * @brief A method that adds a value to the end of a queue
         * 
         * @param value 
         */
        void push(const T& value) {
            if(Size > capacity) reAllocate(capacity + capacity / 2);

            queue[Size] = value;
            Size++;
        }

        /**
         * @brief A method that adds a value to the end of a queue
         * 
         * @param value 
         */
        void push(T&& value) {
            if(Size > capacity) reAllocate(capacity + capacity / 2);

            queue[Size] = move(value);
            Size++;       
        }

        /**
         * @brief A method that removes the first a queue
         * 
         */
        void pop() {
            this->reverse();
            if(Size > 0) {
                Size--;
                queue[Size].~T();
            }
            this->reverse();
        }

        /**
         * @brief A method that makes a queue empty
         * 
         * @return bool
         */
        bool empty() {
            for (size_t i = 0; i < Size; i++) queue[i].~T();

            Size = 0;
            return true;
        }

        /**
         * @brief A method that checks if a queue is empty
         * 
         * @return bool
         */
        bool is_empty() {
            if(Size != 0) return 0;
            return 1;
        }

        /**
         * @brief A method that returns the first value of a queue
         * 
         * @return T 
         */
        T front() { return queue[0]; }

        /**
         * @brief A method that returns the last value of a queue
         * 
         * @return T 
         */
        T back() { return queue[Size - 1]; }

        /**
         * @brief A method that returns the size of a queue
         * 
         * @return size_t 
         */
        size_t size() const { return Size; }

        /**
         * @brief A method to reverse a queue
         * 
         */
        void reverse() {
            T temp;

            for(size_t i = 0; i < Size / 2; i++){
                temp = queue[i];
                queue[i] = queue[Size-i-1];
                queue[Size-i-1] = temp;
            }
        }

        /**
         * @brief A method to print a queue
         * 
         */
        void print() {
            if(!(is_empty())) {
                std::cout << "[ ";
                for(size_t i = 0; i < size(); i++) {
                    if(i == size() - 1) std::cout << queue[i];
                    if(i != size() - 1) std::cout << queue[i] << ", ";
                }
                std::cout << " ]" << '\n';
            }
            else std::cout << "[]";
        }

        /**
         * @brief A method to sort a queue
         * 
         */
        void sort() {
            for (int i = Size / 2 - 1; i >= 0; i--) heapify(queue, Size, i);

            for (int i = Size - 1; i > 0; i--) {
                std::swap(queue[0], queue[i]);

                heapify(queue, i, 0);
            }
        }

        /**
         * @brief A method that checks if a queue is sorted
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
         * @brief An emplace method
         * 
         * @tparam Arguments 
         * @param ARGS 
         * @return T& 
         */
        template <typename... Arguments>
        T& emplace(Arguments&&... ARGS) {
            if (Size >= capacity) reAllocate(capacity + capacity / 2);

            new(&queue[Size]) T(std::forward<Arguments>(ARGS)...);
            return queue[Size++];
        }

        T at(size_t index) const { 
            if(index > this->size()) return 0;
            return queue[index]; 
        }
    };

JAMSTL_NAMESPACE_END
#endif