#include <stdio.h>
#include <stdlib.h>
#include"ArrayEmployees.h"
#include"validaciones.h"

#define TEMPL 5


int main()
{
    Employee empleados[TEMPL];
    int opcion;
    int retorno;
    int id;
    char entrada[10];


   initEmployees(empleados,TEMPL);

    do
    {
        system("cls");
        opcion=mostrarMenu();


        switch(opcion)
        {
            case 1:
            retorno=addEmployees(empleados,TEMPL);
            if(retorno)
            {
                printf("\nEmpleado ingresado correctamente.\n\n");
                system("pause");
            }else
            {
                 printf("La operacion fue cancelada, reeingrese.\n\n");
                 system("pause");
            }
            break;

            case 2:
            if(verificarArrayCarga(empleados,TEMPL))
            {
                printf("Empleados activos actualmente: \n\n");
                printEmplyees(empleados,TEMPL);

                printf("\n\nIngrese ID del empleado a modificar: ");
                fflush(stdin);
                gets(entrada);
                id=validarIntEntreRangos(entrada,1,TEMPL);

                retorno=findEmployeeById(empleados,TEMPL,id);
                if(retorno)
                {
                    printf("Modificacion correcta.\n\n");
                    system("pause");
                }else
                {
                    printf("Operacion cancelada, reeingrese.\n\n");
                    system("pause");
                }
            }else
            {
                printf("No hay empleados cargados, ingrese a la opcion 1 para cargar.\n\n");
                system("pause");
                continue;
            }


            break;

            case 3:
            if(verificarArrayCarga(empleados,TEMPL))
            {
                printf("Empleados activos actualmente: \n\n");
                printEmplyees(empleados,TEMPL);

                printf("\n\nIngrese ID del empleado a eliminar: ");
                fflush(stdin);
                gets(entrada);
                id=validarIntEntreRangos(entrada,1,TEMPL);

                retorno=removeEmployee(empleados,TEMPL,id);
                if(retorno)
                {
                    printf("Eliminacion correcta.\n\n");
                    system("pause");
                }else
                {
                    printf("Operacion cancelada, reeingrese.\n\n");
                    system("pause");
                }
            }
            else
            {
                printf("No hay empleados cargados, ingrese a la opcion 1 para cargar.\n\n");
                system("pause");
                continue;
            }

            break;

            case 4:
            if(verificarArrayCarga(empleados,TEMPL))
            {
                system("cls");
                sortEmployees(empleados,TEMPL);
                printEmplyees(empleados,TEMPL);
            }
            else
            {
                printf("No hay empleados cargados, ingrese a la opcion 1 para cargar.\n\n");
                system("pause");
                continue;
            }

            break;

            case 5:
            printf("Gracias por usar esta aplicacion.");
            break;

            default:
            printf("Opcion invalida.\n\n\n");
            system("pause");
            break;
        }



    }while(opcion!=5);

    return 0;
}
