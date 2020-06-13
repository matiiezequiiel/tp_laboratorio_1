#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"
#include <string.h>

Employee* employee_new()
{
    Employee* nuevoEmpleado=NULL;

    nuevoEmpleado=(Employee*)malloc(sizeof(Employee));


    return nuevoEmpleado;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmplParam=NULL;
    int id;
    int hsTrabajadas;
    int sueldo;

    nuevoEmplParam=employee_new();
    id=atoi(idStr);
    hsTrabajadas=atoi(horasTrabajadasStr);
    sueldo=atoi(sueldoStr);
    //  printf("%d\n",id);



    employee_setId(nuevoEmplParam,id);/*VALIDAR Y PASAR A INT*/
    // printf("%d\n",idStr);
    employee_setNombre(nuevoEmplParam,nombreStr);
    // printf("%s\n",nombreStr);
    employee_setHorasTrabajadas(nuevoEmplParam,hsTrabajadas);/*VALIDAR Y PASAR A INT*/
    // printf("%d\n",horasTrabajadasStr);
    employee_setSueldo(nuevoEmplParam,sueldo);/*VALIDAR Y PASAR A FLOAT*/
    // printf("%d\n",sueldoStr);
    //system("pause");

    return nuevoEmplParam;


}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this != NULL)
    {
         strcpy(this->nombre,nombre);
         retorno=1;
    }


    return retorno;

}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }

    return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;

    if(this != NULL )
    {
        this->sueldo=sueldo;
        retorno=1;
    }

    return retorno;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }

    return retorno;

}

int employee_setId(Employee* this,int id)
{
    int retorno=0;

    if(this != NULL )
    {
        this->id=id;
        retorno=1;
    }

    return retorno;

}
int employee_getId(Employee* this,int* id)
{
     int retorno=0;

    if(this != NULL && id != NULL)
    {
         *id=this->id;
        retorno=1;
    }

    return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;

    if(this != NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }

    return retorno;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int retorno=0;

    if(this != NULL && horasTrabajdas != NULL)
    {
        *horasTrabajdas=this->horasTrabajadas;
        retorno=1;
    }

    return retorno;

}


int employee_CompareByName(Employee* e1, Employee* e2)
{

    if(e1 != NULL && e2 != NULL)
    {
      return strcmp(e1->nombre, e2->nombre);

    }


}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad
     if(e1 != NULL && e2 != NULL)
    {

        if(e1->id > e2->id)
        {
            return 1;
        }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }



    }

    return strcmp(e1->nombre, e2->nombre);
}

void mostrarEmpleados(Employee* empleado)
{
    int id;
    char nombre[20];
    int hs;
    int sueldo;


    employee_getId(empleado,&id);
    employee_getNombre(empleado,nombre);
    employee_getHorasTrabajadas(empleado,&hs);
    employee_getSueldo(empleado,&sueldo);

    printf("\n");
    printf("%d\t",id);
    printf("%s     \t",nombre);
    printf("%d  \t",hs);
    printf("%d\n",sueldo);

}

