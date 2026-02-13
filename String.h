#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "Boolean.h"

const int MAX = 80;
typedef char * String;

//===================================================================================================================

// Crea un string vacío
void strCrear(String &s);

// Libera la memoria usada por el string
void strDestruir(String &s);

// Devuelve el largo del string s */
int strLar(String s);

// Copia el contenido del string s2 en s1
void strCop(String &s1, String s2);

// Lee el string s desde teclado
void strScan(String &s);

// Concatena el contenido de S2 al final de S1
void strCon(String &s1, String s2);

// Intercambia los contenidos de s1 y s2
void strSwp(String &s1, String &s2);

// Imprime el string s por pantalla
void strPrint(String s);

// Determina si s1 es alfabéticamente menor que s2
Boolean strMen(String s1, String s2);

// Determina si los strings s1 y s2 son iguales
Boolean strEq(String s1, String s2);

// ---------- AB STRING ------------
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f);

// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_String (String &s, FILE * f);

// ---------- Funciones / Procedimientos Específicos ------------

Boolean strEsEnteroPositivo(String s1);

Boolean strEsAlfabetico(String s1);

#endif // STRING_H_INCLUDED
