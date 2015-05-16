#include <stdio.h>

int abs(int n){
	return (n>0)? n:-n;
}

int main(){
	
	int a, b, n;
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d", &a, &b);
		
		if(a<b)
			printf("impossible\n");
		else{
			int t1 = (a+b)/2;
			int t2 = abs((a-b)/2);
			
			int tmp;
			
			if(t1<t2){
				tmp=t1; t1=t2; t2=tmp;
			}
			
			if(t1+t2 == a)
				printf("%d %d\n",t1,t2);
			else
				printf("impossible\n");
			
		}
			
	}
	
	return 0;
}