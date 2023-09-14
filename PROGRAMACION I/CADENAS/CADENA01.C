#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hola, mundo!";
    char destination[20];

    strcpy(destination, source);

    printf("Cadena fuente: %s\n", source);
    printf("Cadena destino: %s\n", destination);
    printf("%x\n",source);
    printf("%x\n",destination);
    return 0;
}
