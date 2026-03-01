# include "ListaString.h"
# include "ListaExpresion.h"
# include "Archivos.h"
# include "TipoError.h"

void comandoSimple(ListaString listaStr, ListaExpresion &listaExp){

    String parametro;
    char variableX;
    TipoTermino tipoTerm;
    Termino term;
    ArbolExpresion arbExp;
    Expresion exp;
    Boolean parametroValido = TRUE;
    int valor = 0;
    int largoLista = 0;
    int indice = 0;

    largoLista = listaStringCantElementos(listaStr);
    if(largoLista != 2){
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
    }else{
        listaStringObtener(1, listaStr, parametro);

        if(strEsEntero(parametro)){
            tipoTerm = VALOR;
            valor = strStringToInt(parametro);
        }else{
            if(strEsVariable(parametro)){
                tipoTerm = VARIABLE;
                variableX = strStrToChar(parametro);
            }else{
                parametroValido = FALSE;
            }
        }

        if(parametroValido){
            tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_VARIABLE_INVALIDA);
        }else{
            term = terminoCrear(tipoTerm, valor, variableX);
            arbolExpresionCrear(arbExp);
            arbolExpresionInsertarTermino(arbExp, term, 1);
            indice = listaExpresionIndiceSiguiente(listaExp);
            exp = expresionCrear(arbExp, indice);
            listaExpresionInsertarFinal(listaExp, exp);

            expresionMostrar(exp);
        }
    }
}

void comandoCompuesta(ListaString listaStr, ListaExpresion &listaExp){

    int largoLista = 0;
    int paramInd1, paramInd2, indice;
    String param1, param2, param3;
    char op;
    Boolean existeIndice1, existeIndice2;
    TipoTermino tipoTerm;
    Termino term;
    Expresion expIzq, expDer, expCons;
    ArbolExpresion abbIzq, abbDer, abbCons;

    largoLista = listaStringCantElementos(listaStr);
    if(largoLista != 4) {
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
    }else{
        listaStringObtener(1, listaStr, param1);
        listaStringObtener(2, listaStr, param2);
        listaStringObtener(3, listaStr, param3);

        if(!strEsEnteroPositivo(param1) && !strEsEnteroPositivo(param3)){
            tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_POSITIVO);
        }else{
            if(!strEsOperador(param2)){
                tipoErrorDesplegar(ERROR_PARAMETRO_NO_OPERADOR);
            }else{
                paramInd1 = strStringToInt(param1);
                paramInd2 = strStringToInt(param3);
                existeIndice1 = listaExpresionExisteIndice(listaExp, paramInd1);
                existeIndice2 = listaExpresionExisteIndice(listaExp, paramInd2);
                if(!existeIndice1 || !existeIndice2){
                    tipoErrorDesplegar(ERROR_INDICE_INEXISTENTE);
                }else{
                    expIzq = listaExpresionDevolverExpresionXIndice(listaExp, paramInd1);
                    expDer = listaExpresionDevolverExpresionXIndice(listaExp, paramInd2);
                    abbIzq = expresionDevolverArbolExpresion(expIzq);
                    abbDer = expresionDevolverArbolExpresion(expDer);

                    op = strStrToChar(param2);
                    tipoTerm = OPERADOR;
                    term = terminoCrear(tipoTerm, 0, op);
                    abbCons = arbolExpresionCons(term, abbIzq, abbDer);

                    indice = listaExpresionIndiceSiguiente(listaExp);
                    expCons = expresionCrear(abbCons, indice);
                    listaExpresionInsertarFinal(listaExp, expCons);

                    expresionMostrar(expCons);
                }
            }
        }
    }
}