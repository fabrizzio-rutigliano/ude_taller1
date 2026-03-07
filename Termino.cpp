#include "Termino.h"

// Crea termino valor
Termino terminoCrearValor(TipoTermino tipoTermino, int valor){
    Termino termino;
    termino.discriminante = tipoTermino;
    termino.dato.valor = valor;

    return termino;
}

// Crea termino variable
Termino terminoCrearVariable(TipoTermino tipoTermino, char variable){
    Termino termino;
    termino.discriminante = tipoTermino;
    termino.dato.variable = variable;

    return termino;
}

// Crea termino operador
Termino terminoCrearOperador(TipoTermino tipoTermino, char op){
    Termino termino;
    termino.discriminante = tipoTermino;
    termino.dato.operador = op;

    return termino;
}

// Auxiliares de dar
// Precondicion: La discriminante debe corresponder a la funcion de retorno utilizada.
int terminoDarValor(Termino termino){
    return termino.dato.valor;
}

char terminoDarVariable(Termino termino){
    return termino.dato.variable;
}

char terminoDarOperador(Termino termino){
    return termino.dato.operador;
}

char terminoDarParentesis(Termino termino){
    return termino.dato.parentesis;
}

// Devolver valor del termino según su discriminante.
void terminoDesplegarTermino(Termino termino){
    
    switch (termino.discriminante)
    {
    case VALOR:
        printf("%d", terminoDarValor(termino));
        break;
    
    case PARENTESIS:
        printf("%c", terminoDarParentesis(termino));
        break;

    case VARIABLE:
        printf("%c", terminoDarVariable(termino));
        break;
        
    case OPERADOR:
        printf("%c", terminoDarOperador(termino));
        break;

    default:
        break;
    }
}

// Precondición: El archivo viene abierto para escritura.
void terminoBajar(Termino term, FILE * f ){
    
    fwrite(&term.discriminante, sizeof(TipoTermino), 1, f);

    if(term.discriminante == VALOR){
        fwrite(&term.dato.valor, sizeof(int), 1, f);
    }
    else if(term.discriminante == VARIABLE){
        fwrite(&term.dato.variable, sizeof(char), 1, f);
    }
    else if(term.discriminante == OPERADOR){
        fwrite(&term.dato.operador, sizeof(char), 1, f);
    }
    else if(term.discriminante == PARENTESIS){
        fwrite(&term.dato.parentesis, sizeof(char), 1, f);
    }
}

// Precondición: El archivo viene abierto para lectura.
void terminoLevantar(Termino &term, FILE * f ){
    
    fread(&term.discriminante, sizeof(TipoTermino), 1, f);

    if(term.discriminante == VALOR){
        fread(&term.dato.valor, sizeof(int), 1, f);
    }
    else if(term.discriminante == VARIABLE){
        fread(&term.dato.variable, sizeof(char), 1, f);
    }
    else if(term.discriminante == OPERADOR){
        fread(&term.dato.operador, sizeof(char), 1, f);
    }
    else if(term.discriminante == PARENTESIS){
        fread(&term.dato.parentesis, sizeof(char), 1, f);
    }
}