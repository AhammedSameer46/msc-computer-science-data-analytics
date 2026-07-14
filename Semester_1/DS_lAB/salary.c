#include<stdio.h>
int main()
{
	float da,hra,salary,total;
	printf("Enter the salary");
	scanf("%f",&salary);	
	da=salary*10/100;
	hra=salary*15/100;
	total=salary+da+hra;
	printf("total =%f",total);
}