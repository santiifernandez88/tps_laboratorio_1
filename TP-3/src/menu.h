#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

#ifndef MENU_H_
#define MENU_H_

int menuInformes();
int menuPrincipal();
int menuPorDefecto(char* mensaje, char* mensajeError, int minimo, int maximo);

#endif /* MENU_H_ */
