#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"

int cargarColor(char descripcion[], int id, eColor colores[], int tamcol){
    int retorno = 0;
    for(int i = 0; i < tamcol ; i++){
        if(colores[i].id == id){
            strcpy(descripcion, colores[i].nombreColor);
            retorno = 1;
        }
    }
    return retorno;
}

void inicializarColores(eColor colores[], int tamcol){
     for(int i = 0 ; i < tamcol ; i++){
        colores[i].isEmpty = 1;
     }
}

void mostrarColores(eColor colores[], int tamcol){
    system("clear");
    printf("**** Colores de moto ****\n\n");
    printf("ID           Descripcion\n\n");

    for(int i = 0 ; i < tamcol ; i++){
        if(colores[i].isEmpty == 0){
            printf("%d        %10s\n", colores[i].id, colores[i].nombreColor);
        }
    }
}
