#pragma once

#ifndef JAMSTL_SET_H
#define JAMSTL_SET_H 1
#include "../Macros.h"
#include "../Datatypes.h"
#include <ostream>

JAMSTL_NAMESPACE_BEGIN

    template <typename Type>
    class Set {
    public:
        Set() {
            _size = 0;
            _capacity = 0;
            _array = nullptr;
        }
        ~Set() {
            delete[] _array;
        }
        void add(Type value) {
            if (_size == _capacity) {
                _resize(_capacity * 2);
            }
            _array[_size++] = value;
        }
        void remove(Type value) {
            for (int i = 0; i < _size; i++) {
                if (_array[i] == value) {
                    _array[i] = _array[_size - 1];
                    _size--;
                    return;
                }
            }
        }
        bool contains(Type value) {
            for (int i = 0; i < _size; i++) {
                if (_array[i] == value) {
                    return true;
                }
            }
            return false;
        }
        int size() const {
            return _size;
        }
        Type* getArray() const {
            return _array;
        }
        Type get(int index) const {
            return _array[index];
        }
        void clear() {
            _size = 0;
        }
        void _resize(int newCapacity) {
            Type* newArray = new Type[newCapacity];
            for (int i = 0; i < _size; i++) {
                newArray[i] = _array[i];
            }
            delete[] _array;
            _array = newArray;
            _capacity = newCapacity;
        }

        friend std::ostream& operator<<(std::ostream& os, const Set<Type>& set) {
            for (int i = 0; i < set._size; i++) {
                os << set._array[i] << " ";
            }
            return os;
        }
    private:
        int _size;
        int _capacity;
        Type* _array;
    };

JAMSTL_NAMESPACE_END

#endif