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

/*
IMPORTANTE: EL PROGRAMA TIRA 3 WARNINGS, 2 SON PORQUE LA FUNCION SORT DE LA LINKEDLIST RECIBE DOS PUNTEROS A VOID EN LA FUNCION
CRITERIO POR LO TANTO, AL NO PODER TOCAR LA FUNCION DE LA LINKEDLIST NO PUEDO QUITAR EL WARNING.
Y LA OTRA ES LA FUNCIO TOUPPER QUE SI BIEN AGREGUE LA LIBRERIA STRING SIGUE APARECIENDO EL WARNING
*/

int main()
{
    LinkedList* listaEmpleados;
    int retorno;
    int archivoCargado=0;

    listaEmpleados=ll_newLinkedList();

    int opcion;

    do
    {
        system("cls");
        opcion=mostrarMenuABM();

        switch(opcion)
        {
        case 1:
            retorno=controller_loadFromText("data.csv",listaEmpleados);
            if(!archivoCargado)
            {
                if(retorno)
                {
                    system("cls");
                    printf("\nArchivo cargado correctamente.\n\n");
                    system("pause");
                    archivoCargado=1;
                }
                else
                {
                    system("cls");
                    printf("\nNo se pudo cargar el archivo.\n\n");
                    system("pause");
                }
            }
            else
            {
                system("cls");
                printf("El archivo ya fue cargado.\n\n");
                system("pause");

            }

            break;

        case 2:
            retorno=controller_loadFromBinary("data.bin",listaEmpleados);
            if(!archivoCargado)
            {
                 if(retorno)
                {
                    system("cls");
                    printf("\nArchivo cargado correctamente.\n\n");
                    system("pause");
                    archivoCargado=1;
                }
                else
                {
                    system("cls");
                    printf("\nNo se pudo cargar el archivo.\n\n");
                    system("pause");
                }
            }
            else
            {
                system("cls");
                printf("El archivo ya fue cargado.\n\n");
                system("pause");

            }

            break;

        case 3:
            retorno=controller_addEmployee(listaEmpleados);
            if(retorno)
            {
                system("cls");
                printf("\nEmpleado cargado correctamente.\n\n");
                system("pause");
                archivoCargado=1;
            }
            else
            {
                system("cls");
                printf("\nNo se pudo cargar el empleado.\n\n");
                system("pause");
            }
            break;

        case 4:
            controller_ListEmployee(listaEmpleados);
            retorno=controller_editEmployee(listaEmpleados);
            if(retorno)
            {
                system("cls");
                printf("\nEmpleado editado correctamente.\n\n");
                system("pause");
                archivoCargado=1;
            }
            else
            {
                system("cls");
                printf("\nNo se pudo editar el empleado.\n\n");
                system("pause");
            }
            break;

        case 5:
            controller_ListEmployee(listaEmpleados);
            retorno=controller_removeEmployee(listaEmpleados);
            if(retorno)
            {
                system("cls");
                printf("\nEmpleado eliminado correctamente.\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("\nNo se pudo eliminar al empleado.\n\n");
                system("pause");
            }
            break;

        case 6:
           controller_ListEmployee(listaEmpleados);
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            break;

        case 8:
            retorno=controller_saveAsText("data.csv",listaEmpleados);
            if(retorno)
            {
                system("cls");
                printf("\nArchivo guardado correctamente.\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("\nNo se pudo cargar el archivo.\n\n");
                system("pause");
            }

            break;

        case 9:
            retorno=controller_saveAsBinary("data.bin",listaEmpleados);
            if(retorno)
            {
                system("cls");
                printf("\nArchivo guardado correctamente.\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("\nNo se pudo cargar el archivo.\n\n");
                system("pause");
            }
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
