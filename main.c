#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define T 20


int main()
{
    char seguir='s';
    int opcion=0;
    int libre;
    ePersona personas[T];
    inicializarPersonas(personas,T);


    while(seguir=='s')
    {

        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                libre = buscarLibre(personas,T);
                if(libre!=-1)
                {

                    crearPersona(personas,libre);
                    printf("\nPersona ingresada: \n");
                    mostrarPersona(personas[libre]);

                }
                else
                {
                    printf("No hay lugar disponible !\n");
                }

                break;
            case 2:
                eliminarPersona(personas,T);
                break;
            case 3:
                printf("----------------------------------------------------\n");
                ordenar(personas,T);
                listar(personas,T);
                printf("----------------------------------------------------\n");
                break;
            case 4:
                grafico(personas,T);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("La opcion ingresada no es valida. Reingrese\n");
                break;
        }
    }

    return 0;
}
