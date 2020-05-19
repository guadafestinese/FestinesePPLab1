
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



int altaTrabajo(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrabajo){


    int todoOk=0;


    for(int i=0; i<tam; i++){
        if(trabajos[i].isEmpty == 1){
            mostrarNotebooks(notebooks, tam, tipos, tamTipos, marcas, tamMarcas);

            printf("Ingrese el ID de la notebook que desee: \n");
            scanf("%d", &trabajos[i].idNotebook);


            listarServicios(servicios, tamServ);
            printf("Ingrese el ID del servicio que desee: \n");
            scanf("%d", &trabajos[i].idServicio);
            while(trabajos[i].idServicio<1 || trabajos[i].idServicio >4)
            {
                listarServicios(servicios, tamServ);
                printf("Error, ingrese un ID valido\n");
                scanf("%d", &trabajos[i].idServicio);

            }

            printf("Ingrese dia: \n");
            scanf("%d", &trabajos[i].fecha.dia);
            while(trabajos[i].fecha.dia<1 || trabajos[i].fecha.dia>31)
            {
                printf("Error, ingrese un dia entre 1 y 31\n");
                scanf("%d", &trabajos[i].fecha.dia);
            }
            printf("Ingrese mes: \n");
            scanf("%d", &trabajos[i].fecha.mes);
            while(trabajos[i].fecha.mes<1 || trabajos[i].fecha.mes>12)
            {
                printf("Error, ingrese un dia entre 1 y 12\n");
                scanf("%d", &trabajos[i].fecha.mes);
            }
            printf("Ingrese anio: \n");
            scanf("%d", &trabajos[i].fecha.anio);
            while( trabajos[i].fecha.anio <1990 || trabajos[i].fecha.anio > 2020)
            {
                printf("Error, ingrese un anio correcto: \n");
                scanf("%d", &trabajos[i].fecha.anio);
            }




            trabajos[i].isEmpty = 0;
            trabajos[i].id = i+1;
            todoOk = 1;

            break;

        }
    }//fin for


   return todoOk;



}

void cargarDescripcionNotebookTrabajo (char descripcion[], int id, eNotebook notebooks[], int tam){

	for (int i=0; i<tam; i++)
    {
        if (notebooks[i].id == id)
        {
            strcpy(descripcion, notebooks[i].modelo);
        }
	}

}
void cargarDescripcionServicioTrabajo (char descripcion[], int id, eServicio servicios[], int tam){

	for (int i=0; i<tam; i++)
    {
        if (servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
        }
	}

}

void mostrarTrabajo(eTrabajo trabajo, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ)
{
 if(trabajo.isEmpty == 0)
    {
        char descripcionNote[20];
        char descripcionServ[20];


        cargarDescripcionNotebookTrabajo(descripcionNote, trabajo.idNotebook, notebooks, tamNote);
        cargarDescripcionServicioTrabajo(descripcionServ, trabajo.idServicio, servicios, tamServ);

        printf("    %d    %10s     %10s     %02d/%02d/%d\n", trabajo.id, descripcionNote, descripcionServ, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);

    }

}

void listarTrabajos(eTrabajo trabajos[], int tam, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ)
{
        int flag=0;

        system("cls");
        printf("\n*** Listado de trabajos ***\n\n");
        printf("   Id       NOTEBOOK     SERVICIO           FECHA\n");
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


