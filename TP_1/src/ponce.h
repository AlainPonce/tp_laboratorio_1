/*
 * ponce.h
 *
 *  Created on: 20 sep. 2021
 *      Author: alain
 */

#ifndef PONCE_H_
#define PONCE_H_

/** \brief Menu de opciones.
 *
 * \param flagPrimerOperador int Flag para modificar A=X y A=Int.
 * \param flagSegundoOperador int Flag para modificar B=Y y B=Int.
 * \param a int Valor entero del primer digito.
 * \param b int Valor entero del segundo digito.
 * \return int
 *
 */
int menu(int flagPrimerOperador, int flagSegundoOperador, int a, int b);

/** \brief Funcion suma de dos enteros.
 *
 * \param a int Valor entero del primer digito.
 * \param b int Valor entero del segundo digito.
 * \return int
 *
 */
int suma(int a, int b);

/** \brief Funcion resta de dos enteros.
 *
 * \param a int Valor entero del primer digito.
 * \param b int Valor entero del segundo digito.
 * \return int
 *
 */
int resta(int a, int b);

/** \brief Funcion de posible division de dos enteros.
 *
 * \param a int Valor entero del primer digito.
 * \param b int Valor entero del segundo digito.
 * \return float
 *
 */
int dividirRobusta (int a, int b, float* c);

/** \brief Funcion multiplicacion de dos enteros.
 *
 * \param a int Valor entero del primer digito.
 * \param b int Valor entero del segundo digito.
 * \return int
 *
 */
int multiplicacion(int a, int b);

/** \brief Funcion multiplicacion de dos enteros
 *
 * \param a int Valor entero de digito.
 * \return int
 *
 */
int factorial(int a);

#endif /* PONCE_H_ */
