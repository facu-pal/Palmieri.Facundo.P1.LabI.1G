#include "paciente.h"
#include "vacuna.h"
#include "provincia.h"
#include "fecha.h"
#include "laboratorio.h"




#ifndef INOCULACION_H_
#define INOCULACION_H_

typedef struct
{
    int id; // pk
    int idPaciente; // pk
    int idVacuna;
    eFecha fecha;
    int isEmpty; //1 esta vacio, 0 esta lleno
} eInoculacion;

#endif /* INOCULACION_H_ */
int inicializarInoculacion(eInoculacion inoculacion[], int tam);
int buscarLibreIno(eInoculacion inoculacion[], int tam);

int altaInoculacion(eInoculacion Inoculacion[], int tam, ePaciente paciente[],int tamPac,eVacuna vacuna[],int tamVac,eProvincia pronvicia[], int tamProv,eLaboratorio laboratorio[], int tamLab,int *pNextId);
void mostrarInoculacion(eInoculacion inoculacion);

int mostrarInoculaciones(eInoculacion Inoculacion[], int tam) ;
