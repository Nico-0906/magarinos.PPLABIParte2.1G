#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "cliente.h"

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    int cilindrada;
    int isEmpty;

}eMoto;

#endif // MOTO_H_INCLUDED

/**
* \brief da el mensaje para elegir cilindrada y las opciones y las guarda
* \return retorna la opcion de cilindrada elegida
*/
int cargarCilindrada();

/**
* \brief permite modificar una estructura de motos
* \param estructura de motos que se quiere modificar
* \param tamaño de estructura motos
* \param estructura de tipos para usar datos
* \param tama{o de estructura tipos
* \param estructura de colores para usar datos
* \param tamaño de estructura colores
*/
void modificarMoto(eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);

/**
* \brief busca una moto por el id
* \param id que se quiere buscar
* \param estructura de motos donde buscar
* \param tamaño de la estructura motos
* \return retorna la posicion de la moto buscada por id
*/
int buscarMoto(int id, eMoto motos[], int tammot);

/**
* \brief da de baja a una moto
* \param estructura de motos para dar de baja
* \param tamaño de dicha estructura
* \param estructura de tipos para usar datos
* \param tama{o de estructura tipos
* \param estructura de colores para usar datos
* \param tamaño de estructura colores
* \return retorna 1 si se pudo dar de baja o 0 si no se pudo
*/
int bajaMoto(eMoto motos[] , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);

/**
* \brief muestra una sola moto
* \param estructura de motos para mostrar
* \param tamaño de dicha estructura
* \param estructura de tipos para usar datos
* \param tama{o de estructura tipos
* \param estructura de colores para usar datos
* \param tamaño de estructura colores
*/
void mostrarMoto(eMoto motos , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);

/**
* \brief lista todas las motos dadas de alta
* \param estructura de motos para mostra
* \param tamaño de estructura motos
* \param estructura de tipos para usar datos
* \param tama{o de estructura tipos
* \param estructura de colores para usar datos
* \param tamaño de estructura colores
*/
void listarMotos(eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);

/**
* \brief da de alta nueva moto
* \param id de la nueva moto a dar de alta
* \param estructura de motos para dar de alta
* \param tamaño de dicha estructura
* \param estructura de tipos para usar datos
* \param tama{o de estructura tipos
* \param estructura de colores para usar datos
* \param tamaño de estructura colores
* \return retorna 1 si se pudo dar de alta o 0 si no se pudo
*/
int altaMoto(int idMoto, eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol);

/**
* \brief busca lugar disponible para nueva moto en isEmpty == 1
* \param vector donde se desea buscar lugar libre
* \param tamaño de vector
* \return retorna el lugar que se encontro o -1 si no se encontro lugar
*/
int buscarLibreMoto(eMoto motos[], int tammot);

/**
* \brief inicializa la estructura motos dejando los isEmpty en 1
* \param estructura que se desea inicializar
* \param tamaño de la estructura
*/
void inicializarMoto(eMoto motos[], int tammot);
