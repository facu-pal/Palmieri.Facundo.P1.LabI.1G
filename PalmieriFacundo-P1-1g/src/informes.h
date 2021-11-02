#include "paciente.h"
#include "provincia.h"
#include "provincia.h"
#include "inoculacion.h"
#include "laboratorio.h"

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */
int menuInforme();
int informe1();

int informe2(ePaciente pacientes[], int tamPac, eProvincia provincia[], int tamProv);
int informe3(ePaciente pacientes[], int tamPac, eProvincia provincia[], int tamProv);
int informe4(ePaciente pacientes[], int tamPac, eProvincia provincia[], int tamProv);
int informe5(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac);
int informe6(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac);
int informe7(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,eLaboratorio laboratorio[], int tamLab,ePaciente paciente[],int tamPac);
int informe8(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,eLaboratorio laboratorio[], int tamLab,ePaciente paciente[],int tamPac,eProvincia provincia[], int tamProv);
int informe9(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,ePaciente paciente[],int tamPac,eProvincia provincia[], int tamProv);
int informe10(eInoculacion inoculacion[], int tamIno,eVacuna vacuna[],int tamVac,ePaciente paciente[],int tamPac);
