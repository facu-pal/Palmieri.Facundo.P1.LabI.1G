#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "laboratorio.h"

int mostrarLaboratorio(eLaboratorio laboratorio[],int tamLav){
	 int todoOk = 0;
	    if (laboratorio != NULL && tamLav > 0 )
	    {
	        printf("      *** Laboratorios *** \n\n");
	        printf("  Id         nacionalidad       \n");
	        for (int i = 0; i < tamLav; i++)
	        {
	            printf("  %d       %-10s\n", laboratorio[i].id, laboratorio[i].nacionalidad);
	        }
	        printf("\n\n");
	        todoOk = 1;
	    }

	    return todoOk;


}
int cargarDescLaboratorio(eLaboratorio laboratorio[], int tamLab, int idLaboratorio, char descLaboratorio[]) {
	int retorno = 0;
	int flag = 1;

	if (laboratorio != NULL && tamLab > 0 && descLaboratorio != NULL) {
		retorno = 1;
		for (int i = 0; i < tamLab; i++) {
			if (laboratorio[i].id == idLaboratorio) {
				strcpy(descLaboratorio, laboratorio[i].nacionalidad);
				flag = 0;
				break;
			}
		}
		if (flag) {
			retorno = -1;
		}
	}

	return retorno;
}
