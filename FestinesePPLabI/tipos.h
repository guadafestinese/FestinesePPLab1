#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;
#endif // TIPOS_H_INCLUDED


/** \brief Funcion para mostrar una lista de los tipos de notebook
 *
 * \param eTipo tipos[], array de tipos
 * \param int tamTipos
 * \return -
 *
 */

void listarTipos(eTipo tipos[], int tamTipos);

/** \brief Funcion para relacionar estructuras con la descripcion y el ID
 *
 * \param char descripcion[], cadena de caracteres de la descripcion
 * \param int id
 * \param eTipo tipos[], array de tipos
 * \param int tamTipo, tamaño del array de tipos
 * \return -
 *
 */
void cargarDescripcionTipo (char descripcion[], int id, eTipo tipos[], int tamTipo);


