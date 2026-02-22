#include "TipoTermino.h"
#include <stdio.h>

void tipoTerminoDesplegar(TipoTermino tterm){
    switch(tterm){
        case VALOR:      printf("VALOR"); break;
        case VARIABLE:   printf("VARIABLE"); break;
        case PARENTESIS: printf("PARENTESIS"); break;
        case OPERADOR:   printf("OPERADOR"); break;
    }
}