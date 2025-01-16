//
// Created by Salvador Cruz on 16/01/2025.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "package.h"

template<typename T>

class stack {
public:
    struct Node {
        T data;
        Node* next;

        explicit Node(const T& data, Node *next = nullptr)
                : data(data), next(next) {}

    };

    stack() : head(nullptr), tail(nullptr){}

    ~stack(){
        //Destructor
    }

    void addPackage(const T& data) {
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void takeOutPackage() {
        if(head == nullptr) {
            std::cout << "No hay paquetes que retirar" << std::endl;
        } else {
            Node* oldNode = head;
            head = head->next;
            std::cout << "Se retiro el paquete con ID: " << oldNode->data.getPackageID() << std::endl;
            delete oldNode;
        }
    }

    void checkPackages() {
        if(head == nullptr) {
            std::cout << "El camion esta vacio" <<std::endl;
            return;
        }
        Node* temp = head;
        std::cout << "Los paquetes que aun se encuentran en el camion son: " << std::endl;
        while (temp) {
            std::cout << "ID: " << temp->data.getPackageID() << "\n";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void checkFirstPackage() {
        if(head == nullptr) {
            std::cout << "No hay paquetes en el camion" << std::endl;
            return;
        }
        else if(head == tail) {
            std::cout << "Solo hay un paquete en la pila con ID: " << head->data.getPackageID() << std::endl;
            return;
        }
        std::cout << "El siguiente paquete para retirar es el de ID: " << head->data.getPackageID() << std::endl;
    }

    void checkLastPackage() {
        if(head == nullptr) {
            std::cout << "No hay paquetes en el camion" << std::endl;
            return;
        }
        else if(head == tail) {
            std::cout << "Solo hay un paquete en el camion con ID: " << head->data.getPackageID() << std::endl;
            return;
        }
        std::cout << "El ultimo paquete para retirares : " << tail->data.getPackageID() << std::endl;
    }

private:
    Node* head;
    Node* tail;
};



#endif //STACK_H
