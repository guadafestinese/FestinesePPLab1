#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[205];
    float precio;
}eServicio;
#endif // SERVICIOS_H_INCLUDED

/** \brief Funcion para mostrar una lista de los servicios
 *
 * \param eServicio servicios[], array de servicios
 * \param int tamS, tamaño del array
 * \return -
 *
 */

void listarServicios(eServicio servicios[], int tamS);
//--------------------------------------------------------------------------------------------------
/** \brief Funcion para buscar un servicio por su ID
 *
 * \param int id, id a buscar
 * \param eServicio servicios[], array de servicios
 * \param int tamServ, tamaño del array de servicios
 * \return devuelve -1 si no encuentra el ID, y si lo encuentra devuelve el ID
 *
 */

int buscarServicio(int id, eServicio servicios[], int tamServ);
