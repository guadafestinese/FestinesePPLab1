
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajos.h"
#include "notebooks.h"

void inicializarTrabajos(eTrabajo trabajos[], int tam){
	for (int i=0; i<tam; i++)
	{
	   trabajos[i].isEmpty = 1;
	}
}
int buscarLibreTrabajo (eTrabajo trabajos[], int tamTr)
{
    int indice= -1;

    for (int i=0; i<tamTr; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaTrabajo(int id, eNotebook notebooks[], int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrabajo, eCliente clientes[], int tamCliente){

    int todoOk=0;
    int indice;
    eTrabajo nuevoTrabajo;

    system("cls");
    printf("*** ALTA TRABAJO ***\n");

    indice = buscarLibreTrabajo(trabajos, tamTrabajo);
    if(indice == -1){
        printf("No hay lugar para otro trabajo\n");
        system("pause");
    }else{
            mostrarNotebooks(notebooks, tam, tipos, tamTipos, marcas, tamMarcas, clientes, tamCliente);

            printf("Ingrese el ID de la notebook que desee: \n");
            scanf("%d", &nuevoTrabajo.idNotebook);

            listarServicios(servicios, tamServ);
            printf("Ingrese el ID del servicio que desee: \n");
            scanf("%d", &nuevoTrabajo.idServicio);
            while(nuevoTrabajo.idServicio<1 || nuevoTrabajo.idServicio >4)
            {
                listarServicios(servicios, tamServ);
                printf("Error, ingrese un ID valido\n");
                scanf("%d", &nuevoTrabajo.idServicio);

            }

            printf("Ingrese dia: \n");
            scanf("%d", &nuevoTrabajo.fecha.dia);
            while(nuevoTrabajo.fecha.dia<1 || nuevoTrabajo.fecha.dia>31)
            {
                printf("Error, ingrese un dia entre 1 y 31\n");
                scanf("%d", &nuevoTrabajo.fecha.dia);
            }
            printf("Ingrese mes: \n");
            scanf("%d", &nuevoTrabajo.fecha.mes);
            while(nuevoTrabajo.fecha.mes<1 || nuevoTrabajo.fecha.mes>12)
            {
                printf("Error, ingrese un dia entre 1 y 12\n");
                scanf("%d", &nuevoTrabajo.fecha.mes);
            }
            printf("Ingrese anio: \n");
            scanf("%d", &nuevoTrabajo.fecha.anio);
            while( nuevoTrabajo.fecha.anio <1990 || nuevoTrabajo.fecha.anio > 2020)
            {
                printf("Error, ingrese un anio correcto: \n");
                scanf("%d", &nuevoTrabajo.fecha.anio);
            }
            nuevoTrabajo.isEmpty = 0;
            nuevoTrabajo.id = id;

            trabajos[indice] = nuevoTrabajo;
            todoOk = 1;

        }

   return todoOk;
}

int cargarModeloNotebookTrabajo (char modelo[], int id, eNotebook notebooks[], int tam){

    int todoOk =0;
	for (int i=0; i<tam; i++)
    {
        if (notebooks[i].id == id)
        {
            strcpy(modelo, notebooks[i].modelo);
            todoOk =1;
        }
	}
    return todoOk;
}
int cargarDescripcionServicioTrabajo (char descripcion[], int id, eServicio servicios[], int tam){

    int todoOk =0;
	for (int i=0; i<tam; i++)
    {
        if (servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
             todoOk =1;
        }
	}
	return todoOk;
}

void mostrarTrabajo(eTrabajo trabajo, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ)
{
        char modeloNote[20];
        char descripcionServ[20];

        cargarModeloNotebookTrabajo(modeloNote, trabajo.idNotebook, notebooks, tamNote);
        cargarDescripcionServicioTrabajo(descripcionServ, trabajo.idServicio, servicios, tamServ);

        printf("%2d      %10s       %15s     %02d/%02d/%d\n", trabajo.id,modeloNote, descripcionServ, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);

}

void mostrarTrabajos(eTrabajo trabajos[], int tam, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ)
{
	int flag=0;

	system("cls");
	printf("\n*** Listado de trabajos ***\n\n");
	printf("ID            NOTEBOOK         SERVICIO        FECHA\n");
	for (int i=0; i< tam; i++)
	{
         if(trabajos[i].isEmpty == 0)
         {
                mostrarTrabajo(trabajos[i], notebooks, tamNote, servicios, tamServ);
                flag=1;
         }
    }


	if(flag==0)
	{
		printf("No hay trabajos que mostrar\n");
	}
	printf("\n\n");
}


