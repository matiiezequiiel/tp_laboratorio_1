#include "Validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int getInt(char* entero)
{
    int retorno;
    int enteroValidado;

    retorno=validarEntero(entero);

    while(retorno)
    {
        printf("Numero invalido.\n\n");
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

        //if( (cadenaValidar[i]>='a' && cadenaValidar[i]<='z') || (cadenaValidar[i]>='A' && cadenaValidar[i]<='Z') || (contadorEspacios==0) || (lenght==0))
        if( (cadenaValidar[i]>='a' && cadenaValidar[i]<='z') || (cadenaValidar[i]>='A' && cadenaValidar[i]<='Z') )
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

//void formatearNombres (char* nombre,char* apellido)
void formatearNombres (char* nombre)
{
    char apellidoNombre[30];
    int i;

    strlwr(nombre);
  //  strlwr(apellido);
    nombre[0]=toupper(nombre[0]);
 //   apellido[0]=toupper(apellido[0]);

  //  for(i=0;i<strlen(nombre);i++)
  //  {
  //      if(isspace(nombre[i]))
  //          nombre[i+1]=toupper(nombre[i+1]);
  //  }

 //   strcpy(apellidoNombre, apellido);
  //  strcat(apellidoNombre, ", ");
  //  strcat(apellidoNombre, nombre);
        strcpy(apellidoNombre, nombre);

}
