#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"


Seleccion* selec_new()
{
	Seleccion* pSeleccion;

	pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	return pSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* pSeleccion;

	pSeleccion = selec_new();
	if(pSeleccion != NULL)
	{
		pSeleccion->id = atoi(idStr);
		strcpy(pSeleccion->pais, paisStr);
		strcpy(pSeleccion->confederacion, confederacionStr);
		pSeleccion->convocados = atoi(convocadosStr);
	}

	return pSeleccion;
}

void selec_delete(Seleccion* pSeleccion)
{
	free(pSeleccion);
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = 1;

	if(this != NULL && pais != NULL)
	{
		strcpy(pais, this->pais);
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 1;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion, this->confederacion);
		retorno = 0;
	}

	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = 1;

	if(this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		retorno  = 0;
	}

	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = 1;

	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		retorno = 0;
	}

	return retorno;
}

int seleccion_CompareByConfederacion(void* seleccionUno, void* seleccionDos)
{
	int compara;

	char confederacionUno[50];
	char confederacionDos[50];

	Seleccion* unaSeleccion;
	Seleccion* otraSeleccion;

	unaSeleccion = (Seleccion*)seleccionUno;
	otraSeleccion = (Seleccion*)seleccionDos;

	if(unaSeleccion != NULL && otraSeleccion != NULL)
	{
		selec_getConfederacion(unaSeleccion, confederacionUno);
		selec_getConfederacion(otraSeleccion, confederacionDos);
		compara = strcmp(confederacionUno, confederacionDos);
	}

	return compara;
}

void seleccion_printOne(Seleccion* pSeleccion)
{
	int id;
	char pais[100];
	char confederacion[100];
	int convocados;

	selec_getId(pSeleccion, &id);
	selec_getPais(pSeleccion, pais);
	selec_getConfederacion(pSeleccion, confederacion);
	selec_getConvocados(pSeleccion, &convocados);

	if(pSeleccion != NULL)
	{
		printf("%4d %25s %25s %10d \n", id, pais, confederacion, convocados);
	}
}

int buscarIdSeleccion(LinkedList* pArrayListSeleccion)
{
	Seleccion* pSeleccion;
	int idAux;
	int id;

	validarEntero("Ingrese el id de la seleccion: \n", "Error, vuelva a ingresar un id valido.\n", 1, 500, 5, &idAux);

	for(int i=0;i<ll_len(pArrayListSeleccion);i++)
	{
		pSeleccion = ll_get(pArrayListSeleccion,i);
		if(pSeleccion != NULL)
		{
			selec_getId(pSeleccion, &id);
			if(id == idAux)
			{
				printf("La seleccion que usted ingreso es: \n");
				seleccion_printOne(pSeleccion);
			}
		}
	}

	return idAux;
}
