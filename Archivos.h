#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "String.h"


// ---------- CREAR --------------
// Agrega el nuevo entero al final del archivo
void crearArchivo(String nomArch);

// ---------- CONSULTAR ------------
// Determina si existe o no un archivo con el nombre recibido por parámetro
Boolean existeArchivo(String nomArch);

#endif // ARCHIVOS_H_INCLUDED