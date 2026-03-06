#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

#include "ArbolExpresion.h"

typedef struct{
        int indice;
        ArbolExpresion terminos;
        } Expresion;

// Carga un Struct expresion con su índice y árbol de terminos.
Expresion expresionCrear(ArbolExpresion arbol, int indice);

// Devuelve el indice de la expresión.
int expresionDevolverIndice(Expresion exp);

// Devuelve el árbol expresión del estructurado expresión.
ArbolExpresion expresionDevolverArbolExpresion(Expresion expresion);

// Copia una expresión
void expresionCopiar(Expresion &expCopia, Expresion expOriginal);

// Despliega la expresion
void expresionMostrar(Expresion exp);

// Liberar memoria dinamica del arbolexpresion
void expresionLiberarArbolDeExpresion(Expresion &exp);

#endif // EXPRESION_H_INCLUDED