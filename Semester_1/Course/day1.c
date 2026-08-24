#include<stdio.h>
int main()
{
    int a[],i;
    for (i=0;i<5;i++)
    {
        printf("Enter the value of a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("The values of the array are: ");
    for (i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}