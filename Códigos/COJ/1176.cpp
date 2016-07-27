//1176 - Ternary

#include <stdio.h>

void fun(int n){
	
	if(n!=0){
		fun(n/3);
		printf("%d",n%3);
	}
}

int main(){
	
	int n;
	
	while(1){
		scanf("%d", &n);
		if(n==-1)
			break;
		fun(n);
		printf("\n");
	}
		
	return 0;
}
