#include<stdio.h>
#include<math.h>
int main(){
	int n,k=0,i=1,p;
	printf("Enter a decimal number:");
	scanf("%d",&n);
	printf("Binary: ");
	while(n>0){
		p=n%2;
		k=k+(p*i);
		n=n/2;
		i=i*10;
	}
	printf("\n%d",k);
//	printf("Binary nmber = %d",s);
}
