#pragma once

#ifndef JAMSTL_TUPLE_H
#define JAMSTL_TUPLE_H
#include "../Macros.h"
#include "../Object.h"
#include "../bits/TypeTraits.h"
#include "../String.h"
#include "./Pair.h"
#include <initializer_list>

JAMSTL_NAMESPACE_BEGIN

template<typename... Types>
class Tuple;

template<>
class Tuple<> extends Object {
public:
    Tuple() {}
    Tuple(const Tuple<>&) {}

    Tuple& operator=(const Tuple<>&) {
        return *this;
    }


    String valueOf() const {
        return "";
    }

    String toString() const {
        return valueOf();
    }
};

template<typename T1, typename... Types>
class Tuple<T1, Types...> extends Object {
    T1 first;
    Tuple<Types...> rest;
public:

    Tuple() : first(), rest() {}
    Tuple(const T1& arg, const Types&... args) : first(arg), rest(args...) {}

    Tuple(const Tuple<T1, Types...>& tuple) : first(tuple.first), rest(tuple.rest) {}

    Tuple(Tuple<T1, Types...>&& tuple) : 
    first(jamstl::TypeTraits::move(tuple.first)), rest(jamstl::TypeTraits::move(tuple.rest)) {}

    Tuple& operator=(const Tuple<T1, Types...>& tuple) {
        first = tuple.first;
        rest = tuple.rest;
        return *this;
    }

    Tuple& operator=(Tuple<T1, Types...>&& tuple) {
        first = jamstl::TypeTraits::move(tuple.first);
        rest = jamstl::TypeTraits::move(tuple.rest);
        return *this;
    }

    void swap(Tuple& tuple) {
        jamstl::swap(first, tuple.first);
        rest.swap(tuple.rest);
    }

    String valueOf() const {
        return first.valueOf() + " "_s + rest.valueOf();
    }

    String toString() const {
        return valueOf();
    }

    bool operator==(const Tuple<T1, Types...>& tuple) const {
        return first == tuple.first && rest == tuple.rest;
    }

    bool operator!=(const Tuple<T1, Types...>& tuple) const {
        return !(*this == tuple);
    }

    T1 getFirst() const {
        return first;
    }

    Tuple<Types...> getRest() const {
        return rest;
    }

};


template<typename... Types>
Tuple<Types...> makeTuple(const Types&... args) {
    return Tuple<Types...>(args...);
}

template<typename... Types>
Tuple<Types...> makeTuple(Types&&... args) {
    return Tuple<Types...>(jamstl::TypeTraits::move(args)...);
}







JAMSTL_NAMESPACE_END

#endif