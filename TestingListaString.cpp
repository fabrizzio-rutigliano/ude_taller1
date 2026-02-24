#include <stdio.h>
#include "ListaString.h"

void testListaStringModulo() {

    printf("\n================================================================================\n");
    printf("INICIO DE TESTS DEL MODULO ListaString\n");
    printf("================================================================================\n");

    // =========================================================================
    // listaStringSplit
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: listaStringSplit(String entrada, ListaString &lista)\n");
    printf("Caso entrada sin espacios extra\n");
    {
        ListaString lista;
        char entrada[] = "hola mundo";

        listaStringCrear(lista);
        listaStringSplit(entrada, lista);

        int largo = listaStringCantElementos(lista);
        printf("Largo de la lista es %d\n", largo);
        listaStringDesplegar(lista);
    }

    // =========================================================================
    // listaStringSplit
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: listaStringSplit(String entrada, ListaString &lista)\n");
    printf("Caso entrada con espacios al inicio\n");
    {
        ListaString lista;
        char entrada[] = "   hola mundo";

        listaStringCrear(lista);
        listaStringSplit(entrada, lista);

        int largo = listaStringCantElementos(lista);
        printf("Largo de la lista es %d\n", largo);
        listaStringDesplegar(lista);
    }

    // =========================================================================
    // listaStringSplit
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: listaStringSplit(String entrada, ListaString &lista)\n");
    printf("Caso entrada con espacios entremedio\n");
    {
        ListaString lista;
        char entrada[] = "   hola     mundo";

        listaStringCrear(lista);
        listaStringSplit(entrada, lista);

        int largo = listaStringCantElementos(lista);
        printf("Largo de la lista es %d\n", largo);
        listaStringDesplegar(lista);
    }

    // =========================================================================
    // listaStringSplit
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: listaStringSplit(String entrada, ListaString &lista)\n");
    printf("Caso entrada con espacios al final\n");
    {
        ListaString lista;
        char entrada[] = "   hola     mundo    ";

        listaStringCrear(lista);
        listaStringSplit(entrada, lista);

        int largo = listaStringCantElementos(lista);
        printf("Largo de la lista es %d\n", largo);
        listaStringDesplegar(lista);
    }

    // =========================================================================
    // listaStringSplit
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: listaStringSplit(String entrada, ListaString &lista)\n");
    printf("Caso entrada con mas de 2 palabras y multiples espacios\n");
    {
        ListaString lista;
        char entrada[] = "   hola     mundo aca estoy    ";

        listaStringCrear(lista);
        listaStringSplit(entrada, lista);

        int largo = listaStringCantElementos(lista);
        printf("Largo de la lista es %d\n", largo);
        listaStringDesplegar(lista);
    }
    
}
