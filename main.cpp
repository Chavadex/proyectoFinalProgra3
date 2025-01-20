#include <iostream>
#include <string>


#include "camion.h"
#include "package.h"
#include "queue.h"
#include "stack.h"
#include "DDList.h"
#include "AVLTree.h"
#include "cliente.h"

//Aqui inicializo las clases que he creado para que pueda usarlas en el main

package createPackage();
void addClient(AVLTree& tree);

int main()
{

    int opc, inputQueue, inputCamion, inputStack;
    std::string addressRecipient, recipient, sender, addressSender, nombrePaquete;
    DDList<package> List;
    camion miCamion(List);
    queue<package> miQueue;
    stack<package> miStack;

    do {
        std::cout << "Bienvenido al sistema de Logistica de ChavadeXtafeta, ingresa el numero de la opcion deseada" << std::endl;
        std::cin >> opc ; //Este input selecciona la opcion del usuario para poder ver que parte del codigo se ejecutara.
        switch (opc) {
            case 1: //Gestor de paquetes, simula una carga de camion en donde mediante una lista enlazada doble podemos verificar cuales son los paquetes que hay en
                    //el camion y retirar o anadir mas
                do {
                    std::cout << "Simulacion de camion de carga; ingresa la opcion deseada: \n 1. Agregar Paquete "
                                 "\n 2. Revisar el contenido del camion \n 3. Retirar un paquete \n 4. Vovler al menu." <<std::endl;
                    std::cin >> inputCamion;
                    switch (inputCamion) {

                        case 1:
                            miCamion.addPackageToTruck();
                        break;
                        case 2:
                            miCamion.checkTruck();
                        break;
                    }
                 } while (inputCamion != 4);
            break;

            case 2: //Queue. Simula que los paquetes se van cargando en fila, lo que respeta el principio de FIFO (First Int, Fist Out), donde podemos anadir
                    //mas paquetes si los necesitamos, verificar cual es el que saldria siguiente y cual es el que saldria de ultimo, ademas de poder revisar
                    //los paquetes actuales.
                do {
                    std::cout << "Sistema de simulacion de fila; ingresa la opcion deseada: \n" << "1. Agregar paquete a la fila\n "
                        "2. Revisar que paquetes hay en la fila\n 3. Revisar el primer paquete para sacar\n 4. Checar el ultimo paquete agregado\n 5. Volver al menu." << std::endl;
                    std::cin >> inputQueue;
                    switch (inputQueue) {
                        case 1:
                            miQueue.addPackage(createPackage());
                            miQueue.checkPackages();
                        break;
                        case 2:
                            miQueue.checkPackages();
                            break;
                        case 3:
                            miQueue.checkFirstPackage();
                            break;
                        case 4:
                            miQueue.checkLastPackage();
                            break;
                    }
                } while (inputQueue != 5);
            break;

            case 3: //Stack. Simula los paquetes como si etsuvieran en una pila, respetando el principio de FILO (First In, Last Out), donde podemos anadir
                    //mas paquetes si los necesitamos, verificar cual es el que saldria siguiente y cual es el que saldria de ultimo, ademas de poder revisar
                    //los paquetes actuales.
                do {
                    std::cout << "Sistema de simulacion de pila; ingresa la opcion deseada: \n" << "1. Agregar un paquete\n" << "2. Revisar que paquetes hay actualmente\n"
                    << "3. Revisar el paquete que sigue por entregar\n" << "4. Revisar el ultimo paquete para entregar\n" << "5. Volver al menu" << std::endl;
                    std::cin >> inputStack;
                    switch (inputStack) {
                        case 1:
                            miStack.addPackage(createPackage());
                            miStack.checkPackages();
                            break;
                        case 2:
                            miStack.checkPackages();
                            break;
                        case 3:
                            miStack.checkFirstPackage();
                            break;
                        case 4:
                            miStack.checkLastPackage();
                            break;
                    }
                }while (inputStack != 5);
                break;
            case 4: //Arbol binario
                
                break;
        }
    }while (opc != 5);


#pragma region Prueba de Stack
    /*
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
    camion1.checkPackages();*/
#pragma endregion

#pragma region Prueba AVLTree
    AVLTree tree;

    cliente c1("Juan", "Calle 1", 11);
    cliente c2("Maria", "Calle 2", 105);
    cliente c3("Pedro", "Calle 3", 153);
    cliente c4("Ana", "Calle 4", 2);
    cliente c5("Luis", "Calle 5", 46);
    cliente c6("Luis", "Calle 5", 987);
    cliente c7("Luis", "Calle 5", 34);

    tree.insert(c1);
    tree.insert(c2);
    tree.insert(c3);
    tree.insert(c4);
    tree.insert(c5);
    tree.insert(c6);
    tree.insert(c7);

    std::cout << "Clientes en orden por ID:\n";
    tree.printTree();
#pragma endregion
    return 0;
}

package createPackage() {
    int  id_package, priorityLevel, trackingCode;
    std::string addressRecipient, recipient, sender, addressSender, nombrePaquete;
    float deliveryDistance;
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

    std::cout << "Se agrego el paquete con ID: " << newPackage.getPackageID() << std::endl;
    return newPackage;
}

void addClient(AVLTree& tree) {
    std::string nombre, direccion;
    int id_cliente;

    std::cout << "Ingrese el nombre del cliente: ";
    std::cin.ignore(); // Limpiar el buffer
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la direccion del cliente: ";
    std::getline(std::cin, direccion);

    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> id_cliente;

    cliente newClient(nombre, direccion, id_cliente);
    tree.insert(newClient);
    std::cout << "Cliente agregado exitosamente.\n";
}
