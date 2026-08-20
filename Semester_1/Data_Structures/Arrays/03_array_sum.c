#include<stdio.h>
int main()
{
	int a[50],i,n,b=0;
	printf("enter the size of your array:");
	scanf("%d",&n);
	printf("enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		b=b+a[i];
	}
	printf("Sum of elements:%d",b);
	return 0;
}
 
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