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
    arbolExpresionInsertarTermino(ar, ter, 1);


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


    // =========================================================================
    // arbolExpresionCons
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionCons\n");
    printf("================================================================================\n"); 
    Termino ter4;
    ter4.discriminante = VALOR;
    printf("\n");
    tipoTerminoDesplegar(ter4.discriminante);
    printf("\n");
    ter4.dato.valor = 23;
    
    arbolExpresionInsertarTermino(ar,ter4, 1);
    printf("\n");
    tipoTerminoDesplegar(ar->info.discriminante);
    printf("\n");
    ArbolExpresion ar2;
    ar2 = NULL;
    Termino ter3;
    ter3.discriminante = VARIABLE;
    ter3.dato.valor = 'x';
    arbolExpresionInsertarTermino(ar2, ter3, 2);
    Termino ter2;
    ter2.discriminante = OPERADOR;
    ter2.dato.operador = '+';
    ArbolExpresion arsalida;
    arsalida = NULL;
    arsalida = arbolExpresionCons(ter2,ar,ar2);
    arbolExpresionDesplegarArbol(arsalida);
    //arbolExpresionDestruir(ar);
    //arbolExpresionDestruir(ar2);
    

    // =========================================================================
    // arbolExpresionEvaluar
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionEvaluar\n");
    printf("================================================================================\n"); 

    Boolean error = FALSE;
    int resultado;
    resultado = arbolExpresionEvaluar(arsalida, 7, error);
    printf("\nLa evaluacion resulta en... %d\n",resultado);
    delete(arsalida);
    arsalida = NULL;
    arbolExpresionDestruir(ar);
    arbolExpresionDestruir(ar2);
}