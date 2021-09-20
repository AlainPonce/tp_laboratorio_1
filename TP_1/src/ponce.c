/*
 * ponce.c
 *
 *  Created on: 20 sep. 2021
 *      Author: alain
 */

#include <stdio.h>
#include <stdlib.h>
#include "ponce.h"

int menu (int flagPrimerOperador, int flagSegundoOperador, int a, int b)
{
    int operador;

    system("cls");
    printf("    *** Menu de Calculadora***\n\n");
    if(flagPrimerOperador)
    {
        printf("1. Ingresar el primer operando (A = %d)\n", a);
    }
    else
    {
        printf("1. Ingresar el primer operando (A = X)\n");
    }
    if(flagSegundoOperador)
    {
        printf("2. Ingresar el segundo operando (B = %d)\n\n", b);
    }
    else
    {
        printf("2. Ingresar el segundo operando (B = Y)\n\n");
    }

    printf("3. Calcular todas las operaciones.\n");

    if(flagPrimerOperador==0)
    {
        if(flagSegundoOperador==0)
        {
            printf("    a. Calcular la suma (A + B).\n");
            printf("    b. Calcular la resta (A - B).\n");
            printf("    c. Calcular la division (A / B).\n");
            printf("    d. Calcular la multiplicacion (A * B).\n");
            printf("    e. Calcular el factorial (A! y B!).\n\n");
        }
    }
    else
    {
        if(flagSegundoOperador==0)
        {
            printf("    a. Calcular la suma (%d + B).\n", a);
            printf("    b. Calcular la resta (%d - B).\n", a);
            printf("    c. Calcular la division (%d / B).\n", a);
            printf("    d. Calcular la multiplicacion (%d * B).\n", a);
            printf("    e. Calcular el factorial (%d! + B!).\n\n", a);
        }
        else
        {
            printf("    a. Calcular la suma (%d + %d).\n", a, b);
            printf("    b. Calcular la resta (%d - %d).\n", a, b);
            printf("    c. Calcular la division (%d / %d).\n", a, b);
            printf("    d. Calcular la multiplicacion (%d * %d).\n", a, b);
            printf("    e. Calcular el factorial (%d! + %d!).\n\n", a, b);
        }
    }

    printf("4. Informar resultados.\n");

    printf("5. Salir.\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &operador);
    printf("\n");

    return operador;
}
int suma(int a, int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}
int resta(int a, int b)
{
    int resultado;

    resultado = a - b;

    return resultado;
}
int dividirRobusta (int a, int b, float* c)
{
    int todoOk = 0;

    if(b != 0 && c != NULL)
    {
        *c = (float) a / b;
        todoOk = 1;
    }
    return todoOk;
}
int multiplicacion(int a, int b)
{
    int resultado;

    resultado = a * b;

    return resultado;
}
int factorial(int a)
{
	int resultado = 1; //por si el numero ingresado es 0 y no entra al for. El factorial de dicho numero es =1
	for(int i = 1; i <= a; i++)
	{
		resultado *= i;
	}

    return resultado;
}


