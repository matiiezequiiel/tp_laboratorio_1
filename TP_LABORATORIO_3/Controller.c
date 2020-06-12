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


    fileArchivo=fopen(path,"r");

   fscanf(fileArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",cabeceraId,cabeceraNombre,cabeceraHsTrabajadas,cabeceraSueldo);

    while(!feof(fileArchivo))
    {
        parser_EmployeeFromText(fileArchivo,pArrayListEmployee);
    }

    fclose(fileArchivo);

    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* f;

    f = fopen(path,"r+b");

    if(f != NULL)
    {
        while(!feof(f))
        {
            parser_EmployeeFromBinary(f,pArrayListEmployee);
        }
    }

    /*if( f != NULL)
    {
        if(parser_EmployeeFromBinary(f,pArrayListEmployee) != 0)
        {
            printf("\nCarga correcta.!! \n");
            retorno = 1;
        }else
        {
            retorno = 0;
            printf("\nLa carga del archivo no fue correcta.\n");
        }

    }else
    {
        printf("\nEl archivo no se pudo abrir correctamente.\n");
        retorno = 0;
    }*/

    return retorno;



}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    int id=25;
    int hs;
    int sueldo;
    char entrada[20];  //VALIDAR

    nuevoEmpleado=employee_new();

    employee_setId(nuevoEmpleado,id);
    printf("Ingrese nombre del empleado: ");
    gets(entrada);
    employee_setNombre(nuevoEmpleado,entrada);
    printf("Ingrese hs trabajadas: ");
    scanf("%d",&hs);
    employee_setHorasTrabajadas(nuevoEmpleado,hs);
    printf("Ingrese sueldo: ");
    scanf("%d",&sueldo);
    employee_setSueldo(nuevoEmpleado,sueldo);

    ll_add(pArrayListEmployee,nuevoEmpleado);




return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idModificar;
    int idArray;
    int lenght;
    int i;
    char nuevoNombre[20];
    int nuevasHs;
    int nuevoSueldo;
    Employee* empleado;

    printf("Ingrese el id a modificar: ");
    scanf("%d",&idModificar);

    lenght=ll_len(pArrayListEmployee);

    for(i=0;i<lenght;i++)
    {
        empleado=ll_get(pArrayListEmployee,i);
        employee_getId(empleado,&idArray);

        if(idModificar==idArray )
        {
            printf("ENCONTRADO\n");
            system("pause");
            printf("\n\n");
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(nuevoNombre);
            printf("\nIngrese nuevas HS: ");
            scanf("%d",&nuevasHs);
            printf("\nIngrese nuevo sueldo: ");
            scanf("%d",&nuevoSueldo);
            employee_setNombre(empleado,nuevoNombre);
            employee_setHorasTrabajadas(empleado,nuevasHs);
            employee_setSueldo(empleado,nuevoSueldo);
            ll_set(pArrayListEmployee,i,empleado);

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

    Employee* empleado;

    printf("Ingrese el id a eliminar: ");
    scanf("%d",&idEliminar);

    lenght=ll_len(pArrayListEmployee);

    for(i=0;i<lenght;i++)
    {
        empleado=ll_get(pArrayListEmployee,i);
        employee_getId(empleado,&idArray);

        if(idArray==idEliminar )
        {
            printf("ENCONTRADO\n");
            system("pause");
            printf("\n\n");
            ll_remove(pArrayListEmployee,i);
        }

    }
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
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

        for(i=0; i < ll_len(pArrayListEmployee);i++)
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
return 1;
}

