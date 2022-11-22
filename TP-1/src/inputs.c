#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarEntero(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pResultado)
{
	int retorno = -1;
	int bufferInt;
	int retorno_getInt;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pResultado != NULL && reintentos > 0)
	{
		printf("\n%s",mensaje);
		fflush(stdin);
		retorno_getInt = obtenerEntero(&bufferInt);
		do
		{
			if(retorno_getInt == -1 || bufferInt > maximo || bufferInt < minimo)
			{
				printf("\n%s",mensajeError);
				reintentos--;
				printf("\nQuedan %d reintentos.",reintentos);
				printf("\n%s",mensaje);
				fflush(stdin);
				retorno_getInt = obtenerEntero(&bufferInt);
			}
			else
			{
				reintentos = 0;
				*pResultado = bufferInt;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

int obtenerEntero(int* pNumeroTomado)
{
	int retorno = -1;
	char bufferNum[200];

	if(myGets(bufferNum, sizeof(bufferNum)) == 0 && esNumerica(bufferNum) == 0)
	{
		*pNumeroTomado= atoi(bufferNum);
		retorno = 0;
	}
	return retorno;
}

int esNumerica(char cadena[])
{
	int retorno = 0;
	int i;

	if(cadena != NULL)
	{
		i = 0;

		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0'; //Porque toma el "enter" como �ltimo caracter.
		}
		if(cadena[0]=='-')
		{
			i++; // Para que empiece el while en 2da posici�n a chequear que sean todos n�meros (luego de pasar el signo menos)
		}
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else
	{
		retorno = -1 ;
	}
	return retorno;
}

int myGets(char cadena[], int len)
{
	int retorno = -1;

	if(cadena != NULL && len > 0 && fgets(cadena, len, stdin) == cadena)
	{
		retorno = 0;
	}
	return retorno;
}
