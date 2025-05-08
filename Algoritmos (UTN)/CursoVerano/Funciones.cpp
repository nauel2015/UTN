
// Funcion busqueda binaria:

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


// Funcion de apareo:
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