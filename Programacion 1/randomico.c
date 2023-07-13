#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   int lower = -200, upper = 200;
   
   // Establecer la semilla para el generador de números aleatorios
   srand(time(NULL));
   
   // Generar 10 números aleatorios en el rango de -200 a 200
   for(i = 0; i < 10; i++) {
      n = rand() % (upper - lower + 1) + lower;
      printf("%d ", n);
   }
   
   return 0;
}
