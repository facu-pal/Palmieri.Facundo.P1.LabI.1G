#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fecha.h"
#include "laboratorio.h"
#include "provincia.h"
#include "paciente.h"
#include "vacuna.h"
#include "inoculacion.h"

//define
#define TAM_LAB 4
#define TAM_PROV 5
#define TAM_VAC 6
#define TAM_PAC 10 //No especifica el ta
#define TAN_INO 50

int main(void) {
    setbuf(stdout, NULL);
    char seguir = 's';
    int pNextId = 10;
    int pNextIdInoculacion = 100;

    ePaciente pacientes[TAM_PAC];//No especifica el tamanio del array de paciente
    eInoculacion inoculacion[TAN_INO];

    eLaboratorio laboratorio[TAM_LAB]={
    		{1000, "Chino"},
			{1001, "Ingles"},
			{1002, "USA"},
			{1003, "Ruso"}
    };

    eProvincia provincia[TAM_PROV] = {
    		{ 5000, "BsAs" },
			{ 5001, "Mendoza" },
			{5002, "Cordoba" },
			{ 5003, "San Luis" },
			{5004, "Corrientes"}
    };

    eVacuna vacuna[TAM_VAC]={
    		{ 20000,"Pfyzer",450,1000 },
    		{ 20001,"Moderna",500,1002 },
    		{ 20002,"Cancino",400,1003 },
    		{ 20003,"Synopharm",410,1001 },
    		{ 20004,"Sputnik",390,1002 },
    		{ 20005,"Jhonson",470,1001 },
    		} ;

    if(inicializarPaciente(pacientes, TAM_PAC)==0){
       	printf("problemas a inicializar\n");
       }
    if(inicializarInoculacion(inoculacion,TAN_INO)==0){
        	printf("problemas a inicializar\n");
        }


    do{
       	switch (menu()){
       	case 1:
			if (altaPaciente(pacientes, TAM_PAC, provincia, TAM_PROV, &pNextId)== 0) {
				printf("No se pudo el alta del paciente\n");
			} else {
				printf("Se pudo hace el alta del paciente\n");
			}
			break;
       	case 2:
     		if(modificarPaciente(pacientes, TAM_PAC,provincia,TAM_PROV)==0){
        		    printf("No se pudo modificar al paciente\n");
        		}else{
        		    printf("Se pudo modificar al paciente\n");
        		}
        		break;
      	case 3:
        		if(bajaPaciente(pacientes, TAM_PAC,provincia,TAM_PROV)==0){
        		    printf("No se pudo la baja de la persona\n");
        		}else{
        		    printf("Se pudo hace la baja de la persona\n");
        		}
        		break;
      	case 4:
      		ordenarPacientes(pacientes, TAM_PAC,provincia,TAM_PROV) ;
      		 break;

       	case 5:
       		mostrarProvincia(provincia, TAM_PROV);
       		break;
       	case 6:
       		mostrarLaboratorio(laboratorio,TAM_LAB);
       		break;
       	case 7:
       		mostrarVacuna(vacuna,TAM_VAC,laboratorio,TAM_LAB);
       		break;
       	case 8:
       		altaInoculacion(inoculacion,TAN_INO, pacientes,TAM_PAC, vacuna, TAM_VAC,provincia,TAM_PROV, laboratorio, TAM_LAB, &pNextIdInoculacion);
       		break;
       	case 9:
       		mostrarInoculaciones(inoculacion,TAN_INO);
       		break;
       	case 10:
       		printf("Salio\n");
       		seguir  = 'n';
       		break;
       	default:
       		printf("No increase una opcion valida\n");
       	break;

       	}
       }while(seguir  == 's');
	return EXIT_SUCCESS;
}
