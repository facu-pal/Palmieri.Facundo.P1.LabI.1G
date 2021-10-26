#include "laboratorio.h"

#ifndef VACUNA_H_
#define VACUNA_H_

typedef struct
{
    int id; // pk
    char nombre[20];
    float precio;
    int idLaboratorio;
    int isEmpty; //1 esta vacio, 0 esta lleno
} eVacuna;

#endif /* VACUNA_H_ */
int mostrarVacuna(eVacuna vacuna[],int tamVac,eLaboratorio labo[], int tamLav);
int validarIdVacuna( int id, eVacuna vacuna[], int tamVac );
