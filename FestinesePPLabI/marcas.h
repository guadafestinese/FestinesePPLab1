#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED
typedef struct{
    int id;
    char descripcion[20];
}eMarca;
#endif // MARCAS_H_INCLUDED

/** \brief Funcion para mostrar una lista de las marcas
 *
 * \param eMarca marcas[], array de marcas
 * \param int tamMarcas
 * \return -
 *
 */

void listarMarcas(eMarca marcas[], int tamMarcas);

/** \brief Funcion para relacionar estructuras con la descripcion y el ID
 *
 * \param char descripcion[], cadena de caracteres de la descripcion
 * \param int id
 * \param eMarca marcas[], array de marcas
 * \param int tamMarca, tamaño del array de marcas
 * \return -
 *
 */

void cargarDescripcionMarca (char descripcion[], int id, eMarca marcas[], int tamMarca);




