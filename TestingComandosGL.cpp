#include <stdio.h>
#include "Comandos.h"

void testComandosMostrarCalcularModulo()
{
    //crear listaString

    ListaString lista;
    char entrada[] = "simple 45";
    char entrada2[] = "simple x";
    char entrada3[] = "simple 2000";
    char entradaMostrar[] = "mostrar";
    char entradaComponer[] = "compuesta 1 + 2";
    char entradaComponer2[] = "compuesta 1 + 4";
    char entradaCalcular[] = "calcular 3 10";
    char entradaCalcular2[] = "calcular 5 1";
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

    procesarEntrada(lista, entradaCalcular);
    comandoCalcular(lista, lisExp);

    procesarEntrada(lista, entrada3);
    comandoSimple(lista, lisExp);

    procesarEntrada(lista, entradaComponer2);
    comandoCompuesta(lista, lisExp);

    procesarEntrada(lista, entradaCalcular2);
    comandoCalcular(lista, lisExp);

    procesarEntrada(lista, entradaMostrar);
    comandoMostrar(lista, lisExp);

    printf("\n-------------Fin test comando calcular---------------\n");

}

void procesarEntrada(ListaString &lista, String entrada)
{
    listaStringDestruir(lista);
    listaStringCrear(lista);
    listaStringSplit(entrada, lista);
}
