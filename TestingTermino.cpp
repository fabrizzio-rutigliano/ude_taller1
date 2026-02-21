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
        Termino termino;
        String s;

        terminoCrear(tipoTermino, 4566, '\0', termino);
        strCrear(s);
        strIntToStr(termino.dato.valor, s);
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
        Termino termino;
        String s;

        terminoCrear(tipoTermino, 0, 'x', termino);
        strCrear(s);
        strCharToStr(termino.dato.variable, s);
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
        Termino termino;
        String s;

        terminoCrear(tipoTermino, 0, '+', termino);
        strCrear(s);
        strCharToStr(termino.dato.operador, s);
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
        Termino termino;
        String s;

        terminoCrear(tipoTermino, 0, ')', termino);
        strCrear(s);
        strCharToStr(termino.dato.variable, s);
        terminoDesplegarTermino(termino);
        printf("\nTermino con discriminante PARENTESIS = ");
        strPrint(s);
        strDestruir(s);
    }
}

