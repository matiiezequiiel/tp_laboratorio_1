<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char id[20];
    char nombre[20];
    char hsTrabajadas[20];
    char sueldo[20];
    int retorno=0;
    Employee* empleado;

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,hsTrabajadas,sueldo);
        empleado=employee_newParametros(id,nombre,hsTrabajadas,sueldo);

        if(empleado!=NULL && pArrayListEmployee!=NULL)
        {
            ll_add(pArrayListEmployee,empleado);
            retorno=1;
        }
    }

    return retorno;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno=0;

    if(pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {

            auxEmployee=employee_new();
            if(fread(auxEmployee,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee,auxEmployee);
                retorno=1;
            }
            else
            {
                break;
            }

        }
    }


    return retorno;
    /*
    while(!feof(pFile)&&pArrayListEmployee!=NULL)
    {
        auxEmployee=employee_new();
        fread(auxEmployee,sizeof(Employee),1,pFile);

        if (feof(pFile))
        {
            break;
        }
        else
        {
            ll_add(pArrayListEmployee,auxEmployee);
        }

    }
*/

}
=======
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char id[20];
    char nombre[20];
    char hsTrabajadas[20];
    char sueldo[20];
    int retorno=0;
    Employee* empleado;

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,hsTrabajadas,sueldo);
        empleado=employee_newParametros(id,nombre,hsTrabajadas,sueldo);

        if(empleado!=NULL && pArrayListEmployee!=NULL)
        {
            ll_add(pArrayListEmployee,empleado);
            retorno=1;
        }
    }

    return retorno;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno=0;

    if(pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {

            auxEmployee=employee_new();
            if(fread(auxEmployee,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee,auxEmployee);
                retorno=1;
            }
            else
            {
                break;
            }

        }
    }


    return retorno;
    /*
    while(!feof(pFile)&&pArrayListEmployee!=NULL)
    {
        auxEmployee=employee_new();
        fread(auxEmployee,sizeof(Employee),1,pFile);

        if (feof(pFile))
        {
            break;
        }
        else
        {
            ll_add(pArrayListEmployee,auxEmployee);
        }

    }
*/

}
>>>>>>> 765b5f569e3eca1e3793ba023b5893c9a36aa7d9
