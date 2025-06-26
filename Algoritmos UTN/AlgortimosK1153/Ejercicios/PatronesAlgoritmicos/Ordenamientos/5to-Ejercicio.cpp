
/* Ejercicio N°5: Siendo Equipo { string nombre; int puntos } . Crear una función que devuelva la tabla de posiciones ordenada por los
puntos obtenidos. 

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct equipo
{
    char nombreEquipo[30];
    int puntos=0;
}equipos[20];

// Declaracion de las funciones.
equipo cargarEquipos(equipo [], int &);
equipo ordenamientoBurbuja(equipo [], int);
void mostrarTablaPuntajes(equipo [], int);

int main()
{
    int contEquipos=0, opcion=0;
    do{
        cout <<"\n\tCompeticion. " << endl << endl;
        cout <<"Opcion 1: Cargar Equipos. " << endl;
        cout <<"Opcion 2: Mostrar Tabla de Puntajes. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarEquipos(equipos, contEquipos); system("cls"); break;
            case 2: system("cls"); ordenamientoBurbuja(equipos, contEquipos);
            mostrarTablaPuntajes(equipos, contEquipos); system("cls"); break;
            case 3: cout <<"\nHasta Luego. " << endl; break;
        }

    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
equipo cargarEquipos(equipo equipos[], int &contEquipos)
{
    int cantEquipos;
    cout <<"\n\tHay [" << contEquipos <<"] en la competencia. " << endl;
    cin.ignore();
    cout <<"\ningrese la cantidad de equipos a cargar: "; cin >> cantEquipos;

    if(cantEquipos+contEquipos>20)
    {
        cout <<"ERROR. Cupos insuficientes. solo pueden ingresar hasta " <<(20-contEquipos) <<" equipos mas. " << endl;

        cout <<"\nVolviendo al menu... [ENTER]" << endl;
        system("PAUSE");
        return *equipos;
    }

    if(contEquipos>20)
    {
        cout <<"\nCupos llenos, ya no pueden ingresar mas equipos a la competicion. " << endl;

        cout <<"\nVolviendo al menu... [ENTER]" << endl;
        system("PAUSE");
        return *equipos;
    }

    cout <<"Proceda con la carga de datos. " << endl;

    for(int i=0; i<cantEquipos; i++)
    {
        cin.ignore();
        cout <<"\nNombre del equipo: "; cin.getline(equipos[contEquipos].nombreEquipo, 30, '\n');
        cout <<"Puntos ganados: "; cin >> equipos[contEquipos].puntos;
        contEquipos++;
    }

    return *equipos;
}

equipo ordenamientoBurbuja(equipo equipos[], int contEquipos)
{
    equipo aux;
    for(int i=0; i<contEquipos; i++)
    {
        for(int j=0; j<contEquipos-1; j++)
        {
            if(equipos[j].puntos<equipos[j+1].puntos)
            {
                aux = equipos[j];
                equipos[j] = equipos[j+1];
                equipos[j+1] = aux;
            }
        }
    }

    return *equipos;
}

void mostrarTablaPuntajes(equipo equipos[], int contEquipos)
{
    cout <<"\n\tTabla de Puntajes. " << endl;
    for(int i=0; i<contEquipos; i++)
    {
        if(equipos[i].puntos!=0)
        {
            cout <<"\n" << i+1 <<". Lugar: " << equipos[i].nombreEquipo <<" [" << equipos[i].puntos <<"] puntos. ";
        }
    }

    cout <<"\nVolviendo al menu... [ENTER]" << endl;
    system("PAUSE");
}