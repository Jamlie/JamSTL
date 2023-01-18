#pragma once

#ifndef JAMSTL_JARRAYLIST_H
#define JAMSTL_JARRAYLIST_H
#include "../Macros.h"
#include "JArray.h"

JAMSTL_NAMESPACE_BEGIN

template<class T>
class JArrayList extends Object {
private:
    JArray<T> arraylist;
    int size;
    int capa;
public:
    JArrayList() {
        size = 0;
        capa = 10;
        arraylist = JArray<T>(capa);
    }

    JArrayList(int capa) {
        size = 0;
        this->capa = capa;
        arraylist = JArray<T>(capa);
    }

    JArrayList(const JArrayList& other) {
        this->size = other.size;
        this->capa = other.capa;
        this->arraylist = other.arraylist;
    }

    JArrayList(JArrayList&& other) {
        this->size = other.size;
        this->capa = other.capa;
        this->arraylist = other.arraylist;
        other.arraylist = nullptr;
    }

    void add(T element) {
        if (size == capa) {
            capa *= 2;
            JArray<T> temp(capa);
            for (int i = 0; i < size; i++) {
                temp[i] = arraylist[i];
            }
            arraylist = temp;
        }
        arraylist[size++] = element;
    }

    void add(int index, T element) {
        if (index < 0 || index > size) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        if (size == capa) {
            capa *= 2;
            JArray<T> temp(capa);
            for (int i = 0; i < size; i++) {
                temp[i] = arraylist[i];
            }
            arraylist = temp;
        }
        for (int i = size; i > index; i--) {
            arraylist[i] = arraylist[i - 1];
        }
        arraylist[index] = element;
        size++;
    }

    void clear() {
        size = 0;
    }

    bool contains(T element) {
        for (int i = 0; i < size; i++) {
            if (arraylist[i] == element) {
                return true;
            }
        }
        return false;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        return arraylist[index];
    }

    int indexOf(T element) {
        for (int i = 0; i < size; i++) {
            if (arraylist[i] == element) {
                return i;
            }
        }
        return -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        for (int i = index; i < size - 1; i++) {
            arraylist[i] = arraylist[i + 1];
        }
        size--;
    }

    void remove() {
        if (size == 0) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        this->arraylist[size - 1] = T();
        size--;
    }

    void set(int index, T element) {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException("Index out of bounds");
        }
        arraylist[index] = element;
    }

    int length() const {
        return this->size;
    }

    int capacity() const {
        return this->capa;
    }

    String valueOf() const {
        String str = "[";
        for (int i = 0; i < size; i++) {
            str.append(arraylist[i]);
            if (i != size - 1) {
                str += ", ";
            }
        }
        str += "]";
        return str;
    }

};

JAMSTL_NAMESPACE_END


#endif