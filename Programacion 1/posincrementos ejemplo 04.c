#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define p printf
#define s scanf


int main()
{
 int j=0,i=1;
 system("cls");
 system("color 9f");
 printf("\n--------------\n");
 printf("j=%d\n",j);
 printf("i=%d\n",i);
 j=--i;
printf("\n--------------\n");
 printf("j=%d\n",j);
 printf("i=%d\n",i);;
 printf("j=%d\n",++j);
 printf("\n--------------\n");
 printf("i=%d\n",i++);
 printf("\n--------------\n");
 printf("j=%d\n",j);
 printf("i=%d\n",i);
 printf("\n--------------\n");
 j=(++i)%2;
 printf("j=%d\n",j);
 printf("i=%d\n",i);
 printf("\n--------------\n");

 return 0;
}

/*

--------------
j=0
i=1

--------------
j=0
i=0
j=1

--------------
i=0

--------------
j=1
i=1

--------------
j=0
i=2

--------------
*/
