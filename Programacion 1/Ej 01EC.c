#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main() {
   int nota;

   do
    {
      printf("Ingrese una nota (1-10): ");
      scanf("%d", &nota);

      if (nota >= 1 && nota <= 10) {
         printf("La nota ingresada es: %d\n", nota);
      } else {
         printf("La nota ingresada no es válida.\n");
      }
   } while (nota < 1 || nota > 10);
   switch (nota)
   {
    case 1:
    case 2:
    case 3:
        printf("Recupera\n");
        break;
    case 4:
    case 5:
    case 6:
        printf("Bien !! \n");
        break;
    case 7:
    case 8:
        printf("Muy Bien !! \n");
        break;
    case 9:
        printf("Excelente !! \n");
        break;
    case 10:
        printf("Sobresaliente!! \n");

   }
   return 0;
}
