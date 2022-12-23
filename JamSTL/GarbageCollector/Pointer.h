#pragma once

#ifndef JAMSTL_POINTER_H
#define JAMSTL_POINTER_H
#include "../Macros.h"
#include "../Object.h"
#include "../String.h"
#include "../PrintStream.h"

JAMSTL_NAMESPACE_BEGIN

    template <class T>
    class Pointer extends Object {
        private:
            T* ptr;
            int count = 0;
        public:
            Pointer() : ptr(nullptr) {};
    
            Pointer(T* ptr) : ptr(ptr) {}

            Pointer(const T& other) {
                this->ptr = new T(other);
            }

            Pointer(T&& other) {
                this->ptr = new T(other);
            }

            Pointer(const Pointer& other) {
                this->ptr = other.ptr;
                count++;
            }

            Pointer(Pointer* other) {
                this->ptr = other->ptr;
                count++;
            }

            Pointer(Pointer&& other) {
                this->ptr = other.ptr;
                other.ptr = nullptr;
            }

            ~Pointer() {
                if(count != 0) {
                    count--;
                    this->ptr = nullptr;
                } else {
                    destroy();
                }
            }


            void destroyArray() {
                if(this->ptr != nullptr) {
                    ::operator delete[](this->ptr);
                }
                this->ptr = nullptr;
            }

            void destroy() {
                if(this->ptr != nullptr) {
                    delete this->ptr;
                }
                this->ptr = nullptr;
            }

            // operator+
            Pointer operator+(int num) {
                return Pointer(this->ptr + num);
            }


            fun getAddress() const {
                return ptr;
            }

            fun getAddress() {
                return ptr;
            }
            
            Pointer& operator=(const Pointer& other) {
                if(count != 0) { this->count = 0; this->ptr = nullptr; }
                if(ptr != nullptr) { this->ptr->~T(); this->ptr = nullptr; }
                ptr = other.ptr;
                count++;
                return *this;
            }

            Pointer& operator=(const T& other) {
                if(count != 0) { this->count = 0; this->ptr = nullptr; }
                if(ptr != nullptr) this->ptr->~T();
                ptr = new T(other);
                return *this;
            }

            Pointer& operator=(const Pointer* other) {
                if(count != 0) { this->count = 0; this->ptr = nullptr; }
                if(ptr != nullptr) { this->ptr->~T(); this->ptr = nullptr; }
                ptr = other->ptr;
                count++;
                return *this;
            }

            Pointer& operator=(T* other) {
                if(count != 0) { this->count = 0; this->ptr = nullptr; }
                if(ptr != nullptr) { this->ptr->~T(); this->ptr = nullptr; }
                ptr = other;
                return *this;
            }

            Pointer& operator=(Pointer&& other) {
                if(count != 0) { this->count = 0; this->ptr = nullptr; }
                if(ptr != nullptr) { this->ptr->~T(); this->ptr = nullptr; }
                ptr = other.ptr;
                other.ptr = nullptr;
                return *this;
            }

            Pointer& operator=(T&& other) {
                if(count != 0) { this->count = 0; this->ptr = nullptr; }
                if(ptr != nullptr) { this->ptr->~T(); this->ptr = nullptr; }
                ptr = new T(other);
                return *this;
            }



            void* operator new(size_t size) {
                return ::operator new(size);
            }

            void* operator new[](size_t size) {
                return ::operator new[](size);
            }

            void operator delete(void* ptr) {
                ::operator delete(ptr);
            }

            void operator delete[](void* ptr) {
                ::operator delete[](ptr);
            }

            T& operator[](usize index) {
                return ptr[index];
            }

            const T& operator[](usize index) const {
                return ptr[index];
            }

            template<class U>
            Pointer<U> cast() {
                return Pointer<U>((U*)ptr);
            }


            T* operator&() {
                return ptr;
            }

            T* operator&() const {
                return ptr;
            }



            T* operator->() {
                return ptr;
            }

            const T* operator->() const {
                return ptr;
            }

            T& operator*() {
                return *ptr;
            }

            const T& operator*() const {
                return *ptr;
            }

            String valueOf() const {
                return String::valueOf(*ptr);
            }

            String valueOf() {
                return String::valueOf(*ptr);
            }
            

            Pointer operator*(const Pointer& pointer) = delete;



            bool operator==(const Pointer& other) const {
                return this->ptr == other.ptr;
            }

            bool operator!=(const Pointer& other) const {
                return this->ptr != other.ptr;
            }

            bool operator==(const Pointer* other) const {
                return this->ptr == other->ptr;
            }

            bool operator!=(const Pointer* other) const {
                return this->ptr != other->ptr;
            }

            bool operator==(const T* other) const {
                return this->ptr == other;
            }

            bool operator!=(const T* other) const {
                return this->ptr != other;
            }

            bool operator==(const T& other) const {
                return *this->ptr == other;
            }

            bool operator!=(const T& other) const {
                return *this->ptr != other;
            }

            bool equalReference(const Pointer& other) const {
                return this->ptr == other.ptr;
            }

            int getCount() const {
                return this->count;
            }

            bool isNull() const {
                return this->ptr == nullptr;
            }

            bool operator!() const {
                return this->ptr == nullptr;
            }

            friend PrintStream& operator<<(PrintStream& out, const Pointer& ptr) {
                out << *ptr.ptr;
                return out;
            }

            friend PrintStream& operator<<(PrintStream& out, const Pointer* ptr) {
                out << *ptr->ptr;
                return out;
            }

            friend PrintStream& operator<<(PrintStream& out, const Pointer&& ptr) {
                out << *ptr.ptr;
                return out;
            }

            friend PrintStream& println(PrintStream& out, const Pointer& ptr) {
                out << *ptr.ptr << "\n";
                return out;
            }

            friend PrintStream& println(PrintStream& out, const Pointer* ptr) {
                out << *ptr->ptr << "\n";
                return out;
            }

            friend PrintStream& println(PrintStream& out, const Pointer&& ptr) {
                out << *ptr.ptr << "\n";
                return out;
            }

    };

JAMSTL_NAMESPACE_END


#endif