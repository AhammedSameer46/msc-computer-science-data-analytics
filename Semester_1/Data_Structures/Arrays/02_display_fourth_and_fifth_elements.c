#include<stdio.h>
int main()
{
	int a[50],i,n;
	printf("enter the size of your array:");
	scanf("%d",&n);
	printf("enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("4th and 5th position value elements are:%d %d",a[3],a[4]);
	return 0;
}
