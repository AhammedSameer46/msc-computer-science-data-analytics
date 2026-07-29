#include<stdio.h>
int main ()
{
    int a,b,temp;
    printf("Enter the value of a and b :");
    scanf("%d%d",&a,&b);
    temp=a;
    a=b;
    b=temp;
    printf("after swapping a=%d \n b=%d",a,b);
}
