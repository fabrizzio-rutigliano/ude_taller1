#include "Comandos.h"
//GP
//Sintaxis del compando verificada antes de llamar a la funcion en MAIN
void comandoCalcular(ListaExpresion listaExp, int posLista, int valor)
{
    if (posLista >= 1)
    {
        Boolean error = FALSE;
        int resultado; 
        resultado = arbolExpresionEvaluar(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(listaExp, posLista)), valor, error);
        if(error == TRUE)
            //mensaje error division 0
    }
}

//GP
/*void comandoIguales(ListaString listaStr)
{

}*/

//GP
/*
void comandoGuardar(ListaString listaStr)
{

}*/