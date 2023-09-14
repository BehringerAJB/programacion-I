/*

#include <stdio.h>

int main() {
    char caracter;

    printf("Ingrese un caracter: ");
    caracter = getchar();
    printf("El caracter ingresado fue: %c\n", caracter);
    return 0;
}

*/

#include <stdio.h>
#include <conio.h> // Biblioteca que puede contener la función getch en algunos entornos

int main() {
    char caracter;

    printf("Presione una tecla: ");
    caracter = getch();

    printf("La tecla presionada fue: %c\n", caracter);

    return 0;
}
