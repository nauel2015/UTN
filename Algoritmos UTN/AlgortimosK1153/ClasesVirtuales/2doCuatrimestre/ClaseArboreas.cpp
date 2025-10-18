
// Ejercicio N°1: 

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Declaracion de las funciones.
TreeNode* crearNodo(int valor);
TreeNode* insertar(TreeNode* root, int valor);
int calcularAltura(TreeNode* root);
bool estaBalanceado(TreeNode* root);

int main()
{
    TreeNode* root = nullptr; // Inicializa un árbol vacío

    // Inserta elementos en el árbol
    root = insertar(root, 4);
    root = insertar(root, 2);
    root = insertar(root, 6);
    root = insertar(root, 1);
    root = insertar(root, 3);
    root = insertar(root, 5);
    root = insertar(root, 7);

    // Tu árbol ahora contiene los elementos 1, 2, 3, 4, 5, 6, 7

    return 0;
}

// Definicion de las funciones.

// Función para crear un nuevo nodo con el valor dado
TreeNode* crearNodo(int valor)
{
    TreeNode* nuevoNodo = new TreeNode;
    nuevoNodo->data = valor;
    nuevoNodo->left = nullptr;
    nuevoNodo->right = nullptr;
    return nuevoNodo;
}

// Función para insertar un nuevo elemento en el árbol binario de búsqueda
TreeNode* insertar(TreeNode* root, int valor)
{
    if (root == nullptr)
    {
        return crearNodo(valor); // Si el nodo es nulo, crea un nuevo nodo con el valor dado
    }

    // Si el valor es menor que el valor actual, inserta en el subárbol izquierdo
    if (valor < root->data)
    {
        root->left = insertar(root->left, valor);
    }
    // Si el valor es mayor que el valor actual, inserta en el subárbol derecho
    else if (valor > root->data)
    {
        root->right = insertar(root->right, valor);
    }

    return root; // Retorna el nodo raíz actual después de la inserción
}

// Función para calcular la altura de un árbol
int calcularAltura(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int alturaIzquierda = calcularAltura(root->left);
    int alturaDerecha = calcularAltura(root->right);

    return 1 + max(alturaIzquierda, alturaDerecha);
}

// Función para verificar si un árbol está balanceado
bool estaBalanceado(TreeNode* root)
{
    if (root == nullptr)
    {
        return true; // Un árbol vacío se considera balanceado
    }

    int alturaIzquierda = calcularAltura(root->left);
    int alturaDerecha = calcularAltura(root->right);

    int diferenciaAltura = alturaIzquierda - alturaDerecha;
    if (diferenciaAltura < 0)
    diferenciaAltura = diferenciaAltura * -1;

    if (diferenciaAltura <= 1 && estaBalanceado(root->left)
    && estaBalanceado(root->right))
    {
        return true;
    }

    return false;
}

