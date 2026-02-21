#include <stdio.h>
#include "String.h"
#include "Boolean.h"

void testStringModulo() {

    printf("\n================================================================================\n");
    printf("INICIO DE TESTS DEL MODULO String\n");
    printf("================================================================================\n");

    // =========================================================================
    // strIntToStr
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strIntToStr(int, String&)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        printf("\nPrueba: num = 0\n");
        strIntToStr(0, s);
        printf("Resultado: \""); strPrint(s); printf("\"\n");

        printf("\nPrueba: num = 12345\n");
        strIntToStr(12345, s);
        printf("Resultado: \""); strPrint(s); printf("\"\n");

        printf("\nPrueba: num = -987\n");
        strIntToStr(-987, s);
        printf("Resultado: \""); strPrint(s); printf("\"\n");

        strDestruir(s);
    }

    // =========================================================================
    // strCharToStr
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strCharToStr(char, String&)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        printf("\nPrueba: char = 'A'\n");
        strDestruir(s);
        strCharToStr('A', s);
        printf("Resultado: \""); strPrint(s); printf("\"\n");

        printf("\nPrueba: char = ' ' (espacio)\n");
        strDestruir(s);
        strCharToStr(' ', s);
        printf("Resultado: \""); strPrint(s); printf("\"\n");

        strDestruir(s);
    }

    // =========================================================================
    // strStringToInt
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strStringToInt(String)  Precondicion: s es entero\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char t0[] = "0";
        char t1[] = "12345";
        char t2[] = "-987";

        printf("\nPrueba: s = \"0\"\n");
        strCop(s, t0);
        printf("Resultado: %d\n", strStringToInt(s));

        printf("\nPrueba: s = \"12345\"\n");
        strCop(s, t1);
        printf("Resultado: %d\n", strStringToInt(s));

        printf("\nPrueba: s = \"-987\"\n");
        strCop(s, t2);
        printf("Resultado: %d\n", strStringToInt(s));

        strDestruir(s);
    }

    // =========================================================================
    // strStrToChar
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strStrToChar(String) Precondicion: s es variable u operador o parentesis)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char a[] = "X\0";
        char b[] = "+\0";
        char c[] = "(\0";

        printf("\nPrueba: s = \"X\"\n");
        strCop(s, a);
        printf("Resultado: '%c'\n", strStrToChar(s));

        printf("\nPrueba: s = \"+\"\n");
        strCop(s, b);
        printf("Resultado: '%c'\n", strStrToChar(s));

        printf("\nPrueba: s = \"(\"\n");
        strCop(s, c);
        printf("Resultado: '%c'\n", strStrToChar(s));

        strDestruir(s);
    }

    // =========================================================================
    // strEsDigito
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsDigito(char)\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("\nPrueba: c = '0'\n");
    printf("Resultado: "); desplegarBool(strEsDigito('0')); printf("\n");

    printf("\nPrueba: c = '9'\n");
    printf("Resultado: "); desplegarBool(strEsDigito('9')); printf("\n");

    printf("\nPrueba: c = 'a'\n");
    printf("Resultado: "); desplegarBool(strEsDigito('a')); printf("\n");

    // =========================================================================
    // strEsLetra
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsLetra(char)\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("\nPrueba: c = 'a'\n");
    printf("Resultado: "); desplegarBool(strEsLetra('a')); printf("\n");

    printf("\nPrueba: c = 'Z'\n");
    printf("Resultado: "); desplegarBool(strEsLetra('Z')); printf("\n");

    printf("\nPrueba: c = '7'\n");
    printf("Resultado: "); desplegarBool(strEsLetra('7')); printf("\n");

    // =========================================================================
    // strEsEspacioBlanco
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsEspacioBlanco(char)\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("\nPrueba: c = ' ' (espacio)\n");
    printf("Resultado: "); desplegarBool(strEsEspacioBlanco(' ')); printf("\n");

    printf("\nPrueba: c = 'A'\n");
    printf("Resultado: "); desplegarBool(strEsEspacioBlanco('A')); printf("\n");

    // =========================================================================
    // strEsEntero
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsEntero(String)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char vacio[] = "";
        char p1[] = "123";
        char p2[] = "-45";
        char p3[] = "12a";
        char p4[] = "-";

        printf("\nPrueba: s = NULL\n");
        printf("Resultado: "); desplegarBool(strEsEntero(NULL)); printf("\n");

        printf("\nPrueba: s = \"\" (vacio)\n");
        strCop(s, vacio);
        printf("Resultado: "); desplegarBool(strEsEntero(s)); printf("\n");

        printf("\nPrueba: s = \"123\"\n");
        strCop(s, p1);
        printf("Resultado: "); desplegarBool(strEsEntero(s)); printf("\n");

        printf("\nPrueba: s = \"-45\"\n");
        strCop(s, p2);
        printf("Resultado: "); desplegarBool(strEsEntero(s)); printf("\n");

        printf("\nPrueba: s = \"12a\"\n");
        strCop(s, p3);
        printf("Resultado: "); desplegarBool(strEsEntero(s)); printf("\n");

        printf("\nPrueba: s = \"-\" (solo signo)\n");
        strCop(s, p4);
        printf("Resultado: "); desplegarBool(strEsEntero(s)); printf("\n");

        strDestruir(s);
    }

    // =========================================================================
    // strEsEnteroPositivo
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsEnteroPositivo(String)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char vacio[] = "";
        char c0[] = "0";
        char c1[] = "123";
        char c2[] = "-1";
        char c3[] = "12a";

        printf("\nPrueba: s = NULL\n");
        printf("Resultado: "); desplegarBool(strEsEnteroPositivo(NULL)); printf("\n");

        printf("\nPrueba: s = \"\" (vacio)\n");
        strCop(s, vacio);
        printf("Resultado: "); desplegarBool(strEsEnteroPositivo(s)); printf("\n");

        printf("\nPrueba: s = \"0\"\n");
        strCop(s, c0);
        printf("Resultado: "); desplegarBool(strEsEnteroPositivo(s)); printf("\n");

        printf("\nPrueba: s = \"123\"\n");
        strCop(s, c1);
        printf("Resultado: "); desplegarBool(strEsEnteroPositivo(s)); printf("\n");

        printf("\nPrueba: s = \"-1\" (no deberia ser valido)\n");
        strCop(s, c2);
        printf("Resultado: "); desplegarBool(strEsEnteroPositivo(s)); printf("\n");

        printf("\nPrueba: s = \"12a\" (no deberia ser valido)\n");
        strCop(s, c3);
        printf("Resultado: "); desplegarBool(strEsEnteroPositivo(s)); printf("\n");

        strDestruir(s);
    }

    // =========================================================================
    // strEsAlfabetico
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsAlfabetico(String)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char vacio[] = "";
        char a1[] = "Hola";
        char a2[] = "holaMUNDO";
        char a3[] = "Hola123";
        char a4[] = "Ho la";

        printf("\nPrueba: s = NULL\n");
        printf("Resultado: "); desplegarBool(strEsAlfabetico(NULL)); printf("\n");

        printf("\nPrueba: s = \"\" (vacio)\n");
        strCop(s, vacio);
        printf("Resultado: "); desplegarBool(strEsAlfabetico(s)); printf("\n");

        printf("\nPrueba: s = \"Hola\"\n");
        strCop(s, a1);
        printf("Resultado: "); desplegarBool(strEsAlfabetico(s)); printf("\n");

        printf("\nPrueba: s = \"holaMUNDO\"\n");
        strCop(s, a2);
        printf("Resultado: "); desplegarBool(strEsAlfabetico(s)); printf("\n");

        printf("\nPrueba: s = \"Hola123\" (no deberia ser valido)\n");
        strCop(s, a3);
        printf("Resultado: "); desplegarBool(strEsAlfabetico(s)); printf("\n");

        printf("\nPrueba: s = \"Ho la\" (tiene espacio, no deberia ser valido)\n");
        strCop(s, a4);
        printf("Resultado: "); desplegarBool(strEsAlfabetico(s)); printf("\n");

        strDestruir(s);
    }

    // =========================================================================
    // strEliminarEspaciosInicio
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEliminarEspaciosInicio(String, String&)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String in;
        String out;
        strCrear(in);
        strCrear(out);

        char e1[] = "   hola";
        char e2[] = "hola";
        char e3[] = "     ";

        printf("\nPrueba: sin = \"   hola\"\n");
        strCop(in, e1);
        strEliminarEspaciosInicio(in, out);
        printf("Entrada: \""); strPrint(in); printf("\"\n");
        printf("Salida:  \""); strPrint(out); printf("\"\n");

        printf("\nPrueba: sin = \"hola\"\n");
        strCop(in, e2);
        strEliminarEspaciosInicio(in, out);
        printf("Entrada: \""); strPrint(in); printf("\"\n");
        printf("Salida:  \""); strPrint(out); printf("\"\n");

        printf("\nPrueba: sin = \"     \" (solo espacios)\n");
        strCop(in, e3);
        strEliminarEspaciosInicio(in, out);
        printf("Entrada: \""); strPrint(in); printf("\"\n");
        printf("Salida:  \""); strPrint(out); printf("\"\n");

        //printf("\nPrueba: sin = NULL (según implementación, no debería modificar sout)\n");
        //strEliminarEspaciosInicio(NULL, out);
        //printf("Salida:  \""); strPrint(out); printf("\"\n");

        strDestruir(in);
        strDestruir(out);
    }

    // =========================================================================
    // strDividir
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strDividir(String, String&, String&)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String in;
        String out;
        String resto;
        strCrear(in);
        strCrear(out);
        strCrear(resto);

        char d1[] = "comando termino";
        char d2[] = "   comando   termino";
        char d3[] = "comando";

        printf("\nPrueba: sin = \"comando termino\"\n");
        strCop(in, d1);
        strDividir(in, out, resto);
        printf("Entrada:         \""); strPrint(in); printf("\"\n");
        printf("Primera palabra: \""); strPrint(out); printf("\"\n");
        printf("Resto:           \""); strPrint(resto); printf("\"\n");

        printf("\nPrueba: sin = \"   comando   termino\" (espacios iniciales y multiples)\n");
        strCop(in, d2);
        strDividir(in, out, resto);
        printf("Entrada:         \""); strPrint(in); printf("\"\n");
        printf("Primera palabra: \""); strPrint(out); printf("\"\n");
        printf("Resto:           \""); strPrint(resto); printf("\"\n");

        printf("\nPrueba: sin = \"comando\" (una sola palabra)\n");
        strCop(in, d3);
        strDividir(in, out, resto);
        printf("Entrada:         \""); strPrint(in); printf("\"\n");
        printf("Primera palabra: \""); strPrint(out); printf("\"\n");
        printf("Resto:           \""); strPrint(resto); printf("\"\n");

        //printf("\nPrueba: sin = NULL (según implementación, no debería modificar sout/sresto)\n");
        //strDividir(NULL, out, resto);
        //printf("Primera palabra: \""); strPrint(out); printf("\"\n");
        //printf("Resto:           \""); strPrint(resto); printf("\"\n");

        strDestruir(in);
        strDestruir(out);
        strDestruir(resto);
    }

    // =========================================================================
    // strEsVariable
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsVariable(String)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char v1[] = "X";
        char v2[] = "x";
        char v3[] = "X1";
        char v4[] = "Y";

        printf("\nPrueba: s = NULL\n");
        printf("Resultado: "); desplegarBool(strEsVariable(NULL)); printf("\n");

        printf("\nPrueba: s = \"X\"\n");
        strCop(s, v1);
        printf("Resultado: "); desplegarBool(strEsVariable(s)); printf("\n");

        printf("\nPrueba: s = \"x\"\n");
        strCop(s, v2);
        printf("Resultado: "); desplegarBool(strEsVariable(s)); printf("\n");

        printf("\nPrueba: s = \"X1\" (no deberia ser valido)\n");
        strCop(s, v3);
        printf("Resultado: "); desplegarBool(strEsVariable(s)); printf("\n");

        printf("\nPrueba: s = \"Y\" (no deberia ser valido)\n");
        strCop(s, v4);
        printf("Resultado: "); desplegarBool(strEsVariable(s)); printf("\n");

        strDestruir(s);
    }

    // =========================================================================
    // strEsOperador
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: strEsOperador(String)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char o1[] = "+";
        char o2[] = "-";
        char o3[] = "*";
        char o4[] = "/";
        char o5[] = "++";
        char o6[] = "a";

        printf("\nPrueba: s = NULL\n");
        printf("Resultado: "); desplegarBool(strEsOperador(NULL)); printf("\n");

        printf("\nPrueba: s = \"+\"\n");
        strCop(s, o1);
        printf("Resultado: "); desplegarBool(strEsOperador(s)); printf("\n");

        printf("\nPrueba: s = \"-\"\n");
        strCop(s, o2);
        printf("Resultado: "); desplegarBool(strEsOperador(s)); printf("\n");

        printf("\nPrueba: s = \"*\"\n");
        strCop(s, o3);
        printf("Resultado: "); desplegarBool(strEsOperador(s)); printf("\n");

        printf("\nPrueba: s = \"/\"\n");
        strCop(s, o4);
        printf("Resultado: "); desplegarBool(strEsOperador(s)); printf("\n");

        printf("\nPrueba: s = \"++\" (no deberia ser valido)\n");
        strCop(s, o5);
        printf("Resultado: "); desplegarBool(strEsOperador(s)); printf("\n");

        printf("\nPrueba: s = \"a\" (no deberia ser valido)\n");
        strCop(s, o6);
        printf("Resultado: "); desplegarBool(strEsOperador(s)); printf("\n");

        strDestruir(s);
    }

    // =========================================================================
    // comandoEsValido
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: comandoEsValido(String)  (Precondicion: no contiene espacios iniciales)\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        String s;
        strCrear(s);

        char c1[] = "SIMPLE\0";
        char c2[] = "COMPUESTA\0";
        char c3[] = "CALCULAR\0";
        char c4[] = "IGUALES\0";
        char c5[] = "GUARDAR\0";
        char c6[] = "RECUPERAR\0";
        char c7[] = "SALIR\0";
        char c8[] = "simple\0";
        char c9[] = " SIMPLE\0";

        printf("\nPrueba: str = NULL\n");
        printf("Resultado: "); desplegarBool(comandoEsValido(NULL)); printf("\n");

        printf("\nPrueba: str = \"SIMPLE\"\n");
        strCop(s, c1);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \"COMPUESTA\"\n");
        strCop(s, c2);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \"CALCULAR\"\n");
        strCop(s, c3);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \"IGUALES\"\n");
        strCop(s, c4);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \"GUARDAR\"\n");
        strCop(s, c5);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \"RECUPERAR\"\n");
        strCop(s, c6);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \"SALIR\"\n");
        strCop(s, c7);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \"simple\" (minusculas, no deberia ser valido)\n");
        strCop(s, c8);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        printf("\nPrueba: str = \" SIMPLE\" (con espacio inicial; no cumple precondicion)\n");
        strCop(s, c9);
        printf("Resultado: "); desplegarBool(comandoEsValido(s)); printf("\n");

        strDestruir(s);
    }

    printf("\n================================================================================\n");
    printf("FIN DE TESTS DEL MODULO String\n");
    printf("================================================================================\n");
}