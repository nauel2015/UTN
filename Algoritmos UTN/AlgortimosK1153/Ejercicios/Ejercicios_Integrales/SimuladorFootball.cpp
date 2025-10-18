
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
};

// Declaracion de las funciones.
void mejorCalidadEquipo(Equipo, int &, int &);
void equipoConMayorSocios(Equipo, int &, int &);
void mejorJugador(Equipo, int &, int &);
void peorJugador(Equipo, int &, int &);
void mejorEquipo(Equipo, int &, int &);

int main()
{
    int opcion, contGol1=0, contGol2=0;
    Equipo equipo;

    do{
        cout <<"\n\tSimulador de football. " << endl;
        cout <<"\nReglas de la partida: " << endl;
        cout <<"\n1- El equipo que suma mas calidad en sus jugadores suma 2 goles. ";
        cout <<"\n2- El equipo que tiene mas cantidad de socios suma un gol. ";
        cout <<"\n3- El equipo que tiene al mejor jugadores suma 1 gol. ";
        cout <<"\n4- El equipo que tiene al peor jugador resta 1 gol (solo si tiene goles a favor) ";
        cout <<"\n5- Comparando jugador por jugador segun su nivel, se suma un gol por cada jugador mejor. ";

        cout <<"\n\nPresione [1] para comenzar o [2] para cancelar la simulacion. "; cin >> opcion;

        if(opcion==1)
        {
            system("cls");
            cout <<"\n\tPrimera ronda: Competencia por calidad de equipos. " << endl;
            mejorCalidadEquipo(equipo, contGol1, contGol2);
            system("cls");
            cout <<"\n\tSegunda ronda: Competencia por cantidad de socios. " << endl;
            equipoConMayorSocios(equipo, contGol1, contGol2);
            system("cls");
            cout <<"\n\tTercera ronda: Competencia por el mejor jugador. " << endl;
            mejorJugador(equipo, contGol1, contGol2);
            system("cls");
            cout <<"\n\tCuarta ronda: Competencia por el peor jugador. " << endl;
            peorJugador(equipo, contGol1, contGol2);
            system("cls");
            cout <<"\n\tUltima ronda: Competencia entre jugadores segun sus puntos de calidad. " << endl;
            mejorEquipo(equipo, contGol1, contGol2);
            system("cls");
        }else if(opcion==2){
            system("cls");
            cout <<"\n\tSumulador finalizado. " << endl;
        }

    }while(opcion!=2);


    cout <<"\n- Nahuel Richeri\n";
    return 0;
}

// Definicion de las funciones.
void mejorCalidadEquipo(Equipo equipo, int &contGol1, int &contGol2)
{
    FILE* archivo = fopen("resultados.dat", "rb");
    if(archivo!=NULL)
    {
        int puntosDeCalidad1=0, puntosDeCalidad2=0;
        char nombre1[30], nombre2[30];

        while(fread(&equipo, sizeof(Equipo), 1, archivo)==1)
        {
            if(equipo.id_Equipo==1)
            {
                strcpy(nombre1, equipo.nombre);
                for(int i=0; i<5;i++)
                {
                    puntosDeCalidad1+=equipo.jugadores[i].puntos_De_Calidad;
                }

            }else if(equipo.id_Equipo==2){
                for(int i=0; i<5;i++)
                {
                    strcpy(nombre2, equipo.nombre);
                    puntosDeCalidad2+=equipo.jugadores[i].puntos_De_Calidad;
                }
            }
        }

        fclose(archivo);

        if(puntosDeCalidad1>puntosDeCalidad2)
        {
            cout <<"\nEl equipo: " << nombre1 <<" gana la ronda y suma 2 goles. ";
            contGol1+=2;
        }else{
            cout <<"\nEl equipo: " << nombre2 <<" gana la ronda y suma 2 goles. ";
            contGol2+=2;
        }
    }

    cout <<"\n\nContinuando con la siguiente ronda. " << endl;
    system("PAUSE");
}

void equipoConMayorSocios(Equipo equipo, int &contGol1, int &contGol2)
{
    FILE* archivo = fopen("resultados.dat", "rb");
    if(archivo!=NULL)
    {
        int socios1=0, socios2=0;
        char nombre1[30], nombre2[30];

        while(fread(&equipo, sizeof(Equipo), 1, archivo)==1)
        {
            if(equipo.id_Equipo==1)
            {
                strcpy(nombre1, equipo.nombre);
                socios1 = equipo.socios;
            }else if(equipo.id_Equipo==2){
                strcpy(nombre2, equipo.nombre);
                socios2 = equipo.socios;
            }
        }

        fclose(archivo);

        if(socios1>socios2)
        {
            cout <<"\nEl equipo: " << nombre1 <<" gana la ronda y suma 1 gol. ";
            contGol1++;
        }else{
            cout <<"\nEl equipo: " << nombre2 <<" gana la ronda y suma 1 gol. ";
            contGol2++;
        }
    }

    cout <<"\n\nContinuando con la siguiente ronda. " << endl;
    system("PAUSE");
}

void mejorJugador(Equipo equipo, int &contGol1, int &contGol2)
{
    FILE* archivo = fopen("resultados.dat", "rb");
    if(archivo!=NULL)
    {
        int mejor, mejorJugador1=0, mejorJugador2=0;
        char nombre1[30], nombre2[30];

        while(fread(&equipo, sizeof(Equipo), 1, archivo)==1)
        {
            mejor = equipo.jugadores[0].puntos_De_Calidad;
            for(int i=1; i<5; i++)
            {
                if(equipo.jugadores[i].puntos_De_Calidad>mejor)
                {
                    mejor = equipo.jugadores[i].puntos_De_Calidad;
                }
            }

            if(equipo.id_Equipo==1)
            {
                mejorJugador1 = mejor;
                strcpy(nombre1, equipo.nombre);
            }else{
                mejorJugador2 = mejor;
                strcpy(nombre2, equipo.nombre);
            }
        }

        fclose(archivo);

        if(mejorJugador1>mejorJugador2)
        {
            cout <<"\nEl equipo: " << nombre1 <<" gana la ronda y suma 1 gol. ";
            contGol1++;
        }else if (mejorJugador1<mejorJugador2){
            cout <<"\nEl equipo: " << nombre2 <<" gana la ronda y suma 1 gol. ";
            contGol2++;
        }else{
            cout <<"\nEmpate ambos equipos pasan la ronda y no suman ni restan puntos. ";
        }
    }

    cout <<"\n\nContinuando con la siguiente ronda. " << endl;
    system("PAUSE");
}

void peorJugador(Equipo equipo, int &contGol1, int &contGol2)
{
    FILE* archivo = fopen("resultados.dat", "rb");
    if(archivo!=NULL)
    {
        int peor, Jugador1=0, Jugador2=0;
        char nombre1[30], nombre2[30];

        while(fread(&equipo, sizeof(Equipo), 1, archivo)==1)
        {
            peor = equipo.jugadores[0].puntos_De_Calidad;

            for(int i=1; i<5; i++)
            {
                if(equipo.jugadores[i].puntos_De_Calidad<peor)
                {
                    peor = equipo.jugadores[i].puntos_De_Calidad;
                }
            }

            if(equipo.id_Equipo==1)
            {
                Jugador1 = peor;
                strcpy(nombre1, equipo.nombre);
            }else{
                Jugador2 = peor;
                strcpy(nombre2, equipo.nombre);
            }
        }

        fclose(archivo);

        if(Jugador1<Jugador2)
        {
            cout <<"\nEl equipo: " << nombre1 <<" pierde la ronda y se le resta 1 gol. ";
            if(contGol1>0)
            contGol1--;
            if(contGol2>0)
            contGol2--;
        }else if (Jugador1>Jugador2){
            cout <<"\nEl equipo: " << nombre2 <<" pierde la ronda y se le resta 1 gol. ";
            contGol2--;
        }else{
            cout <<"\nEmpate ambos equipos pasan la ronda y no suman ni restan puntos. ";
        }
    }

    cout <<"\n\nContinuando con la siguiente ronda. " << endl;
    system("PAUSE");
}

void mejorEquipo(Equipo equipo, int &contGol1, int &contGol2)
{
    FILE* archivo = fopen("resultados.dat", "rb");
    if(archivo!=NULL)
    {
        char equipoNombre1[30], equipoNombre2[30];
        Equipo equipo1, equipo2;

        while(fread(&equipo, sizeof(Equipo), 1, archivo)==1)
        {
            if(equipo.id_Equipo==1)
            {
                strcpy(equipoNombre1, equipo.nombre);
                equipo1=equipo;
            }else if(equipo.id_Equipo==2){
                strcpy(equipoNombre2, equipo.nombre);
                equipo2=equipo;
            }
        }

        fclose(archivo);

        for(int i=0; i<5; i++)
        {
            cout <<"\n" << equipo1.jugadores[i].nombre <<" vs " << equipo2.jugadores[i].nombre << endl;

            if(equipo1.jugadores[i].puntos_De_Calidad>equipo2.jugadores[i].puntos_De_Calidad)
            {
                cout <<"El jugador: " << equipo1.jugadores[i].nombre <<" gana la ronda y suma un gol. " << endl;
                contGol1++;
            }else if(equipo1.jugadores[i].puntos_De_Calidad<equipo2.jugadores[i].puntos_De_Calidad){
                cout <<"El jugador: " << equipo2.jugadores[i].nombre <<" gana la ronda y suma un gol. " << endl;
                contGol2++;
            }else{
                 cout << "Empate entre ambos jugadores. Ninguno suma gol.\n";
            }
        }

        cout <<"\n\nFinalizando el simulador de football. " << endl;
        system("PAUSE"); system("cls");

        cout <<"\n\tResultados finales del partido. " << endl;
        cout <<"\n" << equipoNombre1 <<" [" << contGol1 <<"][" << contGol2 <<"] " << equipoNombre2 << endl;
        cout <<"\n\tSumulador finalizado... " << endl;
        system("PAUSE");
    }
}