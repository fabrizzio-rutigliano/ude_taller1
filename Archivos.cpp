#include "Archivos.h"


// ---------- CREAR/ABRIR--------------

// Crear archivo
void crearArchivo(String nomArch)
{
    FILE * f;
    f = fopen(nomArch, "wb");
    fclose(f);
}

/* Abrir archivo con tipos de lectura
FILE * fopen (String filename, String mode)
"rb" Abre el archivo solo para lectura. Precondición: El archivo debe existir.
"wb" Crea un archivo solo para escritura. Si un archivo con ese nombre
ya existe, será sobreescrito.
"ab" Append; abre un archivo solo para escritura de nuevos datos
*/


// ---------- CONSULTAR ------------
// Determina si existe o no un archivo con el nombre recibido por parámetro
Boolean existeArchivo(String nomArch)
{
    Boolean existe = FALSE;
    FILE * f;
    f = fopen (nomArch, "rb");

    if(f != NULL)
    {
        existe = TRUE;
        fclose(f);
    }
    return existe;
}