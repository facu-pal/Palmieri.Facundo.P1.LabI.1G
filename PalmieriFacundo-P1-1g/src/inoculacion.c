#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inoculacion.h"
#include "utn.h"

#define VACIO 1

int inicializarInoculacion(eInoculacion inoculacion[], int tam){
	int retorno = 0;

	if (inoculacion != NULL && tam > 0) {
		retorno = 1;
		for (int i = 0; i < tam; i++) {
			inoculacion[i].isEmpty = VACIO;
		}
	}
	return retorno;
}

int buscarLibreIno(eInoculacion inoculacion[], int tam){
	int indice = -1;
	for (int i = 0; i < tam; i++) {
		if (inoculacion[i].isEmpty == VACIO) {
			indice = i;
			break;
		}
	}
	return indice;
}

int altaInoculacion(eInoculacion Inoculacion[], int tam, ePaciente paciente[],int tamPac,eVacuna vacuna[],int tamVac,eProvincia pronvicia[], int tamProv,eLaboratorio laboratorio[], int tamLab,int *pNextId){
	int todoOk = 0;
		int indice;
		eInoculacion auxInoculacion;
		if (Inoculacion != NULL && tam > 0 && paciente != NULL && tamPac > 0 && vacuna != NULL && tamVac > 0 && pronvicia != NULL && tamProv > 0 && laboratorio != NULL && tamLab > 0 && pNextId != NULL) {
			system("cls");
			printf("  ***Alta inoculacion*** \n\n");
			indice = buscarLibre(paciente, tam);
			if (indice == -1) {
				printf("No hay lugar\n");
			} else {
				auxInoculacion.id = *pNextId;
				(*pNextId)++;

				mostrarPacientes(paciente, tamPac, pronvicia, tamProv);
				utn_getNumero(&auxInoculacion.idPaciente, "Ingrese la id del paciente:","Error.Ingrese la id del paciente:", 0, 100000, 3);
				while (!validarIdPaciente(auxInoculacion.idPaciente, paciente,tamPac)) {
				utn_getNumero(&auxInoculacion.idPaciente, "Ingrese la id del paciente:","Error.Ingrese la id del paciente:", 0, 100000, 3);
				}

				mostrarVacuna(vacuna, tamVac, laboratorio, tamLab);
				utn_getNumero(&auxInoculacion.idVacuna, "Ingrese la id de la vacuna:","Error.Ingrese la id de la vacuna:", 20000, 200000, 3);
				while (!validarIdVacuna(auxInoculacion.idVacuna, vacuna,tamVac)) {
					utn_getNumero(&auxInoculacion.idVacuna, "Ingrese la id de la vacuna:","Error.Ingrese la id de la vacuna:", 20000, 200000, 3);
				}


				utn_getNumero(&auxInoculacion.fecha.dia, "Ingrese el dia(entre 1 a 31):","Error.Ingrese el dia(entre 1 a 31):", 1, 31, 3);



				utn_getNumero(&auxInoculacion.fecha.mes, "Ingrese el mes(entre el 1 al 12):","Error.Ingrese el mes(entre el 1 al 12):", 1, 31, 3);



				utn_getNumero(&auxInoculacion.fecha.anio, "Ingrese el anio(entre 2020 y 2022):","Error.Ingrese el anio(entre 2020 y 2022):", 2020, 2022, 3);




				auxInoculacion.isEmpty = 0;

				Inoculacion[indice] = auxInoculacion;

				todoOk = 1;
			}
		}
		system("pause");

		return todoOk;

}

void mostrarInoculacion(eInoculacion inoculacion){

	printf(" %d       %d       %d         %d/%d/%d            \n", inoculacion.id,inoculacion.idPaciente,inoculacion.idVacuna,inoculacion.fecha.dia,inoculacion.fecha.mes,inoculacion.fecha.anio);


}
int mostrarInoculaciones(eInoculacion Inoculacion[], int tam) {
	int todoOk = 0;
		int flag = 1;

		if (Inoculacion != NULL && tam > 0 ) {
			printf("                     ***Lista de inoculacion  ***\n");
			printf(
					"------------------------------------------------------------\n");
			printf(
					" ID    idPaciente       idVacuna    fecha       \n");
			printf(
					"------------------------------------------------------------\n");
			for (int i = 0; i < tam; i++) {

				if (!Inoculacion[i].isEmpty) {

					mostrarInoculacion(Inoculacion[i]);
					flag = 0;
				}
			}
			if (flag) {
				printf("No hay personas para mostrar.\n");
			}

			todoOk = 1;
		}
		system("pause");

		return todoOk;
}








