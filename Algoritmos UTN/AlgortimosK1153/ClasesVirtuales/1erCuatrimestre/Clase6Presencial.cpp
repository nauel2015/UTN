
// Clase N°7: 28/05/2025
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

/* Ejercicio en clase N°1: Somos una empresa de envios a domicilio y queremos poder insertar de manera ordenada en un array
los envios que tenemos que hacer. Por cada envio se conoce:

1- Destino [char/string]
2- Fecha de envio [int = YYYYMMDD].

*/

/* Ejercicio en clase N°2: La empresa de envios ahora solicita poder cancelar envios que tiene programados.
El usuario deberia poder escribir la fecha del envio que quiere cancelar y deberia eliminarse del arrays.

1- Busqueda secuencial para encontrar la posicion.
2- Una vez encontrada la posicion, vamos a eliminar el elemento de dicha posicion

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct envio
{
    char destino[30];
    int fecha;
}envios[5], insertarEnvio;

// Declaracion de las funciones:
void insertar(envio [], int &, envio, int);
void insertarOrdenadoEnvio(envio [], int &, envio);
int busquedaSecuencial(envio [], int);
void eliminarEnvio(envio [], int &, int);
void consultarEnvios(envio [], int);

int main()
{
    int len=0, opcion=0;
    do{
        cout <<"\n\tMenu envios " << endl;
        cout <<"\nOpcion 1: Nuevo envio. " << endl;
        cout <<"Opcion 2: Consultar envios. " << endl;
        cout <<"Opcion 3: Cancelar envio. " << endl;
        cout <<"Opcion 4: Salir. " << endl;
        cout <<"\nSeleccione su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); insertarOrdenadoEnvio(envios, len, insertarEnvio); system("cls"); break;
            case 2: system("cls"); consultarEnvios(envios, len); system("cls"); break;
            case 3: system("cls"); busquedaSecuencial(envios, len); system("cls"); break;
            case 4: cout <<"\nHasta Luego. " << endl; break;
        }
    }while(opcion!=4);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
void insertar(envio envios[], int &len, envio insertarEnvio, int pos)
{
    for (int i = len; i > pos; i--) 
    {
        envios[i] = envios[i - 1];
    }

    envios[pos] = insertarEnvio;
    len++;
}


void insertarOrdenadoEnvio(envio envios[], int &len, envio insertarEnvio)
{
    cin.ignore();
    cout <<"\n\tIngrese los datos del envio a realizar. " << endl;
    cout <<"\nDestino: "; cin.getline(insertarEnvio.destino, 30, '\n');
    cout <<"Fecha de envio: "; cin >> insertarEnvio.fecha;

    int i = 0;
    while (i < len && envios[i].fecha <= insertarEnvio.fecha) 
    {
        i++;
    }

    if (i == len)
    {
        envios[len] = insertarEnvio;
        len++;
    }else 
    {
        insertar(envios, len, insertarEnvio, i);
    }
    
}

int busquedaSecuencial(envio envios[], int len) 
{
    int i = 0, buscarEnvio;
    cout <<"\n\tIngrese la fecha del envio a buscar." << endl;
    cout <<"\nFecha de envio: "; cin >> buscarEnvio;
    while (i < len && envios[i].fecha != buscarEnvio) 
    {
        i++;
    }

    if (i == len) 
    {
        cout <<"\nERROR. Envio no escontrado. " << endl;
        return -1;
    }else{
        cout <<"\nEnvio encontrado. " << endl;
        char flag;
        cout <<"Quiere eliminar el envio definitivamente? [S/N]: "; cin >> flag;

        if(flag == 's' || flag == 'S')
        {
            eliminarEnvio(envios, len, i);
            cout <<"\nEl envio fue cancelado. " << endl;
            system("pause");
        }else if(flag != 'n' || flag != 'N'){
            cout <<"\nEliminacion interrumpida, Volviendo al menu... " << endl;
            system("pause");
        }
    }
}

void eliminarEnvio(envio envios[], int &len, int pos) 
{
    for (int i = pos; i < len - 1; i++) 
    {
        envios[i] = envios[i + 1];
    }

    len--;
}

void consultarEnvios(envio envios[], int len)
{
    cout <<"\nTodos los envios pendientes a enviar hasta el momento. " << endl;
    for(int i=0; i< len; i++)
    {
        cout <<"\nCliente N°" << i+1 <<": " << endl;
        cout <<"Destino: " << envios[i].destino << endl;
        cout <<"Fecha de entrega: " << envios[i].fecha << endl;
    }

    cout <<"\n[ENTER PARA VOLVER AL MENU] " << endl;
    system("Pause");
}