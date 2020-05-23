#ifndef HERRAMIENTAS_H_INCLUDED
#define HERRAMIENTAS_H_INCLUDED



#endif // HERRAMIENTAS_H_INCLUDED


/**
* \brief menu de opciones del programa
* \return retorna la opcion elegida por el usuario
*/
int menuOpciones();

/**
* \brief pide al usuario que ingrese una fecha y la guarda en un vector fecha
* \param estructura de fecha donde guardar la fecha
*/
void pedirFecha(eFecha fechas[]);

/**
* \brief valida una opcion numerica entre un maximo y un minimo con mensajes
* \param maximo permitido
* \param minimo permitido
* \param mensaje a enviar para pedir opcion
* \param mensaje de error de opcion erronea
* \return retorna la opcion valida ingresada
*/
int validarOpcion(int max, int min,char mensaje[], char mensajeError[]);

/**
* \brief toma una cadena de caracteres y la pasa a formato Nombre
* \param cadena que se desea formatear
* \param tamaño de la cadena
*/
void tipoNombre(char vec[], int tam);

/**
* \brief solo toma una cadena de caracteres y la guarda
* \param cadena donde se desea guardar lo ingresado
* \param tamaño de la cadena
*/
void getStr(char cadena[], int tam);


/**
* \brief solicita se ingrese una cadena de solo letras
* \param vector donde se guardara la cadena ingresada
* \param tamaño del vector de cadena
* \return retorna 1 si salio todo bien o 0 si no
*/
int getNombre(char nombre[], int tam);

/**
* \brief obtiene un caracter s o n para confirmaciones
* \param puntero a caracter donde se desea guardar la respuesta
*/
void getCharConfirmValidado(char* caracter);

