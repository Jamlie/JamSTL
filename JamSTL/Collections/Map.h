#pragma once

#ifndef JAMSTL_MAP_H
#define JAMSTL_MAP_H
#include "../Macros.h"
#include "../Object.h"

JAMSTL_NAMESPACE_BEGIN

    template<class K, class V>
    abstract class Map extends Object {
        public:

            usize virtual size() const = 0;

            bool virtual isEmpty() const = 0;

            bool virtual containsKey(const K& key) const = 0;

            bool virtual containsValue(const V& value) const = 0;

            V virtual get(const K& key) const = 0;

            V virtual put(const K& key, const V& value) = 0;

            V virtual remove(const K& key) = 0;

            void virtual putAll(const Map<K, V>& map) = 0;

            void virtual clear() = 0;

            bool virtual equals() const = 0;

            long long virtual hashCode() = 0;

            V putIfAbsent(K key, V value) {
                if (!containsKey(key)) {
                    put(key, value);
                }
                return get(key);
            }

            virtual ~Map() = default;

            class Entry {
                public:
                    K virtual getKey() const = 0;

                    V virtual getValue() const = 0;

                    V virtual setValue(const V& value) = 0;

                    // bool virtual equals() const = 0; 

                    long long virtual hashCode() = 0;

                    virtual ~Entry() = default;
            };

    };

JAMSTL_NAMESPACE_END


#endif