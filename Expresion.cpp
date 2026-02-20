#include "Expresion.h"


void expresionCrear(ArbolExpresion arbol, int indice, Expresion &exp)
{
    exp.indice=indice;
    exp.terminos=arbol;
}

int expresionDevolverIndice(Expresion exp)
{
    return exp.indice;
}

void expresionDevolverArbolExpresion(Expresion expresion, ArbolExpresion &arbolExpresion)
{
    arbolExpresion=exp;
}