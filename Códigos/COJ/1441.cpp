//1441 - Egypt

#include <stdio.h>

int main(){

	long long int a,b,c;
	
	while(scanf("%lld%lld%lld", &a,&b,&c), a,b,c){
		a*=a;
		b*=b;
		c*=c;
		if( ((a+b) == c) || ((c+b) == a) || ((a+c) == b))
			printf("right\n");
		else
			printf("wrong\n");
	}
	
	return 0;		
}
