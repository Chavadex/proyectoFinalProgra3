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
- removePackage(*int posicion*) : Requiere de un entero para determinar el lugar de la posicion, y se borrara ese objeto.

Requiere de la creación de la calse DDList, von un package como objeto a recibir.

## Clase "*DDList.h*"

Su funcion es ser una lista enlazada doble que tarabaja con nodos que reciben un tipo de dato cualqueira T, en este caso se usa el de package. Los objetos pasados se almacenan en los nodos los cuales estan conectados a un nodo previo y uno posterior. Las principales funcioens que hay aqui son:

-  addObject(*package*) : Requiere de un tipo de dato para almacenar, en este caso un package al cual guarda y le crea los nodos correspondientes. Si es el primer elemento en la lista lo convierte automatciamente en la *root* y la *head*.
-  print( ) : No pide ningun parámetro y nos muestra el contenido del camion.
-  erase(*int index*) : Funcion usada para eliminar un nodo de la lista, en este caso un paquete, de acuerdo a la posicion ingresada.

## Clase "*Queue.h*"

Utilizado para formar los objetos en una fila. Se basa en el principio de FIFO (First In, First Out). Es decir que formando los paquete, el primero en ingrersar sera el primero en ser retirado. Sus funciones principales son:

- addPackage(*package*) : Esta funcion utilza un parametro package para agregar un paquete a la fila. Al usar la funcion, ésta pedira todos los datos necesarios para creación de un package.
- takeOutPackage( ) : No requiere de ningun parámetro. Se usa para retirar de la fila el paquete correspondiente, siguiente el principio FIFO.
- checkPackages( ) : Sin parámetros necesarios. Su uso es para cuando se quiere ver cual es el contenido de la fila, pues mostrara los paquetes contenidos.
- checkFisrtPackage( ) : Esta funcion revisara en la fila cual es el paquete que entro primero d elos paquetes actuales, es decir, el proximo en salir.
- checkLastPackage( ) : Esta función revisara el último package agregado, es decir, el ultimo en salir de los paquetes actuales.

## Clase "*Stack.h*"

Utilizada para formar los objetos en una pila, es decir, encimados, respetando el principio de FILO (First In, Last Out). Refiriendonos a que el primer paquete que entra en la pila, será el último en ser retirado. Sus funciones principales son:

- addPackage(*package*) : Esta funcion utilza un parametro package para agregar un paquete a la fila. Al usar la funcion, ésta pedira todos los datos necesarios para creación de un package.
- takeOutPackage( ) : No requiere de ningun parámetro. Se usa para retirar de la fila el paquete correspondiente, siguiente el principio FILO.
- checkPackages( ) : Sin parámetros necesarios. Su uso es para cuando se quiere ver cual es el contenido de la fila, pues mostrara los paquetes contenidos.
- checkFisrtPackage( ) : Esta funcion revisara en la fila cual es el paquete que entro último de los paquetes actuales, es decir, el próximo en salir.
- checkLastPackage( ) : Esta función revisara el primer package agregado, es decir, el ultimo en salir de los paquetes actuales.


