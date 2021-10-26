#include "provincia.h"

#ifndef PACIENTE_H_
#define PACIENTE_H_
typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char grupoRiesgo;
    int idProvincia;
    int isEmpty; //1 esta vacio, 0 esta lleno
} ePaciente;


#endif /* PACIENTE_H_ */
int menu();

int inicializarPaciente(ePaciente pacientes[], int tam);
int buscarLibre(ePaciente lista[], int tam);
int altaPaciente(ePaciente lista[], int tam, eProvincia provincia[],int tamProvincia,int *pNextId);
int buscarPacienteId(ePaciente lista[], int tam, int Id);
void mostrarPaciente(ePaciente unaPaciente, eProvincia provincia[], int tamLoc) ;
int mostrarPacientes(ePaciente lista[], int tam, eProvincia provincia[],int tamProv) ;
int modificarPaciente(ePaciente paciente[], int tam, eProvincia provincia[],int tamProv);
int menuModificacion();
int bajaPaciente(ePaciente paciente[], int tam, eProvincia provincia[], int tamProv);
int ordenarPacientes(ePaciente pacientes[], int tam,eProvincia provincias[],int tamProv) ;
int validarIdPaciente( int id, ePaciente paciente[], int tamPac );
