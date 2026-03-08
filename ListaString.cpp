#include "ListaString.h"

//Crea una lista vacia
void listaStringCrear(ListaString &lista){
    lista = NULL;
}

//Libera toda la memoria de lista
void listaStringDestruir(ListaString &lista){
    ListaString aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista ->sig;
        strDestruir(aux ->palabra);
        delete aux;
    }
}

//Inserta str al final de lista
void listaStringInsertarElemento(String str, ListaString &lista){

    ListaString aux;
    ListaString nuevoNodo = new NodoS();
    strCrear(nuevoNodo->palabra);
    strCop(nuevoNodo->palabra, str);
    nuevoNodo ->sig = NULL;
    
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        aux = lista;
        while(aux ->sig != NULL){
            aux = aux ->sig;
        }
        aux->sig = nuevoNodo;
    }
}

//Parsea entrada por espacios, las 'palabras' resultantes se guardan en lista
void listaStringSplit(String entrada, ListaString &lista){
    String strAux, strOut, strResto;

    strCrear(strResto);
    strCop(strResto, entrada);
    while(!strEsVacio(strResto)){
        strCrear(strAux);
        strEliminarEspaciosInicio(strResto, strAux);

        strDestruir(strResto);
        strCrear(strResto);

        strCrear(strOut);
        strDividir(strAux, strOut, strResto);
        listaStringInsertarElemento(strOut, lista);
        strDestruir(strOut);
        strDestruir(strAux);
    }
    strDestruir(strResto);
}

//Obtiene str guardado en lista segun su indice
//Precondicion la lista no es vacia
//Precondicion indice es mayor a cero y es menor igual a la cantidad de elementos de la lista
void listaStringObtener(int indice, ListaString lista, String &str){
    Boolean encontre = FALSE;
    ListaString aux = lista;
    int count = 0;

    while(aux != NULL && !encontre){
        if(count == indice){
            strCop(str, aux ->palabra);
            encontre = TRUE;
        }else{
            count ++;
            aux = aux ->sig;
        }
    }
}

//Retorna la cantidad de elementos de lista
int listaStringCantElementos(ListaString lista){
    ListaString aux = lista;
    int count = 0;

    while (aux != NULL)
    {
        count ++;
        aux = aux ->sig;
    }
    return count;
}
