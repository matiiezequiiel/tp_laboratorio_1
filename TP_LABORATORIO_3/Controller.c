#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    //ABRIR ARCHIVOS
    FILE* fileArchivo;
    char cabeceraId[20];
    char cabeceraNombre[20];
    char cabeceraHsTrabajadas[20];
    char cabeceraSueldo[20];
    int retorno=0;

    if(pArrayListEmployee!=NULL)
    {
        fileArchivo=fopen(path,"r");
        if(fileArchivo!=NULL)
        {
            printf("Archivo abierto correctamente.\n");
            fscanf(fileArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",cabeceraId,cabeceraNombre,cabeceraHsTrabajadas,cabeceraSueldo);
            if(parser_EmployeeFromText(fileArchivo,pArrayListEmployee))
            {
                retorno=1;
            }
            else
            {
                retorno=0;
            }
        }
        else
        {
            printf("No se pudo abrir el archivo.");
        }
        fclose(fileArchivo);
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* fileBinario;

    if(pArrayListEmployee != NULL)
    {
        fileBinario = fopen(path,"rb");
        if(fileBinario != NULL )
        {
            printf("Archivo abierto correctamente.\n");
            if(parser_EmployeeFromBinary(fileBinario,pArrayListEmployee))
            {
                retorno=1;
            }
            else
            {
                retorno=0;
            }

        }
        else
        {
            printf("No se pudo abrir el archivo.");
        }
        fclose(fileBinario);
    }
    return retorno;



}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    char entrada[20];  //VALIDAR
    char nombre[20];
    int hs;
    int sueldo;
    char confirmacion;
    int retorno=0;

    nuevoEmpleado=employee_new();

    employee_setId(nuevoEmpleado,ll_len(pArrayListEmployee)+1);
    printf("Ingrese nombre del empleado: ");
    gets(entrada); //validarNombre;
    formatearNombres(entrada);
    while(!validarCadena(entrada))
    {
        printf("Nombre invalido, reeingrese: ");
        fflush(stdin);
        gets(entrada);
        formatearNombres(entrada);
        validarCadena(entrada);
    }
    employee_setNombre(nuevoEmpleado,entrada);

    printf("Ingrese hs trabajadas: ");
    gets(entrada);
    hs=getInt(entrada);
    employee_setHorasTrabajadas(nuevoEmpleado,hs);

    printf("Ingrese sueldo: ");
    gets(entrada);
    sueldo=getInt(entrada);
    employee_setSueldo(nuevoEmpleado,sueldo);

    printf("\n\nIngrese S para confirmar, N para salir.");
    printf("\n\nOpcion ingresada: ");
    scanf("%c",&confirmacion);
    confirmacion=toupper(confirmacion);

    if(confirmacion=='S')
    {
         ll_add(pArrayListEmployee,nuevoEmpleado);
         retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idModificar;
    int idArray;
    int i;
    Employee* empleado;
    int retorno=0;

    printf("Ingrese el id a modificar: ");
    scanf("%d",&idModificar);

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        empleado=ll_get(pArrayListEmployee,i);
        employee_getId(empleado,&idArray);

        if(idModificar==idArray )
        {
            printf("ENCONTRADO\n");
            system("pause");
            menuModificaciones(pArrayListEmployee,empleado,i);

        }

    }


    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int lenght;
    int i;
    int idArray;
    int idEliminar;
    int retorno=0;

    Employee* empleado;

    printf("Ingrese el id a eliminar: ");
    scanf("%d",&idEliminar);

    lenght=ll_len(pArrayListEmployee);

    for(i=0; i<lenght; i++)
    {
        empleado=ll_get(pArrayListEmployee,i);
        employee_getId(empleado,&idArray);

        if(idArray==idEliminar )
        {
            printf("ENCONTRADO\n");
            system("pause");
            printf("\n\n");
            ll_remove(pArrayListEmployee,i);
            retorno=1;
            break;
        }

    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int i;

    printf("ID    NOMBRE    HS TRABAJADAS   SUELDO");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        empleado=ll_get(pArrayListEmployee,i);
        mostrarEmpleados(empleado);
    }
    printf("\n\n");
    system("pause");
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    LinkedList* clonLinked;
    Employee* empleado;
    int opcion;

    clonLinked=ll_clone(pArrayListEmployee);

    printf("Ingrese opcion 1 para ordenar por ID.\n");
    printf("Ingrese opcion 2 para ordenar por nombre.\n\n");
    printf("Opcion elegida:");

    scanf("%d",&opcion);


    switch(opcion)
    {
    case 1:
        ll_sort(clonLinked,employee_CompareById,0);
        break;
    case 2:
        ll_sort(clonLinked,employee_CompareByName,0);
        break;
    default:
        break;
    }

    printf("ID    NOMBRE    HS TRABAJADAS   SUELDO");
    for(int i=0; i<ll_len(clonLinked); i++)
    {
        empleado=ll_get(clonLinked,i);
        mostrarEmpleados(empleado);
    }


    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fileText;
    Employee* p;
    int i;

    fileText=fopen(path,"w");

    if(fileText!=NULL)
    {
        fprintf(fileText,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");

        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            p = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(fileText,"%d,%s,%d,%d\n",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
        }
        fclose(fileText);
    }





    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fileBinary;
    Employee* p;
    int i ;
    int cont=0;
    int lenght;

    lenght=ll_len(pArrayListEmployee);
    printf("%d\n",lenght);
    system("pause");

    fileBinary=fopen(path,"wb");

    if(fileBinary!=NULL)
    {

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            p =(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(p,sizeof(Employee),1,fileBinary);
            cont++;
        }
        printf("%d",cont);
        system("pause");
        fclose(fileBinary);
    }
    return 1;
}

