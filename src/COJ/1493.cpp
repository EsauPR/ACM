//1493 - Geometrical Task II
#include <stdio.h>
#include <string.h>

int main(){

	double a,b;
	char vec[50];
	
	scanf("%s",vec);
	
	if(strcmp(vec,"circle")==0){
		scanf("%lf", &a);
		printf("%.2lf\n", a*a*3.14);
	}
	else if(strcmp(vec,"triangle")==0){
		scanf("%lf%lf", &a,&b);
		printf("%.2lf\n", (a*b)/2);
	}
	else if(strcmp(vec,"rhombus")==0){
		scanf("%lf%lf", &a,&b);
		printf("%.2lf\n", (a*b)/2);
	}
		
	
	return 0;
}

