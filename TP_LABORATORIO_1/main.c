#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


/*
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/
float getOperando(char[]);
float calcularSuma(float operandoUno, float operandoDos);
float calcularResta(float operandoUno, float operandoDos);
float calcularMultiplicacion(float operandoUno, float operandoDos);
float calcularDivision(float operandoUno, float operandoDos);
unsigned long long int calcularFactorial(float operandoUno);
int validarEntrada(char[]);
int validarAmbosOperando(char[],char[]);

int main()
{
    int opcion;
    float primerOperando;
    float segundoOperando;
    char numeroMenuX[10]="X";
    char numeroMenuY[10]="Y";
    char respuesta=' ';
    float resultadoSuma=0;
    float resultadoResta=0;
    float resultadoMultiplicacion=0;
    float resultadoDivision=0;
    unsigned long long int resultadoFactorialUno=0;
    unsigned long long int resultadoFactorialDos=0;

    int auxFactorial;


    do
    {
        opcion=mostrarMenu(numeroMenuX,numeroMenuY,resultadoSuma,resultadoResta,resultadoMultiplicacion,
                           resultadoDivision,resultadoFactorialUno,resultadoFactorialDos);

        switch(opcion)
        {
            case 1:

                 printf("Ingrese el primer operando: ");
                 fflush(stdin);
                 gets(numeroMenuX);
                 primerOperando=getOperando(numeroMenuX);
                 system("cls");

            break;
            case 2:
                printf("Ingrese el segundo operando: ");
                fflush(stdin);
                gets(numeroMenuY);
                segundoOperando=getOperando(numeroMenuY);
                system("cls");

            break;
            case 3:
                if(validarAmbosOperando(numeroMenuX,numeroMenuY)==0)
                {
                    resultadoSuma=calcularSuma(primerOperando,segundoOperando);
                    resultadoResta=calcularResta(primerOperando,segundoOperando);
                    resultadoMultiplicacion=calcularMultiplicacion(primerOperando,segundoOperando);
                    resultadoDivision=calcularDivision(primerOperando,segundoOperando);
                    resultadoFactorialUno=calcularFactorial(primerOperando);
                    resultadoFactorialUno=calcularFactorial(primerOperando);
                }

                else
                {
                    continue;
                }

            break;
            case 4:
            break;
            case 5:
            break;
        }



    }while(opcion!=5);

    return 0;
}



float getOperando(char* operando)
{
    float operandoValidado;

    while(validarEntrada(operando)==1)
    {
        printf("Numero no valido!!, Ingrese otro numero: ");
        fflush(stdin);
        gets(operando);
        validarEntrada(operando);
    }

    operandoValidado=atof(operando);

    return operandoValidado;



}

int validarEntrada(char* entrada)
{
     int i;
     int lenght;
     lenght=strlen(entrada);

     for (i=0;i<lenght;i++)
    {


              if(isdigit(entrada[i])==0 || isspace(entrada[i]!=0)) //SI ES 0 ES UN DIGITO INVALIDO (NO ES NUMERO)
            {
                if(entrada[i]!='.' && entrada[i]!='-')// VER QUE NO FUNCIONAN NUMEROS NEGATIVOS.
                    return 1;
                if(i==0)
                    return 1;
            }



    }
    return 0;
}

int validarAmbosOperando(char* numeroUno,char* numeroDos)
{
        if(numeroUno[0]=='X'||numeroDos[0]=='Y')
        {
              printf("Alguno de los operandos no fueron cargados.\n\n");
              printf("Cargue con opcion 1 u opcion 2 ambos operandos para continuar.\n\n");
              system("pause");
              system("cls");
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
unsigned long long int calcularFactorial(float operandoUno)
{

}
