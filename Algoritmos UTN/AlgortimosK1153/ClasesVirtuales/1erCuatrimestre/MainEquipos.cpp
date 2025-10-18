
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

using namespace std;

struct equipo
{
    int idEquipo;
    char nombre[30];
    char facultad[30];
}equipos[2];

// Declaracion de las funciones.
equipo cargarEquipos(equipo [], int &);

int main()
{
    int contEquipos=0;
    cargarEquipos(equipos, contEquipos);

    FILE* archivo = fopen("equipos.dat", "ab");
    if(archivo!=NULL)
    {
        fwrite(equipos, sizeof(equipo), 2, archivo);
        fclose(archivo);
        cout << "Archivo de equipos actualizado exitosamente." << endl;
    }else{
        cout << "No se pudo actualizar el archivo." << endl;
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
equipo cargarEquipos(equipo equipos[], int &contEquipos)
{
    cout <<"\nFormulario de inscripcion. " << endl;

    for(int i=0; i<2; i++)
    {
        cout <<"\nID del equipo: "; cin >> equipos[contEquipos].idEquipo;
        cin.ignore();
        cout <<"Nombre del equipo: "; cin.getline(equipos[contEquipos].nombre, 30, '\n');
        cin.ignore();
        cout <<"Facultad del equipo: "; cin.getline(equipos[contEquipos].facultad, 30, '\n');
        
        cin.ignore();
        contEquipos++;
    }

    return *equipos;
}