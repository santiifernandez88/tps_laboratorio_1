#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "inputs.h"
#include "menu.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    int flag;
    int convocar;
    convocar = 0;
    flag = 0;


    printf("Antes de usar nuestro programa, le pedimos que cargue los archivos para poder utilizar las funciones que usted desee.\n");
    do
    {
    	option = menuPrincipal();

    	switch(option)
    	{
			case 1:
				if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 0 &&
					controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 0)
				{
					printf("Se cargaron los archivos correctamente.\n");
					flag = 1;
				}
				break;
			case 2:
				if(flag == 1)
				{
					controller_agregarJugador(listaJugadores);
				}
				break;
			case 3:
				if(flag == 1)
				{
					controller_editarJugador(listaJugadores);
				}
				break;
			case 4:
				if(flag == 1)
				{
					controller_removerJugador(listaJugadores, listaSelecciones);
				}
				break;
			case 5:
				if(flag == 1)
				{
					controller_listados(listaSelecciones, listaJugadores);
				}
				break;
			case 6:
				if(flag == 1)
				{
					convocar = menuPorDefecto("1.Convocar jugadores\n2.Desafectar de la seleccion\n", "Error elija una opcion valida.\n", 1,2);
					switch(convocar)
					{
					case 1:
						controller_convocarJugadores(listaJugadores, listaSelecciones);
						break;
					case 2:
						controller_editarSeleccion(listaSelecciones, listaJugadores);
						break;
					}
				}
				break;
			case 7:
				if(flag == 1)
				{
					controller_ordenarJugadores(listaJugadores, listaSelecciones);
				}
				break;
			case 8:
				if(flag == 1)
				{
					controller_guardarJugadoresModoBinario("jugadoresConvocados.bin" , listaJugadores, listaSelecciones);
				}
				break;
			case 9:
				if(flag == 1)
				{
					controller_cargarJugadoresDesdeBinario("jugadoresConvocados.bin" , listaJugadores);
				}
				break;
			case 10:
				if(flag == 1)
				{
					controller_guardarJugadoresModoTexto("jugadores.csv" , listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv" , listaSelecciones);
				}
				break;
			case 11:
				printf("GRACIAS POR USAR NUESTRO PROGRAMA!!!\n");
				ll_deleteLinkedList(listaJugadores);
				ll_deleteLinkedList(listaSelecciones);
				break;
    	}

    }while(option != 11);


    return 0;
}

