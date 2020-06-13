/** \brief Separa el archivo que ingresa por el caracter ',' ,carga en memoria dinamica los empleados y los agrega a la LinkedList.
 *
 * \param pFile FILE* Archivo.
 * \param pArrayListEmployee LinkedList* LinkedList.
 * \return int 1 carga correcta, 0 no se pudo cargar.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Carga el archivo binario en memoria dinamica y los agrega a la LinkedList.
 *
 * \param pFile FILE* Archivos
 * \param pArrayListEmployee LinkedList* LinkedList
 * \return int 1 carga correcta, 0 no se pudo cargar.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
