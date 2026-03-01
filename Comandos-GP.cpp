#include "Comandos.h"

//Sintaxis del compando verificada antes de llamar a la funcion en MAIN
void comandoCalcular(ListaString lstring, ListaExpresion listaExp)
{
    if (listaStringCantElementos(lstring) == 3)
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
                    tipoErrorDesplegar(ERROR_DIVISION_POR_CERO);
                }
                else
                    printf("\nEl resultado de calcular la expresion es... %d\n", resultado);
            }
            else
                    tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO);
        }
        else
            tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_POSITIVO);
        strDestruir(str);
        strDestruir(str2);

    }
    else    
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
}


void comandoIguales(ListaString lstring, ListaExpresion listaExp)
{
    if (listaStringCantElementos(lstring) == 3)
    {
        String str,str2;
        strCrear(str);
        strCrear(str2);
        listaStringObtener(2, lstring, str);
        listaStringObtener(3, lstring, str2);
        if(strEsEnteroPositivo(str) && strEsEnteroPositivo(str2))
        {
            Boolean iguales = FALSE;
            int pos1 = strStringToInt(str);
            int pos2 = strStringToInt(str2);
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
        else
            tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_POSITIVO);
        strDestruir(str);
        strDestruir(str2);
    }
    else
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
}



void comandoGuardar(ListaString lstring, ListaExpresion listaExp)
{
    if(listaStringCantElementos(lstring) == 3)
    {
        String str,str2;
        strCrear(str);
        strCrear(str2);
        listaStringObtener(2, lstring, str);
        if(strEsEnteroPositivo(str))
        {
            if(existeArchivo(str2))
                tipoErrorDesplegar(ERROR_ARCHIVO_YA_EXISTE);
            else
                arbolExpresionBajar(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(listaExp, strStringToInt(str))), str2);
        }
        else
            tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_POSITIVO);

        strDestruir(str);
        strDestruir(str2);
    }
    else
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
}