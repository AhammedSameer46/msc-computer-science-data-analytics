#include<stdio.h>
void main(){
	char s[10];
	int a,k,digit=0,i,temp;
//	printf("Price of book\n\t150 Rs.");
	printf("Enter the number:");
	scanf("%d",&k);
	temp=k;
	while(temp>0){
		temp=temp/10;
		digit++;
	}
	printf("%d\n",digit);
	switch(digit){
		case 1:
			printf("single digit");
			break;
		case 2:
			printf("Double digit");
			break;
		case 3:
			printf("Three digit");
			break;
		default:
			printf("there are %d number of digits for %d",digit,k);
			break;
	}
		
}
