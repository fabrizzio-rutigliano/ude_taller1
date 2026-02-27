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
    arbolExpresionInsertarTermino(ar2, ter3, 1);
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
    


    // =========================================================================
    // arbolExpresionIguales
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionIguales\n");
    printf("================================================================================\n"); 


    printf("\nEl arbol 1 es... ");
    arbolExpresionDesplegarArbol(arsalida);
    printf("\nEl arbol 2 es... ");
    arbolExpresionDesplegarArbol(arsalida);
    Boolean eq=FALSE;
    eq = arbolExpresionIguales(arsalida, arsalida);
    if(eq)
        printf("\nIguales\n");
    else    
        printf("\nNo son iguales\n");




    // =========================================================================
    // arbolExpresionBajar
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionBajar\n");
    printf("================================================================================\n");

    String narch;
    printf("\nIngrese el nombre de archivo... ");
    strCrear(narch);
    strScan(narch);
    arbolExpresionBajar(arsalida, narch);
    printf("\nSe gurdo... ");
    arbolExpresionDesplegarArbol(arsalida);

    // =========================================================================
    // arbolExpresionLevantar
    // =========================================================================

    printf("\n================================================================================\n");
    printf("TESTS DE arbolExpresionLevantar\n");
    printf("================================================================================\n");
    ar2=NULL;
    arbolExpresionLevantar(ar2, narch);
    printf("\nSe levanto... ");
    arbolExpresionDesplegarArbol(ar2);

    strDestruir(narch);
    



    arbolExpresionDestruir(ar);
    arbolExpresionDestruir(ar2);
    delete(arsalida);
    arsalida = NULL;
}