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

## Clase "*AVLTree.h*"

Se usa esta clase para generar un arbol binario autobalanceable con el fin de poder almacenar de manera eficiente los clientes de la emrpesa de envíos. Se crea un nodo cque apunta a sus ramas hijas y contiene un objeto *cliente* el cual ya fue explciado anteriormente, con el fin de almacenarlos de acuerdo a su ID personal. Las principales funciones con las que cuenta son:

- insert(*cliente*) : Esta función nos pide un objeto *cliente* para ser usada, lo que hace es que a su vez llama a la funcion *insertNode(root, cliente)* la cual realizara la tarea de la insercion el el ALVTree.
- printTree( ) : Esta funcion imprime en consola el arbol actual con los datos con los que cuentem ya en su estado balanceado.
- remove(cliente) : Esta funcion toma el ID del cliente que se desea borrar y lo elimina del árbol. Cabe aclarar que para su uso correcto dentro de *main.cpp* es necesario la creación de un "Dummy" que hará de objeto cliente, con datos preestablecidos pero con un ID otorgado por el usuario para que la funcion *remove()* tome en cuenta ese ID.

## Clase "*HashTable.h*"

Esta clase e susada para lacenar de manera rapida los paquetes de acuerdo a su codigo de rastreo (TrackingCode). Lo que hace es convertir su código en un indice de acuerdo a la division del código/tamañoTabla, y asigna su lugar en un vector con su índice.

- HashTable(*int size*) : Su constrcutor, rquiere de un entero que determine el tamaño de la tabla.
- hashFunction(*packkage*) : Esta función toma el trackingCode del paquete nviado y lo convierte en su key, luego devuelve un indice el cual depende del sobrante de *key/tamañoTabla*.
- insert(*package*) : Esta función es usada para insertar algun paquete en la tabla Hash, determina un indice mediante la funcion hasFucntion(*paqueteEnviado*) y de acuerdo al indice lo inserta en el vector de listas.
- remove(*int trackingCode*) : Esta funcion requiere de un TrackingCode que tilizara para borrar de la tabla Hash el ID del paquete con ese TrackingCode.
- display( ) : Esta funcion mostrará toda la tabla Hash hasta el momento, con los índices que tienen datos y los que no tienen.

En el caso de esta tabla Hash, si en algun caso se diera el hecho de que dos TrackingCode tuvieran el mismo index, se acumularan en el mismo, siendo mostrados ambos al momento de usar *display( )*.

## Funciones de ordenamiento

Estas estan incluidas en el *main.cpp* en la parte final del codigo. Su funcion es ordenar un grupo de paquetes de acuerdo a su nivel de prioridad (*PriorityLevel*). Cada uno de los paquetes creados se añade a un vector llamado -*packagesOrder*. Sus funciones principales son:

- addPackagesOrder(packageOrder) : Llama a la función de *createPackage()* y añade el apquete creado al vector.
- printPackages(*std::vector<packages>*) : Esta función requiere de un vector, que en este caso es el llamado packagesOrder, lo qu ehace es imprimir el ID y el nivel de prioridad de los paquetes dentro del vector.
- MergeSort(*std::vector<packages>, int inicio, int final*) : Esta función requiere que se le pase el vector con lso elementos a ordenar y que se le indique el inciio y el final, el cual ya esta mencionado adecuadamente en la interfaz. Lo que hace es ordenar los valores del vector tomando su PriorityLevel mediante el metodo de Merge Sort elc ual divide los valores en mitades y los va acomodando.
- QuickSort(*std::vector<packages>, int inicio, int final*) : Esta función requiere que se le pase el vector con los elementos a ordenar y que se le indique el incio y el final, el cual ya esta mencionado adecuadamente en la interfaz. Lo que hace es ordenar los valores del vector tomando su PriorityLevel mediante el metodo de Quick Sort el cual tambien divide el grupo de valores y los va ordenando pero esto con el uso de un pivote.


## Main.cpp

Esta es la compilación de todas las clases creadas. Ya se ha explkicado previamente el funcionamiento de cada clase, por lo que aqui solo explicare el funcionamiento de la interfaz de *Main.cpp* y algunas funciones que fueron colocadas aqui mismo, como el ordenamiento.

### Funcion *package createPackage( )*

Esta función se usa para crear paquetes con todos sus valores, usado para aquellas estructuras de datos que requieren de un package.

Así como una funcion mencionada anteriormente, esta función utiliza los *cin >>* y los *std:::getLine(std::cin, variable)* con el fin de leer la informacionmediante inputs sin que se salten algunas líneas.

### Interfaz de usuario.

Básicamente la interfaz esta compuesta por diferentes *Swicth* que de acuerdo a cada input van a ir seleccionando que área del programa se quiere usar. A continuación enlisto las opciones:

1. Gestor de paquetes en camión.
   1. Agregar paquete
   2. Revisar el contenido del camión.
   3. Retirar un paquete.
   4. Vovler al menú.

2. Fila de paquetes.
    1. Agregar paquete a la fila.
    2. Revisar paquetes en la fila.
    3. Revisar el primer paquete que va a salir.
    4. Revisar el ultimo paquete agregado.
    5. Volver al menu
     
3. Pila de paquetes.
    1. Agregar paquete a la fila.
    2. Revisar paquetes en la fila.
    3. Revisar el primer paquete que va a salir.
    4. Revisar el ultimo paquete por entregar.
    5. Volver al menu

4. Registro de clientes mediante AVLTree.
    1. Agregar cliente nuevo.
    2. Revisar los clientes actuales.
    3. Eliminar algun cliente.
    4. Vovler al menu
  
5. Ordenamiento de paquetes mediante nivel de prioridad.
    1. Revisar paquetes actuales.
    2. Agregar nuevo paquete.
    3. Ordenar paquetes mediante MergeSort.
    4. Ordenar paquetes mediante QuickSort.
    5. Salir al menu.

6. Organizacion de pedidos mediante el codigo de rastreo.
    1. Revisar los valores almacenados.
    2. Insertar paquete.
    3. Eliminar pauqte.
    4. Salir al menú.
  
