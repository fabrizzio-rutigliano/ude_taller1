# include "ListaString.h"
# include "ListaExpresion.h"
# include "Archivos.h"
# include "TipoError.h"


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

//FR
void comandoRecuperar(ListaString listaStr);

//FR
Boolean comandoSalir(ListaString listaStr);

//FR
void comandoMostrar(ListaString listaStr, ListaExpresion listaExp);
