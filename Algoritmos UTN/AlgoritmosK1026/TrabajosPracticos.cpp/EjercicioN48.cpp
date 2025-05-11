// Ejercicio Nro. 48: Ingresar un valor entero N (< 40).
// Luego ingresar un conjunto REFER de N elementos reales (ingresan ordenados por magnitud creciente).
// Finalmente ingresar un valor pesquisa X. Desarrollar el programa que determine e imprima:
// a) Con cual elemento (posición) del conjunto coincide, o
// b) Entre cuales dos elementos (posiciones) se encuentra, o
// c) Si es menor que el primero o mayor que el último.

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() 
{
    int N;
    
    // Ingresar el valor de N
    cout << "Ingrese el valor de N (< 40): ";
    cin >> N;
    if (N >= 40) 
    {
        cout << "Error: N debe ser menor que 40." << endl;
        return 1;
    }

    // Ingresar los elementos del conjunto REFER
    vector<double> REFER(N);
    cout << "Ingrese los elementos del conjunto REFER (en orden creciente):" << endl;
    for (int i = 0; i < N; ++i) 
    {
        cin >> REFER[i];
    }

    // Ingresar el valor de pesquisa X
    double X;
    cout << "Ingrese el valor de pesquisa X: ";
    cin >> X;

    // Determinar la posición de X en el conjunto REFER
    bool found = false;
    for (int i = 0; i < N; ++i) 
    {
        if (X == REFER[i]) 
        {
            cout << "El valor X coincide con el elemento en la posición " << i << "." << endl;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        if (X < REFER[0]) 
        {
            cout << "El valor X es menor que el primer elemento." << endl;
        } else if (X > REFER[N-1]) 
        {
            cout << "El valor X es mayor que el último elemento." << endl;
        } else 
        {
            for (int i = 0; i < N-1; ++i) 
            {
                if (X > REFER[i] && X < REFER[i+1]) 
                {
                    cout << "El valor X se encuentra entre los elementos en las posiciones " << i << " y " << i+1 << "." << endl;
                    break;
                }
            }
        }
    }

    system("pause");
    return 0;
}
