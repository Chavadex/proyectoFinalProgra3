//
// Created by Salvador Cruz on 20/01/2025.
//

#include "cliente.h"

cliente::cliente(std::string name, std::string address, int id_customer)  : name(name), address(address), id_customer(id_customer) {}

cliente::~cliente() {
    //Destructor
}

std::string cliente::getName() const {
    return name;
}

std::string cliente::getAddress() const {
    return address;
}

int cliente::getId_user() const {
    return id_customer;
}

void cliente::setName(std::string name) {
    this->name = name;
}

void cliente::setAddress(std::string address) {
    this->address=address;
}

void cliente::setId_customer(int id_customer) {
    this->id_customer=id_customer;
}






