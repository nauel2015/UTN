
/* Ejercicio 1: Intercambio de valores usando punteros.

1. Escribe una función llamada intercambiar que reciba dos punteros a enteros e intercambie sus valores.
2. En el main , declara dos variables enteras, asígnales valores, y muestra sus valores antes y después de llamar a la función. 

*/
#include <iostream>
using namespace std;

void intercambiar(int *, int *);

int main() 
{
    int *a = new int, *b = new int;
    *a=5; 
    *b=7;
    intercambiar(a, b);

    cout <<"\nEl valor de a = " << a << endl;
    cout <<"El valor de b = " << b << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

void intercambiar(int *numero1, int *numero2)
{
    int aux = *numero1;
    *numero1 = *numero2;
    *numero2 = aux;
}