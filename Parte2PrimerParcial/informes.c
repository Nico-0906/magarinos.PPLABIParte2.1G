#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"
#include "herramientas.h"
#include "cliente.h"


void motosColorMasElegido(eMoto motos[],int tammot, eColor colores[],int tamcol, eServicio servicios[],int tamser, eTipo tipos[],int tamtip, eTrabajo trabajos[],int tamtra, eCliente clientes[], int tamcli){
    system("clear");
    int azul = 0;
    int rojo = 0;
    int gris = 0;
    int negro = 0;
    int blanco = 0;


    printf("****** MOTOS DE COLOR MAS ELEGIDO ******\n\n");
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");

    for(int i = 0; i < tammot ; i++){
        if(motos[i].idColor == 10000 && motos[i].isEmpty == 0){
            gris++;
        }else if(motos[i].idColor == 10001 && motos[i].isEmpty == 0){
            negro++;
        }else if(motos[i].idColor == 10002 && motos[i].isEmpty == 0){
            blanco++;
        }else if(motos[i].idColor == 10003 && motos[i].isEmpty == 0){
            azul++;
        }else if(motos[i].idColor == 10004 && motos[i].isEmpty == 0){
            rojo++;
        }
    }
}

void motosPorColorTipo(eMoto motos[],int tammot, eColor colores[],int tamcol, eServicio servicios[],int tamser, eTipo tipos[],int tamtip, eTrabajo trabajos[],int tamtra, eCliente clientes[], int tamcli){
    int opcionTipo;
    int opcionColor;
    int bandera = 1;

    system("clear");
    printf("****** MOTOS DE COLOR Y TIPO ******\n\n");
    mostrarTipos(tipos, tamtip);
    opcionTipo = validarOpcion(1003, 1000, "\nIngrese tipo de moto por ID: ", "\nID incorrecto, reintentar: ");

    system("clear");
    printf("****** MOTOS DE COLOR Y TIPO ******\n\n");
    mostrarColores(colores, tamcol);
    printf("Seleccione color por id: ");
    opcionColor = validarOpcion(10004, 10000, "\nIngrese color de moto por ID: ", "\nID incorrecto, reintentar: ");

    system("clear");
    printf("****** MOTOS DE COLOR Y TIPO ******\n\n");
    for(int i = 0 ; i < tammot ; i++){
        if(motos[i].idColor == opcionColor && motos[i].idTipo == opcionTipo && motos[i].isEmpty == 0){
            bandera = 0;
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
        }
    }
    if(bandera == 1){
        printf("\nNo hay motos con el color y el tipo seleccionado \n");
    }
}

void motosSeparadasTipo(eMoto motos[],int tammot, eColor colores[],int tamcol, eServicio servicios[],int tamser, eTipo tipos[],int tamtip, eTrabajo trabajos[],int tamtra, eCliente clientes[], int tamcli){
    system("clear");
    printf("****** MOTOS SEPARADAS POR TIPO ******\n\n");
    printf("MOTOS TIPO ENDURO\n");
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");
    for(int i = 0; i < tammot; i++){
        if(motos[i].idTipo == 1000 && motos[i].isEmpty == 0){
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
        }
    }
     printf("\n\nMOTOS TIPO CHOPERA\n");
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");
    for(int i = 0; i < tammot; i++){
        if(motos[i].idTipo == 1001 && motos[i].isEmpty == 0){
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
        }
    }
     printf("\n\nMOTOS TIPO SCOOTER\n");
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");
    for(int i = 0; i < tammot; i++){
        if(motos[i].idTipo == 1002 && motos[i].isEmpty == 0){
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
        }
    }
     printf("\n\nMOTOS TIPO CICLOMOTOR\n");
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");
    for(int i = 0; i < tammot; i++){
        if(motos[i].idTipo == 1003 && motos[i].isEmpty == 0){
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
        }
    }


}

void motosMayorCilindrada(eMoto motos[],int tammot, eColor colores[],int tamcol, eServicio servicios[],int tamser, eTipo tipos[],int tamtip, eTrabajo trabajos[],int tamtra, eCliente clientes[], int tamcli){
    int mayor = 0;
    int bandera = 0;

    system("clear");
    printf("****** MOTOS MAYOR CILINDRADA ******\n\n");
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");

    for(int i = 0; i < tammot ; i++){
        if(motos[i].cilindrada >= mayor && motos[i].isEmpty == 0){
            mayor = motos[i].cilindrada;
        }
    }
    for(int i = 0; i < tammot ; i++){
        if(motos[i].cilindrada == mayor && motos[i].isEmpty == 0){
            bandera = 1;
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
        }
    }
    if(bandera == 0){
        printf("\n NO HAY MOTOS INGRESADAS \n");
    }
}

void motosPorTipo(eMoto motos[],int tammot, eColor colores[],int tamcol, eServicio servicios[],int tamser, eTipo tipos[],int tamtip, eTrabajo trabajos[],int tamtra, eCliente clientes[], int tamcli){
    int opcion;
    char tipo[20];
    int bandera = 1;
    mostrarTipos(tipos, tamtip);
    opcion = validarOpcion(1003, 1000, "\nIngrese tipo de moto por ID: ", "\nID incorrecto, reintentar: ");

    cargarTipo(tipo, opcion, tipos, tamtip);

    system("clear");
    printf("****** Motos tipo %s ******\n\n", tipo);
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");

    for(int i = 0; i < tamcol; i++){
        if(motos[i].idTipo == opcion && tipos[i].isEmpty == 0 && motos[i].isEmpty == 0){
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
            bandera = 0;
        }
    }
    if(bandera == 1){
        printf("\nNo hay motos de ese tipo cargadas. \n");
    }

}

void motosPorColor(eMoto motos[],int tammot, eColor colores[],int tamcol, eServicio servicios[],int tamser, eTipo tipos[],int tamtip, eTrabajo trabajos[],int tamtra, eCliente clientes[], int tamcli){
    int opcion;
    char color[20];
    int bandera = 1;
    mostrarColores(colores, tamcol);
    opcion = validarOpcion(10004, 10000, "\nIngrese color de moto por ID: ", "\nID incorrecto, reintentar: ");

    cargarColor(color, opcion, colores, tamcol);

    system("clear");
    printf("****** Motos color %s ******\n\n", color);
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");

    for(int i = 0; i < tamcol; i++){
        if(motos[i].idColor == opcion && colores[i].isEmpty == 0 && motos[i].isEmpty == 0){
            mostrarMoto(motos[i], tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
            bandera = 0;
        }
    }
    if(bandera == 1){
        printf("\nNo hay motos de ese color cargadas. \n");
    }

}

int menuInforme(){

    int retorno;

    system("clear");

    printf("***** INFORME MOTOS ***** \n");

    printf("1- Listar motos por color elegido \n");
    printf("2- Listar motos por tipo elegido \n");
    printf("3- Motos de mayor cilindrada \n");
    printf("4- Motos separadas por tipo \n");
    printf("5- Cantidad de motos por color y tipo\n");
    printf("6- Colores mas elegidos por clientes \n");
    printf("7- SALIR \n \n ");

    retorno = validarOpcion(7, 1, "\nIngrese opcion: ", "\nOpcion incorrecta, reintentar: ");
    __fpurge(stdin);

    return retorno;
}

void informesMotos(eMoto motos[], int tammot, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTipo tipos[], int tamtip, eTrabajo trabajos[], int tamtra, eCliente clientes[], int tamcli){

    char seguir = 's';
    char confirma;
    do{
        switch(menuInforme())
        {
            case 1:
                motosPorColor(motos, tammot, colores, tamcol, servicios, tamser, tipos, tamtip, trabajos, tamtra, clientes, tamcli);
                break;
            case 2:
                motosPorTipo(motos, tammot, colores, tamcol, servicios, tamser, tipos, tamtip, trabajos, tamtra, clientes, tamcli);
                break;
            case 3:
                motosMayorCilindrada(motos ,tammot, colores,tamcol, servicios,tamser, tipos,tamtip,trabajos,tamtra,clientes,tamcli);
                break;
            case 4:
                motosSeparadasTipo(motos,tammot, colores,tamcol, servicios,tamser, tipos,tamtip, trabajos,tamtra, clientes, tamcli);
                break;
            case 5:
                motosPorColorTipo(motos,tammot, colores,tamcol, servicios,tamser, tipos,tamtip, trabajos,tamtra, clientes, tamcli);
                break;
            case 6:
                break;
            case 7:
                printf("\nConfirma salida? s/n \n");
                __fpurge(stdin);
                scanf("%c", &confirma);
                if(confirma == 's'){
                    seguir = 'n';
                }
                break;
        }

        __fpurge(stdin);
        getchar();

    }while(seguir == 's');

}
