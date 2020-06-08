#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include"ArrayEmployees.h"
#include"validaciones.h"


void initEmployees(Employee nominaEmpleados[],int sizeEmpleados)
{
    int i;

    for(i=0;i<sizeEmpleados;i++)
    {
        nominaEmpleados[i].id=i+1;
        nominaEmpleados[i].isEmpty=true;
    }

}


int addEmployees(Employee nominaEmpleados[],int sizeEmpleados)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreEmpleados(nominaEmpleados,sizeEmpleados);

    system("cls");

    if(posicionLibre!=-1)

    {
        confirmacion=cargarCamposEmpleados(nominaEmpleados,posicionLibre);


        if (confirmacion==1)
        {
            nominaEmpleados[posicionLibre].isEmpty=false;
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }


}

int cargarCamposEmpleados(Employee nominaEmpleados[],int posicionLibre)
{
    char entrada[10];
    char opcion[5];
    int confirmacion;


        printf("Ingrese nombre del empleado: ");
        fflush(stdin);
        gets(nominaEmpleados[posicionLibre].name);
        formatearNombres(nominaEmpleados[posicionLibre].name);
        while(validarCadena(nominaEmpleados[posicionLibre].name)==0)
        {
            system("cls");
            printf("Nombre invalido, reeingrese nombre: ");
            formatearNombres(nominaEmpleados[posicionLibre].name);
            gets(nominaEmpleados[posicionLibre].name);
            validarCadena(nominaEmpleados[posicionLibre].name);

        }
        printf("\nIngrese apellido del empleado: ");
        fflush(stdin);
        gets(nominaEmpleados[posicionLibre].lastName);
        formatearNombres(nominaEmpleados[posicionLibre].lastName);
        while(validarCadena(nominaEmpleados[posicionLibre].lastName)==0)
        {
            system("cls");
            printf("Apellido invalido, reeingrese apellido: ");
            gets(nominaEmpleados[posicionLibre].lastName);
            formatearNombres(nominaEmpleados[posicionLibre].lastName);
            validarCadena(nominaEmpleados[posicionLibre].lastName);

        }
        printf("\nIngrese salario del empleado: ");
        gets(entrada);
        nominaEmpleados[posicionLibre].salary=getFloat(entrada);

        printf("\nIngrese sector del empleado: ");
        gets(entrada);
        nominaEmpleados[posicionLibre].sector=getInt(entrada);

        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(opcion);

        confirmacion=validarIntEntreRangos(opcion,1,2);

        return confirmacion;

}


int findEmployeeById(Employee nominaEmpleados[],int sizeEmpleados,int idModificar)
{
    int i;
    int retorno=0;
    int contEmpleados=0;



    if(idModificar<0 || idModificar>sizeEmpleados)
    {
        return 0;
    }

    for(i=0;i<sizeEmpleados;i++)

    {
        if((nominaEmpleados[i].id==idModificar) && (nominaEmpleados[i].isEmpty==false))
        {
            system("cls");
            printf("EMPLEADO ENCONTRADO. \n");

            contEmpleados++;
            retorno=menuModificaciones(nominaEmpleados,i);

        }

    }

    if(contEmpleados==0)
    {
        printf("No se encontraron empleados\n\n");

    }

    return retorno;


}

int buscarLibreEmpleados(Employee nominaEmpleados[],int sizeEmpleados)
{
    int i;
    int lugarLibre=-1;

        for(i=0;i<sizeEmpleados;i++)
        {
            if(nominaEmpleados[i].isEmpty==true)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;
}


void printEmplyees(Employee nominaEmpleados[],int sizeEmpleados)
{
    int i;
    float totalSalarios=0;
    int contEmpleados=0;
    float promedio;

    printf("ID      NOMBRE          APELLIDO  SALARIO           SECTOR \n");

    for(i=0;i<sizeEmpleados;i++)
    {
        if(nominaEmpleados[i].isEmpty==false)
        {


            printf("%d\t",nominaEmpleados[i].id);
            printf("%s     \t",nominaEmpleados[i].name);
            printf("%s\t  ",nominaEmpleados[i].lastName);
            printf("%.2f\t    ",nominaEmpleados[i].salary);
            printf("%d\n",nominaEmpleados[i].sector);
            totalSalarios=nominaEmpleados[i].salary+totalSalarios;
            contEmpleados++;

        }
    }
    printf("\nSalario total todos los empleados: %.2f\n",totalSalarios);
    promedio=totalSalarios/contEmpleados;
    printf("Promedio de salario: %.2f\n\n",promedio);
    mostrarEmpleadosEncimaPromedio(nominaEmpleados,sizeEmpleados,promedio);

    printf("\n\n");
    system("pause");
}

int removeEmployee(Employee nominaEmpleados[],int sizeEmpleados,int idEliminar)
{
    int i;
    char entrada[10];
    int confirmacion;
    int retorno=0;
    int contEmpleados=0;

    for(i=0;i<sizeEmpleados;i++)

    {
        if((nominaEmpleados[i].id==idEliminar) && (nominaEmpleados[i].isEmpty==false))
        {
                contEmpleados++;
                system("cls");
                printf("EMPLEADO ENCONTRADO. \n");

                printf("Ingrese 1 para confirmar la eliminacion.\n");
                printf("Ingrese 2 para salir.\n\n");
                printf("Opcion elegida: ");

                gets(entrada);

                confirmacion=validarIntEntreRangos(entrada,1,2);

                if (confirmacion==1)
                {
                    nominaEmpleados[i].isEmpty=true;
                    return 1;
                }
                else
                {
                    return 0;
                }
                break;
        }

    }

    if(contEmpleados==0)
    {
        printf("No se encontraron empleados\n\n");

    }


    return retorno;



}

void sortEmployees(Employee nominaEmpleados[], int sizeEmpleados)
{
    int i;
    int j;
    Employee auxEmpleado;

    for(i=0; i<sizeEmpleados-1; i++)
    {
        for(j=i+1; j<sizeEmpleados; j++)
        {
            if(strcmp(nominaEmpleados[i].lastName,nominaEmpleados[j].lastName)>0)
            {
               auxEmpleado  =  nominaEmpleados[i];
               nominaEmpleados[i] = nominaEmpleados[j];
               nominaEmpleados[j] = auxEmpleado;
            }
            else
            {
               if(strcmp(nominaEmpleados[i].lastName,nominaEmpleados[j].lastName)==0)
               {
                   if(nominaEmpleados[i].sector>nominaEmpleados[j].sector)
                   {
                          auxEmpleado  =  nominaEmpleados[i];
                          nominaEmpleados[i] = nominaEmpleados[j];
                          nominaEmpleados[j] = auxEmpleado;
                   }
               }
            }

        }
    }
}



void mostrarEmpleadosEncimaPromedio(Employee nominaEmpleados[] ,int sizeEmpleados,float sueldoPromedio)
{
    int i;

    printf("Empleados con sueldo mayor al promedio: \n");

    for(i=0;i<sizeEmpleados;i++)
    {
        if(nominaEmpleados[i].isEmpty==false && nominaEmpleados[i].salary>sueldoPromedio)
        {


            printf("%d\t",nominaEmpleados[i].id);
            printf("%s     \t",nominaEmpleados[i].name);
            printf("%s\t  ",nominaEmpleados[i].lastName);
            printf("%.2f\t    ",nominaEmpleados[i].salary);
            printf("%d\n",nominaEmpleados[i].sector);

        }
    }
}

int menuModificaciones(Employee nominaEmpleados[],int posicionModificar)
{
    char entrada[10];
    int opcion;
    int confirmacion;
    float nuevoSalario;
    int nuevoSector;
    char auxModificacion[30];


        printf("\n\n1.Modificar nombre.");
        printf("\n2.Modificar apellido.");
        printf("\n3.Modificar salario.");
        printf("\n4.Modificar sector.");
        printf("\n\nIngrese opcion: ");

        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,4);

                switch(opcion)
                {
                    case 1:
                    system("cls");
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    while (validarCadena(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Nombre invalido, reeingrese nombre: ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarCadena(auxModificacion);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        formatearNombres(auxModificacion);
                        strcpy(nominaEmpleados[posicionModificar].name,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 2:
                    system("cls");
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    while (validarCadena(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Apellido invalido, reeingrese apellido: ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarCadena(auxModificacion);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        formatearNombres(auxModificacion);
                        strcpy(nominaEmpleados[posicionModificar].lastName,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 3:
                     system("cls");
                    printf("Ingrese nuevo salario: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    nuevoSalario=getFloat(auxModificacion);

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        nominaEmpleados[posicionModificar].salary=nuevoSalario;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 4:
                    system("cls");
                    printf("Ingrese nuevo sector: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    nuevoSector=getInt(auxModificacion);

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        nominaEmpleados[posicionModificar].sector=nuevoSector;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;
                    default:
                    system("cls");
                    printf("Opcion invalida, vuelva a comenzar.\n\n");
                    system("pause");
                    return 0;
                    break;
                }
}

int verificarArrayCarga(Employee nominaEmpleados[],int sizeEmpleados)
{
    int i;
    int retorno=0;

    for(i=0;i<sizeEmpleados;i++)
    {
        if(nominaEmpleados[i].isEmpty==false)
        {
            return 1;
        }
        else
        {
            continue;
        }
    }

    return retorno;
}

