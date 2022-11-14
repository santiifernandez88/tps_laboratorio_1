
#include "menu.h"


int menuInformes()
{
	int opcion;

	opcion = inputs_getNumberInt("Ingrese la opcion del listado que desea ver: \n"
			  "1) Todos los jugadores.\n"
			  "2) Todas las selecciones.\n"
			  "3) Los jugadore convocados.\n", "Error, reingrese una opcion: \n", 1, 3);

	return opcion;
}

int menuPrincipal()
{
	int opcion;

	opcion = inputs_getNumberInt(" \t\t---------------- MENU PRINCIPAL ----------------\t\t\n\n\n"
								"Antes de empezar a utilizar nuestro programa le recomiendo cargar los archivos antes de empezar a usar sus diversas utilidades.\n"
								"1) CARGAR ARCHIVOS.\n"
								"2) ALTA DE JUGADOR.\n"
								"3) MODFICAR JUGADOR.\n"
								"4) BAJA DE JUGADOR.\n"
								"5) LISTADO.\n"
								"6) CONVOCAR JUGADORES.\n"
								"7) ORDENAR Y LISTAR.\n"
								"8) GENERAR ARCHIVO BINARIO.\n"
								"9) CARGAR ARCHIVO BINARIO.\n"
								"10) GUARDAR ARCHIVOS .CSV.\n"
								"11) SALIR.\n"
								"Elija la opcion del menu a la que quiera ingresar: \n", "Error, reingrese la opcion valida.\n", 1, 11);

	return opcion;
}

int menuPorDefecto(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int opcion;

	opcion = inputs_getNumberInt(mensaje, mensajeError, minimo, maximo);

	return opcion;
}
