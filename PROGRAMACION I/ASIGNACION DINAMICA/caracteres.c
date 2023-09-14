#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *cadena = NULL; // Inicializa un puntero a char (cadena) a NULL
    char caracter;
    int longitud = 0; // Inicializa la longitud de la cadena a 0

    printf("Ingresa caracteres (presiona Enter para finalizar):\n");

    // Lee caracteres hasta que se presione Enter (tecla '\n')
    while ((caracter = getchar()) != '\n') {
        // Aumenta la longitud de la cadena en 1
        longitud++;
        // Reasigna la memoria dinámica para acomodar el nuevo caracter
        cadena = (char *)realloc(cadena, longitud * sizeof(char));
        
        // Agrega el nuevo caracter a la cadena
        cadena[longitud - 1] = caracter;
    }

    // Agrega el carácter nulo para formar una cadena válida en C
    cadena = (char *)realloc(cadena, (longitud + 1) * sizeof(char));
    cadena[longitud] = '\0';

    printf("La cadena ingresada es: %s\n", cadena);

    // Liberar la memoria dinámica cuando ya no se necesite
    free(cadena);

    return 0;
}
