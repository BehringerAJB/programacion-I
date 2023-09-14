#include <stdio.h>
#include <stdlib.h>

#define FILAS 5  // Número de filas en la imagen
#define COLUMNAS 5  // Número de columnas en la imagen

void aplicarFiltroSuavizado(int imagen[FILAS][COLUMNAS]) {
    int resultado[FILAS][COLUMNAS];  // Matriz para almacenar el resultado

    // Iterar sobre cada píxel en la imagen
    for (int i = 1; i < FILAS - 1; i++) {
        for (int j = 1; j < COLUMNAS - 1; j++) {
            // Calcular el valor promedio de los 8 píxeles circundantes
            int suma = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    suma += imagen[i + x][j + y];
                }
            }
            resultado[i][j] = suma / 9;  // 9 es el número de píxeles circundantes
        }
    }

    // Copiar el resultado de vuelta a la imagen original
    for (int i = 1; i < FILAS - 1; i++) {
        for (int j = 1; j < COLUMNAS - 1; j++) {
            imagen[i][j] = resultado[i][j];
        }
    }
}

int main() {
    int imagen[FILAS][COLUMNAS] = {
        {0, 0, 0, 0, 0},
        {0, 255, 255, 0, 0},
        {0, 255, 255, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    printf("Imagen original:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", imagen[i][j]);
        }
        printf("\n");
    }

    aplicarFiltroSuavizado(imagen);

    printf("\nImagen suavizada:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", imagen[i][j]);
        }
        printf("\n");
    }

    return 0;
}
