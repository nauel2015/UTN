
/* Ejercicio N°5: Tienda de Mascotas.

Una tienda registra hasta 20 mascotas. 
Cada mascota tiene:

nombre (string)
especie (string: perro, gato, conejo)
edad (int)
precio (float)

Tareas:
1. Permitir cargar hasta 20 mascotas.
2. Implementar una función que devuelva la mascota más cara.
3. Calcular cuántos perros hay menores a 2 años.
4. Mostrar el promedio de precios por especie (usando una función).
5. Permitir al usuario ingresar una especie y mostrar todas las mascotas de esa especie ordenadas por precio.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct mascota
{
    char nombre [30];
    char especie [10];
    int edad;
    int precio;
}mascotas[20];

struct preciosMascotas
{
    float totalPreciosP=0;
    float totalPreciosG=0;
    float totalPreciosC=0;
    float contPerros=0;
    float contGatos=0;
    float contConejos=0;
}precios;

// Declaracion de las funciones.
mascota insetarMascota(mascota [], preciosMascotas &, int &);
void mascotaMasCara(mascota [], int);
void calcularPerros(mascota [], int);
void promedioPreciosEspecies(preciosMascotas, int);
void ordenamientoBurbuja(mascota [], int);
void buscarEspecieOrdenada(mascota [], int);

int main()
{
    int opcion, contMascotas=0;
    do{
        cout <<"\n\tTienda de Mascotas. " << endl << endl;
        cout <<"Opcion 1: Cargar Mascotas. " << endl;
        cout <<"Opcion 2: Ver la Mascota mas cara. " << endl;
        cout <<"Opcion 3: Ver todos los Perros menores a 2 años. " << endl;
        cout <<"Opcion 4: Ver el Promedio de precios por Especie. " << endl;
        cout <<"Opcion 5: Buscar mascotas por Especie. " << endl;
        cout <<"Opcion 6: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: system("cls"); insetarMascota(mascotas, precios, contMascotas); system("cls"); break;
            case 2: system("cls"); mascotaMasCara(mascotas, contMascotas); system("cls"); break;
            case 3: system("cls"); calcularPerros(mascotas, contMascotas); system("cls"); break;
            case 4: system("cls"); promedioPreciosEspecies(precios, contMascotas); system("cls"); break;
            case 5: system("cls"); ordenamientoBurbuja(mascotas, contMascotas);
            buscarEspecieOrdenada(mascotas, contMascotas); system("cls"); break;
            case 6: cout <<"\nHasta luego. " << endl; break;
        }

    }while(opcion!=6);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
mascota insetarMascota(mascota mascotas[], preciosMascotas &precio, int &contMascotas)
{
    int cantMascotas;
    cout <<"\n\tHay [" << contMascotas <<"] mascotas en la tienda. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de mascotas a cargar: "; cin >> cantMascotas;

    if (contMascotas + cantMascotas > 20) 
    {
        cout <<"\nERROR: No hay suficiente espacio. Solo se pueden cargar " << (20 - contMascotas) << " mascotas más." << endl;

        cout <<"\nVolviendo al menu [ENTER]..." << endl;
        system("PAUSE");
        return *mascotas;
    }

    if (contMascotas>=20)
    {
        cout << "La tienda ya tiene 20 mascotas cargadas. No se pueden cargar más." << endl;

        cout <<"\nVolviendo al menu [ENTER]..." << endl;
        system("PAUSE");
        return *mascotas;
    }

    for(int i=0; i<cantMascotas && contMascotas<20; i++)
    {

        cin.ignore();
        cout <<"\nNombre: "; cin.getline(mascotas[contMascotas].nombre, 30, '\n');
        cout <<"Especie [PERRO]/[GATO]/[CONEJO]: "; cin.getline(mascotas[contMascotas].especie, 10, '\n');
        strupr(mascotas[contMascotas].especie);
        cout <<"Edad: "; cin >> mascotas[contMascotas].edad;
        cout <<"Precio: "; cin >> mascotas[contMascotas].precio;

        // Actualizar precios
        if(strcmp(mascotas[contMascotas].especie, "PERRO") == 0)
        {
            precio.totalPreciosP += mascotas[contMascotas].precio;
            precio.contPerros++;
        }
        else if(strcmp(mascotas[contMascotas].especie, "GATO") == 0)
        {
            precio.totalPreciosG += mascotas[contMascotas].precio;
            precio.contGatos++;
        }
        else if(strcmp(mascotas[contMascotas].especie, "CONEJO") == 0)
        {
            precio.totalPreciosC += mascotas[contMascotas].precio;
            precio.contConejos++;
        }

        contMascotas++;
    }

    return *mascotas;
}

void mascotaMasCara(mascota mascotas[], int contMascotas)
{
    float mascotaCara=0; int edad=0;
    char especie[10], nombre[30];
    cout <<"\n\tHay [" << contMascotas <<"] mascotas en la tienda. " << endl;

    for(int i=0; i<contMascotas; i++)
    {
        if(mascotas[i].precio > mascotaCara)
        {
            mascotaCara = mascotas[i].precio;
            strcpy(nombre, mascotas[i].nombre);
            strcpy(especie, mascotas[i].especie);
            edad = mascotas[i].edad;
        }
    }

    cout <<"\nLa mascota mas cara de la tienda vale $" << mascotaCara <<" dolares. " << endl;
    cout <<"Nombre: " << nombre << endl;
    cout <<"Especie: " << especie << endl;
    cout <<"Edad: " << edad << endl;

    cout <<"\nVolviendo al menu [ENTER]..." << endl;
    system("PAUSE");
}

void calcularPerros(mascota mascotas[], int contMascotas)
{
    cout <<"\n\tHay [" << contMascotas <<"] mascotas en la tienda. " << endl;
    cout <<"\nDatos de todos los perros menores a 2 años." << endl;
    for(int i=0; i<contMascotas; i++)
    {
        if((strcmp(mascotas[i].especie, "PERRO") == 0) && mascotas[i].edad<2)
        {
            cout <<"\nMascota Nro [" << i+1 <<"]. " << endl; 
            cout <<"Nombre: " << mascotas[i].nombre << endl;
            cout <<"Edad: " << mascotas[i].edad << endl;
            cout <<"Precio: " << mascotas[i].precio << endl;
        }
    }

    cout <<"\nVolviendo al menu [ENTER]..." << endl;
    system("PAUSE");
}

void promedioPreciosEspecies(preciosMascotas precios, int contMascotas)
{
    cout <<"\n\tHay [" << contMascotas <<"] mascotas en la tienda. " << endl;
    
    cout <<"\nPromedio de precios por especie. " << endl;
    if (precios.contPerros > 0)
    {
        cout <<"Perros: $" << precios.totalPreciosP/precios.contPerros <<"Dolares. " << endl;
    }else{
        cout <<"\nNo hay registros de perros en la tienda. " << endl;
    }
    
    if (precios.contGatos > 0)
    {
        cout <<"Gatos: $" << precios.totalPreciosG/precios.contGatos <<"Dolares. " << endl;
    }else{
        cout <<"\nNo hay registros de gatos en la tienda. " << endl;
    }

    if (precios.contConejos > 0)
    {
        cout <<"Conejos: $" << precios.totalPreciosC/precios.contConejos <<"Dolares. " << endl;
    }else{
        cout <<"\nNo hay registros de conejos en la tienda. " << endl;
    }

    cout <<"\nVolviendo al menu [ENTER]..." << endl;
    system("PAUSE");
}

void ordenamientoBurbuja(mascota mascotas[], int len)
{
    mascota aux;
    cout <<"\n\tHay [" << len <<"] mascotas en la tienda. " << endl;

    for (int i=0; i < len; i++) 
    {
        for(int j=0; j<len; j++)
        {
            if(mascotas[j].precio>mascotas[j+1].precio)
            {
                aux = mascotas[j];
                mascotas[j] = mascotas[j+1];
                mascotas[j+1] = aux;
            }
        }
    }
}

void buscarEspecieOrdenada(mascota mascotas[], int contMascotas)
{
    char especieBuscada[10];
    cin.ignore();
    cout << "Ingrese especie a buscar: "; cin.getline(especieBuscada, 10, '\n');
    strupr(especieBuscada);

    for (int i = 0; i < contMascotas; i++) 
    {
        if (strcmp(mascotas[i].especie, especieBuscada) == 0) 
        {
            cout << "\nNombre: " << mascotas[i].nombre << endl;
            cout << "Edad: " << mascotas[i].edad << endl;
            cout << "Precio: " << mascotas[i].precio << endl;
        }
    }

    cout <<"\nVolviendo al menu [ENTER]..." << endl;
    system("PAUSE");
}