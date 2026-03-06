#include <stdio.h>
#include "Comandos.h"

void testComandosMostrarCalcularModulo()
{
    //crear listaString

    ListaString lista;
    char entrada[] = "simple 45";
    char entrada2[] = "simple x";
    char entradaMostrar[] = "mostrar";
    char entradaComponer[] = "compuesta 1 + 2";
    listaStringCrear(lista);
    listaStringSplit(entrada, lista);

    //crear listaExpresion

    ListaExpresion lisExp;
    listaExpresionCrear(lisExp);


    //Testing Comando Simple
    //------------------------------------------------------------------------------------------------------------------------
    printf("\n-----------------------------Testing comando mostrar-----------------------------------\n\n");
    procesarEntrada(lista, entrada);
    comandoSimple(lista, lisExp);
    //arbolExpresionDesplegarArbol(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(lisExp,1)));

    //segunda entrada
    procesarEntrada(lista, entrada2);
    comandoSimple(lista, lisExp);
    procesarEntrada(lista, entradaMostrar);
    comandoMostrar(lista, lisExp);

    printf("\n-------------Fin test comando mostrar---------------\n");

    //Testing comando Compuesta
    //------------------------------------------------------------------------------------------------------------------------
    printf("\n-----------------------------Testing comando Calcular-----------------------------------\n\n");

    procesarEntrada(lista, entradaComponer);
    comandoCompuesta(lista, lisExp);




}

void procesarEntrada(ListaString &lista, String entrada)
{
    listaStringDestruir(lista);
    listaStringCrear(lista);
    listaStringSplit(entrada, lista);
}
