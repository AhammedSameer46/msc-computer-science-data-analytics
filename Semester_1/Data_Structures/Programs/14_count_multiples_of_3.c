#include<stdio.h>
void main(){
	int n,i,count=0;

	printf("Enter n:");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		if(i%3==0)
			count++;
	}

	printf("Count = %d",count);
}