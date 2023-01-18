#pragma once

#ifndef JAMSTL_JARRAY_H
#define JAMSTL_JARRAY_H
#include "../Macros.h"
#include "../Object.h"
#include "../String.h"
#include "../Exception/ArrayIndexOutOfBoundsException.h"
#include "../Iterator.h"
#include <initializer_list>

JAMSTL_NAMESPACE_BEGIN


template<typename T>
class JArray extends Object {
private:
    T* arr;
    usize length;
public:
    JArray() : arr(nullptr), length(0) {}
    JArray(usize length) : arr(new T[length]), length(length) {}
    JArray(std::initializer_list<T> list) {
        this->length = list.size();
        this->arr = new T[this->length];
        usize i = 0;
        for(auto&& item : list) {
            this->arr[i] = item;
            i++;
        }
    }

    JArray(const JArray& other) {
        this->length = other.length;
        this->arr = new T[this->length];
        for(usize i = 0; i < this->length; i++) {
            this->arr[i] = other.arr[i];
        }
    }

    JArray(JArray&& other) {
        this->length = other.length;
        this->arr = other.arr;
        other.arr = nullptr;
    }

    ~JArray() {
        if(arr) {
            delete[] arr;
        }
    }

    JArray& operator=(const JArray& other) {
        if(this->arr) {
            delete[] this->arr;
        }
        this->length = other.length;
        this->arr = new T[this->length];
        for(usize i = 0; i < this->length; i++) {
            this->arr[i] = other.arr[i];
        }
        return *this;
    }

    JArray& operator=(JArray&& other) {
        if(this->arr) {
            delete[] this->arr;
        }
        this->length = other.length;
        this->arr = other.arr;
        other.arr = nullptr;
        return *this;
    }

    JArray& operator=(std::initializer_list<T> list) {
        if(this->length != 0) {
            this->length = this->length;
            this->arr = new T[this->length];
            usize i = 0;
            for(auto&& item : list) {
                if(i >= this->length) break;
                this->arr[i] = item;
                i++;
            }
            return *this;
        }

        this->length = list.size();
        this->arr = new T[this->length];
        usize i = 0;
        for(auto&& item : list) {
            this->arr[i] = item;
            i++;
        }
        return *this;
    }

    T& operator[](int index) {
        if((usize)index > this->length) {
            throw ArrayIndexOutOfBoundsException("Index out of bounds");
        }
        return this->arr[index];
    }

    const T& operator[](int index) const {
        if((usize)index > this->length) {
            throw ArrayIndexOutOfBoundsException("Index out of bounds");
        }
        return this->arr[index];
    }

    usize size() const {
        return this->length;
    }

    void set(usize size) {
        if(this->arr) {
            delete[] this->arr;
        }
        this->length = size;
        this->arr = new T[this->length];
    }

    String valueOf() const {
        String str = "[";
        for(usize i = 0; i < this->length; i++) {
            str += String::valueOf(this->arr[i]);
            if(i != this->length - 1) {
                str += ", ";
            }
        }
        str += "]";
        return str;
    }

    String toString() const {
        return this->valueOf();
    }

    operator T*() {
        return this->arr;
    }

    operator const T*() const {
        return this->arr;
    }

    class Iterate extends Iterator<ForwardIteratorTag, T> {
    private:
        JArray<T>* arr;
        usize index;
    public:
        Iterate(JArray<T>* arr, usize index) : arr(arr), index(index) {}

        Iterate& operator++() {
            this->index++;
            return *this;
        }

        Iterate operator++(int) {
            Iterate it = *this;
            this->index++;
            return it;
        }

        Iterate& operator--() {
            this->index--;
            return *this;
        }

        Iterate operator--(int) {
            Iterate it = *this;
            this->index--;
            return it;
        }

        bool operator==(const Iterate& other) const {
            return this->arr == other.arr && this->index == other.index;
        }

        bool operator!=(const Iterate& other) const {
            return this->arr != other.arr || this->index != other.index;
        }

        T& operator*() {
            return (*this->arr)[this->index];
        }

        T* operator->() {
            return &(*this->arr)[this->index];
        }
    };

    Iterate begin() {
        return Iterate(this, 0);
    }

    Iterate end() {
        return Iterate(this, this->length);
    }

};



JAMSTL_NAMESPACE_END

#endif