#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"
#include "Funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados;
    Employee* empleado;
    int lenght;
    int i;

    listaEmpleados=ll_newLinkedList();

    int opcion;

    do
    {
        opcion=mostrarMenuABM();

        switch(opcion)
        {
        case 1:
            controller_loadFromText("prueba.csv",listaEmpleados);
            break;

        case 2:
            controller_loadFromBinary("nuevo.bin",listaEmpleados);
            break;

        case 3:
            controller_addEmployee(listaEmpleados);
            break;

        case 4:
            lenght=ll_len(listaEmpleados);
            printf("ID    NOMBRE    HS TRABAJADAS   SUELDO");
            for(i=0;i<lenght;i++)
            {
                empleado=ll_get(listaEmpleados,i);
                mostrarEmpleados(empleado);
            }
            controller_editEmployee(listaEmpleados);
            break;

        case 5:
            lenght=ll_len(listaEmpleados);
            printf("ID    NOMBRE    HS TRABAJADAS   SUELDO");
            for(i=0;i<lenght;i++)
            {
                empleado=ll_get(listaEmpleados,i);
                mostrarEmpleados(empleado);
            }
            controller_removeEmployee(listaEmpleados);
            break;

        case 6:
            lenght=ll_len(listaEmpleados);
            printf("ID    NOMBRE    HS TRABAJADAS   SUELDO");
            for(i=0;i<lenght;i++)
            {
                empleado=ll_get(listaEmpleados,i);
                mostrarEmpleados(empleado);
            }
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            break;

        case 8:
            controller_saveAsText("nuevo.csv",listaEmpleados);
            break;

        case 9:
            controller_saveAsBinary("nuevo.bin",listaEmpleados);
            break;

        case 10:
            system("cls");
            printf("Gracias por haber usado esta aplicacion.");
            break;
        }

    }
    while(opcion!=10);



    return 0;
}
