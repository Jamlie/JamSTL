#pragma once

#ifndef JAMSTL_ITERATOR_H
#define JAMSTL_ITERATOR_H 1
#include "Macros.h"
#include "TypeTraits.h"
#include "bits/TypeTraits.h"

JAMSTL_NAMESPACE_BEGIN

    struct InputIteratorTag {};

    struct OutputIteratorTag {};

    struct ForwardIteratorTag : public InputIteratorTag {};

    struct BidirectionalIteratorTag : public ForwardIteratorTag {};

    struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

    template <typename _Category_, typename _Tp_, typename _Distance_ = long,
                typename _Pointer_ = _Tp_*, typename _Reference_ = _Tp_&>
    struct Iterator {
        typedef _Category_ iteratorCategory;
        typedef _Tp_ valueType;
        typedef _Distance_ differenceType;
        typedef _Pointer_ pointer;
        typedef _Reference_ reference;
    };

    template<typename _Iterator>
    struct IteratorTraits {
        typedef typename _Iterator::iteratorCategory    iteratorCategory;
        typedef typename _Iterator::valueType           valueType;
        typedef typename _Iterator::differenceType      differenceType;
        typedef typename _Iterator::pointer             pointer;
        typedef typename _Iterator::reference           reference;
    };

    template<typename _Tp_>
    struct iteratorTraits {
        typedef RandomAccessIteratorTag     iteratorCategory;
        typedef _Tp_                        valueType;
        typedef long                        differenceType;
        typedef _Tp_*                       pointer;
        typedef _Tp_&                       reference;
    };

    template<typename _Tp_>
    struct iteratorTraits<const _Tp_*> {
        typedef RandomAccessIteratorTag     iteratorCategory;
        typedef _Tp_                        valueType;
        typedef long                        differenceType;
        typedef const _Tp_*                 pointer;
        typedef const _Tp_&                 reference;
    };

    template<typename _Iter>
    inline typename IteratorTraits<_Iter>::iteratorCategory
    iteratorCategory(const _Iter&) {
        return typename IteratorTraits<_Iter>::iteratorCategory();
    }

    template<typename _Iterator, bool _HasBase>
    struct _Iter_base {
        typedef _Iterator iteratorType;
        static iteratorType _S_base(_Iterator __it) { return __it; }
    };

    template<typename _Iterator>
    struct _Iter_base<_Iterator, true> {
        typedef typename _Iterator::iteratorType iteratorType;
        static iteratorType _S_base(_Iterator __it) { return __it.base(); }
    };


JAMSTL_NAMESPACE_END


#endif