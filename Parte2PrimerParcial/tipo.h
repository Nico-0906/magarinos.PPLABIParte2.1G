#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    int isEmpty;

}eTipo;


#endif // TIPO_H_INCLUDED

/**
* \brief carga el tipo de una moto segun el Id tipo que tenga en la variable nombre
* \param descripcion direccion donde guardar el nombre del tipo
* \param id del tipo que se desea cargar
* \param tipos estructura de tios de donde se sacan los datos
* \param tamaño de la estructura
* \return retorna 1 si se cargo con exito o 0 si no
*/
int cargarTipo(char descripcion[], int id, eTipo tipos[], int tamtip);

/**
* \brief inicializa la estructura colocando todos los isEmpty en 1
* \param estructura que se desea inicializar
* \param tamaño de la estructura
*/
void inicializarTipo(eTipo tipos[], int tamtip);

/**
* \brief muestra la lista de tipos
* \param estructura de tipos ue se desea mostrar
* \param tamaño de la estructura
*/
void mostrarTipos(eTipo tipos[], int tamtip);
