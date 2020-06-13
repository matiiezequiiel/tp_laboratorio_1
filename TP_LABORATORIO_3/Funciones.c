#include "Funciones.h"
#include "Validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int mostrarMenuABM(void)
{
        char entrada[10];
        int opcion;


        printf("BIENVENIDOS: \n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). ");
        printf("\n3. Alta de empleado. ");
        printf("\n4. Modificar datos de empleado.");
        printf("\n5. Baja de empleado.");
        printf("\n6. Listar empleados. ");
        printf("\n7. Ordenar empleados. ");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
        printf("\n10. Salir.");

        printf("\n\nOpcion elegida:");
        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,10);
        system("cls");
        return opcion;


}

