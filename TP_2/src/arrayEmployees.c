/*
 * arrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Alain Fernando Ponce
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    int todoOk = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
            todoOk = 0;
        }
    }

    return todoOk;
}
int addEmployee(Employee* list, int len, int* id, char name[], char lastName[], float salary, int sector)
{
    int todoOk = -1;
    Employee nuevoEmpleado;
    char salario[128];
    int indice;

    system("cls");
    printf("      ***Alta empleado***\n\n");
    printf("ID: %d\n", *id);

    indice = buscarLibre(list,len);
    if(list != NULL && len > 0 && id != NULL)
    {
        if(indice == -1)
        {
            printf("No hay mas espacio para ingresar.");

        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.name);
            while(strlen(nuevoEmpleado.name) > 51 || validarNombre(nuevoEmpleado.name)== 0)
            {
                printf("Error. Ingrese nombre correctamente: ");
                fflush(stdin);
                gets(nuevoEmpleado.name);
            }
            strcpy(name,nuevoEmpleado.name);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.lastName);

            while(strlen(nuevoEmpleado.lastName) > 51 || validarNombre(nuevoEmpleado.lastName)== 0)
            {
                printf("Error. Ingrese nombre correctamente: ");
                fflush(stdin);
                gets(nuevoEmpleado.lastName);
            }

            strcpy(lastName,nuevoEmpleado.lastName);

            printf("Ingrese salario: ");
            //scanf("%s", &salario);
            fflush(stdin);
            gets(salario);

            while(atof(salario) < 0 || validarFloat(salario) == 0)
            {
                printf("Error. Ingrese salario correctamente: ");
                fflush(stdin);
                gets(salario);
            }

            nuevoEmpleado.salary = atof(salario);
            salary = nuevoEmpleado.salary;

            printf("Ingrese sector (1-100): ");
            scanf("%d", &nuevoEmpleado.sector);

            while(nuevoEmpleado.sector < 1 || nuevoEmpleado.sector > 100)
            {
                printf("Error. Ingrese sector correctamente (1-100): ");
                scanf("%d", &nuevoEmpleado.sector);
            }
            sector = nuevoEmpleado.sector;

            printf("\n");

            nuevoEmpleado.id= *id;
            *id = *id +1;
            nuevoEmpleado.isEmpty = 0;

            list[indice] = nuevoEmpleado;
            todoOk = 0;
        }
    }

    return todoOk;
}
int buscarLibre(Employee* list, int len)
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int modificarEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk=0;
    int indice;
    int opcion;
    char salario[128];

    system("cls");
    printf("                    ***Modificar Empleado***\n");
    printEmployees(list, len);
    printf("Ingrese ID: ");
    scanf("%d", &id);

    printf("\n");

    indice = findEmployeeById(list, len, id);
    if(len>0 && id !=0)
    {
        if(indice == -1)
        {
            printf("No hay ningun empleado registrado con el ID ingresado: %d.\n\n", id);
        }
        else
        {
            printf("ID        NOMBRE    APELLIDO    SALARIO         SECTOR\n");
            printEmploye(list[indice]);

            printf("\n");

            printf("Que desea modificar?\n\n");

            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Sueldo\n");
            printf("4. Sector\n\n");

            printf("Opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            printf("\n");

            switch(opcion)
            {
                case 1:

                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    scanf("%s", list[indice].name);
                    while(strlen(list[indice].name) > 51 || validarNombre(list[indice].name)== 0)
                    {
                        printf("Error. Ingrese nombre correctamente: ");
                        fflush(stdin);
                        scanf("%s", list[indice].name);
                    }

                    printf("\nModificacion aplicada!\n");

                    break;

                case 2:
                    printf("Ingrese apellido: ");
                    fflush(stdin);
                    scanf("%s", list[indice].lastName);
                    while(strlen(list[indice].lastName) > 51 || validarNombre(list[indice].lastName)== 0)
                    {
                        printf("Error. Ingrese apellido correctamente: ");
                        fflush(stdin);
                        scanf("%s", list[indice].lastName);
                    }

                    printf("\nModificacion aplicada!\n");

                    break;

                case 3:

                    printf("Ingrese salario: ");
                    fflush(stdin);
                    gets(salario);

                    while(atof(salario) < 0 || validarFloat(salario) == 0)
                    {
                        printf("Error. Ingrese salario correctamente: ");
                        fflush(stdin);
                        gets(salario);
                    }

                    list[indice].salary = atof(salario);
                    salary = list[indice].salary;

                    break;

                case 4:

                    printf("Ingrese sector: ");
                    scanf("%d", &list[indice].sector);

                    while(list[indice].sector <= 100 || list[indice].sector >= 200)
                    {
                        printf("Error. Ingrese sector correctamente: ");
                        scanf("%d", &list[indice].sector);
                    }

                    printf("\nModificacion aplicada!\n");

                    break;
            }
            todoOk=1;

        }
    }
    return todoOk;
}
int removeEmployee(Employee* list, int len, int id)
{
    int todoOk=-1;
    int indice;
    char confirma;

    system("cls");
    printf("                    ***Baja de Empleado***\n");
    printEmployees(list, len);
    printf("Ingrese ID: ");
    scanf("%d", &id);

    printf("\n");

    indice = findEmployeeById(list, len, id);
    if(len>0 && id !=0)
    {
            if(indice == -1)
        {
            printf("No hay ningun empleado registrado con el ID ingresado: %d.\n\n", id);
        }
        else
        {
            printf("ID        NOMBRE    APELLIDO    SALARIO         SECTOR\n");
            printEmploye(list[indice]);
            printf("\n");
            printf("Confirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            printf("\n");
            if(confirma == 's')
            {
                list[indice].isEmpty=1;
                todoOk=0;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n\n");
            }
        }
    }

    return todoOk;
}
int printEmployees(Employee list[], int length)
{
    int flag = 1;
    int todoOk =0;
    system("cls");
    printf("                  ***Listado de Empleados***\n\n");
    printf("ID        NOMBRE    APELLIDO    SALARIO         SECTOR\n");
    for(int i=0; i<length; i++)
    {
        if(list[i].isEmpty == 0)
        {
          printEmploye(list[i]);
          flag = 0;
          todoOk=1;
        }
    }
    if(flag)
    {
        printf("       No hay empleados que mostrar.");
    }
    printf("\n");
    return todoOk;
}
void printEmploye(Employee unEmploye)
{
    printf("%d     %10s    %s\t%.2f\t%.2d"
       , unEmploye.id
       , unEmploye.name
       , unEmploye.lastName
       , unEmploye.salary
       , unEmploye.sector);

    printf("\n");

}
int findEmployeeById(Employee list[], int len,int id)
{
    int indice= -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int sortEmployees(Employee* list, int len, int order)
{
    int todoOk = -1;

    Employee aux;

    if(list != NULL && len > 0)
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (order == 1)
                {
                    if (stricmp(list[i].lastName, list[j].lastName) > 0)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }

                    if(stricmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                else if(order == 2)
                {
                    if (stricmp(list[i].lastName, list[j].lastName) < 0)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }

                    if(stricmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                else
                {
                    printf("Opcion Invalida!");
                }
            }
        }
        todoOk =0;
    }
    return todoOk;
}

int totalesInformes(Employee* list, int len)
{
    int todoOk=0;
    float totalSueldos;
    float promedio;
    int contador=0;
    int contadorPromedio=0;
    int i;

    system("cls");
    printf("                ***Total Sueldos***\n\n");
    printf("----------------------------------------------------------------\n");

    for(i=0; i <len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            totalSueldos += list[i].salary;
            contador++;
        }
    }

    promedio = (float) totalSueldos / contador;

    for(i=0; i <len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary > promedio)
            {
                contadorPromedio++;
            }
    }

    printf("\nTotal Sueldos: $%.2f\n\n", totalSueldos);
    printf("----------------------------------------------------------------\n\n");

    printf("\nTotal Promedio: $%.2f\n\n", promedio);
    printf("----------------------------------------------------------------\n\n");

    printf("\nCantidad de empleados que superan el salario promedio: %d\n\n", contadorPromedio);

    printf("----------------------------------------------------------------\n\n");
    todoOk = 1;


    return todoOk;
}

//                           Funciones por correccion.

int validarNombre(char cadena[])
{
    for(int i = 0; i < strlen(cadena); i++)
    {
        if((cadena[i] >= 65 && cadena[i]<= 90) || (cadena[i] >= 97 && cadena[i] <= 122))
        {
            return 1;
        }
    }
    return 0;
}
int validarFloat(char numero[])
{
    for(int i = 0; i < strlen(numero); i++)
    {
        if(isdigit(numero[i]) || numero[i] == '.')
        {
            return 1;
        }
    }

    return 0;
}
