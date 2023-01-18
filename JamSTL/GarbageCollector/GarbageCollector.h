#pragma once

#ifndef JAMSTL_GARBAGECOLLECTOR_H
#define JAMSTL_GARBAGECOLLECTOR_H
#include "../Macros.h"
#include "Pointer.h"
#include "Reference.h"

JAMSTL_NAMESPACE_BEGIN


class GarbageCollector extends Object {
public:
    GarbageCollector() = delete;
    GarbageCollector(const GarbageCollector&) = delete;
    GarbageCollector(GarbageCollector&&) = delete;
    GarbageCollector& operator=(const GarbageCollector&) = delete;
    GarbageCollector& operator=(GarbageCollector&&) = delete;

    template<class T, class... Args>
    static Pointer<T> pallocate(Args&&... args) {
        return Pointer<T>(new T(jamstl::TypeTraits::forward<Args>(args)...));
    }

    template<class T, class... Args>
    static Reference<T> rallocate(Args&&... args) {
        return Reference<T>(new T(jamstl::TypeTraits::forward<Args>(args)...));
    }

};


JAMSTL_NAMESPACE_END

#endif