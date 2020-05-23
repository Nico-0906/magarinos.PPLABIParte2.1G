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

int cargarCilindrada(){
    int retorno;
    int opcion;
    int bucle = 1;

    system("clear");
    printf("***** Ingrese opcion de cilindrada ***** \n\n");
    printf(" 1-  50cc\n 2-  125cc\n 3-  500cc\n 4-  600cc \n 5-  750cc\n\n");
    opcion = validarOpcion(5, 1, "\nIngrese opcion de cilindrada: ", "\nOpcion incorrecta, reintentar: ");;

    while(bucle == 1){
        switch(opcion){
            case 1:
                retorno = 50;
                bucle = 0;
                break;
            case 2:
                retorno = 125;
                bucle = 0;
                break;
            case 3:
                retorno = 500;
                bucle = 0;
                break;
            case 4:
                retorno = 600;
                bucle = 0;
                break;
            case 5:
                retorno = 750;
                bucle = 0;
                break;
            default:
                printf("\nOpcion incorrecta, reingrese opcion: ");
                scanf("%d", &opcion);
                __fpurge(stdin);
                break;
        }
    }
    return retorno;
}

void modificarMoto(eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli){
    system("clear");
    int auxId;
    int busqueda;
    char confirmacion;
    int opcion;
    eMoto auxMoto;

    printf("***** MODIFICAR MOTO ***** \n\n");

    listarMotos(motos, tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
    printf("\n\nIngrese ID de MOTO: ");
    __fpurge(stdin);
    scanf("%d", &auxId);

    busqueda = buscarMoto(auxId, motos, tammot);

    system("clear");
    printf("***** MODIFICAR MOTO ***** \n\n");

    if(busqueda != -1){
        mostrarMoto(motos[busqueda] , tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);

        printf("\nQue desea modificar: \n\n 1- Color\n 2- Cilindrada\n 3- Cancelar \n\n");

        scanf("%d", &opcion);

    switch(opcion){
        case 1:
            mostrarColores(colores, tamcol);
            printf("\nSeleccione nuevo color: ");
            __fpurge(stdin);
            scanf("%d", &auxMoto.idColor);

            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            getCharConfirmValidado(&confirmacion);

            if(confirmacion == 's' || confirmacion == 'S'){
                motos[busqueda].idColor = auxMoto.idColor;
                printf("\nModificado con exito.! \n\n");
                __fpurge(stdin);
                getchar();
            }else if(confirmacion == 'n' || confirmacion == 'N'){
                printf("\nOperacion cancelada. \n\n");
                __fpurge(stdin);
                getchar();
            }
            break;
        case 2:
            auxMoto.cilindrada = cargarCilindrada();
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            getCharConfirmValidado(&confirmacion);

            if(confirmacion == 's' || confirmacion == 'S'){
                motos[busqueda].cilindrada = auxMoto.cilindrada;
                printf("\nModificado con exito.! \n\n");
                __fpurge(stdin);
                getchar();
            }else if(confirmacion == 'n' || confirmacion == 'N'){
                printf("\nOperacion cancelada. \n\n");
                __fpurge(stdin);
                getchar();
            }
            break;
        case 3:
           break;
    }

    }else{
        printf("\nMoto no encontrada. \n\n");
        __fpurge(stdin);
        getchar();
    }
}

void mostrarMoto(eMoto motos , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli){
    char color[20];
    char tipo[20];
    char nombre[20];

    cargarColor(color , motos.idColor, colores, tamcol);
    cargarTipo(tipo , motos.idTipo, tipos, tamtip);
    cargarCliente(nombre, motos.idCliente, clientes, tamcli);

    printf("%d     %10s     %10s     %10s    %10s       %4d\n", motos.id, nombre, motos.marca , tipo, color, motos.cilindrada);
}

int buscarMoto(int id, eMoto motos[], int tammot){
    int retorno = -1;
    for(int i = 0 ; i < tammot ; i++){
        if(motos[i].id == id && motos[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }

    return retorno;
}

int bajaMoto(eMoto motos[] , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli){
    int retorno = 0;

    system("clear");

    int auxId;
    int busqueda;
    char confirmacion;

    printf("***** BAJA MOTO ***** \n\n");

    listarMotos(motos, tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
    printf("\nIngrese ID de moto: ");
    scanf("%d", &auxId);
    __fpurge(stdin);

    busqueda = buscarMoto(auxId, motos, tammot);

    if(busqueda != -1){
        //mostrarMoto(motos, tammot, tipos, tamtip, colores, tamcol);

        printf("\nDesea confirmar la baja? s/n \n\n");
        __fpurge(stdin);
        getCharConfirmValidado(&confirmacion);

        if(confirmacion == 's' || confirmacion == 'S'){
            motos[busqueda].isEmpty = 1;
            retorno = 1;
            printf("\nDada de baja con exito.! \n\n");
            __fpurge(stdin);
            getchar();
        }else if(confirmacion == 'n' || confirmacion == 'N'){
            printf("\nOperacion cancelada. \n\n");
            __fpurge(stdin);
            getchar();
        }
    }else{
        printf("\nMoto no encontrada. \n\n");
        __fpurge(stdin);
        getchar();
    }
    return retorno;
}

void listarMotos(eMoto motos[] , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli){

    printf("****** MOTOS ******\n\n");
    printf("ID       NOMBRE           MARCA           TIPO         COLOR     CILINDRADA\n\n");

    for(int i = 0 ; i < tammot ; i++){
        if(motos[i].isEmpty == 0){
            mostrarMoto(motos[i] , tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);
        }
    }
}

int buscarLibreMoto(eMoto motos[], int tammot){
    int posicion = -1;
        for(int i = 0 ; i < tammot ; i++){
            if(motos[i].isEmpty == 1){
                posicion = i;
                break;
            }
        }
    return posicion;
}

int altaMoto(int idMoto, eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol){
    int retorno = 0;
    int lugar;
    eMoto auxMoto;

    system("clear");

    printf("****** ALTA MOTO ******\n\n");

    lugar = buscarLibreMoto(motos, tammot);

    if(lugar == -1){

    printf("\nNo hay lugar para mas motos. \n\n");
    __fpurge(stdin);
    getchar();

    }else{

    auxMoto.id = idMoto;

    printf("Ingrese marca: \n");
    __fpurge(stdin);
    //getStr(auxMoto.marca, 20);
    while(getNombre(auxMoto.marca, 20)){
        printf("\nReingrese nombre: ");
    }
    //tipoNombre(auxMoto.marca, 20);

    mostrarTipos(tipos, tamtip);
    __fpurge(stdin);
    auxMoto.idTipo = validarOpcion(1003, 1000, "\nIngrese tipo por ID: ", "\nID incorrecto, reintentar: ");

    mostrarColores(colores, tamcol);
    auxMoto.idColor = validarOpcion(10004, 10000, "\nIngrese color por ID: ", "\nID incorrecto, reintentar: ");;


    auxMoto.cilindrada = cargarCilindrada();

    printf("\nMoto agregada con exito.!");
    __fpurge(stdin);
    getchar();

    auxMoto.isEmpty = 0;

    motos[lugar] = auxMoto;

    retorno = 1;
    }

    return retorno;
}

void inicializarMoto(eMoto motos[], int tammot){
     for(int i = 0 ; i < tammot ; i++){
        motos[i].isEmpty = 1;
     }
}
