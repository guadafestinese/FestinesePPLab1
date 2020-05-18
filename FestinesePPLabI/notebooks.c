
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
printf("10) Salir\n");

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
/*
int buscarLibre(eNotebook notebooks[], int tam)
{
    int maxId = 1;
	for (int i=0; i < tam; i++)
	{
	    if(notebooks[i].id > maxId) {
            maxId = notebooks[i].id;
	    }
	}
  return maxId + 1;
}
*/

int buscarLibre(eNotebook notebooks[], int tam)
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
int altaNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas){

    int i;

    int todoOk=0;

    eNotebook auxNotebook;


    for(i=0; i<tam; i++){
        if(notebooks[i].isEmpty == 1){


            printf("Ingrese modelo: \n");
            fflush(stdin);
            myFgets(auxNotebook.modelo, 20);


            listarMarcas(marcas, tamMarcas);
            printf("Ingrese idMarca: \n");
            fflush(stdin);
            scanf("%d", &auxNotebook.idMarca);
            while(auxNotebook.idMarca<1 || auxNotebook.idMarca>4){
                listarMarcas(marcas, tamMarcas);
                printf("Error, no ingreso un id valido. Ingrese id marca: \n");
                fflush(stdin);
                scanf("%d", &auxNotebook.idMarca);
            }

            listarTipos(tipos, tamTipos);
            printf("Ingrese idTipo: \n");
            scanf("%d", &auxNotebook.idTipo);
            while(auxNotebook.idTipo <1 || auxNotebook.idTipo>4){
                listarTipos(tipos, tamTipos);
                printf("Error, no ingreso un id valido. Ingrese id tipo: \n");
                fflush(stdin);
                scanf("%d", &auxNotebook.idTipo);
            }

            printf("Ingrese precio: \n");
            scanf("%f", &auxNotebook.precio);


            auxNotebook.isEmpty = 0;
            auxNotebook.id = i+1;
            todoOk = 1;
            notebooks[i] = auxNotebook;
            break;

        }
    }//fin for


   return todoOk;



}


//---------------------------------------------------------------------------
int buscarNotebook(int id, eNotebook notebooks[], int tam){

int indice= -1;

for(int i=0; i<tam; i++){
if(notebooks[i].id == id){
indice= i;
break;
}
}
return indice;
}

//------------------------------------------------------------
void mostrarNotebook(eNotebook note, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca)
{
 if(note.isEmpty == 0){
    char descripcionMarca [20];
	char descripcionTipo[20];
    cargarDescripcionMarca(descripcionMarca, note.idMarca, marcas, tamMarca);
    cargarDescripcionTipo(descripcionTipo, note.idTipo, tipos, tamTipo);

    printf("%d 	%10s   %10s    %10s   %.2f\n", note.id, note.modelo, descripcionMarca, descripcionTipo, note.precio);
    }

}

//-----------------------------------------------------------------
void mostrarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca){
    int flag=0;

system("cls");
printf("****** LISTA NOTEBOOKS ******\n");
printf("ID	      Modelo	  Marca      	Tipo	 Precio	\n");

for(int i=0; i<tam; i++){

mostrarNotebook(notebooks[i], tipos, tamTipo, marcas, tamMarca);
flag=1;
}

if(flag==0){
printf("No hay notebooks que mostrar\n");
}

}

//--------------------------------------------------------
void modificarNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca){

    int id;

    char confirma;
    //eNotebook auxNotebook;


    system("cls");
    printf("*** Modificar notebook ***\n");
    mostrarNotebooks(notebooks, tam, tipos, tamTipo, marcas, tamMarca);
    printf("Ingrese id: \n");
    scanf("%d", &id);

    id = buscarNotebook(id, notebooks, tam);

    if(id == -1){
        printf("No hay registro de una notebook con el id %d\n", id);
    }else{
        mostrarNotebook(notebooks[id], tipos, tamTipo, marcas, tamMarca);

        printf("Modifica notebook? \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's'){

           switch(menuModificar()){

            case 1:
                printf("Ingrese nuevo precio: \n");
                scanf("%f", &notebooks[id].precio);
                break;

            case 2:
                listarTipos(tipos, tamTipo);
                printf("Ingrese el id del nuevo tipo: \n");
                scanf("%d", &notebooks[id].idTipo);
                while(notebooks[id].idTipo<1|| notebooks[id].idTipo>4){
                    listarTipos(tipos, tamTipo);
                    printf("Error, el id no es valido. Reingrese: \n");
                     scanf("%d", &notebooks[id].idTipo);
                }
                break;

            case 3:
                printf("Salio\n");
                break;




            }

        }else{
            printf("Se ha cancelado la operacion\n");
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
printf("Ingrese la opcion que quiera modificar: \n");
printf("1) Precio\n");
printf("2) Tipo\n");
printf("3) Salir\n");


printf("Ingrese opcion: \n");
fflush(stdin);
scanf("%d", &opcion);

return opcion;
}

//

void ordenarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca){

 eNotebook aux;

for(int i=0; i<tam-1; i++){
for(int j=i+1; j<tam; j++){
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
 mostrarNotebooks(notebooks,tam, tipos, tamTipo, marcas, tamMarca);
}


//------------------------------------------------------------

//-------------------------------------------------
void bajaNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca){
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("*** Baja notebook ***\n");
    mostrarNotebooks(notebooks, tam, tipos, tamTipo, marcas, tamMarca);
    printf("Ingrese id: \n");
    scanf("%d", &id);

    indice = buscarNotebook(id, notebooks, tam);

    if(indice == -1){
        printf("No hay registro de una notebook con el id %d\n", id);
    }else{
        mostrarNotebook(notebooks[indice], tipos, tamTipo, marcas, tamMarca);
        printf("Confima baja? \n");
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




