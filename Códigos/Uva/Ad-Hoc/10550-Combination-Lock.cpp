//10550 - Combination Lock
#include <stdio.h>


int main()
{
	int ini, p1, p2, p3, nv;
	
	while(scanf("%d %d %d %d", &ini, &p1, &p2, &p3), ini || p1 || p2 || p3)
	{
		nv = 120;
		if(ini < p1) nv += ini+40-p1;
		else nv += ini-p1;
		
		if(p1 <= p2) nv += p2-p1;
		else nv += p2+40-p1;
		
		if(p2 < p3) nv += p2+40-p3;
		else nv += p2-p3;
		printf("%d\n", nv*9);
	}
	
	return 0;
}
