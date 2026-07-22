#include<stdio.h>
void main(){
	int a,count=0,m=0,n,i;
	printf("Age:");
	scanf("%d",&a);
	if(a<14)
		printf("child");
	else if(a>13&a<21)
		printf("Teenage");
	else if(a>21&a<50)
		printf("Adult");
	else
		printf("Old age");
	
}
