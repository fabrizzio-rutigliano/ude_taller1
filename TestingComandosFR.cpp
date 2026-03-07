#include <stdio.h>
#include "Comandos.h"

void testComandoGuardar() {

    printf("\n==================================================");
    printf("\nTEST COMANDO GUARDAR");
    printf("\n==================================================\n");

    // -------------------------------------------------
    // 1) Crear lista de expresiones
    // -------------------------------------------------
    ListaExpresion listaExp;
    listaExpresionCrear(listaExp);
    printf("\n[OK] ListaExpresion creada\n");

    // -------------------------------------------------
    // 2) Crear expresion simple: SIMPLE 5
    // -------------------------------------------------
    ListaString listaSimple;
    listaStringCrear(listaSimple);
    printf("[OK] ListaString para comando SIMPLE creada\n");

    String s1, s2;
    strCrear(s1);
    strCrear(s2);
    printf("[OK] Strings s1 y s2 creados\n");

    strCop(s1, (char*)"SIMPLE");
    strCop(s2, (char*)"10");
    printf("[OK] Strings cargados: SIMPLE 5\n");

    listaStringInsertarElemento(s1, listaSimple);
    listaStringInsertarElemento(s2, listaSimple);
    printf("[OK] Parametros insertados en listaSimple\n");

    printf("\n[CONTROL] Antes de comandoSimple\n");
    comandoSimple(listaSimple, listaExp);
    printf("\n[CONTROL] Despues de comandoSimple\n");

    // -------------------------------------------------
    // 3) Intentar obtener y mostrar la expresion guardada
    // -------------------------------------------------
    printf("\n[CONTROL] Antes de devolver expresion por indice\n");
    Expresion e = listaExpresionDevolverExpresionXIndice(listaExp, 1);
    printf("[CONTROL] Despues de devolver expresion por indice\n");

    printf("\n[CONTROL] Antes de mostrar expresion recuperada desde lista\n");
    expresionMostrar(e);
    printf("\n[CONTROL] Despues de mostrar expresion recuperada desde lista\n");

    listaStringDestruir(listaSimple);
    strDestruir(s1);
    strDestruir(s2);
    printf("\n[OK] Recursos de comando SIMPLE liberados\n");

    // -------------------------------------------------
    // 4) Crear comando: GUARDAR 1 prueba
    // -------------------------------------------------
    ListaString listaGuardar;
    listaStringCrear(listaGuardar);
    printf("[OK] ListaString para comando GUARDAR creada\n");

    String g1, g2, g3;
    strCrear(g1);
    strCrear(g2);
    strCrear(g3);
    printf("[OK] Strings g1, g2 y g3 creados\n");

    strCop(g1, (char*)"GUARDAR");
    strCop(g2, (char*)"1");
    strCop(g3, (char*)"prueba");
    printf("[OK] Strings cargados: GUARDAR 1 prueba\n");

    listaStringInsertarElemento(g1, listaGuardar);
    listaStringInsertarElemento(g2, listaGuardar);
    listaStringInsertarElemento(g3, listaGuardar);
    printf("[OK] Parametros insertados en listaGuardar\n");

    // -------------------------------------------------
    // 5) Ejecutar comando guardar
    // -------------------------------------------------
    printf("\n[CONTROL] Antes de comandoGuardar\n");
    comandoGuardar(listaGuardar, listaExp);
    printf("[CONTROL] Despues de comandoGuardar\n");

    // -------------------------------------------------
    // 6) Liberar memoria
    // -------------------------------------------------
    listaStringDestruir(listaGuardar);
    strDestruir(g1);
    strDestruir(g2);
    strDestruir(g3);
    printf("\n[OK] Recursos de comando GUARDAR liberados\n");

    listaExpresionDestruir(listaExp);
    printf("[OK] ListaExpresion destruida\n");

    printf("\nVerificacion manual: deberia haberse creado el archivo prueba.txt\n");
}



void testComandoRecuperar() {

    printf("\n==================================================");
    printf("\nTEST COMANDO RECUPERAR");
    printf("\n==================================================\n");

    // -------------------------------------------------
    // 1) Crear lista de expresiones vacía
    // -------------------------------------------------

    ListaExpresion listaExp;
    listaExpresionCrear(listaExp);

    printf("\n[OK] ListaExpresion creada\n");

    // -------------------------------------------------
    // 2) Crear comando: RECUPERAR prueba
    // -------------------------------------------------

    ListaString listaRecuperar;
    listaStringCrear(listaRecuperar);

    String r1, r2;

    strCrear(r1);
    strCrear(r2);

    strCop(r1, (char*)"RECUPERAR");
    strCop(r2, (char*)"prueba");

    listaStringInsertarElemento(r1, listaRecuperar);
    listaStringInsertarElemento(r2, listaRecuperar);

    printf("\n[CONTROL] Antes de comandoRecuperar\n");

    comandoRecuperar(listaRecuperar, listaExp);

    printf("\n[CONTROL] Después de comandoRecuperar\n");

    // -------------------------------------------------
    // 3) Crear comando: MOSTRAR
    // -------------------------------------------------

    ListaString listaMostrar;
    listaStringCrear(listaMostrar);

    String m1;
    strCrear(m1);

    strCop(m1, (char*)"MOSTRAR");

    listaStringInsertarElemento(m1, listaMostrar);

    printf("\n[CONTROL] Ejecutando comandoMostrar\n");

    comandoMostrar(listaMostrar, listaExp);

    // -------------------------------------------------
    // 4) Liberar memoria
    // -------------------------------------------------

    listaStringDestruir(listaRecuperar);
    listaStringDestruir(listaMostrar);

    strDestruir(r1);
    strDestruir(r2);
    strDestruir(m1);

    listaExpresionDestruir(listaExp);

    printf("\n[OK] Memoria liberada\n");
}