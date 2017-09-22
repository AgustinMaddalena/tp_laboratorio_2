#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <conio.h>

void mostrarPersona(ePersona personas)
{
    printf("-Nombre: %s\n-DNI: %d\n-Edad: %d\n", personas.nombre, personas.dni, personas.edad); /// Muestra la persona pasada por parametro.
}


void inicializarPersonas(ePersona personas[],int tam) /// inicializa todo el array de "ePersona" para que en la funcion de buscar espacio
                                                 /// encuentre un valor valido y no basura.
{
    int i;
     for(i = 0 ; i < tam ; i++)
     {
         personas[i].estado = 0;
     }
}
int buscarLibre(ePersona personas[], int tam) /// Busca un lugar para ingresar una persona.
{
    int lugar = -1;
    int i;

    for(i = 0 ; i < tam ; i++)  /// busca en el array de ePersona.
    {
        if(personas[i].estado == 0)
        {
            lugar = i;
            break;
        }
    }
return lugar; /// Devuelve el lugar del array que encontro un espacio.
}
void crearPersona(ePersona personas[], int posicion) /// Crea una ePersona
{
    int edad,dni;
    char nombre[60];


                printf("Ingrese nombre: \n");
                fflush(stdin);
                gets(nombre);
                printf("Ingrese edad: \n");
                scanf("%d", &edad);
                fflush(stdin);
                printf("Ingrese DNI: \n");
                scanf("%d",&dni);
                fflush(stdin);


    strcpy(personas[posicion].nombre,nombre);
    personas[posicion].edad = edad;
    personas[posicion].dni = dni;
    personas[posicion].estado = 1;


}

void eliminarPersona(ePersona personas[],int tam)       /// Elimina una ePersona pasada por parametro.
{
    int i, aux, flag;
    char respuesta;

    flag = 0;
    printf("Ingrese DNI de la persona a eliminar: \n");
    scanf("%d",&aux);                                               /// Guarda el DNI de la persona a eliminar en un auxiliar.

    for(i = 0; i < tam ; i++)   /// Recorre el array de ePersona para encontrar el valor pasado por parametro.
    {
        if(personas[i].estado == 1 && aux == personas[i].dni)
        {
            mostrarPersona(personas[i]);

            printf("Esta seguro de eliminar la persona elegida?: ");
            respuesta = getche();                                       /// confirmacion de eliminacion.
            if(respuesta == 's')
            {
                personas[i].estado = 0;
            }
            else
            {
                printf("\nAccion cancelada.\n");
            }
            flag=1;                                                       /// Si encuentra la persona, levanta la bandera.
            break;
        }

    }
    if(flag == 0)                                                       /// si la bandera esta baja, notifica que la persona no existe en la base.
    {
        printf("La persona a eliminar es inexistente.\n");
    }
}



void ordenar(ePersona personas[],int tam)
{
    int i,j;
    ePersona auxPersona;

    for(i = 0; i < tam-1 ; i++) /// recorre el array en la posicion i, hasta uno antes del final, asi poder comparar.
    {
        for(j=i+1; j < tam ; j++) /// con este for que recorre una posicion mas que el anterior.
        {
           if(strcmp(personas[i].nombre,personas[j].nombre) > 0) /// si devuelve mayor a 0, intercambia los valores por burbujeo.
           {
              strcpy(auxPersona.nombre,personas[i].nombre);
              strcpy(personas[i].nombre,personas[j].nombre);
              strcpy(personas[j].nombre,auxPersona.nombre);
           }
        }
    }



}

void listar(ePersona personas[],int tam)
{
    int i;

    for(i = 0; i < tam ; i++)
    {
        if(personas[i].estado!=0)
        {
            mostrarPersona(personas[i]);     ///lista las personas usando la funcion de mostrar un solo individuo, pasandole por parametro la posicion "i".
        }
    }


}

void grafico(ePersona personas[],int tam)
{
    int i;

    for(i = 0; i < tam ; i++)               /// Recorre el array pasado por parametro
    {
        if(personas[i].edad <= 18)              /// busca personas menores o igual a 18.
        {
            printf(" * ");                      /// imprime "*" en la primer posicion de la tabla
        }
        else if(personas[i].edad >= 19 && personas[i].edad <= 35) /// busca edades entre 19 y 35.
        {
            printf("\t  * ");                                       /// imprime "*" en la segunda posicion
        }
        else                                                        /// si no esta entre los menores a 18, ni entre 19 y 35, imprime en la tercer posicion.
        {
            printf("\t\t  * ");
        }
        printf("\n");
    }

    printf("\n<18\t19-35\t3>5");


}
