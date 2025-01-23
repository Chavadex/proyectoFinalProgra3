#include <iostream>
#include <string>
#include <vector>


#include "camion.h"
#include "package.h"
#include "queue.h"
#include "stack.h"
#include "DDList.h"
#include "AVLTree.h"
#include "cliente.h"
#include "HashTable.h"

//Aqui inicializo las clases que he creado para que pueda usarlas en el main

package createPackage();
void addClient(AVLTree& tree);
void MergeSort(std::vector<package>& array, int first, int final);
void merge(std::vector<package>& array, int start, int middle, int end);
void printPackages(const std::vector<package>& packages);
void addPackagesOrder(std::vector<package>& mispackages);
void QuickSort(std::vector<package>& array, int first, int final);
int particion(std::vector<package>& array, int start, int end);
void swap(package& a, package& b);


int main()
{

    int opc, inputQueue, inputCamion, inputStack,inputAVL, inputOrder, inputHash;
    std::string addressRecipient, recipient, sender, addressSender, nombrePaquete;
    DDList<package> List;
    camion miCamion(List);
    queue<package> miQueue;
    stack<package> miStack;
    std::vector<package> packagesOrder;
    AVLTree tree;
    HashTable<package> hash_table(10);

    do {
        std::cout << "Bienvenido al sistema de Logistica de ChavadeXtafeta, ingresa el numero de la opcion deseada" << std::endl;
        std::cout << "1. Carga de camiones.\n 2. Fila de paquetes. \n 3. Apialcion de paquetes en bodega\n 4. Creacion y almacenamiento de clientes por ID (AVLTree)\n 5. Ordenamiento de paquetes por prioridad.\n"
                     "6. Gaurdado de paquetes por us codigo de rastreo. (Tabla HASH)\n 7. Salir" << std::endl;
        std::cin >> opc ; //Este input selecciona la opcion del usuario para poder ver que parte del codigo se ejecutara.
        switch (opc) {
            case 1: //Gestor de paquetes, simula una carga de camion en donde mediante una lista enlazada doble podemos verificar cuales son los paquetes que hay en
                    //el camion y retirar o anadir mas
                do {
                    std::cout << "Carga al camion de entrega; ingresa la opcion deseada: \n 1. Agregar Paquete "
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
                    std::cout << "Sistema de fila de paquetes; ingresa la opcion deseada: \n" << "1. Agregar paquete a la fila\n "
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
                    std::cout << "Sistema de carga de paquetes apilados; ingresa la opcion deseada: \n" << "1. Agregar un paquete\n" << "2. Revisar que paquetes hay actualmente\n"
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
            case 4: //Arbol binario. Agrega los clientesy los ordena mediante su ID de cliente para facilitar su busqueda.

                do {
                    std::cout << "Sistema de registro de clientes; ingresa la opcion deseada: \n" << "1. Agregar un cliente nuevo.\n" << "2. Revisar la base de clientes actyal\n"
                    << "3. Eliminar algun cliente\n" << "4. Vovler al menu\n" << std::endl;
                    std::cin >> inputAVL;
                    switch (inputAVL) {
                        case 1:
                            addClient(tree);

                        break;
                        case 2:
                            tree.printTree();
                            break;
                        case 3:
                            int idCustomer;
                            std::cout << "Ingrese el id del cliente por borrar" << std::endl;
                            std::cin >> idCustomer;
                            cliente Dummy("Dummy", "Placehodler", idCustomer);
                            tree.remove(Dummy);
                            break;
                    }

                }while (inputAVL != 4);
                break;
            case 5: //Metodos de ordenamiento. Agrega paquetes y ordenelos mediante el nivel de prioridad de cada uno.
                do {
                    std::cout << "Ordenamiento de paquetes de acuerdo al nivel de prioridad. Ingrese la opcion deseada: \n" << "1. Revisar los paquetes actuales.\n 2. Agregar neuvo paquete\n"
                                                                                                                               "3. Ordenar los paquetes por MergeSort\n 4. Ordenar los paquetes por QuickSort\n "<< std::endl;
                    std::cin >> inputOrder;
                    switch (inputOrder) {
                        case 1:
                            printPackages(packagesOrder);
                            break;
                        case 2:
                            addPackagesOrder(packagesOrder);
                            break;
                        case 3:
                            MergeSort(packagesOrder, 0, packagesOrder.size() - 1);
                            printPackages(packagesOrder);
                            break;
                        case 4:
                            QuickSort(packagesOrder, 0, packagesOrder.size() -1);
                            printPackages(packagesOrder);
                            break;
                    }
                }while (inputOrder != 4);
                break;
            case 6: // Tabla Hash. Gaurdado de los codigo de rastreo mediante la funcion Hash.
                do {
                    std::cout << "Tabla Hash con el Tracking Code como llave. Ingresa la opcion deseada. \n 1. Revisar los valores almacenados.\n 2. Insertar paquete\n 3. Eliminar paquete" << std::endl;
                    std::cin >> inputHash;
                    switch (inputHash) {
                        case 1:
                            hash_table.display();
                            break;
                        case 2:
                            hash_table.insert(createPackage());
                            break;
                        case 3:
                            int trackingCodeToDelete;
                            std::cin >> trackingCodeToDelete;
                            hash_table.remove(trackingCodeToDelete);
                            break;
                    }
                }while (inputHash != 4);


                break;
        }
    }while (opc > 7);





    return 0;
}

#pragma region Funcion CreatePakage //Funcion que devuelve un objeto de tipo package, usada para crear los paquetes cuando se requeira agregar alguno.
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
#pragma endregion


#pragma region FuncionAddClient //Usada para crear cliente con su nombre, su direccion, su ID.
void addClient(AVLTree& tree) {
    std::string nombre, direccion;
    int id_cliente;

    std::cout << "Ingrese el nombre del cliente: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la direccion del cliente: ";
    std::getline(std::cin, direccion);

    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> id_cliente;

    cliente newClient(nombre, direccion, id_cliente);
    tree.insert(newClient);
    std::cout << "Cliente agregado exitosamente.\n";

}
#pragma endregion

#pragma region Metodos Ordenaniento //Funciones de ordenamiento para los niveles de prioridad.
void MergeSort(std::vector<package>& array, int first, int final) {
    if (first < final) {
        int middle = first + (final - first) / 2;
        MergeSort(array, first, middle);
        MergeSort(array, middle + 1, final);
        merge(array, first, middle, final);
    }
}

void merge(std::vector<package>& array, int start, int middle, int end) {
    int i, j, k;
    int leftElements = middle - start + 1;
    int rightElements = end - middle;


    std::vector<package> leftArray(leftElements);
    std::vector<package> rightArray(rightElements);

    for (i = 0; i < leftElements; i++) {
        leftArray[i] = array[start + i];
    }

    for (j = 0; j < rightElements; j++) {
        rightArray[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < leftElements && j < rightElements) {
        if (leftArray[i].getPriorityLevel() <= rightArray[j].getPriorityLevel()) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftElements) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightElements) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void printPackages(const std::vector<package>& packages) {
    std::cout << "Tu lista de paquetes actual es:" << std::endl;
    for (size_t i = 0; i < packages.size(); i++) {
        std::cout << "ID: " << packages[i].getPackageID()
                  << " Prioridad: " << packages[i].getPriorityLevel() << std::endl;
    }
    std::cout << std::endl;
}

void addPackagesOrder(std::vector<package>& mispackages) {

    mispackages.push_back(createPackage());
    std::cout << "Paquete agregado" << std::endl;
}

void QuickSort(std::vector<package>& array, int first, int final) {
    if (first < final) {
        int pivote = particion(array, first, final);
        QuickSort(array, first, pivote - 1);
        QuickSort(array, pivote + 1, final);
    }

}

int particion(std::vector<package>& array, int start, int end) {
    int pivote = array[start].getPackageID();
    int i = start + 1;
    for (int j = i; j <= end; j++) {
        if (array[j].getPackageID() < pivote) {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[start], array[i - 1]);
    return i - 1;
}

void swap(package& a, package& b) {
    package aux = a;
    a = b;
    b = aux;
}

#pragma endregion

