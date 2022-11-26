/*
 * inputs.c
 *
 *  Created on: 13 nov. 2022
 *      Author: santr
 */

#include "inputs.h"


int utn_getOnlyString(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("\n%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) < len)
		{
			strncpy(pResultado,bufferString,len);
			retorno = 0;
			break;
		}
		printf("\n%s",mensajeError);
	}
	return retorno;
}

int getNombre(char* pResultado, int len)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    			esNombre(buffer, sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<len)
    	{
    		strncpy(pResultado,buffer,len);
			retorno = 0;
		}
    }
    return retorno;
}

int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}

int esNombre(char* cadena,int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

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
