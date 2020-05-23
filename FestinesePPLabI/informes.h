#include "notebooks.h"
#include "tipos.h"
#include "marcas.h"
#include "trabajos.h"

/** \brief Funcion para mostrar un menu de opciones
 *
 * \param -
 * \param -
 * \return Devuelve la letra elegida
 *
 */

char menuInformes();

//-------------------------------------------------------------------------------------------------------

void informeNotebooks(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente);
//-----------------------------------------------------------------------------------------------------------------------
/** \brief Funcion para mostrar las notebooks de un tipo elegido por el usuario
 *
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return
 *
 */

void listarNotebooksDeTipo(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);

//-----------------------------------------------------------------------------------------------------
void listarNotebooksDeMarca(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);

void informarMenorPrecioNotebook(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente);

void informarNotebooksXMarcas(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente);

void mostrarNotebooksPorMarcaYTipo(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo);

int obtenerTotalMarcasNotebook (int idMarca, eNotebook notebooks[], int tamN);
void informarMayorMarca (eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca);

void informarTrabajosDeNotebook (eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNote, eTipo tipos[], int tamTipo, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);

void informarNotebooksDeServicio(eNotebook notebooks[], int tamN, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTr);

void listarNotebooksPorFechaTrabajo(eNotebook notebooks[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ);

void preciosServiciosNotebook(eNotebook notebooks[], int tamNotebook, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarca, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicio, eCliente clientes[], int tamCliente);
