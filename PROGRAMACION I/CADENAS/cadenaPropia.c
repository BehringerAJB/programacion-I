#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[] = "Hola";
    int i;
    // Convertir cadenas a minúsculas antes de comparar
    printf("%s\n",str1);
    for (int i = 0; str1[i]; i++) 
    {
        if(str1[i]>='a' && str1[i]<='z')
            str1[i]=str1[i]-32;
    }
    printf("\n%s\n",str1);
    return 0;
}