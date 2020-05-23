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

int cargarServicio(char nombreServicio[], int id, eServicio servicios[], int tamser){
    int retorno = 0;
    for(int i = 0 ; i < tamser ; i++){
        if(servicios[i].id == id){
            strcpy(nombreServicio, servicios[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;
}

int cargarMoto(char nombreMarca[], int id, eMoto motos[], int tammot){
    int retorno = 0;
    for(int i = 0 ; i < tammot ; i++){
        if(motos[i].id == id){
            strcpy(nombreMarca, motos[i].marca);
            retorno = 1;
        }
    }
    return retorno;
}

void mostrarTrabajo(eTrabajo trabajos, eMoto motos[], int tammot, eServicio servicios[], int tamser){
    char nombreMoto[20];
    char nombreServicio[20];

    cargarMoto(nombreMoto, trabajos.idMoto, motos, tammot);
    cargarServicio(nombreServicio, trabajos.idServicio, servicios, tamser);

    printf("%d     %10s      %10s     %2d/%2d/%4d  \n", trabajos.id, nombreMoto, nombreServicio, trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio);

}

void listarTrabajos(eTrabajo trabajos[], int tamtra, eMoto motos[], int tammot, eServicio servicios[], int tamser){
    int bandera = 1;
    printf("****** Listado de Trabajos ******\n\n");
    printf("ID          MOTO         SERVICIO        FECHA \n\n");

    for(int i = 0; i < tamtra; i++){
        if(trabajos[i].isEmpty == 0){
        mostrarTrabajo(trabajos[i], motos, tammot, servicios, tamser);
        bandera = 0;
        }
    }

    if(bandera){
        printf("No hay trabajos asignados\n");
    }
    __fpurge(stdin);
    getchar();

}

int buscarLibreTrabajo(eTrabajo trabajos[], int tamtra){
    int posicion = -1;
        for(int i = 0 ; i < tamtra ; i++){
            if(trabajos[i].isEmpty == 1){
                posicion = i;
                break;
            }
        }
    return posicion;
}

int altaTrabajos(int id, eMoto motos[], int tammot, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTipo tipos [], int tamtip, eTrabajo trabajos[], int tamtra, eCliente clientes[], int tamcli){
    int retorno = 0;
    int lugar;
    int bucle = 1;

    lugar = buscarLibreTrabajo(trabajos, tamtra);
    eTrabajo auxTrabajo;

    if(lugar == -1){

    printf("\nNo hay lugar para mas trabajos. \n\n");
    __fpurge(stdin);
    getchar();

    }else{

    auxTrabajo.id = id;

        system("clear");
        printf("****** Alta trabajos ****** \n\n");
        printf("A que moto desea asignarle un trabajo \n\n");
        listarMotos(motos, tammot, tipos, tamtip, colores, tamcol, clientes, tamcli);

    while(bucle == 1){
        scanf("%d", &auxTrabajo.idMoto);
        if(buscarMoto(auxTrabajo.idMoto, motos, tammot) == -1){
            printf("Moto no encontrada, reingrese ID: ");
        }else{
            bucle = 0;
        }
    }

    system("clear");
    printf("****** Alta trabajos ****** \n\n");
    printf("Que servicio desea para el trabajo \n\n");
    mostrarServicios(servicios, tamser);
    auxTrabajo.idServicio = validarOpcion( 20003, 20000, "\nIngrese ID: ",  "\nID incorrecto, reintente ");

    system("clear");
    printf("****** Alta trabajos ****** \n\n");
    printf("Ingrese fecha para el trabajo DD/MM/AAAA: ");
    //scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
    pedirFecha(&auxTrabajo.fecha);

    auxTrabajo.isEmpty = 0;
    trabajos[lugar] = auxTrabajo;


    printf("\nTrabajo agregado con exito.!");
    __fpurge(stdin);
    getchar();

    retorno = 1;
    }

    return retorno;
}

void inicializarTrabajos(eTrabajo trabajos[] ,int tamtra){
     for(int i = 0 ; i < tamtra ; i++){
        trabajos[i].isEmpty = 1;
     }
}
