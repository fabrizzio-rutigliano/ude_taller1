#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED
# include "TipoTermino.h"
# include "String.h"

typedef struct{
        TipoTermino discriminante;
        union{
            int valor;
            char variable;
            char operador;
            char parentesis;
        }dato;
}Termino;

void terminoCrear(TipoTermino tipoTermino, int valor, char otro, Termino &termino);

int terminoDarValor(Termino termino);

char terminoDarVariable(Termino termino);

char terminoDarOperador(Termino termino);

char terminoDarParentesis(Termino termino);

// Precondición: El archivo viene abierto para escritura.
void terminoBajar(Termino term, FILE * f );

// Precondición: El archivo viene abierto para lectura.
void terminoLevantar(Termino &term, FILE * f );

#endif // TERMINO_H_INCLUDED