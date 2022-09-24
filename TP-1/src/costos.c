/*
 * costos.c
 *
 *  Created on: 15 sep. 2022
 *      Author: santr
 */
#include <stdio.h>
#include <stdlib.h>
#include "costos.h"
#include "inputs.h"

int ingresarCostoHospedaje()
{
	int hospedaje;

	hospedaje = getInt("Ingrese el gasto de hospedaje: ");

	return hospedaje;
}

int ingresarCostoComida()
{
	int comida;

	comida = getInt("Ingrese el gasto de comida: ");

	return comida;
}

int ingresarCostoTransporte()
{
	int transporte;

	transporte = getInt("Ingrese el gasto de transporte: ");


	return transporte;
}

int SumarCostos(int costoUno, int costoDos, int costoTres)
{
	int mantenimiento;

	mantenimiento = 0;

	mantenimiento = costoUno + costoDos + costoTres;

	return mantenimiento;
}
