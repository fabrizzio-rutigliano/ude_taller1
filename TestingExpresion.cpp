#include <stdio.h>
#include "Expresion.h"

void testExpresionModulo()
{
    printf("\n================================================================================\n");
    printf("INICIO DE TESTS DEL MODULO Expresion\n");
    printf("================================================================================\n");

    // -------------------------
    // Test 1: Crear con arbol NULL e indice positivo
    // -------------------------
    {
        ArbolExpresion a = NULL;
        int idx = 7;

        Expresion e = expresionCrear(a, idx);

        if (expresionDevolverIndice(e) == 7)
            printf("[OK] expresionCrear + devolverIndice con idx=7\n");
        else
            printf("[FAIL] devolverIndice (esperado 7, vino %d)\n", expresionDevolverIndice(e));

        if (expresionDevolverArbolExpresion(e) == NULL)
            printf("[OK] expresionCrear + devolverArbolExpresion con arbol=NULL\n");
        else
            printf("[FAIL] devolverArbolExpresion (esperado NULL)\n");
    }


    // -------------------------
    // Test 2: Puntero no-NULL (test de igualdad de puntero)
    // Solo para verificar que el punteo se guarde igual, no requiere de un arbol real.
    // -------------------------
    {
        ArbolExpresion falsoPuntero = (ArbolExpresion)0x1;  // puntero "falso" SOLO para testear asignación
        Expresion exp = expresionCrear(falsoPuntero, 5);

        if (expresionDevolverArbolExpresion(exp) == falsoPuntero)
            printf("[OK] se conserva el puntero del arbol (igualdad de puntero)\n");
        else
            printf("[FAIL] puntero del arbol no coincide\n");
    }

    printf("\nFin tests Expresion.\n");
}