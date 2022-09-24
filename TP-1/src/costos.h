/*
 * costos.h
 *
 *  Created on: 15 sep. 2022
 *      Author: santr
 */

/// @fn int ingresarCostoHospedaje()
/// @brief Pide un numero para el gasto del hospedaje
///
/// @return El gasto de hospedaje
int ingresarCostoHospedaje();

/// @fn int ingresarCostoComida()
/// @brief Pide un numero para el gasto de comida
///
/// @return El gasto de comida
int ingresarCostoComida();

/// @fn int ingresarCostoTransporte()
/// @brief Pide un numero para el gasto de transporte
///
/// @return El gasto de transporte
int ingresarCostoTransporte();

/// @fn int SumarCostos(int, int, int)
/// @brief
///
/// @param costoUno
/// @param costoDos
/// @param costoTres
/// @return La suma de los tres gastos
int SumarCostos(int costoUno, int costoDos, int costoTres);
