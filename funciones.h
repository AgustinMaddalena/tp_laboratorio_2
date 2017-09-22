#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;
void mostrarPersona(ePersona);
void inicializarPersonas(ePersona[],int); /// inicializa los estados del array de "ePersona", para las altas.
int buscarLibre(ePersona[], int);
void crearPersona(ePersona[], int);
void eliminarPersona(ePersona[],int);
void ordenar(ePersona[],int);
void listar(ePersona[],int);
void grafico(ePersona[],int);

void ingresarPersona(ePersona[],int); /// carga los datos de la persona
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
*/
int buscarPorDni(ePersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED
