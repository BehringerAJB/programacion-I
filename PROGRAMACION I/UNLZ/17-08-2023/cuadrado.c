#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
int main()
{
    int i,j, count=5;
    for ( i = 0; i < count; i++)
    {
        for ( j = 0; j < count; j++)
        {
            printf("%3d",j+1);
        }
        printf("\n");
    }
return 0;    
}