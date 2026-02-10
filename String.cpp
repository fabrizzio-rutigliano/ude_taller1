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

void strCon(String &s1, String s2)
{
    String aux;
    strCrear(aux);
    strCop(aux, s1);
    int largo = strLar(s1) + strLar(s2) + 1;
    if (largo > MAX)
        largo = MAX;
    delete[] s1;
    s1 = new char[largo];
    int i = 0;
    while (aux[i] != '\0')
    {
        s1[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX - 1)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    strDestruir(aux);
}

void strSwp(String &s1, String &s2)
{
    String aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
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

Boolean strMen(String s1, String s2)
{
    int i = 0;
    Boolean encontre = FALSE;
    Boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i] != '\0'))
        menor = TRUE;
    return menor;
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
