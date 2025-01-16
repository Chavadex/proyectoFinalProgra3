//
// Created by Salvador Cruz on 15/01/2025.
//

#include "packageManager.h"
#include <iostream>
#include "package.h"


packageManager::packageManager() {

}

void packageManager::obtainData() {
    std::cout << "Para agregar un paquete por favor ingresa los siguientes datos" << std::endl;
    std::cout << "Inserta el ID: " << std::endl; std::cin >> id_package;
    std::cout << "Inserta la direccion de entrega" << std::endl; std::cin >> addressRecipient;
    std::cout << "Inserta el nombre del destinatario: " << std::endl; std::cin >> recipient;
    std::cout << "Ingresa direccion de origen: " << std::endl; std::cin >> addressSender;
    std::cout << "Ingresa el nombre del remitente: " << std::endl; std::cin >> sender;
    std::cout << "Ingresa el nivel de prioridad: " << std::endl; std::cin >> priorityLevel;
    std::cout << "Ingresa el codigo de rastreo: " << std::endl; std::cin >> trackingCode;
    std::cout << "Ingresa la distancia de entrega: " << std::endl; std::cin >> deliveryDistance;

}

int packageManager::getId() const {
    return id_package;
}