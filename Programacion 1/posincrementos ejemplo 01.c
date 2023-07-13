#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define p printf
#define s scanf


int main()
{
 int n=0,i=0;
 system("cls");
 system("color 9f");
 n=5;
 printf("i=%d\n",i);
 printf("n=%d\n",n);
 printf("\n--------------\n");
 printf("--->n++=%d\n",n++);
 printf("i=%d\n",i);
 printf("n=%d\n",n);
 printf("\n--------------\n");
 n+=1; //  n=n+1
 i=n++;
 printf("i=%d\n",i);
 printf("n=%d\n",n);
 printf("\n--------------\n");
 printf("--> --i=%d\n",--i);
 n=++i;
 printf("n=%d\n",n);
 printf("i=%d\n",i);
 printf("\n--------------\n");
 return 0;
}

/*

i=0
n=5

--------------
--->n++=5
i=0
n=6

--------------
i=7
n=8

--------------
--> --i=6
n=7
i=7

--------------


*/

