#include "Expresion.h"

// Carga un Struct expresion con su índice y árbol de terminos.
Expresion expresionCrear(ArbolExpresion arbol, int indice)
{
    Expresion exp;
    ArbolExpresion arbCopia;
    exp.indice = indice;
    arbolExpresionCopiar(arbCopia, arbol);
    exp.terminos = arbCopia;
    return exp;
}

// Devuelve el indice de la expresión.
int expresionDevolverIndice(Expresion exp)
{
    return exp.indice;
}

// Devuelve el árbol expresión del estructurado expresión.
ArbolExpresion expresionDevolverArbolExpresion(Expresion expresion)
{
    return expresion.terminos;
}

// Copia una expresión
void expresionCopiar(Expresion &expCopia, Expresion expOriginal){
    expCopia.indice = expOriginal.indice;
    expCopia.terminos = NULL;
	arbolExpresionCopiar(expCopia.terminos, expOriginal.terminos);
}

// Despliega la expresion
void expresionMostrar(Expresion exp){
    printf("%d) ", exp.indice);
    arbolExpresionDesplegarArbol(exp.terminos);
    printf("\n");
}

// Liberar memoria dinamica del arbolexpresion
void expresionLiberarArbolDeExpresion(Expresion &exp){
	arbolExpresionDestruir(exp.terminos);
}