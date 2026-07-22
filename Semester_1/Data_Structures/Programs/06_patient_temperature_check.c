#include<stdio.h>
void main(){
	int a;
	printf("Enter temp of patient:");
	scanf("%d",&a);
	a = 100>a? printf("Normal"):printf("fever");
	}
