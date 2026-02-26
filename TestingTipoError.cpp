#include <stdio.h>
#include "TipoError.h"

void testTipoErrorModulo() {

    printf("\n================================================================================\n");
    printf("INICIO DE TESTS DEL MODULO TipoError\n");
    printf("================================================================================\n");

    printf("\n--------------------------------------------------------------------------------\n");
    printf("TEST: tipoErrorDesplegar(TipoError)\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("\nPrueba: ERROR_LINEA_VACIA\n");
    tipoErrorDesplegar(ERROR_LINEA_VACIA);

    printf("\nPrueba: ERROR_COMANDO_DESCONOCIDO\n");
    tipoErrorDesplegar(ERROR_COMANDO_DESCONOCIDO);

    printf("\nPrueba: ERROR_CANT_PARAMETROS_INVALIDA\n");
    tipoErrorDesplegar(ERROR_CANT_PARAMETROS_INVALIDA);

    printf("\nPrueba: ERROR_PARAMETRO_INVALIDO\n");
    tipoErrorDesplegar(ERROR_PARAMETRO_INVALIDO);

    printf("\nPrueba: ERROR_PARAMETRO_NO_ENTERO\n");
    tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO);

    printf("\nPrueba: ERROR_PARAMETRO_NO_ENTERO_POSITIVO\n");
    tipoErrorDesplegar(ERROR_PARAMETRO_NO_ENTERO_POSITIVO);

    printf("\nPrueba: ERROR_INDICE_INEXISTENTE\n");
    tipoErrorDesplegar(ERROR_INDICE_INEXISTENTE);

    printf("\nPrueba: ERROR_DIVISION_POR_CERO\n");
    tipoErrorDesplegar(ERROR_DIVISION_POR_CERO);

    printf("\nPrueba: ERROR_ARCHIVO_NOMBRE_INVALIDO\n");
    tipoErrorDesplegar(ERROR_ARCHIVO_NOMBRE_INVALIDO);

    printf("\nPrueba: ERROR_ARCHIVO_NO_ENCONTRADO\n");
    tipoErrorDesplegar(ERROR_ARCHIVO_NO_ENCONTRADO);

    printf("\n================================================================================\n");
    printf("FIN DE TESTS DEL MODULO TipoError\n");
    printf("================================================================================\n");
}