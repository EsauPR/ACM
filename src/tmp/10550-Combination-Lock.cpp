#include <stdio.h>

int main()
{
	int ini,p1,p2,p3,total;	
	
	while(scanf("%d %d %d %d",&ini,&p1,&p2,&p3) && (ini+p1+p2+p3 != 0)){
		total=80;
		
		if(p1<=ini) total += ini-p1; 
			else total += ini+40-p1; 	
		total += 40;
		if(p2<p1) total += (p2+40)-p1;
		else	total += p2-p1;
		if(p3<=p2) total += p2-p3;
		else	total+=p2+40-p3;
		
		printf("%d\n", total*9);
	}
	
	return 0;
}
