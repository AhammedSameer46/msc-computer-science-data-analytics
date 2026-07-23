#include<stdio.h>
int add(int n){
	int a,s=0;
	while(n!=0){
		a=n%10;
		s+=a;
		n/=10;
	}
	return s;
}
void main(){
	int s=0,n,a=0,i=0;
	printf("Enter number:");
	scanf("%d",&n);
	i= add(n);
	while(s==0){
		if(i-9<=0){
			printf("sum = %d",i);
			break;
		}
		else{
			i=add(i);
		}	
	}
	
}

