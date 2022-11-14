#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int realizado;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "r");
		realizado = parser_JugadorFromText(pFile, pArrayListJugador);
		if(realizado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int realizado;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "rb");
		realizado = parser_JugadorFromBinary(pFile, pArrayListJugador);
		if(realizado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	char id[10];
	int idAux;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	char edad[10];
	char idSeleccion[10];
	int retorno = 1;

	if(controller_cargarIdJugadorModoTexto("idJugador.csv",id))
	{
	idAux =atoi(id);
	idAux++;
	sprintf(id,"%d",idAux);
	}

	utn_getOnlyString("Ingrese el nombre del jugador: \n", "Error, reingrese el nombre del jugador: \n", 3,  100, nombre);
	utn_getOnlyString("Ingrese la edad del jugador: \n", "Error, reingrese el nombre del jugador: \n", 3,  100, edad);
	utn_getOnlyString("Ingrese la posicion en la que juega el jugador: \n", "Error, reingrese la posicion del jugador: \n", 3,  100, posicion);
	utn_getOnlyString("Ingrese la nacionalidad del jugador: \n", "Error, reingrese la nacionalidad del jugador: \n", 3,  100, nacionalidad);
	strcpy(idSeleccion, "0");

	pJugador = jug_newParametros(id, nombre, edad, posicion,nacionalidad, idSeleccion);
	if(pJugador != NULL)
	{
		controller_cargarIdJugadorModoTexto("idJugadores.csv", id);
		ll_add(pArrayListJugador, pJugador);
		retorno = 0;
	}

    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int idAModificar;
	int id;
	int respuesta;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int retorno = 1;

	mostrarTodosLosJugadores(pArrayListJugador);
	idAModificar = inputs_getNumberInt("Ingrese el id del jugador a modificar: \n", "Error vuelva a ingresar un id valido.\n", 1, 500);

	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		jug_getId(pJugador, &id);
		if(id == idAModificar)
		{
			printf("El jugador que usted quiere modificar es\n");
			jug_printOne(pJugador);
			respuesta = inputs_getNumberInt("Usted esta seguro que quiere modificar? \n 1.Nombre \t\t 2.Edad \t\t 3.Posicion \t\t 4.Nacionalidad\n", "Error vuelva a ingresar una opcion.\n", 1, 4);
			switch(respuesta)
			{
			case 1:
				utn_getOnlyString("Ingrese el nombre que le quiere modificar al jugador: \n", "Error, reingrese el nombre a modificar: \n", 3,  100, nombre);
				jug_setNombreCompleto(pJugador, nombre);
				break;
			case 2:
				edad = inputs_getNumberInt("Ingrese la edad a modificar del jugador: \n", "Error vuelva a ingresar la edad a modificar.\n", 16, 40);
				jug_setEdad(pJugador, edad);
				break;
			case 3:
				utn_getOnlyString("Ingrese la posicion que le quiere modificar al jugador: \n", "Error, reingrese la posicion a modificar: \n", 3,  100, posicion);
				jug_setPosicion(pJugador, posicion);
				break;
			case 4:
				utn_getOnlyString("Ingrese la nacionalidad que le quiere modificar al jugador: \n", "Error, reingrese la nacionalidad a modificar: \n", 3,  100, nacionalidad);
				jug_setNacionalidad(pJugador, nacionalidad);
				break;
			}
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones)
{
	Seleccion* pSeleccion;
	Jugador* pJugador;
	int idAEliminar;
	int id;
	int idSelec;
	int idSeleccion;
	int respuesta;
	int retorno = 1;
	int convocados;

	controller_listarJugadores(pArrayListJugador, pArrayListSelecciones);
	idAEliminar = inputs_getNumberInt("Ingrese el id del jugador a eliminar: \n", "Error vuelva a ingresar un id valido.\n", 1, 500);
	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		jug_getId(pJugador, &id);
		for(int j=0; j<ll_len(pArrayListSelecciones); j++)
		{
			pSeleccion = (Seleccion*)ll_get(pArrayListSelecciones, j);
			selec_getId(pSeleccion, &idSelec);
			selec_getConvocados(pSeleccion, &convocados);
			jug_getIdSeleccion(pJugador, &idSeleccion);
			if(id == idAEliminar && idSeleccion == idSelec)
			{
				printf("El jugador que usted quiere dar de baja es\n");
				jug_printOne(pJugador);
				respuesta =inputs_getNumberInt("Usted esta seguro que quiere elimarlo? \n 1.CONFIRMAR \t\t 2.SALIR\n", "Error vuelva a ingresar una opcion.\n", 1, 2);
				if(respuesta == 1)
				{
					printf("Eliminado correctamente\n");
					convocados --;
					selec_setConvocados(pSeleccion, convocados);
					ll_remove(pArrayListJugador,i);
					jug_delete(pJugador);
					retorno = 0;
					break;
				}
			}
		}
	}

    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Jugador* pJugador;
	int retorno = 1;
	int cantidad;

	printf("\n\n ---------JUGADORES---------\n");

	if(pArrayListJugador != NULL)
	{
		cantidad = ll_len(pArrayListJugador);

		for(int i = 0; i < cantidad; i++)
		{
			pJugador = (Jugador*)ll_get(pArrayListJugador, i);
			if(pJugador != NULL)
			{
				mostrarJugadoresNoConvocados(pArrayListJugador);
				controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
				retorno = 1;
				break;
			}
			else
			{
				printf("No hay jugadores en la lista.\n");
			}
		}
	}
	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int retorno = 0;
	int opcion;
	LinkedList* misJugadores;
	LinkedList* misSelecciones;

	if(pArrayListJugador != NULL)
	{
		opcion = inputs_getNumberInt("\nSeleccion el criterio de ordenamiento:\n1.JUGADOR POR NACIONALIDAD\n2.JUGADOR POR EDAD\n3.JUGADOR POR NOMBRE\n4.SELECCIONES POR CONFEDERACION", "Error. Ingrese entre 1 y 4.\n", 1, 4);

		switch (opcion)
		{
			case 1:
				misJugadores = ll_clone(pArrayListJugador);
				misSelecciones = ll_clone(pArrayListSeleccion);
				ll_sort(misJugadores, jugador_CompareByNacionalidad, 0);
				controller_listarJugadores(misJugadores, misSelecciones);
				ll_clear(misJugadores);
				ll_clear(misSelecciones);
				break;
			case 2:
				misJugadores = ll_clone(pArrayListJugador);
				misSelecciones = ll_clone(pArrayListSeleccion);
				ll_sort(misJugadores, jugador_CompareByEdad, 0);
				controller_listarJugadores(misJugadores, misSelecciones);
				ll_clear(misJugadores);
				ll_clear(misSelecciones);
				break;
			case 3:
				misJugadores = ll_clone(pArrayListJugador);
				misSelecciones = ll_clone(pArrayListSeleccion);
				ll_sort(misJugadores, jugador_CompareByNombre, 0);
				controller_listarJugadores(misJugadores, misSelecciones);
				ll_clear(misJugadores);
				ll_clear(misSelecciones);
				break;
			case 4:
				misSelecciones = ll_clone(pArrayListSeleccion);
				controller_ordenarSelecciones(misSelecciones);
				ll_clear(misSelecciones);
				break;
		}

	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int realizado;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "w");
		realizado = parser_JugadorToText(pFile, pArrayListJugador);
		if(realizado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int realizado;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "wb");
		realizado = parser_JugadorToBinary(pFile, pArrayListJugador, pArrayListSeleccion);
		if(realizado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int realizado;
	FILE* pFile;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pFile = fopen(path, "r");
		realizado = parser_SeleccionFromText(pFile, pArrayListSeleccion);
		if(realizado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	Seleccion* pSeleccion;
	int id;
	int retorno = 1;
	int idSeleccionJugador;
	int idSelec;
	int convocados;
	int idJugadorADesconvocar;

	listarJugadoresConvocados(pArrayListJugador);
	idJugadorADesconvocar = buscarIdJugador(pArrayListJugador, "Ingrese el id del jugador que quiera desafectar de su convocatoria: \n");

	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = ll_get(pArrayListJugador,i);
		if(pJugador != NULL)
		{
			jug_getIdSeleccion(pJugador, &idSeleccionJugador);
			jug_getId(pJugador, &id);
			for(int j=0; j<ll_len(pArrayListSeleccion); j++)
			{
				pSeleccion = ll_get(pArrayListSeleccion, j);
				if(pSeleccion != NULL)
				{
					selec_getConvocados(pSeleccion, &convocados);
					selec_getId(pSeleccion, &idSelec);
					if(idSeleccionJugador > 0 && idSeleccionJugador == idSelec && id == idJugadorADesconvocar && convocados <= 22)
					{
						jug_setIdSeleccion(pJugador, 0);
						printf("El jugador fue desafectado correctamente.\n");
						convocados --;
						selec_setConvocados(pSeleccion, convocados);
						jug_printOne(pJugador);
						retorno = 0;
						break;
					}
				}
			}
		}
	}
    return retorno;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int cantidad;
	Seleccion* pSeleccion;

	printf("\n\n ---------SELECCIONES---------\n");

	if(pArrayListSeleccion != NULL)
	{
		cantidad = ll_len(pArrayListSeleccion);

		for(int i = 0; i < cantidad; i++)
		{
			pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			if(pSeleccion != NULL)
			{
				seleccion_printOne(pSeleccion);
				retorno = 0;
			}
		}
	}

	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	if(pArrayListSeleccion != NULL)
	{
		ll_sort(pArrayListSeleccion, seleccion_CompareByConfederacion, 0);

		retorno = 0;
	}
	return retorno;

}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int realizado;
	FILE* pFile;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pFile = fopen(path, "w");
		realizado = parser_SeleccionToText(pFile, pArrayListSeleccion);
		if(realizado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}


void controller_listados(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int opcion;

	opcion = menuInformes();

	switch(opcion)
	{
	case 1:
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
		break;
	case 2:
		controller_listarSelecciones(pArrayListSeleccion);
		break;
	case 3:

		break;
	}

}

int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Jugador* pJugador;
	Seleccion* pSeleccion;
	int idJugadorAConvocar;
	int id;
	int idSeleccion;
	int idSeleccionJugador;
	int idSelec;
	int convocados;

	mostrarJugadoresNoConvocados(pArrayListJugador);
	idJugadorAConvocar = buscarIdJugador(pArrayListJugador, "Ingrese el id del jugador a convocar: \n");
	controller_listarSelecciones(pArrayListSeleccion);
	idSeleccion = buscarIdSeleccion(pArrayListSeleccion);

	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = ll_get(pArrayListJugador,i);
		jug_getIdSeleccion(pJugador, &idSeleccionJugador);
		jug_getId(pJugador, &id);
		for(int j=0; j<ll_len(pArrayListSeleccion); j++)
		{
			pSeleccion = ll_get(pArrayListSeleccion, j);
			selec_getConvocados(pSeleccion, &convocados);
			selec_getId(pSeleccion, &idSelec);

			if(idSeleccionJugador == 0 && id == idJugadorAConvocar && idSeleccion == idSelec &&convocados < 22)
			{
				jug_setIdSeleccion(pJugador, idSeleccion);
				printf("El jugador fue convocado correctamente.\n");
				convocados ++;
				selec_setConvocados(pSeleccion, convocados);
				controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
				break;
			}
		}
	}

	return 1;
}

int controller_cargarIdJugadorModoTexto(char* path, char* id)
{
	int retorno =1;
	FILE* pArchivo;

	if((pArchivo=fopen(path,"r"))!=NULL)
	{
		parser_idFromText(pArchivo,id);
		retorno= 0;
	}
	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;

	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;

	int idSelec;
	char pais[30];
	char confederacion[30];
	int convocados;


	if (pArrayListJugador != NULL && pArrayListSeleccion!= NULL)
	{
		for (int i = 0; i < ll_len(pArrayListJugador); i++)//jugadores
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(pJugador, &id);
			jug_getNombreCompleto(pJugador, nombreCompleto);
			jug_getEdad(pJugador, &edad);
			jug_getPosicion(pJugador, posicion);
			jug_getNacionalidad(pJugador, nacionalidad);
			jug_getIdSeleccion(pJugador, &idSeleccion);


			for (int j = 0; j < ll_len(pArrayListSeleccion); j++)//selecciones
			{
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);
				selec_getId(pSeleccion, &idSelec);
				selec_getPais(pSeleccion, pais);
				selec_getConfederacion(pSeleccion, confederacion);
				selec_getConvocados(pSeleccion, &convocados);
				if(idSelec == idSeleccion)
				{
					printf("%4d %25s %10d %25s %25s %10s \n", id, nombreCompleto, edad, posicion, nacionalidad, pais);

				}


			}
		 }
		retorno = 0;
	}

	return retorno;
}

