/*
 * provincia.h
 *
 *  Created on: 25 oct 2021
 *      Author: facun
 */

#ifndef PROVINCIA_H_
#define PROVINCIA_H_

typedef struct
{
    int id; // pk
    char nombrePais[20];
    int isEmpty; //1 esta vacio, 0 esta lleno
} eProvincia;

#endif /* PROVINCIA_H_ */

int cargarDescProvincia(eProvincia provincia[], int tamProv, int idprovincia, char descProvincia[]);

int mostrarProvincia(eProvincia provincia[],int tamLoc);
int validarIdProvincia( int id, eProvincia provincia[], int tamProv );
