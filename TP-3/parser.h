
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "controller.h"


int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int parser_JugadorToText(FILE* pFile, LinkedList* pArrayListJugador);
int parser_SeleccionToText(FILE* pFile, LinkedList* pArrayListSeleccion);
int parser_idFromText(FILE* pFile, char* id);


#endif /* PARSER_H_ */
