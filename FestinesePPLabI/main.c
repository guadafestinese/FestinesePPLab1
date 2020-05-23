#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebooks.h"
#include "marcas.h"
#include "tipos.h"
#include "servicios.h"
#include "trabajos.h"
#include "clientes.h"
#include "informes.h"

#define TAMM 4
#define TAMT 4
#define TAMS 4
#define TAMN 10
#define TAMTR 10
#define TAMCLIENTE 10





int main()
{
    eMarca marcas[TAMM] = {{1000, "Compaq"},{1001, "Asus"}, {1002, "Acer"}, {1003, "HP"}};
    eTipo tipos[TAMT] = { {5000, "Gamer"}, {5001, "Disenio"}, {5002, "Ultrabook"}, {5003, "Normalita"} };
    eServicio servicios[TAMS]= { {20000, "Bateria", 250}, {20001, "Antivirus", 300}, {20002, "Actualizacion", 400}, {20003, "Fuente", 600} };


    eNotebook notebooks[TAMN]= {
    								{1,	"Uno",	1000,	5001,	2000,	0, 3},
									{2, "Dos",	1002,	5002,	3000,	0, 2},
									{3,	"Tres", 1003,	5000,	3500,	0, 4},
									{4,	"Cuatro",1000,	5000,	5000,	0, 8},
									{5, "Cinco", 1001,  5003,	4600,	0, 10},
									{6, "Seis",	 1003,	5003,	3200,	0, 1},
									{7, "Siete", 1003,  5002,	2600,	0, 9},
									{8, "Ocho",  1002,  5003,	5600,	0, 5},
									{9, "Nueve", 1001,	5000,	4900,	0, 7},
									{10, "Diez", 1000,  5001,	3300,	0, 6} };


    eTrabajo trabajos[TAMTR]  ={
    								{1,	2, 20003, {2,4,2020}, 0},
									{2, 3, 20003, {5,6,2004}, 0},
									{3,	1, 20000, {2,10,2005}, 0},
									{4,	1, 20002, {3,2,1995},	0},
									{5, 5, 20002, {6,1,2020},	0},
									{6, 6, 20001, {2,5,2020},	0},
									{7, 8, 20002, {2,5,2020},	0},
									{8, 4, 20000, {3,8,2019},	0},
									{9, 9, 20001, {2,9,2018},	0},
									{10, 10,20000, {9,3,2020}, 0} };

    eCliente clientes[TAMCLIENTE]= {    {1, "Juan", 'm', 0},
                                        {2, "Macarena", 'f', 0},
                                        {3, "Claudia", 'f', 0},
                                        {4, "Franco", 'm', 0},
                                        {5, "Gustavo", 'm', 0},
                                        {6, "Marta", 'f', 0},
                                        {7, "Roberto", 'm', 0},
                                        {8, "Daniel", 'm', 0},
                                        {9, "Pilar", 'f', 0},
                                        {10, "Fabiana", 'f', 0} };



    char confirma;
    char seguir = 's';



    int proximoIdTrabajo = 1;
    int proximoIdNotebook =1;
    int proximoIdCliente = 1;
    int flagAlta=0;
    int flagTrabajo =0;


    //inicializarNotebooks(notebooks, TAMN);
    //inicializarTrabajos(trabajos, TAMTR);


    do{
		switch(menu()){


			case 1:
			if(altaNotebook(proximoIdNotebook, notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE) == 1)
                {

					proximoIdNotebook++;
					proximoIdCliente++;
					flagAlta=1;
                }
				mostrarNotebooks(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE);
				system("pause");
				break;
			case 2:
				/*
				if(flagAlta == 0)
                {
                    printf("No se cargo ninguna notebook aun\n");
                    system("pause");
                }else{
                    modificarNotebook(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE);
                }*/

                modificarNotebook(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE);
				break;

			case 3:
			   /* if(flagAlta == 0)
                {
                    printf("No se cargo ninguna notebook aun\n");
                    system("pause");
                }else{
                    bajaNotebook(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE);
                }*/

                bajaNotebook(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE);
				system("pause");
				break;

			case 4:
			   /* if(flagAlta == 0)
                {
                    printf("No se cargo ninguna notebook aun\n");
                    system("pause");
                }else{
                    ordenarNotebooks(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE);
                }*/
                ordenarNotebooks(notebooks, TAMN, tipos, TAMT, marcas, TAMM, clientes, TAMCLIENTE);
				system("pause");
				break;

			case 5:
				listarMarcas(marcas, TAMM);
				system("pause");
				break;

			case 6:
				listarTipos(tipos, TAMT);
				system("pause");
				break;

			case 7:
				listarServicios(servicios, TAMS);
				system("pause");
				break;

			case 8:
			  /*
			   if(flagAlta == 0)
                {
                printf("No hay ninguna notebook para cargar un trabajo\n");
                system("pause");
			   }else{
                 if(altaTrabajo(proximoIdTrabajo, notebooks, TAMN, tipos, TAMT, marcas, TAMM, servicios, TAMS, trabajos, TAMTR, clientes, TAMCLIENTE)){
				   proximoIdServicio++;
				   proximoIdTrabajo++;
				   flagTrabajo = 1;
			       }
			   }*/
			   break;
			case 9:
			   /*
			   if(flagTrabajo== 0)
                {
                    printf("No hay trabajos cargados\n");
                    system("pause");
			    }else{
			        mostrarTrabajos(trabajos, TAMTR, notebooks, TAMN, servicios, TAMS);
                    system("pause");
			    }*/
			    mostrarTrabajos(trabajos, TAMTR, notebooks, TAMN, servicios, TAMS);
                system("pause");
				break;
            case 10:
                informeNotebooks(notebooks, TAMN, tipos, TAMT, marcas, TAMM, trabajos, TAMTR, servicios, TAMS, clientes, TAMCLIENTE);
                system("pause");
                break;
			case 11:
				printf("Confirma salida?: Ingrese s o n \n");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 's')
				{
					seguir = 'n';
				}
				break;
			default:
				break;
		}//fin switch
    }while(seguir == 's');

    return 0;
}
