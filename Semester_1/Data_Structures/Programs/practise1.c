#include<stdio.h>
int main()
{
    int n,rev=0,rem,i;
    rem=0;
    printf("Enter the 3 numbers :");
    scanf("%d",&n);
    for(i=0;i<3;i++)
   { rem=n%10;
    rev=rev*10+rem;
    n=n/10;
    
   }
       printf("reversd number is n=%d",rev);
    return 0;
}