
// Ejercicio Nro. 49: Ingresar un valor entero CANT (< 50) y a continuación un conjunto SINOR de CANT elementos.
// Desarrollar un programa que determine e imprima:
// a) El conjunto SINOR en el que cada elemento original se intercambie por su simétrico: A[1] con A[CANT], A[2] con A[N-1], ..... etc.
// b) El conjunto SINOR ordenado de menor a mayor sobre si mismo indicando la posición que ocupaba cada elemento en el conjunto original.

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    int CANT;

    // Ingresar el valor de CANT
    cout << "Ingrese el valor de CANT (< 50): ";
    cin >> CANT;
    if (CANT >= 50) 
    {
        cout << "Error: CANT debe ser menor que 50." << endl;
        return 1;
    }

    // Ingresar los elementos del conjunto SINOR
    vector<int> SINOR(CANT);
    cout << "Ingrese los elementos del conjunto SINOR:" << endl;
    for (int i = 0; i < CANT; ++i) 
    {
        cin >> SINOR[i];
    }

    // a) Intercambiar cada elemento original por su simétrico
    vector<int> SIMETRICO = SINOR;
    for (int i = 0; i < CANT / 2; ++i) 
    {
        int temp = SIMETRICO[i];
        SIMETRICO[i] = SIMETRICO[CANT - 1 - i];
        SIMETRICO[CANT - 1 - i] = temp;
    }

    // Imprimir el conjunto SIMETRICO
    cout << "Conjunto SINOR con elementos intercambiados por su simétrico: ";
    for (int elem : SIMETRICO) 
    {
        cout << elem << " ";
    }
    cout << endl;

    // b) Ordenar el conjunto SINOR de menor a mayor y almacenar las posiciones originales
    vector<int> ordenado = SINOR;
    vector<int> posiciones(CANT);
    for (int i = 0; i < CANT; ++i) 
    {
        posiciones[i] = i;
    }

    // Implementar un algoritmo de ordenación por selección
    for (int i = 0; i < CANT - 1; ++i) 
    {
        int minIndex = i;
        for (int j = i + 1; j < CANT; ++j) 
        {
            if (ordenado[j] < ordenado[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            int temp = ordenado[i];
            ordenado[i] = ordenado[minIndex];
            ordenado[minIndex] = temp;

            // Intercambiar también las posiciones
            int tempPos = posiciones[i];
            posiciones[i] = posiciones[minIndex];
            posiciones[minIndex] = tempPos;
        }
    }

    // Imprimir el conjunto SINOR ordenado y las posiciones originales
    cout << "Conjunto SINOR ordenado de menor a mayor con posiciones originales: " << endl;
    for (int i = 0; i < CANT; ++i) 
    {
        cout << ordenado[i] << " (posición original: " << posiciones[i] << ")" << endl;
    }

    system("pause");
    return 0;
}