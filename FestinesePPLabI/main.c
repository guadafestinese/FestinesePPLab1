#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebooks.h"
#include "marcas.h"
#include "tipos.h"
#include "servicios.h"
#include "trabajos.h"

#define TAMM 4
#define TAMT 4
#define TAMS 4
#define TAMN 10



int main()
{
    eMarca marcas[TAMM] = {{1, "Compaq"},{2, "Asus"}, {3, "Acer"}, {4, "HP"}};
    eTipo tipos[TAMT] = { {1, "Gamer"}, {2, "Disenio"}, {3, "Ultrabook"}, {4, "Normalita"} };
    eServicio servicios[TAMS]= { {1, "Bateria", 250}, {2, "Antivirus", 300}, {3, "Actualizacion", 400}, {4, "Fuente", 600} };
    eNotebook notebooks[TAMN]; //={ {1, "Uno", 2, 3, 2000, 0}, {2, "Dos", 1, 3, 3000, 0},{3, "Tres", 1, 3, 3500, 0}, {4, "Cuatro", 2, 4, 5000, 0}, {5, "Cinco", 2, 4, 4600, 0}, {6, "Seis", 1, 3, 3200, 0}, {7, "Siete", 4, 2, 2600, 0}, {8, "Ocho", 3, 3, 5600, 0}, {9, "Nueve", 4,1, 4900, 0}, {10, "Diez", 1, 3, 3300, 0} };
    eTrabajo trabajos[TAMT];


    char confirma;
    char seguir = 's';


    int proximoIdMarca = 1000;
    int proximoIdTipo = 5000;
    int proximoIdServicio = 20000;
    inicializarNotebooks(notebooks, TAMN);


    inicializarTrabajos(trabajos, TAMT);

    do{




    switch(menu()){
    case 1:

        if(altaNotebook(notebooks, TAMN, tipos, TAMT, marcas, TAMM) == 1){
            proximoIdMarca++;
            proximoIdTipo++;
        }
        mostrarNotebooks(notebooks, TAMN, tipos, TAMT, marcas, TAMM);
        system("pause");


        break;
    case 2:
        modificarNotebook(notebooks, TAMN, tipos, TAMT, marcas, TAMM);
        break;
    case 3:
        bajaNotebook(notebooks, TAMN, tipos, TAMT, marcas, TAMM);
        system("pause");
        break;

    case 4:
        ordenarNotebooks(notebooks, TAMN, tipos, TAMT, marcas, TAMM);
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
       if(altaTrabajo(notebooks, TAMN, tipos, TAMT, marcas, TAMM, servicios, TAMS, trabajos, TAMT)){
        proximoIdServicio++;
       }

       break;

    break;
    case 9:
        listarTrabajos(trabajos, TAMT, notebooks, TAMN, servicios, TAMS);
        system("pause");
        break;

    case 10:
        printf("Confirma salida?: Ingrese s o n \n");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            seguir = 'n';
        }
        break;

    }//fin switch
    }while(seguir == 's');


    return 0;
}






