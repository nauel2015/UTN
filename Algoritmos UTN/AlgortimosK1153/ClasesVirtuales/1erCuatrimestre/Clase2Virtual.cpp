

// Clase 2 virtual 23/04/2025
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

// QUiero crear un sistema en el cual el usuario ingrese 10 numeros y por cada uno le diga si es mayor o igual o menor que 18

#include<iostream>
#include<stdlib.h>

using namespace std;


int main()
{
    int cantNumero, numero, mayor=18;
    cout <<"Ingrese la cantidad de numeros a verificar: "; cin >> cantNumero;

    for(int i=0; i<cantNumero;i++)
    {
        cout <<"Ingrese un numero: "; cin >> numero;

        if(numero > mayor)
        {
            cout <<"El numero ingresado [" << numero  "] es mayor a [" << mayor << "]" << endl;
        }else if(numero == mayor)
        {
            cout <<"El numero ingresado [" << numero  "] es igual a [" << mayor << "]" << endl;
        }else{
            cout <<"El numero ingresado [" << numero  "] es menor a [" << mayor << "]" << endl;
        }
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

int main()
{
    int numero, n=18;

    do{
        cout <<"\nIngrese un numero: "; cin >> numero;

        if(numero > n)
        {
            cout <<"El numero ingresado es mayor a " << n << endl;
        }else if(numero == n)
        {
            cout <<"El numero ingresado es igual a " << n << endl;
        }else{
            cout <<"El numero ingresado es menor a " << n << endl;
        }

        cout <<"\nIngrese 0 si quiere finalizar." << endl;
    }while(numero!=0);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// El usuario va a ingresar numeros positivos hasta poner 0, una vez que termina el sistema debe decir cual fue el maximo numero.
// Si se ingresa un numero negativo que lo tome como error.

int main()
{
    int numero, maximo=0;
    char continuar;

    do{
        cout <<"\nIngrese un numero positivo: "; cin >> numero;
        if(numero < 0)
        {
            cout <<"ERROR. El sistema no admite numeros negativos. ";
        }else if(numero > maximo)
        {
            maximo = numero;
        }

        cout <<"Desea ingresar otro numero? (S/N): "; cin >> continuar;

    }while(continuar == 's' || continuar == 'S');

    cout <<"\nEl numero maximo ingresado es: [" << maximo <<"]" << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}