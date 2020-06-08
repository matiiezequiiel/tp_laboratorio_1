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



    do
    {
      opcion=mostrarMenu(numeroMenuX,numeroMenuY);

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
                    resultadoFactorialDos=calcularFactorial(segundoOperando);
                    system("cls");
                    printf("OPERACIONES CALCULADAS, INFORME RESULTADOS CON OPCION 4.\n\n");
                    system("pause");
                    system("cls");
                }

                else
                {
                    continue;
                }

            break;
            case 4:


                if(resultadoSuma==0)
               {
                     system("color 40");
                     printf("Antes de informar los resultados debe realizar los calculos");
                     printf("\n\nPresione la opcion 3 para calcular y luego opcion 4 para ver los resultados.\n\n");
                     system("pause");
                     system("color 0F");
                     system("cls");
               }else if(validarAmbosOperando(numeroMenuX,numeroMenuY)==0)
                     {
                        mostrarMenuResultados(numeroMenuX,numeroMenuY,resultadoSuma,resultadoResta,resultadoMultiplicacion,
                                               resultadoDivision,resultadoFactorialUno,resultadoFactorialDos);
                     }
                    else
                    {
                        continue;
                    }


            break;
            case 5:
                    printf("Gracias por haber usado esta calculadora!.");
            break;
            default:

                system("color 40");
                printf("Ingreso una opcion no valida.\n");
                printf("¿Desea continuar?");
                printf("\n\n ¿S o N?: ");
                fflush(stdin);
                scanf("%c",&respuesta);
                if (toupper(respuesta)=='S')
                {
                     system("color 0F");
                     system("cls");
                     continue;
                }
                else
                 {
                    opcion=5;
                    printf("\n\nGracias por haber usado esta calculadora!.");
                 }

            break;

        }



    }while(opcion!=5);

    return 0;
}

