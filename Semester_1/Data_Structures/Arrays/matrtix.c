
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
		if(a[i]%2==0)
		{
			b=b+a[i];
		}		
	}
	printf("Sum of even numbers:%d",b);
	return 0;
}



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
		if(a[i]%2==0)
		{
			b=b+a[i];
		}		
	}
	printf("Sum of even numbers:%d",b);
	return 0;
}