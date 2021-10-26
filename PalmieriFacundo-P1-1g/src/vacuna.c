#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "vacuna.h"

int mostrarVacuna(eVacuna vacuna[],int tamVac,eLaboratorio labo[], int tamLab){

	int todoOk = 0;
	char descLaboratorio[20];
		    if (vacuna != NULL && tamVac > 0 && labo != NULL && tamLab > 0)
		    {
		        printf("      *** vacuna *** \n\n");
		        printf("  Id         nombre         precio         idLaboratorio       \n");
		        for (int i = 0; i < tamVac; i++)
		        {
		        	cargarDescLaboratorio(labo, tamLab, vacuna[i].idLaboratorio, descLaboratorio);

		            printf("  %d       %-10s      %.2f       %-10s\n", vacuna[i].id, vacuna[i].nombre, vacuna[i].precio, descLaboratorio);
		        }
		        printf("\n\n");
		        todoOk = 1;
		    }

		    return todoOk;

}
int validarIdVacuna( int id, eVacuna vacuna[], int tamVac ){
    int esValido = 0;
    if (vacuna != NULL && tamVac > 0)
    {
        for (int i = 0; i < tamVac; i++)
        {
            if (id == vacuna[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;


}
