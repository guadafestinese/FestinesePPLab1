#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"



void listarTipos(eTipo tipos[], int tamTipos)
{
    system("cls");
    printf("\n*** Listado de tipos ***\n\n");
    printf("   Id       DESCRIPCION\n");
    for (int i=0; i< tamTipos; i++)
    {
       printf("    %d    %10s\n",tipos[i].id, tipos[i].descripcion);
    }
    printf("\n\n");
}

//----------------------------------------------------------------------
void cargarDescripcionTipo (char descripcion[], int id, eTipo tipos[], int tamTipo){

	for (int i=0; i<tamTipo; i++)
	{
        if (tipos[i].id == id)
        {
            strcpy(descripcion, tipos[i].descripcion);
        }
	}

}


