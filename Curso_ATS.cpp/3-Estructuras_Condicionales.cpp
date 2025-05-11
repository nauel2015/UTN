
// Explicando la sentencia if. ↓

// Ejercicio 1: Programa que indica cual variable es mayor o menor.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que identifica cual de los 2 numeros ingresados es mayor." << endl;
    float a, b;
    cout <<"Escriba el valor de a: "; cin >> a;
    cout <<"Escriba el valor de b: "; cin >> b;

    if (a == b)
    {
        cout << "Ambos numero son iguales: " << a <<" = " << b << endl;
    }else if(a > b)
    {
        cout <<"El numero: " << a <<" Es mayor a el numero: " << b << endl;
    }else
    {
        cout <<"El numero: " << b <<" Es mayor a el numero: " << a << endl;
    }

    return 0;
}


// Ejercicio 2: Programa que identifica cual de las 3 variables es el mayor.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que identifica cual de los 3 numeros ingresados es mayor." << endl;
    float a, b, c;

    cout <<"Escriba 3 numeros: "; cin >> a >> b >> c;

    if(a>b && a>c)
    {
        cout <<"Entre los numeros: " << a <<"/" << b <<"/" << c <<": (" << a <<") es el mayor de los 3 numeros. " << endl;
    } else if(b>a && b>c)
    {
        cout <<"Entre los numeros: " << a <<"/" << b <<"/" << c <<": (" << b <<") es el mayor de los 3 numeros. " << endl;
    }else if(c>a && c>b)
    {
        cout <<"Entre los numeros: " << a <<"/" << b <<"/" << c <<": (" << c <<") es el mayor de los 3 numeros. " << endl;
    }

return 0;

}


// Ejercicio 3: Programa que Identifica si un numeros es par o impar.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que identifica si el numero ingresado es par o impar." << endl;
    int numero;
    cout <<"Escriba el numero: "; cin >> numero;

    if(numero==0)
    {
        cout <<"El numero es cero." << endl;
    }else if(numero%2 == 0)
    {
        cout <<"El numero: " << numero <<" es par." << endl;
    }else
    {
        cout <<"El numero: " << numero <<" es impar." << endl; 
    }

return 0;

}


// Ejercicio 4: Programa que identifica si el numero es positivo o negativo.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que identifica si el numero ingresado es negativo o positivo." << endl;
    int numero;
    cout <<"Escriba el numero: "; cin >> numero;

    if(numero==0)
    {
        cout <<"El numero es cero. no es positivo ni negativo >:v" << endl;
    }else if(numero > 0)
    {
        cout <<"El numero: " << numero <<" es positivo." << endl;
    }else if(numero < 0)
    {
        cout <<"El numero: " << numero <<" es negativo." << endl; 
    }

return 0;

}


// Explicando la sentencia switch. ↓

// Ejercicio 5: Programa que indica si un caracter es una vocal minuscula o mayuscula.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que indica si el caracter es una vocal minuscula o mayuscula. " << endl;
    char letra;
    cout <<"Ingrese un caracter: "; cin >> letra;

    switch (letra)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': cout <<"(" << letra <<") es una vocal minuscula"; break;
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': cout <<"(" << letra <<") es una vocal mayuscula"; break;

        default: cout <<"El caracter ingresado no una vocal ni miniscula ni mayuscula >:v "; break;
        
    }

    return 0;
}


// Ejercicio 6: Programa que indica si la edad introducida este en el rango de los 18-25 años.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que identifica si la edad introducida se encuentra entre los 18-25 años" << endl;
    int edad;
    cout <<"Escriba su edad: "; cin >> edad;

    if(edad>=18 && edad<=25)
    {
        cout <<"Su edad: (" << edad <<") se encuentra en el rango de entre los 18-25 anios." << endl;
    }else
    {
        cout <<"su edad: (" << edad <<") no se encuentra en el rango de entre los 18-25 anios." << endl;
    }

    return 0;
}


// Ejercicio 7: Programa que lee 4 numeros y indica si el ultimo coincide con alguno de los anteriores

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que lee 4 numeros y indica si el ultimo coincide con alguno de los anteriores" << endl;
    float a,b,c,d;
    cout <<"Escriba 3 numeros: "; cin >> a >> b >> c;
    cout <<"Escriba el 4to numero para ver si coincide con uno de los anteriores: "; cin >> d;

    if(d==a)
    {
        cout <<"El numero: (" << d <<") coincide con uno de los ingresados anteriormente: " << a << endl;
    }else if(d==b)
    {
        cout <<"El numero: (" << d <<") coincide con uno de los ingresados anteriormente: " << b << endl;
    }else if(d==c)
    {
        cout <<"El numero: (" << d <<") coincide con uno de los ingresados anteriormente: " << c << endl;
    }else
    {
        cout <<"El numero: (" << d <<") no coincide con ninguno de los numeros ingresados anteriormente. " << endl;
    }

    return 0;
}


// Ejercicio 8: Programa que transforma numeros enteros en romanos.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que transforma los numeros enteros en numeros romanos. " << endl;
    int numero, unidades, decenas, centenas, millares;
    cout <<"Escriba un numero: "; cin >> numero;

// Como ejemplo se ingresa 2152 ---> 2000 + 100 + 50 + 2

    unidades = numero%10; numero /= 10; // unidades = el reciduo es 2, numero 215
    decenas = numero%10; numero /= 10; // decenas = el reciduo del numero es 5, el numero 21
    centenas = numero%10; numero /= 10; // centenas = el reciduo del numero es 1, numero 2
    millares = numero%10; numero /= 10; // millares = el reciduo del numero es 2, numero 0

    switch(millares)
    {
        case 1: cout <<"M"; break; // 1000
        case 2: cout <<"MM"; break; // 2000
        case 3: cout <<"MMM"; break; // 3000
    }
    switch(centenas)
    {
        case 1: cout <<"C"; break; // 100
        case 2: cout <<"CC"; break; // 200
        case 3: cout <<"CCC"; break; // 300
        case 4: cout <<"CD"; break; // 400
        case 5: cout <<"D"; break; // 500
        case 6: cout <<"DC"; break; // 600
        case 7: cout <<"DCC"; break; // 700
        case 8: cout <<"DCCC"; break; // 800
        case 9: cout <<"CM"; break; // 900
    }
    switch(decenas)
    {
        case 1: cout <<"X"; break; // 10
        case 2: cout <<"XX"; break; // 20
        case 3: cout <<"XXX"; break; // 30
        case 4: cout <<"XL"; break; // 40
        case 5: cout <<"L"; break; // 50
        case 6: cout <<"LX"; break; // 60
        case 7: cout <<"LXX"; break; // 70
        case 8: cout <<"LXXX"; break; // 80
        case 9: cout <<"XC"; break; // 90
    }

    switch(unidades)
    {
        case 1: cout <<"I"; break; // 1
        case 2: cout <<"II"; break; // 2
        case 3: cout <<"III"; break; // 3
        case 4: cout <<"IV"; break; // 4
        case 5: cout <<"V"; break; // 5
        case 6: cout <<"VI"; break; // 6
        case 7: cout <<"VII"; break; // 7
        case 8: cout <<"VIII"; break; // 8
        case 9: cout <<"IX"; break; // 9
    }

    return 0;
}


// Ejercicio 9: Programa que al ingresar un numero entre el 1-12 devuelve el mes del año al que corresponde.

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que al ingresar un numero del 1-12 devuelve el mes del año al que corresponde. " << endl;

    int numero;
    cout <<"\nIngrese un numero del 1-12: " << endl; cin >> numero;

    switch (numero)
    {
        case 1: cout <<"El Mes del año ingresado: 1 = Enero"; break;
        case 2: cout <<"El Mes del año ingresado: 2 = Febrero"; break;
        case 3: cout <<"El Mes del año ingresado: 3 = Marzo"; break;
        case 4: cout <<"El Mes del año ingresado: 4 = Abril"; break;
        case 5: cout <<"El Mes del año ingresado: 5 = Mayo"; break;
        case 6: cout <<"El Mes del año ingresado: 6 = Junio"; break;
        case 7: cout <<"El Mes del año ingresado: 7 = Julio"; break;
        case 8: cout <<"El Mes del año ingresado: 8 = Agosto"; break;
        case 9: cout <<"El Mes del año ingresado: 9 = Septiembre"; break;
        case 10: cout <<"El Mes del año ingresado: 10 = Octubre"; break;
        case 11: cout <<"El Mes del año ingresado: 11 = Noviembre"; break;
        case 12: cout <<"El Mes del año ingresado: 12 = Diciembre"; break;
        default: cout <<"Numero incorrecto, Ingrese un numero del 1-12: "; break;
    }

    return 0;
}


// Ejercicio 10: Programa que simula un cajero automatico con un saldo inicial de 1000 dolares.

#include <iostream>
using namespace std;

int main()
{
    int saldoInicial = 1000, opcion;
    float deposito, retiro, saldoFinal = 0;

    cout <<"\n\tBienvenido al cajero automatico. " << endl;
    cout <<"\n1. Ingresar dinero a su cuenta." << endl;
    cout <<"2. Retirar dinero de su cuenta." << endl;
    cout <<"3. Salir." << endl; 
    cout <<"\nSeleccione la opcion que desea realizar: " << endl; cin >> opcion;

    switch(opcion) 
    {
        case 1: cout <<"\nIngrese la cantidad de dinero que va a depositar: " << endl; cin >> deposito;
        saldoFinal = saldoInicial + deposito;
        cout <<"Deposito realizado con exito. Su dinero en la cuenta es de: " << saldoFinal << "$" << endl; break;

        case 2: cout <<"\nIngrese el monto de dinero que quiere retirar: " << endl; cin >> retiro;
        
        if(retiro > saldoInicial)
        {
            cout <<"Disculpe, no posee esa cantidad de dinero en su cuenta. " << endl;
        }else
        {
            saldoFinal = saldoInicial - retiro;
            cout <<"\nSu retiro de " << retiro << "$ fue realizado con exito. El saldo restante en la cuenta es de: " << saldoFinal << "$" << endl; break;

            case 3: break;
        }

    return 0;

    }
}
