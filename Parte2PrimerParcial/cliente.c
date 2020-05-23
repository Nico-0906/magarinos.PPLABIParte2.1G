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
#include "cliente.h"


int cargarCliente(char nombre[], int id, eCliente clientes[], int tamcli){
    int retorno = 0;
    for(int i = 0; i < tamcli ; i++){
        if(clientes[i].id == id){
            strcpy(nombre, clientes[i].nombre);
            retorno = 1;
        }
    }
    return retorno;
}
