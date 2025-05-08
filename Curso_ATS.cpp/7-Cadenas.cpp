
// Cadenas y funciones de cadenas:

// Funciones de la libreria: #include<string.h>

// Funcion strlen(cadena) Se utiliza para medir la cantidad de caracteres que tiene la cadena dentro del parentesis.
// Funcion strcpy(cadena2, cadena1) Se utiliza para copiar cadena1 a cadena2.
// Funcion strcmp(cadena1, cadena2) Se utiliza para comparar 2 cadenas y saber si son iguales por ejemplo.
// Funcion strcat(cadena2, cadena1) Se utiliza para añadir los caracteres de cadena1 a cadena2 y asi transformarce en una cadena unica.
// Funcion strrev(cadena) Se utiliza para revertir los caracteres de la cadena dentro del parentesis.
// Funcion strupr(cadena) Se utiliza para converitr cadenas de minusculas a mayusculas.
// Funcion strlwr(cadena) Se utiliza para convertir cadenas de mayusculas a minusculas.

// Funciones de la libreria: #include<stdlib.h>

// Funcion atoi(cadena) Se utiliza para convertir los numeros de una cadena de caracteres a numeros enteros.
// Funcion atof(cadena) Se utiliza para convertir los numeros de una cadena de caracteres a numeros reales.



// Ejercicio n°1 Cadenas de caracteres.

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char letras[] = "Nahuel";
    char letras2[] = {'N','a','h','u','e','l',' '};
    char nombre[30];
    // Para el cin, Apenas encuentre un espacio en la cadena de caracteres lo da por finalizado. Por eso lo mejor es utilizar:
    // gets(nombre) Almacena la cadena completa pero tiene un defecto, no le importa el tamaño de los espacios asignados.
    // cin.getline(nombre,30,'\n') Almacena la cadena completa utilizando los espacios que fueron asignados.
    cout << "\nIngrese su nombre completo: "; cin.getline(nombre,30,'\n');

    cout <<"\nSu nombre es: " << letras << endl;
    cout <<"\nSu nombre es: " << letras2 << endl;
    cout <<"\nSu nombre completo es: " << nombre << endl << endl;

    system("PAUSE");
    return 0;
}

// Ejercicio n°2: Programa que calcula la longitud de una cadena de caracteres. 
// Funcion strlen().

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    cout <<"\n\tBienvenido al programa que calcula la longitud de una cadena de caracteres"
    char nombre[] = "nahuel alexander richeri";
    int longitud = 0;

    longitud = strlen(nombre);
    cout <<"\nLa cantidad de elementos del nombre son: " << longitud;

    cout << "\n\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°3: Programa que al ingresar una cadena de caracteres devuelve la cantidad de elementos que tiene si es mayor a 10.
// Funcion strlen(). 

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    cout <<"\n\tbienvenido al Programa que al ingresar una cadena de caracteres devuelve la cantidad de elementos que tiene si es mayor a 10." << endl;
    
    char cadena[100];
    int longitud = 0;

    cout <<"\nIngrese una cadena de caracteres: "; cin.getline(cadena,100,'\n');
    longitud = strlen(cadena);

    if(longitud > 10)
    {
        cout <<"\nLa cantidad de elementos de la cadena de caracteres es: " << longitud;
    }else{
        cout <<"\nLa cantidad de elementos ingresadas es menor a 10.";
    }

    cout << "\n\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°4: Programa que copia una cadena de caracteres a otra.
// Funcion strcpy().

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    cout <<"\n\tbienvenido al Programa que copia una cadena de caracteres a otra." << endl;

    char cadena[] = "Hola como estas nahuel";
    char cadena2[30];

    strcpy(cadena2, cadena); // cadena2 = cadena;

    cout <<"\nLa cadena de caracteres es: " << cadena2;

    cout << "\n\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°5: Programa que almacena una cadena de caracteres en un vector y lo copia a otro vector de caracteres. 
// Funcion strcpy().

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    cout <<"\n\tbienvenido al Programa que almacena una cadena de caracteres en un vector y lo copia a otro vector de caracteres." << endl;

    char cadena[200];
    char cadena2[200];
    int longitud = 0;

    do{
        cout <<"\nEscriba un texto de maximo 200 caracteres para realizarle una copia: "; cin.getline(cadena,200,'\n');
        longitud = strlen(cadena);

        // muestra la cantidad de caracteres ingresados en caso de superar el limite(200).
        if(longitud > 200)
        {
            cout <<"\nEl texto ingresado supera el limite de 200 caracteres, ingresaste: " << longitud <<" Caracteres. Elimina algunos.";
        }
        cout << endl;
    }while(longitud > 200);

    // Copiando el texto.
    strcpy(cadena2, cadena); // cadena2 = cadena;
    cout <<"\nSu texo a sido copiado con exito: " << cadena2 << endl;
    cout <<"Tiene una longitud de: " << longitud <<" Caracteres.";

    cout << "\n\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°6: Programa que compara dos cadenas.
// Funcion strcmp().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que compara dos cadenas." << endl;
    char cadena[] = "hola que tal";
    char cadena2[] = "Hola que tal";

    if(strcmp(cadena, cadena2) == 0)
    {
        cout <<"\nLa comparacion entre ambas cadenas dio resultado como valida. Son iguales." << endl;
    }else{
        cout <<"\nLa comparacion entre ambas cadenas dio resultado como invalida. Son diferentes." << endl;
    }

    cout <<"\n";
    system("pause");
    return 0;
}

// Ejercicio n°7: Programa que compara dos cadenas ingresadas y dice cual es mayor alfabeticamente.
// Funcion strcmp().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que compara dos cadenas ingresadas y dice cual es mayor alfabeticamente." << endl;
    char cadena[200];
    char cadena2[200];
    int longitudCadena, longitudCadena2;


    cout <<"\nIngrese la primera cadena a comparar: "; cin.getline(cadena,200,'\n');
    cout <<"Ingrese la segunda cadena a comparar: "; cin.getline(cadena2,200,'\n');

    if(strcmp(cadena, cadena2) == 0) // Nahuel del futuro aprendio a usar sentencias sin {}.
    cout <<"\nLa comparacion entre ambas cadenas dio resultado como valida. Son iguales." << endl;
    if(strcmp(cadena, cadena2) != 0)
    cout <<"\nLa comparacion entre ambas cadenas dio resultado como invalida. Son diferentes." << endl;

    longitudCadena = strlen(cadena); longitudCadena2 = strlen(cadena2);

    if(strcmp(cadena, cadena2) > 0)
    cout <<"La cadena mayor alfabeticamente es: " << cadena <<" con " << longitudCadena <<" Caracteres."<< endl;
    if(strcmp(cadena, cadena2) < 0)
    cout <<"La cadena mayor alfabeticamente es: " << cadena2 <<" con " << longitudCadena2 <<" Caracteres."<< endl;

    cout <<"\n";
    system("pause");
    return 0;
}

// Ejercicio n°8: Programa que concatena una cadena con otra.
// Funcion strcat().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que concatena una cadena con otra." << endl;
    char cadena[200]; 
    char cadena2[200];
    char cadenaPlus[200];

    cout <<"\nIngrese la primera cadena: "; cin.getline(cadena,200,'\n');
    cout <<"Ingrese la segunda cadena: "; cin.getline(cadena2,200,'\n');

    strcpy(cadenaPlus, cadena); // Copia la primera cadena a cadenaPlus (cadenaPlus = cadena).
    strcat(cadenaPlus, cadena2); // Se añade a cadenaPlus la segunda cadena de caracteres que esta en cadena2 (cadenaPlus + cadena2).

    cout <<"\nLa cadena completa es: " << cadenaPlus; // Se muestra en consola la cadena completa.
    cout <<"\n";
    system("pause");
    return 0;
}

// Ejercicio n°9: Programa que concatena una cadena con una pregunta.
// Funcion strcat().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que concatena una cadena con una pregunta." << endl;
    char cadena[] = "Hola, ";
    char cadena2[200];
    char cadenaPlus[200];

    cout <<"\nCual es su nombre? "; cin.getline(cadena2,200,'\n');

    strcpy(cadenaPlus, cadena);
    strcat(cadenaPlus, cadena2);

    cout << cadenaPlus;

    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°10: Programa que invierte una cadena.
// Funcion strrev().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que invierte una cadena. " << endl;
    char cadena[200];
    cout <<"\nIngrese una cadena de texto: "; cin.getline(cadena,200,'\n');

    strrev(cadena);
    cout <<"\nLa cadena de texto ingresada invertida seria: " << cadena;

    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°11: Programa que verifica si una palabra es polindroma.
// Funcion strrev().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que verifica si una palabra es polindroma. " << endl;

    char cadena[200];
    char polindroma[200];
    cout <<"\nIngrese una cadena de texto: "; cin.getline(cadena,200,'\n');

    strcpy(polindroma, cadena); // Copiamos la cadena a polindroma.
    strrev(polindroma); // Invertimos polindroma.
    cout <<"\nLa cadena de texto ingresada invertida seria: " << polindroma;

    if(strcmp(polindroma, cadena) == 0) // Comparamos si polindroma y cadena son iguales.
    {
        cout <<"\nLa cadena es polindroma. ";
    }else{
        cout <<"\nLa cadena no es polindroma";
    }


    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°12: Programa que transcribe letras de minusculas a mayusculas.
// Funcion strupr().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que transcribe letras de minusculas a mayusculas. " << endl;

    char cadena[200];
    cout <<"\nIngrese una cadena de texto en minusculas: "; cin.getline(cadena,200,'\n');

    strupr(cadena);

    cout <<"\nLa cadena de texto fue recibida con exito!!, transcribiendo el texto a mayusculas: " << cadena;

    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°13: Programa que transcribe letras de minusculas a mayusculas y las compara.
// Funcion strupr().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que transcribe letras de minusculas a mayusculas y las compara. " << endl;

    char cadena[200];
    char cadena2[200];
    int longitudCadena=0, longitudCadena2=0;

    cout <<"\nIngrese la primera cadena de texto en minusculas: "; cin.getline(cadena,200,'\n');
    cout <<"Ahora ingrese la segunda cadena de texto en minusculas: "; cin.getline(cadena2,200,'\n');

    strupr(cadena); strupr(cadena2);
    cout <<"Comparando el texto 1 (" << cadena <<") con el texto 2 (" << cadena2 <<") " << endl;

    longitudCadena = strlen(cadena); longitudCadena2 = strlen(cadena2);

    if(strcmp(cadena,cadena2) == 0)
    {
        cout <<"\nlas cadenas ingresadas son iguales." << endl;
        cout <<"por ende tienen la misma cantidad de caracteres: " << longitudCadena <<", " << longitudCadena2;

    }else{
        cout <<"\nlas cadenas ingresadas no son iguales." << endl;
        cout <<"por ende tienen diferentes cantidades de caracteres: " << longitudCadena <<", " << longitudCadena2;
    }



    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°14: Programa que transcribe letras de mayusculas a minusculas y las compara.
// Funcion strlwr().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que transcribe letras de mayusculas a minusculas y las compara. " << endl;

    char cadena[200];
    char cadena2[200];
    int longitudCadena=0, longitudCadena2=0;

    cout <<"\nIngrese la primera cadena de texto en mayusculas: "; cin.getline(cadena,200,'\n');
    cout <<"Ahora ingrese la segunda cadena de texto en mayusculas: "; cin.getline(cadena2,200,'\n');

    strlwr(cadena); strlwr(cadena2);
    cout <<"Comparando el texto 1 (" << cadena <<") con el texto 2 (" << cadena2 <<") " << endl;

    longitudCadena = strlen(cadena); longitudCadena2 = strlen(cadena2);

    if(strcmp(cadena,cadena2) == 0)
    {
        cout <<"\nlas cadenas ingresadas son iguales.";
        cout <<"por ende tienen la misma cantidad de caracteres: " << longitudCadena <<", " << longitudCadena2;
    }else{
        cout <<"\nlas cadenas ingresadas no son iguales.";
        cout <<"por ende tienen diferentes cantidades de caracteres: " << longitudCadena <<", " << longitudCadena2;
    }

    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°15: Programa que convierte el nombre Nahuel a nahuel.
// Funcion strlwr().

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que convierte el nombre Nahuel a nahuel. " << endl;

    char cadena[200], cadena2[] = {'N'};
    cout <<"\nEscriba su nombre con la primera letra en mayuscula: "; cin.getline(cadena,200,'\n');

    if(strcmp(cadena, cadena2) > 0)
    {   
        cout <<"\nTranscribiendo su nombre de mayusculas a minusculas.. ";
        strlwr(cadena);
        cout <<"\nHola, " << cadena;
    }else{
        cout <<"Hola, " << cadena;
    }

    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°16: Programa que transforma una cadena de caracteres a numeros.
// Funcion atoi() y atof().

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que transforma una cadena de caracteres a numeros. " << endl;

    char cadena[] = "64";
    char cadena2[] = "256.5";
    int opcion, numero;
    cout <<"\nSeleccione cual cadena tanformar, 1 (Entero) o 2 (Real): "; cin >> opcion;

    if(opcion == 1)
    {   
        cout <<"\nTransformando la cadena de caracteres a entero.. ";
        numero = atoi(cadena);
        cout <<"\nTransformacion exitosa: " << cadena;
    }
    if(opcion == 2)
    {
        cout <<"\nTransformando la cadena de caracteres a real.. ";
        numero = atof(cadena2);
        cout <<"\nTransformacion exitosa: " << cadena2;
    }

    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°17: Programa que transforma dos cadenas de caracteres, uno entero y otro real y los suma.
// Funcion atoi() y atof().

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que transforma dos cadenas de caracteres, uno entero y otro real y los suma. " << endl;

    char cadena[200];
    char cadena2[200];
    int enteros;
    float reales, suma=0;

    cout <<"\nEscriba numeros enteros: "; cin.getline(cadena,200,'\n');
    cout <<"Escriba numeros reales: "; cin.getline(cadena2,200,'\n');

    enteros = atoi(cadena); reales = atof(cadena2);
    suma = enteros + reales;

    cout <<"\nLa suma de la cadena de caracteres tranformada en numeros enteros y reales es: " << suma;

    cout <<"\n\n";
    system("pause");
    return 0;
}

// Ejercicio n°18: Programa que verifica y lee cuantas vocales hay en una cadena de caracteres.
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que verifica y lee cuantas vocales hay en una cadena de caracteres. " << endl;

    char frase[30];
    int longitud=0, vocal_a=0, vocal_e=0, vocal_i=0, vocal_o=0, vocal_u=0;

    cout <<"\nIngrese una frase: "; cin.getline(frase,30,'\n');
    strlwr(frase); // Cambio todos los valores a minuscula.
    longitud = strlen(frase); // Calculo su longitud.

    for(int i=0; i<longitud; i++)
    {
        switch(frase[i])
        {
            case 'a': vocal_a++; break;
            case 'e': vocal_e++; break;
            case 'i': vocal_i++; break;
            case 'o': vocal_o++; break;
            case 'u': vocal_u++; break;
        }
    }

    cout <<"\nLa frase ingresada cuenta con la siguiente cantidad de vocales: ";
    cout <<"\n Vocal a: " << vocal_a;
    cout <<"\n Vocal e: " << vocal_e;
    cout <<"\n Vocal i: " << vocal_i;
    cout <<"\n Vocal o: " << vocal_o;
    cout <<"\n Vocal u: " << vocal_u;

    cout <<"\n\n";
    system("pause");
    return 0;
}
