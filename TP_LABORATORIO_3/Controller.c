#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validaciones.h"
#include "Funciones.h"
#include "Controller.h"


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
            if(menuModificaciones(pArrayListEmployee,empleado,i))
            {
                retorno=1;
            }

        }

    }


    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int lenght;
    int i;
    int idArray;
    int idEliminar;
    int retorno=0;
    char opcion;

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
            printf("Ingrese S para confirmar, N para salir: ");
            fflush(stdin);
            scanf("%c",&opcion);
            opcion=toupper(opcion);

            if(opcion=='S')
            {
                ll_remove(pArrayListEmployee,i);
                retorno=1;
            }
            break;
        }

    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int i;
    int flag=0;

    printf("ID    NOMBRE    HS TRABAJADAS   SUELDO");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {

        if(i %250 == 0)
        {
            printf("\nLista de empleados muy larga, se mostraran de 250 empleados por vez.");
            printf("\n\n");
            system("pause");

        }
        empleado=ll_get(pArrayListEmployee,i);
        mostrarEmpleados(empleado);


    }
    printf("FIN DE LA LISTA");
    printf("\n\n");
    system("pause");
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    LinkedList* clonLinked;
    Employee* empleado;
    int opcion;
    int ordenamiento;
    char entrada[10];
    int retorno=0;

    clonLinked=ll_clone(pArrayListEmployee);

    printf("Ingrese opcion 1 para ordenar por ID.\n");
    printf("Ingrese opcion 2 para ordenar por nombre.\n\n");
    printf("Opcion elegida:");

    scanf("%d",&opcion);


    switch(opcion)
    {
    case 1:
        printf("\nPara ordenar de forma descendente presione 0\n");
        printf("Para ordenar de forma ascendente presione 1 \n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        gets(entrada);
        ordenamiento=validarIntEntreRangos(entrada,0,1);
        if(ordenamiento==0)
        {
            printf("ESPERE, ESTO PUEDE DEMORAR UNOS SEGUNDOS.");
            ll_sort(clonLinked,employee_CompareById,0);
            retorno=1;
        }
        else
        {
            printf("ESPERE, ESTO PUEDE DEMORAR UNOS SEGUNDOS.");
            ll_sort(clonLinked,employee_CompareById,1);
            retorno=1;
        }

        break;
    case 2:
        printf("\nPara ordenar de forma descendente presione 0\n");
        printf("Para ordenar de forma ascendente presione 1 \n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        gets(entrada);
        ordenamiento=validarIntEntreRangos(entrada,0,1);
        if(ordenamiento==0)
        {
            printf("ESPERE, ESTO PUEDE DEMORAR UNOS SEGUNDOS.");
            ll_sort(clonLinked,employee_CompareByName,0);
            retorno=1;
        }
        else
        {
            printf("ESPERE, ESTO PUEDE DEMORAR UNOS SEGUNDOS.");
            ll_sort(clonLinked,employee_CompareByName,1);
            retorno=1;
        }
        break;
    default:
        break;
    }

    system("cls");

    controller_ListEmployee(clonLinked);

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fileText;
    Employee* p;
    int i;
    int retorno=0;

    fileText=fopen(path,"w");

    if(fileText!=NULL)
    {
        fprintf(fileText,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");

        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            p = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(fileText,"%d,%s,%d,%d\n",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
        }
        retorno=1;
        fclose(fileText);
    }
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fileBinary;
    Employee* p;
    int i ;
    int cont=0;
    int lenght;
    int retorno=0;

    fileBinary=fopen(path,"wb");

    if(fileBinary!=NULL)
    {

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            p =(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(p,sizeof(Employee),1,fileBinary);
            retorno=1;
        }

        fclose(fileBinary);
    }
    return retorno;
}

int menuModificaciones(LinkedList* listaEmpleados,void* empleado,int index)
{
    int opcion;
    char entrada[10];
    int nuevasHs;
    int nuevoSueldo;
    char confirmacion;
    int retorno=0;

    system("cls");
    printf("MENU DE MODIFICACIONES.\n\n");
    printf("1.Modificar nombre.\n");
    printf("2.Modificar hs trabajadas.\n");
    printf("3.Modificar sueldo.\n\n");
    printf("Ingrese opcion: ");

    fflush(stdin);
    gets(entrada);
    opcion=getInt(entrada);

    switch(opcion)
    {
    case 1:

        printf("Ingrese nuevo nombre: ");
        fflush(stdin);
        gets(entrada);
        formatearNombres(entrada);
        while(!validarCadena(entrada))
        {
            printf("Nombre invalido, reeingrese: ");
            fflush(stdin);
            gets(entrada);
            formatearNombres(entrada);
            validarCadena(entrada);
        }
        printf("\nS confirma modificacion, N cancela modificacion:");
        scanf("%c",&confirmacion);

        confirmacion=toupper(confirmacion);

        if(confirmacion=='S')
        {
              employee_setNombre(empleado,entrada);
              retorno=1;
        }
        break;

    case 2:
        printf("\nIngrese nuevas HS: ");
        gets(entrada);
        nuevasHs=getInt(entrada);
        printf("\nS confirma modificacion, N cancela modificacion: ");
        scanf("%c",&confirmacion);

        confirmacion=toupper(confirmacion);

        if(confirmacion=='S')
        {
            employee_setHorasTrabajadas(empleado,nuevasHs);
            retorno=1;
        }
        break;
    case 3:
        printf("\nIngrese nuevo sueldo: ");
        gets(entrada);
        nuevoSueldo=getInt(entrada);
        printf("\nS confirma modificacion, N cancela modificacion: ");
        scanf("%c",&confirmacion);

        confirmacion=toupper(confirmacion);

        if(confirmacion=='S')
        {
             employee_setSueldo(empleado,nuevoSueldo);
             retorno=1;
        }

        break;
    }

    ll_set(listaEmpleados,index,empleado);


return retorno;

}


