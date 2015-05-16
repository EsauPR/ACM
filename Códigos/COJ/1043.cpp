//1043 - Simple Dishes

#include <stdio.h>
int b;

void fun(int i, int num){
	if(num){
		if(num%2==1){
			if(b==0)
				printf("%d", i);
			else
				printf(" %d", i);
			b=1;
		}
		fun(i+1,num/2);
	}
}

int main(){
	int n, num;
	scanf("%d", &n);
	while(n--){
		b=0;
		scanf("%d", &num);
		fun(0,num);
		printf("\n");
	}

	return 0;
}
