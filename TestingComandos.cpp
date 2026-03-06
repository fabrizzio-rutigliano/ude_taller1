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
    printf("Se cargo la listaString con... \n");
    listaStringDesplegar(lista);
    printf("\nSe cargo el valor 45 para el comando simple \n");
    printf("la conversion de 45 a int da... %d", strStringToInt(lista->sig->palabra));
    printf("\nes entero el str ingresado? %d\n", strEsEntero(lista->sig->palabra));
    comandoSimple(lista, lisExp);
    printf("\nSe cargo usando comando simple, la listaExpresion en posicion 1, con... \n");
    arbolExpresionDesplegarArbol(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,1)));
    printf("\n-------------Fin test comando simple---------------\n");

    //Testing comando Compuesta
    //------------------------------------------------------------------------------------------------------------------------
    printf("\n-----------------------------Testing comando Compuesto-----------------------------------\n\n");

    listaStringDestruir(lista);
    listaExpresionDestruir(lisExp);


}