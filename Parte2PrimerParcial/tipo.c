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

int cargarTipo(char descripcion[], int id, eTipo tipos[], int tamtip){
    int retorno = 0;
    for(int i = 0; i < tamtip ; i++){
        if(tipos[i].id == id){
            strcpy(descripcion, tipos[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;
}


void inicializarTipo(eTipo tipos[], int tamtip){
     for(int i = 0 ; i < tamtip ; i++){
        tipos[i].isEmpty = 1;
     }
}

void mostrarTipos(eTipo tipos[], int tamtip){
    system("clear");
    printf("**** Tipos de moto ****\n\n");
    printf("ID          Descripcion\n\n");

    for(int i = 0 ; i < tamtip ; i++){
        if(tipos[i].isEmpty == 0){
            printf("%d        %10s\n", tipos[i].id, tipos[i].descripcion);
        }
    }
}
