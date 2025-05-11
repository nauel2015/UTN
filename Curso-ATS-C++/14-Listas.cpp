
// Explicacion de listas: listas enlazadas. Son dinamicas.
// Una lista enlazada consta de un numero de nodos con dos componentes (campos)
// un enlace al siguiente nodo de la lista y un valor, que puede ser de cualquier tipo.

// Clasificacion de listas enlazadas:

// 1- Listas Simplemente Enlazadas:
// Cada Nodo (elemento) contiene un unico enlace que conecta ese nodo al nodo siguiente o nodo sucesor.
// La lista es eficiente en recorridos directos (Adelante).

// 2- Listas Doblemente Enlazadas:
// Cada nodo Contiene dos enlaces, uno a su nodo predecesor y el otro a su nodo sucesor.
// la lista es eficiente tanto en recorrido directo (Adelante) como en recorrido inverso (Atras).

// 3- Lista Circular Simplemente Enlazada:
// Una lista enlazada simplemente en la que el ultimo elemento (cola) se enlaza al primer elemento (Cabeza)
// de tal modo que la lista puede ser recorrida de modo circular (En anillo).

// 4- Lista Circular Doblemente Enlazada:
// Una lista doblemente enlazada es en la que el ultimo elemento se enlaza al pirmer elemento y viceversa.
// Esta lista se puede recorrer de modo circular (En anillo) tanto en direccion directa (Adelante) como inversa (Atras).

// Ejercicio n°1: Realizar un menu con las siguientes opciones:
// 1- Insertar elementos a la lista.
// 2- Mostrar elementos de la lista.
// 3- Buscar un elemento de la lista.
// 4- Eliminar un nodo de la lista.
// 5- Eliminar todos los nodos de la lista.
// 6- Salir.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo* sgte;
}*lista = NULL;

// prototipo de funciones.
void MenuLista();
void insertarLista(Nodo* &, int);
void mostrarLista(Nodo*);
void buscarLista(Nodo*, int);
void eliminar1Nodo(Nodo* &, int);
void eliminarLista(Nodo* &, int &);

int main()
{
    MenuLista();
    cout <<"\n\t!!!Hasta luego!!!." << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void MenuLista()
{
    int dato, opcion;
    char respuesta;

    do{
        cout <<"\n\t===Menu===\n1- Insertar elementos a la lista.\n2- Mostrar elementos de la lista.\n3- Buscar un elemento de la lista.\n4- Eliminar un nodo de la lista.\n5- Eliminar todos los nodos de la lista.\n6- Salir.\nMarque su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: do{
                cout <<"\nIngrese un elemento a la lista: "; cin >> dato;
                insertarLista(lista, dato);
                cout <<"\nQuiere ingresar otro elemento a la lista? (S/N): "; cin >> respuesta;
            }while((respuesta=='S')||(respuesta=='s')); break;

            case 2: 
            system("cls");
            mostrarLista(lista); 
            cout <<"\n";
            system("PAUSE"); break;

            case 3: cout <<"\nIngrese el elemento que quiere buscar en la lista: "; cin >> dato;
            buscarLista(lista, dato);
            cout <<"\n";
            system("PAUSE"); break;

            case 4: cout <<"\nIngrese el elemento q quiere eliminar de la lista: "; cin >> dato;
            eliminar1Nodo(lista, dato);
            cout <<"\n";
            system("PAUSE"); break;

            case 5: cout <<"\nEliminando los elementos ";
            while(lista!=NULL)
            {
                eliminarLista(lista, dato);
                cout << dato <<"..";
            }
            
            cout <<"\nLimpieza de la lista realizada con exito. " << endl;
            cout <<"\n";
            system("PAUSE"); break;

            case 6: break;
        }

        system("cls");

    }while(opcion!=6);

}

void insertarLista(Nodo* &lista, int n)
{
    // 1- Crear un nuevo nodo
    Nodo* nuevo_nodo = new Nodo();
    
    // 2- Asignar a nuevo_nodo->dato el elemento que queremos incluir a la lista.
    nuevo_nodo->dato = n;

    // 3- Crear dos nodos auxiliares y asignar lista al primero de ellos.
    Nodo* aux1 = lista;
    Nodo* aux2;

    // 4- Insertar el elemento a la lista.
    while((aux1!=NULL)&&(aux1->dato<n)) // para insertar los elementos a la lista de forma ordenada.
    {
        aux2 = aux1;
        aux1 = aux1->sgte;
    }

    if(lista==aux1) // Esto se va a cumplir siempre y cuando el elemento vaya al principio de la lista.
    {
        lista = nuevo_nodo;
    }else{
        aux2->sgte = nuevo_nodo;
    }

    nuevo_nodo->sgte = aux1; // aux1 nos va a ayudar a referenciar siempre la ultima posicion de la lista.

    cout <<"El elemento [" << n <<"] se inserto a lista con exito. " << endl;
}

void mostrarLista(Nodo* lista)
{
    // 1- Crear nuevo Nodo llamado actual.
    Nodo* actual = new Nodo();

    // 2- Igualar el nuevo nodo llamado actual a lista.
    actual = lista;

    // 3- Recorrer la lista de inicio a fin.
    cout <<"\nCargando elementos de la lista... " << endl;
    while(actual!=NULL)
    {
        cout <<"[" << actual->dato << "] ";
        actual = actual->sgte;
    }

    cout <<"\n";

}

void buscarLista(Nodo* lista, int buscado)
{
    bool flag = false;

    // 1- Crear un nuevo nodo llamado actual.
    Nodo* actual = new Nodo();

    // 2- Igualar el nuevo nodo actual a lista.
    actual = lista;

    // 3- Recorrer la lista.
    cout <<"\nBuscando el elemento en la lista... " << endl;

    while((actual!=NULL)&&(actual->dato<=buscado))
    {
        // 4- Determinar si el elemento existe o no en la lista.
        if(actual->dato==buscado)
        {
            flag = true;
        }

        actual = actual->sgte;
    }

    if(flag==true)
    cout <<"El elemento [" << buscado <<"] si se encuentro en la lista. " << endl;
    if(flag==false)
    cout <<"El elemento [" << buscado <<"] no se encuentro en la lista. " << endl;
    
}

void eliminar1Nodo(Nodo* &lista, int borrar)
{
    cout <<"\nBuscando el elemento a eliminar en la lista... " << endl;
    // 1- Preguntar si la lista no esta vacia.
    if(lista!=NULL)
    {
        // 2- Crear un *aux_borrar y *anterior=NULL.
        Nodo* aux_borrar;
        Nodo* anterior=NULL; // Anterior apunta a NULL.

        // 3- Igualar *aux_borrar al inicio de la lista.
        aux_borrar = lista;

        // 4- Recorrer la lista.
        while((aux_borrar!=NULL)&&(aux_borrar->dato!=borrar))
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->sgte;
        }

        if(aux_borrar==NULL) // Si recorre toda la lista y no lo encuentra.
        {
            cout <<"Elemento no encontrado en la lista." << endl;
        }
        // 5- Eliminar el elemento.
        else if(anterior==NULL) // Si anterior es igual a NULL, significa que el elemento que queremos eliminar es el primer elemento de la lista.
        { 
            lista = lista->sgte; // Lista apunta al siguiente nodo.
            delete aux_borrar; // Borramos el nodo en el que esta apuntando aux_borrar.
            cout <<"El elemento [" << borrar <<"] fue eliminado con exito. " << endl;
        }else{
            // aux_borrar->dato apunta al elemento que queremos borrar por ende igualamos anterior->sgte a borrar_aux->sgte;
            anterior->sgte = aux_borrar->sgte;
            delete aux_borrar;
        }

    }else{
        cout <<"La lista se encuentra vacia." << endl;
    }
}

void eliminarLista(Nodo* &lista, int &eliminar)
{
    // 1- Crear un Nodo *aux e igualarlo al inicio de la lista.
    Nodo* aux = lista;

    // 2- Guardar el dato que queremos eliminar dentro de aux.
    eliminar = aux->dato;

    // 3- Pasar lista al siguiente nodo.
    lista = aux->sgte;

    // 4- Eliminar aux.
    delete aux;

}

// Ejercicio n°2: Calcular el mayor y menor elemento de una lista.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo* sgte;
}*lista=NULL;

// prototipo de funciones.
void insertarLista(Nodo* &, int);
void mostrarLista(Nodo*);
void calcular_Mayor_Menor(Nodo*);

int main()
{
    int dato;
    char respuesta;

    do{
        cout <<"\nIngrese el elemento que va a agregar a lista: "; cin >> dato;
        insertarLista(lista, dato);
        cout <<"\nQuiere ingresar otro elemento? (s/n): "; cin >> respuesta;
    }while((respuesta=='s')||(respuesta=='S'));

    cout <<"\nCargando elementos ingresados..." << endl;
    mostrarLista(lista);
    calcular_Mayor_Menor(lista);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void insertarLista(Nodo* &lista, int insertar)
{
    Nodo* nuevo_nodo = new Nodo();
    Nodo* aux;

    nuevo_nodo->dato = insertar;
    nuevo_nodo->sgte = NULL;

    if(lista==NULL) // Si la lista esta vacia.
    {
        lista = nuevo_nodo; // Agregamos el primer elemento a la lista.
    }else{
        aux = lista; // aux apunta al inicio de la lista.
        while(aux->sgte!=NULL)
        {
            aux = aux->sgte; // Avanzamos en la lista en busca de null.
        }

        aux->sgte = nuevo_nodo; // Agregamos el nuevo nodo al final de la lista.
    }

    cout <<"El elemento [" << insertar <<"] se agrego a la lista con exito. " << endl;
}

void mostrarLista(Nodo* lista)
{
    while(lista!=NULL)
    {
        cout <<"[" << lista->dato <<"]";
        lista = lista->sgte;
    }
}

void calcular_Mayor_Menor(Nodo*)
{
    int mayor=0; int menor=99999;

    while(lista!=NULL)
    {
        if(lista->dato > mayor)
        {
            mayor = lista->dato;
        }

        if(lista->dato < menor)
        {
            menor = lista->dato;
        }

        lista = lista->sgte;
    }

    cout <<"\nEl mayor elemento de la lista es: [" << mayor <<"] " << endl;
    cout <<"El menor elemento de la lista es: [" << menor <<"] " << endl;

}

// Ejercicio n°3: Crear una lista que almacene n numeros reales, calcular su suma y el promedio de estos.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Nodo
{
    float dato;
    Nodo* sgte;
}*lista=NULL;

int nNodos;

// prototipo de funciones.
void insertarLista(Nodo* &, float);
void mostrarLista(Nodo*);
void calcular_suma_Promedio(Nodo*, int);


int main()
{
    float dato;

    cout <<"\nCantidad de elemento que va a insertar a la lista: "; cin >> nNodos;

    for(int i=0; i<nNodos; i++)
    {
        cout <<"\nIngrese el elemento: "; cin >> dato;
        insertarLista(lista, dato);
    }


    cout <<"\nCargando elementos ingresados..." << endl;
    mostrarLista(lista);
    calcular_suma_Promedio(lista, nNodos);
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void insertarLista(Nodo* &lista, float insertar)
{
    Nodo* nuevo_nodo = new Nodo();
    Nodo* aux;

    nuevo_nodo->dato = insertar;
    nuevo_nodo->sgte = NULL;

    if(lista==NULL) // Si la lista esta vacia.
    {
        lista = nuevo_nodo; // Agregamos el primer elemento a la lista.
    }else{
        aux = lista; // aux apunta al inicio de la lista.
        while(aux->sgte!=NULL)
        {
            aux = aux->sgte; // Avanzamos en la lista en busca de null.
        }

        aux->sgte = nuevo_nodo; // Agregamos el nuevo nodo al final de la lista.
    }

    cout <<"El elemento [" << insertar <<"] se agrego a la lista con exito. " << endl;
}

void mostrarLista(Nodo* lista)
{
    while(lista!=NULL)
    {
        cout <<"[" << lista->dato <<"]";
        lista = lista->sgte;
    }
}

void calcular_suma_Promedio(Nodo* lista, int nNodos)
{
    float suma=0, promedio=0;;

    while(lista!=NULL)
    {
        suma += lista->dato;
        lista = lista->sgte;
    }

    promedio = suma/nNodos;

    cout <<"\nSuma de los nodos es: " << suma << endl;
    cout <<"Promedio: " << promedio << endl;

}