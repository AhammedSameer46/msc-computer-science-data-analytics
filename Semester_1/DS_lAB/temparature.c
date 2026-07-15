#include<stdio.h>
int main()
{
    int temp;
    printf("Enter the teamparature");
    scanf("%d",&temp);
    if(temp>=100)
        printf("High teamparature");
    else
        printf("Normal teamparature");
}