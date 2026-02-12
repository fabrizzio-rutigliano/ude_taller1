#include "String.h"

typedef struct nodoS{
        String palabra;
        nodoS * sig;
        }NodoS;
        
typedef NodoS * ListaString;

// crearLista
// insertarElementoLista
// destruirLista

void listaStringObtener(int indice, ListaString lista, String &str);

void listaStringSplit(String entrada, ListaString &lista);

int listaStringCantElementos(ListaString lista);


