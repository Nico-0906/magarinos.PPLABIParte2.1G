#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/**
* \brief carga la moto segun el Id en la variable descripcion
* \param vector donde se desea guardar el nombre
* \param id de la moto que se desea cargar
* \param vector de motos donde buscar la moto ingresada
* \param tamaño del vetor motos
* \return retorna 1 si se cargo con exito o 0 si no
*/
int cargarMoto(char nombreMarca[], int id, eMoto motos[], int tammot);

/**
* \brief carga el servicio de una moto segun el Id servicio que tenga en la variable descripcion
* \param nombreservicio direccion donde guardar el nombre del servicio
* \param id del servicio que se desea cargar
* \param servicios estructura de servicios de donde se sacan los datos
* \param tamaño de la estructura
* \return retorna 1 si se cargo con exito o 0 si no
*/
int cargarServicio(char nombreServicio[], int id, eServicio servicios[], int tamser);

/**
* \brief se muestra el trabajo indicado
* \param estructura que se desea mostrar
* \param estructura de motos para buscar datos
* \param tamaño de estructura motos
* \param estructura de servicios para buscar datos
* \param tamaño de estructura servicios
*/
void mostrarTrabajo(eTrabajo trabajos, eMoto motos[], int tammot, eServicio servicios[], int tamser);

/**
* \brief se muestra el listado de los trabajos
* \param estructura que se desea mostrar
* \param estructura de motos para buscar datos
* \param tamaño de estructura motos
* \param estructura de servicios para buscar datos
* \param tamaño de estructura servicios
*/
void listarTrabajos(eTrabajo trabajos[], int tamtra, eMoto motos[], int tammot, eServicio servicios[], int tamser);

/**
* \brief busca lugar libre en la estructura trabajos
* \param trabajos estructura donde buscar lugar
* \param tamaño de la estructura
* \return retorna la posicion del lugar encontrado o -1 si no se encontro
*/
int buscarLibreTrabajo(eTrabajo trabajos[], int tamtra);

/**
* \brief para dar de alta nuevos trabajos
* \param id para asignarle al nuevo trabajo
* \param estructura de motos para buscar datos
* \param tamaño de estructura motos
* \param estructura de colores para usar datos
* \param tamaño de estructura colores
* \param estructura de servicios para usar datos
* \param tamaño de la estructura servicios
* \param estructura de tipos para usar datos
* \param tamaño de estructura de tipos
* \param estructura de trabajos para usar datos
* \param tamaño de estructura de trabajos
* \return retorna 1 si se pudo dar de alta o 0 si no se pudo
*/
int altaTrabajos(int id, eMoto motos[], int tammot, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTipo tipos [], int tamtip, eTrabajo trabajos[], int tamtra, eCliente clientes[], int tamcli);

/**
* \brief inicializa la estructura trabajos dejando los isEmpty en 1
* \param estructura que se desea inicializar
* \param tamaño de la estructura trabajos
*/
void inicializarTrabajos(eTrabajo trabajos[],int tamtra);
