
// Explicando la sentencia while: while(condicion logica a cumplirse){instrucciones}.
// Si se cumple cierta condicion dentro del parentecis()
// se ejecuta la instruccion en bucle hasta que deje de cumplirse. ↓

// Ejercicio 1: Programa que escribe un numero desde el 1 hasta al que ingrese el usuario.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{
    cout <<"\n\tBienvenido al Programa que escribe un numero desde el 1 hasta el que ingrese el usuario." << endl;

    int numero, i=1;

    cout <<"\nIngrese la cantidad de numeros: " << endl; cin >> numero;

    while(i <= numero)
    {
        cout << i << endl;
        i++;
    }

    system ("pause");
    return 0;
}


// Ejercicio 2: Programa que escribe un numero desde el que ingrese el usuario hasta el 1.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{
    cout <<"\n\tBienvenido al Programa que escribe un numero desde el que ingrese el usuario hasta el 1." << endl;

    int numero;

    cout <<"\nIngrese la cantidad de numeros: " << endl; cin >> numero;

    while(numero >= 1)
    {
        cout << numero << endl;
        numero--;
    }

    system ("pause");
    return 0;
}


// Explicando la sentencia do while: do{Instrucciones}while(Condicion logica a cumplirse). 
// primero lee la instruccion ejecutada y despues comprueba si se sigue cumpliendo la condicion dentro del()
// luego la ejecuta en bucle hasta que deje de cumplirse. ↓

// Ejercicio 3: Programa que escribe un numero desde el 1 hasta al que ingrese el usuario.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{
    cout <<"\n\tBienvenido al Programa que escribe un numero desde el 1 hasta el que ingrese el usuario." << endl;

    int numero, i=1;

    cout <<"\nIngrese la cantidad de numeros: " << endl; cin >> numero;
    
    do{
        cout << i << endl;
        i++;
    }while(i <= numero);

    system ("pause");
    return 0;
}


// Ejercicio 4: Programa que escribe un numero desde el que ingrese el usuario hasta el 1.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{
    cout <<"\n\tBienvenido al Programa que escribe un numero desde el que ingrese el usuario hasta el 1." << endl;

    int numero;

    cout <<"\nIngrese la cantidad de numeros: " << endl; cin >> numero;

    do{
        cout << numero << endl;
        numero--;
    }while(numero >= 1);

    system ("pause");
    return 0;
}


// explicando la sentencia for: for(expresion1; condicion logica a cumplirse; expresion2){conjunto de Instrucciones}

// Ejercicio 5: Programa que escribe un numero desde el 1 hasta al que ingrese el usuario.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{
    cout <<"\n\tBienvenido al Programa que escribe un numero desde el 1 hasta el que ingrese el usuario." << endl;

    int numero;

    cout <<"\nIngrese la cantidad de numeros: " << endl; cin >> numero;
    
    for(int i=1; i <= numero; i++)
    {
        cout << i << endl;
    }

    system ("pause");
    return 0;
}


// Ejercicio 6: Programa que escribe un numero desde el que ingrese el usuario hasta el 1.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{   
    cout <<"\n\tBienvenido al Programa que escribe un numero desde el que ingrese el usuario hasta el 1." << endl;
    cout <<"\nIngrese la cantidad de numeros: " << endl; cin >> numero;
    for(int numero; numero >= 1; numero--)
    {
        cout << numero << endl;
    }

    system ("pause");
    return 0;
}


// Ejercicio 7: Programa que solicita un numero del 1-100 y muestra su tabla de multiplicar.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{
    cout <<"\n\tBienvenido al programa que muestra la tabla de multiplicar del numero ingresado del 1-100" << endl;
    int numero, resultado;

    do{
        cout <<"\nIngrese un numero del 1-100: " << endl; cin >> numero;
    }while((numero < 1) || (numero > 100));

    for(int i=1; i<=10; i++)
    {
        resultado = numero*i;
        cout << numero <<" * "<< i <<" = " << resultado << endl; 
    }
    system("pause");
    return 0;

}


// Ejercicio 8: Programa que cuenta la cantidad de numero mayores a 0 ingresados y los muestra una vez que se ingresa 0.

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que cuenta la cantidad de numero mayores a 0 ingresados y los muestra una vez que se ingresa 0." << endl;
	float numero;
	int contador=0;
	
	do{
		cout<<"Ingrese un numero: " << endl; cin>>numero;
		if(numero>0)
        {
			contador++;
		}
	}while(numero != 0);
	
	cout<<"\nLa cantidad de numeros de valores mayores a 0 ingresados: "<< contador <<endl;
	
	system("pause");
	return 0;
}


// Ejercicio 9: Programa que calcula la suma de los cuadrados de los 10 primeros enteros mayores a 0.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula la suma de los cuadrados de los 10 primeros enteros mayores a 0." << endl;

    int suma=0, cuadrado;

    for(int i=1; i <= 10; i++)
    {
        cuadrado = i * i;
        suma = suma + cuadrado;
    }

    cout <<"\nLa suma de los 10 primeros numeros enteros al cuadrado: " << suma << endl;

    system("pause");
    return 0;
}


// Ejercicio 11: Programa que calcula 6 temperaturas en un periodo de 24hs (1 cada 4hs) y muestra
// cual fue la temperatura media, la mas alta y la mas baja del dia.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main ()
{
    cout <<"\n\tBienvenido al Programa que calcula 6 temperaturas en un periodo de 24hs y muestra cual fue la temperatura media, la mas alta y la mas baja del dia." << endl;
    
    float temperaturaBaja, temperaturaAlta, temperatura, suma=0, temperaturaMedia=0;
 
 for(int i = 4; i<=24; i = i + 4)
 {
  cout<<"\nIngrese la temperatura tomada a las " << i <<" hs: "; cin >> temperatura;
  suma = suma + temperatura;
  
   if(i==4)
   {
     temperaturaAlta = temperatura;
  temperaturaBaja = temperatura; 
   }
    if(temperatura > temperaturaAlta)
    {
  temperaturaAlta = temperatura;
   }
   if(temperatura < temperaturaBaja)
   {
  temperaturaBaja = temperatura;
   }
 }
    temperaturaMedia = suma / 6;
    cout <<"\nLa temperatura media del dia es: " << temperaturaMedia << endl;
    cout <<"La temperatura mas alta del dia es: " << temperaturaAlta << endl;
    cout <<"La temperatura mas baja del dia es: " << temperaturaBaja << endl;
    cout << endl;

    system("pause");
    return 0;

}

// Ejercicio 12: Programa que calcula la suma de de los enteros ingresados fuera del rango [20-30] y lo muestra una vez que se ingresa un numero dentro del rango o 0.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula la suma de de los enteros ingresados fuera del rango [20-30] y lo muestra una vez que se ingresa un numero dentro del rango o 0." << endl;

    int numero, suma=0;

    do{
        cout <<"Ingrese un numero: " << endl; cin >> numero;
        if(numero > 0)
        {
            suma = suma + numero;
        }

    }while(((numero < 20) || (numero > 30)) && (numero != 0));

    cout <<"\nLa suma de los enteros ingresados es: " << suma << endl;

    system("pause");
    return 0;
}


// Ejercicio 13: Programa que calcula (x^y) donde tanto (x) como (y) son enteros positivos sin utilizar la funcion pow.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\t BIenvenido al Programa que calcula (x^y) donde tanto (x) como (y) son enteros positivos sin utilizar la funcion pow." << endl;

    int x, y, potencia=1;

    do{
        cout <<"\nIngrese el valor de la base (x): " << endl; cin >> x;
        cout <<"Ingrese el valor de la potencia ^(y): " << endl; cin >> y;

        for(int i=0; i < y; i++)
        {
            potencia = potencia * x;
        }

        if(x>0 && y>0)
        {
            cout <<"La potencia del numero ingresado es: " << potencia << endl;
            potencia = 1;
        }
    }while(x>0 && y>0);
    
    system("pause");
    return 0;

}


// Ejercicio 14: Programa que calcula el valor de n elementos que ingresa el usuario 1+2+3+..n:

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula el valor de n elementos que ingresa el usuario 1+2+3+..n:" << endl;

    int numero, suma=0;

    cout <<"\nIngrese la cantidad de n elementos a sumar: " << endl; cin >> numero;

    for(int i=1; i<=numero; i++)
    {   
        suma += i;
    }
    cout <<"\nLa suma del total de los n elementos es: " << suma << endl;

    system("pause");
    return 0;
}


// Ejercicio 15: Programa que calcula el valor de 1+3+5+..2n-1.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula el valor de 1+3+5+..2n-1." << endl;

    int numero, suma=0;

    cout <<"\nIngrese la cantidad de n elementos a sumar: " << endl; cin >> numero;

    for(int i=1; i<=numero; i++)
    {   
        suma += 2*i-1;
    }
    cout <<"\nLa suma del total de los n elementos es: " << suma << endl;

    system("pause");
    return 0;
}


// Ejercicio 16: Programa que calcula el valor de 1*2*3*4*5*...n(multiplicacion factorial).

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula el valor de 1*2*3*4*5*...n(multiplicacion factorial)." << endl;
    int numero, factorial=1;

    cout <<"Ingrese un numero: " << endl; cin >> numero;

    for(int i=1; i<=numero; i++)
    {
        factorial = factorial * i;
    }

    cout <<"El factorial del numero es: " << factorial << endl;

    system("pause");
    return 0;

}


// Ejercicio 17: Programa que calcula el valor de 1+2+3+4+5+...n(suma factorial).

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula el valor de 1+2+3+4+5+...n(suma factorial)." << endl;
    int numero, factorial=0;

    cout <<"Ingrese un numero: " << endl; cin >> numero;

    for(int i=1; i<=numero; i++)
    {
        factorial = factorial + i;
    }

    cout <<"El factorial del numero es: " << factorial << endl;

    system("pause");
    return 0;

}


// Ejercicio 18: Programa que calcula la suma de 2^1,2^2,2^3,2^4,2^5,2^n. 

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula la suma de 2^1,2^2,2^3,2^4,2^5,2^n." << endl;
    int suma=0, potencia, numero;

    cout <<"\nIngrese la cantidad de numeros a potenciar: "; cin >> numero;

    for(int i=1; i<numero; i++)
    {
        potencia = pow(2,i);
        suma = suma + potencia;
    }

    cout <<"\nEl resultado de la suma de potencias es: " << suma << endl;

    system("pause");
    return 0;

}


// Ejercicio 19: Programa que calcula el resultado de 1-2+3-4+5-6...n.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que calcula el resultado de 1-2+3-4+5-6...n." << endl;
    int numero, suma=0;

    cout <<"\nIngrese un numero: "; cin >> numero;

    for(int i=1; i<=numero; i++)
    {
        if(i%2==0)
        {
            suma = suma - i;
        }else{
            suma = suma + i;
        }
    }

    cout <<"\nla suma es: " << suma << endl;

    system("pause");
    return 0;

}


// Ejercicio 20: Programa que realiza la serie fibonacci 1, 1, 2, 3, 5, 8, 13...n.

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que realiza la serie fibonacci." << endl;
    int numero, x=0, y=1, z=0;

    cout <<"\nIngrese la cantidad de numeros de la serie fibonacci a ver: "; cin >> numero;
    cout <<"1, ";
    
    for(int i=1; i<numero; i++)
    {
        z = x + y;
        cout << z <<", ";
        x = y;
        y = z;
    }

    system("pause");
    return 0;
}


// Ejercicio 21: Programa que permite la lecutra de datos y el calculo de las estadisticas. 
// En una clase de 5 alumnos se han realizado tres examenes y se requiere determinar el numero de:
// a) Alumnos que aprobaron todos los examenes.
// b) Alumnos que aprobaron al menos un examen.
// c) Alumnos que aprobaron unicamente el ultimo examen.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que permite la lecutra de datos y el calculo de las estadisticas." << endl;
    int alumno, examen1, examen2, examen3, ultimo=0, almenos1=0, todos=0;

    cout <<"\nIngrese la cantidad de alumnos a cursar los 3 examenes: "; cin >> alumno;
    for(int i=0; i<alumno; i++)
    {
        char nombre[10];
        cout <<"\nIngrese el nombre del alumno: "; cin >> nombre;
        cout <<"\nNota del Examen 1: "; cin >> examen1;
        cout <<"Nota del Examen 2: "; cin >> examen2;
        cout <<"Nota del Examen 3: "; cin >> examen3;

        if (examen1 >= 6 && examen2 >= 6 && examen3 >= 6)
        {
            todos++;
        }else if((examen1 >= 6) || (examen2 >= 6) || (examen3 >=6))
        {
            almenos1++;
        }else if ((examen1 < 6 && examen2 < 6) && (examen3 >= 6))
        {
            ultimo++;
        }

        cout <<"\nEl alumno: " << nombre <<" obtuvo las siguientes notas en los 3 examenes: " << endl;
        cout <<"Examen 1: " << examen1 << endl <<"Examen 2: " << examen2 << endl <<"examen 3: " << examen3 << endl;

    }

    cout <<"\nLa cantidad de alumnos que aprobaron todos los examenes son: " << todos;
    cout <<"\nLa cantidad de alumnos que aprobaron almenos 1 de los examenes son: " << almenos1;
    cout <<"\nLa cantidad de alumnos que aprobaron solo el ultimo examen son: " << todos << endl;

    system("pause");
    return 0;
 
}


// Ejercicio 22: Programa que genera un numero aleatorio y el usuario tiene que adivinar cual es.
// Realice un programa que solicie al usuario que piense un numero del 1 al 100.
// a) El programa debe generar un numero aleatorio en ese mismo rango [1-100],
// b) indicarle al usuario si el numero que ingreso es menor o mayor al numero aleatorio hasta que lo adivine.
// c) Mostrar el numero de intentos que le llevo adivinarlo.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que genera un numero aleatorio, Tienes que adivinar cual es." << endl;
    int numero, dato, contador=0;

    srand(time(NULL)); // genera un numero aleatorio.
    dato = 1 + rand()%(100);

    do{
        cout <<"\nIngrese un numero: "; cin >> numero;
        if(numero > dato)
        {
            cout <<"\nEstuvo cerca ingrese un numero menor: " << endl;
        }
        if(numero < dato)
        {
            cout <<"\nEstuvo cerca ingrese un numero mayor: " << endl;
        }

        contador++;
    }while(numero != dato);

    cout <<"\nFelicidades!! Adivino el numero." << endl;
    cout <<"Numero de intentos realizados: " << contador << endl << endl;

    system("pause");
    return 0;

}