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

template <typename K, typename V>
class HashMap extends Object {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& key, const V& value, Node* next = nullptr) : key(key), value(value), next(next) {}
    };
    Node** table;
    size_t tableSize;
    size_t size;
    size_t hash(const K& key) const {
        return hashBytes(&key, sizeof(key)) % tableSize;
    }
    void resize() {
        Node** oldTable = table;
        size_t oldTableSize = tableSize;
        tableSize = tableSize * 2 + 1;
        table = new Node*[tableSize];
        for (size_t i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
        for (size_t i = 0; i < oldTableSize; i++) {
            Node* node = oldTable[i];
            while (node != nullptr) {
                Node* next = node->next;
                size_t index = hash(node->key);
                node->next = table[index];
                table[index] = node;
                node = next;
            }
        }
        delete[] oldTable;
    }

public:
    HashMap() {
        tableSize = 7;
        table = new Node*[tableSize];
        for (size_t i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
        size = 0;
    }
    HashMap(const HashMap& other) {
        tableSize = other.tableSize;
        table = new Node*[tableSize];
        for (size_t i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
        size = 0;
        for (size_t i = 0; i < other.tableSize; i++) {
            Node* node = other.table[i];
            while (node != nullptr) {
                Node* next = node->next;
                size_t index = hash(node->key);
                node->next = table[index];
                table[index] = node;
                node = next;
                size++;
            }
        }
    }
    HashMap(HashMap&& other) {
        tableSize = other.tableSize;
        table = other.table;
        size = other.size;
        other.tableSize = 0;
        other.table = nullptr;
        other.size = 0;
    }
    HashMap(std::initializer_list<std::pair<K, V>> list) {
        tableSize = 7;
        table = new Node*[tableSize];
        for (size_t i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
        size = 0;
        for (auto it = list.begin(); it != list.end(); it++) {
            replace(it->first, it->second);
        }
    }
    ~HashMap() {
        for (size_t i = 0; i < tableSize; i++) {
            Node* node = table[i];
            while (node != nullptr) {
                Node* next = node->next;
                delete node;
                node = next;
            }
        }
        delete[] table;
    }
    HashMap& operator=(const HashMap& other) {
        if (this != &other) {
            for (size_t i = 0; i < tableSize; i++) {
                Node* node = table[i];
                while (node != nullptr) {
                    Node* next = node->next;
                    delete node;
                    node = next;
                }
            }
            delete[] table;
            tableSize = other.table;
        }
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool containsKey(const K& key) const {
        size_t index = hash(key);
        Node* node = table[index];
        while (node != nullptr) {
            if (node->key == key) {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    bool containsValue(const V& value) const {
        for (size_t i = 0; i < tableSize; i++) {
            Node* node = table[i];
            while (node != nullptr) {
                if (node->value == value) {
                    return true;
                }
                node = node->next;
            }
        }
        return false;
    }

    V& get(const K& key) {
        size_t index = hash(key);
        Node* node = table[index];
        while (node != nullptr) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }
        throw std::out_of_range("Key not found");
    }

    const V& get(const K& key) const {
        size_t index = hash(key);
        Node* node = table[index];
        while (node != nullptr) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }
        throw std::out_of_range("Key not found");
    }

    V& operator[](const K& key) {
        return get(key);
    }

    const V& operator[](const K& key) const {
        return get(key);
    }

    void replace(const K& key, const V& value) {
        size_t index = hash(key);
        Node* node = table[index];
        while (node != nullptr) {
            if (node->key == key) {
                node->value = value;
                return;
            }
            node = node->next;
        }
        node = new Node(key, value, table[index]);
        table[index] = node;
        size++;
        if (size > tableSize) {
            resize();
        }
    }

    void remove(const K& key) {
        size_t index = hash(key);
        Node* node = table[index];
        Node* prev = nullptr;
        while (node != nullptr) {
            if (node->key == key) {
                if (prev == nullptr) {
                    table[index] = node->next;
                } else {
                    prev->next = node->next;
                }
                delete node;
                size--;
                return;
            }
            prev = node;
            node = node->next;
        }
        throw std::out_of_range("Key not found");
    }

    void clear() {
        for (size_t i = 0; i < tableSize; i++) {
            Node* node = table[i];
            while (node != nullptr) {
                Node* next = node->next;
                delete node;
                node = next;
            }
            table[i] = nullptr;
        }
        size = 0;
    }

    void print() const {
        for (size_t i = 0; i < tableSize; i++) {
            Node* node = table[i];
            while (node != nullptr) {
                std::cout << node->key << " " << node->value << std::endl;
                node = node->next;
            }
        }
    }

    void put(K key, V value) {
        replace(key, value);
    }

    class Iterator {
    private:
        HashMap* map;
        size_t index;
        Node* node;
    public:
        Iterator(HashMap* map, size_t index, Node* node) {
            this->map = map;
            this->index = index;
            this->node = node;
        }
        Iterator& operator++() {
            if (node != nullptr) {
                node = node->next;
            }
            while (node == nullptr && index < map->tableSize) {
                index++;
                if (index < map->tableSize) {
                    node = map->table[index];
                }
            }
            return *this;
        }
        Iterator operator++(int) {
            Iterator it = *this;
            ++(*this);
            return it;
        }
        std::pair<K, V>& operator*() {
            return node->pair;
        }
        std::pair<K, V>* operator->() {
            return &node->pair;
        }
        bool operator==(const Iterator& other) const {
            return map == other.map && index == other.index && node == other.node;
        }
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() {
        for (size_t i = 0; i < tableSize; i++) {
            if (table[i] != nullptr) {
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