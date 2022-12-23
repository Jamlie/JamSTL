#pragma once

#ifndef JAMSTL_PAIR_H
#define JAMSTL_PAIR_H
#include "../Macros.h"
#include "../Object.h"
#include "../bits/type_traits.h"
#include "../String.h"
#include <initializer_list>

JAMSTL_NAMESPACE_BEGIN

template<typename K, typename V>
struct Pair extends Object {
    K first;
    V second;

    Pair() : first(), second() {}
    Pair(const K& a, const V& b) : first(a), second(b) {}

    Pair(const Pair<K, V>& pair) : first(pair.first), second(pair.second) {}

    Pair(Pair<K, V>&& pair) : 
    first(jamstl::type_traits::move(pair.first)), second(jamstl::type_traits::move(pair.second)) {}


    Pair& operator=(const Pair<K, V>& pair) {
        first = pair.first;
        second = pair.second;
        return *this;
    }

    Pair& operator=(Pair<K, V>&& pair) {
        first = jamstl::type_traits::move(pair.first);
        second = jamstl::type_traits::move(pair.second);
        return *this;
    }

    void swap(Pair& pair) {
        jamstl::swap(first, pair.first);
        jamstl::swap(second, pair.second);
    }

    String valueOf() const {
        return "["_s + String::valueOf(first) + ", " + String::valueOf(second) + "]"_s;
    }

    String toString() const {
        return valueOf();
    }

    bool operator==(const Pair<K, V>& pair) const {
        return first == pair.first && second == pair.second;
    }

    bool operator!=(const Pair<K, V>& pair) const {
        return !(*this == pair);
    }

    bool operator<(const Pair<K, V>& pair) const {
        return first < pair.first || (!(pair.first < first) && second < pair.second);
    }

    bool operator>(const Pair<K, V>& pair) const {
        return pair < *this;
    }

    bool operator<=(const Pair<K, V>& pair) const {
        return !(pair < *this);
    }

    bool operator>=(const Pair<K, V>& pair) const {
        return !(*this < pair);
    }

    friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
        os << pair.valueOf();
        return os;
    }

};

template<typename K, typename V>
Pair<K, V> makePair(K&& u1, V&& u2) {
    return Pair<K, V>(jamstl::type_traits::forward<K>(u1), jamstl::type_traits::forward<V>(u2));
}

JAMSTL_NAMESPACE_END

#endif