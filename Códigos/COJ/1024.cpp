//1024 - Hangover

#include <stdio.h>

double vec[500];

int main(){
	
	double num;
	int k;
	
	for(int i=1; vec[i-1]<=5.2; i++){
		vec[i] = (double)1/(i+1) + vec[i-1];
//		printf("%lf ", vec[i]);
	}
	//printf("\n");
	
	while(1){
		scanf("%lf", &num);	
		if(num < 0.009)
			break;
		
		for(k=1; vec[k]<num; k++);
		printf("%d card(s)\n", k);
	}
	
	return 0;
}
