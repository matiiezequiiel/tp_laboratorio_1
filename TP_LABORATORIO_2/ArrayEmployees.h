typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief Inicializa array de empleados con id autoincrementable y estado.
 *
 * \param Employee[] Array
 * \param int Tamaño de array.
 * \return void
 *
 */
void initEmployees(Employee[],int);



/** \brief Alta de empleado.
 *
 * \param Employee[] Array de emepleados.
 * \param int Tamaño de empleados.
 * \return int 1 alta correcta, 0 operacion cancelada.
 *
 */
int addEmployees(Employee[],int);



/** \brief
 *
 * \param Employee[] Array de emepleados.
 * \param int Tamaño de empleados.
 * \return int int 1 alta correcta, 0 operacion cancelada.
 *
 */
int cargarCamposEmpleados(Employee[],int);



/** \brief Buscar empleado por ID UNICO.
 *
 * \param Employee[] Array de empleados
 * \param int Tamaño de array.
 * \param int ID a buscar.
 * \return int 1 ENCONTRADO, 0 NO ENCONTRADO.
 *
 */
int findEmployeeById(Employee[],int,int);



/** \brief Buscar posicion libre en array.
 *
 * \param Employee[] Array de empleados.
 * \param int Tamaño array.
 * \return int posicion libre, -1 no hay espacio.
 *
 */
int buscarLibreEmpleados(Employee[],int);



/** \brief Muestra por pantalla en modo de listado los empleados activos con su informacion.
 *
 * \param Employee[] Array de empleados.
 * \param int Tamaño de array.
 * \return void
 *
 */
void printEmplyees(Employee[],int);



/** \brief Baja de un empleado.
 *
 * \param Employee[] Array de empleados.
 * \param int Tamaño de array.
 * \param int ID UNICO del empleado a dar de baja.
 * \return int 1 baja correcta, 0 operacion cancelada.
 *
 */
int removeEmployee(Employee[],int,int);



/** \brief Ordenamiento del array por apellido y sector del empleado.
 *
 * \param Employee[] Array de empleados.
 * \param int Tamaño de array.
 * \return void
 *
 */
void sortEmployees(Employee[], int);



/** \brief Mostrar empleados que esten por encima del promedio de sueldo.
 *
 * \param Employee[] Array de empleados.
 * \param int Tamaño de array.
 * \param float Sueldo promedio.
 * \return void
 *
 */
void mostrarEmpleadosEncimaPromedio(Employee[],int,float);



/** \brief Muestra un menu para modificacion de un empleado.
 *
 * \param Employee[] Array de empleados.
 * \param int Tamaño de array.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int menuModificaciones(Employee[],int);


/** \brief Verifica que haya empleados activos al momento de realizar operaciones que lo requieran.
 *
 * \param Array de empleados.
 * \param Tamaño de empleados.
 * \return 1 hay empleados cargados, 0 no hay empleados cargados.
 *
 */
int verificarArrayCarga(Employee[],int);
