# include "ListaString.h"
# include "ListaExpresion.h"
# include "Archivos.h"


Boolean comandoEsValido(String str);

//GL
void comandoSimple(ListaString listaStr, ListaExpresion &listaExp);

//GL
void comandoCompuesta(ListaString listaStr, ListaExpresion &listaExp);

//GP
void comandoCalcular(ListaString listaStr);

//GP
void comandoIguales(ListaString listaStr);

//GP
void comandoGuardar(ListaString listaStr);

void comandoRecuperar(ListaString listaStr);

void comandoSalir(ListaString listaStr);

void comandoMostrar(ListaString listaStr);
