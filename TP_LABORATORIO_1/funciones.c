#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int mostrarMenu(char* numeroMenuX ,char* numeroMenuY )
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
        printf("\n  E). El factorial de A es: r y El factorial de B es: r2");
        printf("\n5. Salir");

        printf("\n\nOpcion elegida:");
        scanf("%d",& opcion);
        system("cls");
        return opcion;

}
