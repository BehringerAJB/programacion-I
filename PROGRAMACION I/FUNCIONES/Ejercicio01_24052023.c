#include <stdio.h>

int main()
{
    int it1, it2, it3;
    int cont=0;
    do
    {
        printf("Ingrese el estado del interruptor 1: < 1 prendido 0 apagado >");
        scanf("%d", &it1);
    } while (it1 != 1 && it1 != 0);
    do
    {
        printf("Ingrese el estado del interruptor 2: < 1 prendido 0 apagado >");
        scanf("%d", &it2);
    } while (it2 != 1 && it2 != 0);
    do
    {
        printf("Ingrese el estado del interruptor 3: < 1 prendido 0 apagado >");
        scanf("%d", &it3);
    } while (it3 != 1 && it3 != 0);
    if(it1==1)
    cont++;
    if (it2==1)
    cont++;
    if (it3==1)
    cont++;
    printf("Total de lamparas encendidas %d\n",cont);
return 0;
}