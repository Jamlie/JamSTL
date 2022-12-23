#pragma once

#ifndef JAMSTL_HASHMAP_H
#define JASMTL_HASHMAP_H
#include "../Macros.h"
#include "../Object.h"
#include "../String.h"
#include "../String/StringHelper.h"
#include "../Iterator.h"
#include "Pair.h"
#include <initializer_list>

JAMSTL_NAMESPACE_BEGIN

    template<class K, class V>
    class HashMap extends Object {
        private:
            struct Node {
                K key;
                V value;
                Node* next;
            };

            Node** table;
            int Length;
            int capacity;

            int hash(const K& key) {
                return String::hashCode(String::valueOf(key)) % capacity;
            }

            void resize() {
                Node** oldTable = table;
                int oldCapacity = capacity;
                capacity *= 2;
                table = new Node*[capacity];
                for(int i = 0; i < capacity; i++) {
                    table[i] = nullptr;
                }
                Length = 0;
                for(int i = 0; i < oldCapacity; i++) {
                    Node* entry = oldTable[i];
                    while(entry != nullptr) {
                        put(entry->key, entry->value);
                        entry = entry->next;
                    }
                    if(oldTable[i] != nullptr) {
                        delete oldTable[i];
                    }
                }
                delete[] oldTable;
            }

        public:
            HashMap() {
                capacity = 16;
                table = new Node*[capacity];
                for(int i = 0; i < capacity; i++) {
                    table[i] = nullptr;
                }
                Length = 0;
            }

            HashMap(int capacity) {
                this->capacity = capacity;
                table = new Node*[capacity];
                for(int i = 0; i < capacity; i++) {
                    table[i] = nullptr;
                }
                Length = 0;
            }

            HashMap(std::initializer_list<Pair<K, V>> list) {
                capacity = 16;
                table = new Node*[capacity];
                for(int i = 0; i < capacity; i++) {
                    table[i] = nullptr;
                }
                Length = 0;
                for(auto& pair : list) {
                    put(pair.first, pair.second);
                }
            }

            HashMap(const HashMap& other) {
                capacity = other.capacity;
                table = new Node*[capacity];
                for(int i = 0; i < capacity; i++) {
                    table[i] = nullptr;
                }
                Length = 0;
                for(int i = 0; i < other.capacity; i++) {
                    Node* entry = other.table[i];
                    while(entry != nullptr) {
                        put(entry->key, entry->value);
                        entry = entry->next;
                    }
                }
            }

            HashMap(HashMap&& other) {
                capacity = other.capacity;
                table = other.table;
                Length = other.Length;
                other.capacity = 0;
                other.table = nullptr;
                other.Length = 0;
            }

            ~HashMap() {
                for(int i = 0; i < capacity; i++) {
                    Node* entry = table[i];
                    while(entry != nullptr) {
                        Node* prev = entry;
                        entry = entry->next;
                        delete prev;
                    }
                }
                ::operator delete[](table);
            }

            void put(const K& key, const V& value) {
                int hashValue = hash(key);
                Node* entry = table[hashValue];
                if(entry == nullptr) {
                    table[hashValue] = new Node{key, value, nullptr};
                    Length++;
                } else {
                    Node* prev;
                    do {
                        if(entry->key == key) {
                            entry->value = value;
                            return;
                        }
                        prev = entry;
                        entry = entry->next;
                    } while(entry != nullptr);
                    prev->next = new Node{key, value, nullptr};
                    Length++;
                }
                float loadFactor = (float)Length / (float)capacity;
                if(loadFactor >= 0.75f) {
                    resize();
                }
            }

            void putIfAbsent(const K& key, const V& value) {
                if(!containsKey(key)) {
                    put(key, value);
                }
            }

            V get(const K& key) {
                int hashValue = hash(key);
                Node* entry = table[hashValue];
                if(entry == nullptr) {
                    return V();
                } else {
                    do {
                        if(entry->key == key) {
                            return entry->value;
                        }
                        entry = entry->next;
                    } while(entry != nullptr);
                    return V();
                }
            }

            bool containsKey(const K& key) {
                int hashValue = hash(key);
                Node* entry = table[hashValue];
                if(entry == nullptr) {
                    return false;
                } else {
                    do {
                        if(entry->key == key) {
                            return true;
                        }
                        entry = entry->next;
                    } while(entry != nullptr);
                    return false;
                }
            }

            bool containsValue(const V& value) {
                for(int i = 0; i < capacity; i++) {
                    Node* entry = table[i];
                    while(entry != nullptr) {
                        if(entry->value == value) {
                            return true;
                        }
                        entry = entry->next;
                    }
                }
                return false;
            }

            bool containsHash(int hash) const {
                for(int i = 0; i < capacity; i++) {
                    Node* entry = table[i];
                    while(entry != nullptr) {
                        if((int)String::hashCode(String::valueOf(entry->key)) == hash) {
                            return true;
                        }
                        entry = entry->next;
                    }
                }
                return false;
            }

            String values() const {
                String result = "[";
                for(int i = 0; i < Length; i++) {
                    result += String::valueOf(getValue(i));
                    if(i < Length - 1) {
                        result += ", ";
                    }
                }
                result += "]";
                return result;
            }

            String keys() const {
                String result = "[";
                for(int i = 0; i < Length; i++) {
                    result += String::valueOf(getKey(i));
                    if(i < Length - 1) {
                        result += ", ";
                    }
                }
                result += "]";
                return result;
            }

            V getValue(int index) const {
                if(index >= Length) {
                    return V();
                }
                int i = 0;
                for(int j = 0; j < capacity; j++) {
                    Node* entry = table[j];
                    while(entry != nullptr) {
                        if(i == index) {
                            return entry->value;
                        }
                        entry = entry->next;
                        i++;
                    }
                }
                return V();
            }

            K getKey(int index) const {
                if(index >= Length) {
                    return K();
                }
                int i = 0;
                for(int j = 0; j < capacity; j++) {
                    Node* entry = table[j];
                    while(entry != nullptr) {
                        if(i == index) {
                            return entry->key;
                        }
                        entry = entry->next;
                        i++;
                    }
                }
                return K();
            }
            

            void remove(const K& key) {
                int hashValue = hash(key);
                Node* entry = table[hashValue];
                if(entry == nullptr) {
                    return;
                } else {
                    Node* prev = nullptr;
                    do {
                        if(entry->key == key) {
                            if(prev == nullptr) {
                                table[hashValue] = entry->next;
                            } else {
                                prev->next = entry->next;
                            }
                            delete entry;
                            Length--;
                            return;
                        }
                        prev = entry;
                        entry = entry->next;
                    } while(entry != nullptr);
                }
            }

            void removeByHashValue(int hash) {
                for(int i = 0; i < capacity; i++) {
                    Node* entry = table[i];
                    if(entry == nullptr) {
                        continue;
                    } else {
                        Node* prev = nullptr;
                        do {
                            if((int)String::hashCode(String::valueOf(entry->key)) == hash) {
                                if(prev == nullptr) {
                                    table[i] = entry->next;
                                } else {
                                    prev->next = entry->next;
                                }
                                delete entry;
                                Length--;
                                return;
                            }
                            prev = entry;
                            entry = entry->next;
                        } while(entry != nullptr);
                    }
                }
            }

            void clear() {
                for(int i = 0; i < capacity; i++) {
                    Node* entry = table[i];
                    while(entry != nullptr) {
                        Node* prev = entry;
                        entry = entry->next;
                        delete prev;
                    }
                    table[i] = nullptr;
                }
                Length = 0;
            }

            int size() const {
                return Length;
            }

            String valueOf() const {
                String result = "{";
                bool first = true;
                for(int i = 0; i < capacity; i++) {
                    Node* entry = table[i];
                    while(entry != nullptr) {
                        if(first) {
                            first = false;
                        } else {
                            result += ", ";
                        }
                        result += String::valueOf(entry->key) + "=" + String::valueOf(entry->value);
                        entry = entry->next;
                    }
                }
                result += "}";
                return result;
            }


            V operator[](const K& key) const {
                return get(key);
            }
            

            HashMap& operator=(const HashMap& other) {
                if(this != &other) {
                    clear();
                    for(int i = 0; i < other.capacity; i++) {
                        Node* entry = other.table[i];
                        while(entry != nullptr) {
                            put(entry->key, entry->value);
                            entry = entry->next;
                        }
                    }
                }
                return *this;
            }


            bool operator==(const HashMap& other) const {
                if(this == &other) {
                    return true;
                }
                if(Length != other.Length) {
                    return false;
                }
                for(int i = 0; i < capacity; i++) {
                    Node* entry = table[i];
                    while(entry != nullptr) {
                        if(!other.containsKey(entry->key)) {
                            return false;
                        }
                        if(entry->value != other.get(entry->key)) {
                            return false;
                        }
                        entry = entry->next;
                    }
                }
                return true;
            }


            bool operator!=(const HashMap& other) const {
                return !(*this == other);
            }

            bool equals(const HashMap& other) const {
                return *this == other;
            }

            friend std::ostream& operator<<(std::ostream& os, const HashMap& map) {
                os << "{";
                bool first = true;
                for(int i = 0; i < map.capacity; i++) {
                    Node* entry = map.table[i];
                    while(entry != nullptr) {
                        if(first) {
                            first = false;
                        } else {
                            os << ", ";
                        }
                        os << entry->key << "=" << entry->value;
                        entry = entry->next;
                    }
                }
                os << "}";
                return os;
            }

            class iterator : public Iterator<ForwardIteratorTag, Pair<K, V>> {
            private:
                HashMap* map;
                int index;
                Node* entry;
            public:
                iterator(HashMap* map, int index, Node* entry) : map(map), index(index), entry(entry) {
                }

                iterator(const iterator& other) : map(other.map), index(other.index), entry(other.entry) {
                }

                iterator& operator=(const iterator& other) {
                    map = other.map;
                    index = other.index;
                    entry = other.entry;
                    return *this;
                }

                iterator& operator++() {
                    if(entry != nullptr) {
                        entry = entry->next;
                    }
                    if(entry == nullptr) {
                        index++;
                        while(index < map->capacity && map->table[index] == nullptr) {
                            index++;
                        }
                        if(index < map->capacity) {
                            entry = map->table[index];
                        }
                    }
                    return *this;
                }

                iterator operator++(int) {
                    iterator result = *this;
                    ++(*this);
                    return result;
                }

                bool operator==(const iterator& other) const {
                    return map == other.map && index == other.index && entry == other.entry;
                }

                bool operator!=(const iterator& other) const {
                    return !(*this == other);
                }

                Pair<K, V> operator*() const {
                    return Pair<K, V>(entry->key, entry->value);
                }

                Pair<K, V>* operator->() const {
                    return new Pair<K, V>(entry->key, entry->value);
                }
            };

            iterator begin() {
                for(int i = 0; i < capacity; i++) {
                    if(table[i] != nullptr) {
                        return iterator(this, i, table[i]);
                    }
                }
                return end();
            }

            iterator end() {
                return iterator(this, capacity, nullptr);
            }

            class const_iterator : public Iterator<ForwardIteratorTag, const Pair<K, V>> {
            private:
                const HashMap* map;
                int index;
                Node* entry;
            public:
                const_iterator(const HashMap* map, int index, Node* entry) : map(map), index(index), entry(entry) {
                }

                const_iterator(const const_iterator& other) : map(other.map), index(other.index), entry(other.entry) {
                }

                const_iterator& operator=(const const_iterator& other) {
                    map = other.map;
                    index = other.index;
                    entry = other.entry;
                    return *this;
                }

                const_iterator& operator++() {
                    if(entry != nullptr) {
                        entry = entry->next;
                    }
                    if(entry == nullptr) {
                        index++;
                        while(index < map->capacity && map->table[index] == nullptr) {
                            index++;
                        }
                        if(index < map->capacity) {
                            entry = map->table[index];
                        }
                    }
                    return *this;
                }

                const_iterator operator++(int) {
                    const_iterator result = *this;
                    ++(*this);
                    return result;
                }

                bool operator==(const const_iterator& other) const {
                    return map == other.map && index == other.index && entry == other.entry;
                }

                bool operator!=(const const_iterator& other) const {
                    return !(*this == other);
                }

                const Pair<K, V> operator*() const {
                    return Pair<K, V>(entry->key, entry->value);
                }

                const Pair<K, V>* operator->() const {
                    return new Pair<K, V>(entry->key, entry->value);
                }
            };

            const_iterator begin() const {
                for(int i = 0; i < capacity; i++) {
                    if(table[i] != nullptr) {
                        return const_iterator(this, i, table[i]);
                    }
                }
                return end();
            }

            const_iterator end() const {
                return const_iterator(this, capacity, nullptr);
            }

    };

JAMSTL_NAMESPACE_END

#endif