
// Concepto de matrices/tablas (Arrays bidimensionales).

una matriz es un vector de vectores o un tambien llamado arrays bidimensional.

// Como declarar una matriz: La manera de hacerlo es similar a la de un vector.

tipo matriz[nFilas][nColumnas];
int numeros[2][3]; char letras[3][2];

// Como agregar elementos a una matriz:

int numeros[2][3] = {{1,2,3},{4,5,6}}; // {1,2,3,4,5,6}

cout << numeros[1][2]; // Fila 1, Columna 2 = 6
cout << numeros[0][1]; // Fila 0, Columna 1 = 2

// Ejercicio n°1: Programa que rellena una matriz con los numeros de filas y columnas que ingresa el usuario.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"\n\tBienvenido al Programa que rellena una matriz con los numeros de filas y columnas que ingresa el usuario." << endl;

    int numerosMatriz[100][100], filas, columnas;

    cout <<"\nIngrese la cantidad de filas de la matriz: "; cin >> filas;
    cout <<"\nIngrese la cantidad de comlumnas de la matriz: "; cin >> columnas;

    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> numerosMatriz[i][j];
        }
    }

    cout <<"\nSe muestran la cantidad de filas y columnas con los datos que ingreso el usuario: " << endl;

    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
    {
        cout << numerosMatriz[i][j] << " ";
    }
        cout <<"\n";
    }

    cout <<"\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°2: Programa que define una matriz 3x3 y muestra solo los datos diagonales.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"Bienvenido al Programa qur define una matriz 3x3 y muestra muestra solo los datos diagonales." << endl;

    int matriz[3][3]{{1,2,3},{4,5,6},{7,8,9}};

    cout <<"\nSe muestra los datos dentro de las filas y columnas: " << endl;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout <<"Se muestran los datos diagonales de la matriz:" << endl;

    // Se iguala a i con j para que solo se muestren aquellas filas y columnas q son iguales ([0][0],[1][1],[2][2]).
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (i == j)
            {
                cout << matriz[i][j] << " ";
            }
        }
    }

    cout <<" \n\n";
    system("PAUSE");
    return 0;
}

+// Ejercicio n°3: Programa que copia el contenido de una matriz 3x3 a otra matriz.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"\n\tBienvenido al programa que copia el contenido de una matriz 3x3 a otra matriz." << endl;

    int matriz[3][3]{{1,2,3},{4,5,6},{7,8,9}};
    int matriz2[3][3];

    // Se igualan las matrices.
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matriz2[i][j] = matriz[i][j];
        }
    }

    cout <<"\nSe muestra la matriz copiada: " << endl;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << matriz2[i][j] << " ";
        }
        cout << "\n";
    }

    cout <<"\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°4: Programa que copia el contenido de una matriz 3x3 a otra matriz con numeros ingresados por el usuario.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"\n\tBienvenido al Programa que copia el contenido de una matriz 3x3 a otra matriz con numeros ingresados por el usuario." << endl;

    int matriz[3][3];
    int matriz2[3][3];

    // Se le piden numeros para la matriz al usuario
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> matriz[i][j];
        }
    }

    // Se igualan las matrices.
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matriz2[i][j] = matriz[i][j];
        }
    }

    cout <<"\nSe muestra la matriz copiada: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << matriz2[i][j] << " ";
        }
        cout << "\n";
    }

    cout <<"\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°5: Programa que lee el contenido de una matriz 3x3 y crea su matriz transpuesta.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"\n\tBienvenido al Programa que lee el contenido de una matriz 3x3 y crea su matriz transpuesta." << endl;

    int matriz[3][3];

    // Se le piden numeros para la matriz al usuario
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> matriz[i][j];
        }
    }

    cout <<"\nSe muestra la matriz original: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << matriz[i][j] <<" ";
        }
        cout << "\n";
    }

    cout <<"\nSe muestra la matriz transpuesta: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << matriz[j][i] << " ";
        }
        cout << "\n";
    }

    cout <<"\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°6: Programa que suma 2 matrices de 3x3.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"\n\tBienvenido al Programa que suma 2 matrices de 3x3." << endl;

    int matriz[3][3];
    int matriz2[3][3];
    int matrizSuma[3][3];

    // Se le piden numeros para la primera matriz al usuario.
    cout <<"\nPrimera matriz: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> matriz[i][j];
        }
    }

    // Se le piden numeros para la segunda matriz al usuario.
    cout <<"\nSegunda matriz: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> matriz2[i][j];
        }
    }

    // Se suman las matrices.
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrizSuma[i][j] = matriz[i][j] + matriz2[i][j];
        }
        cout << "\n";
    }

    cout <<"\nSe muestra la suma de las matrices: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << matrizSuma[i][j] <<" ";
        }
        cout << "\n";
    }

    cout <<"\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°7: Programa que determina si una matriz es simetrica o no.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"\n\tBienvenido al Programa que determina si una matriz es simetrica o no." << endl;

    int matriz[100][100], filas, columnas;
    char flag = 'F';

    cout <<"\ningrese la cantidad de filas de la matriz: " << endl; cin >> filas;
    cout <<"\ningrese la cantidad de columnas de la matriz: " << endl; cin >> columnas;

    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> matriz[i][j];
        }
    }

    if(filas == columnas)
    {
        for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            if(matriz[i][j] == matriz[j][i])
            {
                flag = 'V';
            }else{
                flag = 'F';
                break;
            }
        }
    }
    }

    if(flag == 'V')
    {
        cout <<"\nLa matriz es simetrica.";
    }else{
        cout <<"\nLa matriz no es simetrica.";
    }

    cout <<"\n\n";
    system("PAUSE");
    return 0;
}

// Ejercicio n°8: Programa que multiplica 2 matrices de 3x3.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{   
    cout <<"\n\tBienvenido al Programa que multiplica 2 matrices de 3x3." << endl;

    int matriz[3][3];
    int matriz2[3][3];
    int matrizMultiplicacion
    [3][3];

    // Se le piden numeros para la primera matriz al usuario.
    cout <<"\nPrimera matriz: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> matriz[i][j];
        }
    }

    // Se le piden numeros para la segunda matriz al usuario.
    cout <<"\nSegunda matriz: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout <<"\nIngrese un numero para la fila [" << i << "] columna [" << j << "]: "; cin >> matriz2[i][j];
        }
    }

    // Se multiplcan las matrices.
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrizMultiplicacion[i][j] = matriz[i][j] * matriz2[i][j];
        }
        cout << "\n";
    }

    cout <<"\nSe muestra la multiplicacion de las matrices: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << matrizMultiplicacion[i][j] <<" ";
        }
        cout << "\n";
    }

    cout <<"\n";
    system("PAUSE");
    return 0;
}
