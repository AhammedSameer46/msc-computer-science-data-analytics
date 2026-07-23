#include<stdio.h>
void main(){
	int n,i,num;
	int pos=0,neg=0,zero=0;

	printf("How many numbers:");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("Enter number:");
		scanf("%d",&num);

		if(num>0)
			pos++;
		else if(num<0)
			neg++;
		else
			zero++;
	}

	printf("\nPositive = %d",pos);
	printf("\nNegative = %d",neg);
	printf("\nZero = %d",zero);
}