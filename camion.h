//
// Created by Salvador Cruz on 17/01/2025.
//

#ifndef CAMION_H
#define CAMION_H
#include <string>
#include <iostream>
#include "package.h"
#include "DDList.h"



class camion {
public:
    camion(DDList<package> packages) : packages(packages) {}

    void addPackageToTruck() {
        std::cout << "Para agregar un paquete por favor ingresa los siguientes datos" << std::endl;


        std::cout << "Inserta el ID: " << std::endl;
        std::cin >> id_package;
        std::cin.ignore();


        std::cout << "Inserta la direccion de entrega" << std::endl;
        std::getline(std::cin, addressRecipient);


        std::cout << "Inserta el nombre del destinatario: " << std::endl;
        std::getline(std::cin, recipient);


        std::cout << "Ingresa direccion de origen: " << std::endl;
        std::getline(std::cin, addressSender);


        std::cout << "Ingresa el nombre del remitente: " << std::endl;
        std::getline(std::cin, sender);


        std::cout << "Ingresa el nivel de prioridad: " << std::endl;
        std::cin >> priorityLevel;
        std::cin.ignore();


        std::cout << "Ingresa el codigo de rastreo: " << std::endl;
        std::cin >> trackingCode;
        std::cin.ignore();


        std::cout << "Ingresa la distancia de entrega: " << std::endl;
        std::cin >> deliveryDistance;
        std::cin.ignore();


        package newPackage(id_package, addressRecipient, recipient, addressSender, sender, priorityLevel, trackingCode, deliveryDistance);

        packages.addObject(newPackage);
        std::cout << "Se agrego el paquete con ID: " << newPackage.getPackageID();

    }

    void checkTruck() {
        std::cout<<"A continuacion los paquetes del camion" << std::endl;
        packages.print();
    }
private:
    DDList<package> packages;
    int  id_package, priorityLevel, trackingCode, counter;
    std::string addressRecipient, recipient, sender, addressSender, nombrePaquete;
    float deliveryDistance;
};


#endif //CAMION_H
