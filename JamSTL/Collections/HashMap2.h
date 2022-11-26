#pragma once

#include <ostream>
#include <initializer_list>
#include <functional>
#include "../Iterator.h"
#include "../type_traits.h"
#include "../Macros.h"
#include "../Math.h"
#include "../Object.h"

#ifndef HASHMAP_H
#define HASHMAP_H

JAMSTL_NAMESPACE_BEGIN

template <typename Key, typename Value>
class HashMap extends Object {
    private:
        struct Node {
            Key key;
            Value value;
            Node* next;
        };

        Node** table;
        usize tableSize;
        usize length;

        

        void resize() {
            usize newTableSize = tableSize * 2;
            Node** newTable = new Node*[newTableSize];
            for(usize i = 0; i < newTableSize; i++) {
                newTable[i] = nullptr;
            }

            for(usize i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while(node != nullptr) {
                    usize hashValue = hash(node->key);
                    Node* newNode = new Node;
                    newNode->key = node->key;
                    newNode->value = node->value;
                    newNode->next = newTable[hashValue];
                    newTable[hashValue] = newNode;
                    node = node->next;
                }
            }

            for(usize i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while(node != nullptr) {
                    Node* next = node->next;
                    delete node;
                    node = next;
                }
            }

            delete[] table;
            table = newTable;
            tableSize = newTableSize;
        }

    public:
        usize hash(const Key& key) const {
            if(type_traits::isNumber<Key>) {
                return hash
            }
            return hashBytes(&key, sizeof(Key)) % tableSize;
        }
        HashMap() {
            tableSize = 16;
            table = new Node*[tableSize];
            for(usize i = 0; i < tableSize; i++) {
                table[i] = nullptr;
            }
            length = 0;
        }

        HashMap(std::initializer_list<std::pair<Key, Value>> list) {
            tableSize = 16;
            table = new Node*[tableSize];
            for(usize i = 0; i < tableSize; i++) {
                table[i] = nullptr;
            }
            length = 0;

            for(auto& pair : list) {
                put(pair.first, pair.second);
            }
        }

        HashMap(const HashMap& other) {
            tableSize = other.tableSize;
            table = new Node*[tableSize];
            for(usize i = 0; i < tableSize; i++) {
                table[i] = nullptr;
            }
            length = 0;

            for(auto& pair : other) {
                put(pair.first, pair.second);
            }
        }

        HashMap(HashMap&& other) {
            tableSize = other.tableSize;
            table = other.table;
            length = other.length;

            other.tableSize = 0;
            other.table = nullptr;
            other.length = 0;
        }

        HashMap& operator=(const HashMap& other) {
            if(this == &other) {
                return *this;
            }

            for(usize i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while(node != nullptr) {
                    Node* next = node->next;
                    delete node;
                    node = next;
                }
            }

            delete[] table;

            tableSize = other.tableSize;
            table = new Node*[tableSize];
            for(usize i = 0; i < tableSize; i++) {
                table[i] = nullptr;
            }
            length = 0;

            for(auto& pair : other) {
                put(pair.first, pair.second);
            }

            return *this;
        }

        HashMap& operator=(HashMap&& other) {
            if(this == &other) {
                return *this;
            }

            for(usize i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while(node != nullptr) {
                    Node* next = node->next;
                    delete node;
                    node = next;
                }
            }
        }

        ~HashMap() {
            for(usize i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while(node != nullptr) {
                    Node* next = node->next;
                    delete node;
                    node = next;
                }
            }

            delete[] table;
        }

        usize size() const {
            return length;
        }

        bool isEmpty() const {
            return length == 0;
        }

        void clear() {
            for(usize i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while(node != nullptr) {
                    Node* next = node->next;
                    delete node;
                    node = next;
                }
                table[i] = nullptr;
            }
            length = 0;
        }

        void put(const Key& key, const Value& value) {
            usize hashValue = hash(key);
            Node* node = table[hashValue];
            while(node != nullptr) {
                if(node->key == key) {
                    node->value = value;
                    return;
                }
                node = node->next;
            }

            Node* newNode = new Node;
            newNode->key = key;
            newNode->value = value;
            newNode->next = table[hashValue];
            table[hashValue] = newNode;
            length++;

            if(length > tableSize * 0.75) {
                resize();
            }
        }

        bool containsKey(const Key& key) const {
            usize hashValue = hash(key);
            Node* node = table[hashValue];
            while(node != nullptr) {
                if(node->key == key) {
                    return true;
                }
                node = node->next;
            }
            return false;
        }

        bool containsValue(const Value& value) const {
            for(usize i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while(node != nullptr) {
                    if(node->value == value) {
                        return true;
                    }
                    node = node->next;
                }
            }
            return false;
        }

        Value get(const Key& key) {
            usize hashValue = hash(key);
            Node* node = table[hashValue];
            while(node != nullptr) {
                if(node->key == key) {
                    return node->value;
                }
                node = node->next;
            }
            return Value();
        }

        class Iterator {
            friend class HashMap;
        private:
            HashMap* map;
            usize index;
            Node* node;

            Iterator(HashMap* map, usize index, Node* node) {
                this->map = map;
                this->index = index;
                this->node = node;
            }

        public:
            Iterator(const Iterator& other) {
                map = other.map;
                index = other.index;
                node = other.node;
            }

            Iterator& operator=(const Iterator& other) {
                if(this == &other) {
                    return *this;
                }

                map = other.map;
                index = other.index;
                node = other.node;

                return *this;
            }

            Iterator& operator++() {
                if(node->next != nullptr) {
                    node = node->next;
                } else {
                    index++;
                    while(index < map->tableSize && map->table[index] == nullptr) {
                        index++;
                    }
                    if(index < map->tableSize) {
                        node = map->table[index];
                    } else {
                        node = nullptr;
                    }
                }
                return *this;
            }

            Iterator operator++(int) {
                Iterator it = *this;
                ++(*this);
                return it;
            }

            bool operator==(const Iterator& other) const {
                return map == other.map && index == other.index && node == other.node;
            }

            bool operator!=(const Iterator& other) const {
                return !(*this == other);
            }

            std::pair<Key, Value>& operator*() const {
                return node->pair;
            }

            std::pair<Key, Value>* operator->() const {
                return &node->pair;
            }
        };

        Iterator begin() {
            for(usize i = 0; i < tableSize; i++) {
                if(table[i] != nullptr) {
                    return Iterator(this, i, table[i]);
                }
            }
            return end();
        }

        Iterator end() {
            return Iterator(this, tableSize, nullptr);
        }
};

JAMSTL_NAMESPACE_END

#endif