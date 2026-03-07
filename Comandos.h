#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include "ListaString.h"
#include "ListaExpresion.h"
#include "Archivos.h"
#include "TipoError.h"

//Comando Simple
void comandoSimple(ListaString listaStr, ListaExpresion &listaExp);

//Comando Compuesta
void comandoCompuesta(ListaString listaStr, ListaExpresion &listaExp);

//Comando Calcular
void comandoCalcular(ListaString lstring, ListaExpresion listaExp);

//Comando Iguales
void comandoIguales(ListaString lstring, ListaExpresion listaExp);

//Comando Guardar
void comandoGuardar(ListaString lstring, ListaExpresion listaExp);

//Comando Mostrar
void comandoMostrar(ListaString listaStr, ListaExpresion listaExp);

//Comando Salir
void comandoSalir(ListaString &listaStr, ListaExpresion &listaExp, Boolean &salir);

//Comando Recuperar
void comandoRecuperar(ListaString listaStr, ListaExpresion &listaExp);

//SOLO POR MOTIVOS DE TESTING
void procesarEntrada(ListaString &lista, String entrada);

#endif // COMANDO_H_INCLUDED