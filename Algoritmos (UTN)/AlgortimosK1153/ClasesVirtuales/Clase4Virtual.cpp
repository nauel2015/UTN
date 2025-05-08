//
// Clase N°4: 7/05/2025
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

// Ejercicio en clase N°1: Crea una estructura llamada Tiempo que tenga los campos horas, minutos y segundos.
// Luego, crea una función que tome dos estructuras Tiempo y calcule la diferencia entre ambas en segundos y la retorne.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct tiempo
{
    int horas;
    int minutos;
    int segundos;
}tiempo1, tiempo2;

// Declaracion de las funciones:
int calcularSegundos(tiempo);
int convertirPositivo(int);
int calcularDiferenciaTiempo(tiempo, tiempo);

int main()
{
    int segTiempo1, segTiempo2;
    cout <<"\nIngrese la cantidad de segundos del tiempo 1: "; cin >> segTiempo1;

    // Tiempo 1.
    tiempo1.horas = segTiempo1/3600;
    segTiempo1 %= 3600;
    tiempo1.minutos = segTiempo1/60;
    tiempo1.segundos = segTiempo1%60;

    cout <<"\nEl tiempo equivalente a la cantidad de segundos ingresados para el primer tiempo es: " << tiempo1.horas << " horas, " << tiempo1.minutos << " minutos y " << tiempo1.segundos << " segundos." << endl;
    cout <<"\nIngrese la cantidad de segundos del tiempo 2: "; cin >> segTiempo2;

    // Tiempo 2.
    tiempo2.horas = segTiempo2/3600;
    segTiempo2 %= 3600;
    tiempo2.minutos = segTiempo2/60;
    tiempo2.segundos = segTiempo2%60;

    cout <<"El tiempo equivalente a la cantidad de segundos ingresados para el segundo tiempo es: " << tiempo2.horas << " horas, " << tiempo2.minutos << " minutos y " << tiempo2.segundos << " segundos." << endl;

    cout <<"\nLa diferencia en segundos entre estos 2 tiempos es de: " << calcularDiferenciaTiempo(tiempo1, tiempo2) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:

int calcularSegundos(tiempo t)
{
    int totalSeg = t.horas * 3600 + t.minutos * 60 + t.segundos;
    return totalSeg;
}

int convertirPositivo(int diferencia)
{
    if(diferencia > 0)
    {
        return diferencia;
    }else{
        return diferencia*-1;
    }
}

int calcularDiferenciaTiempo(tiempo t1, tiempo t2)
{
    int totalSeg1 = calcularSegundos(t1);
    int totalSeg2 = calcularSegundos(t2);
    int resultado = totalSeg1-totalSeg2;

    return convertirPositivo(resultado);
}

// Ejercicio en clase N°2: realizar una funcion que le pida al usuario que ingrese los segundos, minutos y horas de 1 tiempo y lo retorne.
// Ademas quiero hacer que el usuario ingrese 5 tiempos y guardarlos en un array. 

#include<iostream>
#include<stdlib.h>

using namespace std;

struct tiempo
{
    int horas;
    int minutos;
    int segundos;
};

// Declaracion de las funciones:
tiempo dameTiempo(tiempo);
void mostrarTiempo(tiempo);

int main()
{
    tiempo tiempos[5];

    cout <<"\nIngrese los tiempos que tendra almacenado el arrays." << endl;
    for(int i=0; i<5; i++)
    {
        cout <<"\nPosicion [" << i << "]: ";
        tiempos[i] = dameTiempo(tiempos[i]);
    }

    cout <<"\nTotal de tiempos ingresados: " << endl;
    for(int i=0; i<5; i++)
    {
        cout << i+1 <<". ";
        mostrarTiempo(tiempos[i]);
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:

tiempo dameTiempo(tiempo t)
{
    do {
        cout << "\nIngrese la cantidad de horas (0-23): ";
        cin >> t.horas;
        if(t.horas < 0 || t.horas > 23)
            cout << "Horas inválidas. Deben estar entre 0 y 23.\n";
    } while(t.horas < 0 || t.horas > 23);

    do {
        cout << "Ingrese la cantidad de minutos (0-59): ";
        cin >> t.minutos;
        if(t.minutos < 0 || t.minutos > 59)
            cout << "Minutos inválidos. Deben estar entre 0 y 59.\n";
    } while(t.minutos < 0 || t.minutos > 59);

    do {
        cout << "Ingrese la cantidad de segundos (0-59): ";
        cin >> t.segundos;
        if(t.segundos < 0 || t.segundos > 59)
            cout << "Segundos inválidos. Deben estar entre 0 y 59.\n";
    } while(t.segundos < 0 || t.segundos > 59);

    return t;
}

void mostrarTiempo(tiempo t)
{
    cout <<"Tiempo ingresado: " << t.horas << " horas, " << t.minutos << " minutos y " << t.segundos << " segundos." << endl;
}
