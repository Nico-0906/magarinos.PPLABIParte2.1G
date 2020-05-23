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
#include "herramientas.h"


void inicializarServicios(eServicio servicios[], int tamser){
     for(int i = 0 ; i < tamser ; i++){
        servicios[i].isEmpty = 1;
     }
}

void mostrarServicios(eServicio servicios[], int tamser){
    printf("**** Servicios ****\n\n");
    printf("ID          Descripcion     Precio\n\n");

    for(int i = 0 ; i < tamser ; i++){
        if(servicios[i].isEmpty == 0){
            printf("%d        %10s     %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
    }
}
