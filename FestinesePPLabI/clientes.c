#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"

void mostrarCliente(eCliente cliente, int tamCliente){

    printf("%2d    %10s        %c\n", cliente.id, cliente.nombre, cliente.sexo);
}

//---------------------------------------------------------------------------------------
void mostrarClientes(eCliente clientes[], int tamCliente){

 int flag=0;
 system("cls");
 printf("****** LISTA CLIENTES ******\n");
 printf("ID	   NOMBRE     SEXO	\n");

    for(int i=0; i<tamCliente; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            mostrarCliente(clientes[i], tamCliente);
            flag=1;
        }

    }

    if(flag==0)
    {
        printf("No hay clientes que mostrar\n");
    }

}

//---------------------------------------------------------------------------------------
int buscarCliente(int id, eCliente clientes[], int tamCliente){

  int indice= -1;

    for(int i=0; i<tamCliente; i++)
    {
        if(clientes[i].id == id)
        {
            indice= i;
            break;
        }
    }
  return indice;
}

//---------------------------------------------------------------------------------------


int cargarNombreCliente(char nombre[], int id, eCliente clientes[], int tamCliente){

    int todoOk = 0;

    for (int i=0; i<tamCliente; i++)
    {
        if(clientes[i].id == id)
        {
            strcpy(nombre, clientes[i].nombre);
            todoOk =1;

        }
    }
    return todoOk;
}

//---------------------------------------------------------------------------------------
