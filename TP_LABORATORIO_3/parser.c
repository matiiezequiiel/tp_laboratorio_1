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
    int cant;

    while(!feof(pFile)&&pArrayListEmployee!=NULL)
    {
        auxEmployee=employee_new();


        if (fread(auxEmployee,sizeof(Employee),1,pFile)==1)
        {
            ll_add(pArrayListEmployee,auxEmployee);
        }


    }

    free(pFile);

    return 1;





   /* Employee* auxEmployee;
    int retorno=1;
    int cant;
    int cont=0;


       // auxEmployee= employee_new();
        if(auxEmployee!=NULL)
        {
            while(!feof(pFile))
            {
                auxEmployee= employee_new();
                cant = fread(auxEmployee, sizeof(Employee), 1, pFile);
                printf("%d\n",cant);
                printf("%s\n",auxEmployee->nombre);
                system("pause");
                ll_add(pArrayListEmployee, auxEmployee);
                cont++;
            }


        }


    return retorno;*/

}
