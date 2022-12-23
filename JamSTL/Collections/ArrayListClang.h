#pragma once

#ifndef JAMSTL_ARRAYLISTCLANG_H
#define JAMSTL_ARRAYLISTCLANG_H 1
#include "../Macros.h"
#include "../Object.h"
#include "../String.h"
#include "../Math.h"

JAMSTL_NAMESPACE_BEGIN


template<typename T>
class ArrayListClang extends Object {
private:
    T* array;
    usize length;
    usize capacity;

    void resize(usize newCapacity) {
        T* newArray = new T[newCapacity];
        for (usize i = 0; i < length; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

    void heapify(T arr[], usize arrSize, usize index) {
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
            T temp = arr[index];
            arr[index] = arr[largest];
            arr[largest] = temp;

            heapify(arr, arrSize, largest);
        }
    }

public:
    ArrayListClang() {
        array = new T[10];
        length = 0;
        capacity = 10;
    }

    ArrayListClang(usize initialCapacity) {
        array = new T[initialCapacity];
        length = 0;
        capacity = initialCapacity;
    }

    ArrayListClang(const ArrayListClang<T>& other) {
        array = new T[other.capacity];
        length = other.length;
        capacity = other.capacity;
        for (usize i = 0; i < length; i++) {
            array[i] = other.array[i];
        }
    }

    ArrayListClang(ArrayListClang<T>&& other) {
        array = other.array;
        length = other.length;
        capacity = other.capacity;
        other.array = nullptr;
        other.length = 0;
        other.capacity = 0;
    }

    ~ArrayListClang() {
        delete[] array;
    }

    ArrayListClang<T>& operator=(const ArrayListClang<T>& other) {
        if (this != &other) {
            delete[] array;
            array = new T[other.capacity];
            length = other.length;
            capacity = other.capacity;
            for (usize i = 0; i < length; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    ArrayListClang<T>& operator=(ArrayListClang<T>&& other) {
        if (this != &other) {
            delete[] array;
            array = other.array;
            length = other.length;
            capacity = other.capacity;
            other.array = nullptr;
            other.length = 0;
            other.capacity = 0;
        }
        return *this;
    }

    usize size() const {
        return length;
    }

    usize getCapacity() const {
        return capacity;
    }

    bool isEmpty() const {
        return length == 0;
    }

    T get(usize index) const {
        if (index >= length) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        return array[index];
    }

    void set(usize index, T element) {
        if (index >= length) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        array[index] = element;
    }

    void add(const T& element) {
        if (length == capacity) {
            resize(2 * capacity);
        }
        array[length] = element;
        length++;
    }

    void add(usize index, const T& element) {
        if (index > length) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        if (length == capacity) {
            resize(2 * capacity);
        }
        for (usize i = length; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = element;
        length++;
    }

    void add(T&& element) {
        if (length == capacity) {
            resize(2 * capacity);
        }
        array[length] = jamstl::type_traits::move(element);
        length++;
    }

    void add(usize index, T&& element) {
        if (index > length) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        if (length == capacity) {
            resize(2 * capacity);
        }
        for (usize i = length; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = jamstl::type_traits::move(element);
        length++;
    }

    void remove(usize index) {
        if (index >= length) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        for (usize i = index; i < length - 1; i++) {
            array[i] = array[i + 1];
        }
        length--;
        if (length > 0 && length == capacity / 4) {
            resize(capacity / 2);
        }
    }

    void remove(T element) {
        for (usize i = 0; i < length; i++) {
            if (array[i] == element) {
                remove(i);
                return;
            }
        }
    }

    void clear() {
        delete[] array;
        array = new T[10];
        length = 0;
        capacity = 10;
    }

    bool contains(T element) const {
        for (usize i = 0; i < length; i++) {
            if (array[i] == element) {
                return true;
            }
        }
        return false;
    }

    usize indexOf(T element) const {
        for (usize i = 0; i < length; i++) {
            if (array[i] == element) {
                return i;
            }
        }
        return -1;
    }

    usize lastIndexOf(T element) const {
        for (usize i = length - 1; i >= 0; i--) {
            if (array[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void sort() {
        for (usize i = length / 2 - 1; i >= 0; i--) {
            heapify(array, length, i);
        }

        for (usize i = length - 1; i >= 0; i--) {
            T temp = array[0];
            array[0] = array[i];
            array[i] = temp;

            heapify(array, i, 0);
        }
    }

    void reverse() {
        for (usize i = 0; i < length / 2; i++) {
            T temp = array[i];
            array[i] = array[length - i - 1];
            array[length - i - 1] = temp;
        }
    }

    T& operator[](usize index) {
        if (index >= length) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        return array[index];
    }

    const T& operator[](usize index) const {
        if (index >= length) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        return array[index];
    }

    String valueOf() const {
        String result = "[";
        for (usize i = 0; i < length; i++) {
            result += String::valueOf(array[i]);
            if (i != length - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

};




JAMSTL_NAMESPACE_END

#endif