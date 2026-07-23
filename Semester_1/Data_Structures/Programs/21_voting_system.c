#include<stdio.h>
void main(){
	int s,n,a=1234,i=0,q=0,w=0;
	while(1){
		printf("Enter vote\ncandidate 1 = press 1\ncandidate 2 = press 2\ncandidate 3 = press 3\nexit poll = press 0\n your choice:");
		scanf("%d",&n);
		if(n==1)
			i++;
		else if(n==2)
			q++;
		else if(n==3)
			w++;
		else if(n==0)
			break;
		else
			printf("invalid choice!");
		
	}
	printf("Voting Result:\ncandidate 1 = \t%d\ncandidate 2 = \t%d\ncandidate 3 = \t%d\n\n",i,q,w);
}
