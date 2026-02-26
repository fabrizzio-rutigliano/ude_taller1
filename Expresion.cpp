#include "Expresion.h"

// Carga un Struct expresion con su índice y árbol de terminos.
Expresion expresionCrear(ArbolExpresion arbol, int indice)
{
    Expresion exp;
    exp.indice=indice;
    exp.terminos=arbol;
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
