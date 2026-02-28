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
        
        // Obtener y mostrar indice
        printf("%d - ", expresionDevolverIndice(aux->info));

        // Obtener arbol y mostrar expresion
        ArbolExpresion arb = expresionDevolverArbolExpresion(aux->info);
        arbolExpresionDesplegarArbol(arb);
        
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


//void comandoRecuperar(ListaString listaStr);
