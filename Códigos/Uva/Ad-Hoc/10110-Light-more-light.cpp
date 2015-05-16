#include <stdio.h>
#include <math.h>

int main()
{
	long long int num,r;
	while(scanf("%lld", &num), num)
	{
		r = (long long int) sqrt((double)num);
		if(r*r == num)
			puts("yes");
		else puts("no");
	}
	
	return 0;
}
