#include "ArbolExpresion.h"

void testingModuloArbolExpresion ()
{
    printf("\n================================================================================\n");
    printf("INICIO DE TESTS DEL MODULO ArbolExpresion\n");
    printf("================================================================================\n");      
    // =========================================================================
    // ArbolExpresionCrear
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE crearArbolExpresion\n");
    printf("================================================================================\n"); 
    ArbolExpresion ar;
    arbolExpresionCrear(ar);
    if (ar==NULL)
        printf("\nel contenido del nuevo Arbol es... NULL\n");
    else
        printf("\nalgo mal\n");




    // =========================================================================
    // arbolExpresionEsVacio
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionEsVacio\n");
    printf("================================================================================\n"); 
    ar = new nodoA;
    Boolean result = arbolExpresionEsVacio(ar);
    if(result == TRUE)
        printf("\nEl arbol es vacio\n");
    else
        printf("\nEl arbol no es vacio\n");
    delete(ar);
    ar = NULL;

    // =========================================================================
    // arbolExpresionInsertarTermino
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionInsertarTermino\n");
    printf("================================================================================\n"); 
    Termino ter;
    ter.discriminante = VALOR;
    ter.dato.valor = 23;
    arbolExpresionInsertarTermino(ar, ter);


    // =========================================================================
    // arbolExpresionDesplegarArbol
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionDesplegarArbol\n");
    printf("================================================================================\n"); 
    arbolExpresionDesplegarArbol(ar);



    // =========================================================================
    // arbolExpresionDestruir
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionDestruir\n");
    printf("================================================================================\n"); 
    arbolExpresionDestruir(ar);
    result = arbolExpresionEsVacio(ar);
    if(result == TRUE)
        printf("\nEl arbol es vacio\n");
    else
        printf("\nEl arbol no es vacio\n");


}