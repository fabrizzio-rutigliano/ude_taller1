# include "Expresion.h"

typedef struct nodoLis{
        Expresion info;
        nodoLis * sig;
        }nodoL;
        
typedef nodoL * ListaExpresion;

void listaExpresionCrear(ListaExpresion &listaExp);

void listaExpresionDestruir(ListaExpresion &listaExp);

Boolean listaExpresionEsVacia(ListaExpresion listaExp);

int listaExpresionIndiceSiguiente(ListaExpresion listaExp);

void listaExpresionDestruir(ListaExpresion &ListaExp);

void listaExpresionInsertarFinal(ListaExpresion &ListaExp, Expresion exp);

Boolean listaExpresionExisteIndice(ListaExpresion ListaExp, int indice);

void listaExpresionDevolverExpresionXIndice(ListaExpresion ListaExp, int indice, Expresion &expresion);