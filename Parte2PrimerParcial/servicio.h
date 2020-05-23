#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
    int isEmpty;

}eServicio;

#endif // SERVICIO_H_INCLUDED

/**
* \brief lista los servicios existentes
* \param vector de ervicios ue se desean mostrar
* \param tamaño del vector
*/
void mostrarServicios(eServicio servicios[], int tamser);

/**
* \brief inicializa la estructura servicios poniendo los isEmpty en 0
* \param servicios es la estructura que se desea inicializar
* \param tamaño de la estructura
*/
void inicializarServicios(eServicio servicios[], int tamser);
