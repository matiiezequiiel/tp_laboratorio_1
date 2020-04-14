#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int mostrarMenu(char* numeroMenuX ,char* numeroMenuY ,float suma,float resta,
                float multipicacion,float division,unsigned long long int factorialUno,
                unsigned long long int factorialDos)
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
        printf("\n  A). El resultado de A+B es: %g",suma);
        printf("\n  B). El resultado de A-B es: %g",resta);
        printf("\n  C). El resultado de A/B es: %g",division);
        printf("\n  D). El resultado de A/B es: %g",multipicacion);
        printf("\n  E). El factorial de A es: %llu y El factorial de B es: %llu",factorialUno,factorialDos);
        printf("\n5. Salir");

        printf("\n\nOpcion elegida:");
        scanf("%d",& opcion);
        system("cls");
        return opcion;

}
