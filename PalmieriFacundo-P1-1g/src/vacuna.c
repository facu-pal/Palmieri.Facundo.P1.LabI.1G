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

int cargarDescVacuna(eVacuna vacuna[], int tamVac, int idVacuna, char descVacuna[]) {
	int retorno = 0;
	int flag = 1;

	if (vacuna != NULL && tamVac > 0 && descVacuna != NULL) {
		retorno = 1;
		for (int i = 0; i < tamVac; i++) {
			if (vacuna[i].id == idVacuna) {
				strcpy(descVacuna, vacuna[i].nombre);
				flag = 0;
				break;
			}
		}
		if (flag) {
			retorno = -1; // no habia localidad con el id que le pasaron
		}
	}

	return retorno;
}
int cargarPrecio(eVacuna vacuna[], int tamVac, int idVacuna, float *precio) {
	int retorno = 0;
	int flag = 1;

	if (vacuna != NULL && tamVac > 0) {
		retorno = 1;
		for (int i = 0; i < tamVac; i++) {
			if (vacuna[i].id == idVacuna) {
				*precio = vacuna[i].precio;
				flag = 0;
				break;
			}
		}
		if (flag) {
			retorno = -1; // no habia localidad con el id que le pasaron
		}
	}

	return retorno;
}
