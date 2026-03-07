#include <stdio.h>
#include "Comandos.h"

void testComandosModulo()
{
    //crear listaString

    ListaString lista;
    char entrada[] = "simple 45";
    char entrada2[] = "simple x";
    char entrada3[] = "simple 300";
    char entrada4[] = "compuesta 1 + 3";
    char entrada5[] = "compuesta 4 + 2";
    listaStringCrear(lista);
    listaStringSplit(entrada, lista);
    ArbolExpresion arbolete;
    arbolExpresionCrear(arbolete);
    

    //crear listaExpresion

    ListaExpresion lisExp;
    listaExpresionCrear(lisExp);


    //Testing Comando Simple
    //------------------------------------------------------------------------------------------------------------------------
    printf("\n-----------------------------Testing comando simple-----------------------------------\n\n");
    printf("Se cargo la listaString con... \n");
    listaStringDesplegar(lista);
    printf("\nSe cargo el valor 45 para el comando simple \n");
    printf("la conversion de 45 a int da... %d", strStringToInt(lista->sig->palabra));
    printf("\nes entero el str ingresado? %d\n", strEsEntero(lista->sig->palabra));
    comandoSimple(lista, lisExp);
    printf("\nSe cargo usando comando simple, la listaExpresion en posicion 1, con... \n");
    arbolExpresionDesplegarArbol(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,1)));
    listaStringDestruir(lista);
    printf("\n-------------Fin test comando simple---------------\n");

    //Testing comando Compuesta
    //------------------------------------------------------------------------------------------------------------------------
    printf("\n-----------------------------Testing comando Compuesto-----------------------------------\n\n");

    listaStringCrear(lista);
    listaStringSplit(entrada2, lista);
    comandoSimple(lista, lisExp);
    listaStringDestruir(lista);
    listaStringCrear(lista);
    listaStringSplit(entrada3, lista);
    comandoSimple(lista, lisExp);
    listaStringDestruir(lista);
    listaStringCrear(lista);
    listaStringSplit(entrada4, lista);
    arbolete = expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,1));
    arbolExpresionDesplegarArbol(arbolete);
    printf("\n");
    arbolete = NULL;
    arbolete = expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,3));
    arbolExpresionDesplegarArbol(arbolete);
    printf("\n");
    arbolete = NULL;
    printf("\nel comando a ejecutar es... \n");
    listaStringDesplegar(lista);
    printf("\n");
    comandoCompuesta(lista, lisExp);
    arbolete = expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,4));
    arbolExpresionDesplegarArbol(arbolete);
    printf("\n");

    listaStringDestruir(lista);
    listaStringCrear(lista);
    listaStringSplit(entrada5, lista);
    printf("\nel comando a ejecutar es... \n");
    listaStringDesplegar(lista);
    printf("\n");
    comandoCompuesta(lista, lisExp);
    arbolete = expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,5));
    arbolExpresionDesplegarArbol(arbolete);
    printf("\n");


    listaStringDestruir(lista);
    listaExpresionDestruir(lisExp);

}