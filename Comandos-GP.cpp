#include "Comandos.h"

//Sintaxis del compando verificada antes de llamar a la funcion en MAIN
void comandoCalcular(ListaString lstring, ListaExpresion listaExp)
{
    if (listaStringCantElementos(lstring) != 3)
    {
        String str,str2;
        strCrear(str);
        strCrear(str2);
        listaStringObtener(2, lstring, str);
        if(strEsEnteroPositivo(str))
        {
            int posLista = strStringToInt(str);
            listaStringObtener(3, lstring, str2);
            if(strEsEntero(str2))
            {
                int valor = strStringToInt(str2);
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
            else
                //mensaje de error no es entero 
        }
        else
            //mensaje de error no es entero positivo
        strDestruir(str);
        strDestruir(str2);

    }
    else    
        //error cantidad de parametros
    strDestruir(str);
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