#include <stdio.h>
#include <stdlib.h>
/*
Enunciado: Manipulación de Arrays de Punteros y Vectores

Se dispone de un array de punteros que almacenará las direcciones de tres vectores: vec1, vec2 y vec3. 
Cada uno de estos vectores tiene un tamaño de 10 posiciones.

Paso 1: Se requiere obtener las direcciones de los vectores vec1, vec2 y vec3. 
Para esto, se debe implementar una función llamada cargarDirecciones, 
cuyo propósito es almacenar en cada posición del array de punteros ptr las direcciones de los tres vectores respectivos.

Paso 2: A continuación, se debe implementar una función llamada cargarVector, 
la cual tomará como argumento un vector y su tamaño. 
Utilizando la función cargarVector, 
se debe cargar cada uno de los vectores vec1, vec2 y vec3 
con datos aleatorios entre 20 y 500. 
Esto se realizará de manera individual, un vector a la vez.

Paso 3: Finalmente, se implementará la función listarVectores, 
que permitirá listar los valores de los vectores. 
Para lograr esto, se requerirá pasar la dirección contenida en el array de punteros ptr que apunta a cada vector. 
Esta dirección proporcionará el acceso necesario a los elementos del vector, permitiendo mostrar sus contenidos.

El enunciado busca desarrollar una solución completa que involucra la manipulación de arrays de punteros
 y la gestión de vectores. 
 La claridad y estructura de las funciones permitirán lograr estos objetivos de manera organizada y comprensible.
 mucha suerte chicos !!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarDirecciones(int **, int *, int *, int *);
void cargarVector(int *, int tam);
void listarVectores(int **);

int main() 
{
    int vec1[10], vec2[10], vec3[10]; // declaro los vecores que tendran los valores
    int *ptr[3] = {NULL}; // defino el arrays de Punteros
    srand(time(NULL));
    printf("\nDireccion del vector 1 %x\n",vec1);
    printf("Direccion del vector 2 %x\n",vec2);
    printf("Direccion del vector 3 %x\n",vec3);
    cargarDirecciones(&ptr, vec1, vec2, vec3); // le cargo las direcciones de cada vector
    printf("\nDireccion del vector 1 dentro de ptr: %x\n",*(ptr+0));
    printf("Direccion del vector 2 dentro de ptr: %x\n",*(ptr+1));
    printf("Direccion del vector 3 dentro de ptr: %x\n",*(ptr+2));
    for (int i = 0; i < 3; i++) 
    {
        printf("\nDireccion  del vector vec:%d dentro de ptr %p\n",i+1,*(ptr+i));
        cargarVector(*(ptr+i), 10); // lleno los vectores con los valores
        printf("\n---------------------------------------------------\n");
    }
    listarVectores(ptr);
    return 0;
}

void cargarDirecciones(int **ptr, int *vec1, int *vec2, int *vec3) 
{
    ptr[0] = vec1;
    ptr[1] = vec2;
    ptr[2] = vec3;
}

void cargarVector(int *vector, int tam) 
{
    printf("\n..................................\n");
    for (int i = 0; i < tam; i++) 
    {
        *(vector+i) = rand() % (500 - 20 + 1) + 20;
        printf("Posiciones de vector %d\n",*(vector+i));
    }
}
// listar vector Version 2 la version 1 seria uno por uno llamandolo


void listarVectores(int **x) 
{
    int i,j;
    for ( i = 0; i < 3; i++) 
    {
        printf("Vector %d: direcci%cn %p\n", i + 1,162, (void *)x[i]);
        printf("\n -------------------- \n");
        for (j = 0; j < 10; j++) 
        {
            printf("Vec[%d] = %d\n", j, x[i][j]); // version entendible
        }
        printf("\n ******************************************* \n");
    }
    /*
    utilizamos x[i] para acceder a la dirección del i-ésimo vector en el array de punteros, 
    lo que mostrará la dirección correcta de cada vector. El operador de indexación x[i][j] 
    se utiliza para acceder a los elementos individuales de cada vector.
    */
}


