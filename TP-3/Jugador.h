#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "inputs.h"
#include "seleccion.h"



#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

//Funciones Agregadas

void jug_printOne(Jugador* unJugador);
void mostrarTodosLosJugadores(LinkedList* pArrayListJugador);

int jugador_CompareByNombre(void* jugadorUno, void* jugadorDos);
int jugador_CompareByEdad(void* jugadorUno, void* jugadorDos);
int jugador_CompareByNacionalidad(void* jugadorUno, void* jugadorDos);

int buscarIdJugador(LinkedList* pArrayListJugador, char* mensaje);

void listarJugadoresConvocados(LinkedList* pArrayListJugador);
void mostrarJugadoresNoConvocados(LinkedList* pArrayListJugador);

#endif // jug_H_INCLUDED
