#ifndef TIPOTERMINO_H_INCLUDED
#define TIPOTERMINO_H_INCLUDED

typedef enum{VALOR, VARIABLE, PARENTESIS, OPERADOR} TipoTermino;

// Auxiliar para desplegar, posible uso en tests.
void tipoTerminoDesplegar(TipoTermino t);

#endif