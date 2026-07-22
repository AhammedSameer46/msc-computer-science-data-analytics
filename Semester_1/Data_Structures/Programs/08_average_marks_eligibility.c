#include<stdio.h>
void main(){
	int a,count=0,m=0,n,i;
	printf("Number of subjects:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter marks:");
		scanf("%d",&a);
		m=m+a;
		count++;
	}
	if(m/count>40)
		printf("\nEligible");
	else
		printf("\nNot eligible");
	
	}
