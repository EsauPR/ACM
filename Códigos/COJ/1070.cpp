// 1070 - A Simple Calculation

#include<stdio.h>

int main(){
	
	int n,cua,rec;
	
	while(scanf("%d", &n)!=EOF){
		cua=n*(n+1)*(2*n+1)/6;
		rec=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				rec+=(n-j+1)*(n-i+1);
		printf("%d %d\n", cua, rec);
	}
	
	return 0;
}
