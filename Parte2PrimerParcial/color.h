#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
    int isEmpty;

}eColor;


#endif // COLOR_H_INCLUDED

/**
* \brief carga el color de una moto segun el Id color ue tenga en la variable descripcion
* \param descripcion direccion donde guardar el nombre del color
* \param id del color que se desea cargar
* \param colores estructura de colores de donde se sacan los datos
* \param tamaño de la estructura
* \return retorna 1 si se cargo con exito o 0 si no
*/
int cargarColor(char descripcion[], int id, eColor colores[], int tamcol);

/**
* \brief inicializa la estructura colores dejando todos los isEmpty en 0
* \param colores estructura que se desea inicializar
* \param tamaño de la estructura colores
*/
void inicializarColores(eColor colores[], int tamcol);

/**
* \brief muestra listado de colores
* \param colores estructura que se desea mostrar
* \param tamaño de la estructura que sedesea mostrar
*/
void mostrarColores(eColor colores[], int tamcol);
