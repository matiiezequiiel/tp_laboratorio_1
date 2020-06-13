/** \brief Apertura del archivo y llamado a funcion parser.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayListEmployee LinkedList*
 * \return int 1 apertura y carga correcta, 0 error.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Apertura del archivo y llamado a funcion parser.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayListEmployee LinkedList*
 * \return int int 1 apertura y carga correcta, 0 error.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Agrega un empleado a la LinkedList.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 empleado agregado correctamente, 0 no se pudo agregar al empleado.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Edita un empleado de la LinkedList.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 empleado editado correctamente, 0 no se pudo editar el empleado.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Elimina un empleado de la LinkedList.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 empleado eliminado correctamente, 0 no se pudo eliminar el empleado.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Lista los empleados cargados en la LinkedList.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 listado correcto.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Menu para elegir el criterio de ordenamiento.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 ordenamiento correcto.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda lo cargado en la LinkedList separado por coma.
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int 1 carga correcta, 0 no se pudo cargar.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief  Guarda lo cargado en la LinkedList en formato binario.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayListEmployee LinkedList*
 * \return int  int 1 carga correcta, 0 no se pudo cargar.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Muestra un meno para modificar un empleado.
 *
 * \param listaEmpleados LinkedList* LinkedList.
 * \param empleado void* Puntero a empleado.
 * \param index int Indice donde se encuentra el empleado en la LinkedList.
 * \return int 1 modificacion correcta, 0 no se pudo modificar
 *
 */
int menuModificaciones(LinkedList* listaEmpleados,void* empleado,int index);


