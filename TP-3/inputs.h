/*
 * inputs.h
 *
 *  Created on: 13 nov. 2022
 *      Author: santr
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getOnlyString(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado);
int getNombre(char* pResultado, int len);
int getString(char* cadena, int len);
int esNombre(char* cadena,int len);
int inputs_getNumberInt(char* mensaje, char* mensajeError, int minimo, int maximo);


#endif /* INPUTS_H_ */
