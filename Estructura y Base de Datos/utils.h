#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define CLEAN() system("cls")
#define PAUSE() system("pause")
#define FONDO_AZUL system("color 10")
#define FONDO_VERDE system("color 20")
#define FONDO_AGUAMARINA system("color 30")
#define FONDO_ROJO system("color 40")
#define FONDO_PURPURA system("color 50")
#define FONDO_AMARILLO system("color 60")
#define FONDO_BLANCO system("color 70")
#define FONDO_GRIS system("color 80")
#define FONDO_AZUL_CLARO system("color 90")
#define FONDO_VERDE_CLARO system("color A0")
#define FONDO_AGUAMARINA_CLARO system("color B0")
#define FONDO_ROJO_CLARO system("color C0")
#define FONDO_PURPURA_CLARO system("color D0")
#define FONDO_AMARILLO_CLARO system("color E0")
#define FONDO_BLANCO_CLARO system("color F0")
#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"

typedef char string[50];

// Lectura de datos
int leerEntero(string mensaje);
float leerFloat(string mensaje);
char leerCaracter(string mensaje);
int leerEnteroEntre(int valorMin, int valorMax, string mensaje);
float leerFloatEntre(float valorMin, float valorMax, string mensaje);
void leerString(string mensaje, string str);
void leerStringEntre(int minLength, int maxLength, string mensaje, string str);

// Vectores
void leerVectorDeEnteros(string mensaje, int vec[], int cant);
void leerVectorDeFloats(string mensaje, float vec[], int cant);
void leerVectorDeCaracteres(string mensaje, char vec[], int cant);
void leerVectorDeEnterosEntre(int valorMin, int valorMax, string mensaje, int vec[], int cant);
void leerVectorDeFloatsEntre(float valorMin, float valorMax, string mensaje, float vec[], int cant);
void mostrarVectorEnteros(int vec[], int cant);
void mostrarVectorFloats(float vec[], int cant);
void mostrarVectorDeCaracteres(char vec[], int cant);

// Utilidad
int generarNumAleatorio(int valorMin, int valorMax);
int sonIguales(string texto, string texto2);
void swap(int *a, int *b);
bool confirmaUsuario(string mensaje);
void retardo(float seg);
void linea(int x);
int error(string path);
void tecla(void);
void cargar();

// Ordenamiento
void bubbleSortAsc (int numeros[], int cant);
void bubbleSortDesc (int numeros[], int cant);

// Busqueda
int buscarLineal(int vec[], int cant, int valorB);
int buscarBinario(int vec[], int min, int max, int valorB);

// Matrices
void leerMatrizDeEnteros(string mensaje, int f, int c, int mat[f][c]);
void leerMatrizDeFloats(string mensaje, int f, int c, float mat[f][c]);
void leerMatrizDeCaracteres(string mensaje, int f, int c, char mat[f][c]);
void mostrarMatrizDeEnteros(int f, int c, int mat[f][c]);
void mostrarMatrizDeFloats(int f, int c, float mat[f][c]);
void mostrarMatrizDeCaracteres(int f, int c, char mat[f][c]);

// Archivos
FILE* abrirArchivo(string path, string tipo);
void cerrarArchivo(FILE* pArch, char path[]);
int existeArchivo(FILE* pArch);
void agregarTXT(string archiveName);
FILE* abrirArchivoBinario(string path, string tipo);

#include "utils.c"
#endif // UTILS_H_INCLUDED
