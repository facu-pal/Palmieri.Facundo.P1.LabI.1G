#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "provincia.h"



int cargarDescProvincia(eProvincia provincia[], int tamProv, int idprovincia, char descProvincia[]) {
	int retorno = 0;
	int flag = 1;

	if (provincia != NULL && tamProv > 0 && descProvincia != NULL) {
		retorno = 1;
		for (int i = 0; i < tamProv; i++) {
			if (provincia[i].id == idprovincia) {
				strcpy(descProvincia, provincia[i].nombrePais);
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

int mostrarProvincia(eProvincia provincia[],int tamProv){
	 int todoOk = 0;
	    if (provincia != NULL && tamProv > 0 )
	    {
	        printf("      *** provincias *** \n\n");
	        printf("  Id         nombre pais       \n");
	        for (int i = 0; i < tamProv; i++)
	        {
	            printf("  %d       %-10s\n", provincia[i].id, provincia[i].nombrePais);
	        }
	        printf("\n\n");
	        todoOk = 1;
	    }

	    return todoOk;
}

int validarIdProvincia( int id, eProvincia provincia[], int tamProv )
{
    int esValido = 0;
    if (provincia != NULL && tamProv > 0)
    {
        for (int i = 0; i < tamProv; i++)
        {
            if (id == provincia[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

