//
// Created by Salvador Cruz on 12/01/2025.
//

#ifndef DDLIST_H
#define DDLIST_H

#include <iostream>
#include <string>
#include "package.h"

template<typename T>

class DDList {
public:
    struct Node {
        package data;
        Node* next;
        Node* prev;

        explicit Node(const T& data, Node *next = nullptr, Node *prev = nullptr)
                : data(data), next(next), prev(prev) {}
    };

    class iterator {
    public:
        explicit iterator(Node *node = nullptr) : node(node) {}

        T& operator*() {
                return node->data;

        }

        iterator& operator++() {
            if (node) {
                node = node->next;
            }
            return *this;
        }

        iterator& operator--() {

            if (node) {
                node = node->prev;
            }
            return *this;

        }

        bool operator==(const iterator& other) const {
            return node == other.node; // Missing implementation
        }

        bool operator!=(const iterator& other) const {
            return node != other.node;// Missing implementation
        }

        Node* getNode() const {
            return node;
        }

    private:
        Node* node;
    };

    DDList() : head(nullptr), tail(nullptr) {}

    ~DDList() {
        clear();
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator();
    }

    void addObject(const package& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void push_back(const T& data) {
        Node *newNode = new Node(data);
        if(tail == nullptr) {
            tail = newNode;
            head = tail;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == nullptr) {
            tail == nullptr;
        }
        if(head) {
            Node *temp = head;
            Node *temp2 = head->next->prev;
            head = head->next;
            head->prev = nullptr;
        }
       // print();
    }

    void pop_back() {
        if(tail){
            if (tail == head) {
                delete tail;
                tail = head = nullptr;
            }

            if (head != tail) {
                Node *tempNode = tail->prev;
                tail = tempNode;
                tail->next = nullptr;
            }

        }
    }

    void insert(int index, const T& data) {
        if(index == 0) {
            push_front(data);
        } else {
            auto it = begin();
            for (int i = 0; i < index && it != end(); i++) {
                ++it;
            }
            if(it != end()) {
                Node *newNode = new Node(data, it.getNode(), it.getNode()->prev);
                it.getNode()->prev->next = newNode;
                it.getNode()->prev = newNode;
               // it.getNode()->prev->next = newNode;
                //newNode->prev = it.node;
            }
            if (it == end()) {
                push_back(data);
            }
        }
    }

    void erase(int index) {
        if(index == 0) {
            pop_front();
           // print();
        } else {
            Node *temp = head;
            for (int i = 0; i < index  && temp->next != nullptr; i++) {
                temp = temp->next;
            }
            if (temp !=nullptr) {
                Node *nodeToDelete = temp;
                if(nodeToDelete == tail) {
                    pop_back();
                } else {
                    nodeToDelete->next->prev = nodeToDelete->prev;
                    nodeToDelete->prev->next = nodeToDelete->next;
                    delete nodeToDelete;
                }

            }
        }
        //print();
    }

    void clear() {
        while (head) {
            pop_back();
        }

    }

    void print() const {
        Node* temp = head;
        while (temp) {
            std::cout << "El ID del paquete es: " << temp->data.getPackageID() << "\n";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void print_reverse() const {
        Node *temp = tail;
        while (temp) {
            std::cout << "El ID del paquete es: " << temp->data << "\n";
            temp = temp->prev;
        }
    }

private:
    Node* head;
    Node* tail;
};



#endif //DDLIST_H
