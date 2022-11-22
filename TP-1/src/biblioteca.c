#include "biblioteca.h"

#include <stdio.h>
#include <stdlib.h>


int validarPosiciones(int* jugador, int max, char* mensaje)
{
	int bandera = 0;

	if(*jugador < max)
	{
		*jugador+=1;
		bandera = 1;
	}
	else
	{
		printf("%s", mensaje);
	}

	return bandera;
}

int MenuPosiciones(int posicion, int* contadorArqueros, int* contadorDefensor, int* contadorMediocampistas, int* contadorDelanteros)
{
	int bandera;

	switch(posicion)
	{
		case 1:
			bandera = validarPosiciones(contadorArqueros, 2, "Error, ya hay suficientes arqueros en el equipo.\n");

			break;
		case 2:
			bandera = validarPosiciones(contadorDefensor, 8, "ERROR!! ya hay demasiados defensores en el equipo.\n");

			break;
		case 3:
			bandera = validarPosiciones(contadorMediocampistas, 8, "ERROR!! ya hay demasiados defensores en el equipo.\n");

			break;
		case 4:
			bandera = validarPosiciones(contadorDelanteros, 4, "ERROR!! ya hay demasiados defensores en el equipo.\n");
			break;
		default:
			printf("Posicion incorrecta, vuelva a leer las opciones y ponga una valida por favor!");
			break;
	}

	return bandera;
}

int SumarCostos(int costoUno, int costoDos, int costoTres)
{
	int mantenimiento;

	mantenimiento = 0;

	mantenimiento = costoUno + costoDos + costoTres;

	return mantenimiento;
}

int AumentarMantenimiento(int contadorEuropa, int contadorSudAmerica, int contadorNorAmerica, int contadorAfrica, int contadorOceania, int contadorAsia, int mantenimiento)
{
	int aumento;
	aumento  = mantenimiento;

	if(contadorEuropa > contadorSudAmerica && contadorEuropa > contadorAfrica && contadorEuropa > contadorOceania && contadorEuropa > contadorAsia && contadorEuropa > contadorNorAmerica)
	{
		aumento = mantenimiento * 1.35;
	}

	return aumento;
}

float promediarConfederaciones(int confederacion, int jugadores)
{
	float promedio;

	promedio = (float) confederacion / jugadores;

	return promedio;
}
