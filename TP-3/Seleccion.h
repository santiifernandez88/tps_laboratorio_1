#include "LinkedList.h"
#include "inputs.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* pSeleccion);

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

//Funciones Agregadas

int seleccion_CompareByConfederacion(void* seleccionUno, void* seleccionDos);
void seleccion_printOne(Seleccion* pSeleccion);
int buscarIdSeleccion(LinkedList* pArrayListSeleccion);
#endif // selec_H_INCLUDED
