#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct {
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

#endif // CLIENTES_H_INCLUDED
//------------------------------------------------------------------------------------------------------------------------
/** \brief Funcion para mostrar un cliente
 *
 * \param eCliente cliente
 * \param int tamCliente
 * \return -
 *
 */

void mostrarCliente(eCliente cliente, int tamCliente);
//------------------------------------------------------------------------------------------------------------------------
/** \brief Funcion para mostrar todos los clientes
 *
 * \param eCliente clientes[], array de clientes
 * \param int tamCliente, tamaño del array
 * \return -
 *
 */

void mostrarClientes(eCliente clientes[], int tamCliente);
//------------------------------------------------------------------------------------------------------------------------
/** \brief Funcion para buscar un cliente por su ID
 *
 * \param int id, id a buscar
 * \param eCliente clientes[], array de clientes
 * \param int tamCliente, tamaño del array
 * \return devuelve -1 si no lo encuentra, y el numero de ID si lo encuentra
 *
 */

int buscarCliente(int id, eCliente clientes[], int tamCliente);
//------------------------------------------------------------------------------------------------------------------------

/** \brief Funcion para cargar el nombre del cliente relacionando con estructura de notebooks
 *
 * \param char nombre[], nombre a cargar
 * \param int id, idCliente de la notebook
 * \param eCliente clientes[], array de clientes
 * \param int tamCliente, tamaño del array de clientes
 * \return
 *
 */

int cargarNombreCliente(char nombre[], int id, eCliente clientes[], int tamCliente);
