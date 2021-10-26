#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "paciente.h"
#include "utn.h"

#define VACIO 1

int menu() {
	int opcion = 0;
	system("cls");
	printf("     *** ABM clinica ***\n");
	printf("1- Alta paciente\n");
	printf("2- modificar paciente\n");
	printf("3- baja paciente \n");
	printf("4- listar paciente\n");
	printf("5- Listar provincia\n");
	printf("6- Listar laboratorio\n");
	printf("7- Listar vacuna\n");
	printf("8- Alta inoculacion\n");
	printf("9- listar inoculacion\n");
	printf("10- Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);
	return opcion;

	return opcion;
}

int inicializarPaciente(ePaciente pacientes[], int tam) {
	int retorno = 0;

	if (pacientes != NULL && tam > 0) {
		retorno = 1;
		for (int i = 0; i < tam; i++) {
			pacientes[i].isEmpty = VACIO;
		}
	}
	return retorno;
}

int buscarLibre(ePaciente paciente[], int tam) {
	int indice = -1;
	for (int i = 0; i < tam; i++) {
		if (paciente[i].isEmpty == VACIO) {
			indice = i;
			break;
		}
	}
	return indice;
}
int altaPaciente(ePaciente paciente[], int tam, eProvincia provincia[],int tamProvincia, int *pNextId) {
	int todoOk = 0;
	int indice;
	ePaciente auxPaciente;

	if (paciente != NULL
			&& tam
					> 0&& provincia != NULL && tamProvincia > 0 && pNextId != NULL) {
		system("cls");
		printf("  ***Alta Provincia*** \n\n");
		indice = buscarLibre(paciente, tam);
		if (indice == -1) {
			printf("No hay lugar\n");
		} else {
			auxPaciente.id = *pNextId;
			(*pNextId)++;

			utn_getString(auxPaciente.nombre, 20,
					"Ingrese el nombre del paciente:",
					"Error. Ingrese el nombre del paciente:", 3);

			utn_getNumero(&auxPaciente.edad, "Ingrese la edad de la paciente:",
					"Error.Ingrese la edad de la paciente:", 0, 140, 3);

			getChar("Ingrese si es un grupo de riesgo (s=si o n =no)",&auxPaciente.grupoRiesgo);
			while (auxPaciente.grupoRiesgo != 's'
					&& auxPaciente.grupoRiesgo != 'n') {
				getChar("Error. Ingrese si es un grupo de riesgo (s=si o n =no)",&auxPaciente.grupoRiesgo);

			}
			mostrarProvincia(provincia, tamProvincia);

			utn_getNumero(&auxPaciente.idProvincia,
					"Ingrese el id de la provincia:",
					"Error.Ingrese el id de la provincia:", 5000, 6000, 3);

			while (!validarIdProvincia(auxPaciente.idProvincia, provincia,
					tamProvincia)) {
				utn_getNumero(&auxPaciente.idProvincia,
						"Ingrese el id de la provincia:",
						"Error.Ingrese el id de la provincia:", 5000, 6000, 3);

			}

			auxPaciente.isEmpty = 0;

			paciente[indice] = auxPaciente;

			todoOk = 1;
		}
	}
	system("pause");

	return todoOk;
}

void mostrarPaciente(ePaciente unaPaciente, eProvincia provincia[],
		int tamLoc) {
	char descLocalidad[20];
	if (cargarDescProvincia(provincia, tamLoc, unaPaciente.idProvincia,
			descLocalidad) == 1) {

		printf(" %d     %-10s  %2d         %c           %10s \n", unaPaciente.id,
				unaPaciente.nombre, unaPaciente.edad, unaPaciente.grupoRiesgo,
				descLocalidad);
	}
}

int mostrarPacientes(ePaciente lista[], int tam, eProvincia provincia[],int tamProv) {
	int todoOk = 0;
	int flag = 1;

	if (lista != NULL && tam > 0 &&provincia != NULL && tamProv > 0) {
		printf("                     ***Lista de Paciente  ***\n");
		printf(
				"------------------------------------------------------------\n");
		printf(
				" ID    Nombre       edad    grupo de riesgo       idProvincia \n");
		printf(
				"------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++) {

			if (!lista[i].isEmpty) {

				mostrarPaciente(lista[i], provincia, tamProv);
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

int buscarPacienteId(ePaciente lista[], int tam, int Id) {
	int indice = -1;
	for (int i = 0; i < tam; i++) {
		if (lista[i].id == Id && lista[i].isEmpty == 0) {
			indice = i;
			break;
		}
	}
	return indice;
}
int modificarPaciente(ePaciente paciente[], int tam, eProvincia provincia[],int tamProv) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	ePaciente auxPaciente;

	if (paciente != NULL && tam > 0 && provincia != NULL && tamProv > 0) {
		system("cls");
		printf("   *** modificar Persona *** \n\n");
		mostrarPacientes(paciente, tam, provincia, tamProv);
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarPacienteId(paciente, tam, id);

		if (indice == -1) {

			printf("El id: %d no esta registrado en el sistema\n", id);

		} else {

			mostrarPaciente(paciente[indice], provincia, tamProv);
			printf("Confirma modificacion?: ");
			fflush(stdin);
			scanf("%c", &confirma);

			if (confirma == 's') {

				switch (menuModificacion()) {

				case 1:
					mostrarProvincia(provincia, tamProv);
					printf("Modificar id localidad: ");
					scanf("%d", &auxPaciente.idProvincia);

					while (!validarIdProvincia(auxPaciente.idProvincia,provincia, tamProv)) {
						printf("Error, ingrese id de localidad valido: ");
						scanf("%d", &auxPaciente.idProvincia);
					}

					printf("Confirma cambio de id localidad? (S/N)\n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);

					if (confirma == 'S') {
						todoOk = 1;

						paciente[indice].idProvincia = auxPaciente.idProvincia;
					} else {
						printf("Edición cancelada\n");
					}
					break;

				case 2:


					getChar("Ingrese el nuevo un grupo de riesgo (s=si o n =no)",&auxPaciente.grupoRiesgo);
					while (auxPaciente.grupoRiesgo != 's' && auxPaciente.grupoRiesgo != 'n') {
						getChar("Error. Ingrese si es un grupo de riesgo (s=si o n =no)",&auxPaciente.grupoRiesgo);
					}

					printf("Confirma cambio de grupo de riesgo? (S/N)\n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);

					if (confirma == 'S') {
						paciente[indice].grupoRiesgo= auxPaciente.grupoRiesgo;
						todoOk = 1;
					} else {
						printf("Edición cancelada\n");
					}
					break;
				case 3:
					printf("Salio de modificar\n");

					break;
				default:
					printf("Opcion invalida\n");

				}
			} else {
				printf("Se ha cancelada la modificaicon.\n");
			}
		}
	}
	system("pause");

	return todoOk;
}

int menuModificacion() {
	int opcion = 0;
	printf("1- provincia\n");
	printf("2- grupo de riesgo\n");
	printf("3- Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);
	return opcion;
}

int bajaPaciente(ePaciente paciente[], int tam, eProvincia provincia[], int tamProv) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	if (paciente != NULL && tam > 0) {
		system("cls");
		printf("   *** Baja Persona *** \n\n");
		mostrarPacientes(paciente, tam, provincia, tamProv);
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarPacienteId(paciente, tam, id);

		if (indice == -1) {
			printf("El id: %d no esta registrado en el sistema\n", id);
		} else {
			mostrarPaciente(paciente[indice], provincia, tamProv);

			printf("Confirma baja?: ");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				paciente[indice].isEmpty = 1;
				todoOk = 1;
			} else {
				printf("Baja cancelada por el usuario.\n");
			}
		}
	}
	system("pause");

	return todoOk;
}
/*    int id;
    char nombre[20];
    int edad;
    char grupoRiesgo;
    int idProvincia;*/

int ordenarPacientes(ePaciente pacientes[], int tam,eProvincia provincias[],int tamProv) {
	int retorno = 0;
	ePaciente auxPaciente;

	if (pacientes != NULL && tam > 0 &&provincias != NULL && tamProv > 0) {
		retorno = 1;
		for (int i = 0; i < tam - 1; i++) {
			for (int j = i + 1; j < tam; j++) {

				if ((pacientes[i].idProvincia > pacientes[j].idProvincia)|| (pacientes[i].idProvincia == pacientes[j].idProvincia	&& pacientes[i].grupoRiesgo > pacientes[j].grupoRiesgo)) {

					auxPaciente = pacientes[i];
					pacientes[i] = pacientes[j];
					pacientes[j] = auxPaciente;
				}
			}
		}

 		 mostrarPacientes(pacientes, tam,provincias,tamProv) ;


	}
	system("pause");

	return retorno;
}

int validarIdPaciente( int id, ePaciente paciente[], int tamPac )
{
    int esValido = 0;
    if (paciente != NULL && tamPac > 0)
    {
        for (int i = 0; i < tamPac; i++)
        {
            if (id == paciente[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


