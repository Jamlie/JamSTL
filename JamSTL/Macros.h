#pragma once


#ifndef JAMSTL_MACROS_H
#define JAMSTL_MACROS_H

#define JAMSTL_NAMESPACE_BEGIN namespace jamstl {
#define JAMSTL_NAMESPACE_END }

#define JAM_NOEXCEPT noexcept



#define undefined (void)0
#define let decltype(auto)
namespace jamstl {

#define __SIZE__TYPE__ long unsigned int
// Used to define a type that is the size of the type passed in
typedef __SIZE__TYPE__ usize;
#define __UNSIGNED__CHAR__ unsigned char
typedef __UNSIGNED__CHAR__ byte;

}

#define Main() int main()
#define null '\0'
#define fun decltype(auto)
#define Public public:
#define Private private:
#define Protected protected:
#define extends :public
#define Println(x) Printer::println(x)
#define import using namespace
#define true true
#define false false


#endif