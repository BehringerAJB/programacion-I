#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hola";
    char str2[] = "Hola";
    int c;
    c = strcmp(str1, str2);
    
    if (c == 0) 
    {
        printf("Las cadenas son iguales.\n");
    } else 
    if (c < 0) 
    {
        printf("La cadena str1:%s es menor que str2:%s.\n",str1,str2);
    } else 
    {
        printf("La cadena str1:%s es mayor que str2:%s.\n",str1,str2);
    }
    
    return 0;
}
