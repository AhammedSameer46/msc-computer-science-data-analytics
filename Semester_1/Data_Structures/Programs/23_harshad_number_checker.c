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
	int s,n,a,i;
	printf("Enter number:");
	scanf("%d",&n);
	i=add(n);
	if(n%i==0)
		printf("Harshad!");
	else
		printf("not Harshad");
}

