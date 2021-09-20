/*
 ============================================================================
 Name        : TP_1.c
 Author      : Alain Fernando Ponce
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ponce.h"
int main(void)
{
	setbuf(stdout, NULL);

	int primerNumero; // A = X
	int segundoNumero; // B = Y

	int flagComando1 = 0;
	int flagComando2 = 0;

	int flagPrimerNumero = 0;
	int flagSegundoNumero = 0;
	int flagCalcular = 0;

	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int divisionPosible;
	int resultadoMultiplicacion;
	int resultadoFactorial;
	int resultadoFactorial2;

	char salir = 'n';

	do
	{
		switch(menu(flagComando1, flagComando2, primerNumero, segundoNumero))
		{
			case 1:
				printf("Ingrese el primer digito: ");
				while(scanf("%d", &primerNumero) == 0)
				{
					printf("Error. Ingrese el primer digito correctamente: ");
					fflush(stdin);
				}
				flagPrimerNumero = 1;
				flagComando1=1;
				system("pause");
				break;

			case 2:
				if(flagPrimerNumero)
				{
					printf("Ingrese el segundo digito: ");
					while(scanf("%d", &segundoNumero) == 0)
					{
						printf("Error. Ingrese el segundo digito correctamente: ");
						fflush(stdin);
					}
					flagSegundoNumero = 1;
					flagComando2 = 1;
				}
				else
				{
					printf("Antes de ingresar el segundo digito, debemos ingresar el primero.\n\n");
				}
				system("pause");
				break;

			case 3:
				if(flagPrimerNumero && flagSegundoNumero)
				{
					printf("Calculando...\n\n");
					resultadoSuma = suma(primerNumero, segundoNumero);
					resultadoResta = resta(primerNumero, segundoNumero);
					divisionPosible= dividirRobusta(primerNumero, segundoNumero, &resultadoDivision);
					resultadoMultiplicacion = multiplicacion(primerNumero, segundoNumero);
					resultadoFactorial = factorial(primerNumero);
					resultadoFactorial2 = factorial(segundoNumero);
					flagCalcular=1;
				}
				else
				{
					printf("Antes de calcular, debe ingresar el primer y segundo digito.\n\n");
				}
				system("pause");
				break;

			case 4:
				if(flagCalcular)
				{
					printf("Los resultados de las operaciones son los siguientes: \n");
					printf("    a. El resultado de %d + %d es: %d\n", primerNumero, segundoNumero, resultadoSuma);
					printf("    b. El resultado de %d - %d es: %d\n", primerNumero, segundoNumero, resultadoResta);
					if(divisionPosible)
					{
						printf("    c. El resultado de %d / %d es: %.2f\n", primerNumero, segundoNumero, resultadoDivision);
					}
					else
					{
						printf("    c. No se puede dividir por 0!\n");
					}

					printf("    d. El resultado de %d * %d es: %d\n", primerNumero, segundoNumero, resultadoMultiplicacion);

					if(primerNumero<0)
					{
						if(segundoNumero<0)
						{
							printf("    e. No es posible realizar el factorial de %d y de %d ya que ambos son negativos", primerNumero, segundoNumero);
						}
						else
						{
							printf("    e. No es posible realizar el factorial de %d ya que es negativo. El factorial de %d es %d.\n\n", primerNumero, segundoNumero, resultadoFactorial2);
						}
					}
					else
					{
						if(segundoNumero<0)
						{
							printf("    e. El factorial de %d es: %d. No es posible realizar el factorial de %d ya que es negativo. .\n\n", primerNumero, resultadoFactorial, segundoNumero);
						}
						else
						{
							printf("    e. El factorial de %d es: %d, y el factorial de %d es: %d\n\n", primerNumero, resultadoFactorial, segundoNumero, resultadoFactorial2);
						}
					}

					flagPrimerNumero = 0;
					flagSegundoNumero = 0;
					flagCalcular = 0;
					flagComando1 = 0;
					flagComando2 = 0;
				}
				else
				{
					printf("No se pueden mostrar los resultados si no se completan todos los pasos anteriores..\n\n");
				}
				system("pause");
				break;

			case 5:
				printf("Confirma salida?");
				fflush(stdin);
				salir=getchar();
				break;

			default:
				printf("Opcion Invalida!\n");
				system("pause");
		}

	}while(salir=='n');

	return EXIT_SUCCESS;
}
