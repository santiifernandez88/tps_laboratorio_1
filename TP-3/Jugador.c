
#include "Jugador.h"

Jugador* jug_new()
{

	Jugador* pJugador;

	pJugador = (Jugador*) calloc(sizeof(Jugador),1);

	return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* pJugador;

	pJugador = jug_new();
	if(pJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL)
	{
		jug_setId(pJugador,atoi(idStr));
		jug_setNombreCompleto(pJugador, nombreCompletoStr);
		jug_setEdad(pJugador,atoi(edadStr));
		jug_setPosicion(pJugador, posicionStr);
		jug_setNacionalidad(pJugador, nacionalidadStr);
		jug_setIdSeleccion(pJugador,atoi(idSeleccionStr));
	}

	return pJugador;
}

void jug_delete(Jugador* unJugador)
{
	free(unJugador);
}

int jug_setId(Jugador* this,int id)
{
	int retorno;
	retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno;
	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno;
	retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(this->posicion, posicion);
		retorno = 0;
	}

	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno;
	retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion, this->posicion);
		retorno = 0;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}

	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 0;
	}

	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno;
	retorno = -1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno;
	retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad= this->edad;
		retorno = 0;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno;
	retorno = -1;

	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}

	return retorno;
}

int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno;
	retorno = -1;

	if(this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

int jugador_CompareByEdad(void* jugadorUno, void* jugadorDos)
{
	int retorno = 0;
	int edadUnJugador;
	int edadOtroJugador;

	Jugador* unJugador;
	Jugador* otroJugador;

	unJugador = (Jugador*) jugadorUno;
	otroJugador = (Jugador*) jugadorDos;

	if(unJugador != NULL && otroJugador != NULL)
	{
		jug_getEdad(unJugador, &edadUnJugador);
		jug_getEdad(otroJugador, &edadOtroJugador);

		if(edadUnJugador < edadOtroJugador)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}
	}


	return retorno;
}

int jugador_CompareByNacionalidad(void* jugadorUno, void* jugadorDos)
{
	int compara = -1;
	char nacionalidadUnJugador[100];
	char nacionalidadOtroJugador[100];

	Jugador* unJugador;
	Jugador* otroJugador;

	unJugador = (Jugador*)jugadorUno;
	otroJugador = (Jugador*)jugadorDos;

	if(unJugador!= NULL && otroJugador != NULL)
	{
		jug_getNacionalidad(unJugador, nacionalidadUnJugador);
		jug_getNacionalidad(otroJugador, nacionalidadOtroJugador);
		compara = strcmp(nacionalidadUnJugador, nacionalidadOtroJugador);
	}

	return compara;
}


int jugador_CompareByNombre(void* jugadorUno, void* jugadorDos)
{
	int compara = -1;
	char nombreUnJugador[100];
	char nombreOtroJugador[100];

	Jugador* unJugador;
	Jugador* otroJugador;

	unJugador = (Jugador*)jugadorUno;
	otroJugador = (Jugador*)jugadorDos;

	if(unJugador!= NULL && otroJugador != NULL)
	{
		jug_getNombreCompleto(unJugador, nombreUnJugador);
		jug_getNombreCompleto(otroJugador, nombreOtroJugador);
		compara = strcmp(nombreUnJugador, nombreOtroJugador);
	}

	return compara;
}

void mostrarUnJugadorConPais(Jugador* pJugador, Seleccion* pSeleccion)
{
	int id;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;
	char pais[100];
	int idSelec;

	if(pJugador != NULL && pSeleccion != NULL)
	{
		jug_getId(pJugador, &id);
		jug_getNombreCompleto(pJugador, nombre);
		jug_getEdad(pJugador, &edad);
		jug_getPosicion(pJugador, posicion);
		jug_getNacionalidad(pJugador, nacionalidad);
		jug_getIdSeleccion(pJugador, &idSeleccion);
		selec_getPais(pSeleccion, pais);
		selec_getId(pSeleccion, &idSelec);
		if(idSeleccion == idSelec)
		{
			printf("%4d %25s %10d %25s %25s %25s \n", id,nombre,edad,posicion,nacionalidad,pais);
		}
		else
		{
			jug_printOne(pJugador);
		}
	}
}

void jug_printOne(Jugador* unJugador)
{
	int id;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;

	if(unJugador != NULL)
	{
		jug_getId(unJugador, &id);
		jug_getNombreCompleto(unJugador, nombre);
		jug_getEdad(unJugador, &edad);
		jug_getPosicion(unJugador, posicion);
		jug_getNacionalidad(unJugador, nacionalidad);
		jug_getIdSeleccion(unJugador, &idSeleccion);

		printf("%4d %25s %10d %25s %25s %25s \n", id, nombre, edad, posicion, nacionalidad, "NO CONVOCADO");

	}
}

void mostrarJugadorSinIdSeleccion(Jugador* unJugador)
{
	int id;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];

	if(unJugador != NULL)
	{
		jug_getId(unJugador, &id);
		jug_getNombreCompleto(unJugador, nombre);
		jug_getEdad(unJugador, &edad);
		jug_getPosicion(unJugador, posicion);
		jug_getNacionalidad(unJugador, nacionalidad);

		printf("%4d %25s %10d %25s %25s \n", id, nombre, edad, posicion, nacionalidad);
	}
}


