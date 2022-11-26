#pragma once

#include "../Datatypes.h"
#include "../Macros.h"

#ifndef HASHBYTES_H
#define HASHBYTES_H 

JAMSTL_NAMESPACE_BEGIN
    
    int hashBytes(const void* ptr, usize size) {
        const byte* bytes = static_cast<const byte*>(ptr);
        int hash = 0;
        for(usize i = 0; i < size; i++) {
            hash = hash * 31 + bytes[i];
        }
        return hash;
    }

    int hashBytes(const void* ptr, usize size, int seed) {
        const byte* bytes = static_cast<const byte*>(ptr);
        int hash = seed;
        for(usize i = 0; i < size; i++) {
            hash = hash * 31 + bytes[i];
        }
        return hash;
    }



JAMSTL_NAMESPACE_END

#endif