/*
 ============================================================================
 Name        : TP_2.c
 Author      : Alain Fernando Ponce
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define LEN 10
#define LENC 51

int menu();
int informes();
int informeAlfa();

int main(void)
{
	setbuf(stdout, NULL);
    int id = 1;
    char nombre[LENC];
    char apellido[LENC];
    float sueldo=0;
    int lugar=0;
    int flagEmpleado=0;
    char salir='n';

    Employee nomina[LEN];
    initEmployees(nomina, LEN);

    do
    {
        switch(menu())
        {
case 1:
                if(!addEmployee(nomina, LEN, &id, nombre, apellido, sueldo, lugar))
                {
                    printf("Alta exitosa!\n\n");
                    flagEmpleado = 1;
                }
                else
                {
                    printf("Hubo un problema con el alta.\n\n");

                }
                system("pause");
                break;

            case 2:
                if(flagEmpleado == 1 && modificarEmployee(nomina, LEN, id, nombre, apellido, sueldo, lugar))
                {
                    printf("\nModificacion aplicada!\n\n");
                }
                else
                {
                    printf("\nNo se ha dado de alta a ningun empleado.\n\n");

                }
                system("pause");
                break;

            case 3:
                if(flagEmpleado == 1 && !removeEmployee(nomina, LEN, id))
                {
                    printf("Baja exitosa!\n\n");
                }
                else
                {
                    printf("\nNo se ha dado de alta a ningun empleado.\n\n");

                }
                system("pause");
                break;

            case 4:
                if(flagEmpleado == 1)
                {
                    switch(informes())
                    {
                        case 1:
                            switch(informeAlfa())
                            {
                                case 1:

                                    sortEmployees(nomina, LEN, 1);
                                    printEmployees(nomina,LEN);
                                    system("pause");
                                    break;

                                case 2:
                                    sortEmployees(nomina, LEN, 2);
                                    printEmployees(nomina,LEN);
                                    system("pause");
                                    break;

                                default:
                                    printf("\nOpcion Invalida!\n\n");
                                    system("pause");
                            }
                            break;

                        case 2:
                            totalesInformes(nomina, LEN);
                            system("pause");
                            break;

                        default:
                                printf("\nOpcion Invalida!\n\n");
                                system("pause");
                    }
                }
                else
                {
                    printf("\nNo se ha dado de alta a ningun empleado.\n\n");
                    system("pause");
                }
                break;

            case 5:
                printf("\nConfirma salida? (s/n): ");
                fflush(stdin);
                salir=getchar();

                if(salir == 's')
                {
                    exit(1);
                }
                else if (salir =='n')
                {
                    printf("\nUsted seguira en el programa!\n\n");
                }
                else
                {
                    printf("\nOpcion Invalida!\n\n");
                }
                system("pause");
                break;

            default:
                printf("\nOpcion Invalida!\n\n");
                system("pause");
        }

    }while(salir!='s');
    return EXIT_SUCCESS;
}
int menu()
{
    int opcion;

    system("cls");
    printf("    *** ABM Empleados***\n\n");
    printf("1. ALTA.\n");
    printf("2. MODIFICAR.\n");
    printf("3. BAJA.\n");
    printf("4. LISTAR.\n");
    printf("5. SALIR.\n\n");

    printf("Ingrese opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int informes()
{
    int opcion;

    system("cls");
    printf("                             ***Informes***\n\n");
    printf(" 1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf(" 2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");

    printf("Ingrese opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int informeAlfa()
{
    int opcion;

    system("cls");
    printf("                 ***Informes alfabeticos***\n\n");
    printf(" 1. Listado ordenado alfabeticamente de manera ASCENDENTE.\n");
    printf(" 2. Listado ordenado alfabeticamente de manera DESCENDENTE.\n\n");

    printf("Ingrese opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
