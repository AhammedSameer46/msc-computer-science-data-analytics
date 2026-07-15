#include<stdio.h>
int main()
{
    char ch;
    printf("Enter anything:");
    scanf("%c",&ch);
    if(ch>='A'&& ch<='Z')
        printf("Upper case");
    else if(ch>='a'&& ch<='z')
        printf("Lower case");
        
    else if(ch>='0'&& ch<='9')
        printf("Intergers");
    else
        printf("Invalid input");
}