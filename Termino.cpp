#include "Termino.h"

void terminoCrear(TipoTermino tipoTermino, int valor, char otro, Termino &termino){

    termino.discriminante = tipoTermino;
    switch(tipoTermino)
    {
    case VALOR:
        termino.dato.valor = valor;
        break;
    case VARIABLE:
        termino.dato.variable = otro;
        break;
    case PARENTESIS:
        termino.dato.parentesis = otro;
        break;
    case OPERADOR:
        termino.dato.operador = otro;
        break;    
    }
}

int terminoDarValor(Termino termino){
    return termino.dato.valor;
}

void terminoDesplegarTermino(Termino termino){
    if(termino.discriminante == VALOR)
    printf('%d',termino.dato.valor);
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

// Precondición: El archivo viene abierto para escritura.
void terminoBajar(Termino term, FILE * f ){

    String s;
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
}

// Precondición: El archivo viene abierto para lectura.
void terminoLevantar(Termino &term, FILE * f ){
    String s;

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
}