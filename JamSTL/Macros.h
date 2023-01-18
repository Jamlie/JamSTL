#pragma once


#ifndef JAMSTL_MACROS_H
#define JAMSTL_MACROS_H

#define JAMSTL_NAMESPACE_BEGIN namespace jamstl {
#define JAMSTL_NAMESPACE_END }

#define JAM_NOEXCEPT noexcept



namespace jamstl {

#define let decltype(auto)
#define __SIZE__TYPE__ unsigned long long
// Used to define a type that is the size of the type passed in
typedef __SIZE__TYPE__ usize;
#define __UNSIGNED__CHAR__ unsigned char
typedef __UNSIGNED__CHAR__ byte;

}

#define Main() int main()
constexpr auto null = nullptr;
#define fun decltype(auto)
#define pub private:public:
#define priv public:private:
#define prot private:protected:
#define extends :public
#define import using namespace
#define abstract

#endif