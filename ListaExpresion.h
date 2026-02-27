#ifndef LISTAEXPRESION_H_INCLUDED
#define LISTAEXPRESION_H_INCLUDED

#include "Expresion.h"

typedef struct nodoLis{
        Expresion info;
        nodoLis * sig;
        }nodoL;
        
typedef nodoL * ListaExpresion;

// Crea una lista vacía.
void listaExpresionCrear(ListaExpresion &listaExp);

// Libera la memoria asignada a la lista.
void listaExpresionDestruir(ListaExpresion &listaExp);

// Evaluar si la lista está vacía.
Boolean listaExpresionEsVacia(ListaExpresion listaExp);

// Recorre la lista devolviendo la cantidad de elementos + 1.
int listaExpresionIndiceSiguiente(ListaExpresion listaExp);

// Inserta la expresión al final de la lista.
void listaExpresionInsertarFinal(ListaExpresion &listaExp, Expresion exp);

// Evalua si el indice dado existe en la lista expresión.
Boolean listaExpresionExisteIndice(ListaExpresion listaExp, int indice);

// Dado un indice devuelve la expresión correspondiente.
Expresion listaExpresionDevolverExpresionXIndice(ListaExpresion listaExp, int indice);

#endif // LISTAEXPRESION_H_INCLUDED