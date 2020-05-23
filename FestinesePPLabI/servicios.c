#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"


void listarServicios(eServicio servicios[], int tamS)
{
    system("cls");
    printf("\n*** Listado de servicios ***\n\n");
    printf("ID          DESCRIPCION       PRECIO\n");
    for (int i=0; i< tamS; i++)
    {
       printf("%d    %15s     %.2f\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }
    printf("\n\n");
}
//-------------------------------------------------------------------------

int buscarServicio(int id, eServicio servicios[], int tamServ){

  int indice= -1;

    for(int i=0; i<tamServ; i++)
    {
        if(servicios[i].id == id)
        {
            indice= i;
            break;
        }
    }
  return indice;
}

//--------------------------------------------------------------------




