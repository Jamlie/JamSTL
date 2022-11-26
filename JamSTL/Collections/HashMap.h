#pragma once

#include <iostream>
#include <functional>
#include <thread>

#ifndef HASHMAP_H
#define HASHMAP_H

template<typename Keys, typename Values>
class HashMap {
private:
    Keys* KEYS     = nullptr;
    Values* VALUES = nullptr;

    size_t SizeKey     = 0;
    size_t CapacityKey = 0;

    size_t SizeValue     = 0;
    size_t CapacityValue = 0;


    void reAllocateKey(size_t newCapacity) {
        reAllocateValue(newCapacity);
        Keys* newBlock = new Keys[newCapacity];

        if (newCapacity < this->SizeKey) this->SizeKey = newCapacity;

        for (size_t i = 0; i < this->SizeKey; i++) newBlock[i] = std::move(this->KEYS[i]);

        for(size_t i = 0; i < this->SizeKey; i++) this->KEYS[i].~Keys();


        ::operator delete(this->KEYS, newCapacity * sizeof(Keys));
        this->KEYS = newBlock;
        this->CapacityKey = newCapacity;
    }

    void reAllocateValue(size_t newCapacity) {
        Values* newBlock = new Values[newCapacity];

        if (newCapacity < this->SizeValue) this->SizeValue = newCapacity;

        for (size_t i = 0; i < this->SizeValue; i++) newBlock[i] = std::move(this->VALUES[i]);

        for(size_t i = 0; i < this->SizeValue; i++) this->VALUES[i].~Values();


        ::operator delete(this->VALUES, newCapacity * sizeof(Values));
        this->VALUES = newBlock;
        this->CapacityKey = newCapacity;
    }

public:
    HashMap() {
        reAllocateKey(2);
    }

    ~HashMap() { 
        ::operator delete(this->KEYS, this->CapacityKey * sizeof(Keys));
        ::operator delete(this->VALUES, this->CapacityValue * sizeof(Values));
    }

    HashMap(const HashMap& other) {
        this->reAllocateKey(other.CapacityKey);
        this->reAllocateValue(other.CapacityValue);

        this->SizeKey = other.SizeKey;
        this->SizeValue = other.SizeValue;

        for (size_t i = 0; i < this->SizeKey; i++) this->KEYS[i] = other.KEYS[i];
        for (size_t i = 0; i < this->SizeValue; i++) this->VALUES[i] = other.VALUES[i];
    }

    void put(std::pair<Keys, Values> pair) {
        if (this->SizeKey == this->CapacityKey) reAllocateKey(this->CapacityKey * 2);

        this->KEYS[this->SizeKey] = pair.first;
        this->VALUES[this->SizeValue] = pair.second;

        this->SizeKey++;
        this->SizeValue++;
        if(!this->is_sorted()) this->sort();
    }

    void put(const Keys& key, const Values& value) {
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                this->VALUES[i] = value;
                return;
            }
        }

        if(this->SizeKey >= this->CapacityKey) 
            reAllocateKey(this->CapacityKey * 2);
                    
        this->KEYS[this->SizeKey] = key;
        this->VALUES[this->SizeValue] = value;

        this->SizeKey++;
        this->SizeValue++;
        if(!this->is_sorted()) this->sort();
    }

    void put(Keys&& key, Values&& value) {
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                this->VALUES[i] = value;
                return;
            }
        }

        if(this->SizeKey >= this->CapacityKey) 
            reAllocateKey(this->CapacityKey * 2);
                
        this->KEYS[this->SizeKey] = std::move(key);
        this->VALUES[this->SizeValue] = std::move(value);

        this->SizeKey++;
        this->SizeValue++;
        if(!this->is_sorted()) this->sort();
    }

    template<typename... Args>
    Values& emplace(Keys&& key, Args&&... args) {
        if(!this->is_sorted()) this->sort();
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                return this->VALUES[i];
            }
        }

        if(this->SizeKey >= this->CapacityKey) 
            reAllocateKey(this->CapacityKey * 2);

        this->KEYS[this->SizeKey] = std::move(key);
        new(&this->VALUES[this->SizeValue]) Values(std::forward<Args>(args)...);

        this->SizeKey++;
        this->SizeValue++;

        return this->VALUES[this->SizeValue - 1];
    }

    bool remove(const Keys& key) {
        if(!this->is_sorted()) this->sort();
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                for(size_t j = i; j < this->SizeKey - 1; j++) {
                    this->KEYS[j] = std::move(this->KEYS[j + 1]);
                    this->VALUES[j] = std::move(this->VALUES[j + 1]);
                }
                this->SizeKey--;
                this->SizeValue--;
                return true;
            }
        }
        return false;
    }



    bool remove(Keys&& key) {
        if(!this->is_sorted()) this->sort();
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                for(size_t j = i; j < this->SizeKey - 1; j++) {
                    this->KEYS[j] = std::move(this->KEYS[j + 1]);
                    this->VALUES[j] = std::move(this->VALUES[j + 1]);
                }
                this->SizeKey--;
                this->SizeValue--;
                return true;
            }
        }
        return false;
    }
    

    bool replace(const Keys& key, const Values& value) {
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                this->VALUES[i] = value;
                
                return true;
            }
        }
        return false;
    }

    bool putIfAbsent(const Keys& key, const Values& value) {
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                return false;
            }
        }

        this->put(key, value);
        if(!this->is_sorted()) this->sort();
        return true;
    }

    Keys getKey(const Values& value) const {
        for (size_t i = 0; i < this->SizeValue; i++) {
            if(this->VALUES[i] == value) {
                return this->KEYS[i];
            }
        }
        throw std::out_of_range("Value not found");
    }

    size_t size() const { return this->SizeKey; }

    bool containsKey(const Keys& key) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) return true; 
        }
        return false;
    }

    bool containsValue(const Values& value) {
        for (size_t i = 0; i < this->SizeValue; i++) {
            if (this->VALUES[i] == value) return true; 
        }
        return false;
    }

    HashMap<Keys, Values>& operator=(const HashMap<Keys, Values>& other) {
        if (this == &other) return *this;

        this->SizeKey = other.SizeKey;
        this->SizeValue = other.SizeValue;
        this->CapacityKey = other.CapacityKey;
        this->CapacityValue = other.CapacityValue;

        this->KEYS = other.KEYS;
        this->VALUES = other.VALUES;

        return *this;
    }

    HashMap& map(const std::function<Keys(const Keys&, const Values&)>& mapper) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            this->KEYS[i] = mapper(this->KEYS[i], this->VALUES[i]);
        }
        return *this;
    }

    HashMap& map(const std::function<Keys(const Keys&)>& mapper) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            this->KEYS[i] = mapper(this->KEYS[i]);
        }
        return *this;
    }

    HashMap& map(const std::function<Values(const Values&)>& mapper) {
        for (size_t i = 0; i < this->SizeValue; i++) {
            this->VALUES[i] = mapper(this->VALUES[i]);
        }
        return *this;
    }

    HashMap& forEach(const std::function<void(const Keys&, const Values&)>& action) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            action(this->KEYS[i], this->VALUES[i]);
        }
        return *this;
    }

    HashMap& forEach(const std::function<void(const Keys&)>& action) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            action(this->KEYS[i]);
        }
        return *this;
    }

    HashMap& forEach(const std::function<void(const Values&)>& action) {
        for (size_t i = 0; i < this->SizeValue; i++) {
            action(this->VALUES[i]);
        }
        return *this;
    }

    template<typename T>
    HashMap& forEach(const std::function<void(const Keys&, const Values&, T&)>& action, T& t) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            action(this->KEYS[i], this->VALUES[i], t);
        }
        return *this;
    }

    template<typename T>
    HashMap& forEach(const std::function<void(const Keys&, T&)>& action, T& t) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            action(this->KEYS[i], t);
        }
        return *this;
    }

    template<typename T>
    HashMap& forEach(const std::function<void(const Values&, T&)>& action, T& t) {
        for (size_t i = 0; i < this->SizeValue; i++) {
            action(this->VALUES[i], t);
        }
        return *this;
    }

    template<typename T>
    HashMap& forEach(const std::function<void(T&)>& action, T& t) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            action(t);
        }
        return *this;
    }

    bool empty() {
        for(size_t i = 0; i < this->SizeKey; i++) {
            this->KEYS[i].~Keys();
            this->VALUES[i].~Values();
        }
        this->SizeKey = 0;
        this->SizeValue = 0;
        return true;
    }
    
    bool is_empty() {
        if(this->SizeKey == 0) return true;
        return false;
    }


    bool is_sorted() const {
        if(this->size() == 0) return false;
        if(this->size() == 1) return true;

        for(size_t i = 1; i < this->size(); i++) if(this->KEYS[i - 1] > this->KEYS[i]) return false;

        return true;
    }

    bool find(const Values& value) {
        for(size_t i = 0; i < this->SizeValue; i++) {
            if(this->VALUES[i] == value) {
                return true;
            }
        }
        return false;
    }

    bool find(const Keys& key) {
        for(size_t i = 0; i < this->SizeKey; i++) {
            if(this->KEYS[i] == key) {
                return true;
            }
        }
        return false;
    }
    

    Values& operator[](const Keys& key) {
        size_t count = 0;
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                count++;
            }
        }
        if(count == 1) {
            for (size_t i = 0; i < this->SizeKey; i++) {
                if(this->KEYS[i] == key) return this->VALUES[i];
            }
        }

        if(this->SizeKey >= this->CapacityKey)
            reAllocateKey(this->CapacityKey * 2);
        
        this->KEYS[this->SizeKey] = key;
        new(&this->VALUES[this->SizeValue]) Values();

        this->SizeKey++;
        this->SizeValue++;

        if(!this->is_sorted()) this->sort();

        return this->VALUES[this->SizeValue - 1];
    }

    Values& operator[](const Keys& key) const {
        
        for (size_t i = 0; i < this->SizeKey; i++) {
            if(this->KEYS[i] == key) {
                return this->VALUES[i];
            }
        }
        throw std::out_of_range("Key not found");
    }

    Values& operator[](Keys&& key) {
        size_t count = 0;
        for(size_t i = 0; i < this->SizeKey; i++) {
            if (this->KEYS[i] == key) {
                count++;
            }
        }

        if(count == 1) {
            for (size_t i = 0; i < this->SizeKey; i++) {
                if(this->KEYS[i] == key) return this->VALUES[i];
            }
        }

        if(this->SizeKey >= this->CapacityKey)
            reAllocateKey(this->CapacityKey * 2);
        
        this->KEYS[this->SizeKey] = std::move(key);
        new(&this->VALUES[this->SizeValue]) Values();
        
        this->SizeKey++;
        this->SizeValue++;

        return this->VALUES[this->SizeValue - 1];
    }

    Values& operator[](Keys&& key) const {
        for (size_t i = 0; i < this->SizeKey; i++) {
            if(this->KEYS[i] == key) return this->VALUES[i];
        }
        throw std::out_of_range("Key not found");
    }

    friend std::ostream& operator<<(std::ostream& out, HashMap& hash) {
        // if(!hash.is_sorted()) hash.sort();
        if(hash.size() == 1) {
            out << "{" << hash.KEYS[0] << ": " << hash.VALUES[0] << "}\n";
            return out;
        }

        out << "{";
        for (size_t i = 0; i < hash.size(); i++) {
            if(i == 0) out << hash.KEYS[0] << ": " << hash.VALUES[0] << ", ";
            else if (i != hash.size() - 1) out << hash.KEYS[i] << ": " << hash.VALUES[i] << ", ";
            if(i == hash.size() - 1) out << hash.KEYS[i] << ": " << hash.VALUES[i];
        }
        out << "}\n";
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const HashMap& hash) {
        if(!hash->is_sorted()) hash->sort();
        if(hash.size() == 1) {
            out << "{" << hash.KEYS[0] << ": " << hash.VALUES[0] << "}\n";
            return out;
        }

        out << "{";
        for (size_t i = 0; i < hash.size(); i++) {
            if(i == 0) out << hash.KEYS[0] << ": " << hash.VALUES[0] << ", ";
            else if (i != hash.size() - 1) out << hash.KEYS[i] << ": " << hash.VALUES[i] << ", ";
            if(i == hash.size() - 1) out << hash.KEYS[i] << ": " << hash.VALUES[i];
        }
        out << "}\n";
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const HashMap* hash) {
        if(!hash->is_sorted()) hash->sort();
        if(hash->size() == 1) {
            out << "{" << hash->KEYS[0] << ": " << hash->VALUES[0] << "}\n";
            return out;
        }

        out << "{";
        for (size_t i = 0; i < hash->size(); i++) {
            if(i == 0) out << hash->KEYS[0] << ": " << hash->VALUES[0] << ", ";
            else if (i != hash->size() - 1) out << hash->KEYS[i] << ": " << hash->VALUES[i] << ", ";
            if(i == hash->size() - 1) out << hash->KEYS[i] << ": " << hash->VALUES[i];
        }
        out << "}\n";
        return out;
    }

    void sort() {
        for (size_t i = 0; i < this->SizeKey; i++) {
            for (size_t j = 0; j < this->SizeKey; j++) {
                if(this->KEYS[j] > this->KEYS[i]) {
                    std::swap(this->KEYS[i], this->KEYS[j]);
                    std::swap(this->VALUES[i], this->VALUES[j]);
                }
            }
        }
    }

    bool every(std::function<bool(Keys&, Values&)> func) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            if(!func(this->KEYS[i], this->VALUES[i])) return false;
        }
        return true;
    }

    bool some(std::function<bool(Keys&, Values&)> func) {
        for (size_t i = 0; i < this->SizeKey; i++) {
            if(func(this->KEYS[i], this->VALUES[i])) return true;
        }
        return false;
    }


    class iterator {
        public:
            iterator(Keys* keys, Values* values, size_t size) : KEYS(keys), VALUES(values), SIZE(size) {}

            iterator& operator++() {
                this->KEYS++;
                this->VALUES++;
                return *this;
            }

            iterator operator++(int) {
                iterator tmp(*this);
                this->KEYS++;
                this->VALUES++;
                return tmp;
            }

            iterator& operator--() {
                this->KEYS--;
                this->VALUES--;
                return *this;
            }

            iterator operator--(int) {
                iterator tmp(*this);
                this->KEYS--;
                this->VALUES--;
                return tmp;
            }

            bool operator==(const iterator& other) const {
                return this->KEYS == other.KEYS;
            }

            bool operator!=(const iterator& other) const {
                return this->KEYS != other.KEYS;
            }

            bool operator==(const iterator* other) const {
                return this->KEYS == other->KEYS;
            }

            bool operator!=(const iterator* other) const {
                return this->KEYS != other->KEYS;
            }

            bool operator<(const iterator& other) const {
                return this->KEYS < other.KEYS;
            }

            bool operator>(const iterator& other) const {
                return this->KEYS > other.KEYS;
            }

            bool operator<=(const iterator& other) const {
                return this->KEYS <= other.KEYS;
            }

            bool operator>=(const iterator& other) const {
                return this->KEYS >= other.KEYS;
            }

            bool operator<(const iterator* other) const {
                return this->KEYS < other->KEYS;
            }

            bool operator>(const iterator* other) const {
                return this->KEYS > other->KEYS;
            }

            bool operator<=(const iterator* other) const {
                return this->KEYS <= other->KEYS;
            }

            bool operator>=(const iterator* other) const {
                return this->KEYS >= other->KEYS;
            }

            Keys& operator*() {
                return *this->KEYS;
            }

            Keys* operator->() {
                return this->KEYS;
            }

            iterator& operator+(int n) {
                this->KEYS += n;
                this->VALUES += n;
                return *this;
            }

            iterator operator()(int n) {
                this->KEYS += n;
                this->VALUES += n;
                return *this;
            }

            iterator& operator-(int n) {
                this->KEYS -= n;
                this->VALUES -= n;
                return *this;
            }

            iterator& operator+=(int n) {
                this->KEYS += n;
                this->VALUES += n;
                return *this;
            }

            iterator& operator-=(int n) {
                this->KEYS -= n;
                this->VALUES -= n;
                return *this;
            }

            auto operator[](int n) {
                return std::tie(this->KEYS[n], this->VALUES[n]);
            }

            friend std::ostream& operator<<(std::ostream& out, iterator& it) {
                for(size_t i = 0; i < it.SIZE; i++) {
                    out << it.KEYS[i] << ": " << it.VALUES[i] << ", ";
                }
                return out;
            }

        private:
            friend class HashMap;
            friend class const_iterator;
            Keys* KEYS;
            Values* VALUES;
            size_t SIZE;
    };

    class const_iterator {
        public:
            const_iterator(const Keys* keys, const Values* values, size_t size) : KEYS(keys), VALUES(values), SIZE(size) {}

            const_iterator& operator++() {
                this->KEYS++;
                this->VALUES++;
                return *this;
            }

            const_iterator operator++(int) {
                const_iterator tmp(*this);
                this->KEYS++;
                this->VALUES++;
                return tmp;
            }

            const_iterator& operator--() {
                this->KEYS--;
                this->VALUES--;
                return *this;
            }

            const_iterator operator--(int) {
                const_iterator tmp(*this);
                this->KEYS--;
                this->VALUES--;
                return tmp;
            }

            bool operator==(const const_iterator& other) {
                return this->KEYS == other.KEYS;
            }

            bool operator!=(const const_iterator& other) {
                return this->KEYS != other.KEYS;
            }

            bool operator==(const iterator& other) {
                return this->KEYS == other.KEYS;
            }

            bool operator!=(const iterator& other) {
                return this->KEYS != other.KEYS;
            }

            bool operator<(const const_iterator& other) {
                return this->KEYS < other.KEYS;
            }

            bool operator>(const const_iterator& other) {
                return this->KEYS > other.KEYS;
            }

            bool operator<=(const const_iterator& other) {
                return this->KEYS <= other.KEYS;
            }

            bool operator>=(const const_iterator& other) {
                return this->KEYS >= other.KEYS;
            }

            bool operator<(const iterator& other) {
                return this->KEYS < other.KEYS;
            }

            bool operator>(const iterator& other) {
                return this->KEYS > other.KEYS;
            }

            const Keys& operator*() {
                return *this->KEYS;
            }

            const Keys* operator->() {
                return this->KEYS;
            }

            const_iterator operator()(int n) {
                this->KEYS += n;
                this->VALUES += n;
                return *this;
            }

            const_iterator& operator+(int n) {
                this->KEYS += n;
                this->VALUES += n;
                return *this;
            }

            const_iterator& operator-(int n) {
                this->KEYS -= n;
                this->VALUES -= n;
                return *this;
            }
            
            const_iterator& operator+=(int n) {
                this->KEYS += n;
                this->VALUES += n;
                return *this;
            }

            const_iterator& operator-=(int n) {
                this->KEYS -= n;
                this->VALUES -= n;
                return *this;
            }

            auto operator[](int n) {
                return std::tie(this->KEYS[n], this->VALUES[n]);
            }

            friend std::ostream& operator<<(std::ostream& out, const_iterator& it) {
                for(size_t i = 0; i < it.SIZE; i++) {
                    out << it.KEYS[i] << ": " << it.VALUES[i] << ", ";
                }
                return out;
            }

        private:
            friend class HashMap;
            friend class iterator;
            const Keys* KEYS;
            const Values* VALUES;
            size_t SIZE;
    };

    class value_iterator {
        public:
            value_iterator(Values* values, size_t size) : VALUES(values), SIZE(size) {}

            value_iterator& operator++() {
                this->VALUES++;
                return *this;
            }

            value_iterator operator++(int) {
                value_iterator tmp(*this);
                this->VALUES++;
                return tmp;
            }

            value_iterator& operator--() {
                this->VALUES--;
                return *this;
            }

            value_iterator operator--(int) {
                value_iterator tmp(*this);
                this->VALUES--;
                return tmp;
            }

            bool operator==(const value_iterator& other) {
                return this->VALUES == other.VALUES;
            }

            bool operator!=(const value_iterator& other) {
                return this->VALUES != other.VALUES;
            }

            bool operator!=(const value_iterator* other) {
                return this->VALUES != other->VALUES;
            }

            bool operator<(const value_iterator& other) {
                return this->VALUES < other.VALUES;
            }

            bool operator>(const value_iterator& other) {
                return this->VALUES > other.VALUES;
            }

            bool operator<=(const value_iterator& other) {
                return this->VALUES <= other.VALUES;
            }

            bool operator>=(const value_iterator& other) {
                return this->VALUES >= other.VALUES;
            }

            bool operator>(const value_iterator* other) {
                return this->VALUES > other->VALUES;
            }

            bool operator<=(const value_iterator* other) {
                return this->VALUES <= other->VALUES;
            }

            bool operator>=(const value_iterator* other) {
                return this->VALUES >= other->VALUES;
            }

            const Values& operator*() {
                return *this->VALUES;
            }

            const Values* operator->() {
                return this->VALUES;
            }

            value_iterator operator()(int n) {
                this->VALUES += n;
                return *this;
            }

            value_iterator& operator+(int n) {
                this->VALUES += n;
                return *this;
            }   

            value_iterator& operator-(int n) {
                this->VALUES -= n;
                return *this;
            }

            value_iterator& operator+=(int n) {
                this->VALUES += n;
                return *this;
            }

            value_iterator& operator-=(int n) {
                this->VALUES -= n;
                return *this;
            }

            auto operator[](int n) {
                return std::tie(this->VALUES[n]);
            }

            friend std::ostream& operator<<(std::ostream& out, const value_iterator& it) {
                out << "{" << *it.VALUES << "}";
                return out;
            }

        private:
            friend class HashMap;
            friend class iterator;
            Values* VALUES;
            size_t SIZE;
    };

    class const_value_iterator {
        public:
            const_value_iterator(const Values* values, size_t size) : VALUES(values), SIZE(size) {}

            const_value_iterator& operator++() {
                this->VALUES++;
                return *this;
            }

            const_value_iterator operator++(int) {
                const_value_iterator tmp(*this);
                this->VALUES++;
                return tmp;
            }

            const_value_iterator& operator--() {
                this->VALUES--;
                return *this;
            }

            const_value_iterator operator--(int) {
                const_value_iterator tmp(*this);
                this->VALUES--;
                return tmp;
            }

            bool operator==(const const_value_iterator& other) {
                return this->VALUES == other.VALUES;
            }

            bool operator!=(const const_value_iterator& other) {
                return this->VALUES != other.VALUES;
            }

            bool operator!=(const const_value_iterator* other) {
                return this->VALUES != other->VALUES;
            }

            bool operator==(const const_value_iterator* other) {
                return this->VALUES == other->VALUES;
            }

            bool operator<(const const_value_iterator& other) {
                return this->VALUES < other.VALUES;
            }

            bool operator>(const const_value_iterator& other) {
                return this->VALUES > other.VALUES;
            }

            bool operator<=(const const_value_iterator& other) {
                return this->VALUES <= other.VALUES;
            }

            bool operator>=(const const_value_iterator& other) {
                return this->VALUES >= other.VALUES;
            }

            bool operator<(const const_value_iterator* other) {
                return this->VALUES < other->VALUES;
            }

            bool operator>(const const_value_iterator* other) {
                return this->VALUES > other->VALUES;
            }

            bool operator<=(const const_value_iterator* other) {
                return this->VALUES <= other->VALUES;
            }

            bool operator>=(const const_value_iterator* other) {
                return this->VALUES >= other->VALUES;
            }

            const Values& operator*() {
                return *this->VALUES;
            }

            const Values* operator->() {
                return this->VALUES;
            }

            const_value_iterator operator()(int n) {
                this->VALUES += n;
                return *this;
            }

            const_value_iterator& operator+(int n) {
                this->VALUES += n;
                return *this;
            }

            const_value_iterator& operator-(int n) {
                this->VALUES -= n;
                return *this;
            }

            const_value_iterator& operator+=(int n) {
                this->VALUES += n;
                return *this;
            }

            const_value_iterator& operator-=(int n) {
                this->VALUES -= n;
                return *this;
            }
            
            auto operator[](int n) {
                return std::tie(this->VALUES[n].first, this->VALUES[n].second);
            }

        private:
            friend class HashMap;
            friend class iterator;
            const Values* VALUES;
            size_t SIZE;
    };

    value_iterator vbegin() {
        return value_iterator(this->VALUES, this->SizeValue);
    }

    value_iterator vend() {
        return value_iterator(this->VALUES + this->SizeValue, this->SizeValue);
    }

    const_value_iterator vcbegin() const {
        return const_value_iterator(this->VALUES, this->SizeValue);
    }

    const_value_iterator vcend() const {
        return const_value_iterator(this->VALUES + this->SizeValue, this->SizeValue);
    }


    iterator begin() {
        return iterator(this->KEYS, this->VALUES, this->SizeKey);
    }

    iterator end() {
        return iterator(this->KEYS + this->SizeKey, this->VALUES + this->SizeValue, this->SizeKey);
    }

    const_iterator begin() const {
        return const_iterator(this->KEYS, this->VALUES, this->SizeKey);
    }

    const_iterator end() const {
        return const_iterator(this->KEYS + this->SizeKey, this->VALUES + this->SizeValue, this->SizeKey);
    }

    const_iterator cbegin() const {
        return const_iterator(this->KEYS, this->VALUES, this->SizeKey);
    }

    const_iterator cend() const {
        return const_iterator(this->KEYS + this->SizeKey, this->VALUES + this->SizeValue, this->SizeKey);
    }
};


#endif