/*
 * jugadores.h
 *
 *  Created on: 17 sep. 2022
 *      Author: santr
 */
/**
 * @fn int contadorArqueros(int)
 * @brief  Se fija si el usuario ingreso la opcion valida y cuenta los arqueros
 *
 * @param posicion
 * @return el contador de arqueros
 */
int validarPosiciones(int* jugador, int max, char* mensaje);

/// @fn int MenuPosiciones(int, int*, int*, int*, int*)
/// @brief Valida que el usuario no pueda ingresar mas posiciones que el maximo de cada una
///
/// @param posicion
/// @param contadorArqueros
/// @param contadorDefensor
/// @param contadorMediocampistas
/// @param contadorDelanteros
/// @return bandera que valida que el usuario no pueda ingresar mas posiciones que el maximo de cada una
int MenuPosiciones(int posicion, int* contadorArqueros, int* contadorDefensor, int* contadorMediocampistas, int* contadorDelanteros);

/// @fn float promediarConfederaciones(int, int)
/// @brief  Promedia las confederaciones
///
/// @param confederacion
/// @param jugadores
/// @return el promedio de una confederacion
float promediarConfederaciones(int confederacion, int jugadores);

/// @fn int AumentarMantenimiento(int, int, int, int, int, int, int)
/// @brief Si se cumple el if, le da un 35% de aumento al mantenimiento del equipo
///
/// @param contadorEuropa
/// @param contadorSudAmerica
/// @param contadorNorAmerica
/// @param contadorAfrica
/// @param contadorOceania
/// @param contadorAsia
/// @param mantenimiento
/// @return el valor del aumento al mantenimiento
int AumentarMantenimiento(int contadorEuropa, int contadorSudAmerica, int contadorNorAmerica, int contadorAfrica, int contadorOceania, int contadorAsia, int mantenimiento);

/// @fn int SumarCostos(int, int, int)
/// @brief
///
/// @param costoUno
/// @param costoDos
/// @param costoTres
/// @return La suma de los tres gastos
int SumarCostos(int costoUno, int costoDos, int costoTres);
