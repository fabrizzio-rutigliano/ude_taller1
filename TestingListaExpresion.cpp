#include <stdio.h>
#include "ListaExpresion.h"

// =====================================================================================
// Testing del modulo ListaExpresion
// =====================================================================================

void testListaExpresionModulo()
{
    printf("\n================================================================================\n");
    printf("INICIO DE TESTS DEL MODULO ListaExpresion\n");
    printf("================================================================================\n");

    // =========================================================================
    // Test 1: Crear + EsVacia
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST 1: listaExpresionCrear + listaExpresionEsVacia\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        ListaExpresion l;
        listaExpresionCrear(l);

        if (l == NULL)
            printf("[OK] listaExpresionCrear deja la lista en NULL\n");
        else
            printf("[FAIL] listaExpresionCrear (esperado NULL)\n");

        if (listaExpresionEsVacia(l) == TRUE)
            printf("[OK] listaExpresionEsVacia devuelve TRUE en lista vacia\n");
        else
            printf("[FAIL] listaExpresionEsVacia (esperado TRUE)\n");

        listaExpresionDestruir(l);
    }

    // =========================================================================
    // Test 2: IndiceSiguiente en lista vacia
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST 2: listaExpresionIndiceSiguiente en lista vacia\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        ListaExpresion l;
        listaExpresionCrear(l);

        int sig = listaExpresionIndiceSiguiente(l);
        if (sig == 1)
            printf("[OK] indiceSiguiente en vacia devuelve 1\n");
        else
            printf("[FAIL] indiceSiguiente en vacia (esperado 1, vino %d)\n", sig);

        listaExpresionDestruir(l);
    }

    // =========================================================================
    // Test 3: InsertarFinal + ExisteIndice + IndiceSiguiente
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST 3: insertarFinal + existeIndice + indiceSiguiente\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        ListaExpresion l;
        listaExpresionCrear(l);

        // Expresion 1: indice 1, arbol con un VALOR 5
        ArbolExpresion a1;
        arbolExpresionCrear(a1);
        Termino t1 = terminoCrearValor(VALOR, 5);
        arbolExpresionInsertarTermino(a1, t1, 1);
        Expresion e1 = expresionCrear(a1, 1);

        // Expresion 2: indice 3, arbol con una VARIABLE 'x'
        ArbolExpresion a2;
        arbolExpresionCrear(a2);
        Termino t2 = terminoCrearVariable(VARIABLE, 'x');
        arbolExpresionInsertarTermino(a2, t2, 1);
        Expresion e2 = expresionCrear(a2, 3);

        // Expresion 3: indice 2, arbol con (5 + 3)
        ArbolExpresion a3;
        arbolExpresionCrear(a3);
        Termino operador = terminoCrearOperador(OPERADOR, '+');
        Termino valor_1 = terminoCrearValor(VALOR, 5);
        Termino valor_2 = terminoCrearValor(VALOR, 3);
        arbolExpresionInsertarTermino(a3,operador, 2);
        arbolExpresionInsertarTermino(a3, valor_1, 1);
        arbolExpresionInsertarTermino(a3, valor_2, 3);
        Expresion e3 = expresionCrear(a3, 2);

        // Insertar en orden distinto a los indices (1, 3, 2)
        listaExpresionInsertarFinal(l, e1);
        listaExpresionInsertarFinal(l, e2);
        listaExpresionInsertarFinal(l, e3);

        if (listaExpresionEsVacia(l) == FALSE)
            printf("[OK] luego de insertar, la lista NO esta vacia\n");
        else
            printf("[FAIL] luego de insertar, listaExpresionEsVacia (esperado FALSE)\n");

        // existeIndice
        if (listaExpresionExisteIndice(l, 1) == TRUE &&
            listaExpresionExisteIndice(l, 2) == TRUE &&
            listaExpresionExisteIndice(l, 3) == TRUE)
            printf("[OK] existeIndice devuelve TRUE para indices existentes (1,2,3)\n");
        else
            printf("[FAIL] existeIndice para indices existentes\n");

        if (listaExpresionExisteIndice(l, 99) == FALSE)
            printf("[OK] existeIndice devuelve FALSE para indice inexistente (99)\n");
        else
            printf("[FAIL] existeIndice (esperado FALSE para 99)\n");

        // indiceSiguiente (max indice = 3)
        int sig = listaExpresionIndiceSiguiente(l);
        if (sig == 4)
            printf("[OK] indiceSiguiente devuelve 4 cuando max indice es 3\n");
        else
            printf("[FAIL] indiceSiguiente (esperado 4, vino %d)\n", sig);

        listaExpresionDestruir(l);

        if (l == NULL)
            printf("[OK] destruir deja la lista en NULL\n");
        else
            printf("[FAIL] destruir no dejo la lista en NULL\n");
    }

    // =========================================================================
    // Test 4: DevolverExpresionXIndice
    // =========================================================================
    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST 4: listaExpresionDevolverExpresionXIndice\n");
    printf("--------------------------------------------------------------------------------\n");
    {
        ListaExpresion l;
        listaExpresionCrear(l);

        // Creamos 2 expresiones simples
        ArbolExpresion a1;
        arbolExpresionCrear(a1);
        arbolExpresionInsertarTermino(a1, terminoCrearValor(VALOR, 10), 1);
        Expresion e1 = expresionCrear(a1, 10);

        ArbolExpresion a2;
        arbolExpresionCrear(a2);
        Termino operador = terminoCrearOperador(OPERADOR, '+');
        Termino valor_1 = terminoCrearValor(VALOR, 5);
        Termino valor_2 = terminoCrearValor(VALOR, 3);
        arbolExpresionInsertarTermino(a2,operador, 2);
        arbolExpresionInsertarTermino(a2, valor_1, 1);
        arbolExpresionInsertarTermino(a2, valor_2, 3);
        Expresion e2 = expresionCrear(a2, 20);

        listaExpresionInsertarFinal(l, e1);
        listaExpresionInsertarFinal(l, e2);

        // Precondicion: el indice existe
        Expresion devuelta;
        devuelta = listaExpresionDevolverExpresionXIndice(l, 20);

        if (expresionDevolverIndice(devuelta) == 20)
            printf("[OK] devolverExpresionXIndice devuelve una expresion con indice 20\n");
        else
            printf("[FAIL] devolverExpresionXIndice (esperado 20, vino %d)\n", expresionDevolverIndice(devuelta));

        // Chequeo extra: evaluar el arbol devuelto (5+3 = 8)
        Boolean errorCero = FALSE;
        int val = arbolExpresionEvaluar(expresionDevolverArbolExpresion(devuelta), 0, errorCero);
        if (errorCero == FALSE && val == 8)
            printf("[OK] el arbol de la expresion devuelta evalua 8 (5+3) y no hay division por cero\n");
        else
            printf("[FAIL] evaluar arbol devuelto (esperado 8 sin error, vino %d, errorCero=%d)\n", val, (int)errorCero);

        listaExpresionDestruir(l);
    }

    printf("\n================================================================================\n");
    printf("FIN DE TESTS DEL MODULO ListaExpresion\n");
    printf("================================================================================\n");
}
