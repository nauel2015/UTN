// Ejercicio Nro. 47: Ingresar dos valores enteros M (< 25) y N (< 10)
// A continuación ingresar un conjunto A de M elementos y luego otro B de N elementos, ambos ordenados en forma creciente por magnitud.
// Generar e imprimir el conjunto TOTAL resultante del apareo por magnitud de los conjuntos A y B.

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() 

{
    int M, N;

    // Ingresar los valores de M y N
    cout << "Ingrese el valor de M (< 10): ";
    cin >> M;
    if (M >= 10) 
    {
        cout << "Error: M debe ser menor que 10." << endl;
        return 1;
    }

    cout << "Ingrese el valor de N (< 15): ";
    cin >> N;
    if (N >= 15) 
    {
        cout << "Error: N debe ser menor que 15." << endl;
        return 1;
    }

    // Ingresar los elementos del conjunto A
    vector<int> A(M);
    cout << "Ingrese los elementos del conjunto A:" << endl;
    for (int i = 0; i < M; ++i) 
    {
        cin >> A[i];
    }

    // Ingresar los elementos del conjunto B
    vector<int> B(N);
    cout << "Ingrese los elementos del conjunto B:" << endl;
    for (int i = 0; i < N; ++i) 
    {
        cin >> B[i];
    }

    // Generar el conjunto C resultante de la anexión de A y B
    vector<int> C;
    C.insert(C.end(), A.begin(), A.end());
    C.insert(C.end(), B.begin(), B.end());

    // Imprimir el conjunto C
    cout << "Conjunto C (anexión de A y B): ";
    for (int elem : C) 
    {
        cout << elem << " ";
    }
    cout << endl;

    // Generar el conjunto D con los elementos distintos de cero de A y B
    vector<int> D;
    for (int elem : A) 
    {
        if (elem != 0) 
        {
            D.push_back(elem);
        }
    }
    for (int elem : B) 
    {
        if (elem != 0) 
        {
            D.push_back(elem);
        }
    }

    // Imprimir el conjunto D
    cout << "Conjunto D (elementos distintos de cero de A y B): ";
    for (int elem : D) 
    {
        cout << elem << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}