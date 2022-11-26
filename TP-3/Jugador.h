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
/// @fn void jug_printOne(Jugador*)
/// @brief muestra un jugador sin convocar
///
/// @param unJugador
void jug_printOne(Jugador* unJugador);
/// @fn void mostrarUnJugadorConPais(Jugador*, Seleccion*)
/// @brief muestra un jugador convocado
///
/// @param pJugador
/// @param pSeleccion
void mostrarUnJugadorConPais(Jugador* pJugador, Seleccion* pSeleccion);
/// @fn void mostrarJugadorSinIdSeleccion(Jugador*)
/// @brief muestra un jugador sin el campo de la id de la seleccion
///
/// @param unJugador
void mostrarJugadorSinIdSeleccion(Jugador* unJugador);
/// @fn int jugador_CompareByNombre(void*, void*)
/// @brief compara por nombre
///
/// @param jugadorUno
/// @param jugadorDos
/// @return int
int jugador_CompareByNombre(void* jugadorUno, void* jugadorDos);
/// @fn int jugador_CompareByEdad(void*, void*)
/// @brief compara por edad
///
/// @param jugadorUno
/// @param jugadorDos
/// @return int
int jugador_CompareByEdad(void* jugadorUno, void* jugadorDos);
/// @fn int jugador_CompareByNacionalidad(void*, void*)
/// @brief  compara por nacionalidad
///
/// @param jugadorUno
/// @param jugadorDos
/// @return int
int jugador_CompareByNacionalidad(void* jugadorUno, void* jugadorDos);

#endif // jug_H_INCLUDED
