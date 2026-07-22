#include<stdio.h>
void main(){
	int a,count=0,m=0,n,i;
	printf("Enter electrical units consumed:");
	scanf("%d",&a);
	
	if(a>500){
		i=(400)*8;
		m=(a-500)*10;
		printf("%d greater than 500UNits therefor10Rs/unit\n\t Bill = %d",a,m+i+(100*5));
	}	
	else if(a>100){
		i=(a-100)*8;
		printf("%d greater than 100UNits therefor 8Rs/unit\n\t Bill = %d",a,i+(100*5));
	}
	else
		printf("%d less than 100Units therefor 5Rs/UNit\n\t Bill = %d",a,a*5);
	
	
}
