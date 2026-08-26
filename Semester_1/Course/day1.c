/////#include<stdio.h>
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
}/////

//// struct


#include<stdio.h>
void main()

#include<stdio.h>
 struct reactangle ;
{
   int length;
   int breadth;
   char x;
   
}
int main()
{
    struct reactangle r1=(10,15);
    r1.length=20;
    r1.breadth=30
    printf("%d",sizeof(r1.length));
    return 0;
}