#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void mostrarMenuResultados(char* numeroMenuX ,char* numeroMenuY ,float suma,float resta,
                float multipicacion,float division,unsigned long long int factorialUno,
                unsigned long long int factorialDos)
{


        printf("BIENVENIDOS A LA CALCULADORA!!\n\n");
        printf("1. Ingresar 1er operando (A=%s)",numeroMenuX);
        printf("\n2. Ingresar 2do operando (B=%s)", numeroMenuY);
        printf("\n3. Calcular todas las operaciones.");
        printf("\n  A). Calcular la suma (A+B)");
        printf("\n  B). Calcular la resta (A-B)");
        printf("\n  C). Calcular la division (A/B)");
        printf("\n  D). Calcular la multiplicacion (A*B)");
        printf("\n  E). Calcular el factorial (A!)");
        printf("\n4. Informar resultados.");
        printf("\n  A). El resultado de A+B es: %g",suma);
        printf("\n  B). El resultado de A-B es: %g",resta);
        printf("\n  C). El resultado de A/B es: %g",division);
        printf("\n  D). El resultado de A/B es: %g",multipicacion);
        printf("\n  E). El factorial de A es: %llu y El factorial de B es: %llu",factorialUno,factorialDos);
        printf("\n5. Salir");
        printf("\n\n\n");
        system("pause");
        system("cls");


}

int mostrarMenu(char* numeroMenuX ,char* numeroMenuY)
{

        int opcion;

        printf("BIENVENIDOS A LA CALCULADORA!!\n\n");
        printf("1. Ingresar 1er operando (A=%s)",numeroMenuX);
        printf("\n2. Ingresar 2do operando (B=%s)", numeroMenuY);
        printf("\n3. Calcular todas las operaciones.");
        printf("\n  A). Calcular la suma (A+B)");
        printf("\n  B). Calcular la resta (A-B)");
        printf("\n  C). Calcular la division (A/B)");
        printf("\n  D). Calcular la multiplicacion (A*B)");
        printf("\n  E). Calcular el factorial (A!)");
        printf("\n4. Informar resultados.");
        printf("\n  A). El resultado de A+B es:");
        printf("\n  B). El resultado de A-B es:");
        printf("\n  C). El resultado de A/B es:");
        printf("\n  D). El resultado de A/B es:");
        printf("\n  E). El factorial de A es: y El factorial de B es: ");
        printf("\n5. Salir");

        printf("\n\nOpcion elegida:");
        scanf("%d",& opcion);
        system("cls");
        return opcion;

}


float getOperando(char* operando)
{
    float operandoValidado;

    while(validarEntrada(operando)==1)
    {
        system("color 40");
        printf("Numero no valido!!, Ingrese otro numero: ");
        fflush(stdin);
        gets(operando);
        validarEntrada(operando);

    }
    system("color 0F");

    operandoValidado=atof(operando);

    return operandoValidado;



}

int validarEntrada(char* entrada)
{
     int i;
     float numero;
     int lenght;
     int contadorPuntos=0;
     lenght=strlen(entrada);

    numero=atof(entrada);
    if(numero==0)
    {
        return 1;
    }

    if(entrada[0]=='\0')
       return 1;


     for (i=0;i<lenght;i++)
    {


              if(isdigit(entrada[i])==0 || isspace(entrada[i]!=0)) //SI ES 0 ES UN DIGITO INVALIDO (NO ES NUMERO)
            {

              if(entrada[i]!='-' && entrada[i]!='.')
                return 1;

              //SIGNO -
              if(entrada[i]=='-')
              {
                  if( lenght==1 || i!=0 )
                  return 1;
              }
              //SIGNO .
               if(entrada[i]=='.')
                   if(i==0)
                   return 1;
               else
                   contadorPuntos++;

               if(contadorPuntos>1)
                    return 1;

            }





    }
    return 0;
}

int validarAmbosOperando(char* numeroUno,char* numeroDos)
{
        if(numeroUno[0]=='X'||numeroDos[0]=='Y')
        {

              system("color 40");
              printf("Alguno de los operandos no fueron cargados.\n\n");
              printf("Cargue con opcion 1 u opcion 2 ambos operandos para continuar.\n\n");
              system("pause");
              system("cls");
              system("color 0F");
              return 1;
        }
        else
              return 0;
}

float calcularSuma(float operandoUno, float operandoDos)
{
    float resultado;

    resultado=operandoUno+operandoDos;

    return resultado;
}
float calcularResta(float operandoUno, float operandoDos)
{
    float resultado;

    resultado= operandoUno-operandoDos;

    return resultado;
}
float calcularMultiplicacion(float operandoUno, float operandoDos)
{
    float resultado;

    resultado= operandoUno*operandoDos;

    return resultado;
}
float calcularDivision(float operandoUno, float operandoDos)
{
    float resultado;

    resultado= operandoUno/operandoDos;

    return resultado;
}
unsigned long long int calcularFactorial(float operando)
{
     int i;
     unsigned long long int resultado=1; //ver factorial de 0 y 1



    for(i=operando;i>1;i--)
    {
        if (i==operando)
        {
            i--;
            resultado=operando*i;
        }

        else
        {
            resultado=resultado*i;
        }

    }

    return resultado;
}
