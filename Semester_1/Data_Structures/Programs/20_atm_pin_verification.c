#include<stdio.h>
void main(){
	int s,n,a=1234,i;
	while(i<3){
		printf("Enter pin\n(4 digits):");
		scanf("%d",&n);
		if(n==a)
			printf("Sucsess!");
		else
			printf("wrong password\n %d attempts remaining!",3-i);
		i++;
	}
	printf("Blocked!");
}
