
#include "menu.h"


int menuInformes()
{
	int opcion;

	validarEntero("Ingrese la opcion del listado que desea ver: \n"
			  "1) Todos los jugadores.\n"
			  "2) Todas las selecciones.\n"
			  "3) Los jugadores convocados.\n", "Error, reingrese una opcion: \n", 1, 4, 5, &opcion);

	return opcion;
}

int menuPrincipal()
{
	int opcion;

	validarEntero("\n\n \t\t---------------- MENU PRINCIPAL ----------------\t\t\n\n\n"
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
								"Elija la opcion del menu a la que quiera ingresar: \n", "Error, reingrese la opcion valida.\n", 1, 11, 5, &opcion);

	return opcion;
}
