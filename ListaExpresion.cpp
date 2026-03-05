#include "ListaExpresion.h"

// Crea una lista vacía.
void listaExpresionCrear(ListaExpresion &listaExp)
{
    listaExp = NULL;
};

// Libera la memoria asignada a la lista.
//Usar selectora
void listaExpresionDestruir(ListaExpresion &listaExp)
{
    
    while (listaExp != NULL)
    {
        ListaExpresion aux = listaExp;
        listaExp = listaExp->sig;

        // Liberar el árbol asociado a la expresión
        ArbolExpresion arbol;
        arbolExpresionCrear(arbol);
        arbol = expresionDevolverArbolExpresion(aux->info);
        arbolExpresionDestruir(arbol);
        

        delete aux;
    }
};

// Evaluar si la lista está vacía.
Boolean listaExpresionEsVacia(ListaExpresion listaExp)
{
    Boolean vacia = FALSE;
    if (listaExp == NULL)
        vacia = TRUE;

    return vacia;
};

// Recorre la lista devolviendo la cantidad de elementos + 1.
int listaExpresionIndiceSiguiente(ListaExpresion listaExp)
{
    int maxIndice = 0;
    while (listaExp != NULL)
    {
        int idExp = expresionDevolverIndice(listaExp->info);
        if (idExp > maxIndice)
            maxIndice = idExp;

        listaExp = listaExp->sig;
    }
    return maxIndice + 1;
};

// Inserta la expresión al final de la lista.
void listaExpresionInsertarFinal(ListaExpresion &listaExp, Expresion exp)
{
    ListaExpresion nuevoNodo = new nodoL;
    ArbolExpresion arbExp;
    
    arbolExpresionCrear(arbExp);
    nuevoNodo->info.terminos = arbExp; // TODO LLAMAR AL CREAR ARBOL
    expresionCopiar(nuevoNodo->info, exp);
    
    nuevoNodo->sig = NULL;

    if (listaExpresionEsVacia(listaExp))
    {
        listaExp = nuevoNodo;
    }
    else
    {
        ListaExpresion aux = listaExp;
        while (aux->sig != NULL)
            aux = aux->sig;

        aux->sig = nuevoNodo;
    }
};

// Evalua si el indice dado existe en la lista expresión.
Boolean listaExpresionExisteIndice(ListaExpresion listaExp, int indice)
{
    Boolean existe = FALSE;

    while (listaExp != NULL)
    {
        if (expresionDevolverIndice(listaExp->info) == indice)
            existe = TRUE;

        listaExp = listaExp->sig;
    }
    
    return existe;
};

// Dado un indice devuelve la expresión correspondiente.
// Precondicion: existe el indice en la lista
Expresion listaExpresionDevolverExpresionXIndice(ListaExpresion listaExp, int indice)
{
    ListaExpresion auxList;
    auxList = listaExp;
    int auxIndice = 1;
    while (auxIndice < indice)
    {
        auxIndice++;
        auxList = auxList->sig;
    }
    return auxList->info;
};