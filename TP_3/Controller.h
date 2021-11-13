/** \brief Carga en nuestro programa los datos de un archivo de texto .csv
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int Retorna 0 si los punteros recibidos son igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);//Abre el archivo
/** \brief Carga en nuestro programa los datos de un archivo binario .bin
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int retorna 0 si los punteros recibidos son igual a NULL, sino retorna 1.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);//Abre el archivo
/** \brief Agrega un nuevo empleado a la lista recibida
 *
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \param id int* puntero del id a leer
 * \return int retorna 0 si la lista es igual a NULL, sino retorna 1.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
/** \brief Edita cualquier empleado de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int retorna 0 si la lista es igual a NULL, sino retorna 1.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Elimina cualquier empleado de la lista de empleados
 *
 *
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int retorna 0 si la lista es igual a NULL, sino retorna 1.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Lista los empleados recibidos
 *
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int retorna 0 si la lista es igual a NULL, sino retorna 1.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordena la lista de los empleados recibidos
 *
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int retorna 0 si la lista es igual a NULL, sino retorna 1.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda la lista de empleados en un archivo de texto en la direccion indicada
 *
 * \param path char* Direccion indicada
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int retorna 0 si los punteros recibidos son igual a NULL, sino retorna 1.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda la lista de empleados en un archivo binario en la direccion indicada
 *
 * \param path char* Direccion indicada
 * \param pArrayListEmployee LinkedList* lista de empleados recibida
 * \return int retorna 0 si los punteros recibidos son igual a NULL, sino retorna 1.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
