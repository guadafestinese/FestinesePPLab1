
#include "tipos.h"
#include "notebooks.h"
#include "marcas.h"
#include "servicios.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
typedef struct{
 int dia;
 int mes;
 int anio;
}eFecha;


typedef struct{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;
#endif // TRABAJO_H_INCLUDED

/** \brief
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array de notebooks
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \param eMarca marcas[], array de marcas
 * \param  int tamMarca, tamaño del array de marcas
 * \param eServicio servicios[], array de servicios
 * \param int tamServ, tamaño del array de servicios
 * \param eTrabajo trabajos[], array de trabajos
 * \param int tamTrabajo, tamaño del array de trabajos


 * \return Devuelve 1 si se cargo y 0 si no se cargo
 *
 */

int altaTrabajo(int id, eNotebook notebooks[], int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrabajo);

/** \brief Funcion para mostrar los trabajos

 * \param eTrabajo trabajos[], array de trabajos
 * \param int tam, tamaño del array de trabajos
 * \param eNotebook notebooks[], array de notebooks
 * \param int tamNote, tamaño del array de notebooks
 * \param eServicio servicios[], array de servicios
 * \param int tamServ, tamaño del array de servicios


 * \return -
 *
 */
void mostrarTrabajos(eTrabajo trabajos[], int tam, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ);

/** \brief Funcion para mostrar un solo trabajo

 * \param eTrabajo trabajo, estructura a mostrar
 * \param eNotebook notebooks[], array de notebooks
 * \param int tamNote, tamaño del array de notebooks
 * \param eServicio servicios[], array de servicios
 * \param int tamServ, tamaño del array de servicios


 * \return -
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ);

/** \brief Funcion para relacionar estructuras con ID

 * \param char descripcion[], descripcion a cargar
 * \param int id, id que se quiere relacionar
 * \param eServicio servicios[], array de servicios
 * \param int tam, tamaño del array de servicios

 * \return -
 *
 */
int cargarDescripcionServicioTrabajo (char descripcion[], int id, eServicio servicios[], int tam);

/** \brief Funcion para relacionar estructuras con ID

 * \param char descripcion[], descripcion a cargar
 * \param int id, id que se quiere relacionar
 * \param eNotebook notebooks[], array de notebooks
 * \param int tam, tamaño del array de notebooks

 * \return -
 *
 */
int cargarDescripcionNotebookTrabajo (char descripcion[], int id, eNotebook notebooks[], int tam);

/** \brief Funcion para inicializar los trabajos, pone isEmpty en 1
 *
 * \param eTrabajo trabajos[], array de trabajos
 * \param int tam, tamaño del array de trabajos
 * \return -
 *
 */

void inicializarTrabajos(eTrabajo trabajos[], int tam);

