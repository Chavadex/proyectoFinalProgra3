#include <iostream>
#include "DDList.h"
#include "queue.h"
#include <string>

#include "package.h"
#include "queue.h"
#include "stack.h"

int main()
{
    /*
    int opc, id_package, priorityLevel, trackingCode;
    std::string addressRecipient, recipient, sender, addressSender, nombrePaquete;
    float deliveryDistance;

    std::cout << "Bienvenido al sistema de Logistica de ChavadeXtafeta, ingresa el numero de la opcion deseada" << std::endl;
    std::cin >> opc ;

    switch (opc) {
        case 1: //Gestor de paquetes
            std::cout << "Para agregar un paquete por favor ingresa los siguientes datos" << std::endl;
            std::cout << "Inserta el ID: " << std::endl; std::cin >> id_package;
            std::cout << "Inserta la direccion de entrega" << std::endl; std::cin >> addressRecipient;
            std::cout << "Inserta el nombre del destinatario: " << std::endl; std::cin >> recipient;
            std::cout << "Ingresa direccion de origen: " << std::endl; std::cin >> addressSender;
            std::cout << "Ingresa el nombre del remitente: " << std::endl; std::cin >> sender;
            std::cout << "Ingresa el nivel de prioridad: " << std::endl; std::cin >> priorityLevel;
            std::cout << "Ingresa el codigo de rastreo: " << std::endl; std::cin >> trackingCode;
            std::cout << "Ingresa la distancia de entrega: " << std::endl; std::cin >> deliveryDistance;

            package Paquete1(id_package, addressRecipient, recipient, addressSender, sender, priorityLevel, trackingCode, deliveryDistance);

            std::cout << "Tu paquete de ID:" << Paquete1.getPackageID() << " se ha creado" << std::endl;
/*
            break;
        case 2:
            break;
        case 3:
            break;
    }
    */

#pragma region Prueba de la queue
  /* PRUEBA DE LA QUEUE
    package Paquete1(1, "Su casa", "Juan", "Julian", "Mi casa", 222, 12345, 12.5);
    package Paquete2(2, "Su casitaa", "Sofia", "Elena", "Mi casa", 522, 9865, 2.5);
    package Paquete3(3, "Su hotel", "Martha", "Perez", "Mi canton", 7665, 1234321, 76.5);
    queue<package> camion1;
    camion1.checkPackages();
    camion1.addPackage(Paquete1);
    camion1.checkPackages();
    camion1.checkFirstPackage();
    camion1.addPackage(Paquete2);
    camion1.checkPackages();
    camion1.checkFirstPackage();
    camion1.checkLastPackage();
    camion1.addPackage(Paquete3);
    camion1.checkPackages();
    camion1.checkFirstPackage();
    camion1.takeOutPackage();
    camion1.checkFirstPackage();
    camion1.checkPackages();
*/
#pragma endregion

#pragma region Prueba de Stack
    package Paquete1(1, "Su casa", "Juan", "Julian", "Mi casa", 222, 12345, 12.5);
    package Paquete2(2, "Su casitaa", "Sofia", "Elena", "Mi casa", 522, 9865, 2.5);
    package Paquete3(3, "Su hotel", "Martha", "Perez", "Mi canton", 7665, 1234321, 76.5);
    stack<package> camion1;
    camion1.checkPackages();
    camion1.addPackage(Paquete1);
    camion1.checkPackages();
    camion1.checkFirstPackage();
    camion1.addPackage(Paquete2);
    camion1.checkPackages();
    camion1.checkFirstPackage();
    camion1.checkLastPackage();
    camion1.addPackage(Paquete3);
    camion1.checkPackages();
    camion1.checkFirstPackage();
    camion1.takeOutPackage();
    camion1.checkFirstPackage();
    camion1.checkPackages();
#pragma endregion
    return 0;
}
