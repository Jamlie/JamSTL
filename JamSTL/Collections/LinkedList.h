#pragma once


#ifndef JAMSTL_LINKEDLIST_H
#define JAMSTL_LINKEDLIST_H 1
#include "../Macros.h"
#include "../Datatypes.h"
#include <iterator>

JAMSTL_NAMESPACE_BEGIN

    template<typename Type>
    struct Node {
        Type value;
        Node<Type>* next;
    };

    template<typename Type>
    class LinkedList {
        Node<Type> *head;
        Node<Type> *tail;
        size_t Size;
    public:
        LinkedList() : head(nullptr), tail(nullptr), Size(1){};
        LinkedList(const LinkedList<Type>& other) : head(nullptr), tail(nullptr), Size(0) {
            for(size_t i = 0; i < other.size(); i++) {
                push(other.get(i));
            }
        }
        LinkedList(LinkedList<Type>&& other) : head(other.head), tail(other.tail), Size(other.size()) {
            other.head = nullptr;
            other.tail = nullptr;
            other.Size = 0;
        }
        ~LinkedList() {
            Node<Type> *current = this->head;
            while(current != nullptr) {
                Node<Type> *temp = current;
                current = current->next;
                delete temp;
            }
        }

        Type push(const Type& value) {
            Node<Type> *node = new Node<Type>();
            node->value = value;
            node->next = nullptr;
            if(this->head == nullptr) {
                this->head = node;
                this->tail = node;
                return value;
            }
            this->tail->next = node;
            this->tail = node;
            this->Size++;
            return value;
        }

        Type insert(const size_t& index, const Type& value) {
            if(index < 0 || index > this->Size) {
                return value;
            }
            Node<Type> *node = new Node<Type>();
            node->value = value;
            node->next = nullptr;
            if(index == 0) {
                node->next = this->head;
                this->head = node;
                return value;
            }
            Node<Type> *current = this->head;
            for(int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
            this->Size++;
            return value;
        }
        
        Type pop() {
            if(this->head == nullptr) {
                return 0;
            }
            Node<Type> *temp = this->head;
            this->head = this->head->next;
            this->Size--;
            Type value = temp->value;
            delete temp;
            return value;
        }

        Type pop(const size_t& index) {
            if(index < 0 || index >= this->Size) {
                return this->head->value;
            }
            if(index == 0) {
                Node<Type> *temp = this->head;
                this->head = this->head->next;
                this->Size--;
                Type value = temp->value;
                delete temp;
                return value;
            }
            Node<Type> *current = this->head;
            for(int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<Type> *temp = current->next;
            current->next = temp->next;
            this->Size--;
            Type value = temp->value;
            delete temp;
            return value;
        }

        Type get(const unsigned int& index) const{
            if(index < 0 || index >= this->Size) {
                return this->head->value;
            }
            Node<Type> *current = this->head;
            for(int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->value;
        }

        Type getFirst() const {
            return this->head->value;
        }

        Type getLast() const {
            return this->tail->value;
        }

        void empty() {
            Node<Type> *current = this->head;
            while(current != nullptr) {
                Node<Type> *temp = current;
                current = current->next;
                delete temp;
            }
            this->head = nullptr;
            this->tail = nullptr;
            this->Size = 0;
        }

        bool isEmpty() {
            return this->Size == 0;
        }

        size_t size() const {
            return this->Size;
        }

        Type remove(const Type& value) {
            if(this->head == nullptr) {
                return 0;
            }
            if(this->head->value == value) {
                Node<Type> *temp = this->head;
                this->head = this->head->next;
                this->Size--;
                Type value = temp->value;
                delete temp;
                return value;
            }
            Node<Type> *current = this->head;
            while(current->next != nullptr) {
                if(current->next->value == value) {
                    Node<Type> *temp = current->next;
                    current->next = current->next->next;
                    this->Size--;
                    Type value = temp->value;
                    delete temp;
                    return value;
                }
                current = current->next;
            }
            return this->tail->value;
        }

        Type removeAll(const Type& value) {
            if(this->head == nullptr) {
                return this->tail->value;
            }
            int i;
            for(i = 0; i < this->Size; i++) {
                if(this->get(i) == value) {
                    this->remove(value);
                }
            }

            return this->tail->value;
        }

        size_t indexOf(const Type& value) {
            if(this->head == nullptr) {
                return -1;
            }
            if(this->head->value == value) {
                return 0;
            }
            Node<Type> *current = this->head;
            for(int i = 0; i < this->Size; i++) {
                if(current->value == value) {
                    return i;
                }
                current = current->next;
            }
            return -1;
        }

        bool contains(const Type& value) {
            if(this->head == nullptr) {
                return false;
            }
            if(this->head->value == value) {
                return true;
            }
            Node<Type> *current = this->head;
            for(int i = 0; i < this->Size; i++) {
                if(current->value == value) {
                    return true;
                }
                current = current->next;
            }
            return false;
        }

        LinkedList copy() {
            LinkedList<Type> list;
            Node<Type> *current = this->head;
            while(current != nullptr) {
                list.push(current->value);
                current = current->next;
            }
            return list;
        }

        LinkedList& operator=(const LinkedList& list) {
            this->empty();
            Node<Type> *current = list.head;
            while(current != nullptr) {
                this->push(current->value);
                current = current->next;
            }
            return *this;
        }

        LinkedList& operator=(LinkedList&& list) {
            this->empty();
            this->head = list.head;
            this->tail = list.tail;
            this->Size = list.Size;
            list.head = nullptr;
            list.tail = nullptr;
            list.Size = 0;
            return *this;
        }

        LinkedList& operator+=(const LinkedList& list) {
            Node<Type> *current = list.head;
            while(current != nullptr) {
                this->push(current->value);
                current = current->next;
            }
            return *this;
        }

        LinkedList& operator+=(LinkedList&& list) {
            Node<Type> *current = list.head;
            while(current != nullptr) {
                this->push(current->value);
                current = current->next;
            }
            list.head = nullptr;
            list.tail = nullptr;
            list.Size = 0;
            return *this;
        }

        LinkedList& operator+=(const Type& value) {
            this->push(value);
            return *this;
        }

        LinkedList& operator+=(Type&& value) {
            this->push(value);
            return *this;
        }

        LinkedList& operator-=(const Type& value) {
            this->remove(value);
            return *this;
        }

        LinkedList& operator--() {
            this->pop();
            return *this;
        }

        LinkedList& operator--(int) {
            this->pop();
            return *this;
        }

        LinkedList operator+(const LinkedList& list) {
            LinkedList<Type> newList = this->copy();
            Node<Type> *current = list.head;
            while(current != nullptr) {
                newList.push(current->value);
                current = current->next;
            }
            return newList;
        }

        LinkedList operator+(LinkedList&& list) {
            LinkedList<Type> newList = this->copy();
            Node<Type> *current = list.head;
            while(current != nullptr) {
                newList.push(current->value);
                current = current->next;
            }
            list.head = nullptr;
            list.tail = nullptr;
            list.Size = 0;
            return newList;
        }

        LinkedList operator+(const Type& value) {
            LinkedList<Type> newList = this->copy();
            newList.push(value);
            return newList;
        }

        bool operator==(const LinkedList& list) {
            if(this->Size != list.Size) {
                return false;
            }
            Node<Type> *current = this->head;
            Node<Type> *current2 = list.head;
            while(current != nullptr) {
                if(current->value != current2->value) {
                    return false;
                }
                current = current->next;
                current2 = current2->next;
            }
            return true;
        }

        bool operator!=(const LinkedList& list) {
            return !(*this == list);
        }

        class Iterator : public std::iterator<std::forward_iterator_tag, Type> {
            public:
                Iterator(Node<Type> *node) {
                    this->node = node;
                }

                Iterator& operator++() {
                    this->node = this->node->next;
                    return *this;
                }

                Iterator operator++(int) {
                    Iterator temp = *this;
                    this->node = this->node->next;
                    return temp;
                }

                Type& operator*() {
                    return this->node->value;
                }

                bool operator==(const Iterator& iterator) {
                    return this->node == iterator.node;
                }

                bool operator!=(const Iterator& iterator) {
                    return !(*this == iterator);
                }

            private:
                Node<Type> *node;
        };

        Iterator begin() {
            return Iterator(this->head);
        }

        Iterator begin() const {
            return Iterator(this->head);
        }

        Iterator end() {
            return Iterator(nullptr);
        }

        Iterator end() const {
            return Iterator(nullptr);
        }
    };

JAMSTL_NAMESPACE_END

#endif