#include "parser.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int cantidadLeida;

	char id[10];
	char nombre[100];
	char edad[10];
	char posicion[100];
	char nacionalidad[100];
	char idSeleccion[10];

	Jugador* pJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, edad, posicion, nacionalidad, idSeleccion);

		while(!feof(pFile))
		{
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, edad, posicion, nacionalidad, idSeleccion);

			if(cantidadLeida == 6)
			{
				pJugador =  jug_newParametros( id, nombre, edad, posicion,  nacionalidad,  idSeleccion);

				if(pJugador != NULL)
				{
					ll_add(pArrayListJugador, pJugador);
					retorno = 0;
				}
			}
		}
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	Jugador* pJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		while(!feof(pFile))
		{
			pJugador = jug_new();
			if(pJugador != NULL)
			{
				fread(pJugador, sizeof(Jugador),1,pFile);
				if(feof(pFile))
				{
					jug_delete(pJugador);
					retorno =-1;
					break;
				}

				ll_add(pArrayListJugador, pJugador);
				retorno = 0;
			}
		}
	}

    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int cantidadLeida;

	char id[10];
	char pais[50];
	char confederacion[50];
	char convocados[10];

	Seleccion* pSeleccion;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);

		while(!feof(pFile))
		{
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);

			if(cantidadLeida == 4)
			{
				pSeleccion =  selec_newParametros(id, pais, confederacion, convocados);

				if(pSeleccion != NULL)
				{
					ll_add(pArrayListSeleccion, pSeleccion);
					retorno = 0;
				}
			}
		}
	}

    return retorno;
}


int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int retorno = 1;
	Jugador* pJugador;
	Seleccion* pSeleccion;
	char confederacion[100];
	char confederacionAux[100];
	LinkedList* auxListaSelecciones;
	LinkedList* auxListaJugadores;
	int idSelecciones;
	int idSelec;
	auxListaSelecciones = ll_clone(pArrayListSeleccion);
	auxListaJugadores = ll_clone(pArrayListJugador);

	utn_getOnlyString("Ingrese la confederacion de la seleccion (CAF - UEFA - CONMEBOL - AFC): \n", "Error, reingrese la confederacion de la seleccion: \n", 5,  100, confederacionAux);

	if(pArrayListJugador != NULL)
	{
		for(int i = 0; i < ll_len(auxListaSelecciones); i++)
		{
			pSeleccion = (Seleccion*)ll_get(auxListaSelecciones, i);
			selec_getConfederacion(pSeleccion, confederacion);
			selec_getId(pSeleccion, &idSelec);
			if(strcmp(confederacion, confederacionAux) == 0)
			{
				for(int j=0; j<ll_len(auxListaJugadores); j++)
				{
					pJugador = (Jugador*)ll_get(auxListaJugadores, j);
					jug_getIdSeleccion(pJugador, &idSelecciones);
					if(pJugador != NULL && pFile != NULL && idSelecciones == idSelec)
					{
						controller_listarJugadoresConvocados(auxListaJugadores, auxListaSelecciones);
						fwrite(pJugador, sizeof(Jugador), 1, pFile);
						retorno = 0;
						break;
					}
				}
			}
		}
	}

	return retorno;
}

int parser_JugadorToText(FILE* pFile, LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int cantidad;
	Jugador* pJugador;
	int id;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;

	if(pArrayListJugador != NULL)
	{
		cantidad = ll_len(pArrayListJugador);

		for(int i = 0; i < cantidad; i++)
		{
			pJugador = (Jugador*)ll_get(pArrayListJugador, i);
			if(pJugador != NULL && pFile != NULL)
			{
				jug_getId(pJugador,&id);
				jug_getNombreCompleto(pJugador, nombre);
				jug_getEdad(pJugador, &edad);
				jug_getPosicion(pJugador, posicion);
				jug_getNacionalidad(pJugador, nacionalidad);
				jug_getIdSeleccion(pJugador, &idSeleccion);

				fprintf(pFile, "%d,%s,%d,%s,%s,%d", id, nombre, edad,posicion,nacionalidad,idSeleccion);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int parser_SeleccionToText(FILE* pFile, LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int cantidad;
	Seleccion* pSeleccion;
	int id;
	char nombre[100];
	char nacionalidad[100];
	int idSeleccion;

	if(pArrayListSeleccion != NULL)
	{
		cantidad = ll_len(pArrayListSeleccion);

		for(int i = 0; i < cantidad; i++)
		{
			pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			if(pSeleccion != NULL && pFile != NULL)
			{
				selec_getId(pSeleccion,&id);
				selec_getPais(pSeleccion, nombre);
				selec_getConfederacion(pSeleccion, nacionalidad);
				selec_getConvocados(pSeleccion, &idSeleccion);

				fprintf(pFile, "%d,%s,%s,%d", id, nombre,nacionalidad,idSeleccion);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int parser_idFromText(FILE* pFile, char* id)
{

    int retorno =0;
	do{
		fflush(stdin);
		if(fgets(id,4,pFile)!=NULL){retorno=1;}
	}while(!feof(pFile));

	fclose(pFile);
	return retorno;
}



