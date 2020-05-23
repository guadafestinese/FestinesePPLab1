
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebooks.h"

int menu(){

    int opcion;

    system("cls");
    printf("*** Menu de opciones ***\n");
    printf("1) Alta notebook\n");
    printf("2) Modificar notebook\n");
    printf("3) Baja notebook\n");
    printf("4) Listar notebooks\n");
    printf("5) Listar Marcas\n");
    printf("6) Listar tipos\n");
    printf("7) Listar servicios\n");
    printf("8) Alta trabajo\n");
    printf("9) Listar trabajos\n");
    printf("10) Informes\n");
    printf("11) Salir\n");

    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
//------------------------------------------------------
void myFgets (char nombre [], int cant)
{
    fflush (stdin);
    fgets(nombre, cant, stdin);
    nombre[strcspn(nombre, "\r\n")] = 0;
}
//---------------------------------------------------------


int buscarLibreNotebook(eNotebook notebooks[], int tam)
{
	int indice = -1;

	for (int i=0; i< tam; i++)
	{
 		if(notebooks[i].isEmpty == 1)
		{
    			indice = i;
    			break;
		}
	}
  return indice;
}


//---------------------------------------------------------

int buscarLibreCliente(eCliente clientes[], int tamCliente)
{
	int indice = -1;

	for (int i=0; i< tamCliente; i++)
	{
 		if(clientes[i].isEmpty == 1)
		{
    			indice = i;
    			break;
		}
	}
  return indice;
}
//---------------------------------------------------------
int altaNotebook(int idNote, eNotebook notebooks[], int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas, eCliente clientes[], int tamCliente){


    int todoOk=0;
    eNotebook auxNotebook;
    int indiceNote;

    system("cls");
    printf("*** ALTA NOTEBOOK *** \n");

    indiceNote= buscarLibreNotebook(notebooks, tam);


    if(indiceNote == -1)
    {
        printf("No hay lugar para otra notebook\n");
        system("pause");
    }else{

        auxNotebook.id = idNote;

        printf("Ingrese modelo: \n");
        fflush(stdin);
        myFgets(auxNotebook.modelo, 20);


        listarMarcas(marcas, tamMarcas);
        printf("Ingrese idMarca: \n");
        fflush(stdin);
        scanf("%d", &auxNotebook.idMarca);
        while(auxNotebook.idMarca<1 || auxNotebook.idMarca>4)
        {
            listarMarcas(marcas, tamMarcas);
            printf("Error, no ingreso un id valido. Ingrese id marca: \n");
            fflush(stdin);
            scanf("%d", &auxNotebook.idMarca);
        }

            listarTipos(tipos, tamTipos);
            printf("Ingrese idTipo: \n");
            scanf("%d", &auxNotebook.idTipo);
            while(auxNotebook.idTipo <1 || auxNotebook.idTipo>4)
            {
                listarTipos(tipos, tamTipos);
                printf("Error, no ingreso un id valido. Ingrese id tipo: \n");
                fflush(stdin);
                scanf("%d", &auxNotebook.idTipo);
            }


                printf("Ingrese precio: \n");
                scanf("%f", &auxNotebook.precio);
                while(auxNotebook.precio <0)
                {
                    printf("Error, ingrese un precio valido mayor a 0\n");
                    scanf("%f", &auxNotebook.precio);
                }


                mostrarClientes(clientes, tamCliente);
                printf("Elija un cliente por su ID: \n");
                fflush(stdin);
                scanf("%d", &auxNotebook.idCliente);
                while(buscarCliente(auxNotebook.idCliente, clientes, tamCliente) == -1)
                {
                    mostrarClientes(clientes, tamCliente);
                    printf("Error, ingrese ID valido: \n");
                    fflush(stdin);
                    scanf("%d", &auxNotebook.idCliente);
                }


                auxNotebook.isEmpty = 0;
                notebooks[indiceNote] = auxNotebook;

                todoOk = 1;

        }

    return todoOk;

}


//---------------------------------------------------------------------------
int buscarNotebook(int id, eNotebook notebooks[], int tam){

  int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].id == id)
        {
            indice= i;
            break;
        }
    }
  return indice;
}

//------------------------------------------------------------
void mostrarNotebook(eNotebook note, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente){

        char descripcionMarca [20];
        char descripcionTipo[20];
        char nombreCliente[20];

        cargarDescripcionMarca(descripcionMarca, note.idMarca, marcas, tamMarca);
        cargarDescripcionTipo(descripcionTipo, note.idTipo, tipos, tamTipo);
        cargarNombreCliente(nombreCliente, note.idCliente, clientes, tamCliente);

        printf("%d 	%10s   %10s   %10s    %10s   %.2f\n", note.id, nombreCliente, note.modelo, descripcionMarca, descripcionTipo, note.precio);


}

//-----------------------------------------------------------------
void mostrarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente){

 int flag=0;
 system("cls");
 printf("****** LISTA NOTEBOOKS ******\n");
 printf("ID	     CLIENTE    MODELO	        MARCA     TIPO	     PRECIO	\n");

    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].isEmpty == 0)
        {
            mostrarNotebook(notebooks[i], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            flag=1;
        }

    }

    if(flag==0)
    {
        printf("No hay notebooks que mostrar\n");
    }

}

//--------------------------------------------------------
void modificarNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente){

    int id;
    char confirma;


    system("cls");
    printf("*** Modificar notebook ***\n");
    mostrarNotebooks(notebooks, tam, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
    printf("Ingrese id de la notebook a modificar: \n");
    scanf("%d", &id);

    id = buscarNotebook(id, notebooks, tam);

    if(id == -1)
    {
        printf("No hay registro de una notebook con el id %d\n", id);
        system("pause");
    }else{
        mostrarNotebook(notebooks[id], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);

        printf("Modifica notebook? Ingrese s o n \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's'){

           switch(menuModificar()){

            case 1:
                printf("Ingrese nuevo precio (mayor a 0): \n");
                scanf("%f", &notebooks[id].precio);
                while(notebooks[id].precio <0)
                    {
                        printf("Error, ingrese un precio mayor a 0\n");
                        scanf("%f", &notebooks[id].precio);
                    }
                    printf("Se modifico el precio\n");
                    system("pause");
                break;

            case 2:
                listarTipos(tipos, tamTipo);
                printf("Ingrese el id del nuevo tipo: \n");
                scanf("%d", &notebooks[id].idTipo);
                while(notebooks[id].idTipo<5000|| notebooks[id].idTipo>5003)
                    {
                        listarTipos(tipos, tamTipo);
                        printf("Error, el id no es valido. Reingrese: \n");
                        scanf("%d", &notebooks[id].idTipo);
                    }
                printf("Se modifico el tipo\n");
                system("pause");
                break;

            case 3:
                printf("Salio\n");
                break;
            }//fin switch

        }else{
            printf("Se ha cancelado la operacion\n");
            system("pause");
        }
    }
}

void inicializarNotebooks(eNotebook notebooks[], int tam){
    for (int i=0; i<tam; i++)
    {
        notebooks[i].isEmpty = 1;
    }
}

//------------------------------------------------------------
int menuModificar(){
    int opcion;

    system("cls");
    printf("Opciones a modificar: \n");
    printf("1) Precio\n");
    printf("2) Tipo\n");
    printf("3) Salir\n");


    printf("Ingrese el numero de la opcion que desee: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//

void ordenarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente){

 eNotebook aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(notebooks[i].idMarca > notebooks[j].idMarca)
            {
                aux = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = aux;
            }else if(notebooks[i].idMarca == notebooks[j].idMarca && notebooks[i].precio > notebooks[j].precio)
            {
                aux = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = aux;
            }
        }//fin for j
    }//fin for i

    mostrarNotebooks(notebooks,tam, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
}


//------------------------------------------------------------

//-------------------------------------------------
void bajaNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente){
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("*** Baja notebook ***\n");
    mostrarNotebooks(notebooks, tam, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
    printf("Ingrese el id de la notebook: \n");
    scanf("%d", &id);

    indice = buscarNotebook(id, notebooks, tam);

    if(indice == -1)
    {
        printf("No hay registro de una notebook con el id %d\n", id);
    }else{
        mostrarNotebook(notebooks[indice], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
        printf("Confima baja? Ingrese s o n \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's'){
            notebooks[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n");
        }else{
            printf("Se ha cancelado la operacion\n");
        }
    }
}


