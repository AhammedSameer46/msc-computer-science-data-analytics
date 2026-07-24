
#include<stdio.h>
int main()
{
	int a[50],i,n,b=0,c;
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
	c=b/n;
	printf("Average of array elememts:%d",c);
	return 0;
}