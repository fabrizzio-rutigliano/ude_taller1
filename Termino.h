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

void terminoCrear(Termino &termino);

Boolean terminoEsEnteroPositivo(String s1);

Boolean terminoEsVariable(String s1);

Boolean terminoEsAlfabetico(String s1);

Boolean terminoEsOperador(String s1);

// Precondición: El archivo viene abierto para escritura.
void terminoBajar(Termino term, FILE * f );

// Precondición: El archivo viene abierto para lectura.
void terminoLevantar(Termino &term, FILE * f );