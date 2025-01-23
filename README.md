# Documentacion "Proyecto final Progra 3"

El proyecto cumple la funcion de ser un programa pensado para la administracion logistica de una empresa de envíos.
Contiene diferentes clases que sirven para llevar a cabo las diversas tareas requeridas. A continuacion explciaremos cada clase que incluye el programa.

## Clase: "*package.h/package.cpp*"

Su funcion principal es crear un objeto de tipo package que almacene la informacion de cada apquete. Al ser llamada pide los datos que un paquete promedio contiene:

- pakcageID (int)
- addressRecipient (String)
- recipient (String)
- sender (String)
- addressSender (String)
- priorityLevel (Int)
- trackingCode (int)
- deliveryDistance (float)

Cada uno de estos valores con sus respectivos getters y setters, denominados get/set seguido del nombre de la variable. Ademas cabe recalcar la inclusion de su destructor y su constructor por default.

Como anotacion extra, al crear el paquete, para los inputs en ves de usar *std::cin* se utilizo *std::getline(std::cin, variable)*, debido a problemas de saltos de linea con el input y el uso de *std::cin.ignore()* por el mismo motivo.

## Clase "*Cliente.h/Cliente.cpp*"

Su funcion es crear un objeto cliente que contenga la infromacion más relevante acerca de los clientes regsitrados en la compañia. Los datos que contiene son:

- name(String)
- address(string)
- id_customer (Int)

Igualmente con sus respectivos getter y setters.

## Clase "*Camion.h*"

Carga un camion con objetos paquetes. Inicializando primero una lista doblemente enlazada que permite ver los paquetes que se van agregando, asi como retirarlos y agregar nuevos de acuerdo a las necesidades. Sus principales funcioens son:

- checkTruck() : No requiere de ningun parámetro y devuelve los objetos existentes dentro del camión.
- addPackageToTrcuk() : No requiere de ngin parametro, pero ejecutara una funcion que pedira los datos para la creacion de un paquete dentro del camion.
