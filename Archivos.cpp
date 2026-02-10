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


// Determina si el archivo está vacío o no. Precondición: El archivo existe
Boolean esVacioArchivo(String nomArch){
    Boolean archivoVacio = FALSE;
    FILE * f = fopen (nomArch, "rb");
    fseek (f, 0, SEEK_END);
    if (ftell (f) == 0)
        archivoVacio = TRUE;
    fclose (f);
    return archivoVacio;
}


// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
Boolean perteneceArchivo(String nomArch, int entero){
    Boolean esta = FALSE;
    FILE * f = fopen (nomArch, "rb");
    int buffer;
    fread (&buffer, sizeof(int), 1, f);
    while (!feof(f) && !esta)
    {
        if (buffer == entero)
            esta = TRUE;
        else
            fread (&buffer, sizeof(int), 1, f);
    }
    fclose (f);
    return esta;
}