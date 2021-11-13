#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int tam;

    char id[128];
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];

    Employee* auxEmpleado = NULL;

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

        while(!feof(pFile) && pArrayListEmployee != NULL)
        {
            tam = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            if(tam == 4)
            {
                auxEmpleado = employee_new();
                if(auxEmpleado != NULL)
                {
                    auxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                    ll_add(pArrayListEmployee, auxEmpleado);
                    todoOk=1;
                }
            }
        }
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* auxEmpleado = NULL;

    if(pFile != NULL)
    {
        while(!feof(pFile) && pArrayListEmployee != NULL)
        {
            auxEmpleado=employee_new();
            if(fread(auxEmpleado, sizeof(Employee),1, pFile))
            {
                ll_add(pArrayListEmployee, auxEmpleado);
                todoOk=1;
            }
        }
    }
    return todoOk;
}
