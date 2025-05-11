
// Escuela de verano. Profe: Roxana leituz.

// Clase 1: generalidades, asignacion, analisis de caso, iteradores

#include <iostream> // El numeral (#) son directivas del compilador e Inclusion de biblioteca: en este caso seria la biblioteca <iostream>
using namespace std; // Uso de espacio nombre estandar para poder usar cin y cout y endl sin tener que poner std::
// C++ es un compilador y los lenguajes de programacion son Interpretes.
//    • Ejemplos -> python, javascript.
// Un ejecutable es: .exe/.docs/.txt
// Variables (a,b,c) Son espacios de memoria. 
//    • int a,b,c;
// El main le indica al compilador que el programa comienza desde la funcion int main(){}

int main()
{
    // Variables: Siempre utilizar variables legibles.
    int contador, codAlumno; // Ejemplos.
    // Operador de incrementacion: incrementamos a.
    int a;
    a++;
    cout << a; // sumamos 1 a la variable (a).
    
    // Ejemplo de presedencia.
    int b, a=10;
    b = a++; // asigno la variable (a) a la variable (b) y luego incremento la variable (a)
    b = ++a; // incremento la varaible (a) y luego lo asigno a la variable (b).
    cout << b; // mostrar b en consola.
    
    // EL condicional if: if(condicion logica a cumplirse) // una condicion logica se reduce a un valor. V o F. 
    // Para el lenguaje c el dato 0 es falso y toma como verdadero cualquier otro dato.
    int edad; cout <<"Ingrese su edad: " << endl; cin >> edad;
    if (edad >= 18)
    {
        cout <<"Es mayor de edad" << endl;
    }else{
    cout <<"Es menor de edad" << endl;
    }
    // Si solo se utiliza una sentencia no hace falta poner llaves {}
    if (edad == 18)
    cout <<"Es mayor de edad" << endl;
    
    // La sentencia en bucle for: for(expresion1; condicion logica a cumplirse; expresion2){conjunto de Instrucciones}

    for(int i=1; i < 20; i++) // contador de 0 a 19.
    {
        cout << i << endl; // muestra el resultado de cada bucle hasta llegar a 19.
    }

    // La sentencia en bucle while: while(condicion logica a cumplirse){instrucciones}.
    while(i < 20)
    {
        cout << i << endl; // Muestra i en pantalla
        i++; // Luego le suma 1.
    }
    
    return 0; // Retorna un entero. En caso de que no lo haga no finaliza la tarea.
}
    
// Clase 2: maximos, minimos y funciones.

#include<iostream>
#include<stdlib.h>

using namespace std;

int i=1;
int miFuncion();

int main() 
{
    int i=2;
    for(int i=3; i<5;i++)
    {
        cout << "\n" << i;
    }

    cout << "\n" << i;
    miFuncion();

    return 0;
}

int miFuncion()
{
    cout << "\n" << i;

    return 0;
}

#include<iostream>
#include<stdlib.h>

using namespace std;

// Desarrollar una funcion que reciba 3 valores de tipo entero que determina si forma un triangulo o no.
int esTriangulo(int a, int b, int c) // los tres parametros estan pasados por valor ya que no tienen (&).
{
    // Como precondicion establecemos que los valores son mayores a 0.

    if ((a<(b+c)) && (b<(a+c)) && (c<(a+b))) 
    return 1;
    return 0; 
}

// Desarrollar una funcion que reciba 3 valores de tipo entero que forma un triangulo y determina si es un triangulo isoseles, equilatero y escaleno.
int tipoTriangulo(int a, int b,int c) 
{
    // Precondicion: tenemos la certeza que los tres valores forman un triangulo.

    if (a==b && b==c) return 1;
    if ( a==b || a==c || b==c) return 2;
                                    return 3;
}

// Hacer un programa que ingrese un conjunto de terna de valores y te informe cuantas ternas no forman equilateros, cuantas ternas forman isoseles y cuantas ternas forman escalenos

int main() 
{

    cout <<"\n\tBienvenido al programa que cuenta si la terna de enteros ingresada forma un triangulo y verifica si es equilatero, isoseles o escaleno. ";

    int x,y,z,i,j;
    int noTriangulo = 0;
    int equilatero=0, isoseles=0, escaleno=0;
    
    // Ingresar los valores:
    cout <<"\n\ningrese un entero x: "; cin >> x;
    cout <<"ingrese un entero y: "; cin >> y;
    cout <<"ingrese un entero z: "; cin >> z;

    while (x>0 && y>0 && z>0)
    {
        i = esTriangulo(x,y,z); // Se invoca la funcion con los argumentos x,y,z ingresados.
        if (i==0)
        {
            noTriangulo++;
        }else{
            j = tipoTriangulo(x,y,z);
            if (j==1) equilatero++;
            if (j==2) isoseles++;
            if (j==3) escaleno++;
        }

        cout <<"\nEl ciclo de ternas se va a repetir hasta que coloques un numero negativo en uno de los enteros.";
        cout <<"\ningrese un entero x: "; cin >> x;
        cout <<"ingrese un entero y: "; cin >> y;
        cout <<"ingrese un entero z: "; cin >> z;

    }
    cout <<"\nLas ternas que no forman triangulos son: " << noTriangulo;
    cout <<"\nLas ternas que forman triangulos equilateros son: " << equilatero;
    cout <<"\nLas ternas que forman triangulos isoseles son: " << isoseles;
    cout <<"\nLas ternas que forman triangulos escalenos son: " << escaleno;
    cout <<"\n\n";

    system("PAUSE");
    return 0;
}

// Clase 3: Vectores y struct.

// vectores: Son posiciones contiguas de memoria.
int alumno[30];
char nombre[50+1];

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char nombre[20+1];
    char nombre2[20+1];

    cout <<"Ingrese su nombre (no mayor a 20 caracteres): "; cin.getline(nombre,21,'\n');

    strcpy(nombre2, nombre); // nombre2 = nombre;
    cout <<"\nHola " << nombre2;

    cout <<"\n\n";
    system("PAUSE");
    return 0;
}

// Struct: son estructuras de datos.

#include <iostream>
using namespace std;

int suma(int,int); // parametros.

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct alumno
{
    int legajo;
    int curso;
    fecha fecha;

};

struct alumnoBIS
{
    int legajo;
    int curso;
    fecha fecha;

};

int contadorAlumno(alumno);


int main ()
{
    alumno al1;
    alumno al2;
    al1.legajo = 2088083;
    al1.fecha.dia = 1;
    //al=..; No se puede.
    al1 = al2;


    system("PAUSE");
    return 0;
}

// clase 4: Repaso de struct y vectores + matrices de 2 y 3 dimenciones.

#include <iostream>
using namespace std;

struct tipoResgistro
{
    int campo1;
    int campo2;
};

int main ()
{
    int vectornum1[10]; // Declaro una posicion de 10 vectores pero se desconocen los valores.
    int vectorNum2[10] = {0,1,2,3,4,5,6,7,8,9}; //inicializada las 10 posiciones con los valores descritos.
    int vectornum3[10] = {8,5,14}; // El resto de las posiciones se finalizan con 0.
    int vectornum4[10] = {0}; // Le asigna 0 al resto del vector.

    int i; // asignacion interna de un vector.

    for(i=0; i<10; i++)
    {
        vectornum1[i] = 0;
    }
    // Asinacion externa de entrada a un vector.
    for(i=0; i<10; i++)
    {
        cout <<"ingrese el valor de la posicion [" << i <<"]: " << endl;
        vectornum1[i] = 0;
    }
    // Asignacion externa de salida de un vector.
    for(i=0; i<10; i++)
    {
        cout << vectornum1[i] << endl;
    }
    //

    tipoRegistro vector[5] = {{3,4},{6,7},{2,4},{5,7},{8,6}};
    // Asignacion interna de un vector.
    for(i=0; i<5; i++)
    {
        vector[i].campo1 = 0;
        vector[i].campo2 = 0;
    }
    // Asignacion externa de entrada a un vector.
    for(i=0; i<5; i++)
    {
        cout <<"ingrese el valor del primer campo: "; cin >> vector[i].campo1;
        cout <<"ingrese el valor del segundo campo: "; cin >> vector[i].campo2;
    }
    // Asignacion externa de salida a un vector.
    for(i=0; i<5; i++)
    {
        cout << vector[i].campo1;
        cout << vector[i].campo2;
    }

    // Asignacion interna de entrada a una matriz.
    int matriz1[5][2] = {{5,2},{6,7},{4,3},{5,1},{1,1}};
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; i++)
        {
            matriz1[i][j] = 0;
        }
    }
    // Asignacion externa de entrada a una matriz.
    int matriz1[5][2];
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; i++)
        {
            cout <<"ingrese un valor: "; cin >> matriz1[i][j];
        }
    }
    // Asignacion externa de salida a una matriz.
    int matriz1[5][2] = {{5,2},{6,7},{4,3},{5,1},{1,1}};
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; i++)
        {
            cout << matriz1[i][j];
        }
        cout <<"\n";
    }
    // Asignacion interna de entrada a una matriz.
    tipoRegistro matriz[5][2];
    int matriz[5][2] = {{},{}};
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; i++)
        {
            matriz[i][j].campo1 = 0;
            matriz[i][j].campo2 = 0;
        }
    }
    // Vector tridimencional.
    int m[5][4][6];
    for(i=0; i<5; i++)
    {
        for(j=0; j<4; j++)
        {
            for(k=0; k<6; k++)
            {
                matriz[i][j][k];
            }
        }
    }
    //Asignacion externa de salida a un vector tridimencional.
    for(i=0; i<5; i++)
    {
        for(j=0; j<4; j++)
        {
            for(k=0; k<6; k++)
            {
                cout << matriz[i][j][k];
            }
        }
    }

    
    tipoResgistro matriz[5][4][6];
    int m[5][4][6];
    for(i=0; i<5; i++)
    {
        for(j=0; j<4; j++)
        {
            for(k=0; k<6; k++)
            {
                cout << matriz[i][j][k].campo1;
                cout << matriz[i][j][k].campo2;
            }
        }
    }


    system("PAUSE");
    return 0;
}

// Clase de consulta 1: breve explicacion de punteros.

#include <iostream>
#include <stdlib.h>
using namespace std;

// trabajando con punteros: 
// El & (Operador de direccion).
// El * (Operador de indireccion).

struct tr // struct tipoRegistro
{
    int campo1;
    int campo2;
};

int main ()
{   
    int b[10]; // b es la direccion de memoria del primer entero de ese vector de 10 enteros.
    // b es equivalente a decir &v[0]. por lo tanto, b es un puntero a la primera direccion de memoria del vector.
    // b[1] es el elemento que esta en la direccion de memoria desplazado 1 del comienzo del vector.
    // b[4] es el elemento que esta en la direccion de memoria desplazado 4 del comienzo del vector.
    int* v;
    v = new int[10];

    b[0] = 20;
    b[1] = 30;
    v[0] = b[0];
    v[1] = b[1];

    cout << b[0] << " , " << b[1] << endl;
    cout << v[0] << " , "  << v[1] << endl;

    tr r; // tipoRegistro registro;
    tr* pr; // tipoRegistro* punteroRegistro.
    r.campo1 = 1;
    r.campo2 = 2;
    pr = &r; // A punteroResgistro, le asignamos la direccion del registro. 

    int a=10;
    int* p; // declaramos un puntero a un entero
    float x = 11.5;
    float *q = &x;

    p = &a; // Le asignamos la direccion de memora de la variable estatica (a).

    cout <<"El valor de (a) es: " << a << endl;
    cout <<"El valor de referenciacion de puntero es: " << *p << endl;

    cout <<"El valor de (x) es: " << x << endl;
    cout <<"El valor de desrefernciacion de puntero es: " << *q << endl;

    cout <<"El campo1 es: " << r.campo1 << " o " << (*pr).campo1 << " o " << pr -> campo1 << endl;
    cout <<"El campo2 es: " << r.campo2 << " o " << (*pr).campo2 << " o " << pr -> campo2 << endl;

    // A un puntero se le puede asignar una instancia en tiempo de ejecuccion.
    // Se crea una variable anonima atraves de (new).

    p = new int; // variable anonima instanciada a traves del puntero p.
    *p = 84; // La instancia del puntero p, le asignamos 84 como entero.
    cout << *p << endl;
    delete p; // No borra el puntero, borra la instancia.

    p = new int; // Se crea otra instancia de p.
    *p = 24;
    cout << *p << endl;

    pr = new tr(); // Se puede poner o no los parentesis.
    pr ->campo1 = 30;
    pr ->campo2 = 44;
    cout << pr->campo1 << endl;
    cout << pr->campo2 << endl;

    system("PAUSE");
    return 0;
}

// Clase 5: busqueda secuencial, busqueda binaria y apareo.

// Busqueda secuencial.
#include<iostream>
#include<stdlib.h>
using namespace std;

struct alumno
{
    char nombre;
    int legajo;
    int curso;
    fecha fecha;

};

int main()
{
    int m[10][10];
    int i, j, valor;

    for(i=0; i<10; i++) // Filas.
    {
        for(j=0; j<10; j++) // Columnas.
        {
            cout <<"Ingrese un valor"; cin >> valor;
            m[10][10] = valor;
        }
    }

// P.U.P. Posicion unica y predecible.
// Mis alumnos estan todos y se numeran del 1 al 1000.

    alumno v[1000];
    int buscado = 235;
    // Dame los datos del alumno 235.
    for(int i=0; i<1000; i++) // Busqueda secuencial.
    {
        if(v[i].legajo==buscado)
        {
            cout <<"Se encontro al alumno con el legajo [" << alumno.legajo <<"] y se llama: " << alumno.nombre << endl;
        }
    }
    i=0;
    while(v[i].legajo!=buscado) // Otra forma mas prolija.
    {
        i++;
    }

    cout << v[i].nombre << endl;
    
    cout << v[buscado - 1] << endl; // Buscado - inicial.
    
    // SI la informacion viene desordenada:
    for(i=0; i<1000; i++)
    {
        cout <<"ingrese un legajo: "; cin >> legajo;
        v[legajo-1].legajo = legajo; 
    }

    return 0;
}

// Ejercicio de la guia como ejemplo de practica de busqueda secuencial en clase.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int numSocio;
    int codDeporte;
    int deportes[20] = {0};
    int mayor = 0;

    cout <<"ingrese su numero de socio: "; cin >> numSocio;

    while(numSocio != 0)
    {
        cout <<"ingrese el codigo de deporte al que se quiera anotar: "; cin >> codDeporte;
        deportes[codDeporte-1]++;
        cout <<"ingrese su numero de socio: "; cin >> numSocio;
    }

    for(int i=0; i<20; i++)
    {
        if(mayor < deportes[i])
        {
            mayor = deportes[i];
        }
        cout <<"La cantidad de inscriptos en el deporte n°" << i+1 <<" es: " << deportes[i] << endl;
    }
    
    cout <<"El deporte con la mayor cantidad de inscriptos fue el n°: " << mayor << endl;

    return 0;
}

// Busqueda binaria.
#include<iostream>
#include<stdlib.h>
using namespace std;

// ¿Y si no estan todos los datos pero el vector esta ordenado?:
// Tengo 1000 legajos pero van del 1 al 4200.

int busquedaBinaria(int v[], int buscado, int& primero, int n)
{
    primero = 0;
    int ultimo = n-1; // Posicion.
    int medio;

    while(primero<=ultimo)
    {
        medio = (primero+ultimo)/2; // posicion.
        if(v[medio==buscado])
        {
            return medio;
        }

        if(v[medio]>buscado)
        {
            ultimo = medio-1;
        }else{
            primero = medio+1;
        }
    }
    return -1;
}

// Apareo en vectores:
#include<iostream>
#include<stdlib.h>
using namespace std;

void apareo(int v1[], int v2[], int v3[], int n, int m)
{
    int i=0;
    int j=0;
    int k=0;

    while(i<n && j<m)
    {
        if (v1[i]<v2[j])
        {
            v3[k]=v1[i];
            i++;
            k++;
        }else{
            v3[k]=v2[j];
            j++;
        }
        k++;
    }
    while(i<n)
    {
        v3[k]=v1[i];
        i++;
        k++;
    }
    while(j<m)
    {
        v3[k]=v2[i];
        j++;
        k++;
    }

}

int main ()
{
    int v1[10];
    int v2[5];
    int v3[15];

    apareo(v1, v2, v3, n, m)
}

// Clase de consulta 2: Breve explicacion de archivos.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct tipoRegistro
{
    int campo1;
    int campo2;
};

int main()
{
    FILE* f = fopen("miArchivo", "Wb+");
    // Como el archivo no esxiste se abre con W, y como vamos a leerlo despues, le agregamos la b  
    // Funcionalidad.

    tipoRegistro r;

    r.campo1 = 1; // Asignamos valores a los campos.
    r.campo2 = 10; // Asignamos valores a los campos.

    // fwrite escribe en el archivo. // sizeof(r) es el tamaño del registro. // 1 es la cantidad de registros. // f es el archivo.
    fwrite(&r, sizeof(r), 1, f); // Guarda el bloque de un registro, almacenado en (r).

    r.campo1 = 2;
    r.campo2 = 20;

    fwrite(&r, sizeof(r), 1, f); // Guarda el bloque de un registro, almacenado en (r).

    r.campo1 = 3;
    r.campo2 = 30;

    fwrite(&r, sizeof(r), 1, f); // Guarda el bloque de un registro, almacenado en (r).

    fseek(f, 0, SEEK_SET); // Posicionamos el puntero al princi´pio del archivo para leer.

    fread(&r, sizeof(r), 1, f);

    while(!feof(f)) // 
    {
        cout << r.campo1 << endl;
        cout << r.campo2 << endl;
        fread(&r, sizeof(r), 1, f); // Lee el siguiente registro.
    }

    fclose(f); // Para cerrar el archivo.
/*
    // Otra forma de leer.
    while(fread(&r, sizeof(r), 1, f))
    cout << r.campo1 << r.campo2 << endl;
    
    fclose(f); // Para cerrar el archivo.
*/
    system("PAUSE");
    return 0;
}

 
// Clase 7: Archivos, punteros y pilas.

#include<iostream>
using namespace std;

struct alumno
{
    int legajos;
    char alumnos[50];
};

int main()
{
    FILE* f=fopen(alumno);
    int N;

    N = cantReg(f);
    alumno alV[N];
    fread(alV, sizeof(alumno), N, f);

    while (fread())
    fread();

}

int cantReeg(FILE*& f)
{
    int posicionActual = ftell(f); // Conservo la posicion de cuando recibo el archivo.

    fseek(f, 0, SEEK_END); // Lleva el puntero del registro al final
    int tamaño = ftell(f); // Cantidad de bytes del registro desde el principio hasta el final.
    cantRegistros = tamaño / sizeof(alumno);

    fseek(f, posicionActual, SEEK_SET); // Vuelvo a la posicion donde estaba en un principio.

    return cantRegistros;
}

// Un puntero es un tipo de dato que permite guardar direcciones en memoria. 
// Representados en hexadecimal (0x). Representa un lugar en la memoria.
// Operadores: 

int main ()
{
    int a=20;
    // El * se utiliza para declarar el tipo de dato puntero. int*, char*, float*.
    int* puntero = &a;
    cout << a << endl;
    cout << puntero << endl;

    int* puntero = new int(); // new int() Reserva espacio en la memoria.
    *puntero = 20;
    cout << puntero << endl;
    // NULL = Dato nulo.
    int* puntero = NULL;
    cout << puntero << endl;

    alumno* punteroAl = new alumno();
    (*punteroAl).legajos = 33;
    cout << (*punteroAl).legajos << endl; // punteroAl -> legajos;

    return 0;
}

// Structuras lineales y enlazadas. Pilas, colas, listas.
// Structuras no lineales: Arboles, Grafos.

// Pilas: Solo ver si esta vacia, apilar o desapilar.
// Colas: Solo puedo ver si esta vacia, puedo encolar o desencolar.
// Listas: Hago lo que quiero. 

// Clase de consulta: Listas de listas.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Cargar los datos de un archivo a un vector de listas de listas
// En el archivo tenemos 3 campos.
// campo1: [1..10] --> perfectamente acotado.
// campo2: entero.
// campo3: entero.

// En el vector el campo1, en la lista principal el campo2, en la lista secundaria el campo3 para
// cargar en el vector



struct RegistroDelArchivo
{
    int campo1;
    int campo2;
    int campo3;
};

// Vamos a declara los nodo.

struct NodoListaSecundaria
{
    int info; // Dijimos que el campo de la informacion es un int.
    NodoListaSecundaria* sgte; // es un puntero a una estructura del mismo tipo(Autoreferenciada).
};

// Declarar el tipo info de la lista principal.
// Tiene que tener el entero q se corresponde con el campo2, y el puntero a la lista secundaria.

struct TipoInfoLP
{
    int campo2; // El dato para ordenar.
    NodoListaSecundaria* subLista; // El puntero a la lista secundaria.
};

struct NodoListaPrincipal
{
    TipoInfoLP info; // El campo de la informacion tiene el campo2 y el puntero a la sublista
    NodoListaPrincipal* sgte; // La referencia al sgte nodo
};

// Declarar el vector de puntero.
NodoListaPrincipal* vector[10] = {NULL}; // El vector para dirigir el campo1 es un vector de punteros inicializados en

FILE* f = fopen("archivo", "rb+"); // Suponemos que el archivo existe.

NodoListaSecundaria* insertarOrdenado(NodoListaSecundaria*& lista, int x)
{
    NodoListaSecundaria* nuevo = new NodoListaSecundaria();
    nuevo->info = x;

    if(lista == NULL || x < lista->info)
    {
        nuevo->sgte = lista;
        lista = nuevo;
    }else{
        NodoListaSecundaria* q = lista;
        
        while(lista->sgte != NULL && x > lista->sgte->info)
        {
            q = q->sgte;
        }

        nuevo->sgte = q->sgte;
        q->sgte = nuevo;
    }

    return nuevo;
}

NodoListaPrincipal* insertarOrdenado(NodoListaPrincipal*& lista, TipoInfoLP info)
{
    NodoListaPrincipal* nuevo = new NodoListaPrincipal();
    nuevo->info = info;

    if(lista == NULL || info.campo2 < lista->info.campo2)
    {
        nuevo->sgte = lista;
        lista = nuevo;
    }else{
        NodoListaPrincipal* q = lista;
        
        while(lista->sgte != NULL && info.campo2 < lista->info.campo2)
        {
            q = q->sgte;
        }

        nuevo->sgte = q->sgte;
        q->sgte = nuevo;
    }

    return nuevo;
}

// Buscamos para saber si esta o no y si no esta usamos el 2do insertar.

NodoListaPrincipal* buscar(NodoListaPrincipal* lista, TipoInfoLP x)
{
    NodoListaPrincipal* q = lista; // Ponemos un puntero al principio de la estructura para empezar a recorrer.

    while((lista != NULL) && (q->info.campo2 != x.campo2))
    {
        // Buscamos mientras la lista sea distinto de null o si el nodo
        q = q->sgte;
    }

    return q; // Retorna null si no lo encuentra y donde esta el nodo en caso de encontrarlo
}

NodoListaPrincipal* cargarSinRepetir(NodoListaPrincipal*& lista, TipoInfoLP x)
{
    NodoListaPrincipal* p = buscar(lista, x);

    if(p == NULL)
    {
        p = insertarOrdenado(NodoListaPrincipal*& lista, x);
    }

    return p;
}

int main()
{
    RegistroDelArchivo registro;
    // Recordar que en las listas tenemos el puntero ya inicializado.

    NodoListaPrincipal* p;
    NodoListaSecundaria* q;
    TipoInfoLP valor;
    while(fread(&registro, sizeof(registro), 1, f))
    {
        // Cargamos la informacion para el nodo de la lista principal.
        valor.campo2 = registro.campo2;
        valor.subLista = NULL;
        p = cargarSinRepetir(vector[registro.campo1 - 1]);
        insertarOrdenado(p->info.subLista, registro.campo3);
    }

    return 0;
}

// Clase 9:  
// Dadas 20 regionales y 10 carreras de la utn y un archivo con los legajos de los alumnos de todas la facultades con los siguientes datos:
// IDRegional | numericos [20] | IDCarreras | numericos [10] | num.legajo 

// Se solicita 
// 1- Un listado de los legajos ordenado por regional, carrera, legajo
// 2- Un listado de los legajos ordenado por carrera, regional, legajo.
// En ambos casos mostrar antes de listar los alumnos la cantidad total.



#include<iostream>
#include<stdlib.h>

using namespace std;

struct NodoCliente // Nodo porque es una lista.
{
    int legajo;
    NodoCliente* sgte;
};

// Prototipo de las funciones.
NodoCliente* insertarOrdenado(NodoCliente*& lista, int legajo);
int pop(NodoCliente*&, lista);

struct tipoRegistro
{
    int regional;
    int carrera;
    int legajo;
};

struct tipoMatriz
{
    int cantAlumnos;
    NodoCliente* lista;
};

int main()
{
    int i, j;
    tipoRegistro r;
    int legajo;
    NodoCliente* aux;
    tipoMatriz matriz[20][10]; // 20 Regionales, 10 Carreras.
    FILE* f = fopen("universidad.dat", "rb+");


    // Inicializar la matriz.
    for(i=0; i<20; i++)
    {
        for(j=0; j<10; i++)
        {
            matriz[i][j].cantAlumnos=0;
            matriz[i][j].lista=NULL;
        }
    }

    while(fread(&r, sizeof(r), 1, f))
    {
        i = r.regional-1;
        j = r.carrera-1;
        matriz[i][j].cantAlumnos++;
        legajo = r.legajo;
        insertarOrdenado(matriz[i][j].lista, legajo);
    }

    // Mostrar por regional, carrera, legajo.
    // Tener en cuenta que no tenemos que eliminar el nodo en esta primera pasada.

    for(i=0; i<20; i++) // Recorre las regionales.
    {
        for(j=0; j<10; j++) // Recorre las carreras.
        {
            aux = matriz[i][j].lista; // Un punteroa aux para recorrer la lista porque no debemos eliminar los nodos. 

            while(aux != NULL) // Recorre los legajos.
            {
                cout << aux->legajo << endl;
                aux = aux->sgte
            }
        }
    }

    // Mostrar por carrera, regional, legajo (Es decir, recorrer por columna).
    // En este caso, vamos a sacar el nodoo porque no lo vamos a necesitar mas.

    for(j=0; j<10; j++)
    {
        for(i=0; i<20; i++)
        {
            while(matriz[i][j].lista != NULL)
            {
                legajo = pop(matriz[i][j].lista); // En este caso, pop hace avanzar el conteo.
                cout << legajo << endl;
            }
        }
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
