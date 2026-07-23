//collatz conjecture
#include<stdio.h>
void main(){
	int i,a,n;
	printf("Enter the number:");
	scanf("%d",&n);
	while(n!=1){
		if(n%2==0){
				printf("\n%d",n);
				n/=2;
		}
		else{
				printf("\n%d",n);
				n=(3*n)+1;
		}
		i++;	
	}
	printf("Collatz conjuctiure in %d steps",i);

}
