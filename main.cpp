#include <stdio.h>
#include "Comandos.h"

//void testStringModulo(); // definicion auxiliar para poder compilar
//void testTerminoModulo();
//void testingModuloArbolExpresion();
//void testExpresionModulo();
//void testListaStringModulo();
//void testListaExpresionModulo();
//void testComandosMostrarCalcularModulo();
//void testComandosModulo();
void testComandoGuardar();

int main() {
    
    // Testeo de modulos
    //testStringModulo(); 
    //testTerminoModulo();
    //testingModuloArbolExpresion();
    //testExpresionModulo();
    //testListaStringModulo();
    //testListaExpresionModulo();
    // Estructura principal
    //testComandosMostrarCalcularModulo();
    //testComandosModulo();
    testComandoGuardar();

    
    /*
    // Inicializar lista de expresiones
    ListaExpresion listaExp;
    listaExpresionCrear(listaExp);

    // Entrada
    String entrada;
    strCrear(entrada);
    // Flag de salida para cortar evaluacion
    Boolean salir = FALSE;

    // String auxiliares para evaluar comando
    String simple; strCrear(simple); char auxSimple[] = "SIMPLE"; strCop(simple, auxSimple);
    String compuesta; strCrear(compuesta); char auxComp[] = "COMPUESTA"; strCop(compuesta, auxComp);
    String calcular; strCrear(calcular); char auxCalc[] = "CALCULAR"; strCop(calcular, auxCalc);
    String iguales; strCrear(iguales); char auxIguales[] = "IGUALES"; strCop(iguales, auxIguales);
    String mostrar; strCrear(mostrar); char auxMostrar[] = "MOSTRAR"; strCop(mostrar, auxMostrar);
    String guardar; strCrear(guardar); char auxGuardar[] = "GUARDAR"; strCop(guardar, auxGuardar);
    String recuperar; strCrear(recuperar); char auxRecuperar[] = "RECUPERAR"; strCop(recuperar, auxRecuperar);
    String salir_str; strCrear(salir_str); char auxSalir[] = "SALIR"; strCop(salir_str, auxSalir);

    while (!salir) {

        printf("\nIngrese comando: ");
        strScan(entrada);

        // Paso 1: validar entrada no vacia
        if (strEsVacio(entrada) || strEsCadenaEnBlanco(entrada)) {
            tipoErrorDesplegar(ERROR_LINEA_VACIA);
        }
        else {
            // Paso 2: realizar el parsing
            ListaString listaStr;
            listaStringCrear(listaStr);
            listaStringSplit(entrada, listaStr);

            if (listaStringCantElementos(listaStr) == 0) {
                tipoErrorDesplegar(ERROR_LINEA_VACIA);
                listaStringDestruir(listaStr);
            }
            else {

                // Paso 3: obtener comando
                String cmd;
                strCrear(cmd);
                listaStringObtener(1, listaStr, cmd);

                // Paso 4: validar comando
                if (!comandoEsValido(cmd)) {
                    tipoErrorDesplegar(ERROR_COMANDO_DESCONOCIDO);
                    strDestruir(cmd);
                    listaStringDestruir(listaStr);
                }
                else {

                    // Paso 5: selector al comando
                    if (strEq(cmd, simple)) {
                        comandoSimple(listaStr, listaExp);
                    }
                    else if (strEq(cmd, compuesta)) {
                        comandoCompuesta(listaStr, listaExp);
                    }
                    else if (strEq(cmd, mostrar)) {
                        comandoMostrar(listaStr, listaExp);
                    }
                    else if (strEq(cmd, calcular)) {
                        comandoCalcular(listaStr, listaExp);
                    }
                    else if (strEq(cmd, iguales)) {
                        comandoIguales(listaStr, listaExp);
                    }
                    else if (strEq(cmd, guardar)) {
                        comandoGuardar(listaStr, listaExp);
                    }
                    else if (strEq(cmd, recuperar)) {
                        comandoRecuperar(listaStr, listaExp);
                    }
                    else if (strEq(cmd, salir_str)) {
                        // comandoSalir destruye listaStr y listaExp, y setea salir=TRUE si todo ok.
                        comandoSalir(listaStr, listaExp, salir);
                    }
                        // Si no se indica salir, entonces hay que liberar lista string para volverla a crear con otra entrada del usuario.
                    if (!salir){
                        listaStringDestruir(listaStr);
                    }
                    strDestruir(cmd);
                }
            }
        }
    }


    // limpieza final strings
    strDestruir(entrada);
    strDestruir(simple);
    strDestruir(compuesta);
    strDestruir(calcular);
    strDestruir(mostrar);
    strDestruir(iguales);
    strDestruir(guardar);
    strDestruir(recuperar);
    strDestruir(salir_str);

    */
}
