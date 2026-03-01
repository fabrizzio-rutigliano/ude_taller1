#include "TipoError.h"
#include <stdio.h>

void tipoErrorDesplegar(TipoError e) {

    printf("\n[ERROR] ");

    switch (e) {
        // ---------------- Entrada ----------------------
        case ERROR_LINEA_VACIA:
            printf("No se ingreso ningun comando.\n");
            printf("Ingrese un comando y sus parametros separados por espacios.\n");
            break;

        case ERROR_COMANDO_DESCONOCIDO:
            printf("Comando desconocido.\n");
            printf("Verifique que el nombre del comando este bien escrito.\n");
            printf("\nEjemplos de comandos validos:\n");
            printf("  - SIMPLE\n");
            printf("  - COMPUESTA\n");
            printf("  - CALCULAR\n");
            printf("  - IGUALES\n");
            printf("  - GUARDAR\n");
            printf("  - RECUPERAR\n");
            printf("  - SALIR\n");
            break;

        // ---------------- Parametros --------------

        case ERROR_CANT_PARAMETROS_INVALIDA:
            printf("Cantidad de parametros invalida para ese comando.\n");
            printf("El comando ingresado debe respetar la cantidad de parametros definidos.\n");
            break;

        case ERROR_PARAMETRO_INVALIDO:
            printf("Se ingreso un parametro invalido.\n");
            printf("Revise el formato y el tipo de dato esperado.\n");
            break;

        case ERROR_PARAMETRO_NO_ENTERO:
            printf("Se esperaba un numero entero, pero se ingreso otro valor.\n");
            printf("Ejemplo: 1, 2, 10 (sin decimales).\n");
            break;

        case ERROR_PARAMETRO_NO_ENTERO_POSITIVO:
            printf("Se esperaba un entero positivo (mayor que 0).\n");
            printf("Ejemplo: 1, 2, 3, ...\n");
            break;

        case ERROR_PARAMETRO_NO_OPERADOR:
            printf("Se esperaba un operador valido).\n");
            printf("Ejemplo: +, -, *, /\n");
            break;

        case ERROR_PARAMETRO_NO_ENTERO_VARIABLE_INVALIDA:
            printf("Se esperaba un numero entero o una variable X o x.\n");
            break; 
        // ---------------- Indices ------------------

        case ERROR_INDICE_INEXISTENTE:
            printf("La expresion indicada por indice no existe.\n");
            printf("Verifique el numero de indice y vuelva a intentar.\n");
            break;
        
        case ERROR_LISTA_VACIA:
            printf("No hay expresiones disponibles para mostrar.\n");
            printf("Debe crear primero alguna expresión para poder desplegarlas en pantalla.\n");
            break;
        // ---------------- Calculos ----------------
        case ERROR_DIVISION_POR_CERO:
            printf("La operacion no puede realizarse: division por cero.\n");
            printf("Revise la expresion y asegure que el divisor no sea 0.\n");
            break;

        // ---------------- Archivos --------------------
        case ERROR_ARCHIVO_NOMBRE_INVALIDO:
            printf("El nombre de archivo ingresado no es valido.\n");
            printf("Evite espacios y caracteres especiales.\n");
            break;

        case ERROR_ARCHIVO_NO_ENCONTRADO:
            printf("No se encontro el archivo indicado.\n");
            printf("Verifique que exista y que el nombre sea correcto.\n");
            break;
    }

        printf("\n");

}