#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<ctype.h>
#include"ArrayEmployees.h"
#include"validaciones.h"

int mostrarMenu(void)
{
        char entrada[10];
        int opcion;

        printf("BIENVENIDOS: \n\n");
        printf("1. Alta empleado. ");
        printf("\n2. Modificar empleado. ");
        printf("\n3. Baje empleado. ");
        printf("\n4. Informar empleados y salarios.");
        printf("\n5. Salir.");

        printf("\n\nOpcion elegida:");
        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,5);
        system("cls");
        return opcion;


}

int validarCadena(char cadenaValidar[])
{
    int retorno=0;
    int lenght;
    int i;
    int contadorEspacios=0;

    lenght=strlen(cadenaValidar);

    for(i=0;i<lenght;i++)
    {
        if(cadenaValidar[i]==' ')
        {
            contadorEspacios++;
        }

        if( (cadenaValidar[i]>='a' && cadenaValidar[i]<='z') || (cadenaValidar[i]>='A' && cadenaValidar[i]<='Z') || (contadorEspacios==1 && i>0))
        {
             retorno=1;
        }
        else
        {
            retorno=0;
            break;
        }

    }


    return retorno;


}

float getFloat(char* numeroValidar)
{

   float operandoValidado;

    while(validarFloat(numeroValidar)==1)
    {
        system("cls");
        printf("Numero no valido!!, Ingrese otro numero: ");
        fflush(stdin);
        gets(numeroValidar);
        validarFloat(numeroValidar);

    }

    operandoValidado=atof(numeroValidar);

    return operandoValidado;

}
int validarFloat(char* numeroValidar )
{

     int i;
     int lenght;
     int contadorPuntos=0;
     lenght=strlen(numeroValidar);


     if(numeroValidar[0]=='\0')
        return 1;


     for (i=0;i<lenght;i++)
    {


              if(isdigit(numeroValidar[i])==0 || isspace(numeroValidar[i]!=0)) //SI ES 0 ES UN DIGITO INVALIDO (NO ES NUMERO)
            {

              if(numeroValidar[i]!='-' && numeroValidar[i]!='.')
              {
                  return 1;
              }

              //SIGNO -
            /*  if(numeroValidar[i]=='-')
              {
                  if( lenght==1 || i!=0 )
                  {
                      return 1;
                  }

              }*/
              //SIGNO .
               if(numeroValidar[i]=='.')
               {
                    if(i==0)
                    {
                        return 1;
                    }

               }
               else
               {
                   contadorPuntos++;
               }


               if(contadorPuntos>1)
               {
                   return 1;
               }


            }


    }
    return 0;

}

int getInt(char* entero)
{
    int retorno;
    int enteroValidado;

    retorno=validarEntero(entero);

    while(retorno)
    {
        //system("cls");
        printf("Numero invalido.\n");
        printf("Reeingrese el numero: ");
        gets(entero);
        retorno=validarEntero(entero);
    }

    enteroValidado=atoi(entero);

    return enteroValidado;

}

int validarEntero (char* numeroValidar)
{
    int i;
    int lenght;
    int retorno=0;

    lenght=strlen(numeroValidar);

    if (lenght==0)  //VACIO
    {
        retorno=1;
    }

    for(i=0;i<lenght;i++)
    {

        if(isdigit(numeroValidar[i])==0) //0 NO ES NUMERO. !=0 ES NUMERO
        {
            retorno=1;
            break;
        }
    }

    return retorno;

}

int validarIntEntreRangos(char entrada[] ,int rangoMinimo,int rangoMaximo)
{
    int numeroValidar;

    numeroValidar=getInt(entrada);

    while(numeroValidar<rangoMinimo || numeroValidar>rangoMaximo)
    {
      //  system("cls");
        printf("Numero invalido, reeingrese un numero valido: \n");
     //   printf("1.Confirma.\n");
     //   printf("2.Cancela.\n\n");
        printf("Ingrese opcion:");
        gets(entrada);
        numeroValidar=getInt(entrada);

    }

    return numeroValidar;

}

void formatearNombres (char* nombre)
{
    int i;

    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);

    for(i=0;i<strlen(nombre);i++)
    {
        if(isspace(nombre[i]))
            nombre[i+1]=toupper(nombre[i+1]);
    }


}
