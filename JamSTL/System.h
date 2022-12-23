#pragma once

#ifndef JAMSTL_SYSTEM_H
#define JAMSTL_SYSTEM_H

#include "Macros.h"
#include "PrintStream.h"
#include "ScanStream.h"
#include "Datatypes.h"
#include "Collections/Array.h"
#include "Math.h"

JAMSTL_NAMESPACE_BEGIN


class System final {
    static void* memoryCopy(void* dest, const void* src, usize count) {
        char* dst = (char*)dest;
        const char* src_ = (const char*)src;
        for (usize i = 0; i < count; ++i) {
            dst[i] = src_[i];
        }
        return dest;
    }

    template<class T, usize size>
    usize len(const T(&)[size]) {
        return size;
    }
    
public:
    System() = delete;
    static PrintStream out;

};

ScanStream scanner(stdin);
PrintStream System::out(stdout);





JAMSTL_NAMESPACE_END
#endif