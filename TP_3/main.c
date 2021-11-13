#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu(void);

int main(void)
{
	setbuf(stdout, NULL);

	char confirmar='n';
	char leerEmpleados='n';
	char salir='n';

	int nextId = 1;

	int flagLectura = 0;
	int flagAlta = 0;
	int flagAlta2 = 0;
	int flagAlta3 = 0;
	int flagBaja1=0;
	int flagBaja2=0;

	LinkedList* listaEmpleados = ll_newLinkedList(); //Constructor del linkedlist

	do{
		switch(menu())
		{
			case 1:
			    if(flagLectura ==0  && flagAlta == 0 && flagAlta2 == 0)
                {
                   controller_loadFromText("data.csv", listaEmpleados);
                   printf("\nSe cargo el archivo 'data.csv' con exito.\n\n");
                   ll_sort(listaEmpleados, employee_ordenarId, 1);
                   flagLectura = 1;
                }
                else if(flagLectura == 0 && flagAlta == 1)
                {
                    printf("\nYa existen empleados cargados en el sistema. Desea sobreescribirlos? (s/n): ");
                    fflush(stdin);
                    leerEmpleados = getchar();

                    if(leerEmpleados == 's')
                    {
                        controller_loadFromText("data.csv", listaEmpleados);
                        printf("\nSe sobreescribio y cargo el archivo 'data.csv' con exito.\n\n");
                        ll_sort(listaEmpleados, employee_ordenarId, 1);
                        flagLectura = 1;
                    }
                    else if(leerEmpleados == 'n')
                    {
                        printf("\nSe ha/n mantenido el/los empleado/s cargado/s anteriormente.\n\n");
                    }
                    else
                    {
                        printf("\nOpcion Invalida!\n\n");
                    }
                }
                else
                {
                    printf("\nYa se ha abierto un archivo de empleados anteriormente.\n\n");
                }

				break;
			case 2:

			    if(flagLectura==0)
                {
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    flagLectura=1;
                }
                else
                {
                    printf("\nYa se ha abierto un archivo de empleados anteriormente.\n\n");
                }

				break;

			case 3:

			    system("cls");
			    if((flagLectura == 0 && flagAlta == 0) || (flagLectura == 0 && flagAlta2 == 1) || (flagLectura == 0 &&flagBaja1==1))
			    {
			        controller_addEmployee(listaEmpleados, &nextId);
                    employee_buscarMayorId(listaEmpleados, &nextId);
                    flagAlta = 1;
                    flagBaja1 = 0;
			    }
                else if(flagLectura == 0 && flagAlta == 1)
                {
                    employee_buscarMayorId(listaEmpleados, &nextId);
                    controller_addEmployee(listaEmpleados, &nextId);
                    flagAlta2 = 1;
                }

                if((flagLectura == 1 && flagAlta3 == 0))
                {
                    employee_buscarMayorId(listaEmpleados, &nextId);
                    controller_addEmployee(listaEmpleados, &nextId);
                    flagAlta3 = 1;

                    break;
                }
                else if((flagLectura == 1 && flagAlta3) == 1 || (flagLectura==1 && flagBaja2 == 1))
                {
                    controller_addEmployee(listaEmpleados, &nextId);
                    employee_buscarMayorId(listaEmpleados, &nextId);
                }

				break;

			case 4:
				if(!ll_isEmpty(listaEmpleados))
				{
					system("cls");
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("\nPrimero se debe cargar la lista de empleados predeterminada.\n\n");
				}

				break;

			case 5:
				if(!ll_isEmpty(listaEmpleados))
				{
					system("cls");
					controller_removeEmployee(listaEmpleados);
					flagBaja1 = 1;
					flagBaja2=1;
				}
				else
				{
					printf("\nPrimero se debe cargar la lista de empleados predeterminada.\n\n");
				}
				break;

			case 6:
				if(!ll_isEmpty(listaEmpleados))
				{
					system("cls");
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("\nNo se ha leido ningun archivo de empleados.\n\n");
				}
				break;

			case 7:
				if(!ll_isEmpty(listaEmpleados))
				{
					system("cls");
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("\nNo se ha leido ningun archivo de empleados.\n\n");
				}
				break;

			case 8:
				if(!ll_isEmpty(listaEmpleados))
				{
					printf("\nDesea sobreescribir el archivo de empleados actual? (s/n): ");
					fflush(stdin);
					confirmar=getchar();
					if(confirmar=='s')
					{
						controller_saveAsText("data.csv", listaEmpleados);
					}
					else
					{
						printf("\nEl archivo no fue guardado.\n\n");
					}
				}
				else
				{
					printf("\nNo hay nada que guardar ya que no se ha leido ningun archivo de empleados.\n\n");
				}
				break;

			case 9:
				if(!ll_isEmpty(listaEmpleados))
				{
					printf("\nDesea crear o sobreescribir un archivo de empleados .bin? (s/n): ");
					fflush(stdin);
					confirmar = getchar();

					if(confirmar == 's')
					{
						controller_saveAsBinary("data.bin", listaEmpleados);
					}
					else
					{
						printf("\nEl archivo no fue guardado.\n\n");
					}
				}
				else
				{
					printf("\nNo hay nada que guardar ya que no se ha leido ningun archivo de empleados.\n\n");
				}
				break;

			case 10:
				printf("\nConfirma salida (s/n)?: ");
				fflush(stdin);
				salir=getchar();
				break;

			default:
				printf("\nOpcion Invalida!\n\n");
		}
		system("pause");

	}while(salir=='n');
    return 0;
}

int menu(void)
{
    int opcion;

    system("cls");
    printf("              *** LinkedList Empleados***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv.\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin.\n");
    printf("10. Salir.\n\n");
    printf("Ingrese opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
