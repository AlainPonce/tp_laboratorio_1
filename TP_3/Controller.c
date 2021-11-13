#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = fopen(path, "r");

    if(f == NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n\n");
        exit(1);
    }
    else
    {
        parser_EmployeeFromText(f, pArrayListEmployee);
        todoOk=1;
    }

    fclose(f);

    return todoOk;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = fopen(path, "rb");

    if(f == NULL)
    {
        printf("\nNo se pudo abrir el archivo o no existe. Primero se debe generar.\n\n");
    }
    else
    {
        parser_EmployeeFromBinary(f, pArrayListEmployee);
        printf("\nSe abrio el archivo binario con exito.\n\n");
        todoOk = 1;
    }

    fclose(f);

    return todoOk;
}
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int todoOk =0;

    if(pArrayListEmployee!=NULL && id != NULL)
    {
        if(employee_alta(pArrayListEmployee, id))
        {
            printf("\nAlta Exitosa!\n\n");
            todoOk = 1;
        }
        else
        {
            printf("Ha ocurrido un error en el alta.\n\n");
            todoOk = 1;
        }
    }
    return todoOk;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk =0;

    if(pArrayListEmployee!=NULL)
    {
        if(employee_modificar(pArrayListEmployee))
        {
            printf("Modificacion Exitosa!\n\n");
            todoOk = 1;
        }
        else
        {
            printf("Ha ocurrido un error en la modificacion.\n\n");
            todoOk = 1;
        }
    }
    return todoOk;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk =0;

    if(pArrayListEmployee!=NULL)
    {
        if(employee_eliminar(pArrayListEmployee))
        {
            printf("Proceso de baja finalizado!\n\n");
            todoOk = 1;
        }
        else
        {
            printf("Ha ocurrido un error en la baja.\n\n");
            todoOk = 1;
        }
    }
    return todoOk;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    Employee* auxEmpleado = NULL;

    if(pArrayListEmployee != NULL)
    {
        printf("ID       NOMBRE   HORAS TRABAJADAS  SUELDO\n");
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            employee_listarEmpleado(auxEmpleado);
        }
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    char criterio = '0';
    int todoOk = 0;
    if(pArrayListEmployee!=NULL)
    {
        printf("          ***Ordenar Empleados***\n\n");
        printf("1. Ordenar por ID de manera ASCENDENTE\n");
        printf("2. Ordenar por ID de manera DESCENDENTE\n");
        printf("3. Ordenar nombres de manera ASCENDENTE.\n");
        printf("4. Ordenar nombres de manera DESCENDENTE.\n");
        printf("5. Ordenar las horas trabajas de manera ASCENDENTE.\n");
        printf("6. Ordenar las horas trabajas de manera DESCENDENTE.\n");
        printf("7. Ordenar los sueldos de manera ASCENDENTE.\n");
        printf("8. Ordenar los sueldos de manera DESCENDENTE.\n\n");
        printf("Opcion: ");

        fflush(stdin);
        criterio=getchar();

        switch(criterio)
        {
            case '1':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarId, 1);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;

            case '2':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarId, 0);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;

            case '3':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarNombre, 1);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;
            case '4':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarNombre, 0);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;

            case '5':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarHorasTrabajadas, 1);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;

            case '6':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarHorasTrabajadas, 0);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;

            case '7':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarSueldo, 1);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;

            case '8':
                printf("\nOrdenando la lista, aguarde un momento...\n");
                ll_sort(pArrayListEmployee, employee_ordenarSueldoDos, 1); //Funcion obligada a ser formulada por falta de respuesta a ll_sort(pArrayListEmployee, employee_ordenarSueldo, 0);
                todoOk = 1;
                printf("\nOrdenamiento completado. Volver a listar empleados.\n\n");
                break;


            default:
            printf("\nError. No ha ingresado un digito valido.\n\n");
        }

    }
    return todoOk;
}
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;

    int todoOk = 0;
    Employee* auxEmpleado;

    FILE* f;

    if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f = fopen(path,"w");
		if(f != NULL && ll_len(pArrayListEmployee) >0)
        {
            fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

            for(int i= 0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = ll_get(pArrayListEmployee, i);

                if(auxEmpleado!=NULL && employee_getId(auxEmpleado, &auxId)
                                     && employee_getNombre(auxEmpleado, auxNombre)
                                     && employee_getHorasTrabajadas(auxEmpleado, &auxHorasTrabajadas)
                                     && employee_getSueldo(auxEmpleado, &auxSueldo))
                {
                    fprintf(f, "%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                    todoOk=1;
                    //break;
                }
                else
                {
                    ll_pop(pArrayListEmployee, i);
                    printf("\nNo se pudo guardar el archivo");
                }
            }
        }
        else
        {
            printf("No se pudo abrir el archivo");
        }
    }

    if(todoOk==1)
    {
        printf("\nEl archivo fue guardado con exito.\n\n");
    }
    fclose(f);

    return todoOk;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmpleado;

    FILE* f;

    if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f = fopen(path,"wb");
		if(f != NULL && ll_len(pArrayListEmployee) >0)
        {
            for(int i= 0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = ll_get(pArrayListEmployee, i);

                if(auxEmpleado!=NULL)
                {
                    fwrite(auxEmpleado, sizeof(Employee), 1, f);
                    todoOk=1;
                }
                else
                {
                    ll_pop(pArrayListEmployee, i);
                    printf("\nError al guardar el archivo\n\n");
                }
            }
        }
        else
        {
            printf("\nError al leer el archivo\n\n");
        }
    }

    if(todoOk==1)
    {
        printf("\nEl archivo fue guardado con exito.\n\n");
    }
    fclose(f);

    return todoOk;
}
