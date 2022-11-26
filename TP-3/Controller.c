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
	char edadAux[10];
	int edad;
	char idSeleccion[10];
	int retorno = 1;

	if(controller_cargarIdJugadorModoTexto("idJugador.csv",id) == 0)
	{
	idAux =atoi(id);
	idAux++;
	sprintf(id,"%d",idAux);
	}

	utn_getOnlyString("Ingrese el nombre del jugador: \n", "Error, reingrese el nombre del jugador: \n", 3,  100, nombre);
	validarEntero("Ingrese la edad del jugador: \n", "Error, reingrese el nombre del jugador: \n", 1,  100, 5, &edad);
	sprintf(edadAux, "%d", edad);
	utn_getOnlyString("Ingrese la posicion en la que juega el jugador: \n", "Error, reingrese la posicion del jugador: \n", 3,  100, posicion);
	utn_getOnlyString("Ingrese la nacionalidad del jugador: \n", "Error, reingrese la nacionalidad del jugador: \n", 3,  100, nacionalidad);
	strcpy(idSeleccion, "0");

	pJugador = jug_newParametros(id, nombre, edadAux, posicion,nacionalidad, idSeleccion);
	if(pJugador != NULL)
	{

		controller_guardarIdJugadorModoTexto("idJugador.csv", id);
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

	mostrarJugadoresSinIdSeleccion(pArrayListJugador);
	validarEntero("Ingrese el id del jugador a modificar: \n", "Error vuelva a ingresar un id valido.\n", 1, 500, 5, &idAModificar);

	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		jug_getId(pJugador, &id);
		if(id == idAModificar)
		{
			printf("El jugador que usted quiere modificar es\n");
			jug_printOne(pJugador);
			validarEntero("Usted que quiere modificar del jugador? \n 1.Nombre \t\t 2.Edad \t\t 3.Posicion \t\t 4.Nacionalidad\n", "Error vuelva a ingresar una opcion.\n", 1, 4, 5, &respuesta);
			switch(respuesta)
			{
			case 1:
				utn_getOnlyString("Ingrese el nombre que le quiere modificar al jugador: \n", "Error, reingrese el nombre a modificar: \n", 3,  100, nombre);
				jug_setNombreCompleto(pJugador, nombre);
				break;
			case 2:
				validarEntero("Ingrese la edad a modificar del jugador: \n", "Error vuelva a ingresar la edad a modificar.\n", 16, 40, 5, &edad);
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
			printf("Se modifico correctamente el jugador.\n");
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
	validarEntero("Ingrese el id del jugador a eliminar: \n", "Error vuelva a ingresar un id valido.\n", 1, 500, 5, &idAEliminar);
	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		jug_getId(pJugador, &id);
		if(id == idAEliminar)
		{
			for(int j=0; j<ll_len(pArrayListSelecciones); j++)
			{
				pSeleccion = (Seleccion*)ll_get(pArrayListSelecciones, j);
				selec_getId(pSeleccion, &idSelec);
				selec_getConvocados(pSeleccion, &convocados);
				jug_getIdSeleccion(pJugador, &idSeleccion);
				if(idSelec == idSeleccion || idSeleccion == 0)
				{
					printf("El jugador que usted quiere dar de baja es\n");
					mostrarUnJugadorConPais(pJugador, pSeleccion);
					validarEntero("Usted esta seguro que quiere elimarlo por mas que este convocado o no? \n 1.CONFIRMAR \t\t 2.SALIR\n", "Error vuelva a ingresar una opcion.\n", 1, 2, 5, &respuesta);
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
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			printf("El jugador no existe...\n");
			break;
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
	int opcionAux;
	LinkedList* misJugadores;
	LinkedList* misSelecciones;

	misJugadores = ll_clone(pArrayListJugador);
	misSelecciones = ll_clone(pArrayListSeleccion);

	if(pArrayListJugador != NULL)
	{
		validarEntero("\nSeleccion el criterio de ordenamiento:\n1.JUGADOR POR NACIONALIDAD\n2.JUGADOR POR EDAD\n3.JUGADOR POR NOMBRE\n4.SELECCIONES POR CONFEDERACION", "Error. Ingrese entre 1 y 4.\n", 1, 4, 5, &opcion);
		validarEntero("De que forma quiere ordenar:\n1.ASCENDENTE\n2.DESCENDENTE\n", "Error. Ingrese entre 1 y 2.\n", 1, 2, 5, &opcionAux);
		switch (opcion)
		{
			case 1:
				if(opcionAux == 1)
				{
					ll_sort(misJugadores, jugador_CompareByNacionalidad, 1);
				}
				else
				{
					ll_sort(misJugadores, jugador_CompareByNacionalidad, 0);
				}
				mostrarJugadoresSinIdSeleccion(misJugadores);
				break;
			case 2:
				if(opcionAux == 1)
				{
					ll_sort(misJugadores, jugador_CompareByEdad, 1);
				}
				else
				{
					ll_sort(misJugadores, jugador_CompareByEdad, 0);
				}
				mostrarJugadoresSinIdSeleccion(misJugadores);
				break;
			case 3:
				if(opcionAux == 1)
				{
					ll_sort(misJugadores, jugador_CompareByNombre, 1);
				}
				else
				{
					ll_sort(misJugadores, jugador_CompareByNombre, 0);
				}
				mostrarJugadoresSinIdSeleccion(misJugadores);
				break;
			case 4:
				if(opcionAux == 1)
				{
					controller_ordenarSelecciones(misSelecciones, 1);
				}
				else
				{
					controller_ordenarSelecciones(misSelecciones, 0);
				}
				controller_listarSelecciones(misSelecciones);
				break;
		}
		ll_clear(misJugadores);
		ll_clear(misSelecciones);

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

	controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
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
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion, int orden)
{
	int retorno = -1;

	if(pArrayListSeleccion != NULL)
	{
		ll_sort(pArrayListSeleccion, seleccion_CompareByConfederacion, orden);
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
/// @fn void controller_listados(LinkedList*, LinkedList*)
/// @brief menu para listar
///
/// @param pArrayListSeleccion
/// @param pArrayListJugador
void controller_listados(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int opcion;
	int realizado;

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
		realizado = controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
		if(realizado == -1)
		{
			printf("No hay jugadores convocados.\n");
		}
		break;
	}

}
/// @fn int controller_convocarJugadores(LinkedList*, LinkedList*)
/// @brief convoca jugadores
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return int
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
	int flag;

	mostrarJugadoresNoConvocados(pArrayListJugador);
	idJugadorAConvocar = buscarIdJugador(pArrayListJugador, "Ingrese el id del jugador a convocar: \n");

	for(int i=0;i<ll_len(pArrayListJugador);i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		jug_getIdSeleccion(pJugador, &idSeleccionJugador);
		jug_getId(pJugador, &id);
		if(idSeleccionJugador == 0 && id == idJugadorAConvocar)
		{
			controller_listarSelecciones(pArrayListSeleccion);
			idSeleccion = buscarIdSeleccion(pArrayListSeleccion);
			for(int j=0; j<ll_len(pArrayListSeleccion); j++)
			{
				pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, j);

				selec_getId(pSeleccion, &idSelec);
				if(idSeleccion == idSelec)
				{
					selec_getConvocados(pSeleccion, &convocados);
					if(convocados < 22)
					{
						jug_setIdSeleccion(pJugador, idSeleccion);
						printf("El jugador fue convocado correctamente.\n");
						convocados ++;
						flag = 1;
						selec_setConvocados(pSeleccion, convocados);
						break;
					}
					else
					{
						printf("La seleccion no tiene mas cupos para seguir convocando jugadores.\n");
						break;
					}
				}
			}
		}
	}
	if(flag == 0 && id != idJugadorAConvocar)
	{
		printf("El jugador no existe o ya esta convocado... \n");
	}

	return 1;
}
/// @fn int controller_guardarIdJugadorModoTexto(char*, char*)
/// @brief guarda el id del jugador en modo texto
///
/// @param path
/// @param id
/// @return int
int controller_guardarIdJugadorModoTexto(char* path, char* id)
{
	int retorno = 1;
	int realizado;
	FILE* pFile;

	pFile = fopen(path, "w");
	realizado = parser_idToText(pFile, id);
	if(realizado == 1)
	{
		fclose(pFile);
		retorno = 0;
	}

	return retorno;
}
/// @fn int controller_cargarIdJugadorModoTexto(char*, char*)
/// @brief carga el id del jugador en modo texto
///
/// @param path
/// @param id
/// @return int
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
/// @fn int controller_listarJugadoresConvocados(LinkedList*, LinkedList*)
/// @brief lista los jugadores convocados
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return int
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
					retorno = 0;
				}


			}
		 }

	}

	return retorno;
}
/// @fn int buscarIdJugador(LinkedList*, char*)
/// @brief  busca el id de un jugador
///
/// @param pArrayListJugador
/// @param mensaje
/// @return el id encontrado
int buscarIdJugador(LinkedList* pArrayListJugador, char* mensaje)
{
	Jugador* pJugador;
	int idAux;
	int id;

	validarEntero(mensaje, "Error, vuelva a ingresar un id valido.\n", 1, 500, 5, &idAux);

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
/// @fn void mostrarJugadoresNoConvocados(LinkedList*)
/// @brief  muestra la lista de jugadores no convocados
///
/// @param pArrayListJugador
void mostrarJugadoresNoConvocados(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int idSeleccion;

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
/// @fn void mostrarJugadoresSinIdSeleccion(LinkedList*)
/// @brief muestra la lista pero sin el campo de la id de la seleccion
///
/// @param pArrayListJugador
void mostrarJugadoresSinIdSeleccion(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;

	for(int i= 0; i<ll_len(pArrayListJugador); i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);
		mostrarJugadorSinIdSeleccion(pJugador);
	}

}
