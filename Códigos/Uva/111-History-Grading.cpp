#include <stdio.h>
#include <algorithm>
using namespace std;

int pos[30];
int a[30], b[30];

int lis(int N){
	int maxi=0;
	for(int i=1; i<=N; i++){
		b[i]=1;
		for(int j=1; j<i; j++)
			if( a[j] < a[i] )
				b[i] = max( b[i], b[j]+1 );
		maxi = max(maxi,b[i]);
	}
	return maxi;
}

int main(){

	int nc,num;
	scanf("%d", &nc);
	for(int i=1; i<=nc; i++){
		scanf("%d", &pos[i]);
	}
	while(1){
	
		for(int i=1; i<=nc; i++){
			scanf("%d", &a[pos[i]]);
		}
		if(feof(stdin)) break;
		printf("%d\n", lis(nc));
	}	
	return 0;
}
