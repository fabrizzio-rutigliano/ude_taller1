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

    String s;
    strCrear(s);
    switch(term.discriminante)
    {
    case VALOR:
        strIntToStr(term.dato.valor, s);
        Bajar_String(s, f);
        break;
    case VARIABLE:
        strCharToStr(term.dato.variable, s);
        Bajar_String(s, f);
        break;
    case PARENTESIS:
        strCharToStr(term.dato.parentesis, s);
        Bajar_String(s, f);
        break;
    case OPERADOR:
        strCharToStr(term.dato.operador, s);
        Bajar_String(s, f);
        break;    
    }

    strDestruir(s);
}

// Precondición: El archivo viene abierto para lectura.
void terminoLevantar(Termino &term, FILE * f ){
    
    String s;
    strCrear(s);

    Levantar_String(s, f);
    if(strEsEntero(s)) {
        term.discriminante = VALOR;
        term.dato.valor = strStringToInt(s);
    }else if(strEsVariable(s)){
        term.discriminante = VARIABLE;
        term.dato.variable = strStrToChar(s);
    }else if(strEsOperador(s)){
        term.discriminante = OPERADOR;
        term.dato.operador = strStrToChar(s);
    }else{
        term.discriminante = PARENTESIS;
        term.dato.parentesis = strStrToChar(s);
    }

    strDestruir(s);
}