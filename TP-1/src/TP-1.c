/*
 ============================================================================
 Name        : TP-1.c
 Author      : Santiago Fernández
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "biblioteca.h"
#include "inputs.h"

int main(void) {
	setbuf(stdout,NULL);

	//Costos
	int hospedaje;
	int comida;
	int transporte;
	int mantenimiento;
	int mantenimientoAumento;
	int aumento;

	//Auxiliares
	int opcionSubMenu;
	int opcion;
	int bandera;

	//Jugadores
	int camisetas;
	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;
	int posicion;
	int jugadores;

	// Confederaciones
	int confederaciones;
	int contadorUefa;
	int contadorConmebol;
	int contadorConcacaf;
	int contadorAfc;
	int contadorOfc;
	int contadorCaf;
	float promedioUefa;
	float promedioAfc;
	float promedioConmebol;
	float promedioOfc;
	float promedioCaf;
	float promedioConcacaf;



	//Var promedios
	promedioUefa = 0;
	promedioAfc = 0;
	promedioConmebol = 0;
	promedioOfc = 0;
	promedioCaf = 0;
	promedioConcacaf = 0;

	//Jugadores
	jugadores = 0;

	//Confederaciones
	contadorUefa = 0;
	contadorConmebol = 0;
	contadorAfc = 0;
	contadorOfc = 0;
	contadorCaf = 0;
	contadorConcacaf = 0;


	//Posiciones
	arqueros = 0;
	defensores = 0;
	mediocampistas = 0;
	delanteros = 0;

	//Auxiliares
	opcionSubMenu = 0;
	opcion = 0;

	//Costos
	mantenimiento = 0;
	comida = 0;
	transporte = 0;
	hospedaje = 0;
	mantenimientoAumento = 0;
	aumento = 0;

	do{

		printf("\n                MENU PRINCIPAL              \n\n"
				"1. Ingreso de los costos de mantenimiento\n"
				"Costo de hospedaje -> $%d\n"
				"Costo de comida -> $%d\n"
				"Costo de transporte -> $%d\n"
				"\n2. Carga de jugadores\n"
				"Arqueros -> %d\n"
				"Defensores -> %d\n"
				"Mediocampistas -> %d\n"
				"Delanteros -> %d\n"
				"\n3. Calcular todo\n"
				"4. Mostrar resultados\n", hospedaje, comida, transporte, arqueros, defensores, mediocampistas, delanteros);
		validarEntero("Que opcion desea ingresar: \n", "Reingrese la opcion: \n", 1, 5, 5, &opcion);

	switch(opcion)
	{
		case 1:

			validarEntero("Que costo quiere ingresar: \n1. Hospedaje\n2. Comida\n3. Transporte\n", "Reingrese la opcion: \n1. Hospedaje\n2. Comida\n3. Transporte \n", 1, 3, 5, &opcionSubMenu);
			switch(opcionSubMenu)
			{
				case 1:
					validarEntero("Ingrese el costo de la hospedaje: \n", "Reingrese el costo de la hospedaje: \n", 0, 1000000, 5, &hospedaje);
					break;
				case 2:
					validarEntero("Ingrese el costo de la comida: \n", "Reingrese el costo de la comida: \n", 0, 1000000, 5, &comida);
					break;
				case 3:
					validarEntero("Ingrese el costo del transporte: \n", "Reingrese el costo del transporte: \n", 0, 1000000, 5, &transporte);
					break;
				default:
					printf("ERROR!! eliga el costo que quiere ingresar con las opciones que se muestan\n");
					break;
			}break;
		case 2:

			validarEntero("Ingrese el numero de la camiseta del jugador: \n", "Reingrese el numero de la camiseta del jugador: \n", 0, 100, 5, &camisetas);
			printf("La camiseta que usted eligio es: %d\n", camisetas);

			validarEntero("Ingrese la posicion en la que juega '1'(Arquero), '2'(Defensor), '3'(Mediocampistas) y '4'(Delantero): \n", "Reingrese la posicion en la que juega '1'(Arquero), '2'(Defensor), '3'(Mediocampistas) y '4'(Delantero): \n", 1, 4, 5, &posicion);
			bandera = MenuPosiciones(posicion, &arqueros, &defensores, &mediocampistas, &delanteros);

			if(bandera == 1)
			{

				validarEntero("Ingrese la confederacion a la que pertenece: \n 1. UEFA\n 2. Conmebol\n 3. Concacaf\n 4. AFC\n 5. CAF\n 6. OFC\n", "Reingrese la confederacion a la que pertenece: \n 1. UEFA\n 2. Conmebol\n 3. Concacaf\n 4. AFC\n 5. CAF\n 6. OFC\n", 1, 6, 5, &confederaciones);
				switch(confederaciones)
				{
				case 1:
					contadorUefa ++;
					break;
				case 2:
					contadorConmebol ++;
					break;
				case 3:
					contadorConcacaf++;
					break;
				case 4:
					contadorAfc ++;
					break;
				case 5:
					contadorCaf ++;
					break;
				case 6:
					contadorOfc ++;
					break;
				default:
					printf("ERROR!!! el dato que usted ingreso es invalido, ingrese un dato valido.\n");
					break;
				}
				jugadores ++;
			}
			break;
		case 3:

			if((hospedaje > 0 && transporte > 0 && comida > 0) && jugadores > 0)
			{
				mantenimiento = SumarCostos(comida, hospedaje, transporte);

				promedioUefa = promediarConfederaciones(contadorUefa, jugadores);
				promedioConmebol = promediarConfederaciones(contadorConmebol, jugadores);
				promedioConcacaf = promediarConfederaciones(contadorConcacaf, jugadores);
				promedioAfc = promediarConfederaciones(contadorAfc, jugadores);
				promedioCaf = promediarConfederaciones(contadorCaf, jugadores);
				promedioOfc = promediarConfederaciones(contadorOfc, jugadores);

				mantenimientoAumento = AumentarMantenimiento( contadorUefa,  contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc,  contadorCaf, mantenimiento);
				aumento = mantenimientoAumento - mantenimiento;

			}
			else
			{
				printf("Para que se calcule todo, usted debe ingresar los gastos y cargar al menos un jugador del equipo.\n");
			}
			break;
		case 4:
			if(mantenimiento > 0 && jugadores > 0)
			{
				printf("\n\t\t Informar resultados \n\n"
						"Promedio Uefa %.2f\n"
						"Promedio Conmebol %.2f\n"
						"Promedio Concacaf %.2f\n"
						"Promedio Afc %.2f\n"
						"Promedio Ofc %.2f\n"
						"Promedio Caf %.2f\n"
						"El costo de mantenimiento era de %d y recibio un aumento de %d, su nuevo valor es de: %d\n", promedioUefa, promedioConmebol, promedioConcacaf,
																													promedioAfc, promedioCaf, promedioOfc,
																													mantenimiento, aumento, mantenimientoAumento);
			}
			else
			{
				printf("Para que se informen los resultados, usted debe ingresar los gastos y cargar al menos un jugador del equipo.\n");
			}
			break;
	}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}
