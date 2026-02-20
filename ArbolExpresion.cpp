#include "ArbolExpresion.h"


void arbolExpresionCrear(ArbolExpresion &arbol)
{
    arbol=NULL;
}

Boolean arbolExpresionEsVacio(ArbolExpresion arbol)
{
    Boolean resultado = FALSE;
    if (arbol == NULL)
        resultado = TRUE;

    return resultado;
}

//el arbol se carga en orden, necesita que se le pasen los terminos considerando el orden. 
//Resolver la logica de carga en funcion que llama a la carga de terminos, asignando el numero correspondiente.
void arbolExpresionInsertarTermino(ArbolExpresion &arbol, Termino termino)
{
    if (arbolExpresionEsVacio(arbol))
    {
        arbol = new nodoA;
        arbol->info = termino;
        arbol->hizq = NULL;
        arbol->hder = NULL;
    }
    else
    {
        if (arbolExpresionEsVacio(arbol->hizq))
        {
            arbolExpresionInsertarTermino(arbol->hizq, termino);
        }
        else
        {
            arbolExpresionInsertarTermino(arbol->hder, termino);
        }
    }
}

void arbolExpresionDesplegarArbol(ArbolExpresion arbol)
{
    if(arbol != NULL)
    {
        arbolExpresionDesplegarArbol(arbol->hizq);
        terminoDesplegarTermino(arbol->info);                     //agregar funcion en modulo Termino
        arbolExpresionDesplegarArbol(arbol->hder);
    }
}

void arbolExpresionDestruir(ArbolExpresion &arbol)
{
    if(arbol != NULL)
    {
        arbolExpresionDestruir(arbol->hizq);
        arbolExpresionDestruir(arbol->hder);
        delete arbol;
        arbol = NULL;
    }    
}

/* dados dos árboles y un valor, devolver un nuevo árbol   
colocando dicho valor como una nueva raíz y a los dos  
árboles como subárboles de la misma */ 
void arbolExpresionCons(Termino r, ArbolExpresion i, ArbolExpresion d, ArbolExpresion &arbol)
{
    arbol = new nodoA;
    arbol->info = r;
    arbol->hizq = i;
    arbol->hder = d;
}

int arbolExpresionEvaluar(ArbolExpresion arbol, int valor)
{

}

Boolean arbolExpresionExisteDivisionCero(ArbolExpresion arbol)
{

}

Boolean arbolExpresionIguales(ArbolExpresion arbol1, ArbolExpresion arbol2)
{

}

// Escribe en el archivo los datos de todos los enteros del árbol
// en forma recursiva. // Precondición: El archivo viene abierto para escritura.
void arbolExpresionBajarAux(ArbolExpresion a, FILE * f)
{

}

// Abre el archivo para escritura y escribe los datos de todos los
// enteros del árbol (llamando al procedimiento anterior)
void arbolExpresionBajar(ArbolExpresion a, String nomArch)
{

}

// Abre el archivo para lectura e inserta en el árbol todos los
// enteros están en el archivo (llamando al procedimiento Insert).
// Precondición: El archivo existe.
void arbolExpresionLevantar(ArbolExpresion &a, String nomArch)
{

}