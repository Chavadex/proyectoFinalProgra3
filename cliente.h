//
// Created by Salvador Cruz on 20/01/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include<string>
#include <iostream>

class cliente {
public:
    cliente(std::string name, std::string address, int id_customer);

    ~cliente();

    std::string getName() const;
    std::string getAddress() const;
    int getId_user() const;

    void setName(std::string name);
    void setAddress(std::string address);
    void setId_customer(int id_customer);

private:
    std::string name;
    std::string address;
    int id_customer;
};



#endif //CLIENTE_H
