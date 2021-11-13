#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "Controller.h"

Employee* employee_new()
{
    Employee* employee_new = (Employee*) malloc(sizeof(Employee));

    if(employee_new != NULL)
    {
        employee_new->id=0;
        strcpy(employee_new->nombre, "");
        employee_new->horasTrabajadas=0;
        employee_new->sueldo=0;
    }
    return employee_new;
}
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new(); //(eEmpleado*) malloc(sizeof(eEmpleado));
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr))&&
           employee_setNombre(nuevoEmpleado, nombreStr)&&
           employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))&&
           employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}
void employee_delete(Employee* p)
{
    free(p);
}
int employee_setId(Employee* this,int id)
{
    int todoOk=0;

    if(this !=NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL && strlen(nombre) < 30)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL)
    {
       strcpy(nombre, this->nombre);
       todoOk = 1;
    }
    return todoOk;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if(this !=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if(this !=NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

//Funciones Nuevas

int employee_alta(LinkedList* listaEmpleados, int* id)
{
    int todoOk = 0;

    char confirma = 'n';

	int auxId;

	char auxNombre[128];
	int auxHorasTrabajadas;
	char auxHorasTrabajadas2[128];
	int auxSueldo;
	char auxSueldo2[128];

	Employee* auxEmpleado = NULL;

	if(listaEmpleados != NULL)
	{
		auxEmpleado = employee_new();

		if(auxEmpleado != NULL)
		{
		    printf("     ***Alta Empleado***\n\n");
			printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxNombre);
            while(employee_setNombre(auxEmpleado, auxNombre) == 0 || validarNombre(auxNombre)== 0)
            {
                printf("Error. Ingrese nombre correctamente: ");
                fflush(stdin);
                gets(auxNombre);
            }

            printf("Ingrese las horas trabajadas: ");
            fflush(stdin);
            gets(auxHorasTrabajadas2);
            while(employee_setHorasTrabajadas(auxEmpleado, atoi(auxHorasTrabajadas2)) == 0  || validarNumero(auxHorasTrabajadas2) == 0)
            {
                printf("Error. Ingrese Ingrese las horas trabajadas correctamente: ");
                fflush(stdin);
                gets(auxHorasTrabajadas2);
            }

            auxHorasTrabajadas = atoi(auxHorasTrabajadas2);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            gets(auxSueldo2);
            while(employee_setSueldo(auxEmpleado, atoi(auxSueldo2)) == 0  || validarNumero(auxSueldo2) == 0)
            {
                printf("Error. Ingrese sueldo correctamente: ");
                fflush(stdin);
                gets(auxSueldo2);
            }

            auxSueldo = atoi(auxSueldo2);

            auxId = *id;

            if(((employee_setId(auxEmpleado, auxId)) &&
                (employee_setNombre(auxEmpleado, auxNombre)) &&
                (employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas)) &&
                (employee_setSueldo(auxEmpleado, auxSueldo))))
            {
                printf("\nID        NOMBRE  H. TRABAJADAS     SUELDO\n");
                employee_listarEmpleado(auxEmpleado);
                printf("\nConfirma agregar el empleado?(s/n): ");
                fflush(stdin);
                confirma=getchar();

                if(confirma == 's')
                {
                    *id = *id +1;
                    ll_add(listaEmpleados, auxEmpleado);
                    todoOk = 1;
                }
                else
                {
                    employee_delete(auxEmpleado);
                    printf("\nUsted ha cancelado el alta del empleado.\n");
                }
            }
            else
            {
                printf("\nError la validacion de los datos ingresados.\n\n");
            }
        }
        else
        {
            printf("\nNo se puede dar de alta el empleado\n");
        }
    }
    else
    {
        printf("\nNo hay lugar para agregar un nuevo empleado\n");
    }
    return todoOk;
}
int employee_modificar(LinkedList* listaEmpleados)
{
    int todoOk=0;
    int pIdEmpleado;
    int opcion;
    int idABuscar;

    char auxHorasTrabajadas[128];
    char auxSueldo[128];

    Employee* auxEmpleado = NULL;

    printf("          ***Modificar Empleado***\n");
    employee_listarEmpleados(listaEmpleados);

    printf("Ingrese ID de empleado para modificar: ");
    scanf("%d", &pIdEmpleado);

    printf("\n");

    for(int i=0; i < ll_len(listaEmpleados); i++)
    {
        auxEmpleado = (Employee*)ll_get(listaEmpleados, i);
        employee_getId(auxEmpleado, &idABuscar);

        if(ll_len(listaEmpleados)> 0 && pIdEmpleado == idABuscar)
        {
            //printf("pIdEmpleado: %d.\n", pIdEmpleado);
            //printf("idABuscar: %d.\n\n", idABuscar);

            printf("           ***Empleado elegido***\n");
            printf("\nID       NOMBRE  H. TRABAJADAS     SUELDO\n");
            employee_listarEmpleado(ll_get(listaEmpleados, i));

            printf("\n");

            printf("Que desea modificar?\n\n");

            printf("1. Nombre.\n");
            printf("2. Horas Trabajadas.\n");
            printf("3. Sueldo.\n\n");

            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            while(opcion<1 || opcion>3)
            {
                printf("Error. Ingrese Opcion correctamente: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }
            printf("\n");

            switch(opcion)
            {
                case 1:

                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(auxEmpleado->nombre);
                    while(employee_setNombre(auxEmpleado, auxEmpleado->nombre) == 0 || validarNombre(auxEmpleado->nombre)== 0)
                    {
                        printf("Error. Ingrese nombre correctamente: ");
                        fflush(stdin);
                        gets(auxEmpleado->nombre);
                    }

                    break;

                case 2:

                    printf("Ingrese las horas trabajadas: ");
                    fflush(stdin);
                    gets(auxHorasTrabajadas);
                    while(employee_setHorasTrabajadas(auxEmpleado, atoi(auxHorasTrabajadas)) == 0  || validarNumero(auxHorasTrabajadas) == 0)
                    {
                        printf("Error. Ingrese las horas trabajadas correctamente: ");
                        fflush(stdin);
                        gets(auxHorasTrabajadas);
                    }

                    auxEmpleado->horasTrabajadas = atoi(auxHorasTrabajadas);

                    break;

                case 3:

                    printf("Ingrese sueldo: ");
                    fflush(stdin);
                    gets(auxSueldo);
                    while(employee_setSueldo(auxEmpleado, atoi(auxSueldo)) == 0  || validarNumero(auxSueldo) == 0)
                    {
                        printf("Error. Ingrese sueldo correctamente: ");
                        fflush(stdin);
                        gets(auxSueldo);
                    }

                    auxEmpleado->sueldo = atoi(auxSueldo);

                    break;
                }

            todoOk=1;
            //printf("\n");
            break;
        }
    }

    //printf("pIdEmpleado: %d.\n", pIdEmpleado);
    //printf("idABuscar: %d.\n\n", idABuscar);

    if(idABuscar != pIdEmpleado)
    {
        printf("No hay ningun cliente registrado con el CODIGO ingresado: %d.\n", pIdEmpleado);
    }
    return todoOk;
}
int employee_listarEmpleados(LinkedList* listaEmpleados)
{
    int todoOk=0;
    if(listaEmpleados != NULL)
    {
        printf("ID         NOMBRE   HORAS TRABAJADAS  SUELDO\n");
        for(int i=0; i< ll_len(listaEmpleados); i++)
        {
            employee_listarEmpleado(ll_get(listaEmpleados, i));
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}
int employee_listarEmpleado(Employee* this)
{
    int todoOk=0;

    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL && employee_getId(this, &id) && employee_getNombre(this, nombre) && employee_getHorasTrabajadas(this, &horasTrabajadas) && employee_getSueldo(this, &sueldo))
    {
        printf("%.4d %10s        %d          %d\n", id, nombre, horasTrabajadas, sueldo);
        todoOk=1;
    }

    return todoOk;
}
int employee_eliminar(LinkedList* listaEmpleados)
{
    int todoOk=0;
    int pIdEmpleado;
    int idEncontrado;

    char confirmar= 'n';

    Employee* auxEmpleado = NULL;

    printf("          ***Eliminar Empleado***\n");
    employee_listarEmpleados(listaEmpleados);

    printf("Ingrese ID de empleado: ");
    scanf("%d", &pIdEmpleado);

    printf("\n");

    //printf("pIdEmpleado: %d.\n", pIdEmpleado);
    //printf("idEncontrado: %d.\n\n", idEncontrado);

    for(int i=0; i < ll_len(listaEmpleados); i++)
    {
        auxEmpleado = (Employee*)ll_get(listaEmpleados, i);
        employee_getId(auxEmpleado, &idEncontrado);

        if(ll_len(listaEmpleados)> 0 && pIdEmpleado == idEncontrado)
        {
            printf("           ***Empleado elegido***\n");
            printf("\nID       NOMBRE  H. TRABAJADAS     SUELDO\n");
            employee_listarEmpleado(ll_get(listaEmpleados, i));

            printf("\nConfirma la baja del empleado? (s/n): ");
            fflush(stdin);
            confirmar=getchar();

            if(confirmar == 's')
            {
                ll_pop(listaEmpleados, i);
            }
            else
            {
                printf("\nSe ha cancelado la baja del empleado");
            }

            todoOk=1;
            printf("\n");
            break;
        }
    }

    if(idEncontrado != pIdEmpleado)
    {
        printf("No hay ningun cliente registrado con el CODIGO ingresado: %d.\n", pIdEmpleado);
    }
    return todoOk;
}
int employee_ordenarNombre(void* employee1, void* employee2)
{
    int todoOk=0;
    Employee* e1= NULL;
    Employee* e2 = NULL;

    char primerNombre[128];
    char segundoNombre[128];

    e1 = (Employee*) employee1;
    e2 = (Employee*) employee2;

    if(employee_getNombre(e1, primerNombre) && employee_getNombre(e2, segundoNombre))
    {
        todoOk = strcmp(primerNombre, segundoNombre);
    }

    return todoOk;
}
int employee_ordenarId(void* employee1, void* employee2)
{
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;

    int idEmp1;
    int idEmp2;

    int todoOk = 0;

    if(employee1 != NULL && employee2 != NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(employee_getId(emp1,&idEmp1) && employee_getId(emp2,&idEmp2))
        {
            if(idEmp1 > idEmp2)
            {
                todoOk = 1;
            }
            else
            {
                todoOk = -1;
            }
        }
    }
    return todoOk;

}
int employee_ordenarHorasTrabajadas(void* employee1, void* employee2)
{
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;

    int horasTrabajadasEmp1;
    int horasTrabajadasEmp2;

    int todoOk = 0;

    if(employee1 != NULL && employee2 != NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(employee_getHorasTrabajadas(emp1,&horasTrabajadasEmp1) && employee_getHorasTrabajadas(emp2,&horasTrabajadasEmp2))
        {
            if(horasTrabajadasEmp1 > horasTrabajadasEmp2)
            {
                todoOk = 1;
            }
            else
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}
int employee_ordenarSueldo(void* employee1, void* employee2)
{
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;

    int sueldoEmp1;
    int sueldoEmp2;

    int todoOk = 0;

    if(employee1 != NULL && employee2 != NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(employee_getSueldo(emp1,&sueldoEmp1) && employee_getSueldo(emp2,&sueldoEmp2))
        {
            if(sueldoEmp1 > sueldoEmp2)
            {
                todoOk = 1;
            }
            else
            {
                todoOk = -1;
            }
        }
    }
    return todoOk;
}
int employee_ordenarSueldoDos(void* employee1, void* employee2)
{
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;

    int sueldoEmp1;
    int sueldoEmp2;

    int todoOk = 0;

    if(employee1 != NULL && employee2 != NULL)
    {
        emp1 = (Employee*)employee1;
        emp2 = (Employee*)employee2;

        if(employee_getSueldo(emp1,&sueldoEmp1) && employee_getSueldo(emp2,&sueldoEmp2))
        {
            if(sueldoEmp1 < sueldoEmp2)
            {
                todoOk = 1;
            }
            else
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}
int employee_buscarMayorId(LinkedList* lista, int* id)
{
    int todoOk =0;

    Employee* auxEmp = NULL;
    int mayor=0;

    if(lista!= NULL)
    {
        for(int i=0; i< ll_len(lista); i++)
        {
            auxEmp = (Employee*) ll_get(lista, i);
            if(auxEmp != NULL && (i == 0 || auxEmp->id > mayor))
            {
                mayor = auxEmp->id;
            }
        }
        *id = mayor + 1;
        todoOk = 1;
    }
    return todoOk;
}
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
int validarNumero(char numero[])
{
    for(int i = 0; i < strlen(numero); i++)
    {
        if(isdigit(numero[i]))
        {
            //atof(numero);
            return 1;
        }
    }

    return 0;
}
