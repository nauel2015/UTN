
// Explicando que es una cola:
// Una cola es una estructura de datos, caracterizada por ser una secuencia de elementos.
// La operacion de insercion se realiza por un extremo (final) y la extraccion por el otro (frente).

// Las operaciones usuales en las colas son:
// 1- La operacion Insertar (push) añade un elemento po el extremo final.
// 2- La operacion Quitar (pop) extrae un elemento por el extremo opuesto (frente).

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct NodoCliente
{
    int dato;
    NodoCliente* sgte;
} *nuevo_nodo, *frente = NULL, *fin = NULL;

// prototipo de funciones.
void insertarCola(NodoCliente* &, NodoCliente* &, int);
bool cola_Vacia(NodoCliente* frente);
void quitarCola(NodoCliente* &, NodoCliente* &, int &);

int main()
{
    int dato;
    char respuesta;
    cout <<"\nIngrese los elementos de cola." << endl;
    do{
        cout <<"\nIngrese el elemento: "; cin >> dato;
        insertarCola(frente, fin, dato);
        cout <<"\nQuiere agregar otro elemento a cola? (S/N) "; cin >> respuesta;
    }while((respuesta=='S')||(respuesta=='s'));

    cout <<"\nSuprimiendo los elementos de la cola: ";
    while(frente!=NULL)
    {
        quitarCola(frente, fin, dato);

        if(frente!=NULL)
        cout << dato <<" , ";
        if(frente==NULL)
        cout << dato <<".";
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void insertarCola(NodoCliente* &frente, NodoCliente* &fin, int n)
{
    // 1- Crear espacio de memoria para almacenar un nodo.
    nuevo_nodo = new NodoCliente();
    // 2- Asignar el nuevo nodo al dato q queremos insertar.
    nuevo_nodo->dato = n;
    nuevo_nodo->sgte = NULL;
    // 3- Asignar el puntero frente y fin hacia el nuevo nodo.
    if(cola_Vacia(frente))
    {
        frente = nuevo_nodo;
    }else{
        fin->sgte = nuevo_nodo;
    }

    fin = nuevo_nodo;

    cout <<"El elemento [" << n <<"] ingreso a cola con exito." << endl;
}

bool cola_Vacia(NodoCliente* frente)
{
    return (frente==NULL)? true : false;

    /*
    if(frente==NULL)
    return true;
    
    if(frente!=NULL)
    return false;
    */
}

void quitarCola(NodoCliente* &frente, NodoCliente* &fin, int &n)
{
    // 1- Obtener el valor del nodo.
    n = frente->dato;

    // 2- Crear un nodo aux y asignarle el frente de la cola.
    NodoCliente* aux = frente;

    // 3- Eliminar el nodo del frente de la cola.
    if(frente==fin)
    {
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->sgte;
    }

    delete aux;

}

// Ejercicio n°1: Hacer un programa utilizando colas que contenga el siguiente menu:
// 1- insertar un caracter a la cola.
// 2- Mostrar todos los elementos de la cola.
// 3- Salir.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct NodoCliente
{
    char dato;
    NodoCliente* sgte;
}*frente = NULL, *fin = NULL;

// prototipo de funciones.
void Menu();
void insertarCola(NodoCliente* &, NodoCliente* &, char);
bool cola_Vacia(NodoCliente* frente);
void quitarCola(NodoCliente* &, NodoCliente* &, char&);

int main()
{
    Menu();

    cout <<"\n¡Hasta luego!." << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void Menu()
{
    int opcion;
    char respuesta, dato;

    do{
        cout <<"\n\tMenu.\n1- insertar un caracter a la cola.\n2- Mostrar todos los elementos de la cola.\n3- Salir." << endl;
        cout <<"Seleccione su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: do{
                        cout <<"\ninserte un caracter a la cola: "; cin >> dato;
                        insertarCola(frente, fin, dato);
                        cout <<"El elemento [" << dato <<"] ingreso a cola con exito." << endl;
                        cout <<"\nQuiere ingresar otro caractera a la cola? (S/N): "; cin >> respuesta;
                    }while((respuesta=='S')||(respuesta=='s')); break;

            case 2: cout <<"\nMostrando los elementos de la cola: ";
                    while(frente!=NULL)
                    {
                        quitarCola(frente, fin, dato);
        
                        if(frente!=NULL)
                        cout << dato <<" , ";
                        if(frente==NULL)
                        cout << dato <<"." << endl;
                    }
                    
                    system("PAUSE"); break;
                    
            case 3: break;
            
            default: cout << "\nOpcion no valida. Intente de nuevo.\n";
        }

        system("cls");
    }while(opcion!=3);
}

void insertarCola(NodoCliente* &frente, NodoCliente* &fin, char n)
{
    NodoCliente* nuevo_nodo = new NodoCliente();
    nuevo_nodo->dato = n;
    nuevo_nodo->sgte = NULL;

    if(cola_Vacia(frente))
    {
        frente = nuevo_nodo;
    }else{
        fin->sgte = nuevo_nodo;
    }

    fin = nuevo_nodo;
}

bool cola_Vacia(NodoCliente* frente)
{
    return (frente==NULL)? true : false;
}

void quitarCola(NodoCliente* &frente, NodoCliente* &fin, char &n)
{
    n = frente->dato;
    NodoCliente* aux = frente;

    if(frente==fin)
    {
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->sgte;
    }

    delete aux;
}

// Ejercicio n°2: Hacer un programa que:
// 1- Guarde datos de clientes de un banco. 
// 2- Los almacene en cola.
// 3- Y por ultimo muestre los clientes en el orden correcto.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct clientes
{
    char nombre[30];
    char clave_Cuenta[30];
    int edad;
}cliente;

struct NodoCliente
{
    clientes cliente;
    NodoCliente* sgte;
}*frente = NULL, *fin = NULL;

// prototipo de funciones.
void MenuBanco();
void pedirDatosClientes(clientes &);
void insertarCola(NodoCliente* &, NodoCliente* &, clientes);
bool cola_Vacia(NodoCliente* frente);
void quitarCola(NodoCliente* &, NodoCliente* &, clientes&);

int main()
{
    MenuBanco();

    cout <<"\n\t!!!Hasta luego!!!." << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void MenuBanco()
{
    int opcion;
    char respuesta;

    
    do{
        cout <<"\n\tMenu Del Banco\n1- Agregar cliente.\n2- Mostrar clientes.\n3- Salir." << endl;
        cout <<"\nSeleccione su opcion: "; cin >> opcion;
        system("cls");

        switch(opcion)
        {
            case 1: do{
                pedirDatosClientes(cliente);
                insertarCola(frente, fin, cliente);
                cout <<"\nEl cliente ingreso al sistema bancario con exito. " << endl;
                cout <<"Desea ingresar otro cliente al sistema? (S/N): "; cin >> respuesta;
                system("cls");
            }while((respuesta=='S')||(respuesta=='s')); break;

            case 2: cout <<"\n\t===Carga de clientes exitosa===" << endl;
            while(frente!=NULL)
            {
                quitarCola(frente, fin, cliente);

                cout <<"\nNombre: " << cliente.nombre << endl;
                cout <<"Clave de usuario: " << cliente.clave_Cuenta << endl;
                cout <<"Edad: " << cliente.edad << endl;

                if(frente==NULL)
                cout <<"\nHasta aca llega la planilla de clientes del banco." << endl;
            }

            system("PAUSE");
            system("cls"); break;

            case 3: break;

            default: cout << "\nOpcion no valida. Intente de nuevo.\n";
        }
    }while(opcion!=3);


}

void pedirDatosClientes(clientes &cliente)
{
    cin.ignore();
    cout <<"\nIngrese los datos del nuevo cliente del banco." << endl;
    cout <<"Nombre: "; cin.getline(cliente.nombre, 30, '\n');
    cout <<"Clave: "; cin.getline(cliente.clave_Cuenta, 30, '\n');
    cout <<"Edad: "; cin >> cliente.edad;
}

void insertarCola(NodoCliente* &frente, NodoCliente* &fin, clientes cliente)
{
    NodoCliente* nuevo_nodo = new NodoCliente();
    nuevo_nodo->cliente = cliente;
    nuevo_nodo->sgte = NULL;

    if(cola_Vacia(frente))
    {
        frente = nuevo_nodo;
    }else{
        fin->sgte = nuevo_nodo;
    }

    fin = nuevo_nodo;
}

bool cola_Vacia(NodoCliente* frente)
{
    return (frente==NULL)? true : false;
}

void quitarCola(NodoCliente* &frente, NodoCliente* &fin, clientes &cliente)
{
    cliente = frente->cliente;
    NodoCliente* aux = frente;

    if(frente==fin)
    {
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->sgte;
    }

    delete aux;
}

