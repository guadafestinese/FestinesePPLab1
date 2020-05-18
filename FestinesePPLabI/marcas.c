#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marcas.h"

//-------------------------------------------------------------------------
void cargarDescripcionMarca (char descripcion[], int id, eMarca marcas[], int tamMarca){
//int todoOk=0;
	for (int i=0; i<tamMarca; i++){
	if (marcas[i].id == id){
	strcpy(descripcion, marcas[i].descripcion);
	//todoOk=1;
	}
	}
	//return todoOk;
}


//------------------------------------------------------
void listarMarcas(eMarca marcas[], int tamMarcas)
{
    system("cls");
    printf("\n*** Listado de marcas ***\n\n");
    printf("   Id       DESCRIPCION\n");
    for (int i=0; i< tamMarcas; i++)
    {
       printf("    %d    %10s\n",marcas[i].id, marcas[i].descripcion);
    }
    printf("\n\n");
}

