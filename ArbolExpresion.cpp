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

int darNumeroNodo(ArbolExpresion arbol)
{
    return arbol->numeroNodo;
}

//el arbol se carga en orden, necesita que se le pasen los terminos considerando el orden. 
//Resolver la logica de carga en funcion que llama a la carga de terminos, asignando el numero correspondiente.
void arbolExpresionInsertarTermino(ArbolExpresion &arbol, Termino termino, int posicion)
{
    if (arbolExpresionEsVacio(arbol))
    {
        arbol = new nodoA();
        arbol->info = termino;
        arbol->numeroNodo = posicion;
        arbol->hizq = NULL;
        arbol->hder = NULL;
    }
    else
    {
        if (posicion < arbol->numeroNodo)
        {
            arbolExpresionInsertarTermino(arbol->hizq, termino, posicion);
        }
        else
        {
            arbolExpresionInsertarTermino(arbol->hder, termino, posicion);
        }
    }
}


void arbolExpresionDesplegarArbol(ArbolExpresion arbol)
{
    if(arbol != NULL)
    {
        arbolExpresionDesplegarArbol(arbol->hizq);
        terminoDesplegarTermino(arbol->info);
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

void arbolExpresionCopiar(ArbolExpresion &ar1, ArbolExpresion ar2)
{
    delete[] ar1;
    ar1 = new nodoA;
    ar1->info = ar2 ->info;
    ar1->numeroNodo = darNumeroNodo(ar2);
    ar1->hizq = ar2->hizq;
    ar1->hder = ar2->hder;
}

int arbolExpresionDarMayor(ArbolExpresion arbol)
{
    int result;
    while(arbol->hder != NULL)
    {
        arbol = arbol->hder;
    }
    result = arbol->numeroNodo;
    return result;
}

void arbolExpresionAjustarIndices(ArbolExpresion &d, int posicion)
{
    if(d!=NULL)
    {
        arbolExpresionAjustarIndices(d->hizq, posicion);
        arbolExpresionAjustarIndices(d->hder, posicion);
        d->numeroNodo = d->numeroNodo + posicion;
    }
}

//parametro indice debe recibir 0 al ser llamada la funcion.
void arbolExpresionIndizar(ArbolExpresion &a, int &indice)
{
    if(a!=NULL)
    {
        arbolExpresionIndizar(a->hizq, indice);
        a->numeroNodo = indice++;
        arbolExpresionIndizar(a->hder, indice); 
    }
}

void arbolExpresionParentizar(ArbolExpresion &arbol, Boolean izq)
{
    if(izq)
    {
        arbolExpresionAjustarIndices(arbol, darNumeroNodo(arbol));
        Termino ter;
        ter.discriminante = PARENTESIS;
        ter.dato.parentesis = '(';
        arbolExpresionInsertarTermino(arbol, ter, 1);
    }
    else
    {
        int mayor = arbolExpresionDarMayor(arbol);
        Termino ter;
        ter.discriminante = PARENTESIS;
        ter.dato.parentesis = ')';
        arbolExpresionInsertarTermino(arbol, ter, mayor + 1);
    }
}

/* dados dos árboles y un valor, devolver un nuevo árbol   
colocando dicho valor como una nueva raíz y a los dos  
árboles como subárboles de la misma */ 
//modificada para devolver arbolExpresion, era void
ArbolExpresion arbolExpresionCons(Termino r, ArbolExpresion i, ArbolExpresion d)
{
    int posicion;
    arbolExpresionParentizar(i,TRUE);
    posicion = arbolExpresionDarMayor(i) + 1;
    ArbolExpresion arbol = new nodoA;
    
    arbol->info = r;
    arbol->numeroNodo = posicion;
    arbol->hizq = i;
    arbolExpresionParentizar(d,FALSE);
    arbolExpresionAjustarIndices(d, posicion);
    arbol->hder = d;
    return arbol;
}

int arbolExpresionEvaluar(ArbolExpresion arbol, int val, Boolean &errorCero)
{
    if (arbol == NULL)
    {
        return 0;
    }
    else
    {
        //printf("\ndiscriminante = %d\n", arbol->info.discriminante);
        switch (arbol->info.discriminante)
        {
            case VALOR:
                {
                //printf("valor izq es... %d",arbol->info.dato.valor);
                return arbol->info.dato.valor;
                break;
                }
            case VARIABLE:
                {
                //printf("%c",arbol->info.dato.variable);
                return val;
                break;
                }
            case OPERADOR:
                {
                int resultIzq = arbolExpresionEvaluar(arbol->hizq, val, errorCero);
                int resultDer = arbolExpresionEvaluar(arbol->hder, val, errorCero);
                //printf("\nresultIzq... %d\n",resultIzq);
                //printf("\nresultDer... %d\n",resultDer);
                switch (arbol->info.dato.operador)
                {
                    case '+':
                        return resultIzq + resultDer;
                        break;
                    case '-':
                        return resultIzq - resultDer;
                        break;
                    case '*':
                        return resultIzq * resultDer;
                        break;
                    case '/':
                        if(resultDer == 0)
                        {
                            errorCero = TRUE;
                            return 0;
                        }
                        else
                            return resultIzq / resultDer;
                        break;
                    default:
                        break;
                }
                }
            case PARENTESIS:
                {
                break;
                }
        }
    }
    return 0;
}

/*Boolean arbolExpresionExisteDivisionCero(ArbolExpresion arbol)
{

}*/

Boolean arbolExpresionIguales(ArbolExpresion arbol1, ArbolExpresion arbol2)
{
    if(arbol1==NULL && arbol2==NULL)
        return TRUE;
    if(arbol1==NULL && arbol2==NULL)
        return FALSE;
    if(arbol1->info.discriminante != arbol2->info.discriminante)
        return FALSE;
    if(arbol1->info.discriminante == arbol2->info.discriminante)
    {
        switch (arbol1->info.discriminante)
        {
            case VALOR:
                if(arbol1->info.dato.valor == arbol2->info.dato.valor)
                    return TRUE;
                else
                    return FALSE;
                break;
            case VARIABLE:
                if(arbol1->info.dato.variable == arbol2->info.dato.variable)
                    return TRUE;
                else 
                    return FALSE;
                break;
            case OPERADOR:
                if(arbol1->info.dato.operador == arbol2->info.dato.operador)
                    return TRUE;
                else 
                    return FALSE;
                break;
            case PARENTESIS:
                if(arbol1->info.dato.parentesis == arbol2->info.dato.parentesis)
                    return TRUE;
                else 
                    return FALSE;
                break;
            default:
                break;
        }

    }
    
    if (arbolExpresionIguales(arbol1->hizq, arbol2->hizq) == arbolExpresionIguales(arbol1->hder, arbol2->hder) == TRUE)
        return TRUE;
    else 
        return FALSE;
}

// Escribe en el archivo los datos de todos los enteros del árbol
// en forma recursiva. // Precondición: El archivo viene abierto para escritura.
void arbolExpresionBajarAux(ArbolExpresion a, FILE * f)
{
    if (a != NULL)
    {
        int indice;
        terminoBajar(a->info, f);
        indice = darNumeroNodo(a);
        fwrite (&indice, sizeof(int), 1, f);
        arbolExpresionBajarAux(a->hizq, f);
        arbolExpresionBajarAux(a->hder, f);
    }
}

// Abre el archivo para escritura y escribe los datos de todos los
// enteros del árbol (llamando al procedimiento anterior)
void arbolExpresionBajar(ArbolExpresion a, String nomArch)
{
    FILE *f = fopen(nomArch, "wb");
    arbolExpresionBajarAux(a, f);
    fclose(f);
}

// Abre el archivo para lectura e inserta en el árbol todos los
// enteros están en el archivo (llamando al procedimiento Insert).
// Precondición: El archivo existe.
void arbolExpresionLevantar(ArbolExpresion &a, String nomArch)
{
    int indice;
    FILE *f = fopen(nomArch, "rb");
    Termino terBuffer;
    arbolExpresionCrear(a);
    terminoLevantar(terBuffer, f);
    fread(&indice,sizeof(int),1,f);
    arbolExpresionInsertarTermino(a, terBuffer, indice);
    while (!feof(f))
    {
        //arbolExpresionInsertarTermino(a, terBuffer);
        terminoLevantar(terBuffer, f);
        fread(&indice,sizeof(int),1,f);
        arbolExpresionInsertarTermino(a, terBuffer, indice);
    }
    fclose(f);
    //arbolExpresionIndizar(a, indice);
}