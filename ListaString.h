#include "String.h"

typedef struct nodoS{
        String palabra;
        nodoS * sig;
        }NodoS;
        
typedef NodoS * ListaString;

void listaStringCrear(ListaString &lista);

void listaStringDestruir(ListaString &lista);

void listaStringInsertarElemento(ListaString &lista, String str);

void listaStringObtener(int indice, ListaString lista, String &str);

void listaStringSplit(String entrada, ListaString &lista);

int listaStringCantElementos(ListaString lista);


