#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

/** \brief Reserva espacio en la memoria dinamica para un nuevo empleado
 *
 * \return Employee* Retorna un puntero a la memoria asignada por el sistema. Si el sistema no pudo conseguir memoria retorna NULL
 *
 */
Employee* employee_new();
/** \brief Reserva espacio en la memoria dinamica para un nuevo empleado y carga valores recibidos por parametros
 *
 * \param idStr char* id recibido
 * \param nombreStr char* nombre recibido
 * \param horasTrabajadasStr char* horas trabajadas recibidas
 * \param sueldoStr char* sueldo recibido
 * \return Employee* Retorna un puntero a la memoria asignada por el sistema. Si el sistema no pudo conseguir memoria retorna NULL
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

/** \brief Elimina un puntero de empleado
 *
 * \param p Employee* Empleado a eliminar
 * \return void
 *
 */
void employee_delete(Employee* p);

/** \brief Setea el id recibido en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a empleado.
 * \param id int Id a setear.
 * \return int Retorna 0 si el puntero es igual a NULL o si el id recibido es menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setId(Employee* this, int id);
/** \brief Obtiene id del empleado recibido.
 *
 * \param this Employee* Puntero al empleado.
 * \param id int* Puntero al id del empleado.
 * \return int Retorna 0 si los punteros son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_getId(Employee* this, int* id);

/** \brief Setea el nombre recibido en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a empleado.
 * \param nombre char* nombre a setear.
 * \return int Retorna 0 si el puntero es igual a NULL o si el nombre recibido es mayor a 30 caracteres. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setNombre(Employee* this, char* nombre);
/** \brief Obtiene nombre del empleado recibido.
 *
 * \param this Employee* Puntero al empleado.
 * \param nombre char* Puntero al nombre del empleado.
 * \return int Retorna 0 si los punteros son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_getNombre(Employee* this, char* nombre);

/** \brief Setea las horas trabajadas recibidas en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a empleado.
 * \param id int Horas trabajadas a setear.
 * \return int Retorna 0 si el puntero es igual a NULL o si las horas trabajadas recibidas son menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
/** \brief Obtiene las horas trabajadas del empleado recibido.
 *
 * \param this Employee* Puntero al empleado.
 * \param id int* Puntero de horasTrabajadas del empleado.
 * \return int Retorna 0 si los punteros son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

/** \brief Setea el sueldo recibido en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a sueldo.
 * \param id int Sueldo a setear.
 * \return int Retorna 0 si el puntero es igual a NULL o si el sueldo recibido es menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setSueldo(Employee* this, int sueldo);
/** \brief Obtiene el sueldo del empleado recibido.
 *
 * \param this Employee* Puntero al empleado.
 * \param id int* Puntero de sueldo del empleado.
 * \return int Retorna 0 si los punteros son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_getSueldo(Employee* this, int* sueldo);

//Funciones Nuevas

/** \brief Entrada de datos del alta de un empleado
 *
 * \param listaEmpleados LinkedList* lista de empleados recibida
 * \param id int* puntero a id recibido
 * \return int Retorna 0 si la lista de empleados es igual a NULL junto a un auxiliar de empleados. De lo contrario retorna 1
 *
 */
int employee_alta(LinkedList* listaEmpleados, int* id);
/** \brief Entrada de datos de la modificacion de un empleado recibido.
 *
 * \param listaEmpleados LinkedList* Lista de empleados
 * \return int Retorna 0 si la lista de empleados es menor a 0. De lo contrario retorna 1;
 *
 */
int employee_modificar(LinkedList* listaEmpleados);

/** \brief Buscador de empleados por su numero de ID
 *
 * \param listaEmpleados LinkedList* Lista de empleados recibida
 * \param idEmpleado int id del empleado buscado
 * \return int retorna el indice del empleado buscado si la lista de empleados es distinta a NULL
 *
 */
int employee_buscarEmpleadoPorID(LinkedList* listaEmpleados, int idEmpleado); ///////
/** \brief Lista los empleados del programa.
 *
 * \param listaEmpleados LinkedList* Lista de empleados recibida
 * \return int Retorna 0 si la lista de empleados es igual a NULL. De lo contrario retorna 1
 *
 */
int employee_listarEmpleados(LinkedList* listaEmpleados);
/** \brief Lista 1 empleado del programa
 *
 * \param this Employee* Lista de empleados recibida
 * \return int Retorna 0 si la lista de empleados y los getters son igual a NULL. De lo contrario retorna 1
 *
 */
int employee_listarEmpleado(Employee* this);
/** \brief Elimina un empleado del programa
 *
 * \param listaEmpleados LinkedList* Lista de empleados recibida
 * \return int Retorna 0 si el tamanio de la lista es menor a 0. De lo contrario retorna 1
 *
 */
int employee_eliminar(LinkedList* listaEmpleados);

/** \brief Ordena los nombres de una lista de empleados
 *
 * \param employee1 void* Primer empleado a evaluar
 * \param employee2 void* Segundo empleado a evaluar
 * \return int Retorna 0 si los getters de los empleados son true. De lo contrario retorna el resultado del strcmp.
 *
 */
int employee_ordenarNombre(void* employee1, void* employee2);
/** \brief Ordena los id de una lista de empleados
 *
 * \param employee1 void* Primer empleado a evaluar
 * \param employee2 void* Segundo empleado a evaluar
 * \return int Retorna 0 si los empleados son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_ordenarId(void* employee1, void* employee2);
/** \brief  Ordena las horas trabajadas de una lista de empleados
 *
 * \param employee1 void* Primer empleado a evaluar
 * \param employee2 void* Segundo empleado a evaluar
 * \return int Retorna 0 si los empleados son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_ordenarHorasTrabajadas(void* employee1, void* employee2);
/** \brief  Ordena los sueldos de una lista de empleados
 *
 * \param employee1 void* Primer empleado a evaluar
 * \param employee2 void* Segundo empleado a evaluar
 * \return int Retorna 0 si los empleados son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_ordenarSueldo(void* employee1, void* employee2); //Se rompe al tomar el valor 0 como order.
/** \brief Por no dar una respuesta en el programa al modificar el ORDER a 0 en el ll_sort, se formula la siguiente funcion para cumplir con el ordenamiento
 *
 * \param employee1 void* Primer empleado a evaluar
 * \param employee2 void* Segundo empleado a evaluar
 * \return int Retorna 0 si los empleados son iguales a NULL. De lo contrario retorna 1.
 *
 */
int employee_ordenarSueldoDos(void* employee1, void* employee2); //Funcion reemplazante al order 0.
/** \brief Buscael mayor ID de la lista de empleados que haya sido al menos utilizado
 *
 * \param lista LinkedList* Lista de empleados recibida
 * \param id int* direccion de memoria donde nos devuelve el id
 * \return int Retorna 0 si la lista es igual a NULL. De lo contrario retorna 1.
 *
 */
int employee_buscarMayorId(LinkedList* lista, int* id);

//**************************************//

/** \brief Valida que una cadena de caracteres sea ingresada con unicamente letras
 *
 * \param cadena[] char Cadena de caracteres recibida
 * \return int Retorna 1 si los caracteres recibidos se encuentran en el codigo ASCII entre: 65 y 90, y 97 y 122. De lo contrario retorna 0
 *
 */
int validarNombre(char cadena[]);
/** \brief Valuda que una cadena de caracteres sea ingresada unicamente con digitos
 *
 * \param numero[] char Cadena de caracteres recibida
 * \return int Retorna 1 si los caracteres recibidos al ser evaluados por isdigit da como resultado un numero. De lo contrario retorna 0
 *
 */
int validarNumero(char numero[]);

#endif // employee_H_INCLUDED
