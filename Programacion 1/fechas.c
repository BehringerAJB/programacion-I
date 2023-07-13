#include <stdio.h>

int main() 
{
   int mes, anio;
   printf("Ingrese un numero de mes (1-12): ");
   scanf("%d", &mes);
   printf("Ingrese un año: ");
   scanf("%d", &anio);

   if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) 
   {
      // El año es bisiesto
      switch (mes) 
      {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
            printf("El mes tiene 31 dias.\n");
            break;
         case 4:
         case 6:
         case 9:
         case 11:
            printf("El mes tiene 30 dias.\n");
            break;
         case 2:
            printf("El mes tiene 29 dias.\n");
            break;
         default:
            printf("El numero de mes ingresado no es valido.\n");
            break;
      }
   } else {
      // El año no es bisiesto
      switch (mes) 
      {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
            printf("El mes tiene 31 dias.\n");
            break;
         case 4:
         case 6:
         case 9:
         case 11:
            printf("El mes tiene 30 dias.\n");
            break;
         case 2:
            printf("El mes tiene 28 dias.\n");
            break;
         default:
            printf("El numero de mes ingresado no es valido.\n");
            break;
      }
   }
   return 0;
}
