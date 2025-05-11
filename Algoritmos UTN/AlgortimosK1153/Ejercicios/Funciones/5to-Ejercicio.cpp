
// Ejercicio N°5: Implementa una función que reciba un número entero y devuelva su factorial. 

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de la funcion:
int factorial(int);

int main()
{
    int n;
    cout <<"\nIngrese un Numero: "; cin >> n;

    cout <<"\nEl Factorial del numero es: " << factorial(n) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int factorial(int nfactorial)
{
    if(nfactorial<0)
    {
        cout <<"Error. El factorial no esta definido para numeros negativos." << endl;
        return -1;
    }
    else if(nfactorial==1)
    {
        return 1;
    }else{
        return nfactorial*factorial(nfactorial-1);
    }
}