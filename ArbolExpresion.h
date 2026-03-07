#ifndef ARBOLEXPRESION_H_INCLUDED
#define ARBOLEXPRESION_H_INCLUDED
#include "Termino.h"

typedef struct NodoArb{
        Termino info;
        int numeroNodo; //facilita bajar a disco : ABB
        NodoArb * hizq;
        NodoArb * hder;
        }nodoA;
        
typedef nodoA * ArbolExpresion;

//Crea un arbol expresion
void arbolExpresionCrear(ArbolExpresion &arbol);

//Retorna is el arbol es vacio
Boolean arbolExpresionEsVacio(ArbolExpresion arbol);

//Retorna el numor nodo de la raiz
int darNumeroNodo(ArbolExpresion arbol);

//Inserta un termino en arbol expresion en la posicion indicada
void arbolExpresionInsertarTermino(ArbolExpresion &arbol, Termino termino, int posicion);

//Despliega todos los nodos del arbol
void arbolExpresionDesplegarArbol(ArbolExpresion arbol);

//Libera toda la memoria del aborl expresion
void arbolExpresionDestruir(ArbolExpresion &arbol);

//Copia el arbol2 en el arbol1
void arbolExpresionCopiar(ArbolExpresion &ar1, ArbolExpresion ar2);

//Devuelve el mayor indice del arbol
int arbolExpresionDarMayor(ArbolExpresion arbol);

//ajusta los indices del arbol a la derecha para el cons
void arbolExpresionAjustarIndices(ArbolExpresion &d, int posicion);

//indiza el arbol
void arbolExpresionIndizar(ArbolExpresion &a, int &indice);

/* dados dos árboles y un valor, devolver un nuevo árbol   
colocando dicho valor como una nueva raíz y a los dos  
árboles como subárboles de la misma */ 
ArbolExpresion arbolExpresionCons(Termino r, ArbolExpresion i, ArbolExpresion d);

//Retorna el calculo de arbol expresion, en caso que aplique valor sustituye
//al parametro x
int arbolExpresionEvaluar(ArbolExpresion arbol, int valor, Boolean &errorCero);

//Boolean arbolExpresionExisteDivisionCero(ArbolExpresion arbol);
Boolean arbolExpresionIguales(ArbolExpresion arbol1, ArbolExpresion arbol2);

// Escribe en el archivo los datos de todos los enteros del árbol
// en forma recursiva. // Precondición: El archivo viene abierto para escritura.
void arbolExpresionBajarAux(ArbolExpresion a, FILE * f);

// Abre el archivo para escritura y escribe los datos de todos los
// enteros del árbol (llamando al procedimiento anterior)
void arbolExpresionBajar(ArbolExpresion a, String nomArch);

// Abre el archivo para lectura e inserta en el árbol todos los
// enteros están en el archivo (llamando al procedimiento Insert).
// Precondición: El archivo existe.
void arbolExpresionLevantar(ArbolExpresion &a, String nomArch);

#endif // ARBOLEXPRESION_H_INCLUDED