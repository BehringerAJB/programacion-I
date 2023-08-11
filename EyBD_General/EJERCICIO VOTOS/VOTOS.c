/*


Ejercicio 1

Procesar los archivos generados en el punto anterior para cargar un Array 
con la siguiente estructura:

? Nombre Agrupación
? Número de Lista
? Nombre Candidato
? Cantidad de Votos

1) Informar nombre del candidato con mayor cantidad de Votos EN SENADORES Y DIPUTADOS
2) iNFORMAR A NIVEL VOTOS,  LA AGRUPACION POLITICA GANADORA






*/


#include<stdio.h> // Carga de un archivo de Texto separado los campos por comas
#include<stdlib.h> 
#include<conio.h> // Probado con strtok
#include<string.h>
#define p printf
#define s scanf
typedef struct
{
     char partido[20];
     int lista;
     char nom_cand[30];
     int cantvot;
 } registro;