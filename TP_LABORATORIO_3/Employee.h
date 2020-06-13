#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Pide memoria dinamica para guardar un empleado.
 *
 * \return Employee* Puntero a donde se encontro memoria para guardar el empleado.
 *
 */
Employee* employee_new();


/** \brief Constructor con parametros.
 *
 * \param idStr char* ID del empleado.
 * \param nombreStr char* Nombre del empleado.
 * \param horasTrabajadasStr char* HS trabajadas.
 * \param sueldoStr char* Sueldo del empleado.
 * \return Employee* Puntero a empleado inicializado.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);


/** \brief Borra un empleado.
 *
 * \return void
 *
 */
void employee_delete();


/** \brief Setea el id.
 *
 * \param this Employee* Puntero al empleado a setear.
 * \param id int Nuevo ID.
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Obtiene el ID de un empleado.
 *
 * \param this Employee* Puntero al empleado a obtener.
 * \param id int ID obtenido.
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Setea el nombre.
 *
 * \param this Employee* Puntero al empleado a setear.
 * \param id int Nuevo nombre.
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene el nombre de un empleado
 *
 * \param this Employee* Puntero al empleado a obtener.
 * \param id int Nombre obtenido.
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setea las hs trabajadas.
 *
 * \param this Employee* Puntero al empleado a setear.
 * \param id int Nuevas Hs trabajadas.
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene las hs trabajadas de un empleado.
 *
 * \param this Employee* Puntero al empleado a obtener.
 * \param id int hs trabajas obtenidas
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Setea el sueldo.
 *
 * \param this Employee* Puntero al empleado a setear.
 * \param sueldo int Sueldo del empleado.
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo del empleado.
 *
 * \param this Employee* Puntero del empleado a obtener.
 * \param sueldo int* Sueldo obtenido.
 * \return int 1 seteo correcto, 0 seteo incorrecto.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara los nombres de 2 empleados.
 *
 * \param e1 Employee* Puntero al empleado 1.
 * \param e2 Employee* Puntero al empleado 2.
 * \return int -1 si e1<e2 ,0 si e1=e2 ,1 si e1>e2.
 *
 */
int employee_CompareByName(Employee* e1, Employee* e2);

/** \brief Compara el ID de 2 empleados.
 *
 * \param e1 Employee* Puntero al empleado 1.
 * \param e2 Employee* Puntero al empleado 2.
 * \return int -1 si e1<e2 ,0 si e1=e2 ,1 si e1>e2.
 *
 */
int employee_CompareById(Employee* e1, Employee* e2);

/** \brief Muestra los campos correspondientes a un empleado por pantalla.
 *
 * \param empleado Employee* Puntero del empleado a mostrar.
 * \return void
 *
 */
void mostrarEmpleados(Employee* empleado);

#endif // employee_H_INCLUDED
