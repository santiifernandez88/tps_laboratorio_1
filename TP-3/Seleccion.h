#include "LinkedList.h"
#include "inputs.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* pSeleccion);

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

//Funciones Agregadas
/// @fn int seleccion_CompareByConfederacion(void*, void*)
/// @brief Compara entre dos confederaciones
///
/// @param seleccionUno
/// @param seleccionDos
/// @return retorna el valor del retorno de la funcion strcmp
int seleccion_CompareByConfederacion(void* seleccionUno, void* seleccionDos);
/// @fn void seleccion_printOne(Seleccion*)
/// @brief Muestra una seleccion
///
/// @param pSeleccion
void seleccion_printOne(Seleccion* pSeleccion);
/// @fn int buscarIdSeleccion(LinkedList*)
/// @brief  busca la id de la seleccion que se pide
///
/// @param pArrayListSeleccion
/// @return retorna el id que se pide.
int buscarIdSeleccion(LinkedList* pArrayListSeleccion);
#endif // selec_H_INCLUDED
