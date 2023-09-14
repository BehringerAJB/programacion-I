#include <stdio.h>
#include <string.h>

int main() {
    char input[100];  // Cadena para capturar el texto
    char copied[100]; // Cadena donde se copiará el texto con acento circunflejo y "n"

    printf("Ingresa un texto: ");
    //scanf("%[^\n]", input); // Captura de texto hasta el salto de línea ALT +94
    gets(input);
    strcpy(copied, input); // Copiar la cadena capturada

    printf("Texto original: %s\n", input);
    printf("Texto copiado: %s\n", copied);

    return 0;
}
