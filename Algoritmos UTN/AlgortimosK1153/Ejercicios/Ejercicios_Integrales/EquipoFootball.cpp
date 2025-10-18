
/* Ejercicio: Simulador de partidos de football.

Tenemos un cliente que quiere realizar un simulador de partidos de fútbol. El usuario debe ingresar 2 equipos de 5 jugadores cada uno.
Cada equipo tiene un nombre, una cantidad de socios y 5 jugadores. Cada jugador tiene un nombre y una cantidad de puntos de calidad.
Una vez cargados ambos equipos, el sistema muestra por pantalla el resultado del mismo y lo guarda en un archivo llamado “resultados.dat”

¿Cómo calcula el resultado? Bajo diferentes criterios.

- El equipo que suma más calidad en sus jugadores suma 2 goles.
- El equipo que tiene más cantidad de socios suma un gol.
- El equipo que tiene al mejor jugadores suma 1 gol.
- El equipo que tiene al peor jugador resta 1 gol (solo si tiene goles a favor)
- Comparando jugador por jugador según su nivel, se suma un gol por cada jugador mejor.
Es decir, se compara al mejor de un equipo contra el mejor del otro y suma gol el de mayor calidad.
Luego, se hace lo mismo con el segundo de cada equipo y suma gol el de mayor calidad.
Luego, se hace lo mismo con el tercero, cuarto y quinto.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Jugador
{
    char nombre[30];
    int puntos_De_Calidad;
};

struct Equipo
{
    char nombre[30];
    int id_Equipo;
    int socios;
    Jugador jugadores[5];
}equipos[2];

// Declaracion de las funciones.
Equipo cargarEquipoDeFootball(Equipo [], int);
void mostrarEquipos(Equipo []);
void GuardarEquiposArchivo(Equipo []);

int main()
{
    int opcion, len=0;
    do{
        cout <<"\n\tInscripcion de Equipos al partido. " << endl;
        cout <<"\nOpcion 1: cargar equipos. ";
        cout <<"\nOpcion 2: Mostrar equipos y guardarlos en un archivo.";

        cout <<"\n\n Indique su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: system("CLS"); cargarEquipoDeFootball(equipos, len); system("CLS"); break;
            case 2: system("CLS"); mostrarEquipos(equipos); system("CLS"); break;
            case 3: cout <<"\nHasta Luego!!! " << endl; break;
        }

    }while(opcion!=4);


    cout <<"\n- Nahuel Richeri\n";
    return 0;
}

// Definicion de las funciones.
Equipo cargarEquipoDeFootball(Equipo equipos[], int len)
{
    for(int i=0; i<2; i++)
    {
        cin.ignore();
        cout <<"\n\tIngrese el equipo. " << endl;
        cout <<"\nNombre del equipo: "; cin.getline(equipos[len].nombre, 30, '\n');
        cout <<"ID del equipo: "; cin >> equipos[len].id_Equipo;
        cout <<"Cantidad de socios: "; cin >> equipos[len].socios;
        cout <<"\n\tIngrese los jugadores del equipo. " << endl;
        for(int j=0; j<5; j++)
        {
            cin.ignore();
            cout <<"\njugador Nro [" << j+1 <<"]. " << endl;
            cout <<"Nombre: "; cin.getline(equipos[len].jugadores->nombre, 30, '\n');
            cout <<"Puntos de calidad: "; cin >> equipos[len].jugadores->puntos_De_Calidad;
        }
    }
    
    cin.ignore();
    return *equipos;
}

void mostrarEquipos(Equipo equipos[])
{
    cout <<"\n\tTabla de equipos inscriptos. " << endl;
    for(int i=0; i<2; i++)
    {
        cout <<"\nEquipo: " << equipos[i].nombre;
        cout <<"\nSocios: " << equipos[i].socios;
        cout <<"\n\nJugadores [5]." << endl;

        for(int j=0; j<5; j++)
        {
            cin.ignore();
            cout <<"\nNombre: " << equipos[j].jugadores->nombre;
            cout <<"Puntos de calidad: " << equipos[j].jugadores->puntos_De_Calidad << endl;
        }
    }

    GuardarEquiposArchivo(equipos);
}

void GuardarEquiposArchivo(Equipo equipos[])
{
    FILE* archivo = fopen("resultados.dat", "wb");
    if(archivo!=NULL)
    {
        fwrite(equipos, sizeof(Equipo), 2, archivo);
        fclose(archivo);
        cout <<"\nArchivo (resultados.dat) creado exitosamente. " << endl;
    }else{
        cout <<"\nArchivo (resultados.dat) fallido. " << endl;
    }

    cout <<"\nVolviendo al menu... " << endl;
    system("Pause");
}