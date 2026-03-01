#include "Comandos.h"

//Sintaxis del compando verificada antes de llamar a la funcion en MAIN
void comandoCalcular(ListaString lstring, listaExp)
{
    if (listaStringCantElementos(listaStr) != 2)
    if (posLista >= 1)
    {
        Boolean error = FALSE;
        int resultado; 
        resultado = arbolExpresionEvaluar(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(listaExp, posLista)), valor, error);
        if(error == TRUE)
        {
            //mensaje error division 0
            //tipoErrorDesplegar(ERROR_DIVISION_POR_CERO);
        }
        else
            printf("\nEl resultado de calcular la expresion es... %d\n", resultado);
    }
}


void comandoIguales(ListaExpresion listaExp, int pos1, int pos2)
{
    Boolean iguales = FALSE;
    iguales = arbolExpresionIguales(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(listaExp, pos1)),expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(listaExp, pos2)));
    if(iguales)
    {
        printf("\nLas expresiones son iguales\n");
    }
    else
    {
        printf("\nLas expresiones no son iguales\n");
    }
}



void comandoGuardar(ListaString listaStr)
{

}