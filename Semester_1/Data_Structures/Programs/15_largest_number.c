 	#include<stdio.h>
void main(){
	int n,i,num,largest;

	printf("How many numbers:");
	scanf("%d",&n);

	printf("Enter number:");
	scanf("%d",&largest);

	for(i=2;i<=n;i++){
		printf("Enter number:");
		scanf("%d",&num);

		if(num>largest)
			largest=num;
	}

	printf("Largest = %d",largest);
}