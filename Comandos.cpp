#include "Comandos.h"

void comandoSimple(ListaString listaStr, ListaExpresion &listaExp){

    
    String parametro;
    strCrear(parametro);
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
            term = terminoCrearValor(tipoTerm, valor);
        }else{
            if(strEsVariable(parametro)){
                tipoTerm = VARIABLE;
                variableX = strStrToChar(parametro);
                term = terminoCrearVariable(tipoTerm, variableX);
            }else{
                parametroValido = FALSE;
            }
        }
        
        if(!parametroValido){
            tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_VARIABLE_INVALIDA);
        }else{
            arbolExpresionCrear(arbExp);
            arbolExpresionInsertarTermino(arbExp, term, 1);
            indice = listaExpresionIndiceSiguiente(listaExp);
            exp = expresionCrear(arbExp, indice);
            listaExpresionInsertarFinal(listaExp, exp);

            expresionMostrar(exp);
            arbolExpresionDestruir(arbExp);
        }
    }
    
    strDestruir(parametro);
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
    ArbolExpresion abbIzq, abbIzqCopia, abbDer, abbDerCopia, abbCons;

    largoLista = listaStringCantElementos(listaStr);
    if(largoLista != 4) {
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
    }else{
        strCrear(param1);
        strCrear(param2);
        strCrear(param3);

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
                    arbolExpresionCopiar(abbIzqCopia, abbIzq);

                    abbDer = expresionDevolverArbolExpresion(expDer);
                    arbolExpresionCopiar(abbDerCopia, abbDer);

                    op = strStrToChar(param2);
                    tipoTerm = OPERADOR;
                    term = terminoCrearOperador(tipoTerm, op);
                    abbCons = arbolExpresionCons(term, abbIzqCopia, abbDerCopia);

                    indice = listaExpresionIndiceSiguiente(listaExp);
                    expCons = expresionCrear(abbCons, indice);
                    listaExpresionInsertarFinal(listaExp, expCons);

                    expresionMostrar(expCons);
                }
            }
        }
        strDestruir(param1);
        strDestruir(param2);
        strDestruir(param3);
    }
}

//Sintaxis del compando verificada antes de llamar a la funcion en MAIN
void comandoCalcular(ListaString lstring, ListaExpresion listaExp)
{
    if (listaStringCantElementos(lstring) == 3)
    {
        String str,str2;
        strCrear(str);
        strCrear(str2);
        listaStringObtener(1, lstring, str);
        if(strEsEnteroPositivo(str))
        {
            int posLista = strStringToInt(str);
            listaStringObtener(2, lstring, str2);
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
        listaStringObtener(1, lstring, str);
        listaStringObtener(2, lstring, str2);
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

void comandoGuardar(ListaString lstring, ListaExpresion listaExp){
    // 1) Chequear la cantidad de elementos
    if (listaStringCantElementos(lstring) != 3)
    {
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
    }
    else
    {
        String strIndice, strNombre, nomArch;
        strCrear(strIndice);
        strCrear(strNombre);
        strCrear(nomArch);

        // guardar indice y nombre de archivo
        listaStringObtener(1, lstring, strIndice);
        listaStringObtener(2, lstring, strNombre);
    // 2) Chequear que el indice sea entero positivo
        if (!strEsEnteroPositivo(strIndice))
        {
            tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_POSITIVO);
        }
        else
        {
            int indice = strStringToInt(strIndice);
    // 3) Chequear que el indice sea válido
            if (!listaExpresionExisteIndice(listaExp, indice))
            {
                tipoErrorDesplegar(ERROR_INDICE_INEXISTENTE);
            }
    // 4) Que el nombre del archivo sea alfabetico
            else if (!strEsAlfabetico(strNombre))
            {
                tipoErrorDesplegar(ERROR_ARCHIVO_NOMBRE_INVALIDO);
            }
            else
            {
                // construir terminacion .txt
                char buffer[MAX];
                int i = 0;

                while (strNombre[i] != '\0')
                {
                    buffer[i] = strNombre[i];
                    i++;
                }

                buffer[i++] = '.';
                buffer[i++] = 't';
                buffer[i++] = 'x';
                buffer[i++] = 't';
                buffer[i] = '\0';

                strCop(nomArch, buffer);

                if (existeArchivo(nomArch))
                {
                    tipoErrorDesplegar(ERROR_ARCHIVO_YA_EXISTE);
                }
                else
                {
                    arbolExpresionBajar(expresionDevolverArbolExpresion(listaExpresionDevolverExpresionXIndice(listaExp, indice)), nomArch);

                    printf("\nExpresion %d guardada correctamente en ", indice);
                    strPrint(nomArch);
                    printf("\n");
                }
            }
        }
        strDestruir(strIndice);
        strDestruir(strNombre);
        strDestruir(nomArch);
    }
}


//Comando desplegar la lista de expresiones con su indice, y la expresion por pantalla. 
// Precondicion evaluado en el main, el primer string debe ser Mostrar.
void comandoMostrar(ListaString listaStr, ListaExpresion listaExp){
    
    // 1) validar cantidad de parámetros
    if (listaStringCantElementos(listaStr) != 1) {
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
    }

    // 2) validar lista no vacía
    else if (listaExpresionEsVacia(listaExp)) {
        tipoErrorDesplegar(ERROR_LISTA_VACIA);
    }

    // 3) recorrer lista
    else {
    
    ListaExpresion aux = listaExp;
    while (aux != NULL) {
        
        expresionMostrar(aux->info);
        aux = aux->sig;
    }

    printf("\n");
    }
}

// Comando salir, se encarga de liberar la memoria dinámica y cerrar el programa.
// Precondicion evaluado en el main, el primer string debe ser Salir.
// Precondicion, el boolean salir debe venir en FALSE.
void comandoSalir(ListaString &listaStr, ListaExpresion &listaExp, Boolean &salir){
    
    // Validar cantidad de parámetros
    if (listaStringCantElementos(listaStr) != 1) {
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
        ;   // no salir, hubo error
    }
    else{
        // Liberar memoria
        listaExpresionDestruir(listaExp);
        
        printf("\nCerrando programa...\n");

        salir = TRUE;
    }
}

//Comando recuperar, recupera una expresión de un archivo existente y la inserta en la lista de expresiones
//Precondicion evaluado en el main, el primer string debe ser recuperar.
void comandoRecuperar(ListaString listaStr, ListaExpresion &listaExp)
{
    // 1) validar cantidad de parámetros
    if (listaStringCantElementos(listaStr) != 2) {
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
    }
    else {

        // 2) obtener nombre de archivo
        String strNombre, nomArch;
        strCrear(strNombre);
        strCrear(nomArch);

        // recuperar archivo
        listaStringObtener(1, listaStr, strNombre);

        // 3) validar nombre alfabético
        if (!strEsAlfabetico(strNombre)) {
            tipoErrorDesplegar(ERROR_ARCHIVO_NOMBRE_INVALIDO);
        }
        else {
            char buffer[MAX];
            int i = 0;

            while (strNombre[i] != '\0')
            {
                buffer[i] = strNombre[i];
                i++;
            }

            buffer[i++] = '.';
            buffer[i++] = 't';
            buffer[i++] = 'x';
            buffer[i++] = 't';
            buffer[i] = '\0';

            strCop(nomArch, buffer);
            // 4) validar que exista el archivo
            if (!existeArchivo(nomArch))
            {
                tipoErrorDesplegar(ERROR_ARCHIVO_NO_ENCONTRADO);
            }
            else{

                // 5) levantar árbol desde archivo
                ArbolExpresion arbol;
                arbolExpresionCrear(arbol);
                arbolExpresionLevantar(arbol, nomArch);

                // 6) crear Expresion con siguiente índice e insertar al final
                int nuevoIndice = listaExpresionIndiceSiguiente(listaExp);
                Expresion exp = expresionCrear(arbol, nuevoIndice);

                listaExpresionInsertarFinal(listaExp, exp);

                // 7) mostrar expresión
                printf("\nSe recupero correctamente la expresion:\n");
                expresionMostrar(exp);
                printf("\n");

                expresionLiberarArbolDeExpresion(exp);
            }
        }

        strDestruir(nomArch);
        strDestruir(strNombre);
    }
}
