
// Clase N°7: 04/06/2025
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

/* Ejercicio en clase N°1: Tengo dos arrays con numeros que están desordenados,
y quiero juntarlos ordenados en un tercer array.

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de las funciones.
void apareo(int [], int, int [], int, int [], int &);

int main()
{
    int A[] = {1, 90, 5};
    int B[] = {2, 4, 60, 18};
    int C[10];
    int lenC;
	
    apareo(A, 3, B, 4, C, lenC);

    cout << "Vector resultado:\n";
    for (int i = 0; i < lenC; i++) {
        cout << C[i] << " ";
    }
    

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void apareo(int A[], int lenA, int B[], int lenB, int C[], int &lenC)
{
    int i=0, j=0;
    lenC=0;

    while (i < lenA && j < lenB)
    {
        if (A[i] <= B[j])
        {
            C[lenC] = A[i];
            lenC++;
            i++;
        }else{
            C[lenC] = B[j];
            lenC++;
            j++;
        }
    }

    while(i<lenA)
    {
        C[lenC] = A[i];
        lenC++;
        i++;
    }

    while(j<lenB)
    {
        C[lenC] = B[j];
        lenC++;
        j++;
    }

}