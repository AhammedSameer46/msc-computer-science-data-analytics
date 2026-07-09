#include<stdio.h>
int main()
{
	int n,number,count=0;
	printf("Enter the number");
	scanf("%d",&number);
	n=number;
		while (n!=0)
	{
		number=number/10;
		count++;
		
		
	}
	printf("the number %d had %d",number,count);
}

