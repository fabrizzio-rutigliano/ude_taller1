# include "ListaString.h"
# include "ListaExpresion.h"
# include "Archivos.h"
# include "TipoError.h"

//GL
void comandoSimple(ListaString listaStr, ListaExpresion &listaExp);

//GL
void comandoCompuesta(ListaString listaStr, ListaExpresion &listaExp);

//GP
void comandoCalcular(ListaString lstring, ListaExpresion listaExp);

//GP
void comandoIguales(ListaString lstring, ListaExpresion listaExp);

//GP
void comandoGuardar(ListaString lstring, ListaExpresion listaExp);

//FR
void comandoMostrar(ListaString listaStr, ListaExpresion listaExp);

//FR
void comandoSalir(ListaString &listaStr, ListaExpresion &listaExp, Boolean &salir);

//FR
void comandoRecuperar(ListaString listaStr, ListaExpresion &listaExp);

//SOLO POR MOTIVOS DE TESTING
void procesarEntrada(ListaString &lista, String entrada);



