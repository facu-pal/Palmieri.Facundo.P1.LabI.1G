#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "paciente.h"
#include "inoculacion.h"

char nombres[10][20] =
{
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"
};

char grupoRiesgo[10]={'s','s','n','n','s','n','n','s','n','s'};

char sexos[10] = {'m','m','f','m','f','f','f','m','m','f'};

int idProvincia[10]={5000,5003,5000,5002,5000,5003,5000,5002,5001,5004};

int idPaciente[10]={10,11,12,13,14,15,16,17,18,19};

int idVacuna[10]={20005,20003,20005,20000,20000,20001,20002,20002,20004,20000};

int dia[10]={5,5,5,31,2,19,20,21,28,1};

int mes[10]={12,12,12,11,5,3,9,3,5,10};

int anio[10]={2020,2020,2020,2020,2021,2021,2021,2021,2021,2020};

int edades[10] = {23,21,28,34,35,34,23,28,30,31};

float alturas[10] = {1.65,1.74,1.68,1.80,1.64,1.69,1.75,1.74,1.73,1.82};

int idLocalidades[10] = {1004,1002,1003,1004,1003,1001,1001,1000,1000,1003};


int hardcodearPaciete(ePaciente lista[], int tam, int cant, int* pId){
    int contador = -1;
    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].edad = edades[i];
            lista[i].grupoRiesgo = grupoRiesgo[i];
            lista[i].idProvincia = idProvincia[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
int hardcodearInoculacion(eInoculacion lista[], int tam, int cant, int* pId){
	   int contador = -1;
	    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	    {
	        contador = 0;
	        for (int i = 0; i < cant;  i++)
	        {
	            lista[i].id = *pId;
	            (*pId)++;
	           lista[i].idPaciente = idPaciente[i];
	           lista[i].idVacuna = idVacuna[i];
	           lista[i].fecha.dia = dia[i];
	           lista[i].fecha.mes = mes[i];
	           lista[i].fecha.anio = anio[i];
	           lista[i].isEmpty = 0;
	            contador++;
	        }
	    }
	    return contador;
}
