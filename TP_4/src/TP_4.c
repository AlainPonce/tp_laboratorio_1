/*
 ============================================================================
 Name        : TP_4.c
 Author      : Alain Fernando Ponce
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
}ePaciente;

int mostrarPaciente(ePaciente* p);
int mostrarPacientes(LinkedList* list);
int ordenarEdad(void* p1, void* p2);

int main(void)
{
    ePaciente* paciente = NULL;
    LinkedList* listaPacientes = NULL;
    LinkedList* listaPacientesClonada = NULL;
    LinkedList* listaPacientesSubListeada = NULL;

    ePaciente p1= {3453, "Raul", 'm', 51};
    ePaciente p2= {7655, "Enrique", 'm', 29};
    ePaciente p3= {2347, "Camila", 'f', 23};
    ePaciente p4= {9856, "Susana", 'f', 64};
    ePaciente p5= {7345, "Viviana", 'f', 58};
    ePaciente p6= {1234, "Esteban", 'm', 35};

    ePaciente p7= {1234, "Marta", 'f', 82};

    printf("1. *** Se crea una LinkedList de Pacientes con: ll_newLinkedList()***\n\n");
    listaPacientes = ll_newLinkedList();
    if(listaPacientes != NULL)
    {
        printf("Se ha creado una LinkedList de Pacientes\n");
    }
    else
    {
        printf("Hubo un error al crear la LinkedList de Pacientes\n");
    }
    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("2. *** Se agregan los pacientes cargados con anticipacion y se muestran: ll_add() ***\n\n");

    if(listaPacientes != NULL)
    {
        ll_add(listaPacientes, &p1);
        ll_add(listaPacientes, &p2);
        ll_add(listaPacientes, &p3);
        ll_add(listaPacientes, &p4);
        ll_add(listaPacientes, &p5);
        ll_add(listaPacientes, &p6);

        mostrarPacientes(listaPacientes);

        printf("Pacientes agregados con exito!\n");
    }
    else
    {
        printf("No se ha podido agregar los elementos a la LinkedList\n");
    }

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("3. *** Muestro el tamanio de la LinkedList de Pacientes: ll_len() ***\n\n");
    printf("Cantidad de Pacientes ingresados: %d\n", ll_len(listaPacientes));

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("4. *** Muestro un elemento de la LinkedList de Pacientes: ll_get() ***\n\n");

    paciente = (ePaciente*) ll_get(listaPacientes, 4);
    if(paciente != NULL)
    {
        printf("***Listado de Pacientes***\n\n ID     NOMBRE   SEXO   EDAD\n");
        mostrarPaciente(paciente);
        printf("\n");
    }
    else
    {
        printf("No se ha podido mostrar un elemento de la LinkedList\n");
    }

    printf("-------------------------------------------------------------------------------------------------\n\n");

    printf("5. *** Modifico el elemento anterior mostrado de la LinkedList de Pacientes: ll_set() ***\n\n");

    paciente = (ePaciente*)malloc(sizeof(ePaciente));

    if(paciente != NULL)
    {
        mostrarPacientes(listaPacientes);

        paciente->id = 9999;
        strcpy(paciente->nombre, "Pepita");
        paciente->sexo = 'f';
        paciente->edad = 32;

    }
    else
    {
        printf("No es posible ingresar el Paciente. \n\n");
    }
    if(!ll_set(listaPacientes, 4, paciente))
    {
        mostrarPacientes(listaPacientes);
        printf("Se reemplazo correctamente en el indice 4.\n");
    }
    else
    {
        printf("No se ha podido modificar al paciente.\n\n");
    }

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("6. *** Elimino el elemento anterior modificado de la LinkedList de Pacientes: ll_remove() ***\n\n");
    if(!ll_remove(listaPacientes, 4)) //Retorna 0 si funciona correctamente
    {
        mostrarPacientes(listaPacientes);
        printf("Se elimino correctamente el indice 4.\n\n");
    }
    else
    {
        printf("No se ha podido eliminar el paciente.\n\n");
    }

    printf("\n--------------------------------------------------------------------------------------------------\n\n");

    printf("7. *** Clono la nueva lista modificada del LinkedList de Pacientes: ll_clone() ***\n\n");
    if(listaPacientesClonada==NULL)
    {
        listaPacientesClonada = ll_clone(listaPacientes);
        mostrarPacientes(listaPacientesClonada);
        printf("Se ha clonado la lista de Pacientes correctamente.\n\n");

    }
    else
    {
        printf("No se ha podido clonar la lista de Pacientes.\n\n");
    }
    printf("\n--------------------------------------------------------------------------------------------------\n\n");

    printf("8. *** Elimino un elemento de la lista clonada y copio su puntero: ll_pop() ***\n\n");
    paciente = ll_pop(listaPacientesClonada, 1);
    if(paciente != NULL)
    {
        mostrarPacientes(listaPacientesClonada);
        printf("Se ha eliminado el Paciente de indice 1 y se ha copiado su puntero\n\n");
    }
    else
    {
        printf("No se ha podido eliminar el paciente de indice 1 y tampoco copiar su puntero.\n\n");
    }

    printf("\n--------------------------------------------------------------------------------------------------\n\n");

    printf("9. *** Comparo la lista original con la clonada si tienen los mismos elementos: ll_containsAll() ***\n\n");

    if(!ll_containsAll(listaPacientesClonada, listaPacientes)) // Retorna 0 por lo tanto no contienen los mismos elementos.
    {
        printf("Lista Pacientes Original:\n\n");
        mostrarPacientes(listaPacientes);
        printf("Lista Pacientes Clonada:\n\n");
        mostrarPacientes(listaPacientesClonada);
        printf("Las listas NO contienen los mismos Pacientes.\n");
    }
    else
    {
        printf("Lista Pacientes Original:\n\n");
        mostrarPacientes(listaPacientes);
        printf("Lista Pacientes Clonada:\n\n");
        mostrarPacientes(listaPacientesClonada);
        printf("Las listas contienen los mismos Pacientes.\n");
    }

    printf("\n--------------------------------------------------------------------------------------------------\n\n");

    printf("10. *** Busco en la lista ORIGINAL si se encuentra el elemento ELIMINADO de la lista CLON: ll_contains() ***\n\n");

    if(ll_contains(listaPacientes, paciente)) //Retorna 1 si contiene el elemento
    {
        printf("El Paciente eliminado en la lista CLON, se encuentra en la ORIGINAL.\n");
    }
    else
    {
        printf("El Paciente eliminado en la lista CLON, NO se encuentra en la ORIGINAL.\n");
    }

    printf("\n--------------------------------------------------------------------------------------------------\n\n");

    printf("11. *** Creo una nueva LinkedList pero solo con algunos elementos de la Linkedlist de Pacientes ORIGINAL: ll_subList() ***\n\n");
    listaPacientesSubListeada = ll_subList(listaPacientes, 0, 2);
    if(listaPacientesSubListeada != NULL)
    {
        printf("Se han cargado los siguientes Pacientes a la nueva SubList: \n\n");
        mostrarPacientes(listaPacientesSubListeada);

    }
    printf("--------------------------------------------------------------------------------------------------\n\n");

    printf("12. *** Agrego un nuevo Paciente entre ambos anteriormente mostrados: ll_push() ***\n\n");

    ll_push(listaPacientesSubListeada, 1, &p7);
    if(listaPacientesSubListeada!= NULL)
    {
        mostrarPacientes(listaPacientesSubListeada);
        printf("Paciente agregado con exito entre ambos Pacientes anteriores.\n\n");
    }
    else
    {
        printf("No se ha podido agregar al nuevo Paciente.\n");
    }

    printf("--------------------------------------------------------------------------------------------------\n\n");
    printf("13. *** Ordeno los elementos de la SubList segun su edad de manera ASCENDENTE y DESCENDENTE: ll_sort() ***\n\n");
    if(!ll_sort(listaPacientesSubListeada, ordenarEdad, 1))
    {
        mostrarPacientes(listaPacientesSubListeada);
        printf("Ordenamiento de manera ASCENDENTE.\n\n");
    }
    if(!ll_sort(listaPacientesSubListeada, ordenarEdad, 0))
    {
        mostrarPacientes(listaPacientesSubListeada);
        printf("Ordenamiento de manera DESCENDENTE.\n\n")   ;
    }

    printf("--------------------------------------------------------------------------------------------------\n\n");

    printf("14. *** Elimino los elementos de la SubList: ll_clear() ***\n\n");
    if(!ll_clear(listaPacientesSubListeada)) //Retorna 0 si se pudo vaciar la lista
    {
        mostrarPacientes(listaPacientesSubListeada);
        printf("No hay Pacientes en la SubList.\n\n");

        printf("Pacientes eliminados correctamente de la SubList.\n");
    }
    else
    {
        printf("Los Pacientes no han podido ser eliminados de la SubList.\n");
    }

    printf("--------------------------------------------------------------------------------------------------\n\n");

    printf("15. *** Verifico si la SubList esta o no vacia: ll_isEmpty() ***\n\n");
    if(ll_isEmpty(listaPacientesSubListeada)) //Retorna 1 si la lista esta vacia
    {
        printf("La lista esta VACIA.\n");
    }
    else
    {
        printf("La lista CONTIENE elementos.\n");
    }
    printf("\n--------------------------------------------------------------------------------------------------\n\n");

    printf("16. *** Elimino completamente la SubList: ll_deleteLinkedList() ***\n\n");
    if(!ll_deleteLinkedList(listaPacientesSubListeada)) //Retorna 0 si se elimina la lista correctamente
    {
        printf("SubList eliminada correctamente.\n\n");
    }
    else
    {
        printf("No se ha podido eliminar la SubList.\n\n");
    }

    printf("--------------------------------------------------------------------------------------------------\n\n");

    printf("***LinkedLists Finales***\n\n");
    mostrarPacientes(listaPacientes);
    printf("LinkedList Original.\n\n");
    mostrarPacientes(listaPacientesClonada);
    printf("LinkedList Clonada.\n\n");
    printf("LinkedList SubList eliminada.\n");
    printf("\n--------------------------------------------------------------------------------------------------\n\n");


    return 0;
}
int mostrarPaciente(ePaciente* p)
{
    int todoOk=0;
    if(p != NULL)
    {
        printf("%d  %8s   %c      %d\n", p->id, p->nombre, p->sexo, p->edad);
        todoOk=1;
    }
    return todoOk;

}
int mostrarPacientes(LinkedList* list)
{
    int tam;
    int todoOk=0;
    if(list!= NULL)
    {
        tam = ll_len(list);
        printf("***Listado de Pacientes***\n\n ID     NOMBRE   SEXO   EDAD\n");
        for(int i = 0; i < tam; i++)
        {
            mostrarPaciente((ePaciente*) ll_get(list, i));
        }
        todoOk=1;
        printf("\n");
    }
    return todoOk;
}

int ordenarEdad(void* p1, void* p2)
{
    ePaciente* paciente1 = NULL;
    ePaciente* paciente2 = NULL;

    int todoOk = 0;

    if(p1 != NULL && p2 != NULL)
    {
        paciente1 = (ePaciente*)p1;
        paciente2 = (ePaciente*)p2;

        if(paciente1->edad > paciente2->edad)
        {
            todoOk = 1;
        }
        else
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
