#include "Termino.h"

// Carga el estructurado de Termino **Cambio a funcion
Termino terminoCrear(TipoTermino tipoTermino, int valor, char otro){

    Termino termino;
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