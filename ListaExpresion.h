# include "Expresion.h"

typedef struct nodoLis{
        Expresion info;
        nodoLis * sig;
        }nodoL;
        
typedef nodoL * ListaExpresion;