#pragma once


#ifndef JAMSTL_MACROS_H
#define JAMSTL_MACROS_H

#define JAMSTL_NAMESPACE_BEGIN namespace jamstl {
#define JAMSTL_NAMESPACE_END }

#define JAM_NOEXCEPT noexcept



#define pass (void)0
#define let decltype(auto)
namespace jamstl {

#define __SIZE__TYPE__ long unsigned int
typedef __SIZE__TYPE__ usize;

}

#define Main() int main()
#define null '\0'
#define fun decltype(auto)
#define Public public:
#define Private private:
#define Protected protected:
#define extends :public


#endif