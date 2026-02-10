# include "Termino.h"

typedef struct NodoArb{
        Termino info;
        int numeroNodo; //facilita bajar a disco : ABB
        NodoArb * hizq;
        NodoArb * hder;
        }nodoA;
        
typedef nodoA * ArbolExpresion;
