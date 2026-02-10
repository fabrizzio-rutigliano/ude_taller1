# include "TipoTermino.h"

typedef struct{
        TipoTermino discriminante;
        union{
            int valor;
            char variable;
            char operador;
            char parentesis;
        }dato;
}Termino;
