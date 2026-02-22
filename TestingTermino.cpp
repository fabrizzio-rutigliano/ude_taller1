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
    printf("TEST: terminoCrear(TipoTermino tipoTermino, int valor, char otro, Termino &termino)\n");
    printf("Caso VALOR\n");
    {
        TipoTermino tipoTermino = VALOR;
        tipoTerminoDesplegar(tipoTermino);printf(" - ");
        String s;

        Termino termino = terminoCrear(tipoTermino, 4566, '\0');
        strCrear(s);
        strIntToStr(terminoDarValor(termino), s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante VALOR = ");
        strPrint(s);
        strDestruir(s);
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: terminoCrear(TipoTermino tipoTermino, int valor, char otro, Termino &termino)\n");
    printf("Caso VARIABLE\n");
    {
        TipoTermino tipoTermino = VARIABLE;
        tipoTerminoDesplegar(tipoTermino);printf(" - ");
        String s;

        Termino termino = terminoCrear(VARIABLE, 0, 'x');
        strCrear(s);
        strCharToStr(terminoDarVariable(termino), s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante VARIABLE = ");
        strPrint(s);
        strDestruir(s);
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: terminoCrear(TipoTermino tipoTermino, int valor, char otro, Termino &termino)\n");
    printf("Caso OPERADOR\n");
    {
        TipoTermino tipoTermino = OPERADOR;
        tipoTerminoDesplegar(tipoTermino);printf(" - ");
        String s;

        Termino termino = terminoCrear(OPERADOR, 0, '+');
        strCrear(s);
        strCharToStr(terminoDarOperador(termino), s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante OPERADOR = ");
        strPrint(s);
        strDestruir(s);
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: terminoCrear(TipoTermino tipoTermino, int valor, char otro, Termino &termino)\n");
    printf("Caso PARENTESIS\n");
    {
        TipoTermino tipoTermino = PARENTESIS;
        tipoTerminoDesplegar(tipoTermino);printf(" - ");
        String s;

        Termino termino = terminoCrear(PARENTESIS, 0, ')');
        strCrear(s);
        strCharToStr(terminoDarParentesis(termino), s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante PARENTESIS = ");
        strPrint(s);
        strDestruir(s);
    }
}

