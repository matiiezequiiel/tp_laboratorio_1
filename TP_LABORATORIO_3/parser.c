#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    //PARSEAR EL ARCHIVO,CONSTRUIR EMPLEADO, CARGAR CON LOS SETTERS EL CAMPO Y AGREGARLOS A LL

    char id[20];
    char nombre[20];
    char hsTrabajadas[20];
    char sueldo[20];
    Employee* empleado;


    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,hsTrabajadas,sueldo);

    empleado=employee_newParametros(id,nombre,hsTrabajadas,sueldo);

    ll_add(pArrayListEmployee,empleado);



    return 1;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    int retorno=1;
    int cant;


        auxEmployee= employee_new();
        if(auxEmployee!=NULL)
            {
            cant = fread(auxEmployee, sizeof(Employee), 1, pFile);
            ll_add(pArrayListEmployee, auxEmployee);

            }







  /*   while(!feof(pFile))
    {
        auxEmployee= employee_new();
        if(auxEmployee!=NULL){
            cant = fread(auxEmployee, sizeof(Employee), 1, pFile);

            if(cant<1)
            {
                if(!feof(pFile))
                    retorno=0;
                break;
            }
            if(ll_add(pArrayListEmployee, auxEmployee) == 0)
            {

                retorno=1;
            }
        }
    }*/
    return retorno;

}
