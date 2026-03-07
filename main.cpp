#include <stdio.h>
#include "Comandos.h"

int main() {

    // Inicializar lista de expresiones
    ListaExpresion listaExp;
    listaExpresionCrear(listaExp);

    // Entrada
    String entrada;
    strCrear(entrada);
    
    // Flag de salida para cortar bucle
    Boolean salir = FALSE;

    // String auxiliares para evaluar comando
    String simple; strCrear(simple); char auxSimple[] = "simple"; strCop(simple, auxSimple);
    String compuesta; strCrear(compuesta); char auxComp[] = "compuesta"; strCop(compuesta, auxComp);
    String calcular; strCrear(calcular); char auxCalc[] = "calcular"; strCop(calcular, auxCalc);
    String iguales; strCrear(iguales); char auxIguales[] = "iguales"; strCop(iguales, auxIguales);
    String mostrar; strCrear(mostrar); char auxMostrar[] = "mostrar"; strCop(mostrar, auxMostrar);
    String guardar; strCrear(guardar); char auxGuardar[] = "guardar"; strCop(guardar, auxGuardar);
    String recuperar; strCrear(recuperar); char auxRecuperar[] = "recuperar"; strCop(recuperar, auxRecuperar);
    String salir_str; strCrear(salir_str); char auxSalir[] = "salir"; strCop(salir_str, auxSalir);

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
            
            // Paso 3: obtener comando
            String cmd;
            strCrear(cmd);
            listaStringObtener(0, listaStr, cmd);

            // Paso 4: validar comando
            if (!comandoEsValido(cmd)) {
                tipoErrorDesplegar(ERROR_COMANDO_DESCONOCIDO);
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
                        // comandoSalir destruye listaExp, y setea salir=TRUE si todo ok.
                        comandoSalir(listaStr ,listaExp, salir);
                    }   
                }
            // Liberacion de memoria para siguente iteracion
            listaStringDestruir(listaStr);
            strDestruir(cmd);
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
}
