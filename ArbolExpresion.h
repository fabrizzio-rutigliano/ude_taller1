# include "Termino.h"

typedef struct NodoArb{
        Termino info;
        int numeroNodo; //facilita bajar a disco : ABB
        NodoArb * hizq;
        NodoArb * hder;
        }nodoA;
        
typedef nodoA * ArbolExpresion;

void arbolExpresionCrear(ArbolExpresion &arbol);

void arbolExpresionInsertarTermino(ArbolExpresion &arbol, Termino termino);

void arbolExpresionDesplegarArbol(ArbolExpresion arbol);

void arbolExpresionDestruir(ArbolExpresion &arbol);

/* dados dos árboles y un valor, devolver un nuevo árbol   
colocando dicho valor como una nueva raíz y a los dos  
árboles como subárboles de la misma */ 
void arbolExpresionCons(Termino r, ArbolExpresion i, ArbolExpresion d);
//TODO VER DE DEVOLVER UN ARBOL

int arbolExpresionEvaluar(ArbolExpresion arbol, int valor);

Boolean arbolExpresionExisteDivisionCero(ArbolExpresion arbol);

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
