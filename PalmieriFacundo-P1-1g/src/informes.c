#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "informes.h"
#include "paciente.h"
#include "provincia.h"
#include "vacuna.h"
#include "provincia.h"
#include "inoculacion.h"
#include "laboratorio.h"
#include "fecha.h"
#include "utn.h"


int menuInforme() {
	int opcion = 0;
	system("cls");
	printf("     *** Informes ***\n");
	printf("1- Informe no realizado\n");
	printf("2- mostrar por provincia y grupo de riesgo\n");
	printf("3- porcentaje de paciente que pertenecen al grupo de riesgo\n");
	printf("4- lista de pacientes separado por provincia\n");
	printf("5- mostrar vacunas mas inoculadas\n");
	printf("6- mostrar vacunas menos inoculadas \n");
	printf("7- Pedir una vacuna y mostrar todos los pacientes inoculados con la misma.\n");
	printf("8- Pagar vacuna por provincia\n");
	printf("9- Paciente si esta vacunado\n");
	printf("10- mostrar inoculaciones por fecha\n");
	printf("11- Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);
	return opcion;

	return opcion;
}
int informe1(){
	printf("No se realizo el informe 1");
	return 0;
}

int informe2(ePaciente pacientes[], int tamPac, eProvincia provincia[], int tamProv) {
	int retorno = 0;
	int idProvincia;
	char grRiesgo;
	int flag=0;
	if (pacientes != NULL && tamPac > 0 && provincia != NULL && tamProv > 0) {
		system("cls");
		getChar("Ingrese si es un grupo de riesgo (s=si o n =no)", &grRiesgo);
		while (grRiesgo != 's' && grRiesgo != 'n') {
			getChar("Error. Ingrese si es un grupo de riesgo (s=si o n =no)",
					&grRiesgo);

		}

		mostrarProvincia(provincia, tamProv);
		utn_getNumero(&idProvincia, "Ingrese el id de la provincia:",
				"Error.Ingrese la edad de la paciente:", 4999, 5010, 3);
		if (!validarIdProvincia(idProvincia, provincia, tamProv)) {
			utn_getNumero(&idProvincia, "Ingrese el id de la provincia:",
					"Error.Ingrese la edad de la paciente:", 4999, 5010, 3);
		}
		printf(" lista de grupo de riesgo y provincia\n");
		for(int i=0;i<tamPac;i++){
			if(pacientes[i].grupoRiesgo ==grRiesgo && pacientes[i].idProvincia ==idProvincia&& pacientes[i].isEmpty ==0){
			mostrarPaciente(pacientes[i], provincia, tamProv);
			flag=1;

			}
		}
		if(flag==0){
			printf("no hay persona de esa provincia\n");
		}
		retorno=0;
	}

	return retorno;
}
int informe3(ePaciente pacientes[], int tamPac, eProvincia provincia[], int tamProv){
	int retorno = 0;
		char grRiesgo;
		int cantGrRiesgo=0;
		int contGrRiesgo=0;
		float porcentaje;
		int flag=0;
		if (pacientes != NULL && tamPac > 0 && provincia != NULL && tamProv > 0) {

			system("cls");
			getChar("Ingrese si es un grupo de riesgo (s=si o n =no)", &grRiesgo);
			while (grRiesgo != 's' && grRiesgo != 'n') {
				getChar("Error. Ingrese si es un grupo de riesgo (s=si o n =no)",&grRiesgo);
			}

			printf(" porcentaje de paciente que pertenecen al grupo de riesgo\n");
			for(int i=0;i<tamPac;i++){
				if(pacientes[i].grupoRiesgo == grRiesgo && pacientes[i].isEmpty ==0){
					cantGrRiesgo++;
					contGrRiesgo++;
					flag=1;
				}else if(pacientes[i].grupoRiesgo != grRiesgo && pacientes[i].isEmpty ==0 ){
				contGrRiesgo++;
				flag=1;
				}
			}
			if(contGrRiesgo!=0){
			porcentaje= ((float)(cantGrRiesgo*100) / contGrRiesgo);
			}

			if(flag==0){
				printf("no hay persona de esa localidad\n");
			}else{
				printf("el porcentaje de paciente que pertenece al grupo de riesgo %c es de : %.2f porciento \n",grRiesgo,porcentaje);
			}
			retorno=0;
		}
		return retorno;

}
int informe4(ePaciente pacientes[], int tamPac, eProvincia provincia[], int tamProv){
	int retorno = 0;
	char descLocalidad[20];

	if (pacientes != NULL && tamPac > 0 && provincia != NULL && tamProv > 0) {
		system("cls");

		printf(" lista de pacientes separado por provincia\n");
		for (int j = 0; j < tamProv; j++) {
			cargarDescProvincia(provincia, tamProv, provincia[j].id,descLocalidad);
			printf("-----------------------------------------\n");
			printf("%s\n", descLocalidad);
			for (int i = 0; i < tamPac; i++) {
				if (pacientes[i].idProvincia == provincia[j].id
						&& pacientes[i].isEmpty == 0) {
					mostrarPaciente(pacientes[i], provincia, tamProv);
				}
			}
			printf("-----------------------------------------\n");

		}

		retorno = 0;
	}

	return retorno;

}

int informe5(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac){
	int retorno = 0;
	int cantVacuna[tamIno];
	float masIno;
	int acumVacuna = 0;

	for (int i = 0; i < tamIno; i++) {
		cantVacuna[i] = 0;
	}
	if (inoculacion != NULL && tamIno > 0 && vacuna != NULL && tamVac > 0) {
		system("cls");

		printf(" vacunas menos inoculadas\n");
		printf("-----------------------------------------\n");
		for (int i = 0; i < tamVac; i++) {
			acumVacuna = 0;
			for (int j = 0; j < tamIno; j++) {
				if (inoculacion[j].isEmpty == 0 && inoculacion[j].idVacuna == vacuna[i].id) {
					acumVacuna++;
				}
			}

				cantVacuna[i] =  acumVacuna ;

		}
		for (int i = 0; i < tamVac; i++) {
			if (cantVacuna[i] > masIno || i == 0) {
				masIno = cantVacuna[i];
			}
		}

		for (int i = 0; i < tamVac; i++) {
			if (cantVacuna[i] == masIno) {
				printf(" %s \n", vacuna[i].nombre);
			}
		}

		retorno = 1;
	}

	return retorno;

}
int informe6(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac){
	int retorno = 0;
	int cantVacuna[tamIno];
	float masIno;
	int acumVacuna = 0;

	for (int i = 0; i < tamIno; i++) {
		cantVacuna[i] = 0;
	}
	if (inoculacion != NULL && tamIno > 0 && vacuna != NULL && tamVac > 0) {
		system("cls");

		printf(" vacunas menos inoculadas\n");
		printf("-----------------------------------------\n");
		for (int i = 0; i < tamVac; i++) {
			acumVacuna = 0;
			for (int j = 0; j < tamIno; j++) {
				if (inoculacion[j].isEmpty == 0 && inoculacion[j].idVacuna == vacuna[i].id) {
					acumVacuna++;
					//cont++;
				}
			}
			cantVacuna[i] =  acumVacuna ;

		}
		for (int i = 0; i < tamVac; i++) {
			if (cantVacuna[i] < masIno || i == 0) {
				masIno = cantVacuna[i];
			}
		}

		for (int i = 0; i < tamVac; i++) {
			if (cantVacuna[i] == masIno) {
				printf(" %s \n", vacuna[i].nombre);
			}
		}

		retorno = 1;
	}

	return retorno;

}

int informe7(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,eLaboratorio laboratorio[], int tamLab,ePaciente paciente[],int tamPac){
	int retorno = 0;
	int idVacuna;

	if (inoculacion != NULL && tamIno > 0 && vacuna != NULL && tamVac > 0 && laboratorio != NULL && tamLab > 0 && paciente != NULL && tamPac > 0 ) {
		system("cls");
		mostrarVacuna(vacuna, tamVac, laboratorio, tamLab);
		utn_getNumero(&idVacuna, "Ingrese la id de la vacuna:","Error.Ingrese la id de la vacuna:", 20000, 200000, 3);
		while (!validarIdVacuna(idVacuna, vacuna, tamVac)) {
			utn_getNumero(&idVacuna, "Ingrese la id de la vacuna:","Error.Ingrese la id de la vacuna:", 20000, 200000, 3);
		}

		printf(" lista de una vacuna\n");
		printf("-----------------------------------------\n");
		for (int i = 0; i < tamIno; i++) {
			if(inoculacion[i].idVacuna == idVacuna && inoculacion[i].isEmpty ==0){
				mostrarInoculacion(inoculacion[i], paciente, tamPac, vacuna, tamVac);
			}
		}

		retorno = 1;
	}

	return retorno;
}

int informe8(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,eLaboratorio laboratorio[], int tamLab,ePaciente paciente[],int tamPac,eProvincia provincia[], int tamProv){
	int retorno = 0;
	int idVacuna;
	int idprovincia;
	float totalPagar=0;
	float precio;

	if (inoculacion != NULL && tamIno > 0 && vacuna != NULL && tamVac > 0 && laboratorio != NULL && tamLab > 0 && paciente != NULL && tamPac > 0 &&  provincia != NULL && tamProv > 0) {
		system("cls");


		mostrarVacuna(vacuna, tamVac, laboratorio, tamLab);
				utn_getNumero(&idVacuna, "Ingrese la id de la vacuna:","Error.Ingrese la id de la vacuna:", 20000, 200000, 3);
				while (!validarIdVacuna(idVacuna, vacuna,tamVac)) {
				utn_getNumero(&idVacuna, "Ingrese la id de la vacuna:","Error.Ingrese la id de la vacuna:", 20000, 200000, 3);
			}


		mostrarProvincia(provincia, tamProv);
		utn_getNumero(&idprovincia, "Ingrese la id de la provincia:","Error.Ingrese la id de la provincia:",  5000, 6000, 3);
		while (!validarIdProvincia(idprovincia, provincia, tamProv)) {
			utn_getNumero(&idVacuna, "Ingrese la id de la provincia:","Error.Ingrese la id de la provincia:",  5000, 6000, 3);
		}

		printf(" pagar vacuna por provinciar\n");
		printf("-----------------------------------------\n");
		cargarPrecio(vacuna, tamVac, idVacuna, &precio);
		for (int i = 0; i < tamIno; i++) {
			for(int j=0;j<tamPac;j++){
				if(inoculacion[i].idVacuna == idVacuna && inoculacion[i].idPaciente == paciente[j].id && paciente[j].idProvincia == idprovincia && paciente[j].isEmpty ==0 && inoculacion[i].isEmpty ==0){
					totalPagar+= precio;
			}
			}
		}
		printf("la provincia tiene que pagar un total de : %.2f\n",totalPagar);
		retorno = 1;
	}

	return retorno;
}
int informe9(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,ePaciente paciente[],int tamPac,eProvincia provincia[], int tamProv){
	int retorno = 0;
	int idPaciente;
	char descVacuna[20] ;
	int flag=0;

	if (inoculacion != NULL && tamIno > 0 && vacuna != NULL && tamVac > 0 && paciente != NULL && tamPac > 0 &&  provincia != NULL && tamProv > 0) {
		system("cls");

		mostrarPacientes(paciente, tamPac, provincia, tamProv);
		utn_getNumero(&idPaciente, "Ingrese la id del paciente:","Error.Ingrese la id del paciente:", 0, 100000, 3);
		while (!validarIdPaciente(idPaciente, paciente,tamPac)) {
		utn_getNumero(&idPaciente, "Se id no existe.Ingrese la id del paciente:","Error.Ingrese la id del paciente:", 0, 100000, 3);
		}

		printf(" paciente si esta vacunado\n");
		printf("-----------------------------------------\n");
		for (int i = 0; i < tamIno; i++) {
			for(int j=0;j<tamPac;j++){
				if(inoculacion[i].idPaciente == idPaciente && inoculacion[i].isEmpty ==0){
					cargarDescVacuna(vacuna, tamVac, inoculacion[i].idVacuna, descVacuna);
					printf("el paciente esta vacunado con la vacuna %s\n",descVacuna);
					break;
					flag=1;
				}
			}
		}
		if(flag==1){
			printf("el paciente no esta vacunado\n");

		}
		retorno = 1;
	}

	return retorno;
}



int informe10(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,ePaciente paciente[],int tamPac){
	int retorno = 0;
	eFecha fecha;
	if (inoculacion != NULL && tamIno > 0  && vacuna != NULL && tamVac > 0 && paciente != NULL && tamPac > 0) {
		system("cls");

		printf("mostrar inoculaciones por fecha\n");
		printf("----------------------------------------------------------------\n");
		printf(" ID    idPaciente       idVacuna                      fecha\n");
		printf("----------------------------------------------------------------\n");
		utn_getNumero(&fecha.dia, "Ingrese el dia(entre 1 a 31):","Error.Ingrese el dia(entre 1 a 31):", 1, 31, 3);
		utn_getNumero(&fecha.mes, "Ingrese el mes(entre el 1 al 12):","Error.Ingrese el mes(entre el 1 al 12):", 1, 31, 3);
		utn_getNumero(&fecha.anio, "Ingrese el anio(entre 2020 y 2022):","Error.Ingrese el anio(entre 2020 y 2022):", 2020, 2022, 3);

		for (int i = 0; i < tamIno; i++) {

			if (inoculacion[i].fecha.dia == fecha.dia && inoculacion[i].fecha.mes == fecha.mes && inoculacion[i].fecha.anio == fecha.anio && inoculacion[i].isEmpty ==0) {
				mostrarInoculacion(inoculacion[i], paciente, tamPac, vacuna, tamVac);

			}
		}
	}
	retorno = 1;


	return retorno;
}
