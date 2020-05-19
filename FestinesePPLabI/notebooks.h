#include "tipos.h"
#include "marcas.h"

#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
}eNotebook;

#endif // NOTEBOOK_H_INCLUDED


/** \brief Funcion para dar de alta una notebook
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array de notebooks
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \param eMarca marcas[], array de marcas
 * \param  int tamMarca, tamaño del array de marcas
 * \return
 *
 */

int altaNotebook(int id, eNotebook notebooks[], int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas);

/** \brief Funcion para modificar notebooks
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array de notebooks
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \param eMarca marcas[], array de marcas
 * \param  int tamMarca, tamaño del array de marcas
 * \return -
 *
 */

void modificarNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca);

/** \brief Funcion para mostrar un menu de opciones
 *
 * \param -
 * \param  -
 * \return Devuelve un int que es la opcion elegida
 *
 */

int menuModificar();

/** \brief Funcion para ordenar notebooks
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array de notebooks
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \param eMarca marcas[], array de marcas
 * \param  int tamMarca, tamaño del array de marcas
 * \return
 *
 */

void ordenarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca);

/** \brief Funcion para validar cadenas de caracteres
 *
 * \param char nombre[], array a validar
 * \param int cant, tamaño del array
 * \return
 *
 */

void myFgets (char nombre [], int cant);

/** \brief Funcion para buscar una notebook mediante su ID
 *
 * \param int id
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array
 * \return -

 */

int buscarNotebook(int id, eNotebook notebooks[], int tam);

/** \brief Funcion para mostrar todas las notebooks cargadas
 *
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array de notebooks
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \param eMarca marcas[], array de marcas
 * \param  int tamMarca, tamaño del array de marcas
 * \return -
 *
 */

void mostrarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca);

/** \brief Funcion para inicializar las estructuras de notebook en isEmpty=1
 *
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array
 * \return -
 *
 */

void inicializarNotebooks(eNotebook notebooks[], int tam);

/** \brief Funcion para mostrar una sola notebook
 * \param eNotebook notebook, la estructura a mostrar
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \param eMarca marcas[], array de marcas
 * \param  int tamMarca, tamaño del array de marcas
 * \return -
 *
 */
void mostrarNotebook(eNotebook note, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca);

/** \brief Funcion para mostrar un menu de opciones
 *
 * \param -
 * \param -
 * \return devuelve un int, es la opcion elegida
 *
 */

int menu();


/** \brief Funcion para hacer una baja logica de notebook
 *
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array de notebooks
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \param eMarca marcas[], array de marcas
 * \param  int tamMarca, tamaño del array de marcas
 * \return
 *
 */

void bajaNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca);


