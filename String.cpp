#include "String.h"

void strCrear(String &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strDestruir(String &s)
{
    delete[] s;
    s = NULL;
}

int strLar(String s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strCop(String &s1, String s2)
{
    int i = 0;
    int largo = strLar(s2) + 1;
    delete[] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void strScan(String &s)
{
    String aux = new char[MAX];
    int i = 0;
    char c;
    scanf(" %c", &c);
    while (c != '\n' && i < MAX - 1)
    {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }
    aux[i] = '\0';
    strCop(s, aux);
    strDestruir(aux);
}

void strPrint(String s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c", s[i]);
        i++;
    }
}

Boolean strEq(String s1, String s2)
{
    int i = 0;
    Boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

// ---------- ARCHIVO String --------------------------------------
// Escribe en el archivo los caracteres del String s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f){
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    // escribo el '\0'
    fwrite (&s[i], sizeof(char), 1, f);
}

// Lee desde el archivo los caracteres del String s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_String (String &s, FILE * f){
    int i=0;
    String aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    if (feof(f))
        aux[i] = '\0';
    strCop (s, aux);
    delete [] aux;
}

// ---------- Funciones / Procedimientos Específicos ------------

//Valida si el string s es vacio
Boolean strEsVacio(String s){
    Boolean result = FALSE;
    if (strLar(s) == 0 && s[0] == '\0'){
        result = TRUE;
    }
    return result;
}

//Transforma un String a un entero
//Precondicion el String es un entero
int strStringToInt(String s)
{
    int i = 0;
    int result = 0;
    Boolean negativo = FALSE;

    if (s[0] == '-'){
        negativo = TRUE;
        i = 1;
    }

    while (s[i] != '\0'){
        result = result * 10 + (s[i] - '0');
        i++;
    }

    if (negativo == TRUE)
        result = -result;

    return result;
}


//Transforma un String en un char
//Precondicion: S es variable, operador o parentesis
char strStrToChar(String s){
    return s[0];
}

// Auxiliar para evaluar si es numerico.
Boolean strEsDigito(char c) {
    
    Boolean check = FALSE;
    if (c >= '0' && c <= '9')
        check = TRUE;
    
    return check;
}

// Auxiliar para evaluar caracter.
Boolean strEsLetra(char c) {
    Boolean check = FALSE;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        check = TRUE;

    return check;
}

// Auxiliar para evaluar espacio en blanco.
Boolean strEsEspacioBlanco(char c) {
    Boolean check = FALSE;
    if (c == ' ') //|| c == '\t' || c == '\n'
        check = TRUE;
    return check;
}

// Devuelve si s1 representa a un entero
Boolean strEsEntero(String s1) {
    
    Boolean check = TRUE;
    int i = 0;

    // Si es NULL no es entero
    if (s1 == NULL)
        check = FALSE;
    // Si viene salto de str tampoco
    if (check && s1[0] == '\0')
        check = FALSE;
    // Evaluamos si es negativo
    if (check && (s1[i] == '-')) {
        i++;

        // Si luego del signo viene termino str no es válido.
        if (s1[i] == '\0')
            check = FALSE;
        // Dejamos el i posicionado en el segundo caracter.
    }

    // Todos los restantes deben ser dígitos
    while (check && s1[i] != '\0') {
        if (strEsDigito(s1[i]) == FALSE)
            check = FALSE;
        i++;
    }

    return check;
}

// Devuelve si s1 representa a un entero positivo
// PARA REVISAR: Positivo = Natural, o mayor estricto a 0??
Boolean strEsEnteroPositivo(String s1){
    Boolean check = TRUE;
    int i = 0;
    

    // si es NULL no es válido
    if (s1 == NULL)
        check = FALSE;
    // Si viene salto de str tampoco
    if (check && s1[0] == '\0')
        check = FALSE;

    // Todos deben ser dígitos
    while (check && s1[i] != '\0') {
        if (strEsDigito(s1[i]) == FALSE)
            check = FALSE;
        i++;
    }
    
    return check;
};

// Devuelve si s1 representa a una cadena de caracteres alfabeticas
Boolean strEsAlfabetico(String s1){
    Boolean check = TRUE;
    int i = 0;

    if (s1 == NULL)
        check = FALSE;

    if (check && s1[0] == '\0')
        check = FALSE;

    while (check && s1[i] != '\0') {
        if (strEsLetra(s1[i]) == FALSE)
            check = FALSE;
        i++;
    }

    return check;
};

// Elimina los espacios en blanco al principio del string.
void strEliminarEspaciosInicio( String sin, String &sout){
    
    int i = 0;
    int j = 0;
    String aux = new char[MAX];

    if ((sin != NULL)) {
        while (sin[i] != '\0' && strEsEspacioBlanco(sin[i]) == TRUE)
            i++;

        while (sin[i] != '\0' && j < MAX - 1) {
            aux[j] = sin[i];
            j++;
            i++;
        }
        aux[j] = '\0';

        strCop(sout, aux);
        
    }
    
    delete[] aux;
};

// Devuelve si s1 es una cadena de espacios
Boolean strEsCadenaEnBlanco(String s1){
    int i = 0;
    Boolean enBlanco = TRUE;

    if(strEsVacio(s1)){
        enBlanco = FALSE;
    }

    while (s1[i] != '\0' && enBlanco){
        if(!strEsEspacioBlanco(s1[i])){
            enBlanco = FALSE;
        }
        i++;
    }
    return enBlanco;
}

/* Devuelve sOut con la primera palabra de sIn, 
    y devuelve sResto con lo que está después de la palabra inicial.*/
void strDividir(String sin, String &sout, String &sresto){
    
    int i = 0;
    int j = 0;
    int k = 0;

    if (sin != NULL) {
        // Saltear espacios blancos iniciales
        while (sin[i] != '\0' && strEsEspacioBlanco(sin[i]) == TRUE)
            i++;
        
        // primera palabra
        String o = new char[MAX];
        while (sin[i] != '\0' && strEsEspacioBlanco(sin[i]) == FALSE && j < MAX - 1) {
            o[j] = sin[i];
            j++;
            i++;
        }
        o[j] = '\0';

        // resto (lo que sigue a partir de i)
        String r = new char[MAX];
        while (sin[i] != '\0' && k < MAX - 1) {
            r[k] = sin[i];
            k++;
            i++;
        }
        r[k] = '\0';
        if(strEsCadenaEnBlanco(r)){
            r[0] = '\0';
        }

        strCop(sout, o);
        strCop(sresto, r);

        delete[] o;
        delete[] r;
    }
};

// Valida si s1 es la variable X
Boolean strEsVariable(String s1){
    Boolean check = TRUE;
    // Que no sea nulo
    if (s1 == NULL)
        check = FALSE;
    // Evalua que sea variable X
    if (check && (s1[0] != 'X' && s1[0] != 'x'))
        check = FALSE;
    // Y que termine inmediatamente luego de la variable
    if (check && s1[1] != '\0')
        check = FALSE;

    return check;
};

// Valida si s1 es un operador (+,-,*,/)
Boolean strEsOperador(String s1){
    Boolean check = TRUE;
    // Que no sea nulo
    if (s1 == NULL)
        check = FALSE;
    // Debe ser un solo caracter
    if (check && s1[1] != '\0')
        check = FALSE;
    // Evalua que sea un simbolo valido
    if (check && (s1[0] != '+' && s1[0] != '-' && s1[0] != '*' && s1[0] != '/'))
        check = FALSE;

    return check;
};

Boolean comandoEsValido(String str){
    
    Boolean check = FALSE;

    String simple;
    strCrear(simple);
    char auxSimple[] = "simple";
    strCop(simple, auxSimple);

    String compuesta;
    strCrear(compuesta);
    char auxComp[] = "compuesta";
    strCop(compuesta, auxComp);

    String mostrar;
    strCrear(mostrar);
    char auxMostrar[] = "mostrar";
    strCop(mostrar, auxMostrar);
    
    String calcular;
    strCrear(calcular);
    char auxCalc[] = "calcular";
    strCop(calcular, auxCalc);
    
    String iguales;
    strCrear(iguales);
    char auxIguales[] = "iguales";
    strCop(iguales, auxIguales);

    String guardar;
    strCrear(guardar);
    char auxGuardar[] = "guardar";
    strCop(guardar, auxGuardar);

    String recuperar;
    strCrear(recuperar);
    char auxRecuperar[] = "recuperar";
    strCop(recuperar, auxRecuperar);

    String salir;
    strCrear(salir);
    char auxSalir[] = "salir";
    strCop(salir, auxSalir);

    if (str != NULL) {

        if (strEq(str, simple) == TRUE)
            check = TRUE;
        else if (strEq(str, compuesta) == TRUE)
            check = TRUE;
        else if (strEq(str, calcular) == TRUE)
            check = TRUE;
        else if (strEq(str, iguales) == TRUE)
            check = TRUE;
        else if (strEq(str, mostrar) == TRUE)
            check = TRUE;
        else if (strEq(str, guardar) == TRUE)
            check = TRUE;
        else if (strEq(str, recuperar) == TRUE)
            check = TRUE;
        else if (strEq(str, salir) == TRUE)
            check = TRUE;
    }

    strDestruir(simple);
    strDestruir(compuesta);
    strDestruir(calcular);
    strDestruir(mostrar);
    strDestruir(iguales);
    strDestruir(guardar);
    strDestruir(recuperar);
    strDestruir(salir);

    return check;
};