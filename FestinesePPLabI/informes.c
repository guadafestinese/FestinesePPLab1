#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

char menuInformes()
{
    char opcion;
    system("cls");
    printf("*********** Informes ***********\n");
    printf("a- Mostrar notebooks del tipo seleccionado \n");
    printf("b- Mostrar notebooks de marca seleccionada\n");
    printf("c- Informar la o las notebooks mas baratas\n");
    printf("d- Mostrar un listado de las notebooks separadas por marca\n");
    printf("e- Informar cuantas notebooks hay de un tipo y marca seleccionados\n");
    printf("f- Mostrar la o las marcas mas elegidas\n");
    printf("g- Pedir una notebook y mostrar todos los trabajos que se le hicieron\n");
    printf("h- Pedir una notebook y mostrar la suma de los importes de sus servicios \n");
    printf("i- Pedir un servicio y mostrar las notebooks a las que se le realizo el servicio y la fecha \n");
    printf("j- Pedir una fecha y mostrar todos los servicios realizados en la misma \n");
    printf("x. Salir\n");


    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}
//-----------------------------------------------------------------------------------------------------------------------
void informeNotebooks(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente)
{

    char seguir = 's';
    char confirma = 's';

    do
    {
        switch(menuInformes())
        {
        case 'a':
            listarNotebooksDeTipo(notebooks, tamN, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            break;
        case 'b':
            listarNotebooksDeMarca(notebooks, tamN, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            break;
        case 'c':
            informarMenorPrecioNotebook(notebooks, tamN, marcas, tamMarca, tipos, tamTipo, clientes, tamCliente);
            break;
        case 'd':
            informarNotebooksXMarcas(notebooks, tamN, marcas, tamMarca, tipos, tamTipo, clientes, tamCliente);
            break;
        case 'e':
            mostrarNotebooksPorMarcaYTipo(notebooks, tamN, marcas, tamMarca, tipos, tamTipo);
            break;
        case 'f':
            informarMayorMarca(notebooks, tamN, marcas, tamMarca);
            break;
        case 'g':
            informarTrabajosDeNotebook(trabajos, tamTr, notebooks, tamN, tipos, tamTipo, servicios, tamServ, marcas, tamMarca, clientes, tamCliente);
            break;
        case 'h':
            preciosServiciosNotebook(notebooks, tamN, tipos, tamTipo, marcas, tamMarca, trabajos, tamTr, servicios, tamServ, clientes, tamCliente);
            break;
        case'i':
            informarNotebooksDeServicio(notebooks, tamN, servicios, tamServ, trabajos, tamTr);
            break;
        case 'j':
            listarNotebooksPorFechaTrabajo(notebooks, tamN, trabajos, tamTr, servicios, tamServ);
            break;

        case 'x':
            printf("Confirma salida? Ingrese s o n: \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");

    }
    while ( seguir == 's');

}


//------------------------------------------------------------------------------------------------------------------------

void listarNotebooksDeTipo(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    int idTipo;
    int flag = 0;

    system("cls");

    listarTipos(tipos, tamTipo);
    printf("\n Ingrese el ID del tipo: ");
    scanf("%d", &idTipo);


    printf("**** Listado de notebooks por tipo ****\n\n");
    printf("ID	     CLIENTE    MODELO	        MARCA     TIPO	     PRECIO	\n");
    for (int i=0; i< tamN; i++)
    {
        if (notebooks[i].isEmpty == 0 && notebooks[i].idTipo == idTipo)
        {
            mostrarNotebook(notebooks[i], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay notebooks en ese tipo. \n");
    }

}
//--------------------------------------------------------------------------------------------------------------


void listarNotebooksDeMarca(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    int idMarca;
    int flag = 0;

    system("cls");

    listarMarcas(marcas, tamMarca);
    printf("\n Ingrese el ID de la marca: ");
    scanf("%d", &idMarca);
    while(idMarca<1000 || idMarca>1003){
       listarMarcas(marcas, tamMarca);
        printf("\nERROR, id invalido. Ingrese el ID de la marca: ");
        scanf("%d", &idMarca);
    }


    printf("**** Listado de notebooks por marca ****\n\n");
    printf("ID	     CLIENTE    MODELO	        MARCA     TIPO	     PRECIO	\n");
    for (int i=0; i< tamN; i++)
    {
        if (notebooks[i].isEmpty == 0 && notebooks[i].idMarca == idMarca)
        {
            mostrarNotebook(notebooks[i], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay notebooks en esa marca. \n");
    }

}
//------------------------------------------------------------------------------------------------------------------
void preciosServiciosNotebook(eNotebook notebooks[], int tamNotebook, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarca, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicio, eCliente clientes[], int tamCliente){

	int idNote;
	int indiceNote;
	int idServicio;
	int indiceServicio;
	float totalPrecios = 0;

	system("cls");
	printf("**** Precio de servicios de una notebook ****\n");

	mostrarNotebooks(notebooks, tamNotebook, tipos, tamTipos, marcas, tamMarca, clientes, tamCliente);
	printf("Ingrese el ID de la notebook: ");
	scanf("%d", &idNote);
    printf("\n\n");

	indiceNote = buscarNotebook(idNote, notebooks, tamNotebook);

	if(indiceNote == -1){
		printf("No se encontro la notebook con ese ID\n\n");
	}
	else{
		printf("ID	     CLIENTE    MODELO	        MARCA     TIPO	     PRECIO	\n");

		mostrarNotebook(notebooks[indiceNote], tipos, tamTipos, marcas, tamMarca, clientes, tamCliente);

		for(int t = 0; t < tamTrabajos; t++){
			if(notebooks[indiceNote].id == trabajos[t].idNotebook && trabajos[t].id > 0)
            {
				idServicio = trabajos[t].idServicio;
				indiceServicio = buscarServicio(idServicio, servicios, tamServicio);
				totalPrecios += servicios[indiceServicio].precio;
			}
		}

		if(totalPrecios == 0){
			printf("No se le realizaron trabajos a esta notebook\n");
		}
		else{
			printf("\nTotal de precios de los servicios de la notebook: %.2f\n\n", totalPrecios);
		}
	}
}




//----------------------------------------------------------------------------------------------------------------------------
void informarPreciosNotebookServicios(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarca, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente){
	int idNote;
	int indiceNote;
	int idServicio;
	int indiceServicio;
	float total = 0;

	system("cls");
	printf("**** Servicios de notebook *****\n");

	mostrarNotebooks(notebooks, tamN, tipos, tamTipos, marcas, tamMarca, clientes, tamCliente);
	printf("Ingrese ID de la notebook: \n");
	scanf("%d", &idNote);
	indiceNote = buscarNotebook(idNote, notebooks, tamN);

	if(indiceNote == -1){
		printf("No hay notebook con ese ID\n\n");
	}
	else{
		 printf("ID	     CLIENTE    MODELO	        MARCA     TIPO	     PRECIO	\n");
		mostrarNotebook(notebooks[indiceNote], tipos, tamTipos, marcas, tamMarca, clientes, tamCliente);

		for(int t = 0; t < tamTr; t++)
        {
			if(notebooks[indiceNote].id == trabajos[t].idNotebook && trabajos[t].id > 0)
			{
				idServicio = trabajos[t].idServicio;
				indiceServicio = buscarServicio(idServicio, servicios, tamServ);
				total += servicios[indiceServicio].precio;
			}
		}

		if(total == 0){
			printf(" No se realizaron trabajos en esa notebook\n");
		}
		else{
			printf(" Precio de servicios notebook: %.2f\n", total);
		}
	}
}

//-------------------------------------------------------------------------------------------------
void informarMenorPrecioNotebook(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente)
{
    float menorPrecio = 0;
    int flag=0;
    int hayNotebooks =0;
    char nombreMarca[20];
    char nombreTipo[20];

    system("cls");



    for (int i=0; i< tamN; i++)
    {
        if (notebooks[i].isEmpty == 0)
        {
            if(notebooks[i].precio < menorPrecio || flag ==0 )
            {
                menorPrecio = notebooks[i].precio;
                cargarDescripcionMarca(nombreMarca, notebooks[i].idMarca, marcas, tamMarca);
                cargarDescripcionTipo(nombreTipo, notebooks[i].idTipo, tipos, tamTipo);
                flag = 1;
                hayNotebooks =1;
            }
        }
    }


    printf("El menor precio es $%.2f y corresponde a la/las notebook/s: \n\n", menorPrecio);
    printf("ID	     CLIENTE    MODELO	        MARCA     TIPO	     PRECIO	\n");
    for(int e=0; e<tamN; e++)
    {
        if(notebooks[e].precio == menorPrecio && flag == 1 && hayNotebooks == 1)
        {
            mostrarNotebook(notebooks[e], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
        }
    }


    if ( hayNotebooks == 0)
    {
        printf("\nNo hay notebooks\n");
    }
}

//-----------------------------------------------------------------------------------------------------


void informarNotebooksXMarcas(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente){
    int flag=0;
    system("cls");
    printf("****** Lista de Notebooks de todas las marcas *******\n\n");

    for (int s= 0; s<tamMarca; s++)
    {
        printf("\n\n****************************************************************************************\n\n");
        printf("Marca: %s\n\n", marcas[s].descripcion);
         printf("ID	   CLIENTE        MODELO       MARCA     TIPO	     PRECIO	\n");

        for(int e=0; e<tamN; e++){
            if(notebooks[e].isEmpty == 0 && notebooks[e].idMarca == marcas[s].id)
            {
                mostrarNotebook(notebooks[e], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
                flag =1;
            }

    }
        if (flag == 0)
        {
            printf("Sin notebooks\n");
        }
    }
}
//-------------------------------------------------------------------------------------------------
void mostrarNotebooksPorMarcaYTipo(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo){

    int auxTipo;
    int auxMarca;
    int contador=0;
    char nombreTipo[20];
    char nombreMarca[20];
    int flag=0;

    listarTipos(tipos, tamTipo);
    printf("Selecione un tipo por su ID: ");
    fflush(stdin);
    scanf("%d", &auxTipo);
    while(auxTipo<5000 || auxTipo>5003){
        listarTipos(tipos, tamTipo);
        printf("ERROR, id invalido. Selecione un tipo por su ID: ");
        fflush(stdin);
        scanf("%d", &auxTipo);
    }

    listarMarcas(marcas, tamMarca);
    printf("Selecione una marca por su ID: ");
    fflush(stdin);
    scanf("%d", &auxMarca);
    while(auxMarca<1000 || auxMarca>1003){
        listarMarcas(marcas, tamMarca);
        printf("ERROR, id invalido. Selecione una marca por su ID: ");
        fflush(stdin);
        scanf("%d", &auxMarca);
    }

    for(int e=0; e<tamN; e++)
    {
        if(notebooks[e].isEmpty == 0 && notebooks[e].idTipo == auxTipo && notebooks[e].idMarca)
        {
            cargarDescripcionMarca(nombreMarca, notebooks[e].idMarca, marcas, tamMarca);
            cargarDescripcionTipo(nombreTipo, notebooks[e].idTipo, tipos, tamTipo);
            contador++;
            flag=1;
        }

    }



    if(flag == 1 )
    {
        printf("La cantidad de notebooks del tipo %s y la marca %s es %d\n", nombreTipo, nombreMarca, contador);
    }else if (flag == 0){
        printf("No hay notebooks que tengan ese tipo y esa marca simultaneamente\n");
    }


}

//----------------------------------------------------------------------------------------------------------------
int obtenerTotalMarcasNotebook (int idMarca, eNotebook notebooks[], int tamN){

    int totalNotebooks=0;

    for (int i=0; i<tamN; i++)
    {
        if(notebooks[i].isEmpty == 0 && notebooks[i].idMarca == idMarca)
        {
            totalNotebooks = totalNotebooks + 1;
        }
    }

    return totalNotebooks;
}
//------------------------------------------------------------------------------------------------------------------

void informarMayorMarca (eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca){
    int totalMarcas[tamMarca];
    int mayorTotal;
    int flag =0;

    system("cls");
    printf("***** Marcas mas elegidas *****\n\n");

    for(int i=0; i< tamMarca; i++)
    {
        totalMarcas[i] = obtenerTotalMarcasNotebook(marcas[i].id, notebooks, tamN);
    }

    for (int i=0; i<tamMarca; i++)
    {
        if(totalMarcas[i] > mayorTotal || flag ==0)
        {
            mayorTotal = totalMarcas[i];
            flag =1;
        }
    }
    printf("Se eligio %d veces la marca mas elegida y es: \n", mayorTotal);

    for (int i=0; i<tamMarca; i++)
    {
        if( totalMarcas[i] == mayorTotal)
        {
            printf("%s\n", marcas[i].descripcion);
        }
    }
}

//-----------------------------------------------------------------------------------------------

void informarTrabajosDeNotebook (eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNote, eTipo tipos[], int tamTipo, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca,eCliente clientes[], int tamCliente){
 int flag=0;
 int idNote;
 char nombreNote[20];

 system("cls");
 printf("****** Lista de Trabajos de una notebook *******\n");

 mostrarNotebooks(notebooks, tamNote, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
 printf("Ingrese ID de la notebook elegida: ");
 fflush(stdin);
 scanf("%d", &idNote);

    cargarModeloNotebookTrabajo(nombreNote, idNote, notebooks, tamNote);

    printf("\n\nNotebook: %s\n\n", nombreNote);

    printf(" Id         NOTEBOOK             SERVICIO       FECHA\n");
    for (int i=0; i< tamTr; i++)
    {
        if (trabajos[i].isEmpty == 0 && trabajos[i].idNotebook == idNote)
        {
            mostrarTrabajo(trabajos[i], notebooks, tamNote, servicios, tamServ);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay trabajos en esa notebook \n");
    }
}

//---------------------------------------------------------------------------------------------------

void informarNotebooksDeServicio(eNotebook notebooks[], int tamN, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTr)
{
    int idServicio;
    int hayNotebooksEnServ = 0;
    char nombreServicio[20];

    system("cls");
    printf("** Listado de notebooks por servicio **\n\n");

    listarServicios(servicios, tamS);
    printf("\n Ingrese ID del servicio: ");
    scanf("%d", &idServicio);
    while(idServicio<20000 || idServicio>20003){
        listarServicios(servicios, tamS);
        printf("\nERROR. Ingrese ID del servicio: ");
        scanf("%d", &idServicio);
    }

    cargarDescripcionServicioTrabajo(nombreServicio, idServicio, servicios, tamS);

    printf("\nNotebooks de servicio: %s \n\n ", nombreServicio);

    printf("ID       NOTEBOOK               SERVICIO      FECHA\n");
    for (int i=0; i< tamTr; i++)
    {
        if (trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
        {
            mostrarTrabajo(trabajos[i], notebooks, tamN, servicios, tamS);
            hayNotebooksEnServ = 1;
        }
    }

    if ( hayNotebooksEnServ == 0)
    {
        printf("\nNo hay notebooks en el servicio \n");
    }

}

//-----------------------------------------------------------------------------------

void listarNotebooksPorFechaTrabajo(eNotebook notebooks[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ)
{
    int dia;
    int mes;
    int anio;
    int flag = 0;

    system("cls");

    printf("\n Ingrese el dia: ");
    scanf("%d", &dia);

    printf("\n Ingrese el mes: ");
    scanf("%d", &mes);

    printf("\n Ingrese el anio: ");
    scanf("%d", &anio);


    printf("\n**** Listado de servicios de notebooks por fecha ****\n\n");
    printf("   Id       NOTEBOOK     SERVICIO       FECHA\n");
    for (int i=0; i< tamTrab; i++)
    {
        if (trabajos[i].isEmpty == 0 && trabajos[i].fecha.dia == dia && trabajos[i].fecha.mes == mes && trabajos[i].fecha.anio == anio)
        {
            mostrarTrabajo(trabajos[i], notebooks, tam, servicios, tamServ);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay servicios hechos esa fecha \n");
    }

}
//---------------------------------------------------------------------------------------------------------
