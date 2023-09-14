#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define n 8

int main()
{
    int vec[n];
    int i;
    for(i=0;i<n;i++)
    {
        printf("Ingrese valor:<%d>:",i+1);
        scanf("%d",&vec[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Valor:%d\n",vec[i]);
    }
return 0;
}

