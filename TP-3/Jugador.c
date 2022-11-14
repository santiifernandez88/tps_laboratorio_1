
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

	Jugador* unJugador;
	Jugador* otroJugador;

	unJugador = (Jugador*) jugadorUno;
	otroJugador = (Jugador*) jugadorDos;

	if((unJugador != NULL && otroJugador != NULL) && (unJugador->edad > otroJugador->edad))
	{
		retorno = 1;
	}


	return retorno;
}

int jugador_CompareByNacionalidad(void* jugadorUno, void* jugadorDos)
{
	int compara;
	char nacionalidadUnJugador[100];
	char nacionalidadOtroJugador[100];

	Jugador* unJugador;
	Jugador* otroJugador;

	unJugador = (Jugador*)jugadorUno;
	otroJugador = (Jugador*)jugadorDos;

	if(unJugador!= NULL && otroJugador != NULL)
	{
		jug_getNombreCompleto(unJugador, nacionalidadUnJugador);
		jug_getNombreCompleto(otroJugador, nacionalidadOtroJugador);
		compara = strcmp(nacionalidadUnJugador, nacionalidadOtroJugador);
	}


	return compara;
}


int jugador_CompareByNombre(void* jugadorUno, void* jugadorDos)
{
	int compara;
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

		if(idSeleccion == 0)
		{
			printf("%4d %25s %10d %25s %25s %25s \n", id, nombre, edad, posicion, nacionalidad, "NO CONVOCADO");
		}
		else
		{
			printf("%4d %25s %10d %25s %25s %4d \n", id, nombre, edad, posicion, nacionalidad, idSeleccion);
		}

	}
}

void mostrarTodosLosJugadores(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;

	for(int i= 0; i<ll_len(pArrayListJugador); i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		jug_printOne(pJugador);
	}

}

int buscarIdJugador(LinkedList* pArrayListJugador, char* mensaje)
{
	Jugador* pJugador;
	int idAux;
	int id;

	idAux = inputs_getNumberInt(mensaje, "Error, vuelva a ingresar un id valido.\n", 1, 500);

	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = ll_get(pArrayListJugador,i);
		if(pJugador != NULL)
		{
			jug_getId(pJugador, &id);
			if(id == idAux)
			{
				printf("El jugador que usted ingreso es: \n");
				jug_printOne(pJugador);
			}
		}
	}

	return idAux;
}

void listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int idSeleccion;

	printf("Los jugadores convocados son: \n");
	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		if(pJugador != NULL)
		{
			jug_getIdSeleccion(pJugador, &idSeleccion);
			if(idSeleccion > 0)
			{

				jug_printOne(pJugador);
			}
			else
			{
				printf("No hay jugadores convocados.\n");
				break;
			}
		}
	}
}

void mostrarJugadoresNoConvocados(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int idSeleccion;

	printf("Los jugadores no convocados son: \n");

	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = ll_get(pArrayListJugador,i);
		if(pJugador != NULL)
		{
			jug_getIdSeleccion(pJugador, &idSeleccion);
			if(idSeleccion == 0)
			{
				jug_printOne(pJugador);
			}
		}
	}
}


/*Jugador* altaJugador()
{
	Jugador* miJugador;

	miJugador = jug_new();

	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;


	getOnlyString("Ingrese el nombre del jugador: \n","Error reingrese el nombre: \n", 10, 100, nombre);
	edad = inputs_getNumberInt("Ingrese la edad del jugador: \n", "Error, reingrese la edad del jugador: \n", 16, 45);
	getOnlyString("Ingrese la posicion del jugador: \n","Error reingrese la posicion: \n", 10, 100, posicion);
	getOnlyString("Ingrese la nacionalidad del jugador: \n","Error reingrese la nacionalidad: \n", 10, 100, nacionalidad);

	return miJugador;
}*/
