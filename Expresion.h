# include "ArbolExpresion.h"

typedef struct{
        int indice;
        ArbolExpresion terminos;
        } Expresion;


void expresionCrear(ArbolExpresion arbol, int indice, Expresion &exp);

int expresionDevolverIndice(Expresion exp);

ArbolExpresion expresionDevolverArbolExpresion(Expresion expresion);