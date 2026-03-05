#include <stdio.h>
#include "Comandos.h"

void testComandosModulo()
{
    //crear listaString

    ListaString lista;
    char entrada[] = "simple 45";
    listaStringCrear(lista);
    listaStringSplit(entrada, lista);

    //crear listaExpresion

    ListaExpresion lisExp;
    listaExpresionCrear(lisExp);


    //Testing Comando Simple
    //------------------------------------------------------------------------------------------------------------------------
    printf("\n-----------------------------Testing comando simple-----------------------------------\n\n");
    printf("Se cargo la listaString con... ");
    listaStringDesplegar(lista);
    printf("\nSe cargo el valor 45 para el comando simple \n");
    comandoSimple(lista, lisExp);
    printf("Se cargo usando comando simple, la listaExpresion en posicion 1, con... ");
    arbolExpresionDesplegarArbol(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,1)));
    printf("\n-------------Fin test comando simple---------------\n");


    //Testing comando Compuesta
    //------------------------------------------------------------------------------------------------------------------------


    listaStringDestruir(lista);
    listaExpresionDestruir(lisExp);


}