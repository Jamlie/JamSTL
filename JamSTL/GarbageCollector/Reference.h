#pragma once

#ifndef JAMSTL_REFERENCE_H
#define JAMSTL_REFERENCE_H
#include "../Macros.h"
#include "../Object.h"
#include "../String.h"
#include "../Collections/HashMap.h"

JAMSTL_NAMESPACE_BEGIN

    
    template <class T>
    class Reference extends Object {
        private:
            T* ptr;
            static HashMap<int, int> refCount;
            static HashMap<T, T*> map;
            static int hash(const T& value) {
                return String::hashCode(String::valueOf(value));
            }
                        
        public:
            Reference() {
                this->ptr = nullptr;
            }

            Reference(const T& value) {
                if(map.containsKey(value)) {
                    ptr = map.get(value);
                    refCount.put(hash(value), refCount.get(hash(value)) + 1);
                } else {
                    ptr = new T(value);
                    map.put(value, ptr);
                    refCount.put(hash(value), 1);
                }
            }

            Reference(T* value) {
                if(map.containsKey(*value)) {
                    ptr = map.get(*value);
                    refCount.put(hash(*value), refCount.get(hash(*value)) + 1);
                } else {
                    ptr = value;
                    map.put(*value, ptr);
                    refCount.put(hash(*value), 1);
                }
            }

            Reference(T&& value) {
                if(map.containsKey(value)) {
                    ptr = map.get(value);
                    refCount.put(hash(value), refCount.get(hash(value)) + 1);
                } else {
                    ptr = new T(value);
                    map.put(value, ptr);
                    refCount.put(hash(value), 1);
                }
            }

            Reference(const Reference<T>& ref) {
                ptr = ref.ptr;
                if(ptr != nullptr) {
                    refCount.put(hash(*ptr), refCount.get(hash(*ptr)) + 1);
                }
            }

            Reference(Reference<T>&& ref) {
                ptr = ref.ptr;
                ref.ptr = nullptr;
            }

            ~Reference() {
                if(ptr != nullptr) {
                    int hash = String::hashCode(String::valueOf(*ptr));
                    int count = refCount.get(hash);
                    if(count == 1) {
                        refCount.remove(hash);
                        map.remove(*ptr);
                        ::operator delete(ptr);
                        this->ptr = nullptr;
                    } else {
                        refCount.put(hash, count - 1);
                        this->ptr = nullptr;
                    }
                }
            }

            Reference<T>& operator=(const Reference<T>& ref) {
                if(ptr != nullptr) {
                    int hash = String::hashCode(String::valueOf(*ptr));
                    int count = refCount.get(hash);
                    if(count == 1) {
                        refCount.remove(hash);
                        map.remove(*ptr);
                        delete ptr;
                    } else {
                        refCount.put(hash, count - 1);
                    }
                }
                
                ptr = ref.ptr;
                if(ptr != nullptr) {
                    refCount.put(hash(*ptr), refCount.get(hash(*ptr)) + 1);
                }
                return *this;
            }

            Reference<T>& operator=(Reference<T>&& ref) {
                if(ptr != nullptr) {
                    int hash = String::hashCode(String::valueOf(*ptr));
                    int count = refCount.get(hash);
                    if(count == 1) {
                        refCount.remove(hash);
                        map.remove(*ptr);
                        delete ptr;
                    } else {
                        refCount.put(hash, count - 1);
                    }
                }
                
                ptr = ref.ptr;
                ref.ptr = nullptr;
                return *this;
            }

            Reference<T>& operator=(const T& value) {
                if(ptr != nullptr) {
                    int hash = String::hashCode(String::valueOf(*ptr));
                    int count = refCount.get(hash);
                    if(count == 1) {
                        refCount.remove(hash);
                        map.removeByHashValue(hash);
                        delete ptr;
                    } else {
                        refCount.put(hash, count - 1);
                    }
                }

                if(map.containsKey(value)) {
                    ptr = map.get(value);
                    refCount.put(hash(value), refCount.get(hash(value)) + 1);
                } else {
                    ptr = new T(value);
                    map.put(value, ptr);
                    refCount.put(hash(value), 1);
                }
                return *this;
            }

            Reference<T>& operator=(T* value) {
                if(ptr != nullptr) {
                    int hash = String::hashCode(String::valueOf(*ptr));
                    int count = refCount.get(hash);
                    if(count == 1) {
                        refCount.remove(hash);
                        map.remove(*ptr);
                        delete ptr;
                    } else {
                        refCount.put(hash, count - 1);
                    }
                }

                if(map.containsKey(*value)) {
                    ptr = map.get(*value);
                    refCount.put(hash(*value), refCount.get(hash(*value)) + 1);
                } else {
                    ptr = value;
                    map.put(*value, ptr);
                    refCount.put(hash(*value), 1);
                }
                return *this;
            }

            Reference<T>& operator=(T&& value) {
                if(ptr != nullptr) {
                    int hash = String::hashCode(String::valueOf(*ptr));
                    int count = refCount.get(hash);
                    if(count == 1) {
                        refCount.remove(hash);
                        map.remove(*ptr);
                        delete ptr;
                    } else {
                        refCount.put(hash, count - 1);
                    }
                }

                ptr = map.get(value);
                if(ptr == nullptr) {
                    ptr = new T(value);
                    map.put(value, ptr);
                    refCount.put(hash(value), 1);
                } else {
                    refCount.put(hash(value), refCount.get(hash(value)) + 1);
                }
                return *this;
            }


            void removeReference() {
                this->ptr = nullptr;
            }


            const T& operator*() const {
                return *ptr;
            }

            T& operator[](int index) {
                return ptr[index];
            }

            const T& operator[](int index) const {
                return ptr[index];
            }



            T useType() const {
                return *ptr;
            }

            bool operator==(const Reference<T>& ref) const {
                return ptr == ref.ptr;
            }

            bool operator!=(const Reference<T>& ref) const {
                return ptr != ref.ptr;
            }

            bool operator==(const T& value) const {
                return *ptr == value;
            }

            bool operator!=(const T& value) const {
                return *ptr != value;
            }

            bool operator==(const T* value) const {
                return ptr == value;
            }

            bool operator!=(const T* value) const {
                return ptr != value;
            }

            bool equalReference(const Reference<T>& ref) const {
                return ptr == ref.ptr;
            }

            bool equalValue(const T& value) const {
                return *ptr == value;
            }

            String valueOf() const {
                return String::valueOf(*ptr);
            }

            static usize GetSizeOfMap() {
                return map.size();
            }
            
            usize getSizeOfMap() const {
                return map.size();
            }

            static usize GetSizeOfRefCount() {
                return refCount.size();
            }

            usize getSizeOfRefCount() const {
                return refCount.size();
            }
    };

    template <class T>
    HashMap<int, int> Reference<T>::refCount = HashMap<int, int>();

    template <class T>
    HashMap<T, T*> Reference<T>::map = HashMap<T, T*>();


JAMSTL_NAMESPACE_END


#endif