#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED

#include "String.h"

typedef struct nodoS{
        String palabra;
        nodoS * sig;
        }NodoS;
        
typedef NodoS * ListaString;

//Crea una lista vacia
void listaStringCrear(ListaString &lista);

//Libera toda la memoria de lista
void listaStringDestruir(ListaString &lista);

//Inserta str al final de lista
void listaStringInsertarElemento(String str, ListaString &lista);

//Parsea entrada por espacios, las 'palabras' resultantes se guardan en lista
void listaStringSplit(String entrada, ListaString &lista);

//Obtiene str guardado en lista segun su indice
//Precondicion la lista no es vacia
//Precondicion indic es mayor a cero y es menor igual a la cantidad de elementos de la lista
void listaStringObtener(int indice, ListaString lista, String &str);

//Retorna la cantidad de elementos de lista
int listaStringCantElementos(ListaString lista);

//Despliega la listaString completa - solo por motivos de testing - 
void listaStringDesplegar(ListaString lista);

#endif // LISTASTRING_H_INCLUDED
