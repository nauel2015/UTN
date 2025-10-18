
// Clase N°7: 02/07/2025.
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

/* Ejercicio T.P: Torneo Relámpago UTN.

La UTN organiza un torneo relámpago de fútbol 5 entre distintas facultades.
Cada facultad puede presentar más de un equipo.

1. Implementar una función buscarEquipoDelJugador que reciba el DNI de un jugador y retorne el Equipo al que pertenece.
2. Implementar una función que muestre la cantidad de jugadores y edad promedio de cada equipo, mostrando el nombre de cada equipo:

Equipo: Los Físicos (Facultad de Ciencias Exactas)
Tiene 5 jugadores con un promedio de edad de 22
Equipo: Los Turing (Facultad de Ingeniería en Sistemas)
Tiene 7 jugadores con un promedio de edad de 21
...
..
..

3. Implementar una función que muestre por pantalla el jugador más grande.
4. Implementar una función que muestre por pantalla la facultad con más equipos.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct jugador
{
    int dni;
    char nombre[30];
    int edad;
    int idEquipo; // identificador del equipo al que pertenece
}jugadores[500];

struct equipo
{
    int idEquipo;
    char nombre[30];
    char facultad[30];
};

// Declaracion de las funciones.
jugador cargarJugadores(jugador [], int &);
int buscarJugadorPorDni(jugador [], int, int);
equipo buscarEquipoPorId(int);
void buscarEquipoDelJugador(jugador [], int);
void mostrarJugadoresPorEquipo(jugador [], int);
void jugadorMasGrande(jugador [], int);
void facultadConMasEquipos();

int main()
{

    int opcion, contJugadores=0;

    do{
        cout <<"\n\tTorneo Relampago UTN." << endl;
        cout <<"\nOpcion 1: Cargar Jugadores. ";
        cout <<"\nOpcion 2: Buscar el equipo de un jugador por DNI. ";
        cout <<"\nOpcion 3: Mostrar equipos con todos sus jugadores. ";
        cout <<"\nOpcion 4: Mostrar jugador con mayor edad en el torneo. ";
        cout <<"\nOpcion 5: Mostrar facultad con mas equipos. ";
        cout <<"\nOpcion 6: Salir. ";

        cout <<"\n\nIngrese su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: system("CLS"); cargarJugadores(jugadores, contJugadores); system("CLS"); break;
            case 2: system("CLS"); buscarEquipoDelJugador(jugadores, contJugadores); system("CLS"); break;
            case 3: system("CLS"); mostrarJugadoresPorEquipo(jugadores, contJugadores); system("CLS"); break;
            case 4: system("CLS"); jugadorMasGrande(jugadores, contJugadores); system("CLS"); break;
            case 5: system("CLS"); facultadConMasEquipos(); system("CLS"); break;
            case 6: cout <<"\nHasta luego. " << endl; break;
        }

    }while(opcion!=6);

    FILE* archivo = fopen("jugadores.dat", "ab");

    if(archivo!=NULL)
    {
        fwrite(jugadores, sizeof(jugador), 10, archivo);
        fclose(archivo);

        cout << "Archivo de jugadores actualizado exitosamente." << endl;
    }else{
        cout << "No se pudo actualizar el archivo." << endl;
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
jugador cargarJugadores(jugador jugadores[], int &contJugadores)
{
    int cantJugadores;
    cout <<"\nCantidad de jugadores en el sistema[" << contJugadores <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de jugadores a cargar: "; cin >> cantJugadores;

    for(int i=0; i<cantJugadores; i++)
    {
        cin.ignore();
        cout <<"\njugador Nro " << contJugadores+1 <<". " << endl;
        cout <<"Nombre: "; cin.getline(jugadores[contJugadores].nombre, 30, '\n');
        cout <<"Edad: "; cin >> jugadores[contJugadores].edad;
        cout <<"Dni: "; cin >> jugadores[contJugadores].dni;
        cout <<"ID de Equipo: "; cin >> jugadores[contJugadores].idEquipo;

        contJugadores++;
    }

    return *jugadores;
}

int buscarJugadorPorDni(jugador jugadores[], int contJugadores, int dniBuscado)
{
    int i=0;
    while(i<contJugadores&&jugadores[i].dni!=dniBuscado)
    {
        i++;
    }

    if(i==contJugadores)
    {
        return -1;
    }else{
        return i;
    }
}

equipo buscarEquipoPorId(int equipoBuscado)
{
    equipo equipos;
    FILE* archivo = fopen("equipos.dat","rb");
    if(archivo!=NULL)
    {
        while(fread(&equipos, sizeof(equipo), 1, archivo)==1)
        {
            if(equipos.idEquipo==equipoBuscado)
            {
                fclose(archivo);
                return equipos;
            }
        }

    }else{
        cout <<"\nNo se pudo abrir el archivo. " << endl;

        system("PAUSE");
    }

    // Si no se encontró el equipo, devolvemos uno vacío con id -1
    equipo vacio;
    vacio.idEquipo = -1;
    strcpy(vacio.nombre, "Desconocido");
    strcpy(vacio.facultad, "Desconocida");

    return vacio;
}

void buscarEquipoDelJugador(jugador jugadores[], int contJugadores)
{
    int dniBuscado, posJugador;
    cout <<"\n\tIngrese el dni del jugador: "; cin >> dniBuscado;
    system("CLS");
    posJugador = buscarJugadorPorDni(jugadores, contJugadores, dniBuscado);
    if(posJugador==-1)
    {
        cout <<"\n\tJugador no encontrado. " << endl;

        cout <<"\nVolviendo al menu...";
        system("PAUSE");
    }else{
        equipo equipoDatos = buscarEquipoPorId(jugadores[posJugador].idEquipo);
        cout <<"\n\tDatos del jugador. " << endl;
        cout <<"\nDNI: " << jugadores[posJugador].dni;
        cout <<"\nNombre: " << jugadores[posJugador].nombre;
        cout <<"\nEdad: " << jugadores[posJugador].edad;
        cout <<"\nEquipo: " << equipoDatos.nombre;
        cout <<"\nFacultad: " << equipoDatos.facultad;

        cout <<"\n\nVolviendo al menu...";
        system("PAUSE");
    }
}



void mostrarJugadoresPorEquipo(jugador jugadores[], int contJugadores)
{
    FILE* archivo = fopen("equipos.dat", "rb");

    if (archivo == NULL)
    {
        cout << "\n\tNo se pudo abrir el archivo de equipos. " << endl;

        cout <<"\nVolviendo al menu.." << endl;
        system("PAUSE");
    }else if(archivo!=NULL)
    {
        equipo equipoDatos;
        cout <<"\n\tTabla de equipos. " << endl;
        while(fread(&equipoDatos, sizeof(equipo), 1, archivo)==1)
        {
            int jugadoresPorEquipo=0, totalEdades=0;

            for(int i=0; i<contJugadores; i++)
            {
                if(jugadores[i].idEquipo==equipoDatos.idEquipo)
                {
                    jugadoresPorEquipo++;
                    totalEdades += jugadores[i].edad;
                }
            }

            if(jugadoresPorEquipo>0)
            {
                int promedioEdad = totalEdades/jugadoresPorEquipo;

                cout <<"\nEquipo: " << equipoDatos.nombre;
                cout <<"\nTiene " << jugadoresPorEquipo <<" jugadores con un promedio de edad de " << promedioEdad <<" años. " << endl;
            }
        }

        fclose(archivo);

        cout <<"\nVolviendo al menu..." << endl;
        system("PAUSE");
    }
}

void jugadorMasGrande(jugador jugadores[], int contJugadores)
{
    if (contJugadores == 0) 
    {
        cout << "\n\tNo hay jugadores cargados.\n";

        cout <<"\nVolviendo al menu.." << endl;
        system("PAUSE");
        return;
    }

    int edadMayor=jugadores[0].edad, pos=0;
    equipo equipoDelJugador;

    for(int i=0; i<contJugadores; i++)
    {
        if(jugadores[i].edad>edadMayor)
        {
            edadMayor = jugadores[i].edad;
            pos = i;
        }
    }

    cout <<"\n\tJugador con mayor edad del torneo. " << endl;

    FILE* archivo = fopen("equipos.dat", "rb");
    if(archivo!=NULL)
    {
        while(fread(&equipoDelJugador, sizeof(equipo), 1, archivo)==1)
        {
            if(equipoDelJugador.idEquipo==jugadores[pos].idEquipo)
            {
                cout <<"\nEl jugador pertenece al equipo " << equipoDelJugador.nombre <<" de la " << equipoDelJugador.facultad;
                cout <<"\nDni: " << jugadores[pos].dni;
                cout <<"\nNombre: " << jugadores[pos].nombre;
                cout <<"\nEdad: " << jugadores[pos].edad;

                fclose(archivo);
                cout <<"\n\nVolviendo al menu.." << endl;
                system("PAUSE");
            }
        }
    }else{
        cout << "\n\tNo se pudo abrir el archivo de equipos. " << endl;

        cout <<"\nVolviendo al menu.." << endl;
        system("PAUSE");
    }

}

void facultadConMasEquipos()
{
    equipo equipos;
    FILE* archivo = fopen("equipos.dat", "rb");

    if(archivo!=NULL)
    {
        char facultades[100][30];  // hasta 100 facultades distintas
        int cantidadEquipos[100] = {0};
        int cantFacultades = 0;

        while(fread(&equipos, sizeof(equipo), 1, archivo)==1)
        {
            int i=0;
            while(i<cantFacultades&&strcmp(facultades[i], equipos.facultad)!=0)
            {
                i++;
            }

            if(i==cantFacultades)
            {
                strcpy(facultades[cantFacultades], equipos.facultad);
                cantidadEquipos[cantFacultades] = 1;
                cantFacultades++;
            }else{
                cantidadEquipos[i]++;
            }  
        }

    // Buscar facultad con más equipos
        int maxEquipos = cantidadEquipos[0];
        int posMax = 0;

        for (int i = 1; i < cantFacultades; i++)
        {
            if (cantidadEquipos[i] > maxEquipos)
            {
                maxEquipos = cantidadEquipos[i];
                posMax = i;
            }
        }

        cout << "\n\tFacultad con más equipos. " << endl; 
        cout <<"\nFacultad: " << facultades[posMax] << " con " << maxEquipos << " equipos." << endl;
    }

    fclose(archivo);
    cout <<"\nVolviendo al menu..." << endl;
    system("PAUSE");
}