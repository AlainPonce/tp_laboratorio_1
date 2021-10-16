/*
 * arrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Alain Fernando Ponce
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;


#endif /* ARRAYEMPLOYEES_H_ */

/** \brief Indica que todas las posiciones de un array estan vacios. Esta funcion pone la bandera (isEmpty) in VERDADERA en todas las posiciones del array.
 *
 * \param list Employee* Puntero del array de empleados.
 * \param len int Tamanio del array.
 * \return int Retorna -1 si el error es por tamaño invalido o puntero nulo. 0 si está OK.
 *
 */
int initEmployees(Employee* list, int len);
/** \brief Recibe en una lista existente de empleados los valores recibidos por paramentros en la primer posicion empty.
 *
 * \param list Employee* array de empleados
 * \param len int tamanio del array.
 * \param id int* numero verificador del empleado.
 * \param name[] char nombre del empleado.
 * \param lastName[] char apellido del empleado.
 * \param salary float salario del empleado.
 * \param sector int sector del empleado.
 * \return int  retorna -1 si el error es por tamaño invalido o un puntero NULL sin espacio libre. 0 si esta Ok.
 *
 */
int addEmployee(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector);
/** \brief Recibe en una lista existente de empleados, el tamaño maximo de la nomina y busca el primer lugar libre.
 *
 * \param list Employee* listado de empleados a analizar.
 * \param len int tamanio de empleados.
 * \return int retorna -1 si no hay lugares disponibles dentro del tamanio maximo. Retorna indice como proximo lugar disponible.
 *
 */
int buscarLibre(Employee* list, int len);
/** \brief busca un empleado por su ID y retorna su posicion en el array.
 *
 * \param list Employee* lista de empleados a analizar.
 * \param len int tamanio de empleados.
 * \param id int variable para buscar el id del empleado.
 * \return int retorna la posicion del array de empleados del empleado buscado o -1 si es invalido su tamanio o nulo el puntero recibido.
 *
 */

int findEmployeeById(Employee* list, int len,int id);
/** \brief Modifica los datos del empleado ingresando su ID(unico valor inmodificable).
 *
 * \param list Employee* array de empleados
 * \param len int tamanio del array.
 * \param id int* numero verificador del empleado.
 * \param name[] char nombre del empleado.
 * \param lastName[] char apellido del empleado.
 * \param salary float salario del empleado.
 * \param sector int sector del empleado.
 * \return int 0 si hay un error en el tamanio o el puntero es nulo. 1 si esta  OK.
 *
 */
int modificarEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Remueve un empleado por su ID.
 *
 * \param list Employee* array de empleados
 * \param len int tamanio del array
 * \param id int variable usada para acceder al empleado buscado.
 * \return int retorna -1 si hay un error en el tamanio o el puntero es nulo o no se encuentra un id registrado a un empleado.
 *
 */
int removeEmployee(Employee* list, int len, int id);
/** \brief Ordena el listado de empleados segun el argumento "order" que se elija.
 *
 * \param list Employee* array de empleados
 * \param len int tamanio del array
 * \param order int variable para elegir si se desea el ordenamiento de forma ASCENDENTE o DESCENDENTE.
 * \return int retorna -1 si hay un error en el tamanio o el puntero es nulo. 0 si esta OK.
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Muestra el contenido del array de empleados.
 *
 * \param list Employee* array de empleados
 * \param length tamanio del array
 * \return int -1 si hay un error en el tamanio o el puntero es nulo. 0 si esta OK.
 *
 */
int printEmployees(Employee* list, int length);
/** \brief Funcion secundaria con las mascaras necesarias para mostrar los datos del empleado.
 *
 * \param unEmploye Employee Un empleado
 * \return void
 *
 */
void printEmploye(Employee unEmploye);
/** \brief Muestra total y promedio de los salarios, y cuantos empleados superan el salario promedio.
 *
 * \param list Employee* array de empleados
 * \param len int tamanio del array.
 * \return int 0 si hay un error en el tamanio o el puntero es nulo. 1 si esta  OK.
 *
 */
int totalesInformes(Employee* list, int len);

//                                  Funciones por correccion:

/** \brief Valida una cadena de caracteres letra por letra verificando si es un caracter o un numero.
 *
 * \param cadena[] char cadena de caracteres a verificar.
 * \return int retorna 1 si es una cadena de caracteres completa o 0 si no lo es.
 *
 */
int validarNombre(char cadena[]);
/** \brief Valida una cadena de digitos numero por numero verificando si es un digito o no.
 *
 * \param numero[] char Cadena de numeros a verificar.
 * \return int retorna 1 si es una cadena de digitos completa o 0 si no lo es.
 *
 */
int validarFloat(char numero[]);

