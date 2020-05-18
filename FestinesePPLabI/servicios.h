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


