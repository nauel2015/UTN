#include <iostream>
using namespace std;

struct tipoRegistro{
    int campo1;
    int campo2;
    int campo3;
};

struct NodoCliente { //declarar la estructura del nodo
    tipoRegistro info;
    NodoCliente*sgte;
};

NodoCliente *insertarOrdenado(NodoCliente *&, tipoRegistro);
NodoCliente *buscarEnLista(NodoCliente *, tipoRegistro);
NodoCliente *cargarSinRepetirEnLista(NodoCliente *&, tipoRegistro);    
tipoRegistro pop(NodoCliente*&);

int main(){
    FILE*f=fopen("prueba", "rb+");
    tipoRegistro registro;
    NodoCliente *lista = NULL;

    fread(&registro, sizeof registro, 1, f);
    while (!feof(f)){
        //cargar sin repetir
        cargarSinRepetirEnLista(lista, registro);
        fread(&registro, sizeof registro, 1, f);
    }
    
    while(lista!=NULL){
        registro = pop(lista);
        cout << registro.campo1 << " " << registro.campo2 << " " << registro.campo3 << endl;
    }

    
    fclose(f);
    system("PAUSE");
    return 0;
}

NodoCliente *insertarOrdenado(NodoCliente *&lista, tipoRegistro x){
    NodoCliente *p = new NodoCliente;
    p -> info = x;

    if(lista == NULL || x.campo1 < lista -> info.campo1){
        p->sgte = lista;
        lista = p;
    } else {
        NodoCliente *q = lista;

        while(q->sgte != NULL && x.campo1 > q->sgte->info.campo1){
            q = q ->sgte;
        }

        p ->sgte = q->sgte;
        q -> sgte = p;
    }

    return p;
}

tipoRegistro pop(NodoCliente *&lista){
    NodoCliente *p = lista;
    tipoRegistro x = p->info;
    lista = p->sgte;
    delete p;

    return x;
}

NodoCliente *buscarEnLista(NodoCliente *lista, tipoRegistro x) {
    NodoCliente *q = lista;

    while(q != NULL && x.campo1 != q->info.campo1){
        q = q->sgte;
    }

    return q; //si no lo encontro, q vale NULL y si lo encontró, la direccion del dato encontrado
}

NodoCliente *cargarSinRepetirEnLista(NodoCliente *&lista, tipoRegistro x){
    NodoCliente *p = buscarEnLista(lista, x);

    if(p==NULL) {
        p = insertarOrdenado(lista, x);
    }

    return p;
}