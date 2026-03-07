#include <stdio.h>
#include "Comandos.h"

void testComandoGuardar() {

    printf("\n==================================================");
    printf("\nTEST COMANDO GUARDAR - CASO SIMPLE");
    printf("\n==================================================\n");

    // -------------------------------------------------
    // 1) Crear lista de expresiones
    // -------------------------------------------------
    ListaExpresion listaExp;
    listaExpresionCrear(listaExp);

    // -------------------------------------------------
    // 2) Crear una expresion simple: SIMPLE 5
    // -------------------------------------------------
    ListaString listaSimple;
    listaStringCrear(listaSimple);

    String s1, s2;
    strCrear(s1);
    strCrear(s2);

    strCop(s1, (char*)"SIMPLE");
    strCop(s2, (char*)"5");

    listaStringInsertarElemento(s1, listaSimple);
    listaStringInsertarElemento(s2, listaSimple);

    comandoSimple(listaSimple, listaExp);

    listaStringDestruir(listaSimple);
    strDestruir(s1);
    strDestruir(s2);

    // -------------------------------------------------
    // 3) Armar comando: GUARDAR 1 prueba
    // -------------------------------------------------
    ListaString listaGuardar;
    listaStringCrear(listaGuardar);

    String g1, g2, g3;
    strCrear(g1);
    strCrear(g2);
    strCrear(g3);

    strCop(g1, (char*)"GUARDAR");
    strCop(g2, (char*)"1");
    strCop(g3, (char*)"prueba");

    listaStringInsertarElemento(g1, listaGuardar);
    listaStringInsertarElemento(g2, listaGuardar);
    listaStringInsertarElemento(g3, listaGuardar);

    // -------------------------------------------------
    // 4) Ejecutar comando
    // -------------------------------------------------
    comandoGuardar(listaGuardar, listaExp);

    // -------------------------------------------------
    // 5) Liberar memoria
    // -------------------------------------------------
    listaStringDestruir(listaGuardar);
    strDestruir(g1);
    strDestruir(g2);
    strDestruir(g3);

    listaExpresionDestruir(listaExp);

    printf("\nVerificacion manual: deberia haberse creado el archivo prueba.txt\n");
}