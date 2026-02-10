#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include<stdio.h>

typedef enum {FALSE, TRUE} Boolean;

//===================================================================================================================

// Cargar valor boolean desde teclado
void cargarBool(Boolean &b);

// Mostrar valor booleano en pantalla
void desplegarBool(Boolean b);

#endif // BOOLEAN_H_INCLUDED
