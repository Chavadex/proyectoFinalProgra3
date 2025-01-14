#include <iostream>
#include "DDList.h"
#include <string>

#include "package.h"

int main()
{
    int opc;
    DDList<package> list;
    package package1(1001, "mi casa", "Julian", "Pablo", "Su casa", 1, 1552, 45.6f);
    package package2(1002, "su casa", "Elfillo", "Jaime", "su casa", 2, 1999, 23.4f);

    list.addObject(package1);
    list.addObject(package2);
    list.print();

    /*


    std::cout << "Bienvenido, ingresa el numero de la opcion deseada" << std::endl;
    std::cin >> opc ;

    switch (opc) {
        case 1: //Gest



            break;
        case 2:
            break;
        case 3:
            break;
    }
*/
    return 0;
}
