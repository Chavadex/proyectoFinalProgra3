//
// Created by Salvador Cruz on 16/01/2025.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include "package.h"

template<typename T>

class queue {
public:
    struct Node {
        package data;
        Node* next;

        explicit Node(const T& data, Node *next = nullptr)
                : data(data), next(next) {}

    };

    queue() : head(nullptr), tail(nullptr){}

    ~queue() {
        //Destructor
    }

    void addPackage(const package& data) {
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void takeOutPackage() {
        if(head == nullptr) {
            std::cout << "No hay paquetes que retirar" << std::endl;
        } else {
            Node* oldNode = head;
            head = head->next;
            std::cout << "Se retiro el paquete con ID: " << oldNode->data.getPackageID() << std::endl;
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
            std::cout << "Solo hay un paquete en el camion con ID: " << head->data.getPackageID() << std::endl;
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
        std::cout << "El ultimo paquete agregado ha sido el de ID: " << tail->data.getPackageID() << std::endl;
    }

private:
    Node* head;
    Node* tail;
};



#endif //QUEUE_H
