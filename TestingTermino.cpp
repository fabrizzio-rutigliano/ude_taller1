#include <stdio.h>
#include "Termino.h"

void testTerminoModulo() {
    printf("\n================================================================================\n");
    printf("INICIO DE TESTS DEL MODULO Termino\n");
    printf("================================================================================\n");

    // =========================================================================
    // terminoCrear
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: terminoCrearValor(TipoTermino tipoTermino, int valor)\n");
    printf("Caso VALOR\n");
    {
        TipoTermino tipoTermino = VALOR;
        tipoTerminoDesplegar(tipoTermino);printf(" - ");
        String s;

        Termino termino = terminoCrearValor(tipoTermino, 4566);
        strCrear(s);
        strIntToStr(terminoDarValor(termino), s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante VALOR = ");
        strPrint(s);
        strDestruir(s);
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: terminoCrearVariable(TipoTermino tipoTermino, char variable)\n");
    printf("Caso VARIABLE\n");
    {
        TipoTermino tipoTermino = VARIABLE;
        tipoTerminoDesplegar(tipoTermino);printf(" - ");
        String s;

        Termino termino = terminoCrearVariable(VARIABLE, 'x');
        strCrear(s);
        strCharToStr(terminoDarVariable(termino), s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante VARIABLE = ");
        strPrint(s);
        strDestruir(s);
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: terminoCrearOperador(TipoTermino tipoTermino, char op)\n");
    printf("Caso OPERADOR\n");
    {
        TipoTermino tipoTermino = OPERADOR;
        tipoTerminoDesplegar(tipoTermino);printf(" - ");
        String s;

        Termino termino = terminoCrearOperador(OPERADOR, '+');
        strCrear(s);
        strCharToStr(terminoDarOperador(termino), s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante OPERADOR = ");
        strPrint(s);
        strDestruir(s);
    }
}

