#pragma once

/**
 * @file ArrayList.h part of JamSTL namespace
 * 
 * @author Omar Estietie (jamlee977@outlook.com), (@OmarEstietie on Twitter)
 * @brief It is a data structure that is used to store a collection of data. 
 * It is a dynamic data structure that can be resized as needed. 
 * It is a linear data structure. It is a collection of data that is indexed by a number. 
 * It works like a vector but it has much more methods and features taken from other languages like Javascript, Python and Java.
 * @version 1.0
 * @since 2020-05-09
 * @date 2022-06-04
 */

// ! Omar Estietie

#ifndef JAMSTL_ArrayList_H
#define JAMSTL_ArrayList_H
#include <initializer_list>
#include <functional>
#include "../Iterator.h"
#include "../TypeTraits.h"
#include "../Macros.h"
#include "../Math.h"
#include "../Object.h"
#include "../Exception/IndexOutOfBoundsException.h"
#include "../IO/PrintStream.h"
#include "../Random.h"
#include "Array.h"

JAMSTL_NAMESPACE_BEGIN
    template<typename T>
    class ArrayList extends Object {
    private:
        T* arrayList = nullptr;

        usize Size = 0;
        usize Capacity = 0;

        /**
         * @brief A method to reallocate the memory
         * 
         * @param newCapacity 
         */
        void reAllocate(usize newCapacity) {
            #ifdef _WIN32

            T* newBlock = new T[newCapacity];
            
            if (newCapacity < this->Size) this->Size = newCapacity;

            for (usize i = 0; i < this->Size; i++) 
                newBlock[i] = jamstl::TypeTraits::move(this->arrayList[i]);

            for(usize i = 0; i < this->Size; i++) this->arrayList[i].~T();

            ::operator delete(this->arrayList, newCapacity * sizeof(T));
            this->arrayList = newBlock;
            this->Capacity = newCapacity;
            
            #else

            T* newArray = new T[newCapacity];
            for (usize i = 0; i < this->size(); i++) {
                newArray[i] = arrayList[i];
            }
            delete[] arrayList;
            arrayList = newArray;
            Capacity = newCapacity;
            
            #endif
        }

        /**
         * @brief A heapify method
         * 
         * @param arrayList 
         * @param Size 
         * @param index 
         */
        void heapify(T arrayList[], usize Size, usize index) {
            usize largest = index; 
            usize member = 2 * index + 1; 
            usize other_member = 2 * index + 2; 
            
            if (member < Size && arrayList[member] > arrayList[largest])
                largest = member;
        
            if (other_member < Size && arrayList[other_member] > arrayList[largest])
                largest = other_member;
        
            if (largest != index) {
                jamstl::swap(arrayList[index], arrayList[largest]);
        
                heapify(arrayList, Size, largest);
            }
        }

    public:

        ArrayList() { this->reAllocate(2); }

        template<usize sizeOfArray>
        ArrayList(const T(&array)[sizeOfArray]) {
            this->reAllocate(2);
            for (usize i = 0; i < sizeOfArray; i++) this->push(array[i]);
        }

        ArrayList(T* arr, usize sizeOfArray) {
            this->reAllocate(2);
            for (usize i = 0; i < sizeOfArray; i++) this->push(arr[i]);
        }

        template<usize sizeOfArray>
        ArrayList(const Array<T, sizeOfArray>& array) {
            this->reserve(sizeOfArray);
            for (usize i = 0; i < sizeOfArray; i++) this->push(array[i]);
        }

        ArrayList(std::initializer_list<T> arrayList) {
            this->reAllocate(2);
            for(const auto& element : arrayList) {
                this->push(element);
            }
        }

        ArrayList(const ArrayList<T>& arrayList) {
            this->reAllocate(2);
            for (usize i = 0; i < arrayList.Size; i++) this->push(arrayList[i]);
        }

        ArrayList(ArrayList<T>&& arrayList) {
            this->reAllocate(2);
            for (usize i = 0; i < arrayList.Size; i++) this->push(arrayList[i]);
        }

        ArrayList(usize num) { this->reAllocate(num); }

        ~ArrayList() { 
            #ifdef _WIN32 
            ::operator delete(this->arrayList, this->Capacity * sizeof(T)); 
            #else
            delete[] this->arrayList;
            #endif
        }

        // reserve
        void reserve(usize number) {
            if (number > this->Capacity) this->reAllocate(number);
        }

        /**
         * @brief A push method to enter elements into the ArrayList to the end of it
         * 
         * @param value The value
         */
        usize push(const T& value) {
            if (this->Size >= this->Capacity) 
                this->reAllocate(this->Capacity + this->Capacity / 2);
            

            this->arrayList[this->Size] = value;
            this->Size++;

            return this->size();
        }

        /**
         * @brief A push method to enter elements into the ArrayList to the end of it
         * 
         * @param value The value
         */
        usize push(T&& value) {

            if (this->Size >= this->Capacity) 
                this->reAllocate(this->Capacity + this->Capacity / 2);

            this->arrayList[this->Size] = jamstl::TypeTraits::move(value);
            this->Size++;

            return this->size();
        }

        /**
         * @brief A pop method to remove the last element of an ArrayList
         */
        T pop() {
            T value = this->arrayList[this->size() - 1];
            if(this->Size > 0) {
                this->Size--;
                this->arrayList[this->Size].~T();
            }
            return value;
        }

        /**
         * @brief A function that removes a specific index from an ArrayList
         * 
         * @param indecies 
         * @return bool
         */
        T pop(usize index) {
            if(index > this->size() || (index + 1) > this->size()) 
                return this->arrayList[this->size()];
            if(index == this->size()) {
                this->pop();
                return this->arrayList[this->size() - 1];
            }

            auto value = this->arrayList[index];
            usize newSize = this->size() - 1;
            T* temp = new T[newSize];

            for(usize i = 0, j = 0; i < this->size() - 1; i++, j++) {
                if(j == index) {
                    i--;
                    continue;
                }
                temp[i] = this->arrayList[j];
            }

            this->empty();
            for(usize i = 0; i < newSize; i++) {
                this->push(temp[i]);
            }

            delete[] temp;
            return value;
        }

        /**
         * @brief An empty method to make an ArrayList empty
         * 
         * @return bool
         */
        bool empty() {
            for (usize i = 0; i < this->Size; i++) this->arrayList[i].~T();

            this->Size = 0;
            return true;
        }

        /**
         * @brief A method that determines if an ArrayList is empty and returns true or false
         * 
         * @return bool
         */
        bool isEmpty() {
            return this->Size == 0;
        }

        /**
         * @brief An emplace method
         * 
         * @tparam Arguments 
         * @param args 
         * @return T& 
         */
        template<typename... Arguments>
        T& emplace(Arguments&&... args) {
            if (this->Size >= this->Capacity) 
                this->reAllocate(this->Capacity + this->Capacity / 2);

            this->arrayList[this->Size] = T(jamstl::TypeTraits::forward<Arguments>(args)...);
            this->Size++;

            return this->arrayList[this->Size - 1];
        }

        
        template<typename... Arguments>
        T& emplace(std::initializer_list<T> list, Arguments&&... args) {
            if (this->Size >= this->Capacity) 
                this->reAllocate(this->Capacity + this->Capacity / 2);

            this->arrayList[this->Size] = T(list, jamstl::TypeTraits::forward<Arguments>(args)...);
            this->Size++;

            return this->arrayList[this->Size - 1];         
        }


        T& operator[](int index) {
            if(index >= 0) return this->arrayList[index];
            index = index + 1;
            int temp = (this->size() + index);
            return this->arrayList[temp - 1];
        }
        
        const T& operator[](int index) const { 
            if(index >= 0) return this->arrayList[index];
            index = index + 1;
            int temp = (this->size() + index);
            return this->arrayList[temp - 1];     
        }

        /**
         * @brief A method to return the size of the list
         * 
         * @return usize 
         */
        usize size() const { return this->Size; }

        /**
         * @brief A method to return the capacity of the list
         * 
         * @return usize 
         */
        usize capacity() const { return this->Capacity; }

        /**
         * @brief A method that returns the value of the given index
         * 
         * @param index The index
         * @return T 
         */
        T at(usize index) const {
            return this->arrayList[index];
        }

        /**
         * @brief A method that fills an ArrayList with a given value
         * 
         * @param value The value that you want to fill
         * @param start The start
         * @param end The end
         * @return bool
         */
        bool fill(T value, usize start, usize end) {
            if (start > end) return 0;
            for (usize i = start; i < end; i++) this->arrayList[i] = value;
            return 1;
        }

        /**
         * @brief A method used to find a given value in an ArrayList
         * 
         * @param any The value
         * @return bool 
         */
        bool find(T any) {
            for(usize i = 0; i < this->Size; i++) if(this->arrayList[i] == any) return true;
            return false;
        }

        /**
         * @brief A method that reverses a list
         * 
         * @return ArrayList&
         */
        ArrayList& reverse() {
            T temp;

            for(usize i = 0; i < this->Size / 2; i++){
                temp = this->arrayList[i];
                this->arrayList[i] = this->arrayList[this->Size - i - 1];
                this->arrayList[this->Size - i - 1] = temp;
            }
            return *this;
        }
        
        ArrayList& addAll(std::initializer_list<T> list) {
            for(auto& i : list) this->push(i);
            return *this;
        }

        /**
         * @brief A method that returns the first value of the ArrayList
         * 
         * @return T 
         */
        T front() { return this->arrayList[0]; }

        /**
         * @brief A method that returns the last value of the ArrayList
         * 
         * @return T 
         */
        T back() { return this->arrayList[Size - 1]; }

        /**
         * @brief A method that returns the first value of the ArrayList
         * 
         * @return usize
         */ 
        usize first() { return 0; }

        /**
         * @brief A method that returns the last value of the ArrayList
         * 
         * @return usize 
         */
        usize last() { return this->size() - 1; }


        /**
         * @brief A method that assigns an ArrayList with a given value to a given index
         * 
         * @param indecies The index
         * @param any The value
         */
        void assign(usize indecies, T any) {
            for(usize i = 0; i < indecies; i++)
                this->push(any);
        } 

        /**
         * @brief A method that inserts a value to an index and moves the other indecies by 1
         * 
         * @param indecies The index you want the value to be in
         * @param any The value that you want to be entered
         * @return bool 
         */
        bool insert(usize index, T any) {
            if(index == this->size()) {
                push(any);
                return true;
            }
            if(index > this->size()) return false;
            if(index < 0) return false;
            usize newSize = this->size() + 1;
            T* temp = new T[newSize];

            for(usize i = 0, j = 0; i < newSize; i++, j++) {
                if(i == index) {
                    j--;
                    temp[i] = any;
                    continue;
                }
                temp[i] = this->arrayList[j];
            }
            
            empty();
            for(usize i = 0; i < newSize; i++) {
                this->push(temp[i]);
            }

            delete[] temp;
            return true;
        }

        /**
         * @brief A function that removes a specific value from an ArrayList
         * 
         * @param any 
         * @return bool
         */
        bool remove(T any) {
            usize newSize = this->size() - 1;
            T* temp = new T[newSize];

            usize Size = 0;
            usize count = 0;
            for(usize i = 0, j = 0; i < this->size() - 1; i++, j++) {
                if(count == 0 && this->arrayList[j] == any) {
                    i--;
                    count++;
                    continue;
                }
                
                temp[i] = this->arrayList[j];
                Size++;
            }

            this->empty();
            for(usize i = 0; i <= Size - 1; i++) {
                this->push(temp[i]);
            }

            delete[] temp;
            return true;
        }

        /**
         * @brief A function that removes all specific value from an ArrayList
         * 
         * @param any 
         * @return bool
         */
        bool removeAll(T any) {
            usize newSize = this->size() - 1;
            T* temp = new T[newSize];

            usize Size = 0;
            usize subOfSize = 0;
            for(usize i = 0, j = 0; i < this->size() - 1; j++) {
                if(this->arrayList[j] == any) {
                    subOfSize++;
                    continue;
                }
                temp[i] = this->arrayList[j];
                Size++;
                i++;
            }

            this->empty();
            for(usize i = 0; i <= Size - subOfSize; i++) {
                this->push(temp[i]);
            }

            delete[] temp;
            return true;
        }

        /**
         * @brief A method that exchanges all the values assigned in "old_value" with the "new_value"
         * 
         * @param new_value The new value
         * @param old_value The old value
         */
        void replace(T new_value, T old_value) {
            for (usize i = 0; i < this->size(); i++)
                if (this->arrayList[i] == old_value) this->arrayList[i] = new_value;
        }

        /**
         * @brief A method that exchanges the first value in "old_value" with the "new_value"
         * 
         * @param new_value The new value
         * @param old_value The old value
         */
        void quickReplace(T new_value, T old_value) {
            for (usize i = 0; i < this->size(); i++) {
                if (this->arrayList[i] == old_value) {
                    this->arrayList[i] = new_value;
                    break;
                }
            }
        }

        String toString() const {
            String str = "[";
            for(usize i = 0; i < this->size(); i++) {
                str += this->arrayList[i];
                if(i != this->size() - 1) str += ", ";
            }
            str += "]";
            return str;
        }

        String valueOf() const {
            String str = "[";
            for(usize i = 0; i < this->size(); i++) {
                str.append(this->arrayList[i]);
                if(i != this->size() - 1) str += ", ";
            }
            str += "]";
            return str;
        }


        /**
         * @brief A method that sorts an ArrayList
         */
        void sort() {
            for (int i = this->Size / 2 - 1; i >= 0; i--) heapify(this->arrayList, this->Size, i);

            for (int i = this->Size - 1; i > 0; i--) {
                jamstl::swap(this->arrayList[0], this->arrayList[i]);

                heapify(this->arrayList, i, 0);
            }
        }

        /**
         * @brief A method that checks if an ArrayList is sorted
         * 
         * @return bool
         */
        bool isSorted() {
            if(this->size() == 0) return false;
            if(this->size() == 1) return true;

            for(usize i = 1; i < this->size(); i++) if(this->arrayList[i - 1] > this->arrayList[i]) return false;

            return true;
        }

        /**
         * @brief A range class that can be used to assign an ArrayList of numbers.
         * 
         * @param number The starting of the range. 
         */ 
        bool range(usize number) {
            usize i;
            if(0 > number) return false;
            for (i = 0; i < number; i++) this->push(i);
            return true;
        }

        /**
         * @brief A range class that can be used to assign an ArrayList of numbers.
         * 
         * @param firstNumber The starting of the range.
         * @param lastNumber The ending of the range.
         * 
         */ 
        bool range(int firstNumber, int lastNumber) {
            int i;
            if(firstNumber > lastNumber) return false;
            for (i = firstNumber; i < lastNumber; i++) this->push(i);
            return true;
        }

        /**
         * @brief A range class that can be used to assign an ArrayList.
         * range(0, 21, 2) will assign the even numbers between 0 and 21 including 0
         * 
         * @param firstNumber The starting of the range.
         * @param lastNumber The ending of the range.
         * @param step The step for moving (start from 1).
         * 
         */
        bool range(int firstNumber, int lastNumber, usize step) {
            step = step - 1;
            int i;
            if(firstNumber > lastNumber) return false;
            for (i = firstNumber; i < lastNumber; i++) {
                this->push(i);
                i = i + step;
            }
            return true;
        }

        bool contains(T any) {
            for(usize i = 0; i < this->size(); i++) if(this->arrayList[i] == any) return true;
            return false;
        }

        /**
         * @brief This method can be used to filter out values using lambda function such as:
         * list.filter([](T any) { return any > 10; }); will output the values that are greater than 10 inside that list. 
         * list.filter([](const std::string& any) { return any.size() > 4; }); will output the values that are greater than 4 inside that list. 
         * 
         * @param condition 
         * @return ArrayList& 
         */
        ArrayList filter(const std::function<bool(const T& value)>& condition) {
            for(usize i = 0; i < this->size(); i++) {
                if(!condition(this->arrayList[i])) {
                    this->remove(this->arrayList[i]);
                    i--;
                }
            }
            return *this;
        }
        
        /**
         * @brief Calls an anonymous function on each element of an arraylist, and returns an arraylist that contains the results.
         * 
         * @param condition 
         * @return ArrayList& 
         */
        ArrayList& forEach(const std::function<void(T& value)>& condition) {
            for(usize i = 0; i < this->size(); i++) {
                condition(this->arrayList[i]);
            }
            return *this;
        }

        /**
         * @brief Calls an anonymous function on each element of an arraylist, and returns an arraylist that contains the results.
         * 
         * @param condition 
         * @return ArrayList& 
         */
        ArrayList map(const std::function<T(const T& value)>& condition) {
            for(usize i = 0; i < this->size(); i++) {
                this->arrayList[i] = condition(this->arrayList[i]);
            }
            return *this;
        }

        /**
         * @brief Calls an anonymous function on each element of an arraylist, and removes the elements that return true.
         * 
         * @param condition 
         * @return ArrayList& 
         */
        ArrayList& remove(const std::function<bool(const T& value)>& condition) {
            for(usize i = 0; i < this->size(); i++) {
                if(condition(this->arrayList[i])) {
                    this->remove(this->arrayList[i]);
                    i--;
                }
            }
            return *this;
        }

        /**
         * @brief Removes the first element from an array and returns it.
         * If the array is empty, undefined is returned and the arraylist is not modified.
         * 
         * @return T 
         */
        T shift() {
            if(this->size() == 0) return 0;
            T temp = this->arrayList[0];
            this->remove(this->arrayList[0]);
            return temp;
        }
        
        /**
         * @brief Returns a copy of a section of an arraylist.
         * For both start and end.
         * 
         * @return ArrayList& 
         */
        ArrayList& slice() {
            return *this;
        }

        /**
         * @brief Returns a copy of a section of an arraylist.
         * For both start and end.
         * @return ArrayList& 
         */
        ArrayList& slice(usize start) {
            if(start > this->size()) return *this;
            ArrayList<T> temp;
            for(usize i = start; i < this->size(); i++) {
                temp.push(this->arrayList[i]);
            }
            *this = temp;
            return *this;
        }

        /**
         * @brief Returns a copy of a section of an arraylist.
         * For both start and end.
         * 
         * @return ArrayList& 
         */
        ArrayList& slice(usize start, usize end) {
            if(start > end) return *this;
            if(start > this->size()) return *this;
            if(end > this->size()) end = this->size();

            ArrayList<T> temp;
            for(usize i = start; i < end; i++) {
                temp.push(this->arrayList[i]);
            }
            *this = temp;
            return *this;
        }

        /**
         * @brief Combines two or more arraylists.
         * 
         * @param other 
         * @return ArrayList 
         */
        ArrayList operator+(const ArrayList& other) {
            ArrayList<T> temp;
            for(usize i = 0; i < this->size(); i++) temp.push(this->arrayList[i]);
            for(usize i = 0; i < other.size(); i++) temp.push(other.arrayList[i]);
            return temp;
        }

        /**
         * @brief Combines two or more arraylists.
         * 
         * @param other 
         * @return ArrayList 
         */
        ArrayList operator+=(const ArrayList& other) {
            for(usize i = 0; i < other.size(); i++) this->push(other.arrayList[i]);
            return *this;
        }

        /**
         * @brief Removes an arraylist's elements from another arraylist.
         * 
         * @param other 
         * @return ArrayList 
         */
        ArrayList operator-(const ArrayList& other) {
            ArrayList<T> temp;
            for(usize i = 0; i < this->size(); i++) temp.push(this->arrayList[i]);
            for(usize i = 0; i < other.size(); i++) temp.remove(other.arrayList[i]);
            return temp;
        }

        /**
         * @brief Removes an arraylist's elements from another arraylist.
         * 
         * @param other 
         * @return ArrayList 
         */
        ArrayList operator-=(const ArrayList& other) {
            for(usize i = 0; i < other.size(); i++) this->remove(other.arrayList[i]);
            return *this;
        }

        /**
         * @brief Combines two arraylists.
         * 
         * @param other 
         * @return ArrayList 
         */
        ArrayList concat(const ArrayList<T>& other) {
            ArrayList<T> newList;
            for(usize i = 0; i < this->size(); i++) {
                newList.push(this->arrayList[i]);
            }
            for(usize i = 0; i < other.size(); i++) {
                newList.push(other.arrayList[i]);
            }
            return newList;
        }

        /**
         * @brief Removes a sub list from the list.
         * 
         * @param sublist 
         */
        void removeSublist(const ArrayList<T>& sublist) {
            for(usize i = 0; i < sublist.size(); i++) {
                this->remove(sublist.arrayList[i]);
            }
        }

        /**
         * @brief Determines whether all the members of an array satisfy the specified test.
         * 
         * @param condition 
         * @return bool
         */
        bool every(const std::function<bool(const T& value)>& condition) {
            for(int i = 0; i < this->size(); i++) {
                if(!condition(this->arrayList[i])) return false;
            }
            return true;
        }

        /**
         * @brief Determines whether the specified callback function returns true for any element of an array.
         * 
         * @param condition 
         * @return bool
         */
        bool some(const std::function<bool(const T& value)>& condition) {
            for(int i = 0; i < this->size(); i++) {
                if(condition(this->arrayList[i])) return true;
            }
            return false;
        }
        
        /**
         * @brief Returns the value of the first element in the array where predicate is true.
         * 
         * @param condition 
         * @return T 
         */
        T find(const std::function<bool(const T& value)>& condition) {
            for(int i = 0; i < this->size(); i++) {
                if(condition(this->arrayList[i])) return this->arrayList[i];
            }
            return T();
        }

        /**
         * @brief This method returns the index of an element specified in the third parameter.
         * 
         * @param start start of range
         * @param end end of range
         * @param value 
         * @return int 
         */
        int findIndex(usize start, usize end, const T& value) {
            for(int i = start; i < end; i++) {
                if(this->arrayList[i] == value) return i;
            }
            return -1;
        }

        /**
         * @brief Returns the index of the first element in the array where predicate is true, and -1 otherwise.
         * 
         * @param condition 
         * @return int 
         */
        int findIndex(const std::function<T(const T& value)>& condition) {
            for(int i = 0; i < this->size(); i++) {
                if(condition(this->arrayList[i])) return i;
            }
            return -1;
        }

        /**
         * @brief A method used to swap 2 elements in an ArrayList with indecies starting from 1 for the first index
         * 
         * @param firstIndex 
         * @param secondIndex 
         */
        void swap(usize firstIndex, usize secondIndex) {
            T temp = arrayList[firstIndex];
            arrayList[firstIndex] = arrayList[secondIndex];
            arrayList[secondIndex] = temp;
        }

        /**
         * @brief A method to swap all elements between 2 ArrayLists
         * 
         * @param other Another Arraylist to swap elements with
         * @return bool 
         */
        bool swap(ArrayList<T>& other) {
            usize sizeOfThis  = this->size();
            usize sizeOfOther = other.size();

            T* temp = new T[sizeOfThis];
            for(usize i = 0; i < sizeOfThis; i++) temp[i] = this->arrayList[i];
            this->empty();

            for(usize i = 0; i < sizeOfOther; i++) this->push(other.arrayList[i]);
            other.empty();
            for(usize i = 0; i < sizeOfThis; i++) other.push(temp[i]);

            delete[] temp;
            return true;
        }

        /**
         * @brief A methods that can be used to insert an ArrayList into an array that has a different size compared to the arraylist
         * 
         * @param Array 
         * @param size 
         */
        void toArray(T Array[], usize Size) {
            for(usize i = 0; i < Size; i++) { Array[i] = this->arrayList[i]; }
        }

        template<usize sizeOfArray>
        void toArray(T (&Array)[sizeOfArray]) {
            for(usize i = 0; i < sizeOfArray; i++) { Array[i] = this->arrayList[i]; }
        }

        template<usize sizeOfArray>
        void toArray(Array<T, sizeOfArray>& arr) {
            for(usize i = 0; i < sizeOfArray; i++) { arr[i] = this->arrayList[i]; }
        }


        /**
         * @brief A methods that can be used to insert an ArrayList into an array which has the same size as the arraylist
         * 
         * @param Array 
         */
        void toArray(T Array[]) {
            for(usize i = 0; i < size(); i++) { Array[i] = this->arrayList[i]; }
        }

        /**
         * @brief A methods that can be used to insert an ArrayList into an array which has the same size as the arraylist
         * 
         * @param Array 
         */
        template <usize Size>
        void toArray(const T (&Array)[Size]) {
            for(usize i = 0; i < size(); i++) { Array[i] = this->arrayList[i]; }
        }

        /**
         * @brief A method that can be used to check if 2 ArrayLists are equal for all elements
         * 
         * @param other 
         * @return bool
         */
        bool isEqual(ArrayList<T> other) {
            if(this->size() != other.size()) return false;
            for(usize i = 0; i < this->size(); i++) if(this->arrayList[i] != other.arrayList[i]) return false; 
            return true;
        }

        /**
         * @brief A method that shuffles an ArrayList
         * 
         */
        void shuffle() {
            Random random;
            for(usize i = this->size() - 1; i > 0; i--) {
                usize j = random.nextInt(0, i);
                jamstl::swap(this->arrayList[i], this->arrayList[j]);
            }
            return;
        }

        /**
         * @brief A method to copy an ArrayList into another ArrayList
         * 
         * @param other 
         * @return bool
         */
        bool clone(const ArrayList<T>& other) {
            if(!this->isEmpty()) this->empty();

            for(usize i = 0; i < other.size(); i++) {
                this->push(other.arrayList[i]);
            }
            return true;
        }
        
        ArrayList& operator=(const ArrayList<T>& list) {
            this->clone(list);
            return *this;
        }

        class iterator : public Iterator<ForwardIteratorTag, T> {
        private:
            T* arrayList;
            usize index;
        public:
            iterator(T* arrayList, usize index) 
                : arrayList(arrayList), index(index) {}
            iterator(const iterator& other) 
                : arrayList(other.arrayList), index(other.index) {}

            iterator& operator++() {
                this->index++;
                return *this;
            }

            iterator operator++(int) {
                iterator temp = *this;
                this->index++;
                return temp;
            }

            iterator operator+(const T& n) {
                iterator temp = *this;
                temp.index += n;
                return temp;
            }

            iterator operator+(const iterator& other) {
                iterator temp = *this;
                temp.index += other.index;
                return temp;
            }

            iterator operator-(const T& n) {
                iterator temp = *this;
                temp.index -= n;
                return temp;
            }

            iterator operator-(const iterator& other) {
                iterator temp = *this;
                temp.index -= other.index;
                return temp;
            }

            iterator operator*(const iterator& other) {
                iterator temp = *this;
                temp.index *= other.index;
                return temp;
            }

            iterator operator*(const T& n) {
                iterator temp = *this;
                temp.index *= n;
                return temp;
            }

            iterator operator/(const iterator& other) {
                iterator temp = *this;
                temp.index /= other.index;
                return temp;
            }

            iterator operator/(const T& n) {
                iterator temp = *this;
                temp.index /= n;
                return temp;
            }
            
            iterator& operator=(const iterator& other) {
                this->arrayList = other.arrayList;
                this->index = other.index;
                return *this;
            }

            iterator& operator=(const T& value) {
                this->arrayList[this->index] = value;
                return *this;
            }

            bool operator==(const iterator& other) {
                return this->index == other.index;
            }

            bool operator!=(const iterator& other) {
                return this->index != other.index;
            }

            T& operator*() {
                return this->arrayList[this->index];
            }

            T* operator->() {
                return &this->arrayList[this->index];
            }

            T& operator[](usize index) {
                return this->arrayList[index];
            }

            T& operator()(usize index) {
                return this->arrayList[index];
            }
        };

        iterator begin() const {
            return iterator(this->arrayList, 0);
        }

        iterator end() const {
            return iterator(this->arrayList, this->size());
        }

        iterator rbegin() const {
            return iterator(this->arrayList, this->size() - 1);
        }

        iterator rend() const {
            return iterator(this->arrayList, -1);
        }
        
    };

    namespace TypeTraits {
        template<typename T>
        struct isArrayList {
            static const bool value = false;
        };

        template<typename T>
        struct isArrayList<ArrayList<T>> {
            static const bool value = true;
        };
    }
    

JAMSTL_NAMESPACE_END
#endif