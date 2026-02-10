#include "Boolean.h"

void cargarBool(Boolean &b){
    int valor;
    Boolean check = FALSE;

    do
    {
        printf("\nIngrese 0 en caso de Falso, ingrese 1 en caso de Verdadero.");
        scanf("%d", &valor);

        switch(valor)
        {
        case 0:
            b=FALSE;
            check=TRUE;
            break;
        case 1:
            b=TRUE;
            check=TRUE;
            break;
        default:
            printf("\n Valor ingresado invalido, intente de nuevo.");
            break;
        }
    }
    while (check == FALSE);
}

void desplegarBool(Boolean b){
    switch(b)
    {
    case 1:
        printf("Verdadero");
        break;
    case 0:
        printf("Falso");
        break;
    }
}
