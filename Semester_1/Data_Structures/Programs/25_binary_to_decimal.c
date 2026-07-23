#include<stdio.h>
#include<math.h>
void main(){
	int n,k=0,i,p,s=0;
	printf("Enter a binary number:");
	scanf("%d",&n);
	while(n!=0){
		i=n%10;
		p=i*pow(2,k);
		s=s+p;
		k++;
		n/=10;
	}
	printf("decimal nmber = %d",s);
}
