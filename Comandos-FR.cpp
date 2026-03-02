# include "ListaString.h"
# include "ListaExpresion.h"
# include "Archivos.h"
# include "TipoError.h"

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
        printf("\n");

        aux = aux->sig;
    }

    printf("\n");
    }
}

//Comando salir, es un flag que se le pasa al main que se encarga de liberar la memoria dinámica. 
// Precondicion evaluado en el main, el primer string debe ser Salir.
Boolean comandoSalir(ListaString listaStr){
    
    Boolean salir = FALSE;
    
    // Validar cantidad de parámetros
    if (listaStringCantElementos(listaStr) != 1) {
        tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);
        ;   // no salir, hubo error
    }
    else{
        salir = TRUE;
    }
    
    return salir;        // salir TRUE que recibe el main para liberar la memoria

    // Limpieza final que realiza el main
    //strDestruir(entrada);
    //listaExpresionDestruir(listaExp);
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
        String nomArch;
        strCrear(nomArch);
        listaStringObtener(2, listaStr, nomArch);

        // 3) validar nombre alfabético
        if (!strEsAlfabetico(nomArch)) {
            tipoErrorDesplegar(ERROR_ARCHIVO_NOMBRE_INVALIDO);
        }
        else {

            // 4) validar que exista el archivo
            if (!existeArchivo(nomArch)) {
                tipoErrorDesplegar(ERROR_ARCHIVO_NO_ENCONTRADO);
            }
            else {

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
            }
        }

        strDestruir(nomArch);
    }
}
