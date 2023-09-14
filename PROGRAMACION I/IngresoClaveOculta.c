#include <stdio.h>
#include <ctype.h>

int main() {
    int clave_correcta = 1234;
    int clave_ingresada;
    int caracter;
    
    printf("Ingrese la clave numerica: ");
    
    while ((caracter = getc()) != '\n') {
        if (isdigit(caracter)) 
        {
            putchar('*');
            clave_ingresada = clave_ingresada * 10 + (caracter - '0');
        } 
    }
    
    if (clave_ingresada == clave_correcta) {
        printf("\nClave correcta. Acceso permitido.\n");
    } else {
        printf("\nClave incorrecta. Acceso denegado.\n");
    }
    
    return 0;
}

