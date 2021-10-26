/*
 * laboratorio.h
 *
 *  Created on: 25 oct 2021
 *      Author: facun
 */

#ifndef LABORATORIO_H_
#define LABORATORIO_H_

typedef struct
{
    int id; // pk
    char nacionalidad[20];
    int isEmpty; //1 esta vacio, 0 esta lleno
} eLaboratorio;

#endif /* LABORATORIO_H_ */
int mostrarLaboratorio(eLaboratorio laboratorio[],int tamLav);
int cargarDescLaboratorio(eLaboratorio laboratorio[], int tamLab, int idLaboratorio, char descLaboratorio[]);
