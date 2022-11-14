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
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i] == ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int inputs_getNumberInt(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno= -1;
	int bufferInt=-1;
	if (mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do{
			printf ("%s",mensaje);
			fflush (stdin);
			scanf ("%d",&bufferInt);
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = bufferInt;
				break;
			}
			else
			{
				printf ("%s",mensajeError);
				fflush (stdin);
			}
		}while(retorno==-1);
	}

	return retorno;
}
