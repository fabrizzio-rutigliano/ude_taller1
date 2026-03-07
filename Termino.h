#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED
#include "TipoTermino.h"
#include "String.h"

typedef struct{
        TipoTermino discriminante;
        union{
            int valor;
            char variable;
            char operador;
            char parentesis;
        }dato;
}Termino;

// Crea termino valor
Termino terminoCrearValor(TipoTermino tipoTermino, int valor);

// Crea termino variable
Termino terminoCrearVariable(TipoTermino tipoTermino, char variable);

// Crea termino operador
Termino terminoCrearOperador(TipoTermino tipoTermino, char op);

// Devolver valor del termino según su discriminante.
void terminoDesplegarTermino(Termino termino);

// Devuelve el valor del termino
//Precondicion: el tipo termino es VALOR
int terminoDarValor(Termino termino);

// Devuelve la variable del termino
//Precondicion: el tipo termino es VARIABLE
char terminoDarVariable(Termino termino);

// Devuelve el operador del termino
//Precondicion: el tipo termino es OPERADOR
char terminoDarOperador(Termino termino);

// Devuelve el parentisis del termino
//Precondicion: el tipo termino es PARENTESIS
char terminoDarParentesis(Termino termino);

//Persiste al archivo el termino
void terminoBajar(Termino term, FILE * f );

//Recupera desde el archivo el termino
void terminoLevantar(Termino &term, FILE * f );

#endif // TERMINO_H_INCLUDED